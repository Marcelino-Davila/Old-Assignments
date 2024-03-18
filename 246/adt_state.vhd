library IEEE;
use IEEE.STD_LOGIC_1164.ALL;


entity twi_state is
    port(clk : in std_logic;
         rst : in std_logic; 
         START : in std_logic; 
         stb_i : out std_logic;
         srst : out std_logic; 
         msg_i : out std_logic;
         a_i : out std_logic_VECTOR (7 downto 0);
         d_i : out std_logic_VECTOR (7 downto 0);
         done_o : in std_logic;
         err_o : in std_logic;
         d_o : in std_logic_VECTOR (7 downto 0);
         DATA_OUT : out std_logic_vector(15 downto 0));
end twi_state;

architecture behavior of twi_state is 
constant addrAD2	 : STD_LOGIC_VECTOR(6 downto 0) := b"1001011";
constant read_Bit  : STD_LOGIC := '1';
constant write_Bit : STD_LOGIC := '0';

type state_type is (idle,ready,msb,lsb,waiting, done1, done2); 
signal next_state, present_state : state_type;
signal count : integer := 0;
signal done_sig : std_logic := '0';
signal counter_reset : std_logic;
signal msb_reg, lsb_reg : std_logic_vector(7 downto 0);

begin
counter : process(clk,rst,counter_reset)
begin
  if rst = '1' or counter_reset = '1' then
    count <= 0;
  elsif(rising_edge(clk)) then 
    count <= count+1;
  end if;
end process counter;

clocked : process(clk, rst,counter_reset) 
  BEGIN
    If(rst = '1') THEN 
      present_state <= idle;
    ELSIF(rising_edge(clk)) THEN
      present_state <= next_state;
    END IF;
END PROCESS clocked; 

NextState : process(present_state, Start,count,rst)
begin
  case(present_state) is
    when idle =>
      if count >= 1200 then
        next_state <= ready;
      else
        next_state <= present_state;
      end if;
    when ready =>
      if start = '1' THEN 
        counter_reset <= '1';
        next_state <= done1;
      else
        next_state <= present_state;
      end if;
    when done1 => 
      counter_reset <= '0';
      if done_o = '1' then
        next_state <= msb;
        counter_reset <= '1'; 
      else 
        next_state <= present_state;
      end if;
    when msb =>
    counter_reset <= '0';
      if count > 500 then
        next_state <= done2;  
      else
        next_state <= present_state;
      end if;
    when done2 => 
      if done_o = '1' then
        next_state <= lsb;
      else
        next_state <= present_state;
      end if;
    when lsb =>
    counter_reset <= '0';
      if count > 500 then
        next_state <= waiting;
      else 
        next_state <= present_state;
      end if;
    when waiting => 
      if start = '0' then
        next_state <= ready; 
      else 
        next_state <= present_state;
      end if;
    when others =>
      next_state <= present_state;
    end case;
end process NextState;

output : process(present_state, count)
begin 
  case(present_state) is
    when idle =>
    when ready =>
      msg_i <= '0';
      stb_i <= '0';
      a_i <= addrAD2 & write_Bit;
      d_i <= (others => '0');
    when done1 =>
      stb_i <= '1'; 
      a_i <= addrAD2 & read_bit;
      if count < 10 then
        msg_i <= '1';
      else 
        msg_i <= '0';
      end if;
    when msb => 
      msg_i <= '0';
      data_out(15 downto 8) <= d_o;
    when done2 => 
      msg_i <= '0';
      stb_i <= '0'; 
    when lsb =>
      msg_i <= '0';
      data_out(7 downto 0) <= d_o;
    when waiting =>
      msg_i <= '0';
      stb_i <= '0';
      a_i <= addrAD2 & write_bit;
      d_i <= (others => '0');
    end case;
end process output;

D_ff : process(done_o, present_state) -- capture data from the twi interface 
begin
  if present_state = msb and done_o = '1'then
    msb_reg <= d_o;
  elsif present_state = lsb and done_o = '1' then 
    lsb_reg <= d_o; 
  end if;
end process D_ff;

end behavior;
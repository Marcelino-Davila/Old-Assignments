library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
USE work.alu_resources.all;

entity lab4 is
    port(inA, inB : in std_logic_vector(15 downto 0);
         mode : in std_logic_vector(2 downto 0);
         OE : in std_logic;
         C : out std_logic_vector(15 downto 0);
         Cout, Zero : out std_logic);         
end lab4;

architecture Behavioral of lab4 is
    begin
        process(inA, inB, mode, OE)
        variable temp_c : std_logic_vector(16 downto 0);
        begin
        if(OE = '0') then
            C <= "ZZZZZZZZZZZZZZZZ";
            Zero <= '-';
            Cout <= '-';
        else
            temp_c := alu_function(inA, inB, mode);
            C <= temp_c(15 downto 0);
            Cout <= temp_c(16);
            if temp_c = "00000000000000000" then
                zero <= '1';
            else
                zero <= '0';
            end if;
        end if;
        end process;
    end Behavioral;

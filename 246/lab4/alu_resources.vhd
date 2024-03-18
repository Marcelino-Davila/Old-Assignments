library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

PACKAGE alu_resources IS
    FUNCTION alu_function (A, B : std_logic_vector(15 downto 0);
     mode : std_logic_vector(2 downto 0))
     RETURN std_logic_vector;
end alu_resources;

PACKAGE BODY alu_resources IS
   FUNCTION alu_function (A, B : std_logic_vector(15 downto 0); mode : std_logic_vector(2 downto 0)) RETURN std_logic_vector is
   variable a_temp, b_temp : signed(15 downto 0);
   variable c_temp : signed(16 downto 0);
   BEGIN 
       a_temp := resize(signed(A),17);
       b_temp := resize(signed(B),17);
       case mode is
            when "000" => -- a+b
                c_temp := a_temp + b_temp;
            when "001" => -- a-b
                c_temp := a_temp - b_temp;
            when "010" => -- -a
                c_temp := -1*a_temp;
            when "011" => -- shift left a
			     c_temp := shift_left(a_temp,1);
            when "100" => -- a*b
                c_temp := a_temp * b_temp;
            when "101" => -- a or b
                c_temp := a_temp or b_temp;
            when "110" => -- a xor b
                c_temp := a_temp xor b_temp;
            when "111" =>  -- abs A
                c_temp := abs(a_temp);
       end case;
   RETURN std_logic_vector(c_temp);
   END alu_function;
end alu_resources;

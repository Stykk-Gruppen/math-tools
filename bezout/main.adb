with Ada.Text_IO; use ADA.Text_IO;
with Ada.Command_Line; use Ada.Command_Line;

procedure main is

	procedure extended_gcd(a : Integer; b : Integer) is
	old_r : Integer := a;
	r : Integer := b;
	old_s : Integer := 1;
	s : Integer := 0;
	old_t : Integer := 0;
	t : Integer := 1;
	quotient : Integer;
	temp : Integer;
	begin
		while r /= 0 loop
			quotient := old_r / r;
			temp := r;
			r := old_r - quotient * temp;
			old_r := temp;

			temp := s;
			s := old_s - quotient * temp;
			old_s := temp;

			temp := t;
			t := old_t - quotient * temp;
			old_t := temp;
		end loop;

	Put_Line("GCD: " & Integer'Image(old_r));
	Put_Line("Bezuouts Coefficients: " & Integer'Image(old_s) & ", " &Integer'Image(old_t));

	end extended_gcd;
	
	num1 : Integer;
	num2 : Integer;
begin

	if Argument_Count /= 2 then
		Put_Line("Wrong arguments, should be to non-negative integers");
	end if;

	num1 := Integer'Value(Argument(1));
	num2 := Integer'Value(Argument(2));
	extended_gcd(num1, num2);
end main;

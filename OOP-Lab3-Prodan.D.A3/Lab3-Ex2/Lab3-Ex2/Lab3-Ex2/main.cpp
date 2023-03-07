#include "Canvas.h"

int main()
{
	Canvas canvas(100, 100);
	canvas.DrawLine(2, 2, 18, 2, '-');
	canvas.DrawRect(2, 4, 18, 10, '#');
	canvas.FillRect(3, 5, 17, 9, '+');
	canvas.DrawCircle(9, 26, 4, '0');
	canvas.FillCircle(9, 26, 3, '*');
	canvas.DrawLine(2, 14, 18, 18, '-');
	canvas.DrawRect(6, 37, 49, 48, '@');
	// D
	canvas.SetPoint(9, 40, 'D');
	canvas.SetPoint(9, 41, 'D');
	canvas.SetPoint(9, 42, 'D');
	canvas.SetPoint(9, 43, 'D');
	canvas.SetPoint(9, 44, 'D');
	canvas.SetPoint(9, 45, 'D');

	canvas.SetPoint(10, 40, 'D');
	canvas.SetPoint(11, 40, 'D');
	canvas.SetPoint(12, 40, 'D');
	canvas.SetPoint(10, 45, 'D');
	canvas.SetPoint(11, 45, 'D');
	canvas.SetPoint(12, 45, 'D');

	canvas.SetPoint(13, 41, 'D');
	canvas.SetPoint(14, 42, 'D');
	canvas.SetPoint(14, 43, 'D');
	canvas.SetPoint(13, 44, 'D');



	//A
	canvas.SetPoint(16, 45, 'A');
	canvas.SetPoint(16, 44, 'A');
	canvas.SetPoint(17, 43, 'A');
	canvas.SetPoint(17, 42, 'A');
	canvas.SetPoint(18, 41, 'A');

	canvas.SetPoint(19, 40, 'A');

	canvas.SetPoint(22, 45, 'A');
	canvas.SetPoint(22, 44, 'A');
	canvas.SetPoint(21, 43, 'A');
	canvas.SetPoint(21, 42, 'A');
	canvas.SetPoint(20, 41, 'A');


	canvas.SetPoint(18, 43, 'A');
	canvas.SetPoint(19, 43, 'A');
	canvas.SetPoint(20, 43, 'A');



	//N
	canvas.SetPoint(24, 45, 'N');
	canvas.SetPoint(24, 44, 'N');
	canvas.SetPoint(24, 43, 'N');
	canvas.SetPoint(24, 42, 'N');
	canvas.SetPoint(24, 41, 'N');
	canvas.SetPoint(24, 40, 'N');

	canvas.SetPoint(30, 45, 'N');
	canvas.SetPoint(30, 44, 'N');
	canvas.SetPoint(30, 43, 'N');
	canvas.SetPoint(30, 42, 'N');
	canvas.SetPoint(30, 41, 'N');
	canvas.SetPoint(30, 40, 'N');

	canvas.SetPoint(25, 41, 'N');
	canvas.SetPoint(26, 42, 'N');
	canvas.SetPoint(27, 43, 'N');
	canvas.SetPoint(28, 44, 'N');
	canvas.SetPoint(29, 45, 'N');



	//I
	canvas.SetPoint(32, 40, 'I');
	canvas.SetPoint(32, 41, 'I');
	canvas.SetPoint(32, 42, 'I');
	canvas.SetPoint(32, 43, 'I');
	canvas.SetPoint(32, 44, 'I');
	canvas.SetPoint(32, 45, 'I');



	//E
	canvas.SetPoint(34, 40, 'E');
	canvas.SetPoint(34, 41, 'E');
	canvas.SetPoint(34, 42, 'E');
	canvas.SetPoint(34, 43, 'E');
	canvas.SetPoint(34, 44, 'E');
	canvas.SetPoint(34, 45, 'E');

	canvas.SetPoint(35, 40, 'E');
	canvas.SetPoint(36, 40, 'E');
	canvas.SetPoint(37, 40, 'E');
	canvas.SetPoint(38, 40, 'E');
	canvas.SetPoint(39, 40, 'E');

	canvas.SetPoint(35, 45, 'E');
	canvas.SetPoint(36, 45, 'E');
	canvas.SetPoint(37, 45, 'E');
	canvas.SetPoint(38, 45, 'E');
	canvas.SetPoint(39, 45, 'E');

	canvas.SetPoint(35, 42, 'E');
	canvas.SetPoint(36, 42, 'E');
	canvas.SetPoint(37, 42, 'E');
	canvas.SetPoint(35, 43, 'E');
	canvas.SetPoint(36, 43, 'E');
	canvas.SetPoint(37, 43, 'E');



	//L
	canvas.SetPoint(41, 40, 'L');
	canvas.SetPoint(41, 41, 'L');
	canvas.SetPoint(41, 42, 'L');
	canvas.SetPoint(41, 43, 'L');
	canvas.SetPoint(41, 44, 'L');
	canvas.SetPoint(41, 45, 'L');

	canvas.SetPoint(42, 45, 'L');
	canvas.SetPoint(43, 45, 'L');
	canvas.SetPoint(44, 45, 'L');
	canvas.SetPoint(45, 45, 'L');
	canvas.SetPoint(46, 45, 'L');
	canvas.Print();

	return 0;
}
#include "std_lib_facilities.h"

int main()
{
	//Vari�veis pedidas pelo loop-while, number � a medida e unit serve pra controlar a grandeza dela.
	double number;
	string unit;

	//Vari�veis inicializadas para aceitar doubles menores que DBL_MAX e maiores que -DBL_MAX.
	double smallest = DBL_MAX;
	double largest = -DBL_MAX;

	//Vari�veis din�micas de soma, contagem e vetor para guardar os valores de number.
	double sum = 0.00;
	int counter = 0;
	vector<double>values;

	//Primeiro output pedindo a medida e a grandeza em seguida.
	cout << "Please enter a measurement with it`s unit (in, m, cm, ft):\n";

	//Loop-while
	while (cin >> number >> unit)
	{
		//IF-statements de controle da unidade junto com a convers�o para cm.
		//Falha quando n�o recebe in, m, ft e cm. Printa que n�o conhece a unidade de medida, deixa a janela aberta e retorna o valor 1.
		if (unit == "in")
		{
			number = number * 2.54;
		}
		else if (unit == "m")
		{
			number = number * 100;
		}
		else if (unit == "ft")
		{
			number = number * 30.48;
		}
		else if (unit == "cm")
		{
			number = number;
		}
		else
		{
			cout << "Unknown measurement unit\n";
			keep_window_open();
			return 1;
		}

		//Copia no output o n�mero
		cout << number << " centimeters\n";

		//IF-statement de controle dos maiores e menores n�meros digitados no loop.
		if (number <= smallest)
		{
			smallest = number;
			cout << "The measurement " << smallest << " is the smallest so far\n";
		}

		if (number >= largest)
		{
			largest = number;
			cout << "The measurement " << largest << " is the largest so far\n";
		}

		//Computa��es da soma, contagem, de append de n�meros no vetor values e de sort(organiza��o) do vetor values. 
		sum += number;
		++counter;
		values.push_back(number);
		sort(values);

		//Prints do contador e da soma.
		cout << "The counter of inputed numbers is: " << counter << "\n";
		cout << "The sum of the numbers is:" << sum << "\n";
		
		//Print de todos valores guardados no vetor values.
		for (int i = 0; i < values.size(); i++)
		{
			cout << values[i] << " cm\n";
		}

		//Print de um novo pedido de n�mero para continuar o loop-while.
		cout << "Please enter a number:\n";

	}

}
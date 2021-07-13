#include "std_lib_facilities.h"

int main()
{
	//Variáveis pedidas pelo loop-while, number é a medida e unit serve pra controlar a grandeza dela.
	double number;
	string unit;

	//Variáveis inicializadas para aceitar doubles menores que DBL_MAX e maiores que -DBL_MAX.
	double smallest = DBL_MAX;
	double largest = -DBL_MAX;

	//Variáveis dinâmicas de soma, contagem e vetor para guardar os valores de number.
	double sum = 0.00;
	int counter = 0;
	vector<double>values;

	//Primeiro output pedindo a medida e a grandeza em seguida.
	cout << "Please enter a measurement with it`s unit (in, m, cm, ft):\n";

	//Loop-while
	while (cin >> number >> unit)
	{
		//IF-statements de controle da unidade junto com a conversão para cm.
		//Falha quando não recebe in, m, ft e cm. Printa que não conhece a unidade de medida, deixa a janela aberta e retorna o valor 1.
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

		//Copia no output o número
		cout << number << " centimeters\n";

		//IF-statement de controle dos maiores e menores números digitados no loop.
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

		//Computações da soma, contagem, de append de números no vetor values e de sort(organização) do vetor values. 
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

		//Print de um novo pedido de número para continuar o loop-while.
		cout << "Please enter a number:\n";

	}

}
#include<iostream>
#include<string>
#include<functional>
#include<vector>
#include<algorithm>

//Функторы-классы объекты которых можно использовать вместо функций


//0-pointer
//system-memory
//programm-mem
// BSS/BRS
// Heap
// stack
// programm-args 
//()- оператор вызова


int Summ(int a, int b) { return a + b;}
int Multiply(int a, int b) { return a * b; }

using FunctionName = int (*)(int, int);//Переопределение типа данных функции 
typedef		   int(*NewName)(int, int);

void PrinyOperation(int Jane, int Jacob, FunctionName Alg ) {
	std::cout << "Our operation take params:\n" << " \tJane - " << Jane << '\n' <<
		" \tJacob - " << Jacob << '\n' << "With result - " << Alg(Jane, Jacob);

}

class Functor {
public:
	Functor(int val):num(val){ }

	void operator()(int& val) { 
		val = num; 
	}

private:
	int num;
};

void OperateArray(int *arr, int length, std::function<void(int&)> alg) {
	for (int i = 0; i < length; i++)
	{
		alg(arr[i]);
	}
}

void F02(int& j) {
	j = 9;
}


int mainEx () {
	setlocale(LC_ALL, "ru");
	int a{ 5 }, b{ 9 };
	int i;

	std::cout << Summ << " with " << a << " " << b << " args - " << Summ(a, b) << '\n';
	std::cout << Multiply << " with " << a << " " << b << " args - " << Multiply(a, b) << '\n';
	//std::cout << main<<'\n';
	std::cout << &i<<'\n';

	auto pFunc = Summ;
	int (*pFunc2)(int, int) { Summ };
	pFunc = Multiply;
	pFunc2 = Summ;

	PrinyOperation(2, 4, Multiply);
	std::cout << '\n';
	PrinyOperation(a, b, pFunc2);
	std::cout << '\n';

	int* arr = new int[6] {};
	OperateArray(arr, 6, F02);
	for (size_t i = 0; i < 6; i++)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << '\n';

	Functor funtic(4);

	OperateArray(arr, 6, funtic);
	for (size_t i = 0; i < 6; i++)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << '\n';

	return 0;
}

#include<random>

bool More(int a, int b) {
	return a > b;
}

struct Runner {
	int id;
	double result;
	std::string Name;
};



int main() {
	std::vector<int>arr;
	for (int i = 0; i < 20; i++)
	{
		arr.push_back(i + 1);
	}

	std::shuffle(arr.begin(), arr.end(), std::random_device());//shuffle спецефический алгоритм, который перемешивает коллекцию.
	for (auto& i : arr) {
		std::cout << i << ' ';
	}
	std::cout << '\n';

	//сортирует коллекцию по возрастанию если знает как сравнивать соседние элементы на меньше. В остальных случаях требуется передать правила сравнения 
	std::sort(arr.begin(), arr.end(), More);
	for (auto& i : arr) {
		std::cout << i << ", ";
	}
	std::cout << "\b\b \n";

	std::vector<Runner> lBoard{
		{1,123.4,"Joe"},
		{3,122.6,"Ken"},
		{4,115.3,"Tomas"},
		{6,145.7,"Alex"},
		{7,115.1,"Georgy"}
	};

	for (const auto& i : lBoard) {
		std::cout << "ID: " << i.id << ' ';
		std::cout << "Name: " << i.Name << ' ';
		std::cout << "Result: " << i.result << '\n';
	}

	//Анонимные(лямбда) функции
	//[захват контекста](перечень аргументов)->предписываемый тип возврата{тело функции}

	auto funk = [](int a)->bool {
		if (a % 2) {
			return a % 2;
		}
		else {
			return false;
		}
		};

	std::cout << funk(4) << "\n\n";

	std::sort(lBoard.begin(), lBoard.end(), [](const Runner& a, const Runner& b)->bool {
		return a.result <  b.result;
		}
	);

	for (const auto& i : lBoard) {
		std::cout << "ID: " << i.id << ' ';
		std::cout << "Name: " << i.Name << ' ';
		std::cout << "Result: " << i.result << '\n';
	}


	return 0;
}
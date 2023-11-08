#include <iostream>

	//все локальные переменные ограничиваюится строго тем блоком и теми фигурными скобачками,
	// в рамках которых они были созданы

int NUM; //глобальная переменная
const double PI = 3.14; // глобальная константа
const int SIZE = 5; // глобальная константа
int ARR[SIZE]; // глобальный массив
void num_inc() {
	NUM++;
}
void func() {
	static int a = 0; //статическая переменная которая не удаляется при завершении работы программы. Создается 1 раз
	a++;
	std::cout << a << std::endl;
	if (a % 5 == 0)
		std::cout << "---\n";
}
int power(int num1, int num2 = 2) {
	int result = 1;
	for (int i = 1; i <= num2; i++)
		result *= num1;
	return result;
}
inline double absolute(double num) {
	return (num < 0.0 ? -num : num);
}
int max(int num1, int num2) {
	std::cout << "TWO INTS\n";
	return num1 > num2 ? num1 : num2;
}
double max(double num1, double num2) {
	std::cout << "TWO DOUBLES\n";
	return num1 > num2 ? num1 : num2;
}
char max(char sym1, char sym2) {
	std::cout << "TWO CHARS\n";
	return sym1 > sym2 ? sym1 : sym2;
}
int max(int num1, int num2,int num3) {
	std::cout << "Three INTS\n";
	return num1 > (max(num2, num3)) ? num1 : max(num2, num3);
}
//Шаблонная функция
template <typename T>
void print_arr(T arr[], const int length) {
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ' ';
	std::cout << std::endl;
}
int main() {
	setlocale(LC_ALL, "ru");
	int n;
	//Области видимости данных
	
	std::cout << NUM << std::endl;
	num_inc();
	std::cout << NUM << std::endl;
	std::cout << "PI = " << PI << std::endl;
	for(int i = 0; i < 15;i++)
		func();
	

	//Области применения статических переменных:
	//1. Сохранение данных из вызова в вызов функции;
	//2. Экономия памяти и времени выполнения;
	//3. Создание общих элементов относящихся к конкретным группам объектов;
	
	//Передача данных в функуию.
	//Параметры по умолчанию
	
	std::cout << "5^4 = " << power(5, 4) << std::endl;
	std::cout << "4^2 = " << power(4) << std::endl;
	std::cout << "8^3 = " << power(8, 3) << std::endl;
	std::cout << "15^2 = " << power(15) << std::endl;
	
	// Встраиваемая функция
	
	std::cout << "Введите число -> ";
	std::cin >> n;
	std::cout << '|' << n << "| = " << absolute(n) << std::endl;

	//Функцию невозможно встроить , если место, в котором она вызывается, не может содержать в себе код, описанный в теле функции. Например:
	// 1. Слишком Большой размер функции
	// 2. Функция повторяется в одном и том же выражении несколько раз.
	// 3. Функция содержит управляющие конструкции(цикл, ветвления и т.д.)
	// 4. Функция является рекурсией.
	
	//Перегруженная функция
	
	std::cout << max(5, 7) << std::endl;
	std::cout << max(1.3, 1.03) << std::endl;
	std::cout << max( 'a', 'A') << std::endl;
	std::cout << max(5, 7, 9) << std::endl;
	
	// Шаблонная функция
	const int size = 5;
	int arr[size]{10,20,30,40,50};
	std::cout << "Массив: \n";
	print_arr(arr, size);





	return 0;
}
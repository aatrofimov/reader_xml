//
#include "stdafx.h" //предкомпилированный заголовок

void main(void)
{
	// создание файла output.txt для выходного потока
	std::ofstream fout("output.txt", std::ios_base::out);

	// создание объекта doc класса pugi::xml_document для работы с документами формата xml
	pugi::xml_document doc;
	
	// создание объекта result класса pugi::xml_parse_result, хранаящего результат парсинга файла
	pugi::xml_parse_result result = doc.load_file("config.xml", pugi::parse_default | pugi::parse_comments);

	// вывод сообщения о результате загрузки документа на экран и в файл
	std::cout << "Load result: " << result.description() << std::endl; 
	     fout << "Load result: " << result.description() << std::endl;

	// чтение комментария файла (текст в тегах <!--  -->) при помощи метода value();
	// конвертирование полученных данных в стандартные кодировки windows и вывод в консоль и в файл
	std::cout << converter(doc.first_child().value(), "UTF-8", "cp866") << std::endl;
		 fout << converter(doc.first_child().value(), "UTF-8", "cp1251") << std::endl;
	
	// переменная, хранящая код требуемой пользователем конфигурации эксперимента
	std::string num;

		 // вывод на экран строки "Введите номер эксперимента : " в формате cp866
		 std::cout << "‚ўҐ¤ЁвҐ ­®¬Ґа нЄбЇҐаЁ¬Ґ­в  : ";
		 // получение кода конфигурации
		 std::cin >> num;
		 std::cout << std::endl;

	// создание объекта setups класса pugi::xml_node и переход к элементам <setups> с помощью метода child()
	pugi::xml_node setups = doc.child("config").child("setups");

	// поиск необходимой конфигурации в цикле по атрибутам setups
	std::string chek;
	while (1)
		{
			// создание объекта code класса pugi::xml_attribute и присвоение ему первого атрибута элемента <setups>
			pugi::xml_attribute code = setups.first_attribute();

			// получение значения этого атрибута
			chek = code.value();

			// сравниваем значение атрибута с хранящимся в переменной num
			// "error" - значение атрибута в последнем элементе <setups> для вывода ошибки
			if ((chek == num) || (chek == "error"))
			{
				std::cout << " " << code.name() << " = " << code.value() << std::endl;
				break;
			}

			// переход к следующему элементу <setups>
			setups = setups.next_sibling();
		}
	
	// вывод на экран и в файл значение элемента в тегах <name></name>
	std::cout << converter(setups.child_value("name"), "UTF-8", "cp866") << std::endl;
	fout << converter(setups.child_value("name"), "UTF-8", "cp1251") << std::endl;

	// вывод на экран и в файл значение элемента в тегах <comment></comment>
	std::cout << converter(setups.child_value("comment"), "UTF-8", "cp866") << std::endl;
	fout << converter(setups.child_value("comment"), "UTF-8", "cp1251") << std::endl;

	// еслиискомой конфигурации нет в конфигурационном файле (т.е. chek == "error"), то следующие действия не выполняются
	if (chek != "error")
	{
		// создание объекта grid класса pugi::xml_node для работы с элементами <grid></grid>
		pugi::xml_node grid = setups.child("settings").child("grid");

		// считывание информации для 22-х модуляторов
		for (int i = 0; i < 22; i++)
		{
			// создание объекта number класса pugi::xml_attribute и присвоение ему первого атрибута элемента <grid>
			pugi::xml_attribute number = grid.first_attribute();

			// вывод на экран имени атрибута и его значения (номер модулятора)
			std::cout << number.name() << " = " << number.value() << std::endl;;
			// вывод на экран значения режима работы модулятора
			std::cout << converter(grid.child_value("mode"), "UTF-8", "cp866") << std::endl;
			// вывод на экран значения напряжения в вольтах для каждого модулятора
			std::cout << grid.child_value("voltage") << std::endl;
			// вывод на экран значения времени заряда индуктивного накопителя в миллисекундах 
			std::cout << grid.child_value("charge_time") << std::endl << std::endl;

			// то же самое, только в файл output.txt
			fout << number.name() << " = " << number.value() << std::endl;;
			fout << converter(grid.child_value("mode"), "UTF-8", "cp1251") << std::endl;
			fout << grid.child_value("voltage") << std::endl;
			fout << grid.child_value("charge_time") << std::endl << std::endl;

			// переход к следующему элементу <grid>
			grid = grid.next_sibling();
		}
	}

	// закрытие файла output.txt
	fout.close();

	std::system("pause");
}
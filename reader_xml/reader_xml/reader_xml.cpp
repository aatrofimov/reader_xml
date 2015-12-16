//
#include "stdafx.h" //������������������� ���������

void main(void)
{
	// �������� ����� output.txt ��� ��������� ������
	std::ofstream fout("output.txt", std::ios_base::out);

	// �������� ������� doc ������ pugi::xml_document ��� ������ � ����������� ������� xml
	pugi::xml_document doc;
	
	// �������� ������� result ������ pugi::xml_parse_result, ���������� ��������� �������� �����
	pugi::xml_parse_result result = doc.load_file("config.xml", pugi::parse_default | pugi::parse_comments);

	// ����� ��������� � ���������� �������� ��������� �� ����� � � ����
	std::cout << "Load result: " << result.description() << std::endl; 
	     fout << "Load result: " << result.description() << std::endl;

	// ������ ����������� ����� (����� � ����� <!--  -->) ��� ������ ������ value();
	// ��������������� ���������� ������ � ����������� ��������� windows � ����� � ������� � � ����
	std::cout << converter(doc.first_child().value(), "UTF-8", "cp866") << std::endl;
		 fout << converter(doc.first_child().value(), "UTF-8", "cp1251") << std::endl;
	
	// ����������, �������� ��� ��������� ������������� ������������ ������������
	std::string num;

		 // ����� �� ����� ������ "������� ����� ������������ : " � ������� cp866
		 std::cout << "������ ����� �ᯥਬ��� : ";
		 // ��������� ���� ������������
		 std::cin >> num;
		 std::cout << std::endl;

	// �������� ������� setups ������ pugi::xml_node � ������� � ��������� <setups> � ������� ������ child()
	pugi::xml_node setups = doc.child("config").child("setups");

	// ����� ����������� ������������ � ����� �� ��������� setups
	std::string chek;
	while (1)
		{
			// �������� ������� code ������ pugi::xml_attribute � ���������� ��� ������� �������� �������� <setups>
			pugi::xml_attribute code = setups.first_attribute();

			// ��������� �������� ����� ��������
			chek = code.value();

			// ���������� �������� �������� � ���������� � ���������� num
			// "error" - �������� �������� � ��������� �������� <setups> ��� ������ ������
			if ((chek == num) || (chek == "error"))
			{
				std::cout << " " << code.name() << " = " << code.value() << std::endl;
				break;
			}

			// ������� � ���������� �������� <setups>
			setups = setups.next_sibling();
		}
	
	// ����� �� ����� � � ���� �������� �������� � ����� <name></name>
	std::cout << converter(setups.child_value("name"), "UTF-8", "cp866") << std::endl;
	fout << converter(setups.child_value("name"), "UTF-8", "cp1251") << std::endl;

	// ����� �� ����� � � ���� �������� �������� � ����� <comment></comment>
	std::cout << converter(setups.child_value("comment"), "UTF-8", "cp866") << std::endl;
	fout << converter(setups.child_value("comment"), "UTF-8", "cp1251") << std::endl;

	// ����������� ������������ ��� � ���������������� ����� (�.�. chek == "error"), �� ��������� �������� �� �����������
	if (chek != "error")
	{
		// �������� ������� grid ������ pugi::xml_node ��� ������ � ���������� <grid></grid>
		pugi::xml_node grid = setups.child("settings").child("grid");

		// ���������� ���������� ��� 22-� �����������
		for (int i = 0; i < 22; i++)
		{
			// �������� ������� number ������ pugi::xml_attribute � ���������� ��� ������� �������� �������� <grid>
			pugi::xml_attribute number = grid.first_attribute();

			// ����� �� ����� ����� �������� � ��� �������� (����� ����������)
			std::cout << number.name() << " = " << number.value() << std::endl;;
			// ����� �� ����� �������� ������ ������ ����������
			std::cout << converter(grid.child_value("mode"), "UTF-8", "cp866") << std::endl;
			// ����� �� ����� �������� ���������� � ������� ��� ������� ����������
			std::cout << grid.child_value("voltage") << std::endl;
			// ����� �� ����� �������� ������� ������ ������������ ���������� � ������������� 
			std::cout << grid.child_value("charge_time") << std::endl << std::endl;

			// �� �� �����, ������ � ���� output.txt
			fout << number.name() << " = " << number.value() << std::endl;;
			fout << converter(grid.child_value("mode"), "UTF-8", "cp1251") << std::endl;
			fout << grid.child_value("voltage") << std::endl;
			fout << grid.child_value("charge_time") << std::endl << std::endl;

			// ������� � ���������� �������� <grid>
			grid = grid.next_sibling();
		}
	}

	// �������� ����� output.txt
	fout.close();

	std::system("pause");
}
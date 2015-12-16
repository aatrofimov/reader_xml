// stdafx.h: ���������� ���� ��� ����������� ��������� ���������� ������
// ��� ���������� ������ ��� ����������� �������, ������� ����� ������������, ��
// �� ����� ����������
//

#pragma once

#include "targetver.h"

#include "pugixml.hpp"
#include "iconv.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

// ����������� ���������� libiconv, ������������ ��� ����������� ������������� ������
#pragma comment (lib, "libiconv.lib")

// ����������� ���������� ������� pugixml
#ifdef _DEBUG
#pragma comment(lib, "pugixmld.lib")
#else
#pragma comment(lib, "pugixml.lib")
#endif

// ������� converter, �������������� ������ �������� � ��������� fromcode, � ������ � ��������� tocode
std::string converter(const char * input, const char * fromcode, const char * tocode);

// TODO: ���������� ����� ������ �� �������������� ���������, ����������� ��� ���������

// stdafx.h: включаемый файл дл€ стандартных системных включаемых файлов
// или включаемых файлов дл€ конкретного проекта, которые часто используютс€, но
// не часто измен€ютс€
//

#pragma once

#include "targetver.h"

#include "pugixml.hpp"
#include "iconv.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

// подключение библиотеки libiconv, используемой дл€ корректного представлени€ данных
#pragma comment (lib, "libiconv.lib")

// подключение библиотеки парсера pugixml
#ifdef _DEBUG
#pragma comment(lib, "pugixmld.lib")
#else
#pragma comment(lib, "pugixml.lib")
#endif

// функци€ converter, конвертирующа€ массив символов в кодировке fromcode, в строку в кодировке tocode
std::string converter(const char * input, const char * fromcode, const char * tocode);

// TODO: ”становите здесь ссылки на дополнительные заголовки, требующиес€ дл€ программы

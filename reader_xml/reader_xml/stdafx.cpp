// stdafx.cpp: исходный файл, содержащий только стандартные включаемые модули
// reader_xml.pch будет предкомпилированным заголовком
// stdafx.obj будет содержать предварительно откомпилированные сведения о типе

#include "stdafx.h"
// определение функции converter
std::string converter(const char * input, const char * fromcode, const char * tocode)
{
	int n = strlen(input) + 1; // 
	char * src = new char[n];

	for (int i = 0; i < n; i++)
		src[i] = input[i];
	src[n - 1] = '\0'; // добавление символа завершения строки в конец массива

	char *dst = new char[n];

	size_t srclen = n;
	size_t dstlen = n;

	const char * pIn = src;
	char * pOut = (char*)dst;

	// iconv_open - определяет параметр для изменения кодировки набора символов
	iconv_t conv = iconv_open(tocode, fromcode);
	// iconv - изменяет кодировку набора символов  
	iconv(conv, &pIn, &srclen, &pOut, &dstlen);
	// iconv_close - уничтожает параметр conv, служащий для изменения кодировки символов, созданный ранее функцией iconv_open 
	iconv_close(conv);

	return std::string(dst);
	delete src;
	delete dst;
}
// TODO: Установите ссылки на любые требующиеся дополнительные заголовки в файле STDAFX.H
// , а не в данном файле

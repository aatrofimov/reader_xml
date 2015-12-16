// stdafx.cpp: �������� ����, ���������� ������ ����������� ���������� ������
// reader_xml.pch ����� ������������������� ����������
// stdafx.obj ����� ��������� �������������� ����������������� �������� � ����

#include "stdafx.h"
// ����������� ������� converter
std::string converter(const char * input, const char * fromcode, const char * tocode)
{
	int n = strlen(input) + 1; // 
	char * src = new char[n];

	for (int i = 0; i < n; i++)
		src[i] = input[i];
	src[n - 1] = '\0'; // ���������� ������� ���������� ������ � ����� �������

	char *dst = new char[n];

	size_t srclen = n;
	size_t dstlen = n;

	const char * pIn = src;
	char * pOut = (char*)dst;

	// iconv_open - ���������� �������� ��� ��������� ��������� ������ ��������
	iconv_t conv = iconv_open(tocode, fromcode);
	// iconv - �������� ��������� ������ ��������  
	iconv(conv, &pIn, &srclen, &pOut, &dstlen);
	// iconv_close - ���������� �������� conv, �������� ��� ��������� ��������� ��������, ��������� ����� �������� iconv_open 
	iconv_close(conv);

	return std::string(dst);
	delete src;
	delete dst;
}
// TODO: ���������� ������ �� ����� ����������� �������������� ��������� � ����� STDAFX.H
// , � �� � ������ �����

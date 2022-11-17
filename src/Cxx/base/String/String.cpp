#include "String.h"

namespace Cxx {
namespace base {
CXX_OBJECT_REALIZATION(Cxx::lang::base::String)

i32 String::StrLen(const c8 *str) {
	i32 n = 0;
	for (const c8 *p = str; *p != 0; p++)
		n++;
	return n;
}

void String::StrCpy(const c8 *strSrc, c8 *strDest) {
	const c8 *p1 = strSrc;
	c8 *p2 = strDest;
	for (; *p1 != 0; p1++, p2++)
		*p2 = *p1;
	*p2 = 0;
}

void String::StrNCpy(const c8 *strSrc, c8 *strDest, i32 n) {
	const c8 *p1 = strSrc;
	c8 *p2 = strDest;
	for (i32 i = 0; *p1 != 0 && i < n; p1++, p2++, i++)
		*p2 = *p1;
}

c8* String::Splice(const c8 *str1, const c8 *str2) {
	c8 *newString = new c8[StrLen(str1) + StrLen(str2) + 1];
	const c8 *p1 = str1;
	const c8 *p2 = str2;
	c8 *q = newString;

	while (*p1 != 0) {
		*q = *p1;
		q++;
		p1++;
	}

	while (*p2 != 0) {
		*q = *p2;
		q++;
		p2++;
	}

	*q = 0;

	return newString;
}

bool String::StrCmp(const c8 *str1, const c8 *str2) {
	const c8 *p1 = str1;
	const c8 *p2 = str2;

	while (*p1 == *p2) {
		if (*p1 == 0)
			return true;
		p1++;
		p2++;
	}

	return false;
}

bool String::StrNCmp(const c8 *str1, const c8 *str2, i32 n) {
	const c8 *p1 = str1;
	const c8 *p2 = str2;

	for (i32 i = 0; i < n; p1++, p2++, i++)
		if (*p1 != *p2)
			return false;

	return true;
}

i32 String::SearchSubString(const c8 *strSrc, const c8 *strA) {
	i32 index = 0;
	i32 n = StrLen(strA);
	while (strSrc[index] != 0) {
		if (StrNCmp(strSrc + index, strA, n) == true)
			return index;
		index++;
	}

	return -1;
}

c8* String::ReplaceSubString(const c8 *strSrc, const c8 *strA, const c8 *strB) {
	i32 index = SearchSubString(strSrc, strA);
	if (index == -1) {
		return nullptr;
	}

	i32 lengthSrc = StrLen(strA);
	i32 lengthA = StrLen(strA);
	i32 lengthB = StrLen(strB);

	c8 *newStr = new c8[lengthSrc - lengthA + lengthB + 1];

	StrNCpy(strSrc, newStr, index + 1);
	StrNCpy(strB, newStr + index, lengthB);
	StrCpy(strSrc + index + lengthA, newStr + index + lengthB);

	return newStr;
}

String& String::init() {
	init("");
	return self;
}

void String::remove() {
}

String& String::init(const c8 *string) {
	this->length = StrLen(string) + 1;

	if (this->string != nullptr)
		delete[] (this->string);

	this->string = new c8[this->length + 1];
	StrCpy(string, this->string);

	return self;
}

String& String::copy(const String &other) {
	return self;
}

String& String::move(String &&other) {
	return self;
}

bool operator !=(const String &str1, const String &str2) {
	return !(str1 == str2);
}

const c8* String::toCharArray() const {
	return this->string;
}

const i32 String::getLength() const {
	return this->length;
}

String& String::append(const String &other) {

	return self;
}

c8 String::charAt(i32 i) const {
	if (i < 0 || i >= length)
		throw "错误";
	return string[i];
}

c8 String::operator [](i32 i) const {
	return charAt(i);
}

String operator +(const String &str1, const char *str2) {
	return String(String::Splice(str1.string, str2));
}

String operator +(const char *str1, const String &str2) {
	return String(String::Splice(str1, str2.string));
}

String operator +(const String &str1, const String &str2) {
	return String(String::Splice(str1.string, str2.string));
}

bool operator ==(const String &str1, const char *str2) {
	return String::StrCmp(str1.string, str2);
}

bool operator ==(const char *str1, const String &str2) {
	return String::StrCmp(str1, str2.string);
}

bool operator ==(const String &str1, const String &str2) {
	return String::StrCmp(str1.string, str2.string);
}

bool operator !=(const String &str1, const char *str2) {
	return !(str1 == str2);
}

bool operator !=(const char *str1, const String &str2) {
	return !(str1 == str2);
}

}
}

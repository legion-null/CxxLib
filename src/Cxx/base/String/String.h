#pragma once

#include "Cxx/base/Object/Object.h"

namespace Cxx {
namespace base {

class String: extends Object {
CXX_OBJECT_DEF(String)

public:
	static i32 StrLen(const c8 *str);
	static void StrCpy(const c8 *strSrc, c8 *strDest);
	static void StrNCpy(const c8 *strSrc, c8 *strDest, i32 n);

	static c8* Splice(const c8 *str1, const c8 *str2);

	static bool StrCmp(const c8 *str1, const c8 *str2);
	static bool StrNCmp(const c8 *str1, const c8 *str2, i32 n);

	static i32 SearchSubString(const c8 *strSrc, const c8 *strA);
	static c8* ReplaceSubString(const c8 *strSrc, const c8 *strA, const c8 *strB);

protected:
	c8 *string = nullptr;
	i32 length = 0;

public:
	String(const c8 *string) {
		init(string);
	}

public:
	virtual String& init() override;
	virtual void remove() override;

public:
	String& init(const c8 *string);

public:
	String& copy(const String &other);
	String& move(String &&other);

public:
	const c8* toCharArray() const;
	const i32 getLength() const;

public:
	String& append(const String &other);

public:
	c8 charAt(i32 i) const;
	c8 operator[](i32 i) const;

public:
	friend String operator +(const String &str1, const char *str2);
	friend String operator +(const char *str1, const String &str2);
	friend String operator +(const String &str1, const String &str2);

	friend bool operator ==(const String &str1, const char *str2);
	friend bool operator ==(const char *str1, const String &str2);
	friend bool operator ==(const String &str1, const String &str2);

	friend bool operator !=(const String &str1, const char *str2);
	friend bool operator !=(const char *str1, const String &str2);
	friend bool operator !=(const String &str1, const String &str2);

};

String operator +(const String &str1, const char *str2);
String operator +(const char *str1, const String &str2);
String operator +(const String &str1, const String &str2);

bool operator ==(const String &str1, const char *str2);
bool operator ==(const char *str1, const String &str2);
bool operator ==(const String &str1, const String &str2);

bool operator !=(const String &str1, const char *str2);
bool operator !=(const char *str1, const String &str2);
bool operator !=(const String &str1, const String &str2);

}
}

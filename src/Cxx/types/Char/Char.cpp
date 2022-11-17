#include "Cxx/Cxx.h"

import Cxx;
import Cxx::base;
import Cxx::dev;

namespace Cxx {
namespace types {

bool Char::IsAlnum(i32 ch) {
	CharData &charData = (CharData&) ch;

	if (charData.ASCII.blank != 0)
		return false;

	if ((charData.ASCII.ch >= '0' and charData.ASCII.ch <= '9') or	//
			(charData.ASCII.ch >= 'A' and charData.ASCII.ch <= 'Z') or	//
			(charData.ASCII.ch >= 'a' and charData.ASCII.ch <= 'z'))	//
		return true;

	return false;

}

bool Char::IsAlpha(i32 ch) {
	CharData &charData = (CharData&) ch;

	if (charData.ASCII.blank != 0)
		return false;
	if ((charData.ASCII.ch >= 'A' and charData.ASCII.ch < 'Z') or	//
			(charData.ASCII.ch >= 'a' and charData.ASCII.ch < 'z'))		//
		return true;
	return false;
}

bool Char::IsBlank(i32 ch) {
	CharData &charData = (CharData&) ch;

	if (charData.ASCII.blank != 0)
		return false;
	if (charData.ASCII.ch == ' ')
		return true;
	if (charData.ASCII.ch == '\t')
		return true;
	return false;
}

bool Char::IsCntrl(i32 ch) {
	CharData &charData = (CharData&) ch;

	if (charData.ASCII.blank != 0)
		return false;
	if ((charData.ASCII.ch >= 0x00 and charData.ASCII.ch <= 0x10) or		//
			charData.ASCII.ch == 0x7F)	//
		return true;
	return false;
}

bool Char::IsDigit(i32 ch) {
	CharData &charData = (CharData&) ch;

	if (charData.ASCII.blank != 0)
		return false;
	if (charData.ASCII.ch >= '0' and charData.ASCII.ch <= '9')
		return true;
	return false;
}

bool Char::IsGraph(i32 ch) {
	CharData &charData = (CharData&) ch;
	if (charData.ASCII.blank != 0)
		return false;
	if (charData.ASCII.ch > ' ' and charData.ASCII.ch <= '~')
		return true;
	return false;

}

bool Char::IsLower(i32 ch) {
	CharData &charData = (CharData&) ch;

	if (charData.ASCII.blank != 0)
		return false;
	if (charData.ASCII.ch >= 'a' and charData.ASCII.ch <= 'z')
		return true;
	return false;
}

bool Char::IsPrint(i32 ch) {
	CharData &charData = (CharData&) ch;

	if (charData.ASCII.blank != 0)
		return false;
	if (charData.ASCII.ch >= ' ' and charData.ASCII.ch <= '~')
		return true;
	return false;
}

bool Char::IsPunct(i32 ch) {
	CharData &charData = (CharData&) ch;

	if (charData.ASCII.blank != 0)
		return false;
	if (true)
		return true;
	return false;
}

bool Char::IsSpace(i32 ch) {
	CharData &charData = (CharData&) ch;

	if (charData.ASCII.blank != 0)
		return false;
	if (charData.ASCII.ch == 0x7F or	//
			(charData.ASCII.ch >= 0x00 and charData.ASCII.ch <= 0x10))	//
		return false;
	return true;
}

bool Char::IsUpper(i32 ch) {
	CharData &charData = (CharData&) ch;

	if (charData.ASCII.blank != 0)
		return false;
	if (charData.ASCII.ch >= 'A' and charData.ASCII.ch <= 'Z')
		return true;
	return false;

}

bool Char::IsXDigit(i32 ch) {
	CharData &charData = (CharData&) ch;

	if (charData.ASCII.blank != 0)
		return false;
	if ((charData.ASCII.ch >= '0' and charData.ASCII.ch <= '9') or	//
			(charData.ASCII.ch >= 'a' and charData.ASCII.ch <= 'f') or	//
			(charData.ASCII.ch >= 'A' and charData.ASCII.ch <= 'F'))	//
		return true;
	return false;

}

i32 Char::ToLower(i32 ch) {
	if (IsUpper(ch))
		return ch + 'a' - 'A';
	return ch;
}

i32 Char::ToUpper(i32 ch) {
	if (IsUpper(ch))
		return ch + 'A' - 'a';
	return ch;
}

Char& Char::init() {
	return self;
}

void Char::remove() {

}

Char& Char::init(i32 value) {
	setValue(value);
	return self;
}

Char& Char::init(const c8 *chars) {
	setCharacter(chars);
	return self;
}

Char& Char::copy(const Char &other) {
	return self;
}

Char& Char::move(Char &&other) {
	return self;
}

i32 Char::getValue() const {
	return ch.value;
}

void Char::setValue(i32 value) {
	ch.value = value;
}

const c8* Char::getCharacter() const {
	return ch.chars;
}

void Char::setCharacter(const c8 *chars) {
	ch.chars[0] = chars[0];
	ch.chars[1] = chars[1];
	ch.chars[2] = chars[2];
	ch.chars[3] = chars[3];
}

}
}

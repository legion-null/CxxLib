#pragma once

#include "Cxx/base/Object/Object.h"

namespace Cxx {
namespace types {

class Char: extends base::Object {
CXX_OBJECT_DEF(Char)

public:
	typedef enum Type : i8 {
		ASCII, GBK, UTF_8, UTF_16, UTF_32
	} Encoding;

public:
	static bool IsAlnum(i32 ch);
	static bool IsAlpha(i32 ch);
	static bool IsBlank(i32 ch);
	static bool IsCntrl(i32 ch);
	static bool IsDigit(i32 ch);
	static bool IsGraph(i32 ch);
	static bool IsLower(i32 ch);
	static bool IsPrint(i32 ch);
	static bool IsPunct(i32 ch);
	static bool IsSpace(i32 ch);
	static bool IsUpper(i32 ch);
	static bool IsXDigit(i32 ch);

	static i32 ToLower(i32 ch);
	static i32 ToUpper(i32 ch);

protected:
	struct ASCII {
		i32 blank :24;
		i8 ch;
	} __attribute__((packed));

	struct GBK {
		i32 blank :16;
		i8 ch[2];
	} __attribute__((packed));

	struct UTF_8 {
		i8 ch[4];
	} __attribute__((packed));

	struct UTF_16 {
		i16 ch[2];
	} __attribute__((packed));

	struct UTF_32 {
		i32 ch;
	} __attribute__((packed));

	typedef union {
		i32 value;
		c8 chars[4];
		struct ASCII ASCII;
		struct GBK GBK;
		struct UTF_8 UTF_8;
		struct UTF_16 UTF_16;
		struct UTF_32 UTF_32;
	} __attribute__((packed)) CharData;

protected:
	CharData ch;

public:
	Char(i32 value){
		init(value);
	}

	Char(const c8 *chars){
		init(chars);
	}

public:
	Char& operator=(i32 value){
		return init(value);
	}

	Char& operator=(const c8 *chars){
		return init(chars);
	}

public:
	virtual Char& init() override;
	virtual void remove() override;

public:
	Char& init(i32 value);
	Char& init(const c8 *chars);

public:
	Char& copy(const Char &other);
	Char& move(Char &&other);

public:
	i32 getValue() const;
	void setValue(i32 value);

	const c8* getCharacter() const;
	void setCharacter(const c8 *chars);

public:

};

}
}

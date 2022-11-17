#pragma once

#include "Cxx/base/Object/Object.h"

namespace Cxx {
namespace io {

class File: extends base::Object {
CXX_OBJECT_DEF(File)

public:
	typedef enum StandardIOFile : i8 {
		StandardIn = 0, StandardOut = 1, StandardErr = 2
	} StandardIOFile;

public:
	static File StandardInput;
	static File StandardOutput;
	static File StandardError;

protected:
	class FileData *file = nullptr;
	i64 pos = 0;
	i64 size = 0;

public:
	File(const base::String &path, const base::String &mode) {
		init(path, mode);
	}

	File(StandardIOFile stdio) {
		init(stdio);
	}

public:
	virtual File& init() override;
	virtual void remove() override;

public:
	File& init(const base::String &path, const base::String &mode);
	File& init(StandardIOFile stdio);

public:
	File& copy(const File &other);
	File& move(File &&other);

public:
	void close();

	void flush();

public:
	i32 readByte();
	void read(byte *b, i32 len);

public:
	void writeByte(byte b);
	void write(byte *b, i32 len);

public:
	i64 getSize() const;

public:
	i64 getPos() const;

	void setPos(i64 pos);

};

}
}

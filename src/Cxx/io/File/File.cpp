#include "Cxx/Cxx.h"

import Cxx;
import Cxx::base;
import Cxx::dev;

#include <stdio.h>

namespace Cxx {
namespace io {
CXX_OBJECT_REALIZATION(Cxx::io::File)

typedef struct FileData {
	FILE *fp;
} __attribute__((packed)) FileData;

File File::StandardInput = File(StandardIn);
File File::StandardOutput = File(StandardOut);
File File::StandardError = File(StandardErr);

File& File::init() {
	remove();
	this->file = new FileData;
	return self;
}

void File::remove() {
	if (file != nullptr && file->fp != stdin && file->fp != stdout && file->fp != stderr) {
		close();
	}
}

File& File::init(const base::String &path, const base::String &mode) {
	init();
	file->fp = ::fopen(path.toCharArray(), mode.toCharArray());
	size = ::fseek(file->fp, 0, SEEK_END);
	setPos(0);

	return self;
}

File& File::init(StandardIOFile stdio) {
	init();

	switch (stdio) {
	case StandardIn:
		file->fp = stdin;
		break;
	case StandardOut:
		file->fp = stdout;
		break;
	case StandardErr:
		file->fp = stderr;
		break;
	}

	return self;
}

File& File::copy(const File &other) {
	return self;
}

File& File::move(File &&other) {
	return self;
}

void File::close() {
	::fclose(file->fp);
}

void File::flush() {
	::fflush(file->fp);
}

i32 File::readByte() {
	return ::fgetc(file->fp);
}

void File::read(byte *b, i32 len) {
	::fread(b, 1, len, file->fp);
}

void File::writeByte(byte b) {
	::fputc(b, file->fp);
}

void File::write(byte *b, i32 len) {
	::fwrite(b, 1, len, file->fp);
}

i64 File::getSize() const {
	return size;
}

i64 File::getPos() const {
	return pos;
}

void File::setPos(i64 pos) {
	this->pos = pos;
	::fseek(file->fp, pos, SEEK_SET);
}

}
}

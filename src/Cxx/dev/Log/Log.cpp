#include "Cxx/Cxx.h"

import Cxx;
import Cxx::base;
import Cxx::dev;

#include <stdio.h>
#include <stdarg.h>

import Cxx::base;

namespace Cxx {
namespace dev {
CXX_ABSTRACT_OBJECT_REALIZATION(Cxx::dev::Log)

bool Log::TypeEnable[8] = { true, true, true, true, true, true, true, true };

bool Log::IsEnable(Type type) {
	return TypeEnable[type];
}

void Log::LOG(Type type, const String &string) {
	if (!IsEnable(type))
		return;

	::puts(string.toCharArray());
}

void Log::Print(Type type, const c8 *fmt, ...) {
	if (!IsEnable(type))
		return;

	va_list args;
	va_start(args, fmt);
	vprintf(fmt, args);
	va_end(args);

	fflush (stdout);
}

void Log::Scanf(const c8 *fmt, ...) {
	va_list args;
	va_start(args, fmt);
	vscanf(fmt, args);
	va_end(args);

	fflush (stdin);
}
}
}

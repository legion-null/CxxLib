#pragma once

#include "Cxx/base/Object/Object.h"

namespace Cxx {
namespace dev {

class Log: extends base::Object {
CXX_ABSTRACT_OBJECT_DEF(Log)
public:
	typedef enum : i8 {
		SeriousError,		// 严重错误
		Error,				// 错误
		SmallError,			// 小错误
		SeriousWarning,		// 严重警告
		Warning,			// 警告
		SmallWarning,		// 轻微警告
		GeneralLog,			// 普通日志
		DebugLog			// 调试日志
	} Type;

private:
	static bool TypeEnable[8];

protected:
	static bool IsEnable(Type type);

public:
	static void LOG(Type type, const base::String &string);
	static void Print(Type type, const c8 *fmt, ...);
	static void Scanf(const c8 *fmt, ...);
};

}
}

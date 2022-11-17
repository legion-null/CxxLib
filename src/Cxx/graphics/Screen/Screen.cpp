#include "Cxx/Cxx.h"

import Cxx;
import Cxx::base;
import Cxx::dev;

namespace Cxx {
namespace graphics {
CXX_OBJECT_REALIZATION(Cxx::gui::Screen)

Screen& Screen::init() {
	return self;
}

void Screen::remove() {
}

Screen& Screen::init(i32 width, i32 height, i32 bpp, Graphics::Rot rot) {
	Canvas::init(width, height, bpp, rot);
	Log::Print(Log::DebugLog, "Screen::Screen(%d, %d, %d, %d)\n", width, height, bpp, rot);

	return self;
}

Screen& Screen::copy(const Screen &other) {
	return self;
}

Screen& Screen::move(Screen &&other) {
	return self;
}

void Screen::test() {
	// 根据实际需要覆写，默认为循环刷屏（红橙黄绿青蓝紫）
	static const Color colors[7] = { Color::Red, Color::Orange, Color::Yellow, Color::Green, Color::Cyan, Color::Blue,
			Color::Purple };

	Log::Print(Log::DebugLog, "Screen::test()");

	for (i32 i = 0;; i++) {
		Canvas::clear(colors[i % 7]);
		refresh();
	}
}

}
}

#pragma once

#include "Cxx/graphics/Canvas/Canvas.h"

namespace Cxx {
namespace graphics {

class Screen: extends Canvas {
CXX_OBJECT_DEF(Screen)

public:
	Screen(i32 width, i32 height, i32 bpp, Graphics::Rot rot) {
		init(width, height, bpp, rot);
	}

public:
	virtual Screen& init() override;
	virtual void remove() override;

public:
	Screen& init(i32 width, i32 height, i32 bpp, Graphics::Rot rot);

public:
	Screen& copy(const Screen &other);
	Screen& move(Screen &&other);

public:
	virtual void refreshRect(i32 x0, i32 y0, i32 width, i32 height) = 0;
	virtual void refresh() = 0;

public:
	virtual void test();
};

}
}

#include "SDL2/Screen_SDL2.h"

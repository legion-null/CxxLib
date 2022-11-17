#pragma once

#include "Cxx/graphics/Screen/Screen.h"

#include "Cxx/base/String/String.h"

namespace Cxx {
namespace graphics {

class Screen_SDL2: extends Screen {
CXX_OBJECT_DEF(Screen_SDL2)

private:
	base::String title;

private:
	class SDL2Data *sdl2;

public:
	Screen_SDL2(const base::String &title, i32 width, i32 height, Graphics::Rot rot) {
		init(title, width, height, rot);
	}

public:
	virtual Screen_SDL2& init() override;
	virtual void remove() override;

public:
	Screen_SDL2& init(const base::String &title, i32 width, i32 height, Graphics::Rot rot);

public:
	Screen_SDL2& copy(const Screen_SDL2 &other);
	Screen_SDL2& move(Screen_SDL2 &&other);

public:
	virtual void refresh() override;
	virtual void refreshRect(i32 x0, i32 y0, i32 width, i32 height) override;
};

}
}

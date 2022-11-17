#include <SDL2/SDL.h>

#include "Cxx/Cxx.h"

import Cxx;
import Cxx::base;
import Cxx::dev;

namespace Cxx {
namespace graphics {
CXX_OBJECT_REALIZATION(Cxx::graphics::Screen_SDL2)

typedef struct SDL2Data {
	SDL_Window *window;
	SDL_Surface *surface = nullptr;
	u8 *fb = nullptr;
	u8 **fbX = nullptr;
} SDL2Data;

Screen_SDL2& Screen_SDL2::init() {
	this->sdl2 = new SDL2Data;

	init("SDL2 TFT液晶屏模拟器 作者：Legion", 800, 600, Graphics::Rot_0);

	return self;
}

void Screen_SDL2::remove() {
	if (this->sdl2 != nullptr)
		delete this->sdl2;
}

Screen_SDL2& Screen_SDL2::init(const base::String &title, i32 width, i32 height, Graphics::Rot rot) {
	Screen::init(width, height, 32, rot);

	this->sdl2 = new SDL2Data;

	::SDL_Init(SDL_INIT_EVERYTHING);

	sdl2->window = ::SDL_CreateWindow( //
			title.toCharArray(), // 标题
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,	// 居中
			width, height,	// 大小
			SDL_WINDOW_SHOWN);

	sdl2->surface = ::SDL_GetWindowSurface(sdl2->window);

	// 内存缓冲区映射
	sdl2->fb = (u8*) (sdl2->surface->pixels);

	if (sdl2->fbX != nullptr)
		delete[] sdl2->fbX;

	sdl2->fbX = new u8*[this->height];

	for (i32 i = 0; i < this->height; i++)
		sdl2->fbX[i] = &(sdl2->fb[lineSize * i]);

	return self;
}

Screen_SDL2& Screen_SDL2::copy(const Screen_SDL2 &other) {
	return self;
}

Screen_SDL2& Screen_SDL2::move(Screen_SDL2 &&other) {
	return self;
}

void Screen_SDL2::refresh() {
	FrameBuffer::Copy(fb, sdl2->fb, fbSize);
	::SDL_UpdateWindowSurface(sdl2->window);
}

void Screen_SDL2::refreshRect(i32 x0, i32 y0, i32 width, i32 height) {

	::SDL_UpdateWindowSurface(sdl2->window);
}

}
}

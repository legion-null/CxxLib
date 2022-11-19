#include "Cxx/Cxx.h"

#include "unistd.h"

import Cxx;
import Cxx::base;
import Cxx::dev;

import Cxx::graphics;
import Cxx::gui;

i32 gui_Style_Base_test_main() {
	Screen_SDL2 *scr = new Screen_SDL2();
	Graphics2D *g2d = new Graphics2D(scr);
	Component *component = new Component(10, 10, 100, 30);

	scr->clear(Color::White);
	scr->refresh();

	while (true) {
		component->paint(g2d);
		scr->refresh();
	}

	return 0;
}

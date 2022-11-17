#include "Cxx/Cxx.h"

import Cxx;
import Cxx::graphics;

i32 graphics_Screen_test_main() {
	Screen_SDL2 *scr = new Screen_SDL2();

	while (1) {
		scr->test();
	}

	return 0;
}

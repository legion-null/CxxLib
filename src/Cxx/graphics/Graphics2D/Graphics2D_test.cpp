#include "Cxx/Cxx.h"

import Cxx;
import Cxx::graphics;

i32 graphics_Graphics2D_test_main() {
	Screen *scr = new Screen_SDL2();
	Graphics2D *g2d = new Graphics2D(scr);

	while (1) {
		g2d->setColor(Color::Blue);
		g2d->drawOval(100, 100, 300, 200);
		scr->refresh();
	}

	return 0;
}

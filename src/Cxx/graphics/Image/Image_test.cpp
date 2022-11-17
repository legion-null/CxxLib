#include "Cxx/Cxx.h"

import Cxx;
import Cxx::base;
import Cxx::dev;

import Cxx::graphics;

#include <unistd.h>

i32 graphics_Image_test_main() {
	Screen *scr = new Screen_SDL2();
	Graphics2D *g2d = new Graphics2D(scr);
	Image *img1 = new Image_BMP("/disks/Data/工程/Eclipse_CPP/CxxLib_Template/src/Cxx/graphics/Image/BMP/test1.bmp");
	Image *img2 = new Image_BMP("/disks/Data/工程/Eclipse_CPP/CxxLib_Template/src/Cxx/graphics/Image/BMP/test2.bmp");

	scr->clear(Color::White);

	while (true) {
		g2d->drawImage(img1, 0, 0, 800, 600);
		scr->refresh();
		::sleep(1);
		g2d->drawImage(img2, 0, 0, 800, 600);
		scr->refresh();
		::sleep(1);
	}

	while(true);

	return 0;
}

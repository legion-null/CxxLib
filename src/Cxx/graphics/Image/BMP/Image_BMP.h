#pragma once

#include "Cxx/graphics/Image/Image.h"

namespace Cxx {
namespace graphics {

class Image_BMP: extends Image {
CXX_OBJECT_DEF(Image_BMP)

public:
	Image_BMP(const base::String &path){
		init(path);
	}

public:
	virtual Image_BMP& init() override;
	virtual void remove() override;

public:
	Image_BMP& init(const base::String &path);

public:
	Image_BMP& copy(const Image_BMP &other);
	Image_BMP& move(Image_BMP &&other);

};

}
}

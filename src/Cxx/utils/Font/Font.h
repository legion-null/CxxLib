#pragma once

#include "Cxx/base/Object/Object.h"

namespace Cxx {
namespace utils {

class Font: extends Cxx::base::Object {
CXX_OBJECT_DEF(Font)

protected:
	typedef struct CharImage {

	} CharImage;

protected:


public:
	virtual Font& init() override;
	virtual void remove() override;

public:
	Font& copy(const Font &other);
	Font& move(Font &&other);


};

}
}

#include "LatticeFont/LatticeFont.h"

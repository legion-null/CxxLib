#pragma once

#include "Cxx/utils/Font/Font.h"

namespace Cxx {
namespace utils {

class LatticeFont: extends Font {
CXX_OBJECT_DEF(LatticeFont)

public:
	virtual LatticeFont& init() override;
	virtual void remove() override;

public:
	LatticeFont& copy(const LatticeFont &other);
	LatticeFont& move(LatticeFont &&other);


};

}
}

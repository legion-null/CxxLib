#include "Cxx/Cxx.h"

import Cxx;
import Cxx::base;
import Cxx::dev;

namespace Cxx {
namespace graphics {

CXX_OBJECT_REALIZATION(Cxx::graphics::Color)

i32 Color::Mix(i32 background, i32 foreground, f32 a1, f32 a2) {
	// if (a1 < 0.0 || a1 > 1.0 || a2 < 0.0 || a2 > 1.0)

	const ColorData &c1 = (ColorData&) background;
	const ColorData &c2 = (ColorData&) foreground;
	ColorData c;

	c.RGB888.r = c1.RGB888.r * a1 * (1.0 - a2) + c2.RGB888.r * a2;
	c.RGB888.g = c1.RGB888.g * a1 * (1.0 - a2) + c2.RGB888.g * a2;
	c.RGB888.b = c1.RGB888.b * a1 * (1.0 - a2) + c2.RGB888.b * a2;

	return c.value;
}

Color Color::Mix(const Color &background, const Color &foreground) {
	const ColorData c1 = background.data;
	const ColorData c2 = foreground.data;
	f32 a1 = c1.ARGB8888.a / 255.0;
	f32 a2 = c2.ARGB8888.a / 255.0;

	return Mix(c1.value, c2.value, a1, a2);
}

i32 Color::OtherToARGB8888(i32 color, Type src) {
	return 0;
}

i32 Color::ARGB8888ToOther(i32 color, Type dest) {
	return 0;
}

i32 Color::Transform(i32 color, Type src, Type dest) {
	return 0;
}

Color& Color::init() {
	init(Color::Black);
	return self;
}

void Color::remove() {
}

Color& Color::init(i32 data) {
	init(data, ARGB8888);
	return self;
}

Color& Color::init(i32 data, Type type) {
	this->data.value = data;
	this->type = type;
	return self;
}

Color& Color::copy(const Color &other) {
	return self;
}

Color& Color::move(Color &&other) {
	return self;
}

i32 Color::getValue() const {
	return data.value;
}

void Color::setValue(i32 data) {
	this->data.value = data;
}

Color::Type Color::getType() const {
	return type;
}

void Color::setType(Type type) {
	this->type = type;
}

f32 Color::getA() const {
	return this->data.ARGB8888.a / 255.0;
}

f32 Color::getR() const {
	return this->data.ARGB8888.r / 255.0;
}

f32 Color::getG() const {
	return this->data.ARGB8888.g / 255.0;
}

f32 Color::getB() const {
	return this->data.ARGB8888.b / 255.0;
}

void Color::getARGB(f32 &a, f32 &r, f32 &g, f32 &b) const {
	a = this->data.ARGB8888.a / 255.0;
	r = this->data.ARGB8888.r / 255.0;
	g = this->data.ARGB8888.g / 255.0;
	b = this->data.ARGB8888.b / 255.0;
}

void Color::setA(f32 a) {
	this->data.ARGB8888.a = a * 255;
}

void Color::setR(f32 r) {
	this->data.ARGB8888.r = r * 255;
}

void Color::setG(f32 g) {
	this->data.ARGB8888.g = g * 255;
}

void Color::setB(f32 b) {
	this->data.ARGB8888.b = b * 255;
}

void Color::setARGB(f32 a, f32 r, f32 g, f32 b) {
	this->data.ARGB8888.a = a * 255;
	this->data.ARGB8888.r = r * 255;
	this->data.ARGB8888.g = g * 255;
	this->data.ARGB8888.b = b * 255;
}

}
}

#pragma once

#include "Cxx/base/Object/Object.h"

#include "Cxx/graphics/Color/Color.h"
#include "Cxx/graphics/Canvas/Canvas.h"

namespace Cxx {
namespace graphics {

class Image;

class Graphics2D: extends Cxx::base::Object {
CXX_OBJECT_DEF(Graphics2D)

public:
	static void GetLinePoints(i32 x0, i32 y0, i32 x1, i32 y1, i32 **px, i32 **py, i32 &n);

protected: // 内部参数
	Canvas *canvas = nullptr;
	Color color = Color::Black;

	// Font *font = &Font::ASCII_18_4BPP;

public:
	Graphics2D(Canvas *canvas) {
		init(canvas);
	}

public:
	virtual Graphics2D& init() override;
	virtual void remove() override;

public:
	Graphics2D& init(Canvas *canvas);

public:
	Graphics2D& copy(const Graphics2D &other);
	Graphics2D& move(Graphics2D &&other);

public:
	Canvas* getCanvas() const;
	void setCanvas(Canvas *canvas);

	Color getColor() const;
	void setColor(const Color &color);

public:
	Color getPoint(i32 x0, i32 y0);

	void drawPoint(i32 x0, i32 y0);

public:
	void drawLine(i32 x0, i32 y0, i32 x1, i32 y1);

	void drawRect(i32 x0, i32 y0, i32 width, i32 height);
	void drawTriangle(i32 x0, i32 y0, i32 x1, i32 y1, i32 x2, i32 y2);
	void drawPolyline(i32 x[], i32 y[], i32 n);
	void drawPolygon(i32 x[], i32 y[], i32 n);

	void drawCircle1L8(i32 x0, i32 y0, i32 r, i32 area);
	void drawCircle1L4(i32 x0, i32 y0, i32 r, i32 area);
	void drawCircle(i32 x0, i32 y0, i32 r);
	void drawOval(i32 x0, i32 y0, i32 width, i32 height);

	void drawRoundRect(i32 x0, i32 y0, i32 x1, i32 y1, i32 r);

public:
	void drawBezier(i32 x[], i32 y[], i32 n);

public:
	void fillRect(i32 x0, i32 y0, i32 width, i32 height);
	void fillTriangle(i32 x0, i32 y0, i32 x1, i32 y1, i32 x2, i32 y2);
	void fillPolygon(i32 x[], i32 y[], i32 n);

	void fillCircle1L4(i32 x0, i32 y0, i32 r, i32 area);
	void fillCircle(i32 x0, i32 y0, i32 r);
	void fillOval(i32 x0, i32 y0, i32 width, i32 height);

	void fillRoundRect(i32 x0, i32 y0, i32 x1, i32 y1, i32 r);

public:
	void drawImage(Image *img, i32 x0, i32 y0, i32 width, i32 height);

};

}
}

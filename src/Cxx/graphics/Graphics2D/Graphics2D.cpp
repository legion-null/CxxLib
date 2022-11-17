#include "Cxx/Cxx.h"

import Cxx;
import Cxx::base;
import Cxx::dev;

namespace Cxx {
namespace graphics {
CXX_OBJECT_REALIZATION(Cxx::graphics::Graphics2D)

void Graphics2D::GetLinePoints(i32 x0, i32 y0, i32 x1, i32 y1, i32 **px, i32 **py, i32 &n) {
	i32 x = x0;
	i32 y = y0;

	if (x0 == x1) {
		// 垂直线
		i32 sy = y1 > y0 ? 1 : -1;
		n = (sy == 1 ? y1 - y0 : y0 - y1) + 1;

		*px = new i32[n]; // 分配内存
		*py = new i32[n]; // 分配内存

		for (i32 i = 1; i < n - 1; i++) {
			y = y + sy;
			(*px)[i] = x;
			(*py)[i] = y;
		}
	} else if (y0 == y1) {
		// 水平线
		i32 sx = x1 > x0 ? 1 : -1;
		n = (sx == 1 ? x1 - x0 : x0 - x1) + 1;

		*px = new i32[n]; // 分配内存
		*py = new i32[n]; // 分配内存

		for (i32 i = 1; i < n - 1; i++) {
			x = x + sx;
			(*px)[i] = x;
			(*py)[i] = y;
		}
	} else {
		// 斜线，Bresenham算法
		i32 sx = x1 > x0 ? 1 : -1;
		i32 sy = y1 > y0 ? 1 : -1;
		i32 dx = (sx == 1 ? x1 - x0 : x0 - x1);
		i32 dy = (sy == 1 ? y1 - y0 : y0 - y1);
		i32 erro = (dx > dy ? dx : -dy) / 2;
		n = (dx > dy ? dx : dy) + 1;

		*px = new i32[n]; // 分配内存
		*py = new i32[n]; // 分配内存

		for (i32 i = 1; i < n - 1; i++) {
			if (erro > -dx) {
				erro = erro - dy;
				x = x + sx;
			}
			if (erro < dy) {
				erro = erro + dx;
				y = y + sy;
			}
			(*px)[i] = x;
			(*py)[i] = y;
		}
	}

	// 首尾两点统一处理
	(*px)[0] = x0;
	(*py)[0] = y0;
	(*px)[n - 1] = x1;
	(*py)[n - 1] = y1;
}

Graphics2D& Graphics2D::init() {
	return self;
}

void Graphics2D::remove() {
}

Graphics2D& Graphics2D::init(Canvas *canvas) {
	setCanvas(canvas);
	return self;
}

Graphics2D& Graphics2D::copy(const Graphics2D &other) {
	return self;
}

Graphics2D& Graphics2D::move(Graphics2D &&other) {
	return self;
}

Canvas* Graphics2D::getCanvas() const {
	return this->canvas;
}

void Graphics2D::setCanvas(Canvas *canvas) {
	this->canvas = canvas;
}

Color Graphics2D::getColor() const {
	return color;
}

void Graphics2D::setColor(const Color &color) {
	this->color = color;
}

Color Graphics2D::getPoint(i32 x0, i32 y0) {
	return this->canvas->getPoint(x0, y0);
}

void Graphics2D::drawPoint(i32 x0, i32 y0) {
	this->canvas->drawPoint(x0, y0, this->color);
}

void Graphics2D::drawLine(i32 x0, i32 y0, i32 x1, i32 y1) {
	if (x0 == x1) {
		return this->canvas->drawLineV(x0, Min(y0, y1), Abs(y1 - y0) + 1, this->color);
	} else if (y0 == y1) {
		return this->canvas->drawLineH(Min(x0, x1), y0, Abs(x1 - x0) + 1, this->color);
	} else {
		// Bresenham算法
		i32 x = x0;
		i32 y = y0;

		i32 sx = x1 > x0 ? 1 : -1;
		i32 sy = y1 > y0 ? 1 : -1;
		i32 dx = sx == 1 ? x1 - x0 : x0 - x1;
		i32 dy = sy == 1 ? y1 - y0 : y0 - y1;
		i32 erro = (dx > dy ? dx : -dy) / 2;
		i32 n = (dx > dy ? dx : dy) + 1;

		for (i32 i = 1; i < n - 1; i++) {
			if (erro > -dx) {
				erro = erro - dy;
				x = x + sx;
			}
			if (erro < dy) {
				erro = erro + dx;
				y = y + sy;
			}
			drawPoint(x, y);
		}

		// 首尾两点统一处理
		drawPoint(x0, y0);
		drawPoint(x1, y1);
	}
}

void Graphics2D::drawRect(i32 x0, i32 y0, i32 width, i32 height) {
	i32 x1 = x0 + width - 1;
	i32 y1 = y0 + height - 1;

	drawLine(x0, y0, x1, y0);
	drawLine(x0, y0, x0, y1);
	drawLine(x1, y0, x1, y1);
	drawLine(x0, y1, x1, y1);
}

void Graphics2D::drawTriangle(i32 x0, i32 y0, i32 x1, i32 y1, i32 x2, i32 y2) {
	drawLine(x0, y0, x1, y1);
	drawLine(x1, y1, x2, y2);
	drawLine(x2, y2, x0, y0);
}

void Graphics2D::drawPolyline(i32 x[], i32 y[], i32 n) {
	for (i32 i = 0; i < n - 1; i++)
		drawLine(x[i], y[i], x[i + 1], y[i + 1]);
}

void Graphics2D::drawPolygon(i32 x[], i32 y[], i32 n) {
	for (i32 i = 0; i < n - 1; i++)
		drawLine(x[i], y[i], x[i + 1], y[i + 1]);
	drawLine(x[n - 1], y[n - 1], x[0], y[0]);
}

void Graphics2D::drawCircle1L8(i32 x0, i32 y0, i32 r, i32 area) {
	i32 dx = r;
	i32 dy = 0;

	bool flag[8];

	for (i32 i = 0; i < 8; i++)
		flag[i] = (0x01 & (area >> i)) == 1 ? true : false;

	while (dy <= dx) {
		if (flag[0])
			drawPoint(x0 + dx, y0 + dy); //   0 pi ~ 1/4 pi
		if (flag[1])
			drawPoint(x0 + dy, y0 + dx); // 1/4 pi ~ 1/2 pi
		if (flag[2])
			drawPoint(x0 - dy, y0 + dx); // 1/2 pi ~ 3/4 pi
		if (flag[3])
			drawPoint(x0 - dx, y0 + dy); //   1 pi ~ 5/4 pi
		if (flag[4])
			drawPoint(x0 - dy, y0 - dx); // 5/4 pi ~ 3/2 pi
		if (flag[5])
			drawPoint(x0 - dx, y0 - dy); // 3/4 pi ~   1 pi
		if (flag[6])
			drawPoint(x0 + dy, y0 - dx); // 3/2 pi ~ 7/4 pi
		if (flag[7])
			drawPoint(x0 + dx, y0 - dy); // 7/4 pi ~   2 pi

		dx = dx - 1;
		dy = dy + 1;

		if (dx * dx + dy * dy < r * r - r)
			dx = dx + 1;
	}
}

void Graphics2D::drawCircle1L4(i32 x0, i32 y0, i32 r, i32 area) {
	i32 area8 = 0;

	for (i32 i = 0; i < 4; i++) {
		if ((0x01 & (area >> i)) == 1)
			area8 = area8 | 0x03;
		area8 = area8 << 2;
	}

	return drawCircle1L8(x0, y0, r, area8);
}

void Graphics2D::drawCircle(i32 x0, i32 y0, i32 r) {
	return drawCircle1L8(x0, y0, r, 0xff);
}

void Graphics2D::drawOval(i32 x0, i32 y0, i32 width, i32 height) {
	if (width == height) {	// 正圆形
		i32 r = width / 2;
		return drawCircle(x0 + r, y0 + r, r);
	}

	if (width > height) {	// 焦点纵坐标相同的椭圆
		i32 a = width / 2;
		i32 b = height / 2;
		i32 a2 = a * a;
		i32 b2 = b * b;
		i32 basis = a2 * b2;
		i32 dx = a;
		i32 dy = 0;

		x0 = x0 + a;
		y0 = y0 + b;

		while (dy <= b && dx >= 0) {
			drawPoint(x0 + dx, y0 + dy);	//   0 pi ~ 1/2 pi
			drawPoint(x0 - dx, y0 + dy);	// 1/2 pi ~   1 pi
			drawPoint(x0 - dx, y0 - dy);	//   1 pi ~ 3/2 pi
			drawPoint(x0 + dx, y0 - dy);	// 3/2 pi ~   2 pi

			dx = dx - 1;
			dy = dy + 1;

			if (b2 * dx * dx + a2 * dy * dy <= basis)
				dx = dx + 1;
			else
				dy = dy - 1;
		}
	} else {	// 焦点横坐标相同的椭圆
		i32 a = height / 2;
		i32 b = width / 2;
		i32 a2 = a * a;
		i32 b2 = b * b;
		i32 basis = a2 * b2;
		i32 dy = a;
		i32 dx = 0;

		x0 = x0 + b;
		y0 = y0 + a;

		while (dx <= b && dy >= 0) {
			drawPoint(x0 + dx, y0 - dy);	//   0 pi ~ 1/2 pi
			drawPoint(x0 - dx, y0 - dy);	// 1/2 pi ~   1 pi
			drawPoint(x0 - dx, y0 + dy);	//   1 pi ~ 3/2 pi
			drawPoint(x0 + dx, y0 + dy);	// 3/2 pi ~   2 pi

			dy = dy - 1;
			dx = dx + 1;

			if (a2 * dx * dx + b2 * dy * dy <= basis)
				dy = dy + 1;
			else
				dx = dx - 1;
		}
	}
}

void Graphics2D::drawRoundRect(i32 x0, i32 y0, i32 x1, i32 y1, i32 r) {
}

static void bezier(i32 n, i32 x[], i32 y[], f32 t, i32 &px, i32 &py) {
	f32 *b = new f32[n + 1];

	px = 0;
	py = 0;

	if (n == 1) {
		b[0] = 1 - t;
		b[1] = t;
	} else if (n == 2) {
		b[0] = (1 - t) * (1 - t);
		b[1] = 2 * t * (1 - t);
		b[2] = t * t;
	} else if (n == 3) {
		b[0] = (1 - t) * (1 - t) * (1 - t);
		b[1] = 3 * t * (1 - t) * (1 - t);
		b[2] = 3 * t * t * (1 - t);
		b[3] = t * t * t;
	}

	for (i32 i = 0; i < n + 1; i++) {
		px += b[i] * x[i];
		py += b[i] * y[i];
	}

	delete[] b;
}

void Graphics2D::drawBezier(i32 x[], i32 y[], i32 n) {
	f32 dt = 0.002;
	i32 px = 0;
	i32 py = 0;

	for (f32 t = 0; t < 1.0; t += dt) {
		bezier(n, x, y, t, px, py);
		drawPoint(px, py);
	}
}

void Graphics2D::fillRect(i32 x0, i32 y0, i32 width, i32 height) {
	i32 x1 = x0 + width - 1;
	i32 y1 = y0 + height - 1;
	for (i32 y = y0; y <= y1; y++)
		drawLine(x0, y, x1, y);
}

void Graphics2D::fillTriangle(i32 x0, i32 y0, i32 x1, i32 y1, i32 x2, i32 y2) {
	i32 xStart = x0;
	i32 yStart = y0;
	i32 xMid = x0;
	i32 yMid = y0;
	i32 xEnd = x0;
	i32 yEnd = y0;

	i32 *xStart2Mid = nullptr;
	i32 *yStart2Mid = nullptr;
	i32 *xMid2End = nullptr;
	i32 *yMid2End = nullptr;
	i32 *xStart2End = nullptr;
	i32 *yStart2End = nullptr;

	i32 nStart2Mid = 0;
	i32 nMid2End = 0;
	i32 nStart2End = 0;

	// 自顶向下水平渲染，先根据y坐标对点进行排序
	// 最顶端点
	if (yStart > y1) {
		yStart = y1;
		xStart = x1;
		if (yStart > y2) {
			yStart = y2;
			xStart = x2;
		}
	} else if (yStart > y2) {
		yStart = y2;
		xStart = x2;
	}
	// 最底端点
	if (yEnd < y1) {
		yEnd = y1;
		xEnd = x1;
		if (yEnd < y2) {
			yEnd = y2;
			xEnd = x2;
		}
	} else if (yEnd < y2) {
		yEnd = y2;
		xEnd = x2;
	}

	// 中间端点
	xMid = x0 + x1 + x2 - xStart - xEnd;
	yMid = y0 + y1 + y2 - yStart - yEnd;

	// 边框渲染
	GetLinePoints(xStart, yStart, xMid, yMid, &xStart2Mid, &yStart2Mid, nStart2Mid);
	GetLinePoints(xMid, yMid, xEnd, yEnd, &xMid2End, &yMid2End, nMid2End);
	GetLinePoints(xStart, yStart, xEnd, yEnd, &xStart2End, &yStart2End, nStart2End);

	drawLine(xStart, yStart, xMid, yMid);
	drawLine(xMid, yMid, xEnd, yEnd);
	drawLine(xStart, yStart, xEnd, yEnd);

	// 内部渲染
	i32 i = 0; // 作为lineStart2End下标
	i32 j = 0; // 作为lineStart2Mid、lineMid2End下标
	if (yStart != yMid)
		for (i32 y = yStart; y <= yMid; y++) {
			while (yStart2End[i] != y)
				i++;
			while (yStart2Mid[j] != y)
				j++;
			drawLine(xStart2End[i], y, xStart2Mid[j], y);
		}

	j = 0;
	if (yMid != yEnd)
		for (i32 y = yMid; y <= yEnd; y++) {
			while (yStart2End[i] != y)
				i++;
			while (yMid2End[j] != y)
				j++;
			drawLine(xStart2End[i], y, xMid2End[j], y);
		}

	// 释放内存
	delete[] xStart2Mid;
	delete[] yStart2Mid;
	delete[] xMid2End;
	delete[] yMid2End;
	delete[] xStart2End;
	delete[] yStart2End;
}

void Graphics2D::fillPolygon(i32 x[], i32 y[], i32 n) {
	for (i32 i = 0; i < n - 1; i++)
		fillTriangle(x[0], y[0], x[i], y[i], x[i + 1], y[i + 1]);
}

void Graphics2D::fillCircle1L4(i32 x0, i32 y0, i32 r, i32 area) {
	i32 dx = r;
	i32 dy = 0;

	bool flag[4];

	for (i32 i = 0; i < 4; i++)
		flag[i] = (0x01 & (area >> i)) == 1 ? true : false;

	while (dy <= dx) {
		if (flag[0]) {
			drawLine(x0, y0 + dy, x0 + dx, y0 + dy); //   0 pi ~ 1/4 pi
			drawLine(x0, y0 + dx, x0 + dy, y0 + dx); // 1/4 pi ~ 1/2 pi
		}
		if (flag[1]) {
			drawLine(x0, y0 + dx, x0 - dy, y0 + dx); // 1/2 pi ~ 3/4 pi
			drawLine(x0, y0 + dy, x0 - dx, y0 + dy); //   1 pi ~ 5/4 pi
		}
		if (flag[2]) {
			drawLine(x0, y0 - dx, x0 - dy, y0 - dx); // 5/4 pi ~ 3/2 pi
			drawLine(x0, y0 - dy, x0 - dx, y0 - dy); // 3/4 pi ~   1 pi
		}
		if (flag[3]) {
			drawLine(x0, y0 - dx, x0 + dy, y0 - dx); // 3/2 pi ~ 7/4 pi
			drawLine(x0, y0 - dy, x0 + dx, y0 - dy); // 7/4 pi ~   2 pi
		}
		dx = dx - 1;
		dy = dy + 1;

		if (dx * dx + dy * dy < r * r - r)
			dx = dx + 1;
	}
}

void Graphics2D::fillCircle(i32 x0, i32 y0, i32 r) {
	return fillCircle1L4(x0, y0, r, 0xff);
}

void Graphics2D::fillOval(i32 x0, i32 y0, i32 width, i32 height) {
	if (width == height) {	// 正圆形
		i32 r = width / 2;
		return fillCircle(x0 + r, y0 + r, r);
	}

	if (width > height) {	// 焦点纵坐标相同的椭圆
		i32 a = width / 2;
		i32 b = height / 2;
		i32 a2 = a * a;
		i32 b2 = b * b;
		i32 basis = a2 * b2;
		i32 dx = a;
		i32 dy = 0;

		x0 = x0 + a;
		y0 = y0 + b;

		while (dy <= b && dx >= 0) {
			drawLine(x0 + dx, y0 + dy, x0 - dx, y0 + dy);	//   0 pi ~   1 pi
			drawLine(x0 + dx, y0 - dy, x0 - dx, y0 - dy);	//   1 pi ~   2 pi

			dx = dx - 1;
			dy = dy + 1;

			if (b2 * dx * dx + a2 * dy * dy <= basis)
				dx = dx + 1;
			else
				dy = dy - 1;
		}
	} else {	// 焦点横坐标相同的椭圆
		i32 a = height / 2;
		i32 b = width / 2;
		i32 a2 = a * a;
		i32 b2 = b * b;
		i32 basis = a2 * b2;
		i32 dy = a;
		i32 dx = 0;

		x0 = x0 + b;
		y0 = y0 + a;

		while (dx <= b && dy >= 0) {
			drawLine(x0 + dx, y0 + dy, x0 - dx, y0 + dy);	//   0 pi ~   1 pi
			drawLine(x0 + dx, y0 - dy, x0 - dx, y0 - dy);	//   1 pi ~   2 pi

			dy = dy - 1;
			dx = dx + 1;

			if (a2 * dx * dx + b2 * dy * dy <= basis)
				dy = dy + 1;
			else
				dx = dx - 1;
		}
	}
}

void Graphics2D::fillRoundRect(i32 x0, i32 y0, i32 x1, i32 y1, i32 r) {
}

void Graphics2D::drawImage(Image *img, i32 x0, i32 y0, i32 width, i32 height) {
	for (i32 y = 0; y < height; y++)
		for (i32 x = 0; x < width; x++) {
			this->canvas->drawPoint(x0 + x, y0 + y, img->getPoint(x, y).getValue());
		}
}

}
}

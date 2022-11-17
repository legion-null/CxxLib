#pragma once

#include "Cxx/base/Object/Object.h"

namespace Cxx {
namespace graphics {

class Color: extends Cxx::base::Object {
CXX_OBJECT_DEF(Color)

public:
	typedef enum TypicalColor : i32 {
		LightPink = 0xFFB6C1,	// 浅粉红
		Pink = 0xFFC0CB,		// 粉红
		Crimson = 0xDC143C,		// 猩红
		LavenderBlush = 0xFFF0F5,	// 脸红的淡紫色
		PaleVioletRed = 0xDB7093,	// 苍白的紫罗兰红色
		HotPink = 0xFF69B4,		// 热情的粉红
		DeepPink = 0xFF1493,	// 深粉色
		MediumVioletRed = 0xC71585,	// 适中的紫罗兰红色
		Orchid = 0xDA70D6,		// 兰花的紫色
		Thistle = 0xD8BFD8,		// 蓟
		plum = 0xDDA0DD,		// 李子
		Violet = 0xEE82EE,		// 紫罗兰
		Magenta = 0xFF00FF,		// 洋红
		Fuchsia = 0xFF00FF,		// 灯笼海棠(紫红色)
		DarkMagenta = 0x8B008B,	// 深洋红色
		Purple = 0x800080,			// 紫色
		MediumOrchid = 0xBA55D3,	// 适中的兰花紫
		DarkVoilet = 0x9400D3,	// 深紫罗兰色
		DarkOrchid = 0x9932CC,	// 深兰花紫
		Indigo = 0x4B0082,		// 靛青
		BlueViolet = 0x8A2BE2,	// 深紫罗兰的蓝色
		MediumPurple = 0x9370DB,	// 适中的紫色
		MediumSlateBlue = 0x7B68EE,	// 适中的板岩暗蓝灰色
		SlateBlue = 0x6A5ACD,		// 板岩暗蓝灰色
		DarkSlateBlue = 0x483D8B,	// 深岩暗蓝灰色
		Lavender = 0xE6E6FA,	// 熏衣草花的淡紫色
		GhostWhite = 0xF8F8FF,	// 幽灵的白色
		Blue = 0x0000FF,		// 纯蓝
		MediumBlue = 0x0000CD,	// 适中的蓝色
		MidnightBlue = 0x191970,	// 午夜的蓝色
		DarkBlue = 0x00008B,	// 深蓝色
		Navy = 0x000080,		// 海军蓝
		RoyalBlue = 0x4169E1,	// 皇家蓝
		CornflowerBlue = 0x6495ED,	// 矢车菊的蓝色
		LightSteelBlue = 0xB0C4DE,	// 淡钢蓝
		LightSlateGray = 0x778899,	// 浅石板灰
		SlateGray = 0x708090,	// 石板灰
		DoderBlue = 0x1E90FF,	// 道奇蓝
		AliceBlue = 0xF0F8FF,	// 爱丽丝蓝
		SteelBlue = 0x4682B4,	// 钢蓝
		LightSkyBlue = 0x87CEFA,	// 淡蓝色
		SkyBlue = 0x87CEEB,		// 天蓝色
		DeepSkyBlue = 0x00BFFF,	// 深天蓝
		LightBLue = 0xADD8E6,	// 淡蓝
		PowDerBlue = 0xB0E0E6,	// 火药蓝
		CadetBlue = 0x5F9EA0,	// 军校蓝
		Azure = 0xF0FFFF,		// 蔚蓝色
		LightCyan = 0xE1FFFF,	// 淡青色
		PaleTurquoise = 0xAFEEEE,	// 苍白的绿宝石
		Cyan = 0x00FFFF,	// 青色
		Aqua = 0xD4F2E7,	// 水绿色
		DarkTurquoise = 0x00CED1,	// 深绿宝石
		DarkSlateGray = 0x2F4F4F,	// 深石板灰
		DarkCyan = 0x008B8B,	// 深青色
		Teal = 0x008080,	// 水鸭色
		MediumTurquoise = 0x48D1CC,	// 适中的绿宝石
		LightSeaGreen = 0x20B2AA,	// 浅海洋绿
		Turquoise = 0x40E0D0,	// 绿宝石
		Auqamarin = 0x7FFFAA,	// 绿玉\碧绿色
		MediumAquamarine = 0x00FA9A,	// 适中的碧绿色
		MediumSpringGreen = 0x00FF7F,	// 适中的春天的绿色
		MintCream = 0xF5FFFA,	// 薄荷奶油
		SpringGreen = 0x3CB371,	// 春天的绿色
		SeaGreen = 0x2E8B57,	// 海洋绿
		Honeydew = 0xF0FFF0,	// 蜂蜜
		LightGreen = 0x90EE90,	// 淡绿色
		PaleGreen = 0x98FB98,	// 苍白的绿色
		DarkSeaGreen = 0x8FBC8F,	// 深海洋绿
		LimeGreen = 0x32CD32,	// 酸橙绿
		Lime = 0x00FF00,	// 酸橙色
		ForestGreen = 0x228B22,	// 森林绿
		Green = 0x008000,	// 纯绿
		DarkGreen = 0x006400,	// 深绿色
		Chartreuse = 0x7FFF00,	// 查特酒绿
		LawnGreen = 0x7CFC00,	// 草坪绿
		GreenYellow = 0xADFF2F,	// 绿黄色
		OliveDrab = 0x556B2F,	// 橄榄土褐色
		Beige = 0xF5F5DC,	// 米色(浅褐色)
		LightGoldenrodYellow = 0xFAFAD2,	// 浅秋麒麟黄
		Ivory = 0xFFFFF0,	// 象牙
		LightYellow = 0xFFFFE0,	// 浅黄色
		Yellow = 0xFFFF00,	// 纯黄
		Olive = 0x808000,	// 橄榄
		DarkKhaki = 0xBDB76B,	// 深卡其布
		LemonChiffon = 0xFFFACD,	// 柠檬薄纱
		PaleGodenrod = 0xEEE8AA,	// 灰秋麒麟
		Khaki = 0xF0E68C,	// 卡其布
		Gold = 0xFFD700,	// 金
		Cornislk = 0xFFF8DC,	// 玉米色
		GoldEnrod = 0xDAA520,	// 秋麒麟
		FloralWhite = 0xFFFAF0,	// 花的白色
		OldLace = 0xFDF5E6,	// 老饰带
		Wheat = 0xF5DEB3,	// 小麦色
		Moccasin = 0xFFE4B5,	// 鹿皮鞋
		Orange = 0xFFA500,	// 橙色
		PapayaWhip = 0xFFEFD5,	// 番木瓜
		BlanchedAlmond = 0xFFEBCD,	// 漂白的杏仁
		NavajoWhite = 0xFFDEAD,	// 纳瓦霍白
		AntiqueWhite = 0xFAEBD7,	// 古代的白色
		Tan = 0xD2B48C,	// 晒黑
		BrulyWood = 0xDEB887,	// 结实的树
		Bisque = 0xFFE4C4,	// (浓汤)乳脂,番茄等
		DarkOrange = 0xFF8C00,	// 深橙色
		Linen = 0xFAF0E6,	// 亚麻布
		Peru = 0xCD853F,	// 秘鲁
		PeachPuff = 0xFFDAB9,	// 桃色
		SandyBrown = 0xF4A460,	// 沙棕色
		Chocolate = 0xD2691E,	// 巧克力
		SaddleBrown = 0x8B4513,	// 马鞍棕色
		SeaShell = 0xFFF5EE,	// 海贝壳
		Sienna = 0xA0522D,	// 黄土赭色
		LightSalmon = 0xFFA07A,	// 浅鲜肉(鲑鱼)色
		Coral = 0xFF7F50,	// 珊瑚
		OrangeRed = 0xFF4500,	// 橙红色
		DarkSalmon = 0xE9967A,	// 深鲜肉(鲑鱼)色
		Tomato = 0xFF6347,	// 番茄
		MistyRose = 0xFFE4E1,	// 薄雾玫瑰
		Salmon = 0xFA8072,	// 鲜肉(鲑鱼)色
		Snow = 0xFFFAFA,	// 雪
		LightCoral = 0xF08080,	// 淡珊瑚色
		RosyBrown = 0xBC8F8F,	// 玫瑰棕色
		IndianRed = 0xCD5C5C,	// 印度红
		Red = 0xFF0000,	// 纯红
		Brown = 0xA52A2A,	// 棕色
		FireBrick = 0xB22222,	// 耐火砖
		DarkRed = 0x8B0000,	// 深红色
		Maroon = 0x800000,	// 栗色
		White = 0xFFFFFF,	// 纯白
		WhiteSmoke = 0xF5F5F5,	// 白烟
		Gainsboro = 0xDCDCDC,	// 亮灰色
		LightGrey = 0xD3D3D3,	// 浅灰色
		Silver = 0xC0C0C0,	// 银白色
		DarkGray = 0xA9A9A9,	// 深灰色
		Gray = 0x808080,	// 灰色
		DimGray = 0x696969,	// 暗淡的灰色
		Black = 0x000000,	// 纯黑
	} TypicalColor;

public:
	typedef enum Type : i8 {
		// 灰度类型
		GREY_1,		// 灰度[1]
		GREY_2,		// 灰度[2]
		GREY_4,		// 灰度[4]
		GREY_8,		// 灰度[8]
		// 图形适配器类型
		CGA,		// value[2]
		EGA,		// value[4]
		VGA,		// value[8]
		// RGB类型
		RGB332,		// R[3] G[3] B[2]
		RGB555,		// R[5] G[5] B[5]
		RGB565,		// R[5] G[6] B[5]
		RGB888,		// R[8] G[8] B[8]
		// ARGB类型
		ARGB1232,	// A[1] R[2] G[3] B[2]
		ARGB1555,	// A[1] R[5] G[5] B[5]
		ARGB8888,	// A[8] R[8] G[8] B[8]
		// HtmlCode类型
		HtmlCode,	// R[8] G[8] B[8]
	} Type;

protected:
	struct CGA {
		i32 :30; // 留空
		i32 value :2;
	} __attribute__ ((packed));

	struct EGA {
		i32 :28; // 留空
		i32 value :4;
	} __attribute__ ((packed));

	struct VGA {
		i32 :24; // 留空
		i32 value :8;
	} __attribute__ ((packed));

	struct RGB332 {
		i32 :24; // 留空
		i32 r :3;
		i32 g :3;
		i32 b :2;
	} __attribute__ ((packed));

	struct RGB555 {
		i32 :17; // 留空
		i32 r :5;
		i32 g :5;
		i32 b :5;
	} __attribute__ ((packed));

	struct RGB565 {
		i32 :16; // 留空
		i32 r :5;
		i32 g :6;
		i32 b :5;
	} __attribute__ ((packed));

	struct RGB888 {
		i32 :8;
		i32 r :8;
		i32 g :8;
		i32 b :8;
	} __attribute__ ((packed));

	struct ARGB1232 {
		i32 :24; // 留空
		i32 a :1;
		i32 r :2;
		i32 g :3;
		i32 b :2;
	} __attribute__ ((packed));

	struct ARGB1555 {
		i32 :16; // 留空
		i32 a :1;
		i32 r :5;
		i32 g :5;
		i32 b :5;
	} __attribute__ ((packed));

	struct ARGB8888 {
		i32 a :8;
		i32 r :8;
		i32 g :8;
		i32 b :8;
	} __attribute__ ((packed));

	struct HtmlCode {
		i32 :8;
		i32 r :8;
		i32 g :8;
		i32 b :8;
	} __attribute__ ((packed));

	typedef union ColorData {
		i32 value;
		i32 GREY;
		struct CGA CGA;
		struct EGA EGA;
		struct VGA VGA;
		struct RGB332 RGB332;
		struct RGB565 RGB565;
		struct RGB888 RGB888;
		struct ARGB1232 ARGB1232;
		struct ARGB1555 ARGB1555;
		struct ARGB8888 ARGB8888;
		struct HtmlCode HtmlCode;
	} __attribute__ ((packed)) ColorData;

public:
	static i32 Mix(i32 background, i32 foreground, f32 a1, f32 a2);
	static Color Mix(const Color &background, const Color &foreground);

public:
	static i32 OtherToARGB8888(i32 color, Type src);
	static i32 ARGB8888ToOther(i32 color, Type dest);
	static i32 Transform(i32 color, Type src, Type dest);

protected:
	ColorData data;
	Type type;

public:
	Color(i32 data) {
		init(data);
	}

	Color(i32 data, Type type) {
		init(data, type);
	}

public:
	Color& operator=(i32 data) {
		return init(data);
	}

public:
	virtual Color& init() override;
	virtual void remove() override;

public:
	Color& init(i32 data);
	Color& init(i32 data, Type type);

public:
	Color& copy(const Color &other);
	Color& move(Color &&other);

public:
	i32 getValue() const;
	void setValue(i32 data);

	Type getType() const;
	void setType(Type type);

public:
	f32 getA() const;
	f32 getR() const;
	f32 getG() const;
	f32 getB() const;

	void getARGB(f32 &a, f32 &r, f32 &g, f32 &b) const;

public:
	void setA(f32 a);
	void setR(f32 r);
	void setG(f32 g);
	void setB(f32 b);

	void setARGB(f32 a, f32 r, f32 g, f32 b);
};

}
}

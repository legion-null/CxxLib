#include "Cxx/Cxx.h"

import Cxx;
import Cxx::base;
import Cxx::dev;
import Cxx::io;

namespace Cxx {
namespace graphics {
CXX_OBJECT_REALIZATION(Cxx::graphics::Image_BMP)

typedef struct BMP_fileHeader {
	i8 type[2];		// 用于标识BMP和DIB文件的魔数，一般为0x42 0x4D，即ASCII的BM。以下为可能的取值：BM、BA、CI、CP、IC、PT
	u32 size;		// BMP文件的大小（单位为字节）
	i16 reserved1;	// 保留；实际值因创建程序而异
	i16 reserved2;	// 保留；实际值因创建程序而异
	u32 offset;		// 位图数据（像素数组）的地址偏移，也就是起始地址。
} __attribute__ ((packed)) BMP_fileHeader;

typedef struct BMP_infoHeader {
	u32 size;				// 该头结构的大小（40字节）
	i32 width;				// 位图宽度，单位为像素（有符号整数）
	i32 height;				// 位图高度，单位为像素（有符号整数）
	u16 planes;				// 色彩平面数；只有1为有效值
	u16 bpp;				// 每个像素所占位数，即图像的色深。典型值为1、4、8、16、24和32
	u32 compression;		// 所使用的压缩方法，可取值见下表。
	u32 image_size;			// 图像大小。指原始位图数据的大小（详见后文），与文件大小不是同一个概念。
	i32 x_pels_per_meter;	// 图像的横向分辨率，单位为像素每米（有符号整数）
	i32 y_pels_per_meter;	// 图像的纵向分辨率，单位为像素每米（有符号整数）
	u32 clr_used;			// 调色板的颜色数，为0时表示颜色数为默认的2^色深个
	u32 clr_omportant;		// 重要颜色数，为0时表示所有颜色都是重要的；通常不使用本项
} __attribute__ ((packed)) BMP_infoHeader;

typedef struct BMP_colorPalette {
	u8 rgbBlue;		// 该颜色的蓝色分量  (值范围为0-255)
	u8 rgbGreen;	// 该颜色的绿色分量  (值范围为0-255)
	u8 rgbRed;		// 该颜色的红色分量  (值范围为0-255)
	u8 rgbReserved;	// 保留，必须为0
} __attribute__ ((packed)) BMP_colorPalette;

static void printBMPFileHeader(BMP_fileHeader *header) {
	Log::Print(Log::DebugLog, "BMP_fileHeader\n");
	Log::Print(Log::DebugLog, "魔数：0x%x%x\n", header->type[0], header->type[1]);
	Log::Print(Log::DebugLog, "文件大小：%uB（%.1fKB %.1fMB）\n", header->size, header->size / 1024.0, header->size / 1024.0 / 1024.0);
	Log::Print(Log::DebugLog, "保留值1：%d\n", header->reserved1);
	Log::Print(Log::DebugLog, "保留值2：%d\n", header->reserved2);
	Log::Print(Log::DebugLog, "位图数据地址偏移：0x%x\n", header->offset);
	Log::Print(Log::DebugLog, "\n");
}

static void printBMPInfoHeader(BMP_infoHeader *header) {
	Log::Print(Log::DebugLog, "BMP_infoHeader\n");
	Log::Print(Log::DebugLog, "头结构大小：%d\n", header->size);
	Log::Print(Log::DebugLog, "位图宽度：%d\n", header->width);
	Log::Print(Log::DebugLog, "位图高度：%d\n", header->height);
	Log::Print(Log::DebugLog, "色彩平面数：%d\n", header->planes);
	Log::Print(Log::DebugLog, "色深：%d\n", header->bpp);
	Log::Print(Log::DebugLog, "\n");
}

Image_BMP& Image_BMP::init() {
	return self;
}

void Image_BMP::remove() {
}

Image_BMP& Image_BMP::init(const String &path) {
	BMP_fileHeader fileH;
	BMP_infoHeader infoH;

	// 打开BMP图像文件
	File tempFile = File(path, "r");

	// 读取文件基本信息
	tempFile.read((byte*) &fileH, sizeof(BMP_fileHeader));
	// 输出相关信息
	printBMPFileHeader(&fileH);

	// 读取BMP相关信息
	tempFile.read((byte*) &infoH, sizeof(BMP_infoHeader));
	// 输出相关信息
	printBMPInfoHeader(&infoH);

	// 根据相关信息初始化
	Log::Print(Log::DebugLog, "根据相关信息初始化 FrameBuffer\n");
	FrameBuffer::init(infoH.width, infoH.height, 32);

	// 文件指针跳转到图像数据开头
	Log::Print(Log::DebugLog, "文件指针跳转到图像数据开头\n");
	tempFile.setPos(fileH.offset);

	// 读取数据，根据BMP图像为倒置矩阵的特点，在读取时从最后一行开始向上逐行读取，另外，也要考虑到BMP图像的像素格式为BGR
	Log::Print(Log::DebugLog, "读取数据\n");
	for (i32 i = getHeight() - 1; i >= 0; i--) {
		tempFile.read((byte*) (fbX[i]), lineSize);
	}

	return self;
}

Image_BMP& Image_BMP::copy(const Image_BMP &other) {
	return self;
}

Image_BMP& Image_BMP::move(Image_BMP &&other) {
	return self;
}

}
}

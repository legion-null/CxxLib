#pragma once

// 一般类 -------------------------------------------------------------------------//

// 声明
#define CXX_OBJECT_DEF(CLASS) \
public:\
	/* 默认构造函数 */\
	CLASS() {\
		init();\
	}\
\
	/* 析构函数 */\
	virtual ~CLASS() {\
		remove();\
	}\
\
public:\
	/* 复制构造函数 */\
	CLASS(const CLASS &other) {\
		copy(other);\
	}\
\
	/* 移动构造函数 */\
	CLASS(CLASS &&other) {\
		move(static_cast<CLASS&&>(other));\
	}\
\
public:\
	/* 复制构造函数 操作符重载形式 */\
	CLASS& operator=(const CLASS &other) {\
		return copy(other);\
	}\
\
	/* 移动构造函数 操作符重载形式 */\
	CLASS& operator=(CLASS &&other) {\
		return move(static_cast<CLASS&&>(other));\
	}\

// 实现
#define CXX_OBJECT_REALIZATION(CLASS)

//--------------------------------------------------------------------------------//

// 抽象类 -------------------------------------------------------------------------//

// 声明
#define CXX_ABSTRACT_OBJECT_DEF(CLASS) \

// 实现
#define	CXX_ABSTRACT_OBJECT_REALIZATION(CLASS)

//--------------------------------------------------------------------------------//

// 接口类 -------------------------------------------------------------------------//

// 声明
#define CXX_INTERFACE_DEF(CLASS)

// 实现
#define	CXX_INTERFACE_REALIZATION(CLASS)

//--------------------------------------------------------------------------------//

// 模板类 -------------------------------------------------------------------------//

// 声明
#define	CXX_TEMPLATE_OBJECT_DEF(CLASS)

// 实现
#define	CXX_TEMPLATE_OBJECT_REALIZATION(CLASS)

//--------------------------------------------------------------------------------//

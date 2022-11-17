#pragma once

// 标识符转字符串
#define __CXX_STR(X)		#X
#define CXX_STR(X)			__CXX_STR(X)

// 字符串拼接
#define __CXX_PASTE(A,B)	A##B
#define CXX_PASTE(A,B)		__CXX_PASTE(A,B)


#define CXX_CODE_LOCATION	"文件:%s, 函数:%s, 行:%d\n",__FILE__,__FUNCTION__,__LINE__
#define CXX_DATE_TIME		"%s,%s,%s\n",__DATE__,__TIME__,__TIMESTAMP__
#define CXX_CC_VERSION		"GCC Vesrion = %s\n",__VERSION__

#define CXX_GET_CLASSNAME(E)	CXX_STR(E)

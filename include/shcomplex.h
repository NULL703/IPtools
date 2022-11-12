/************************************************************************
公式库的复数计算函数和公式(标头文件)。
Copyright (C) 2022 NULL_703. All rights reserved.
Created on 2022.5.31  18:56
Created by NULL_703
Last change time on 2022.5.31  20:20
************************************************************************/
#ifndef LIBFORMULA_SHCOMPLEX_H
#define LIBFORMULA_SHCOMPLEX_H

#include "formulas.h"

#ifdef __cplusplus
extern "C"{
#endif

/*---------------------------------------------------------------------*/
//复数的加、减运算(函数组主函数)
SHK_COMPLEX shk_clxaddsub(SHK_COMPLEX clx1, SHK_COMPLEX clx2, int calcMode);
//复数的加法运算(函数组引导函数)
SHK_COMPLEX shk_clxadd(SHK_COMPLEX clx1, SHK_COMPLEX clx2);
//复数的减法运算(函数组引导函数)
SHK_COMPLEX shk_clxsub(SHK_COMPLEX clx1, SHK_COMPLEX clx2);
/*---------------------------------------------------------------------*/
//复数的乘法运算
SHK_COMPLEX shk_clxmul(SHK_COMPLEX clx1, SHK_COMPLEX clx2);
//复数的除法运算
SHK_COMPLEX shk_clxdiv(SHK_COMPLEX clx1, SHK_COMPLEX clx2);

#ifdef __cplusplus
}
#endif    //__cplusplus
#endif    //LIBFORMULA_SHCOMPLEX_H
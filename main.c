/*
主程序。
Author: NULL_703
Created on: 2022.11.11    17:46
*/
#include <stdio.h>
#include <stdlib.h>
#include <formulas.h>
#include <network.h>

const char options[0xa][0x20] = {
    "", "--subnetmask-sn", "--subnetmask-bit", "--bintodec", "--dectobin", "--binand", "--binor", "--binNot"
};

SHK_BOOL argsCountCheck(int argc, int stdArgc)
{
    if(argc != stdArgc)
    {
        printf("Error: 选项数量不符合要求！");
        return SHK_FALSE;
    }
    return SHK_TRUE;
}

SHK_IPV4ADDR arg2IPV4(const char* argIPV4)
{
    char temp[5];
    int index = 0;
    int tresloop = 0;
    int tres[4];
    SHK_IPV4ADDR result = {0, 0, 0, 0};
    while(argIPV4)
    {
        for(int i = 0; i < 4; i++, index++)
        {
            if(argIPV4[index] == '.')
            {
                temp[i] = '\0';
                index++;
                break;
            }
            temp[i] = argIPV4[index];
        }
        temp[3] = '\0';
        if(tresloop > 4) break;
        tres[tresloop] = atoi(temp);
        tresloop++;
    }
    for(int j = 0; j < 4; j++)
    {
        switch(j)
        {
            case 0: result.IPV4_A = tres[j]; break;
            case 1: result.IPV4_B = tres[j]; break;
            case 2: result.IPV4_C = tres[j]; break;
            case 3: result.IPV4_D = tres[j]; break;
        }
    }
    return result;
}

int optionMatch(const char* option)
{
    int optIndex = 0;
    while(optIndex < 0xa)
    {
        if(shk_scmp(option, options[optIndex]) == SHK_TRUE) break;
        optIndex++;
    }
    return optIndex;
}

int IPV4_subnetMaskCalc(SHK_IPV4ADDR IPAddress, int netNum)
{
    SHK_IPV4ADDR subnetMask = {0, 0, 0, 0};
    subnetMask = shk_getSubnetmask(IPAddress, netNum);
    printf("根据所提供的条件，所得到的子网掩码是：%d.%d.%d.%d。\n",
        subnetMask.IPV4_A, subnetMask.IPV4_B, subnetMask.IPV4_C, subnetMask.IPV4_D);
    return 0;
}

int IPV4_netprSubnetMaskCalc(SHK_IPV4ADDR IPaddress, int netprefix)
{
    SHK_IPV4ADDR subnetMask = {0, 0, 0, 0};
    subnetMask = shk_getNotypeIPmask(IPaddress, netprefix);
    printf("根据所提供的条件，所得到的子网掩码是：%d.%d.%d.%d。\n", 
        subnetMask.IPV4_A, subnetMask.IPV4_B, subnetMask.IPV4_C, subnetMask.IPV4_D);
    return 0;
}

int bin2dec(const char* bin)
{
    printf("二进制%s的十进制值为：%d。\n", bin, shk_BinToDec(bin));
    return 0;
}

int dec2bin(int dec)
{
    printf("十进制%d的二进制值为：%s。\n", dec, shk_DecToBin(dec));
    return 0;
}

int andCalc(const SHK_BINARY bin1, const SHK_BINARY bin2)
{
    SHK_BINARY res = shk_BitAnd(bin1, bin2);
    printf("二进制%s和%s的与运算结果是：%s，十进制值为%d。\n", bin1, bin2, res, shk_BinToDec(res));
    return 0;
}

int orCalc(const SHK_BINARY bin1, const SHK_BINARY bin2)
{
    SHK_BINARY res = shk_BitOr(bin1, bin2);
    printf("二进制%s和%s的或运算结果是：%s，十进制值为%d。\n", bin1, bin2, res, shk_BinToDec(res));
    return 0;
}

int notCalc(const SHK_BINARY bin)
{
    SHK_BINARY res = shk_BitNot(bin);
    printf("二进制%s的非运算结果是：%s，十进制值为%d。\n", bin, res, shk_BinToDec(res));
    return 0;
}

int main(int argc, char** argv)
{
    switch(optionMatch(argv[1]))
    {
        case 0:
        case 1: {
            if(argsCountCheck(argc, 4) == SHK_FALSE) return 2;
            return IPV4_subnetMaskCalc(arg2IPV4(argv[2]), atoi(argv[3]));
        }
        case 2: {
            if(argsCountCheck(argc, 4) == SHK_FALSE) return 2;
            return IPV4_netprSubnetMaskCalc(arg2IPV4(argv[2]), atoi(argv[3]));
        }
        case 3: {
            if(argsCountCheck(argc, 3) == SHK_FALSE) return 2;
            return bin2dec(argv[2]);
        }
        case 4: {
            if(argsCountCheck(argc, 3) == SHK_FALSE) return 2;
            return dec2bin(atoi(argv[2]));
        }
        case 5: {
            if(argsCountCheck(argc, 4) == SHK_FALSE) return 2;
            return andCalc(argv[2], argv[3]);
        }
        case 6: {
            if(argsCountCheck(argc, 4) == SHK_FALSE) return 2;
            return orCalc(argv[2], argv[3]);
        }
        case 7: {
            if(argsCountCheck(argc, 3) == SHK_FALSE) return 2;
            return notCalc(argv[2]);
        }
        default: printf("Error: 命令选项不存在！\n");
    }
    return 0;
}
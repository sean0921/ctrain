/*******************************************************************************
* encoding: UTF-8
* 編譯方式：gcc -o hw3 hw3.c
* 執行方式：./hw3 <第M個模式> <32/64 bit pattern或整數或浮點數>
* 程式功能：將 32/64 bit pattern 與 整數/浮點數 互相轉換
********************************************************************************/

#include <stdio.h>
#include <stdlib.h> // atoi(),

int main(int argc, char *argv[]) {
/* 一樣限制輸入參數的數目 */
    if (argc != 3) {
        printf("Please input at least 2 interger as arguments. :)\n");
        return 0;
    }

    int trans_mode; // mode, M=1~6
    int i,j;
/* 儲存讀取到的 32 bit 的 pattern 的陣列 */
    int thtw[32];
/* 儲存64 bit 的 pattern  的陣列，宣告也要注意相關整數型態 */
    unsigned long long sxfr[64];
    int sign;
    int exponent_orig = -127;
    float exponent = 1;
    int mantisa_orig[23];
    float mantisa_orig_float[23];
    float mantisa_float;
    unsigned int result_int = 0;
    unsigned long long result_int64 = 0;
    float result_float;
    int32_t input_int32;
    int64_t input_int64;
    float input_float;
    double input_double;
    int result_thtw[32];
    int result_sxfr[64];
    
/* 將狀況依題目分成 1~6 種 */
    trans_mode = atoi(argv[1]);

    switch( trans_mode ) {
/* 將讀取到的 32bit pattern 轉成 integer 或是 float 形式 */
        case 1:
            /* calculate decimal integer first */
		/* 利用 ASCII 字碼表的順序將讀取到的字元型態的數字轉換成整數型態，再做 bitwise operation */
            for(i=0;i<32;i++) {
                thtw[i]=argv[2][i]-'0';
                result_int += thtw[i] << (31-i);
            }
            printf("interger: %d\n", result_int);
            float trans_bits_float;
		/* 利用指標強制轉型的方式，直接將該 pattern 的 float型態表現出來 */
            trans_bits_float = *((float*)&result_int);
            printf("float: %f\n", trans_bits_float);
            break;

        case 2:
            input_int32 = atoi(argv[2]);
            printf("32-bit: ");
/* 將讀取到的整數 right shift，然後再讓它跟最後一碼是 1 的 pattern 作對應以決定列印出來的 bit pattern */
            for(i=0;i<32;i++) {
                j = input_int32 >> (31-i);
                if(j & 1) {
                    printf("1");
                } else {
                    printf("0");
                }
            }
            printf("\n");
            break;
        case 3:
            input_float = atof(argv[2]);
            printf("32-bit: ");
            int32_t trans_bits;
            trans_bits = *((int32_t*)&input_float);
/* 利用指標特性將 float 強制轉型成 interger 型態，再將讀取到的整數 right shift，然後再讓它跟最後一碼是 1 的 pattern 作對應以決定列印出來的 bit pattern */
            for(i=0;i<32;i++) {
                j = trans_bits >> (31-i);
                if(j & 1) {
                    printf("1");
                } else {
                    printf("0");
                }
            }
            printf("\n");
            break;
/* 將讀取到的 64bit pattern 轉成 integer 或是 float 形式 */
        case 4:
            /* calculate decimal integer first */
            for(i=0;i<64;i++) {
                sxfr[i]=argv[2][i]-'0';
                result_int64 += sxfr[i] << (63-i);
            }
            printf("interger: %llu\n", result_int64);
            double trans_bits_double;
		/* 利用指標強制轉型的方式，直接將該 pattern 的 double型態表現出來 */
            trans_bits_double = *((double*)&result_int64);
            printf("double: %lf\n", trans_bits_double);
            break;

        case 5:
            input_int64 = atoi(argv[2]);
/* 將讀取到的整數 right shift，然後再讓它跟最後一碼是 1 的 pattern 作對應以決定列印出來的 bit pattern */
            printf("64-bit: ");
            for(i=0;i<64;i++) {
                j = input_int64 >> (63-i);
                if(j & 1) {
                    printf("1");
                } else {
                    printf("0");
                }
            }
            printf("\n");
            break;
        case 6:
            input_double = atof(argv[2]);
            printf("64-bit: ");
            unsigned long long trans_bits64;
/* 利用指標特性將 double 強制轉型成 unsigned long long 型態，再將讀取到的整數 right shift，然後再讓它跟最後一碼是 1 的 pattern 作對應以決定列印出來的 bit pattern */
            trans_bits64 = *((unsigned long long*)&input_double);
            for(i=0;i<64;i++) {
                j = trans_bits64 >> (63-i);
                if(j & 1) {
                    printf("1");
                } else {
                    printf("0");
                }
            }
            printf("\n");
            break;
    }

    return 0;
}


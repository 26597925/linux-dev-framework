/* 
 * �����Ϊ��ѡ���Դ�����
 * ������İ�Ȩ(����Դ�뼰�����Ʒ����汾)��һ�й������С�
 * ����������ʹ�á������������
 * ��Ҳ�������κ���ʽ���κ�Ŀ��ʹ�ñ����(����Դ�뼰�����Ʒ����汾)���������κΰ�Ȩ���ơ�
 * =====================
 * ����: ������
 * ����: sunmingbao@126.com
 */

#include <stdio.h>
#include "debug.h"
#include "trace_exception.h"

//����Ĵ���������һ���ڴ�����쳣
static int a;
int __attribute__((noinline)) gen_SIGSEGV(int *bad_pointer)
{
    unsigned long *bp;

    asm ("movl %%ebp, %0":"=qm"(bp));
    DBG_PRINT("bp=%p", bp);

    a = *bad_pointer;
    return a;
}

int __attribute__((noinline)) SIGSEGV_test(int para)
{
        unsigned long *bp;

    asm ("movl %%ebp, %0":"=qm"(bp));
    DBG_PRINT("bp=%p", bp);

    return gen_SIGSEGV(NULL)+para;
}

int __attribute__((noinline)) main(int argc, char *argv[])
{
    unsigned long *bp;

    asm ("movl %%ebp, %0":"=qm"(bp));
    DBG_PRINT("bp=%p", bp);

    trace_exception_init();
    SIGSEGV_test(555);
    return 0;
}




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
#include "trace_exception.h"

int a;
int *pa=(void *)0xfa;


int gen_SIGSEGV()
{
    a = *pa;
    return 5;
}

int SIGSEGV_test()
{
    int ret = 8;

    return gen_SIGSEGV()+ret;
}

int main(int argc, char *argv[])
{
    trace_exception_init();

    return SIGSEGV_test();
}


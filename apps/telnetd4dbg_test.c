/* 
 * �����Ϊ��ѡ���Դ�����
 * ������İ�Ȩ(����Դ�뼰�����Ʒ����汾)��һ�й������С�
 * ����������ʹ�á������������
 * ��Ҳ�������κ���ʽ���κ�Ŀ��ʹ�ñ����(����Դ�뼰�����Ʒ����汾)���������κΰ�Ȩ���ơ�
 * =====================
 * ����: ������
 * ����: sunmingbao@126.com
 */

#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include "debug.h"
#include "telnetd4dbg.h"

void hello()
{
    DBG_PRINT("777");
}

int my_var = 1234;
int my_func(long para1, char *para2, unsigned long para3)
{
    printf("para1=%ld para2=%p para3=%lu\n", para1, para2, para3);
    printf("para2 contents = %s", para2);
    return 0;
}

int main(int argc, char *argv[])
{
    telnetd4dbg_init(10000);

    while (1)
    {
        sleep(5);
    }

    return 0;
}


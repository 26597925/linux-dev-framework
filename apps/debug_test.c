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


int main(int argc, char *argv[])
{
    char haha[121] = "I will always love fangfang";
    print_mem(haha, sizeof(haha));

    DBG_PRINT_ERR_QUIT("%d %d", 1, 2);

    printf("haha");
    return 0;
}


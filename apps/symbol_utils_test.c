/* 
 * �����Ϊ��ѡ���Դ�����
 * ������İ�Ȩ(����Դ�뼰�����Ʒ����汾)��һ�й������С�
 * ����������ʹ�á������������
 * ��Ҳ�������κ���ʽ���κ�Ŀ��ʹ�ñ����(����Դ�뼰�����Ʒ����汾)���������κΰ�Ȩ���ơ�
 * =====================
 * ����: ������
 * ����: sunmingbao@126.com
 */

/* 
 * ������ʵ���˲鿴�����е�ȫ�ֱ���ֵ���Լ�ִ�н����еĵ��Ժ����Ĺ��ܡ�
 * Ŀǰ���ܻ������ơ�
 */

#include <stdio.h>
#include <errno.h>


#include "symbol_utils.h"


int my_var = 1234;
int my_func(int para1, int para2)
{
    printf("para1=%d, para2=%d\n", para1, para2);
    return 0;
}


int main(int argc, char *argv[])
{
    init_symbol();
    var_value("my_var");
    exec_func("my_func(20, 15)");


    return 0;
}


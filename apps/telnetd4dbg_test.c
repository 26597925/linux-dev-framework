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
#include "telnetd4dbg.h"
#include "log.h"


int main(int argc, char *argv[])
{
    init_log("abc.log", 1024*1024);
    
    telnetd4dbg_init(10000);

        while (1)
    {


        sleep(5);

    }


    return 0;
}


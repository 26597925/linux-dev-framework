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
 * ������ʵ���˲鿴�����е�ȫ�ֱ������Լ�ִ�н����еĵ��Ժ����Ĺ��ܡ�
 * �������к�init_symbol�����ᴴ��һ���̣߳����̴߳ӱ�׼�����ȡ
 * �û�����ı����������������Ȼ�������Ӧ�Ľ����
 * ���磬
 * ���� my_var�����ɲ鿴����my_var����Ϣ��
 * ���� my_func(1, "good", 0x123) ����ʹ������Ĳ���ִ�к���my_func
 * Ŀǰ���֧��8����������ÿ������size�������sizeof(long)
 * my_func�����ĸ�����ξ���һ������Ҫ������ӡ�
 *
 * ���� d(mem_addr, len) ���Բ鿴�ڴ������
 * ���磬
 * ���� d(0x12345678, 32) ���ɲ鿴�ڴ��ַ0x12345678����32���ֽڵ����ݡ�
 * 
 */


#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include "symbol_utils.h"

int my_var = 1234;
int my_func(long para1, char *para2, unsigned long para3)
{
    printf("para1=%ld para2=%p para3=%lu\n", para1, para2, para3);
    printf("para2 contents = %s", para2);
    return 0;
}

int main(int argc, char *argv[])
{
    init_symbol();

    while (1)
    {
        sleep(1);
    }
    
    return 0;
}



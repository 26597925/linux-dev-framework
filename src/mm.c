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
#include "list.h"
#include "log.h"

static int buffer_num_total;
static int buffer_num_free;

struct list_head free_buffers;

typedef struct
{
    struct list_head list;
    char   buffer[0];
} t_buffer;

void free_buffer_inner(void *buf)
{
    t_buffer *pt_buffer=buf;
    list_add_tail(&(pt_buffer->list), &free_buffers);
    buffer_num_free++;
}

void free_buffer(void *buf)
{
    free_buffer_inner(buf-sizeof(t_buffer));
}

void *alloc_buffer()
{
    t_buffer *pt_buffer;
    struct list_head *pt_list=free_buffers.next;
    
    if (0==buffer_num_free) return NULL;

    list_del(pt_list);
    buffer_num_free--;
    pt_buffer=list_entry(pt_list, t_buffer, list);
    
    return pt_buffer->buffer;
}

int init_buffer(int buf_size, int num)
{
    int i;
    int actual_buf_size=sizeof(t_buffer)+buf_size;
    void *all_mem=malloc(actual_buf_size*num);

    if (NULL==all_mem)
    {
        ErrSysLog("malloc failed");
        return -1;
    }

    buffer_num_total=num;
    INIT_LIST_HEAD(&free_buffers);

    for (i=0; i<num; i++)
    {
        free_buffer_inner(all_mem+i*actual_buf_size);
    }
    
    return 0;
}


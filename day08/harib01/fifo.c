

#include "bootpack.h"

#define FLAGS_OVERRUN           0x0001

void fifo8_init(struct FIFO8 *fifo, int size, unsigned char *buf)
/* initiate FIFO buffer */
{
    fifo->size = size;
    fifo->buf = buf;
    fifo->free = size;  /* 缓冲区的大小 */
    fifo->flags = 0;
    fifo->p = 0;        /* 下一个数据写入位置 */
    fifo->q = 0;        /* 下一个数据独处位置 */
    return;
}

int fifo8_put(struct FIFO8 *fifo, unsigned char data)
/* 向FIFO传送数据并保存 */
{
    if (fifo->free == 0) {
        /* 空余没有了，溢出 */
        fifo->flags |= FLAGS_OVERRUN;
        return -1;
    }
    fifo->buf[fifo->p] = data;
    fifo->p++;
    if (fifo->p == fifo->size) {
        fifo->p = 0;
    }
    fifo->free--;
    return 0;
}

int fifo8_get(struct FIFO8 *fifo)
/* 从FIFO取得一个数据 */
{
    int data;
    if (fifo->free == fifo->size) {
        return -1;
    }
    data = fifo->buf[fifo->q];
    fifo->q++;
    if (fifo->q == fifo->size) {
        fifo->q = 0;
    }
    fifo->free++;
    return data;
}


int fifo8_status(struct FIFO8 *fifo)
/* 报告一下到底积攒了多少数据 */
{
    return fifo->size - fifo->free;
}

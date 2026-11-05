/*
header file for liu laolao kernel module by Raymond 
*/
#include "gearm.h"

void ge_assign_sku(gd_box* box,enum gd_box_id flag);
long ge_probe_kernel_read(void *dst, const void *src, size_t size);
void ll_timer_callback(unsigned long arg);
int ll_writenull_in_timer(void);
void ge_percpu(void);


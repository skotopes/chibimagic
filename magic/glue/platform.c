#include "platform.h"

int32_t swj_delay_cnt;
int cl_debuglevel;

void gdb_if_putchar(unsigned char c, int flush) {
	(void)c;
	(void)flush;
}

unsigned char gdb_if_getchar(void) {
	return 0;
}

unsigned char gdb_if_getchar_to(int timeout) {
	(void) timeout;
	return 0;
}
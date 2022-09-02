#ifndef _NTR_UTILS_H_
#define _NTR_UTILS_H_ 1

#ifndef NULL
#define NULL ((void*)0)
#endif

#define STDIN_NO	0
#define STDOUT_NO	1
#define STDERR_NO	2

#define bool unsigned char
#define true 1
#define false 0
#define time_t int

extern int read(int fd, const void *buff, unsigned long n);
extern int write(int fd, const void *buff, unsigned long n);
extern int time(time_t *tloc);
__attribute__((noreturn))
extern void exit(int rev);

void srand(unsigned s);
int randTo(unsigned n);
int rand(void);

#endif // _NTR_UTILS_H_


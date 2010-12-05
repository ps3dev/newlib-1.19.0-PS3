#include <stdint.h>

#define LV2_INLINE static inline __attribute__((unused))

#define __lv2syscallarg0 
#define __lv2syscallarg1 __lv2syscallarg0, uint64_t a1
#define __lv2syscallarg2 __lv2syscallarg1, uint64_t a2
#define __lv2syscallarg3 __lv2syscallarg2, uint64_t a3
#define __lv2syscallarg4 __lv2syscallarg3, uint64_t a4
#define __lv2syscallarg5 __lv2syscallarg4, uint64_t a5
#define __lv2syscallarg6 __lv2syscallarg5, uint64_t a6
#define __lv2syscallarg7 __lv2syscallarg6, uint64_t a7
#define __lv2syscallarg8 __lv2syscallarg7, uint64_t a8

#define __lv2syscallclobber8 "r0", "r2", "r12", "lr", \
	"ctr", "xer", "cr0", "cr1", "cr5", "cr6", "cr7", \
	"memory"
#define __lv2syscallclobber7 __lv2syscallclobber8, "r10"
#define __lv2syscallclobber6 __lv2syscallclobber7, "r9"
#define __lv2syscallclobber5 __lv2syscallclobber6, "r8"
#define __lv2syscallclobber4 __lv2syscallclobber5, "r7"
#define __lv2syscallclobber3 __lv2syscallclobber4, "r6"
#define __lv2syscallclobber2 __lv2syscallclobber3, "r5"
#define __lv2syscallclobber1 __lv2syscallclobber2, "r4"
#define __lv2syscallclobber0 __lv2syscallclobber1, "r3"
#define __lv2syscallreg(num, reg) \
	register uint64_t p##num asm(reg) = a##num
#define __lv2syscallregs \
	register uint64_t s asm("11") = syscall
#define __lv2syscallparam1(reg) reg(p1), reg(s)
#define __lv2syscallparam2(reg) reg(p1), reg(p2), reg(s)
#define __lv2syscallparam3(reg) reg(p1), reg(p2), reg(p3), reg(s)
#define __lv2syscallparam4(reg) reg(p1), reg(p2), reg(p3), reg(p4), reg(s)
#define __lv2syscallparam5(reg) reg(p1), reg(p2), reg(p3), reg(p4), reg(p5), reg(s)
#define __lv2syscallparam6(reg) reg(p1), reg(p2), reg(p3), reg(p4), reg(p5), reg(p6), reg(s)
#define __lv2syscallparam7(reg) reg(p1), reg(p2), reg(p3), reg(p4), reg(p5), reg(p6), reg(p7), reg(s)
#define __lv2syscallparam8(reg) reg(p1), reg(p2), reg(p3), reg(p4), reg(p5), reg(p6), reg(p7), reg(p8), reg(s)
LV2_INLINE uint64_t __lv2syscall0(uint64_t syscall __lv2syscallarg0) {
	__lv2syscallregs;
	register uint64_t p1 asm("3") = 0;
	asm volatile("sc"
			: __lv2syscallparam1("=r")
			: __lv2syscallparam1("r")
			: __lv2syscallclobber1);
	return p1;
}
LV2_INLINE uint64_t __lv2syscall1(uint64_t syscall __lv2syscallarg1) {
	__lv2syscallregs;
	__lv2syscallreg(1, "3");
	asm volatile("sc"
			: __lv2syscallparam1("=r")
			: __lv2syscallparam1("r")
			: __lv2syscallclobber1);
	return p1;
}
LV2_INLINE uint64_t __lv2syscall2(uint64_t syscall __lv2syscallarg2) {
	__lv2syscallregs;
	__lv2syscallreg(1, "3");
	__lv2syscallreg(2, "4");
	asm volatile("sc"
			: __lv2syscallparam2("=r")
			: __lv2syscallparam2("r")
			: __lv2syscallclobber2);
	return p1;
}
LV2_INLINE uint64_t __lv2syscall3(uint64_t syscall __lv2syscallarg3) {
	__lv2syscallregs;
	__lv2syscallreg(1, "3");
	__lv2syscallreg(2, "4");
	__lv2syscallreg(3, "5");
	asm volatile("sc"
			: __lv2syscallparam3("=r")
			: __lv2syscallparam3("r")
			: __lv2syscallclobber3);
	return p1;
}
LV2_INLINE uint64_t __lv2syscall4(uint64_t syscall __lv2syscallarg4) {
	__lv2syscallregs;
	__lv2syscallreg(1, "3");
	__lv2syscallreg(2, "4");
	__lv2syscallreg(3, "5");
	__lv2syscallreg(4, "6");
	asm volatile("sc"
			: __lv2syscallparam4("=r")
			: __lv2syscallparam4("r")
			: __lv2syscallclobber4);
	return p1;
}
LV2_INLINE uint64_t __lv2syscall5(uint64_t syscall __lv2syscallarg5) {
	__lv2syscallregs;
	__lv2syscallreg(1, "3");
	__lv2syscallreg(2, "4");
	__lv2syscallreg(3, "5");
	__lv2syscallreg(4, "6");
	__lv2syscallreg(5, "7");
	asm volatile("sc"
			: __lv2syscallparam5("=r")
			: __lv2syscallparam5("r")
			: __lv2syscallclobber5);
	return p1;
}
LV2_INLINE uint64_t __lv2syscall6(uint64_t syscall __lv2syscallarg6) {
	__lv2syscallregs;
	__lv2syscallreg(1, "3");
	__lv2syscallreg(2, "4");
	__lv2syscallreg(3, "5");
	__lv2syscallreg(4, "6");
	__lv2syscallreg(5, "7");
	__lv2syscallreg(6, "8");
	asm volatile("sc"
			: __lv2syscallparam6("=r")
			: __lv2syscallparam6("r")
			: __lv2syscallclobber6);
	return p1;
}
LV2_INLINE uint64_t __lv2syscall7(uint64_t syscall __lv2syscallarg7) {
	__lv2syscallregs;
	__lv2syscallreg(1, "3");
	__lv2syscallreg(2, "4");
	__lv2syscallreg(3, "5");
	__lv2syscallreg(4, "6");
	__lv2syscallreg(5, "7");
	__lv2syscallreg(6, "8");
	__lv2syscallreg(7, "9");
	asm volatile("sc"
			: __lv2syscallparam7("=r")
			: __lv2syscallparam7("r")
			: __lv2syscallclobber7);
	return p1;
}
LV2_INLINE uint64_t __lv2syscall8(uint64_t syscall __lv2syscallarg8) {
	__lv2syscallregs;
	__lv2syscallreg(1, "3");
	__lv2syscallreg(2, "4");
	__lv2syscallreg(3, "5");
	__lv2syscallreg(4, "6");
	__lv2syscallreg(5, "7");
	__lv2syscallreg(6, "8");
	__lv2syscallreg(7, "9");
	__lv2syscallreg(8, "10");
	asm volatile("sc"
			: __lv2syscallparam8("=r")
			: __lv2syscallparam8("r")
			: __lv2syscallclobber8);
	return p1;
}

extern void __lv2errno(int32_t errcode);


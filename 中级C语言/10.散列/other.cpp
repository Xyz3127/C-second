#include "fun.h"

int hash(const char* key) {//É¢ÁÐº¯Êý
	int h = 0, g;
	while (*key) {
		h = (h << 4) + *key++;
		g = h & 0xf0000000;
		if (g) {
			h ^= g >> 24;
		}
		h &= ~g;
	}
	return h % MaxKey;
}
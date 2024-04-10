#ifndef UTILS_H
#define UTILS_H

int count_ones(unsigned int dec) {
	int count = 0;
    while (dec != 0) {
        count += dec & 1;   // Add 1 if the last bit is 1
        dec >>= 1;          // Shift the number right by 1
    }
    return count;
}

#endif // UTILS_H

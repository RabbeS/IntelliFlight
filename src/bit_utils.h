
#ifndef INTELLIFLIGHT_BIT_UTILS_H
#define INTELLIFLIGHT_BIT_UTILS_H

//! Set bit y (0-indexed) of x to '1' by generating a a mask with a '1' in the proper bit location and ORing x with the mask.
#define BIT_SET(x, y) (x |= (1 << y))

//! Set bit y (0-indexed) of x to '0' by generating a mask with a '0' in the y position and 1's elsewhere then ANDing the mask with x.
#define BIT_CLEAR(x, y) (x &= ~(1<< y))

//! Return '1' if the bit value at position y within x is '1' and '0' if it's 0 by ANDing x with a bit mask where the bit in y's position is '1' and '0' elsewhere and comparing it to all 0's.  Returns '1' in least significant bit position if the value of the bit is '1', '0' if it was '0'.
#define BIT_READ(x, y) (((0u == (x & (1<<y)))?0u:1u))

//! Toggle bit y (0-index) of x to the inverse: '0' becomes '1', '1' becomes '0' by XORing x with a bitmask where the bit in position y is '1' and all others are '0'.
#define BIT_TOGGLE(x, y) ((x ^= (1<<y)))

//! Concatenate two variables by shifting the first one by `len` bits and ORing the second variable.
#define BIT_CONCAT(A, len, B) ((A << len) | B)

//! Get the prefix of length `len` from some data A
#define BIT_GET_PREFIX(A, len) (A >> (sizeof(A)*8 - len))

/**
 * Get the last `len` bits of some data type by
 *     1) generate 1-bit vector of same length as A => ~(A^A)
 *     2) shifting data_sie-len zeros to get only the last `len` bits equal to 1
 *     3) &-ing that bit bask
 */
#define BIT_GET_SUFFIX(A, len) (A&~(~(A^A) << len))


#endif //INTELLIFLIGHT_BIT_UTILS_H

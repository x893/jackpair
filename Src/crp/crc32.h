#ifndef __CRC32_H__
#define __CRC32_H__

#include <stdint.h>

// void crc32_init( void );
// void crc32_update( uint8_t *blk_adr, int16_t blk_len );
uint32_t crc32( uint8_t *blk_adr, int16_t blk_len );
// uint32_t crc32_value( void );

#endif

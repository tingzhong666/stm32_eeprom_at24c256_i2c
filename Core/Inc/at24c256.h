/**
 * at24c256.h
 * @tingzhong666
 * 2024-04-04 12:53:59
 */

#ifndef AT24C256_H
#define AT24C256_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "main.h"
#include "i2c.h"

#define AT24C256_I2C hi2c1
#define AT24C256_DEVADDR 0xa0

    typedef struct
    {
        void *data;
        int code;
        char *msg;
    } RES;

    RES at24c256_write_byte(uint16_t romAddr, uint8_t *data);
    RES at24c256_read_byte(uint16_t romAddr, uint8_t *recData);

#ifdef __cplusplus
}
#endif

#endif

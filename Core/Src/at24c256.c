/**
 * at24c256.c
 * @tingzhong666
 * 2024-04-04 12:53:46
 */
#include <at24c256.h>

// 忙确认 1闲 -1忙
RES at24c256_busy()
{
    RES res = {0, 1, "ok"};
    if (HAL_I2C_IsDeviceReady(&AT24C256_I2C, AT24C256_DEVADDR, 1, 5) != HAL_OK)
    {
        res.code = -1;
        res.msg = "at24c256 busying";
    }
    return res;
}

// 写 字节
RES at24c256_write_byte(uint16_t romAddr, uint8_t *data)
{
    RES res = {0, 1, "ok"};
    uint8_t tmp[] = {romAddr >> 8, romAddr & 0xf, *data};
    while (at24c256_busy().code == -1)
        ;
    HAL_I2C_Master_Transmit(&AT24C256_I2C, AT24C256_DEVADDR, tmp, 3, 5);

    return res;
}

// 读 随机读取
RES at24c256_read_byte(uint16_t romAddr, uint8_t *recData)
{
    RES res = {recData, 1, "ok"};
    uint8_t tmp[] = {romAddr >> 8, romAddr & 0xf};
    while (at24c256_busy().code == -1)
        ;
    HAL_I2C_Master_Transmit(&AT24C256_I2C, AT24C256_DEVADDR, tmp, 2, 5);
    HAL_I2C_Master_Receive(&AT24C256_I2C, AT24C256_DEVADDR, recData, 1, 5);
    return res;
}

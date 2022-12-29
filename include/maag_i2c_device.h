/*
    ...

*/
#ifndef __MAAG_I2C_DEVICE_H__
#define __MAAG_I2C_DEVICE_H__

#include <time.h>
#include "driver/i2c.h"

#define I2CDEV_TIMEOUT 1000

class MaagI2CDevice
{
private:
    // device port
    i2c_port_t m_port;
    // device address
    uint8_t m_dev_addr;

public:
    MaagI2CDevice();
    // select port that must already be initialized
    void setPort(i2c_port_t port_);
    // set device address
    void setDeviceAddress(uint8_t dev_addr_);
    // read a registry from device, sending standard cmds and directly reading response
    esp_err_t read(uint8_t *data_reg_, size_t data_reg_size_, uint8_t *in_data_, size_t in_data_size_);
    // read a register from a device that probably uses clock stretching between receiving command and sending back response.
    // A manual delay is implemented between sending cmd and requesting response
    esp_err_t readClockStretched(uint8_t *data_reg_, size_t data_reg_size_, uint8_t *in_data_, size_t in_data_size_, int delay_ms_);
    // write to a device register
    esp_err_t write(uint8_t *data_reg_, size_t data_reg_size_, uint8_t *out_data_, size_t out_data_size_);

};




#endif /* __MAAG_I2C_DEVICE_H__ */
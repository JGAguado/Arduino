#ifndef LIB_ADAFRUIT_CCS811_H
#define LIB_ADAFRUIT_CCS811_H

#if (ARDUINO >= 100)
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#include <Wire.h>
    #define CCS811_ADDRESS                (0x5B)
    enum
    {
        CCS811_STATUS = 0x00,
        CCS811_MEAS_MODE = 0x01,
        CCS811_ALG_RESULT_DATA = 0x02,
        CCS811_RAW_DATA = 0x03,
        CCS811_ENV_DATA = 0x05,
        CCS811_NTC = 0x06,
        CCS811_THRESHOLDS = 0x10,
        CCS811_BASELINE = 0x11,
        CCS811_HW_ID = 0x20,
        CCS811_HW_VERSION = 0x21,
        CCS811_FW_BOOT_VERSION = 0x23,
        CCS811_FW_APP_VERSION = 0x24,
        CCS811_ERROR_ID = 0xE0,
        CCS811_SW_RESET = 0xFF,
    };
	
	//bootloader registers
	enum
	{
		CCS811_BOOTLOADER_APP_ERASE = 0xF1,
		CCS811_BOOTLOADER_APP_DATA = 0xF2,
		CCS811_BOOTLOADER_APP_VERIFY = 0xF3,
		CCS811_BOOTLOADER_APP_START = 0xF4
	};
	
	enum
	{
		CCS811_DRIVE_MODE_IDLE = 0x00,
		CCS811_DRIVE_MODE_1SEC = 0x01,
		CCS811_DRIVE_MODE_10SEC = 0x02,
		CCS811_DRIVE_MODE_60SEC = 0x03,
		CCS811_DRIVE_MODE_250MS = 0x04,
	};


#define CCS811_HW_ID_CODE			0x81

#define CCS811_REF_RESISTOR			100000

class Adafruit_CCS811 {
	public:
		Adafruit_CCS811(void) {};
		~Adafruit_CCS811(void) {};
		
		bool begin(uint8_t addr = CCS811_ADDRESS);

		void setEnvironmentalData(uint8_t humidity, double temperature);

		double calculateTemperature();
		
		void setThresholds(uint16_t low_med, uint16_t med_high, uint8_t hysteresis = 50);

		void SWReset();
		
		void setDriveMode(uint8_t mode);
		void enableInterrupt();
		void disableInterrupt();
		
		uint16_t getTVOC() { return _TVOC; }
		uint16_t geteCO2() { return _eCO2; }
		
		void setTempOffset(float offset) { _tempOffset = offset; }
		
		bool available();
		uint8_t readData();
		
		bool checkError();

	private:
		uint8_t _i2caddr;
		float _tempOffset;
		
		uint16_t _TVOC;
		uint16_t _eCO2;
		
		void      write8(byte reg, byte value);
		void      write16(byte reg, uint16_t value);
        uint8_t   read8(byte reg);
		
		void read(uint8_t reg, uint8_t *buf, uint8_t num);
		void write(uint8_t reg, uint8_t *buf, uint8_t num);
		void _i2c_init();
		
        struct status {
           
            uint8_t ERROR: 1;

            uint8_t DATA_READY: 1;
            uint8_t APP_VALID: 1;

            uint8_t FW_MODE: 1;

            void set(uint8_t data){
            	ERROR = data & 0x01;
            	DATA_READY = (data >> 3) & 0x01;
            	APP_VALID = (data >> 4) & 0x01;
            	FW_MODE = (data >> 7) & 0x01;
            }
        };
        status _status;

        struct meas_mode {
        	uint8_t INT_THRESH: 1;

        	uint8_t INT_DATARDY: 1;

        	uint8_t DRIVE_MODE: 3;

        	uint8_t get(){
        		return (INT_THRESH << 2) | (INT_DATARDY << 3) | (DRIVE_MODE << 4);
        	}
        };
        meas_mode _meas_mode;
		
        struct error_id {
        	uint8_t WRITE_REG_INVALID: 1;

        	uint8_t READ_REG_INVALID: 1;

        	uint8_t MEASMODE_INVALID: 1;

        	uint8_t MAX_RESISTANCE: 1;

        	uint8_t HEATER_FAULT: 1;

        	uint8_t HEATER_SUPPLY: 1;

        	void set(uint8_t data){
        		WRITE_REG_INVALID = data & 0x01;
        		READ_REG_INVALID = (data & 0x02) >> 1;
        		MEASMODE_INVALID = (data & 0x04) >> 2;
        		MAX_RESISTANCE = (data & 0x08) >> 3;
        		HEATER_FAULT = (data & 0x10) >> 4;
        		HEATER_SUPPLY = (data & 0x20) >> 5;
        	}
        };
        error_id _error_id;

};

#endif
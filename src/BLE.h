
#ifndef BLE_h
#define BLE_h

#include <sap/source/ti/sap/sap.h>
#include <Energia.h>
#include "Stream.h"
#include "BLETypes.h"

class BLE : public Stream
{
  private:

  public:
    BLE(void);
    BLE(byte portType);

    int begin(void);
    int end(void);

    int useProfile(BLE_Profile *profile); // For predefined profiles
    int addService(BLE_Service *service);
    int addCharacteristic(BLE_Char *characteristic, BLE_Service *service);
    int addCharacteristic(BLE_Char *characteristic); // Adds to last service
    int registerService(BLE_Service *service);
    int registerService(void); // Registers last service

    int startAdvert(void); // Default settings
    int startAdvert(BLE_Advert_Settings advertSettings);
    int stopAdvert(void);
    int setAdvertData(byte advertType, uint8_t *advertData);
    int setAdvertData(byte advertType, char *advertData);
    int setAdvertData(byte advertType, String *advertData);

    int setConnParams(BLE_Conn_Params *connParams);
    int setGapParam(int paramId, int Value); // Will probably just copy the network processor docs
    int setMinConnInt(int minConnInt); // Number of 1.25ms time slots
    int setMaxConnInt(int maxConnInt); // Number of 1.25ms time slots
    int setRespLatency(int respLatency); // Measured in number of connection intervals the slave can miss.
    int setBleTimeout(int timeout);

    void terminateConn(void);
    void terminateConn(byte abruptly);

    int writeValue(int handle, char value);
    int writeValue(int handle, unsigned char value);
    int writeValue(int handle, int value);
    int writeValue(int handle, unsigned int value);
    int writeValue(int handle, long value);
    int writeValue(int handle, unsigned long value);
    int writeValue(int handle, float value);
    int writeValue(int handle, double value);
    int writeValue(int handle, char *str); // Char array
    int writeValue(int handle, String str); // Object, calls fxn for char array
    boolean readValue_boolean(int handle);
    char readValue_char(int handle);
    unsigned char readValue_uchar(int handle);
    byte readValue_byte(int handle);
    int readValue_int(int handle);
    unsigned int readValue_uint(int handle);
    word readValue_word(int handle);
    long readValue_long(int handle);
    unsigned long readValue_ulong(int handle);
    float readValue_float(int handle);
    double readValue_double(int handle);
    char* readValue_string(int handle);
    String readValue_String(int handle);

    int serial(void);
    int iBeacon(void);
    int nordicBeacon(void);
    int uriBeacon(void);
    int eddystone(void);

    virtual int available(void);
    virtual int read(void);
    virtual int peek(void);
    virtual void flush(void);
    virtual size_t write(uint8_t c);
};


#endif
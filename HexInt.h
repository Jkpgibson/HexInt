#ifndef HEXINT_H
#define HEXINT_H

class HexInt{
private:
    unsigned char value[21];
public:
    HexInt(const char* str);
    ~HexInt();
    char* toString();
    char* toTrimmedString();
    static HexInt* add(HexInt&, HexInt&);
    void getVal();
};


#endif
#include "gdal_parse.h"
//#include "hdf5_reader.cpp"

#include <iostream>

int main()
{
    GDAL_Parse gdal_p("test_L1A.h5");
    //GDAL_Parse gdal_p("test.jpg");
    gdal_p.parse();

    return 0;
}

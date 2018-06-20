#include "gdal_parse.h"
//#include "hdf5_reader.cpp"

#include <iostream>

int main()
{
    GDAL_Parse gdal_p("/home/nat/Documents/data/gis_data/test_L1A.h5");
    //GDAL_Parse gdal_p("/home/nat/Documents/data/gis_data/LE71970272000255ESA00_B6_VCID_2.TIF");

    //GDAL_Parse gdal_p("HDF5:\"/home/nat/Documents/data/gis_data/test_L1A.h5\"://MonthlyRainTotal_GeoGrid/Data_Fields/RrLandRain");
    //GDAL_Parse gdal_p("/home/nat/Documents/data/gis_data/test.jpg");
    gdal_p.parse();

    return 0;
}

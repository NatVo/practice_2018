#include "hdf5_reader.h"
//#include "hdf5_reader.cpp"

#include <iostream>

int main()
{
    HDF5_Reader h5_r("test_L1A.h5");
    //h5_r.test();
    h5_r.parse_hdf5();
    
    return 0;
}

#include "gdal_parse.h"
//#include "hdf5_reader.cpp"

#include <iostream>

#include <string>
#include <vector>

int main()
{
	setlocale(LC_ALL, "en_US.UTF-8");
    //GDAL_Parse gdal_p("/home/nat/Documents/data/gis_data/test_L1A.h5");
    GDAL_Parse gdal_p;
    //gdal_p.output_dataset("/home/nat/Documents/data/gis_data/test_1.TIF");
    //gdal_p.output_dataset("/home/nat/Documents/data/gis_data/test_1.jpg");

    std::vector<std::string> datasets = gdal_p.get_datasets("/home/nat/Documents/data/gis_data/test_1.jpg");
    //std::vector<std::string> datasets = gdal_p.get_datasets("/home/nat/Documents/data/gis_data/test_1.TIF");
    //std::vector<std::string> datasets = gdal_p.get_datasets("/home/nat/Documents/data/gis_data/L_1A.h5");

    //GDAL_Parse gdal_p("HDF5:\"/home/nat/Documents/data/gis_data/test_L1A.h5\"://S01/QLK");
    //GDAL_Parse gdal_p("HDF5:\"/home/nat/Documents/data/gis_data/test_L1A.h5\"://S01/SBI");

    for (int i = 0; i < datasets.size(); i++)
    {
    	gdal_p.output_dataset(datasets[i]);
    }
    
    

    //gdal_p.output_dataset("HDF5:\"/home/nat/Documents/data/gis_data/test_L1A.h5\"://S01/QLK");

    return 0;
}

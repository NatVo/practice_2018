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
    //GDAL_Parse gdal_p("/home/nat/Documents/data/gis_data/LE71970272000255ESA00_B6_VCID_2.TIF");

    //GDAL_Parse gdal_p("HDF5:\"/home/nat/Documents/data/gis_data/test_L1A.h5\"://S01/QLK");
    //GDAL_Parse gdal_p("HDF5:\"/home/nat/Documents/data/gis_data/test_L1A.h5\"://S01/SBI");
    //gdal_p.parse();

    std::vector<std::string> datasets = gdal_p.get_datasets("/home/nat/Documents/data/gis_data/test_L1A.h5");
    //std::vector<std::string> datasets = gdal_p.get_datasets("/home/nat/Documents/data/gis_data/r48368_39_satellite_image_pleiades_raqqa_syria_20171016-2.jpg");
    //gdal_p.output_vector(datasets);
   	
   	/*
    for (int i = 0; i < datasets.size(); i++)
    {
    	gdal_p.output_dataset(datasets[i]);
    }
    */

    //gdal_p.output_dataset("HDF5:\"/home/nat/Documents/data/gis_data/test_L1A.h5\"://S01/QLK");

    return 0;
}

#include "gdal_parse.h"

#include <iostream>
#include <string>

//#include "gdal.h"
#include "gdal_priv.h"
#include "cpl_conv.h"
#include "gdal_frmts.h"

std::string FILE_NAME = "test_L1A.h5";
//std::string FILE_NAME = "test.jpg";

int main()
{
	std::cout << "FILE NAME: " << FILE_NAME << std::endl;
	
    GDALAllRegister();

    GDALDataset *ds = (GDALDataset *)GDALOpen(FILE_NAME.c_str(), GA_ReadOnly);
    
	return 0;
}
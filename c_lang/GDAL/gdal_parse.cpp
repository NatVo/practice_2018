#include "gdal_parse.h"

#include <iostream>

//#include "gdal.h"
#include "gdal_priv.h"
#include "cpl_conv.h"
#include "gdal_frmts.h"


void GDAL_Parse::test() 
{

	std::cout << "SUCCESSFUL TEST" << std::endl;
}

GDAL_Parse::GDAL_Parse(std::string file_name)
{
	FILE_NAME = file_name;
}


void GDAL_Parse::parse()
{
	std::cout << "FILE NAME: " << FILE_NAME << std::endl;
	
	GDALDataset  *poDataset;
    GDALAllRegister();
    poDataset = (GDALDataset *) GDALOpen( FILE_NAME.c_str(), GA_ReadOnly );
    GDALClose(poDataset);

    //GDALDataset *ds = (GDALDataset *)GDALOpen(FILE_NAME.c_str(), GA_ReadOnly);
    
    /*
    if( poDataset == NULL )
    {
        std::cout << "ERROR OPEN" << std::endl;
    }
    */
}
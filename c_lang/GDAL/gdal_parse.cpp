#include "gdal_parse.h"

#include <iostream>
#include <stdio.h>

#include <string>

//#include "gdal.h"
#include "gdal_priv.h"
#include "cpl_conv.h"
//#include "gdal_frmts.h"


void GDAL_Parse::test() 
{

	std::cout << "SUCCESSFUL TEST" << std::endl;
}

GDAL_Parse::GDAL_Parse(std::string file_name)
{
	FILE_NAME = file_name;
}

void GDAL_Parse::iterate_pointer(char **metadata)
{
    int counter = 0;
    for(char* i = *metadata; i != 0; i = *(metadata + counter))
    {
        //std::cout << "METADATA: " << i << std::endl;
        parse_string(std::string(i));
        counter++;
    }
}

void GDAL_Parse::parse_string(std::string metadata)
{
    std::cout << "- METADATA: " << metadata << std::endl;
    //printf("METADATA = %s\n", metadata);
}


void GDAL_Parse::parse()
{
	std::cout << "FILE NAME: " << FILE_NAME << std::endl;
	
    GDALAllRegister();

    GDALDataset *poDataset = (GDALDataset *)GDALOpen(FILE_NAME.c_str(), GA_ReadOnly);
    char **metadata = poDataset->GetMetadata("");
    iterate_pointer(metadata);

    std::cout << "\n\n";

    char **metadata_ds = poDataset->GetMetadata("SUBDATASETS");
    iterate_pointer(metadata_ds);
    
    //std::cout << "METADATA: " << *metadata << std::endl;
    //std::cout << "METADATA: " << (metadata + 1) << std::endl;
    

    //std::cout << poDataset->GetDriver()->GetMetadataItem( GDAL_DMD_LONGNAME ) << std::endl;
    //std::cout << poDataset->GetRasterCount() << std::endl;

    
    if( poDataset  == NULL )
    {
        std::cout << "ERROR TO OPEN" << std::endl;
    }

    GDALClose(poDataset);
    
} 
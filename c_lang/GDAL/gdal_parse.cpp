#include "gdal_parse.h"

#include <iostream>
#include <sstream>

#include <stdio.h>

#include <string>

//#include "gdal.h"
#include "gdal_priv.h"
#include "cpl_conv.h"
//#include "gdal_frmts.h"

/*
void GDAL_Parse::test() 
{

	std::cout << "SUCCESSFUL TEST" << std::endl;
}

GDAL_Parse::GDAL_Parse(std::string file_name)
{
	FILE_NAME = file_name;
}

*/

//                          
//



void GDAL_Parse::iterate_pointer(char **metadata)
{
    int counter = 0;
    for(char* i = *metadata; i != 0; i = *(metadata + counter))
    {
        std::cout << "METADATA: " << i << std::endl;
        //get_values(std::string(i));
        counter++;
    }
}

void GDAL_Parse::output_vector(std::vector<std::string> vect)
{
    for (unsigned int i = 0; i < vect.size(); i++)
    {        
        std::cout << vect[i] << " ";
    }
    std::cout << "\n\n";
}



void GDAL_Parse::get_values(std::string metadata)
{
    std::cout << "- METADATA: " << metadata << std::endl;
    //printf("METADATA = %s\n", metadata);
}

void GDAL_Parse::get_subobjs(std::string metadata)
{
    
}


std::vector<std::string> GDAL_Parse::get_datasets(std::string FILE_NAME)
{
    std::vector<std::string> datasets;

    GDALAllRegister();
    GDALDataset *file = (GDALDataset *)GDALOpen(FILE_NAME.c_str(), GA_ReadOnly);

    char **metadata_ds = file->GetMetadata("SUBDATASETS");
    
    if (metadata_ds != NULL)
    {
        int counter = 0;
        for(char* i = *metadata_ds; i != 0; i = *(metadata_ds + counter))
        {   
            
            if (counter % 2 == 0)
            {
                std::cout << "METADATA: " << std::string(i) << std::endl;
                datasets.push_back(split_string(std::string(i), '=')[1]);
                //output_vector(datasets);
                //std::string ds_name = datasets[1];
                //std::cout << "DATASET NAME: " << split_string(std::string(i), '=')[1] << std::endl;

            }
            
        counter++;
        
        }
    }
    else
    {
        datasets.push_back(FILE_NAME);
    }


    GDALClose(file);

    return datasets;

}

void GDAL_Parse::output_dataset(std::string ds_name)
{
    GDALAllRegister();
    GDALDataset *ds = (GDALDataset *)GDALOpen(ds_name.c_str(), GA_ReadOnly);

    int ysize = ds->GetRasterXSize();
    int xsize = ds->GetRasterYSize();
    int num_raster = ds->GetRasterCount();

    std::cout << "XSIZE: " << xsize << std::endl; //1303
    std::cout << "YSIZE: " << ysize << std::endl; //279
    std::cout << "NUMBER OF RASTERS: " << num_raster;

    xsize = 5; //for example
    for (int raster = 1; raster <= 1; raster++)
    {

        GDALRasterBand *rb = ds->GetRasterBand(raster);

        float *buffer = new float[xsize * ysize];
        rb->RasterIO(GF_Read, 0, 5, ysize, xsize, buffer, ysize, xsize, GDT_Float32, 0, 0);

            for (int j = 0; j < xsize; ++j) {
                for (int k = 0; k < ysize; ++k) {
                    std::cout << buffer[j * ysize + k] << " ";
                }
                std::cout << "\n\n";
            }
            delete [] buffer;

    }
    std::cout << "==========================================================================================================\n";
    std::cout << "\n\n";

    GDALClose(ds);
}


std::vector<std::string> GDAL_Parse::split_string(const std::string &line, char delimiter) 
{
    std::vector<std::string> result;
    
    std::stringstream ss(line);
    std::string item;

    
    
    while (std::getline(ss, item, delimiter)) 
    {
        //result.push_back(item);
        result.push_back(std::move(item)); 
    }

    
    return result;
}


//void GDAL_Parse::parse()
//{

	//std::cout << "FILE NAME: " << FILE_NAME << std::endl;
	
    //GDALAllRegister();

    //GDALDataset *poDataset = (GDALDataset *)GDALOpen(FILE_NAME.c_str(), GA_ReadOnly);
    //char **metadata = poDataset->GetMetadata("");
    //iterate_pointer(metadata);

    //char **metadata_ds = poDataset->GetMetadata("SUBDATASETS");
    //iterate_pointer(metadata_ds);
    /*

    int ysize = poDataset->GetRasterXSize();
    int xsize = poDataset->GetRasterYSize();
    int num_raster = poDataset->GetRasterCount();

    std::cout << "XSIZE: " << xsize << std::endl; //1303
    std::cout << "YSIZE: " << ysize << std::endl; //279
    std::cout << "NUMBER OF RASTERS: " << num_raster << std::endl;

    std::cout << "\n\n";

    
    xsize = 5;

    GDALRasterBand *rb = poDataset->GetRasterBand(2);
    float *buffer = new float[xsize * ysize];
    rb->RasterIO(GF_Read, 0, 5, ysize, xsize, buffer, ysize, xsize, GDT_Float32, 0, 0);


    for (int j = 0; j < xsize; ++j) {
        for (int k = 0; k < ysize; ++k) {
            std::cout << buffer[j * ysize + k] << " ";
        }
        std::cout << "\n\n";
    }
    delete [] buffer;

    std::cout << "\n\n";


    //std::cout << "METADATA: " << *metadata << std::endl;
    //std::cout << "METADATA: " << (metadata + 1) << std::endl;
    

    //std::cout << poDataset->GetDriver()->GetMetadataItem( GDAL_DMD_LONGNAME ) << std::endl;
    //std::cout << poDataset->GetRasterCount() << std::endl;

    
    if( poDataset  == NULL )
    {
        std::cout << "ERROR TO OPEN" << std::endl;
    }
    
    */

    //GDALClose(poDataset);
    
//} 
#include <iostream>
#include <stdio.h>

#include <string>
#include <cstring>
#include <vector>

#include "H5Cpp.h"
//#define FILE_NAME_ "CSKS2_SCS_B_PP_06_CO_RA_SF_20110906053953_20110906053959.h5"

using namespace H5;

const H5std_string FILE_NAME( "test_L1A.h5" );
//const H5std_string DATASET_NAME("Compressed_Data");
const H5std_string DATASET_NAME("S01/QLK");

const H5std_string GROUP_NAME("S01/B001");
const H5std_string BLOCK_NAME("S01");
const H5std_string ATTR_NAME("Azimuth First Time");

std::vector<std::string> GroupNames;

const int    NX_SUB = 3;	// hyperslab dimensions
const int    NY_SUB = 4;
//const int    NY = 7;
//const int    NZ = 3;
const int    RANK_OUT = 3;

const int   NX = 1303;                    // dataset dimensions
const int   NY = 279;
const int   RANK = 2;

int tmp = 333;

//g++ -o hdf5_reader hdf5_reader.cpp -I /usr/include/hdf5/serial/ -lhdf5_serial -lhdf5_cpp

void attr_op(H5::H5Location &loc, const std::string attr_name, void *operator_data) 
{
  std::cout << operator_data << std::endl;
  *((int*) operator_data) = 20;
}

herr_t group_info(hid_t group_id, const char *name, const H5L_info_t *linfo, void *opdata)
{

  try
  {
    hid_t group = H5Gopen2(group_id, name, H5P_DEFAULT);
    GroupNames.push_back(name);
    std::cout << "Name : " << name << std::endl;
    H5Gclose(group);
    return 0;
  }
   catch( FileIException error )
   {
      //error.printErrorStack();
      return -1;
   }

   // catch failure caused by the DataSet operations
   catch( DataSetIException error )
   {
      //error.printErrorStack();
      return -1;
   }

   // catch failure caused by the DataSpace operations
   catch( DataSpaceIException error )
   {
      //error.printErrorStack();
      return -1;
   }

   // catch failure caused by the DataSpace operations
   catch( DataTypeIException error )
   {
      //error.printErrorStack();
      return -1;
   }


}

int main ()
{

  //herr_t idx = H5Literate(group.getId(), H5_INDEX_NAME, H5_ITER_INC, NULL, group_info, NULL);


  //hid_t file_id = H5Fopen(FILE_NAME.c_str(), H5F_ACC_RDWR, H5P_DEFAULT);
  //hid_t group_id = H5Gopen2(file_id, BLOCK_NAME.c_str(), H5P_DEFAULT);
  //herr_t idx = H5Literate(group_id, H5_INDEX_NAME, H5_ITER_INC, NULL, group_info, NULL);
  //H5File *file_ = new H5File(FILE_NAME.c_str(), H5F_ACC_TRUNC );
  //herr_t idx = H5Literate(file_->getId(), H5_INDEX_NAME, H5_ITER_INC, NULL, group_info, NULL);

  //std::cout << "GROUP ID: " << group_id << std::endl;
  std::cout << std::endl;

  H5File file(FILE_NAME, H5F_ACC_RDONLY);
  Group group = file.openGroup(GROUP_NAME);
  void* op_d = &tmp;
  unsigned *  _idx = NULL;

  group.iterateAttrs(attr_op, _idx, op_d);

  std::cout << tmp << std::endl;

  /*
  std::cout << "GROUP ID: " << group.getId() << std::endl;
  std::cout << "GROUP OBJ NUM: " << group.getNumObjs() << std::endl;

  for( int i = 0; i < group.getNumObjs(); i++ )
  {
      //memset( pStr, 0, 128 );
      std::cout << group.getObjnameByIdx(i) << std::endl;
  }
  //herr_t idx = H5Literate(group.getId(), H5_INDEX_NAME, H5_ITER_INC, NULL, group_info, NULL);


  //H5File file(FILE_NAME, H5F_ACC_TRUNC);

  //H5File file(FILE_NAME, H5F_ACC_RDWR);
  
  DataSet dataset = file.openDataSet(DATASET_NAME);
  //H5Dopen2(file, "/dset", H5P_DEFAULT);
  //H5File file( FILE_NAME, H5F_ACC_RDONLY, FileCreatPropList::DEFAULT, FileAccPropList::DEFAULT );

  DataSpace filespace = dataset.getSpace();
  //std::cout << "FILESPASE = " << std::endl;

  int rank = filespace.getSimpleExtentNdims();
  std::cout << "RANK = " << rank << std::endl;

  size_t size = dataset.getInMemDataSize();
  std::cout << "SIZE = " << size << std::endl;


  hsize_t dims[2];    // dataset dimensions
  rank = filespace.getSimpleExtentDims( dims );

  DataSpace mspace(RANK, dims);

  int newbuffer[NX][NY]; //static array.

  dataset.read(newbuffer, PredType::NATIVE_INT, mspace, filespace);
  std::cout << "static array:" << std::endl;

  Attribute attr = group.openAttribute("Azimuth First Time");
  Attribute attr_ds = dataset.openAttribute("Quick Look Column Spacing");

  double test = 0.0;
  //H5std_string test;
  //unsigned int test = 0;

  //dataset.iterateAttrs(attr_op);
  std::cout << std::endl;
  group.iterateAttrs(attr_op);

  std::cout << std::endl;

  DataType type = attr.getDataType();

  attr.read(type, &test);

  std::cout << "GROUP ATTRIBUTE: " << test << std::endl;

  double test_ds = 0.0;

  DataType type_ds = attr_ds.getDataType();

  hid_t group_id_ = H5Gopen2(file_id, GROUP_NAME.c_str(), H5P_DEFAULT);
  hid_t attr_id = H5Aopen(group_id_, ATTR_NAME.c_str(), H5P_DEFAULT);
  hid_t attr_type = H5Aget_type(attr_id); 
  H5T_class_t attr_class = H5Tget_class(attr_type);

  
  if (attr_class == H5T_FLOAT)
  {
    std::cout << "\nDATA TYPE!!!!****\n";
  }
  
 
  DataType type_ds_ = H5Aget_type(attr_id); 

  if (type_ds_.getId() == 50331869)
  {
    std::cout << "\nDATA TYPE!!!!\n";
  }

  
  attr_ds.read(type_ds, &test_ds);

  std::cout << "DATA TYPE id: " << type_ds_.getId() << std::endl;
  std::cout << "DATASET ATTRIBUTE: " << test_ds << std::endl;

  //==========================================
  //  READ ARRAY ATTRIBUTE        
  //==========================================  

  Attribute attr_2 = group.openAttribute("RAW Bias");
  //Attribute attr_2 = group.openAttribute("RAW Gain Imbalance");

  DataType attr2_dtype = attr_2.getDataType();
  DataSpace attr2_dspace = attr_2.getSpace();

  H5std_string attr2_name = attr_2.getName();
  std::cout << "ATTR 2 NAME:" << attr2_name << std::endl;

  ssize_t attr_2_size = attr_2.getName(attr2_name);
  std::cout << "ATTR_2_SIZE:" << attr_2_size << std::endl;

  std::cout << std::endl;

  size_t attr2_size_test = attr_2.getInMemDataSize();
  attr2_size_test = attr2_size_test / 8;
  std::cout << "ATTR 2 MEM SIZE TEST: " << attr2_size_test <<std::endl;
  
  hsize_t attr2_size = attr_2.getStorageSize();
  attr2_size = attr2_size / 8;

  std::cout << "ATTR_2 SIZE: " << attr2_size << std::endl;

  std::cout << std::endl;

  double* lpnBuffer = new double[attr2_size];
  attr_2.read(attr2_dtype, lpnBuffer);

  
  for (uint i = 0; i < attr2_size; i++)
  {
    std::cout << lpnBuffer[i] << " ";
  }
  
  std::cout << std::endl;
  delete [] lpnBuffer;
  attr_2.close();
  */
  
 return 0;  // successfully terminated
}


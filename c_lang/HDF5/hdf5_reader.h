#ifndef __HDF5_READER_H__
#define __HDF5_READER_H__


#include <iostream>

#include <string>
#include <vector>
#include <map>

#include <H5Cpp.h>

class HDF5_Reader
{
    private:
        H5::H5File file;
        
            
    public:
        void test();          
        void output_vector(std::vector<std::string> vect);
        
        HDF5_Reader(std::string FILE_NAME);
        
        static void attr_op(H5::H5Location &loc, const std::string attr_name, void *operator_data);

        std::vector<std::string> get_sub_objs();
        std::vector<std::string> get_sub_objs(std::vector<std::string> sub_objs);              
        void iter_group_attrs(std::string obj_name);
        void iter_dataset_attrs(std::string obj_name);

        void sandbox();
        void parse_hdf5();

};

#endif



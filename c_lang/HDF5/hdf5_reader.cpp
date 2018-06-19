#include "hdf5_reader.h"

#include <iostream>

#include <stdio.h>


#include <string>
#include <vector>
#include <map>

#include <functional>

#include <H5Cpp.h>

//using namespace H5;

std::string atr_n;
int tmp = 10;


void HDF5_Reader::test() 
{

}

void HDF5_Reader::output_vector(std::vector<std::string> vect)
{
    for (unsigned int i = 0; i < vect.size(); i++)
    {        
        std::cout << vect[i] << " ";
    }
    std::cout << "\n";
}



//---------------------------------------------------------------------//
//                      MAIN FUNCTIONS                                 //
//---------------------------------------------------------------------//
                        



HDF5_Reader::HDF5_Reader(std::string FILE_NAME)
{
    
    H5::H5File f_tmp(FILE_NAME.c_str(), H5F_ACC_RDONLY);
    file = f_tmp;
}


void HDF5_Reader::attr_op(H5::H5Location &loc, const std::string attr_name, void *operator_data) 
{
    std::cout << attr_name << std::endl;
    //*((std::vector<std::string>*) operator_data) = 20;
    //return attr_name;
    std::cout << operator_data << std::endl;
}



std::vector<std::string> HDF5_Reader::get_sub_objs()
{
    
    std::vector<std::string> subdirs;

    std::string name;
    H5G_obj_t type;

    for (int i = 0; i < file.getNumObjs(); i++)
    {
        //std::cout << file.getObjnameByIdx(i) << " " << std::endl;
        name = file.getObjnameByIdx(i);
        subdirs.push_back(name);

        type = file.getObjTypeByIdx(i);
        //std::cout << type << std::endl;
        
        if (type == 0)
        { iter_group_attrs(name); }

        if (type == 1)
        { iter_dataset_attrs(name); }

    }

    return subdirs;
 
}


std::vector<std::string> HDF5_Reader::get_sub_objs(std::vector<std::string> sub_objs)
{
    
    std::vector<std::string> sub_objs_new;
    H5G_obj_t type;

    for (int i = 0; i < sub_objs.size(); i++)
    {  
        std::string name = "";
          
        try 
        {
            H5::Exception::dontPrint();
            H5::Group group = file.openGroup(sub_objs[i].c_str());

            if (group.getNumObjs() == 0) { return sub_objs; }
        
            //std::cout << "Number of sub objects: " << group.getNumObjs() << std::endl;
            for (int j = 0; j < group.getNumObjs(); j++)
            {
                name = sub_objs[i] + "/" + group.getObjnameByIdx(j);
                type = group.getObjTypeByIdx(j);

                sub_objs_new.push_back(name);
                
                if (type == 0)
                { iter_group_attrs(name); }

                if (type == 1)
                { iter_dataset_attrs(name); }


                //std::cout << name << std::endl;
            }
            
        
        }
        catch (H5::FileIException error ) { }

    
        //std::cout << "continue\n\n";
        std::cout << "\n\n";
    }
    return get_sub_objs(sub_objs_new);
    //return subobjs_new;
}


void HDF5_Reader::iter_group_attrs(std::string obj_name)
{
    //std::string attr_name;

    std::cout << "GROUP" << std::endl;

    try 
    {
        H5::Exception::dontPrint();
        H5::Group group = file.openGroup(obj_name.c_str());

        //attr_name = group.iterateAttrs(attr_op);
        //std::cout << attr_name << std::endl;
        std::vector<std::string> attr_name;
        attr_name.push_back("test");
        void* op_d = &attr_name;
        unsigned* idx = NULL;

        int test = 5;
        std::cout << op_d << std::endl;

        group.iterateAttrs(attr_op, idx, op_d);
        
        //group.iterateAttrs(attr_op);
        //void* check = &tmp;
        //*((int*) check) = 20;

        std::cout << tmp << std::endl;

    }
    catch (H5::FileIException error ) { }
           
}

void HDF5_Reader::iter_dataset_attrs(std::string obj_name)
{
    std::string attr_name;
    std::cout << "DATASET" << std::endl;

    try
    {
        H5::Exception::dontPrint();
        H5::DataSet dataset = file.openDataSet(obj_name.c_str());

    }
    catch (H5::FileIException error ) { }    
       
}


void HDF5_Reader::sandbox()
{
    std::string group_name = "S01/B001";
    std::string dataset_name = "S01/QLK";
    std::string group_big_name = "S01";
    
    H5::Group group_big = file.openGroup(group_big_name.c_str());
    H5::Group group = file.openGroup(group_name.c_str());
    H5::DataSet dataset = file.openDataSet(dataset_name.c_str());

    for (int i = 0; i < group_big.getNumObjs(); i++)
    {   
        std::cout << "name: " << group_big.getObjnameByIdx(i) << std::endl;
        std::cout << "type: " << group_big.getObjTypeByIdx(i) << std::endl;
         
    }
    std::cout << group.getNumAttrs() << std::endl;
    std::cout << dataset.getNumAttrs() << std::endl;

}


void HDF5_Reader::parse_hdf5()
{
    
    std::vector<std::string> sub_objs;
    

    //H5::H5File f(FILE_NAME.c_str(), H5F_ACC_RDONLY);
    
    sub_objs = get_sub_objs(); 
    //output_vector(sub_objs);
    
    sub_objs = get_sub_objs(sub_objs); 
    //output_vector(sub_objs);
           

}

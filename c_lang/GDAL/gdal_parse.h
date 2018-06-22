#ifndef __GDAL_PARSE_H__
#define __GDAL_PARSE_H__


#include <iostream>

#include <string>
#include <vector>
#include <map>


class GDAL_Parse
{
    private:
        std::string FILE_NAME;
        void iterate_pointer(char **metadata);

        void get_values(std::string metadata);
        void get_subobjs(std::string metadata);

        std::vector<std::string> split_string(const std::string &line, char delimiter); 



    public:
        //void test();
        //GDAL_Parse(std::string file_name);
        void output_vector(std::vector<std::string> vect);

        std::vector<std::string> get_datasets(const std::string FILE_NAME);       
        void output_dataset(std::string ds_name);

};

#endif



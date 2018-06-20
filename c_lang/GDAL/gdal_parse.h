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
        void parse_string(std::string metadata);


    public:
        void test();
        GDAL_Parse(std::string file_name); 
        void parse();         


};

#endif



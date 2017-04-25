
#include <iostream>
#include <string>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/ptree.hpp>

using namespace boost::property_tree;
int main(int argc, char const *argv[]) {
    ptree pt; 
    read_xml("aa.xml", pt);
    auto child = pt.get_child("Vehicle");
    for (auto iter = child.begin(); iter != child.end(); ++iter) {
        if("Image" == iter->first) {
            auto node = iter->second;
            std::cout << node.get<std::string>("ImageIndex") << std::endl;
        }   
    }   

    return 0;
}

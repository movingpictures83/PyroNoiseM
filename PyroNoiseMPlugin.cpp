#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "PyroNoiseMPlugin.h"

void PyroNoiseMPlugin::input(std::string file) {
 inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   ifile >> value;
   parameters[key] = value;
 }
}

void PyroNoiseMPlugin::run() {}

void PyroNoiseMPlugin::output(std::string file) {
 std::string outputfile = file;
 std::string myCommand = "";
myCommand += "PyroNoiseM";
myCommand += " ";
myCommand += "-din";
myCommand += " ";
myCommand += parameters["input"];
myCommand += " ";
myCommand += "-out";
myCommand += " ";
myCommand += parameters["output"];
myCommand += " ";
myCommand += "-lin";
myCommand += " ";
myCommand += parameters["listinput"];
myCommand += " -rin";
myCommand += " ";
myCommand += parameters["lookupfile"];
myCommand += " ";
myCommand += "-s";
myCommand += " ";
myCommand += parameters["s"];
myCommand += " ";
myCommand += "-c";
myCommand += " ";
myCommand += parameters["c"];
myCommand += " >& "+outputfile;
 system(myCommand.c_str());
}

PluginProxy<PyroNoiseMPlugin> PyroNoiseMPluginProxy = PluginProxy<PyroNoiseMPlugin>("PyroNoiseM", PluginManager::getInstance());

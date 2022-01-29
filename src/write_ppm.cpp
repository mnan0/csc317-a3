#include "write_ppm.h"
#include <fstream>
#include <cassert>
#include <iostream>

bool write_ppm(
  const std::string & filename,
  const std::vector<unsigned char> & data,
  const int width,
  const int height,
  const int num_channels)
{
  ////////////////////////////////////////////////////////////////////////////
  std::ofstream write_file(filename);
  //std::cout << "Now writing to .ppm: " << filename << "\n";
  if (!write_file){
    printf("failed\n");
    return false;
  }
  std::string mystring;
  int array_length = width * height * num_channels;
  // Case 1: RGB
  if (num_channels ==3){
    //std::cout << filename << " is RGB.\n";
    write_file << "P3" << std::endl;
    write_file << width << " " << height << std::endl;
    write_file << 255 << std::endl;
    

    for (int i = 0; i< array_length; i++){
      write_file << (int)data.at(i) << " ";
      if (i%3==2){
        write_file << std::endl;
      }
    }
    write_file.close();
    

    // std::ifstream read_file(filename);
    // while(getline(read_file,mystring)){
    //   std::cout << mystring << std::endl;
    // }
    // read_file.close();
  }
  
  // Case 2: Grayscale
  else{
    //std::cout << filename << " is grayscale.\n";
    write_file << "P2" << std::endl;
    write_file << width << " " << height << std::endl;
    write_file << 255 << std::endl;
    


    for (int i = 0; i< array_length; i++){
      write_file << (int)data.at(i) << " ";
      if (i%10==9){
        write_file << std::endl;
      }
    }
    write_file.close();
    // std::ifstream read_file(filename);
    // while(getline(read_file,mystring)){
    //   std::cout << mystring << std::endl;
    // }
    // read_file.close();
  }
  //std::cout << "Wrote " << filename << " to .ppm successfully" << std::endl;
  return true;
  ////////////////////////////////////////////////////////////////////////////
}

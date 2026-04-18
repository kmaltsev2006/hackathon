/*
 * @license
 * (C) PROTEI protei.ru
 */
#include <iostream>
#include <unistd.h>
#include <getopt.h>

const struct option long_options[] = {
    {"input", required_argument, nullptr, 'i'},
    {"output", required_argument, nullptr, 'o'},
    {"help", no_argument, nullptr, 'h'},
    {nullptr, 0, nullptr, 0}
};

int main(int argc, char* argv[]) {
  std::string input_filename, output_filename = "a.csv";

  int opt, opt_index = 0;

  if (argc == 1) {
    std::cout << "-i --input:   имя входного файла\n-o --output:   имя выходного файла\n";
  }else{
    while((opt = getopt_long(argc, argv, "i:o:h", long_options, &opt_index)) != -1){
      switch(opt){
        case 'i':
          input_filename = optarg;
          break;
        case 'o':
          output_filename = optarg;
          break;
        case 'h':
          std::cout << "-i --input:   имя входного файла\n-o --output:   имя выходного файла\n";
          break;
      }
    }
  }

  std::cout << "input name: " << input_filename << std::endl << "output name: " << output_filename << std::endl;

}
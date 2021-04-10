#include <iostream>
#include "HTMLReader.h"
 
int main(int argc, char **argv)
{
  HTMLReader reader(argv[1]);
  reader.ProcHTML(argv[2]);
}

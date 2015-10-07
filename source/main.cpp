#include "Shapes2D.hpp"
#include <string>


using namespace std;

main(int argc, char* argv[])
{
  Shapes2D shape;

  string filename = "../data/gorm.dat";

  //Start program
  shape.load(filename);
  shape.centered();

  shape.show();

}

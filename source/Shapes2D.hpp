
#include <iostream>
#include <string>
#include <vector>

#include "Shape2D.hpp"


class Shapes2D
{

private :

  std::vector<Shape2D> m_data;
  std::string m_fileName;

public :

  Shapes2D();

  int numberOfLandmarksByShape();
  int numberOfShape();
  void load(std::string fileName);
  void show();
  void centered();
};

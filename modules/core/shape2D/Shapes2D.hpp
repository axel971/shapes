#ifndef SHAPES2D_HPP
#define SHAPES2D_HPP

#include <iostream>
#include <string>
#include <vector>
#include <complex>

#include "Shape2D.hpp"

namespace shape
{
  class Shapes2D
  {
    
  private :
    
    std::vector<Shape2D> m_data;
    std::string m_fileName;
    
  public :
    
    Shapes2D();
    Shape2D& operator[](std::size_t i);
    
    int numberOfLandmarksByShape();
    int numberOfShape();
    void load(std::string fileName);
    void centered();
    void fullProcrustesFit(Shape2D& src, Shape2D& fit, double& theta, double& beta);
  };

}

#endif

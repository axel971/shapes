#ifndef SHAPE2D_HPP 
#define SHAPE2D_HPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include <eigen3/Eigen/Dense>

    

class Shape2D
{
 private :

  std::vector<double> m_x;
  std::vector<double> m_y;
  std::string m_fileName;

 public:

  Shape2D();

  std::vector<double> x();
  std::vector<double> y();
  double x(int i);
  double y(int i);
  void x(int, double);
  void y(int, double);
  void loadLineFile(std::string fileName);
  void loadLineFlux(std::istringstream& line);
  void normalize();
  int size();
  void mean(double& meanX, double& meanY);
  void centered();
  
};

#endif

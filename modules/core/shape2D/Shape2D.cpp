 

#include "Shape2D.hpp"

using namespace std;
using namespace Eigen;

Shape2D::Shape2D(){}

void Shape2D::loadLineFlux(istringstream& line)
{
  double tmpX, tmpY;
 
  while(line >> tmpX >> tmpY)
    {
      m_x.push_back(tmpX);
      m_y.push_back(tmpY);
    }	 

}

void Shape2D::loadLineFile(string fileName)
{
  m_fileName = fileName;
 
  ifstream file(m_fileName, ios::in);  //Open the file

  if(file) 
    {   
      //Read the line and save the x,y coordinates
      string lineString;

      if(getline(file, lineString))
	{
	  istringstream line(lineString); //Convert the string lineString into the flux line
	  loadLineFlux(line);

	}

      //Close the file
      file.close();
    }

  else
    cerr << "It's impossible to open this file !" << endl;

}

std::vector<double> Shape2D::x()
{
  return m_x;
}

std::vector<double> Shape2D::y()
{
  return m_y;
}

double Shape2D::x(int i)
{
  return m_x[i];
}
double Shape2D::y(int i)
{
  return m_y[i];
}

void Shape2D::x(int i, double value)
{
  m_x[i] = value;
}

void Shape2D::y(int i, double value)
{
  m_y[i] = value;
} 

void Shape2D::normalize()
{}

int Shape2D::size()
 {
   return m_x.size();
 }


void Shape2D::mean(double& meanX, double& meanY)
{
  meanX = 0.;
  meanY = 0.;

  for(vector<double>::iterator itX = m_x.begin(), itY = m_y.begin(); itX < m_x.end(), itY < m_y.end(); ++itX, ++itY)
    {
      meanX += (*itX);
      meanY += (*itY);
    }

  meanX /= m_x.size();
  meanY /= m_y.size();

}

void Shape2D::centered()
{
  double meanX, meanY;

  mean(meanX, meanY);

 for(vector<double>::iterator itX = m_x.begin(), itY = m_y.begin(); itX < m_x.end(), itY < m_y.end(); ++itX, ++itY)
   {
     *itX -= meanX;
     *itY -= meanY;
   }
}


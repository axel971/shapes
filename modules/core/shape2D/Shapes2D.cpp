#include "Shapes2D.hpp"


using namespace std;
using namespace Eigen;

namespace shape
{

  Shapes2D::Shapes2D()
  {}

  Shape2D& Shapes2D::operator[](std::size_t i)
  {
    return m_data[i];
  }

void Shapes2D::load(string fileName)
{
  m_fileName = fileName;

  ifstream file(fileName, ios::in);

  if(file)
    {

      //Read the current line and save the x,y coordinates
      string lineString;
      while(getline(file, lineString))
	{
	  istringstream line(lineString); //Convert lineString into a flux

	  //Save the current landmarks in a shape
	  Shape2D shape; 
	  shape.loadLineFlux(line);
	  
	  //Save this Shape in our vector array structure
	  m_data.push_back(shape);
	}
    }
  else
    {
      cerr << "The file couldn't be loaded" << endl;
    }
}


int Shapes2D::numberOfLandmarksByShape()
{
  if(m_data.size() > 0)
    return m_data[0].size();
  else
    return 0;

}
int Shapes2D::numberOfShape()
{
  return m_data.size();
}


void Shapes2D::centered()
{
  for(vector<Shape2D>::iterator it = m_data.begin(); it < m_data.end(); ++it)
    (*it).centered();
}


  void Shapes2D::fullProcrustesFit(Shape2D& src, Shape2D& fit, double& theta, double& beta)
  {
 
  //Check if the shape have the same size
    if(src.size() == fit.size())
    {
      //Convert the configurations of y and w in the complex framework
      VectorXcd fitc(fit.size()), srcc(src.size());

      for(int i = 0; i < fit.size(); ++i)
	{
	  fitc[i] = complex<double>(fit.x(i), fit.y(i));
	  srcc[i] = complex<double>(src.x(i), src.y(i));
	}
      
      //Compute Theta
      theta = arg((fitc.adjoint()*srcc)[0]);

      //Compute beta
      beta = abs((srcc.adjoint()*fitc)[0]) / real((fitc.adjoint()*fitc)[0]);
   
      //Match the two shapes
      fitc *= beta * exp(complex<double>(0, theta));

      //To Do :  Convert in real coordinates
      for(int i = 0; i < fit.size(); ++i)
	{
	  fit.x(i, fitc[i].real());
	  fit.y(i, fitc[i].imag());	  
	}

    }

 }

}//end of the namespace

#include "Shapes2D.hpp"
#include "../../visualization/shape2D/ViewShapes2D.hpp"

#include <string>


using namespace std;
using namespace shape;

int main(int argc, char* argv[])
{
  Shapes2D shape, registredShape;
  ViewShapes2D view1, view2;

  double beta, theta;

  string filename = argv[1];

  if(filename.empty() ) // Check for invalid input
    {
      cout << "Could not open the file" << endl ;
      return -1;
    }

  //Start program
  shape.load(filename);

  registredShape = shape;
  registredShape.centered();

  for(int i= 0; i < registredShape.numberOfShape(); ++i)
    registredShape.fullProcrustesFit(registredShape[0], registredShape[i], theta, beta);

  //Visualization
  view1.setShape(&shape);
  view2.setShape(&registredShape);
 
  view1.exec();
  view2.exec();

  return 0;
}

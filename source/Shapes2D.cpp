#include "Shapes2D.hpp"


using namespace std;


Shapes2D::Shapes2D()
{}

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

void Shapes2D::show()
{
  // Set up a 2D scene, add an XY chart to it
  vtkSmartPointer<vtkContextView> view = vtkSmartPointer<vtkContextView>::New();
  view->GetRenderer()->SetBackground(1.0, 1.0, 1.0);
  view->GetRenderWindow()->SetSize(400, 300);
 
  vtkSmartPointer<vtkChartXY> chart = vtkSmartPointer<vtkChartXY>::New();
  view->GetScene()->AddItem(chart);
  chart->SetShowLegend(false);
  
  
  for(int i = 0; i < numberOfShape(); ++i)
      {
	//Create a table with some points in it...
	vtkSmartPointer<vtkTable> table = vtkSmartPointer<vtkTable>::New();
  
	vtkSmartPointer<vtkFloatArray> arrX =   vtkSmartPointer<vtkFloatArray>::New();
	arrX->SetName("X Axis");
	table->AddColumn(arrX);
	
	vtkSmartPointer<vtkFloatArray> arrY =  vtkSmartPointer<vtkFloatArray>::New();
	arrY->SetName("Y Axis");
	table->AddColumn(arrY);
  
	//Test charting with a few more points...
	table->SetNumberOfRows(numberOfLandmarksByShape());
  
	for (int j = 0; j < numberOfLandmarksByShape(); ++j)
	  {
	    table->SetValue(j, 0, m_data[i].getX(j));
	    table->SetValue(j, 1, m_data[i].getY(j));
	  }
	
	//Add multiple scatter plots, setting the colors etc
	vtkPlot* points	= chart->AddPlot(vtkChart::POINTS);
	
#if VTK_MAJOR_VERSION <= 5
	points->SetInput(table, 0, 1);
#else
	points->SetInputData(table, 0, 1);
#endif
	points->SetColor(0, 0, 0, 255);

      }

    //Finally render the scene
    view->GetRenderWindow()->SetMultiSamples(0);
    view->GetInteractor()->Initialize();
    view->GetInteractor()->Start();

}

void Shapes2D::centered()
{
  for(vector<Shape2D>::iterator it = m_data.begin(); it < m_data.end(); ++it)
    (*it).centered();
}

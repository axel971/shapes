#Statistical Shape Analysis Tools
The main purpose of this project is to implement some tools from the field of statistical shape analysis.
At this moment the programm only do a rigid registration of a point cloud thank to a Procrustes distance. The data are landmarks posed on male gorilla cranes or digit 3.

The libraries that you need to install are the following : <br>
VTK <br>
EIGEN3 <br>

Here you can find the instructions to compile the project on linux : <br>

cmake -H. -Bbuild/ <br>
cd build <br>
make  <br>
cd .. <br>
cd output/bin/ <br>
./exampleProcruste ../../data/gorm.dat <br>

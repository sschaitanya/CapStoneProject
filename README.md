# UdacityCpp-FinalProject
# Implement a Set using hash based chain implementation (each bucket contains multiple elements)
##Set has following methods:
###Add: add element to the bucket and if the elements exists it will duplicate element in next bucket
###Remove: if the element is present it will remove from the set bucket 
###Contains: if the element is in present in the bucket it will return true else it returns false
###Union: union add two sets and return a resultant set. It will add only one instance of each element
###Intersection: add common elements of resultant set. It will add only one instance of each element
### Difference: It tries to find the elements present in A alone and remove the elements present in B.

#Dependencies for Running Locally
* cmake >= 3.11.3
  1. All OSes: click here for installation instructions
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  1. Linux: make is installed by default on most Linux distros
  2. Mac: install Xcode command line tools to get make
  3. Windows: Click here for installation instructions
* gcc/g++ >= 5.4
  1. Linux: gcc / g++ is installed by default on most Linux distros
  2. Mac: same deal as make - install Xcode command line tools
  3. Windows: recommend using MinGW
  
# Build Instructions

1. cmake ..
2. make
3. ./untitled14

| Criteria                                                                      | Meets Specification                                                                                                                                                   | File and LineNo |
|-------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------- |-----------------|
|  Classes encapsulate behavior.                                                | Appropriate data and functions are grouped into classes. Member data that is subject to an invariant is hidden from the user. State is accessed via member functions  |Set.h && Set.cpp|           
| The submission must compile and Run                                           | we strongly recommend cmake and make as provided in the starter repos.If you choose another build system, the code must compile on any reviewer platform.             |all cpp files   |
| The project demonstrates understanding of c++ function and control structures | A variety of control structures are used in the project.The project code is clearly organized into functions.                                                         | Set.h & Set.cpp|
| The project uses object oriented programming techniques.                      | The project code is organized into classes with class attributes to hold the data and class methods to perform tasks.                                                 | Set.h & Set.cpp|
| Classes use appropriate access specifiers for class members.                  | All class data members are explicitly specified as public, protected and private.                                                                                     | Set.h & Set.cpp|
| Templates generalize functions in the project.                                | One function is declared with the template that allows it to accept a generic parameter.                                                                              | Set.h & Set.cpp| 
      
#include <iostream>

#include<bits/stdc++.h> 
using namespace std ; 

enum Orientation {
    ANTI_CLOCKWISE = -1,
    COLINEAR = 0,
    CLOCKWISE = 1
};

struct mathVector
{
    int _x;
    int _y;
    int _z;
    
    mathVector(int x, int y, int z)
    {
        _x = x;
        _y = y;
        _z = z;
    }
};

// Find the normal of a surface composed of 3 points in 3D world
void getNormal(mathVector v1, mathVector v2, mathVector v3, mathVector& normal)
{
    // using v1,v2,v3 get the normal vector , perpendicular to this plane
    // normal = (v2 - v1) * (v3 - v1);  [Cross Product]
    
    // Distance D21 between V2 and V1
    mathVector D21(v2._x - v1._x, v2._y - v1._y, v2._z - v1._z); 

    // Distance D31 between V3 and V1
    mathVector D31(v3._x - v1._x, v3._y - v1._y, v3._z - v1._z); 
    
    // Normal of the vector = Cross product of D21 and D31
    mathVector n(D21._y * D31._z - D31._y * D21._z,
                 D31._x * D21._z - D21._x * D31._z,
                 D21._x * D31._y - D21._y * D31._x);

    normal._x = n._x;
    normal._y = n._y;
    normal._z = n._z;
}


// Scalar or DOT product of two vectors
int getScalarProduct(mathVector v1, mathVector v2)
{
    // Scalar product of V1 and V2
    return (v2._x * v1._x + v2._y * v1._y + v2._z * v1._z) ;
}

// Check the orientation of a 3D surface
Orientation getOrientationOf3DPoints(mathVector v1, mathVector v2, mathVector v3)
{
    Orientation retVal;
    mathVector normal(0,0,0);
    getNormal(v1, v2, v3, normal);
    int scalarValue = getScalarProduct(v1, normal);
    
    if(scalarValue < 0) {
        retVal = Orientation::CLOCKWISE;
    } else if(scalarValue > 0) {
        retVal = Orientation::ANTI_CLOCKWISE;
    } else {
        retVal = Orientation::COLINEAR;
    }
    return retVal;
}

// Function to check if 4 points 
// in a 3-D plane are Coplanar 
// Function to find equation of plane. 
bool isCoPlanar(mathVector v1, mathVector v2, mathVector v3, mathVector newVertex) 
	{ 
	    mathVector n(0,0,0);
        getNormal(v1, v2, v3, n);
	    
	    // Distance between V1 and normal vector
	    int d = -1 * getScalarProduct(v1, n);
	
	    // checking if the newVertex satisfies plane equation 
	    if(n._x * newVertex._x + n._y * newVertex._y + n._z * newVertex._z + d == 0)
	    {
	        return true;
	    }
    	else
    	{
    	    // TODO : Suggest possible values for making this a Coplanar surface
    	    int x = newVertex._x;
    	    int y = newVertex._y;
    	    int z = newVertex._z;
    	    
    		
    		int newZ = (0 - d - (n._x *x) - (n._y * y))/n._z;
    		if(z != newZ)
    		{
    		    cout << "Make z : " << newZ << endl;
    		    z = newZ;
    		    
    		    int newY = (0 - d - (n._x *x) - (n._z * z))/n._y;
        		if(y != newY)
        		{
        		    cout << "Make y : " << newY << endl; 
        		    y = newY;
        		}
        		
        		int newX = (0 - d - (n._z *z) - (n._y * y))/n._x;
        		if(x != newX)
        		{
        		    cout << "Make x : " << newX << endl; 
        		}
    		}
    		return false;
    	}	
	} 
	
// Driver Code 
int main() 
{ 
    mathVector c1(2,0,-5), c2(-1,4,-3), c3(-3,8,-5), newVertex(2,3,-2);//newVertex(1,0,-1); //newVertex(1,2,-6);
    mathVector a1(0, -10, 0);
    mathVector a2(40, -10, 0);
    mathVector a3(40, 10, 0);
    mathVector a4(0, 10, 0);
    mathVector a5(0, -10, 10);
    mathVector a6(40, -10, 10);
    mathVector a7(40, 10, 10);
    mathVector a8(0, 10, 10);
     
    if(isCoPlanar(c1, c2, c3, newVertex))
        cout << "Coplanar" << endl;
    else
        cout << "Not Coplanar " << endl; 
    
    Orientation val = getOrientationOf3DPoints(a4,a8,a7);
    switch(val) {
      case Orientation::CLOCKWISE :
        cout << "Clockwise" << endl;
      break;
      case Orientation::ANTI_CLOCKWISE :
        cout << "Anti-Clockwise" << endl;
      break;
      case Orientation::COLINEAR :
        cout << "Co-Linear" << endl;
      break;
      default:
        cout << "Erroneous Value" << endl;
        break;
    };  
    
    

        
    return 0; 


}

#include<iostream>

using namespace std;


class Point {
    
    private:
        int x;
        int y;

    public:

        Point(){}

        Point(int x, int y) {
            this->x=x;
            this->y=y;

        }
        
        int get_x() {
            return x;
        }

        int get_y() {
            return y;
        }

        void set_x(int x) {
            this->x=x;
        }

        void set_y(int y) {
            this->y=y;
        }


};

bool is_counterclockwise(Point first_point, Point second_point, Point third_point);
void convexHull(Point points[], int length);



int main() {
    int n,temp=0;
    
    cout << "Enter the number of points you want to enter: "<< endl;
    cin >> n;
    
    if(n<3) {
        cout<< "Invalid Input" <<endl;
    }

    Point points[n];

    cout << "Enter the points: "<<endl;
    while(temp!=n) {
        int temp_x=0,temp_y=0;
        cout << "Enter the x coordinate of point " << temp+1 << endl;
        cin >> temp_x;
        points[temp].set_x(temp_x);
        
        cout << "Enter the y coordinate of point " << temp+1 << endl;
        cin >> temp_y;
        points[temp].set_y(temp_y);
    
        temp++;
    }
   
    convexHull(points,n);    
}

void convexHull(Point points[], int length) {
    int left_most_point=0, first_point=0, second_point=0, i=0;

    Point pointsResult[length];
  
    for(i=0 ; i<length; i++) {
        if (points[i].get_x() < points[left_most_point].get_x()) {
            left_most_point = i; 
        }
    }
  
    int temp=0;
    
    first_point = left_most_point;
    do { 
        pointsResult[temp]=points[first_point];
        
        second_point = ((first_point+1)%length); 
        
        for(i=0; i<length; i++) 
        {   
            if (!is_counterclockwise(points[first_point], points[i], points[second_point])&&i!=first_point&&i!=second_point) {
                second_point = i; 
            }
        } 

        first_point = second_point;

        temp++; 
  
    }  while(first_point != left_most_point);
  
    cout << "\n\nConvex Hull Set: " << endl << "{\n";
    for(i=0; i<temp; i++)  {
        cout << "(" << pointsResult[i].get_x() << ", "<< pointsResult[i].get_y() << ")" << endl;
    } 
    cout << "}" <<endl;
} 

bool is_counterclockwise(Point first_point, Point second_point, Point third_point)
{ 
    int result = (second_point.get_y() - first_point.get_y()) * (third_point.get_x() - second_point.get_x()) - (second_point.get_x() - first_point.get_x()) * (third_point.get_y() - second_point.get_y()); 
  
    if (result > 0) {
        return true;
    }
    else {
        return false;
    } 
} 
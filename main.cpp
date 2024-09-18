//Chaitali Patil
//301877356

#include <string.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>  //including OpenGL utility Toolkit(GLUT) library in OpenGL source file
#endif

#include <stdlib.h>
/* GLUT callback Handlers */
float a,b,c,d,e,f,x,y,x0,y0;     //declaring variables for transformation and coordinates
int i=0;   //declaring a random integer variable used for branching

//Function to handle window resizing
void resize(int width, int height)
{
    //Adjusting the viewport to maintain a square aspect ratio
    if(width<=height)
        //viewport will be centered vertically by adding black bars on the top and bottom
        glViewport(0,(GLsizei) (height-width)/2,(GLsizei) width,(GLsizei) width);

    else
        //viewport will be centered horizontally by adding black bars on the sides
        glViewport((GLsizei) (width-height)/2 ,0 ,(GLsizei) height,(GLsizei) height);
}

//initialization function for setting up the orthographic projection
void init()
{
 glMatrixMode(GL_PROJECTION);  //setting the project matrix
 glLoadIdentity();     //loading the identity matrix (resetting transformation)

 //glOrtho(left,right,bottom,top,zNear,zFar)  --->  // adjusted for suitable viewport
 //glOrtho(-2.5,2.75,10.5,0, -1.0, 1.0);
 glOrtho(-2.5,2.75,0,10.5, -1.0, 1.0);

 x0=y0=0.5;   //initializing the starting points for x0 and y0
}

//function to display the fractal
void display(void)
{
  glClear (GL_COLOR_BUFFER_BIT);        // clear display screen
  // your code here
  for(int j=0;j<100000;j++)    //for loop to generate and plot random points for fractal
  {
        i = rand()%100;   //Generating a random number from 0 to 99
        if(i<1){
            //transformation for 1% of the time
            a = 0,b=0,c=0,d=0.16,e=0,f=0;   //initializing variables for transformation
            //transformation equations
            x=a*x0+c*y0+e;
            y=b*x0+d*y0+f;
        }
        else if(i<86){
            //transformation for 85% of the time
            a= 0.85, b = -0.04, c =0.04, d =0.85, e =0, f=1.6;   //initializing variables for transformation
            //transformation equations
            x=a*x0+c*y0+e;
            y=b*x0+d*y0+f;
        }
        else if(i<93){
            //transformation for 7% of the time
            a= 0.2, b =0.23, c =-0.26, d =0.22, e =0, f=1.6;    //initializing variables for transformation
            //transformation equations
            x=a*x0+c*y0+e;
            y=b*x0+d*y0+f;
        }
        else{
            //transformation for other 7% of the time
            a= -0.15, b =0.26, c =0.28, d =0.24, e =0, f=0.44;   //initializing variables for transformation
            //transformation equations
            x=a*x0+c*y0+e;
            y=b*x0+d*y0+f;
        }
        //draw the point with calculated (x,y) coordinates
        glBegin(GL_POINTS);
        glColor3f(0.0,1.0,0.0);  //setting color as green for the points of the barnsley's fern ---> glColor3f(R,G,B)
        //Trying different colors for barnsley's fern
        //glColor3f(0.0,0.0,1.0);  //setting color to blue
        //glColor3f(1.0,0.0,0.0);  //setting color to red
        //glColor3f(0.0,1.0,1.0);  //setting color to sky blue

        glVertex3f(x,y,0);  //plot the point (x,y)
        glEnd();
        x0=x;  //Update x0 value with new x value
        y0=y;  //Update y0 value with new y value
  }
  glFlush ();                           // clear buffer
}

//function to handle keyboard input
void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :              // esc key to exit
        case 'q':   //Exit the program when 'q' is pressed
            exit(0);
            break;
    }

    glutPostRedisplay();   //requesting a redisplay after key press
}


/* Program entry point */

int main(int argc, char *argv[])
{
   glutInit(&argc, argv);    //Initializing GLUT
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);  //setting display mode(single buffer,RGB)
   glutInitWindowSize (600, 600);                //window screen
   glutInitWindowPosition (100, 100);            //window position
   glutCreateWindow ("Program1");                //program title
   init();                                //Calling the initialization function
   glutDisplayFunc(display);                     //callback function for display
   glutReshapeFunc(resize);                      //callback for reshape
   glutKeyboardFunc(key);                        //callback function for keyboard
   glutMainLoop();                               //entering the GLUT event-processing loop

    return EXIT_SUCCESS;
}

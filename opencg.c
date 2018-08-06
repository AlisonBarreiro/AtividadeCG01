#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <sys/time.h>

void algoritmoBasicEquReta( double xA, double xB, double yA, double yB){

double m = (yA - yB)/(xA - xB);
double y,x;
    for(x = xA; x <= xB; x++){
        y= (m*(x-xB))+ yB;
        glVertex2d(x,y);
    }

}

void lineDDA (int xa, int xb, int ya, int yb){

	    int dx = xb-xa, dy = yb-ya, passos,k;
	    float somax,somay, x=xa,y=ya;
	    if(fabs(dx)>fabs(dy)){
		passos = fabs(dx);
	    }else{
	    	passos = fabs(dy);
	     }
	     	somax=(float) dx/(float) passos;
	     	somay=(float) dy/(float) passos;
	     	x=xa ;
			 	y=ya;
	    	glVertex2d(x,y);

	     for(k=0; k<passos; k++){
	        x+=somax;
	        y+=somay;

	        glVertex2d(x,y);
	     }
}

void Bresenham(int x1, int x2, int y1, int y2){

    int dx,dy,x,y,xfinal,p,const1,const2;

    dx = abs(x1 - x2); dy=abs(y1-y2);
    p=2*dy-dx;
    const1=2*dy;  const2=2*(dy-dx);

    if(x1>x2){
        x=x2; y=y2; xfinal=x1;

    }else{
        x=x1;  y=y1; xfinal=x2;
    }
        glVertex2d(x,y);

    while(x<xfinal){
        x++;
        if(p<0){
            p+=const1;
        }else{
            y++;
            p+=const2;
        }
        glVertex2d(x,y);

    }
}

void display(){
	glClearColor(1.0, 1.0 , 1.0, 1.0); //Cor de limpeza
	glClear(GL_COLOR_BUFFER_BIT);//Limpa o conteúdo da janela
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-150, 150, -150, 150);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glColor3d(0,0,0); //Define a cor do desenho

	glBegin(GL_LINES);
		glColor3d(0,0,0);
		glVertex2d(0, 0);
		glVertex2d(0, 80);
	glEnd();

	glBegin(GL_LINES);
		glColor3d(0,0,0);
		glVertex2d(0, 0);
		glVertex2d(80, 0);
	glEnd();

	int j;
    	struct timeval inicio, final;
    	double tmili;
    	gettimeofday(&inicio, NULL);
    	for (j = 0; j < 1000000; j ++){
			glBegin(GL_POINTS);
			glColor3d(0,0,0);
			//algoritmoBasicEquReta(0, 80, 0, 80);
			//lineDDA(0, 80, 0, 80);
			//Bresenham(0, 80, 0, 80);
		glEnd();
	}
    	gettimeofday(&final, NULL);
    	tmili = (double) (1000 * (final.tv_sec - inicio.tv_sec) + (final.tv_usec - inicio.tv_usec) / 1000) / 1000;
    	printf("tempo decorrido: %f\n", tmili);
	glFlush();
}


int main(int argc, char **argv){

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 50); 
	glutInitWindowSize(700, 700);
	glutCreateWindow("RUN"); 
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}







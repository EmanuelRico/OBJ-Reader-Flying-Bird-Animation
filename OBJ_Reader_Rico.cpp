#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <armadillo>
#include <GLFW/glfw3.h>
#include <GL/glu.h>

#include "include/Object.hpp"
#include "include/Trayectory.hpp"
#include "include/Vertex.hpp"
#include "include/Transf.hpp"
#include "include/Colibri.hpp"
#include "include/Tree.hpp"
#include "include/Rock.hpp"
#include "include/Grass.hpp"

//Hecho por Emanuel Rico Martínez
void Presentacion();

using namespace std;

int main(){

    double BezierValues;
    double vel;
    Presentacion();

    do{
        cout << "Ingresa los valores de los puntos de control de la curva de Bezier: " << endl;
        cout << "Valores recomendados: (4.5 - 10.0)" << endl;
        cin >> BezierValues;
        cout << "Ingresa el valor de la velocidad(dt) de la curva de Bezier: " << endl;
        cout << "El valor es a tu gusto, en cada computadora puede verse diferente según la potencia" << endl;
        cout << "Valores recomendados: (0.005 - 0.1)" << endl;
        cin >> vel;
    }while((BezierValues <= 4.0 || BezierValues >= 10.0) && (vel <= 0.005 || vel >= 5.0));
    
    GLFWwindow* window;

    if( !glfwInit() )
    {
        fprintf( stderr, "Fallo al inicializar GLFW\n" );
        getchar();
        return -1;
    }

    window = glfwCreateWindow(1024, 768, "OBJ_Reader_Rico", NULL, NULL);
    if( window == NULL ) {
        fprintf( stderr, "Fallo al abrir la ventana de GLFW.\n" );
        getchar();
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    double Ia (0.6);

    Colibri hummingbird("obj/Colibri2.obj", Ia);
    hummingbird.color = {0.0, 0.0, 1.0};
    hummingbird.ka = 0.3;
    hummingbird.kd = 0.9;

    Tree tree1("obj/Tree1.obj", Ia);
    tree1.color = {0.0, 0.1, 0.0};
    tree1.ka = 0.3;
    tree1.kd = 0.9;

    Tree tree2("obj/Tree2.obj", Ia);
    tree2.color = {0.0, 0.1, 0.0};
    tree2.ka = 0.3;
    tree2.kd = 0.9;

    Tree tree3("obj/Tree3.obj", Ia);
    tree3.color = {0.0, 0.1, 0.0};
    tree3.ka = 0.3;
    tree3.kd = 0.9;

    Tree tree4("obj/Tree4.obj", Ia);
    tree4.color = {0.0, 0.1, 0.0};
    tree4.ka = 0.3;
    tree4.kd = 0.9;

    Tree tree5("obj/Tree5.obj", Ia);
    tree5.color = {0.0, 0.1, 0.0};
    tree5.ka = 0.3;
    tree5.kd = 0.9;

    Tree tree6("obj/Tree5.obj", Ia);
    tree6.color = {0.0, 0.1, 0.0};
    tree6.ka = 0.3;
    tree6.kd = 0.9;

    Rock rock1("obj/Rock1.obj", Ia);
    rock1.color = {0.4, 0.4, 0.4};
    rock1.ka = 0.3;
    rock1.kd = 0.9;

    Rock rock2("obj/Rock2.obj", Ia);
    rock2.color = {0.5, 0.5, 0.5};
    rock2.ka = 0.3;
    rock2.kd = 0.9;

    Rock rock3("obj/Rock3.obj", Ia);
    rock3.color = {0.2, 0.2, 0.2};
    rock3.ka = 0.3;
    rock3.kd = 0.9;

    Rock rock4("obj/Rock4.obj", Ia);
    rock4.color = {0.1, 0.1, 0.1};
    rock4.ka = 0.3;
    rock4.kd = 0.9;

    Grass grass1("obj/Grass1.obj", Ia);
    grass1.color = {0.0, 1.0, 0.0};
    grass1.ka = 0.3;
    grass1.kd = 0.9;

    Grass grass2("obj/Grass2.obj", Ia);
    grass2.color = {0.0, 0.9, 0.0};
    grass2.ka = 0.3;
    grass2.kd = 0.9;

    Grass grass3("obj/Grass3.obj", Ia);
    grass3.color = {0.0, 0.8, 0.0};
    grass3.ka = 0.3;
    grass3.kd = 0.9;

    Grass grass4("obj/Grass4.obj", Ia);
    grass4.color = {0.0, 0.7, 0.0};
    grass4.ka = 0.3;
    grass4.kd = 0.9;

    Transf tr;
    Trayectory ty;

    //Descomentar si se quiere usar Trayectorias Lineales
    /*Vertex vi = Vertex(0.0, 0.0, -6.0);
    Vertex vf = Vertex(0.0, 0.0, 6.0);
    vector<Vertex> line = ty.lineal(vi, vf, 0.005);
    int num = line.size()-1;
    int line_index = 0;*/

    Vertex vi2 = Vertex(0.0, 0.0, -1.0);
    Vertex vf2 = Vertex(0.0, 0.0, 6.0);
    vector<Vertex> curve = ty.bezier(vi2, vf2, vel, BezierValues);
    int num2 = curve.size()-1;
    int curve_index = 0;

    /*for(Vertex v : curve){
        cout << v.get_X() << " " << v.get_Y() << " " << v.get_Z() << " " << endl;
    }*/

    double ang_hummingbird = 0.0;
    glClearColor(0.4f, 0.1f, 0.1f, 0.0f);

    arma::drowvec eye1 = {0.0, 10.0, 0.0};
    arma::drowvec camera1 = {1.0, 0.0, 1.2};

    arma::drowvec eye2 = {0.0, 0.0, 10.0};
    arma::drowvec camera2 = {0.0, 0.0, 0.0};

    arma::drowvec eye3 = {0.0, 0.0, 0.0};
    arma::drowvec camera3 = {0.0, 0.0, 0.0};

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    int width, height;
    glfwGetFramebufferSize(window, &width, &height);

    double ar = width / height;

    //Paralellal Projection
    glViewport(0, 0, width, height);
    //glOrtho(-2, 2, -2.0, 2.0, 2, 15.0);
    glOrtho(-ar, ar, -1.0, 3.0, -30.0, 30.0);
    //Perspective Projection
    //glFrustum(-ar, ar, -1.0, 1.0, -20.0, 20.0);
    bool auxRotate = false;

    do{
        /*Vertex vl = line[line_index];
        if(line_index < num){
            line_index++;
        }*/

        Vertex vc = curve[curve_index];
        if(curve_index < num2){
            curve_index++;
        }
        else if(curve_index = num2){
            curve_index = 0;
        }

        hummingbird.set_transf(tr.S(0.30, 0.30, 0.30) * tr.T(vc.get_X(), vc.get_Y(), vc.get_Z()) * tr.Rz(ang_hummingbird));
        tree1.set_transf(tr.S(0.30, 0.30, 0.30));
        tree2.set_transf(tr.S(0.30, 0.30, 0.30));
        tree3.set_transf(tr.S(0.30, 0.30, 0.30));
        tree4.set_transf(tr.S(0.30, 0.30, 0.30));
        tree5.set_transf(tr.S(0.30, 0.30, 0.30));
        tree6.set_transf(tr.S(0.30, 0.30, 0.30));
        rock1.set_transf(tr.S(0.30, 0.30, 0.30));
        rock2.set_transf(tr.S(0.30, 0.30, 0.30));
        rock3.set_transf(tr.S(0.30, 0.30, 0.30));
        rock4.set_transf(tr.S(0.30, 0.30, 0.30));
        grass1.set_transf(tr.S(0.30, 0.30, 0.30));
        grass2.set_transf(tr.S(0.30, 0.30, 0.30));
        grass3.set_transf(tr.S(0.30, 0.30, 0.30));
        grass4.set_transf(tr.S(0.30, 0.30, 0.30));

        glClear( GL_COLOR_BUFFER_BIT );
        glClear( GL_DEPTH_BUFFER_BIT );

        if(glfwGetKey(window, GLFW_KEY_1 )){
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            gluLookAt(eye1[0], eye1[1], eye1[2], camera1[0], camera1[1], camera1[2], -10.0, 0.0, 0.0);
        }

        if(glfwGetKey(window, GLFW_KEY_2 )){
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            gluLookAt(eye2[0], eye2[1], eye2[2], camera2[0], camera2[1], camera2[2], 0.0, 1.0, 0.0);
        }
        
        double Ip = 0.9;
        arma::drowvec light_pos = {0.0, 5.0, 0.0};

        //Hummingbird
        hummingbird.print_Colibri(Ip, light_pos);

        //Tree1
        tree1.print_Tree(Ip, light_pos);

        //Tree2
        tree2.print_Tree(Ip, light_pos);

        //Tree3
        tree3.print_Tree(Ip, light_pos);

        //Tree4
        tree4.print_Tree(Ip, light_pos);

        //Tree5
        tree5.print_Tree(Ip, light_pos);

        //Tree6
        tree6.print_Tree(Ip, light_pos);

        //Rock1
        rock1.print_Rock(Ip, light_pos);

        //Rock1
        rock2.print_Rock(Ip, light_pos);

        //Rock1
        rock3.print_Rock(Ip, light_pos);

        //Rock1
        rock4.print_Rock(Ip, light_pos);

        //Grass1
        grass1.print_Grass(Ip, light_pos);

        //Grass2
        grass2.print_Grass(Ip, light_pos);

        //Grass3
        grass3.print_Grass(Ip, light_pos);

        //Grass4
        grass4.print_Grass(Ip, light_pos);

        glfwSwapBuffers(window);
        glfwPollEvents();

        if(ang_hummingbird <= 10 && auxRotate == false){
            hummingbird.rotate(&ang_hummingbird, 1.0);
        }
        else{
            auxRotate = true;
            if(ang_hummingbird >= -10 && auxRotate == true){
                hummingbird.rotate(&ang_hummingbird, -1.0);
            }
            else{
                auxRotate = false;
            }
        }

    } while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS && glfwWindowShouldClose(window) == 0 );

    glfwTerminate();

    cout << "Hecho por Emanuel Rico Martinez "<< endl;
    return 0;
}

void Presentacion(){

    cout << " \n";
    cout << "\t*******************************************" << endl;
    cout << "\t*******                             *******" << endl;
    cout << "\t*******   Este Proyecto esta hecho  *******" << endl;
    cout << "\t*******     por Emanuel Rico Mtz    *******" << endl;
    cout << "\t*******     de la carrera de ISI    *******" << endl;
    cout << "\t*******   encargado por la materia  *******" << endl;
    cout << "\t******* GRAFICACION POR COMPUTADORA *******" << endl;
    cout << "\t*******    a cargo del Ing. Omar    *******" << endl;
    cout << "\t*******     Rodriguez Gonzalez.     *******" << endl;
    cout << "\t*******                             *******" << endl;
    cout << "\t*******   Proyecto Colibri Volando  *******" << endl;
    cout << "\t*******                             *******" << endl;
    cout << "\t*******************************************" << endl;
    cout << endl;
}
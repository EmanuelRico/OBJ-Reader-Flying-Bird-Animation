#include "Grass.hpp"  
#include "GLFW/glfw3.h"
#include "GL/glu.h"
	
Grass::Grass(string obj_file, double Ia) : Object(obj_file){
	
}

void Grass::set_transf(arma::dmat tr){
    this->transf = tr;
}

arma::dmat Grass::get_transf(){
    return this->transf;
}

void Grass::print_Grass(double Ip, arma::drowvec light_pos){
    glBegin(GL_TRIANGLES);
        arma::drowvec color = this->color;
        //Ambiental Light
        //double I = this->ka;
        
            for(Face f : this->faces){
                f.calculate_normal(this->verts);
                arma::drowvec normal = f.get_Normal();
                //Diffuse Reflection
                //double I = Ip * this->kd * max(arma::dot(arma::normalise(normal), arma::normalise(light_pos)), 0.0);

                //Ambiental Light + Diffuse Refelction
                double I =this->ka + (Ip * this->kd * max(arma::dot(arma::normalise(normal), arma::normalise(light_pos)), 0.0));
                arma::drowvec intensity = color * I;
                glColor3d(intensity[0], intensity[1], intensity[2]);
                for(int i : f.get_v()){
                    Vertex v = this->verts[i-1];
                    arma::dcolvec v_div = this->transf * v.homg();
                    v_div = v_div / v_div.at(3, 0);

                    glVertex3d(v_div.at(0, 0), v_div.at(1, 0), v_div.at(2, 0));
                }
            }
    glEnd();
}
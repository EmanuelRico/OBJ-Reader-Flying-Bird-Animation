#ifndef GRASS_H
#define GRASS_H
#pragma once

#include <armadillo>
#include "Object.hpp"

class Grass : public Object 
{
	private:
		arma::dmat transf;
	public:
		arma::drowvec color;
		double ka;
		double kd;
		double Ia;
		Grass(string obj_file, double Ia);
		void set_transf(arma::dmat tr);
		arma::dmat get_transf();
		void print_Grass(double Ip, arma::drowvec light_pos);
};
#endif
#ifndef COLIBRI_H
#define COLIBRI_H
#pragma once

#include <armadillo>
#include "Object.hpp"

class Colibri : public Object 
{
	private:
		arma::dmat transf;
	public:
		arma::drowvec color;
		double ka;
		double kd;
		double Ia;
		Colibri(string obj_file, double Ia);
		void set_transf(arma::dmat tr);
		arma::dmat get_transf();
		void print_Colibri(double Ip, arma::drowvec light_pos);
		void rotate(double *ang, double dang);
};
#endif
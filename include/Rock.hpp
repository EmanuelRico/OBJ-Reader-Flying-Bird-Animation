#ifndef ROCK_H
#define ROCK_H
#pragma once

#include <armadillo>
#include "Object.hpp"

class Rock : public Object 
{
	private:
		arma::dmat transf;
	public:
		arma::drowvec color;
		double ka;
		double kd;
		double Ia;
		Rock(string obj_file, double Ia);
		void set_transf(arma::dmat tr);
		arma::dmat get_transf();
		void print_Rock(double Ip, arma::drowvec light_pos);
};
#endif
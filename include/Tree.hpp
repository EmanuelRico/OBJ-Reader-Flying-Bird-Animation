#ifndef TREE_H
#define TREE_H
#pragma once

#include <armadillo>
#include "Object.hpp"

class Tree : public Object 
{
	private:
		arma::dmat transf;
	public:
		arma::drowvec color;
		double ka;
		double kd;
		double Ia;
		Tree(string obj_file, double Ia);
		void set_transf(arma::dmat tr);
		arma::dmat get_transf();
		void print_Tree(double Ip, arma::drowvec light_pos);
};
#endif
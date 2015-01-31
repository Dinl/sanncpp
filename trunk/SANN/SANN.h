// SANN.cpp: define el punto de entrada de la aplicación de consola.
//

//#ifndef __SANN_H
//#define __SANN_H

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <time.h> 

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/nonfree/nonfree.hpp>

class SANN{
public:

	virtual void train(cv::Mat Descriptors);
	virtual void Match(cv::Mat &Descriptors1, cv::Mat &Descriptors2, std::vector<cv::DMatch> &Matches);

	SANN(){
		muestrasEntrenamiento = 0;
		muestrasClasificacion = 0;
		caracteristicas = 0;
	}
	virtual ~SANN();

private:
	cv::Mat Descriptores1;
	cv::Mat Descriptores2;
	cv::Mat Material;
	cv::Mat Sumas;
	cv::Mat Medias;
	cv::Mat Desviaciones;
	int muestrasEntrenamiento, muestrasClasificacion;
	int caracteristicas;

	virtual float distance(int N, int M);
	virtual void sortByCol(cv::Mat &src, cv::Mat &dst, int col);
	virtual void randomDistribution(int N, int M);
	virtual void proposeRandomPair(float coeff);
	virtual void toString();
	
};

//#endif
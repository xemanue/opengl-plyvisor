#ifndef SPHERE_H
#define SPHERE_H

#include "rev_object3d.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _sphere:public _rev_object
{
public:
	_sphere(float Size = 1.0, unsigned int n_pts = 8);
};

#endif // SPHERE_H

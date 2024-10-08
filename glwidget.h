/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <GL/gl.h>
#include <QOpenGLWidget>
#include <QKeyEvent>
#include <iostream>
#include "axis.h"
#include "tetrahedron.h"
#include "cube.h"
#include "cone.h"
#include "cilinder.h"
#include "sphere.h"
#include "ply_object3d.h"
#include "grua.h"


namespace _gl_widget_ne
{
const float X_MIN = -.1;
	const float X_MAX = .1;
	const float Y_MIN = -.1;
	const float Y_MAX = .1;
	const float FRONT_PLANE_PERSPECTIVE = (X_MAX - X_MIN)/2;
	const float BACK_PLANE_PERSPECTIVE = 1000;
	const float DEFAULT_DISTANCE = 2;
	const float ANGLE_STEP = 1;

	typedef enum {OBJECT_TETRAHEDRON, OBJECT_CUBE, OBJECT_CONE, OBJECT_CILINDER, OBJECT_SPHERE, OBJECT_PLY, OBJECT_CUSTOM} _object;
}

class _window;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _gl_widget : public QOpenGLWidget
{
Q_OBJECT
public:
	_gl_widget(_window *Window1);

	void clear_window();
	void change_projection();
	void change_observer();

	void draw_axis();
	void draw_objects();

	void toggle_point_mode(int state);
	void toggle_line_mode(int state);
	void toggle_fill_mode(int state);
	void toggle_chess_mode(int state);

	void change_object(int index);
	void change_object_to_ply(QString archivo);

	void unload_ply();

protected:
	void resizeGL(int Width1, int Height1) Q_DECL_OVERRIDE;
	void paintGL() Q_DECL_OVERRIDE;
	void initializeGL() Q_DECL_OVERRIDE;
	void keyPressEvent(QKeyEvent *Keyevent) Q_DECL_OVERRIDE;

private:
	_window *Window;

	int n_rev = 9;

	_axis Axis;
	_tetrahedron Tetrahedron;
	_cube Cube;
	_cone Cone;
	_cilinder Cilinder;
	_sphere Sphere;
	_ply_object Ply;
	_grua Custom;

	bool file_loaded = false;

	_gl_widget_ne::_object Object;

	bool Draw_point = false;
	bool Draw_line = false;
	bool Draw_fill = false;
	bool Draw_chess = false;

	float Observer_angle_x;
	float Observer_angle_y;
	float Observer_distance;
};

#endif

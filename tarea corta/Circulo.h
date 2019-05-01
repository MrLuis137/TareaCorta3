#pragma once
class DCirculo : public Fl_Widget {
public:
	DCirculo(double X, double Y, double W, double H, const char*L = 0) : Fl_Widget(X, Y, W, H, L) {
	}
	void draw() {
		fl_color(FL_BLACK);
		double x1 = x(), y1 = y(), r1 = w();
		fl_circle(x1, y1, r1);
	}
};
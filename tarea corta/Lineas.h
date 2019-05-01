#pragma once
class DLineas : public Fl_Widget {
public:
	DLineas(int X, int Y, int W, int H, const char*L = 0) : Fl_Widget(X, Y, W, H, L) {
	}
	void draw() {
		fl_color(FL_BLACK);
		int x1 = x(), y1 = y();
		int x2 = w(), y2 = h();
		fl_line(x1, y1, x2, y2);
	}
};
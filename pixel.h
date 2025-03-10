#ifndef PIXEL_H
#define PIXEL_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

typedef struct _pixel {
	float r;
	float g;
	float b;
	int x;
	int y;
} Pixel;

void read_pixels(const std::string &filename, std::vector<Pixel> &pixel_list);
void average_colors(const std::vector<Pixel> &pixel_list);
void flip_vertically(std::vector<Pixel> &pixel_list);
void save_pixels(const std::string &filename, const std::vector<Pixel> &pixel_list);

#endif

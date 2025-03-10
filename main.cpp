#include "pixel.h"

void read_pixels(const std::string &filename, std::vector<Pixel> &pixel_list){
	std::ifstream file(filename.c_str());
	if (!file) {
		std::cerr << "error opening file: " << filename << std::endl;
		return;
	}
	std::string line;
	while (std::getline(file, line)){
		std::stringstream ss(line);
		std::string value;
		Pixel pixel;
	
		std::getline(ss, value, ','); pixel.x = std::stoi(value);
		std::getline(ss, value, ','); pixel.y = std::stoi(value);
		std::getline(ss, value, ','); pixel.r = std::stof(value);
		std::getline(ss, value, ','); pixel.g = std::stof(value);
		std::getline(ss, value, ','); pixel.b = std::stof(value);
		
		pixel_list.push_back(pixel);
	}
	file.close();
}

void average_colors(const std::vector<Pixel> &pixel_list){
	float total_r = 0, total_g = 0, total_b = 0;
	int count = pixel_list.size();
	for (const auto &pixel : pixel_list){
		total_r += pixel.r;	
		total_g += pixel.g;
		total_b += pixel.b;
	}
	std::cout<< "average colors:\n";
	std::cout << "r: " << total_r / count << "\n";
	std::cout << "g: " << total_g / count << "\n";
	std::cout << "b: " << total_b / count << "\n";
}

void flip_vertically(std::vector<Pixel> &pixel_list) {
	int max_y = 256;
	for (auto &pixel : pixel_list) {
		pixel.y = max_y - 1 - pixel.y;	
	}
}

void save_pixels(const std::string &filename, const std::vector <Pixel> &pixel_list){
	std::ofstream file(filename.c_str());
	if (!file){
		std::cerr << "error opening the output file" << filename << std::endl;
		return;
	}
	
	for (const auto &pixel : pixel_list) {
		file << pixel.x << "," << pixel.y << "," << pixel.r << "," << pixel.g << "," << pixel.b << "\n";
	}
	file.close();
}

int main (int argc, char *argv[]){
	if (argc != 2) {
		std::cerr << "usage: " << argv[0] << "<filename>" << std::endl;
	}
	
	std::string filename = argv[1];
	std::vector<Pixel> pixel_list;

	read_pixels(filename, pixel_list);
	average_colors(pixel_list);
	flip_vertically(pixel_list);
	save_pixels("flipped.dat", pixel_list);

	std::cout << "flipped image saved to to flipped.dat" << std::endl;
	return 0;
}

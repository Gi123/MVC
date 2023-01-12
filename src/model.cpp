#include <algorithm>
#include <iostream>
#include <sstream>
#include "model.h"

Model::Model(const std::string& path) {
	load_project(path);
}
std::string Model::new_file(){
	elements.clear();
	return "C://new_file";
}
void Model::load_project(const std::string& path) {
	elements.clear();
}

void Model::add_primitive(std::shared_ptr<base_primitive>& primitive) {
	elements.emplace_back(primitive);
}

void Model::remove_primitive(std::shared_ptr<base_primitive>& primitive) {
	auto position = std::find(elements.begin(), elements.end(), primitive);
	if (position != elements.end()) {
		elements.erase(position);
	}
}

std::vector<std::string> Model::get_elements() const {
	std::vector<std::string> redrawing;

	for (const auto& element : elements) {
		redrawing.emplace_back(element->draw_figure().c_str());
	}

	return redrawing;
}
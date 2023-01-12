#include "controller.h"
#include <iostream>

controller::controller(Model& model, view_project& view) 
	: _model{ model }, _view{ view } {}
void controller::newDocument()
{
	std::string path_new_file =_model.new_file();
	_view.redraw();
	std::cout << "New file path:" << path_new_file << std::endl;
}
/// Imports the document
void controller::Import(const std::string& filename)
{
    std::cout << "Import file:" << filename << std::endl;
}
/// Exports the document
void controller::Export(const std::string& filename)
{
    std::cout << "Export file:" << filename << std::endl;
}

void controller::add_primitive(std::shared_ptr <base_primitive>& primitive) {
	_model.add_primitive(primitive);
	_view.redraw(); // notify view to update canvas
}

void controller::remove_primitive(std::shared_ptr  <base_primitive>& primitive) {
	_model.remove_primitive(primitive);
	_view.redraw(); // notify view to update canvas
}
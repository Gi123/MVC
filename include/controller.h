#pragma once

#include <string>
#include "model.h"
#include "view.h"

class controller
{
private:
    Model& _model;
	view_project _view;
public:
    controller(Model& model, view_project& view);
    void newDocument();
    void Import(const std::string& filename);
    void Export(const std::string& filename);
    void add_primitive(std::shared_ptr<base_primitive>& primitive);
    void remove_primitive(std::shared_ptr <base_primitive>& primitive);
};

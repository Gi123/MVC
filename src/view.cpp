#include "view.h"
#include "iostream"
    view_project::view_project(const Model& _model)
     : model{_model} { }
     
    void view_project::redraw() {
        const auto& redrawing = model.get_elements();
        if (redrawing.empty()){
            std::cout << "EMPTY WINDOW" << std::endl;// загружаем чистый проект
        }else {
             for (auto& representation : model.get_elements()) {
                std::cout << "*"<<representation << std::endl; ;//перерисовываем каждую фигуру
             }  
        }
    }
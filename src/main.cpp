#include "../include/model.h"
#include "../include/view.h"
#include "../include/controller.h"
#include "../include/base_primitive.h"

int main(int, char const **)
{
    Model context;
    view_project view {context};
    controller editor(context, view);
	editor.newDocument();
	std::shared_ptr<base_primitive> line = std::make_shared<Line> (Point{ 1.2, 2.0 }, Point{5.0, 1.2});
	editor.add_primitive(line);
	editor.remove_primitive(line);
	std::shared_ptr<base_primitive> rectangle = std::make_shared<Rectangle> (Point{ 1.2, 2.0 }, Point{5.0, 1.2}, Point{3.2,2.0}, Point{7.0,1.2});
	editor.add_primitive(rectangle);
	editor.remove_primitive(rectangle);
	editor.Import("C://importFile");
    editor.Export("C://exportFile");
    return 0;
}
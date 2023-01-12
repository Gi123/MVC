#pragma once

#include <string>
#include <vector>
#include <memory>
#include "base_primitive.h"


class Model {
public:
	/**
	 * @brief Конструктор пустого проекта
	 * 
	 */
	Model() = default;

	Model(const std::string& path);
    std::string new_file();
	void load_project(const std::string& path);
	void add_primitive(std::shared_ptr<base_primitive>& primitive);
	void remove_primitive(std::shared_ptr<base_primitive>& primitive);

	std::vector<std::string> get_elements() const;

private:
/**
 * @brief Вектор указателей на набор созданных примитивов в проекте
 * 
 */
	std::vector<std::shared_ptr <base_primitive>> elements; 
};

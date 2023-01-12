#pragma once

#include "model.h"


class view_project {
public:
	/**
	 * @brief Конструктор для View в модели MVC
	 * 
	 * @param Ссылка на класс graph_project
	 */
	view_project(const Model& _model);

	/**
	 * @brief Функция прорисовки если есть данные
	 * 
	 */
	void redraw();

private:
	const Model& model;
	
};
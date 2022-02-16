#include "Grid.h"

Grid::Grid(Draw* _draw) {
	draw = _draw;
}

void Grid::step() {
	Camera camBackUp = *draw->get_camera();
	draw->apply_camera(b2Vec2(0, 0), 1, 1.5 * b2_pi);

	draw->fill_rect({0, 0}, aux::to_b2Vec2(sf::Vector2f(draw->get_window()->getSize())), sf::Color(240, 240, 240, 255), 0);
	draw->get_camera()->set_pos(camBackUp.get_pos());

	auto rightDownCorner = aux::to_b2Vec2(sf::Vector2f(draw->get_window()->getSize()));
	draw->thin_line({-rightDownCorner.x, 0}, {rightDownCorner.x, 0}, sf::Color::Black);
	draw->thin_line({0, -rightDownCorner.y}, {0, rightDownCorner.y}, sf::Color::Black);
	

	draw->set_camera(camBackUp);
	draw->apply_camera();
}
#include <Draw/Draw.h>
#include <SS2MapEditor2/Grid.h>

// Обработчик событий
void processEvents(Draw* draw, sf::Vector2f* mouse_pos) {
	auto window = draw->get_window();
	sf::Event event;
	while (window->pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::MouseMoved:
			mouse_pos->x = event.mouseMove.x;
			mouse_pos->y = event.mouseMove.y;
			break;
		case sf::Event::MouseWheelScrolled:
			draw->get_camera()->modify_scale(pow(2, -0.2 * event.mouseWheelScroll.delta));

			break;
		}
	}

	window->setKeyRepeatEnabled(false);
}

int main() {
	Draw draw;
	draw.create_window(600, 600, "Space Sodomy II");
	draw.apply_camera(b2Vec2(0, 0), 1, 1.5 * b2_pi);

	Grid grid(&draw);

	int time_prev = 0, delay = 20;
	sf::Vector2f mouse_pos;
	while (1) {
		processEvents(&draw, &mouse_pos);

		int time_current = aux::get_milli_count();
		if (time_current - time_prev > delay) {
			time_prev = time_current;
			draw.clear();

			grid.step();

			//draw.fill_rect({ 10, 10 }, { 100, 100 }, sf::Color::Red, 0);
			draw.apply_camera();

			draw.step(0.020);
			draw.display();
		}
	}

	return 0;
}
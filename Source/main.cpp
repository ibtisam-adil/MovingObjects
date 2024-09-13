// IBTISAM ADIL

#include "galba.h"

constexpr float SQUARE_X_SPEED_PIXELS = 3.0f;
constexpr int SQUARE_SIZE_PIXELS = 32;

struct Square {
	float x_position_in_pixels = 0.0f;
	float x_facing_directions = 1.0f;
};

Square john = Square{};

void game_init() 
{
	int window_width = get_window_width();
	john.x_position_in_pixels = window_width * 0.5f;
}

void update() {
	int window_width = get_window_width();

	if (is_key_pressed(Key::Space))
	{
		john.x_facing_directions = -john.x_facing_directions;
	}

	john.x_position_in_pixels += john.x_facing_directions * SQUARE_X_SPEED_PIXELS;

	if (john.x_position_in_pixels >= window_width - SQUARE_SIZE_PIXELS) 
	{
		john.x_facing_directions = -1.0f;
	}
	else if (john.x_position_in_pixels <= 0.0f) 
	{
		john.x_facing_directions = 1.0f;
	}
}

void render()
{
	//int window_width  = get_window_width();
	int window_height = get_window_height();

	int square_x = round_to_int(john.x_position_in_pixels);
	int square_y = round_to_int(window_height * 0.5f);
	draw_rectangle(square_x, square_y, SQUARE_SIZE_PIXELS, SQUARE_SIZE_PIXELS);

}

int main()
{
	game_init();
	initialize(720, 720, "Window");

	while (is_window_open())
	{
		update();

		clear_window();
		render();
		display();
	}

	return 0;
}
// IBTISAM ADIL

#include "galba.h"

// GLOBAL VARIABLES
constexpr float SQUARE_X_SPEED_PIXELS = 3.0f;
constexpr int SQUARE_SIZE_PIXELS = 32;
int NEW_SQUARE_SIZE = SQUARE_SIZE_PIXELS;

float CIRCLE_X_SPEED = random_float_in_range(1.0f, 5.0f);
float CIRCLE_Y_SPEED = random_float_in_range(1.0f, 5.0f);
constexpr int CIRCLE_RADIUS = 25;
int NEW_CIRCLE_RADIUS = CIRCLE_RADIUS;


// STRUCTS
struct Square {
	float x_position_in_pixels = 0.0f;
	float x_facing_directions = 1.0f;
};

struct Circle {
	float circleX = 125.0f;
	float circleY = 120.0f;
	float circle_x_direction = 1.0f;
	float circle_y_direction = 1.0f;

	void resize_circle ()
	{
		if (NEW_CIRCLE_RADIUS == CIRCLE_RADIUS * 2)
		{
			NEW_CIRCLE_RADIUS = CIRCLE_RADIUS;
		}
		else
		{
			NEW_CIRCLE_RADIUS = CIRCLE_RADIUS * 2;
		}
	}
};

Square john = Square{};
Circle circle = Circle{};

void update() {

	// Logic for John
	int window_width = get_window_width();
	int window_height = get_window_height();

	if (is_key_pressed(Key::Space))
	{
		john.x_facing_directions = -john.x_facing_directions;
	}

	john.x_position_in_pixels += john.x_facing_directions * SQUARE_X_SPEED_PIXELS;

	if (john.x_position_in_pixels >= window_width - SQUARE_SIZE_PIXELS)
	{
		john.x_facing_directions = -1.0f;
		NEW_SQUARE_SIZE = SQUARE_SIZE_PIXELS * 2;
	}
	else if (john.x_position_in_pixels <= 0.0f)
	{
		john.x_facing_directions = 1.0f;
		NEW_SQUARE_SIZE = SQUARE_SIZE_PIXELS;
	}

	// Logic for Circle
	circle.circleX += circle.circle_x_direction * CIRCLE_X_SPEED;
	circle.circleY += circle.circle_y_direction * CIRCLE_Y_SPEED;

	if (circle.circleX >= window_width - CIRCLE_RADIUS)
	{
		circle.circle_x_direction = -1.0f;
		circle.resize_circle();
	}
	else if (circle.circleY >= window_height - CIRCLE_RADIUS)
	{
		circle.circle_y_direction = -1.0f;
		circle.resize_circle();
	}
	else if (circle.circleX <= 0.0f + CIRCLE_RADIUS)
	{
		circle.circle_x_direction = 1.0f;
		circle.resize_circle();
	}
	else if (circle.circleY <= 0.0f + CIRCLE_RADIUS)
	{
		circle.circle_y_direction = 1.0f;
		circle.resize_circle();

	}
}

void render()
{
	// Draw John
	int window_height = get_window_height();
	int square_x = round_to_int(john.x_position_in_pixels);
	int square_y = round_to_int(window_height * 0.5f);
	draw_rectangle(square_x, square_y, NEW_SQUARE_SIZE, NEW_SQUARE_SIZE);

	// Draw Circle
	draw_circle(round_to_int(circle.circleX), round_to_int(circle.circleY), NEW_CIRCLE_RADIUS);
}

int main()
{
	//game_init();
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
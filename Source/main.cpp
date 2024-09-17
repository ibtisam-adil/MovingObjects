// IBTISAM ADIL
// Questions Answer
/*
  1* While and do-while loop are control flow loops. In while loop the 
	 condition is checked before executing the statements in the body whereas in 
	 do-while loop the body is executed atleast one time before checking the condition.
  2* The second section for a for loop is used for checking a condition. If there is 
	 no condition in for loop the loop will keep running and never stop. 
  3* Yes, it is possible to assign the same number to two elements of an enumeration.
*/

#include "galba.h"
#include <string>

// GLOBAL VARIABLES
constexpr float SQUARE_X_SPEED_PIXELS = 3.0f;
constexpr int SQUARE_SIZE_PIXELS = 32;
int NEW_SQUARE_SIZE = SQUARE_SIZE_PIXELS;

float CIRCLE_X_SPEED = random_float_in_range(1.0f, 5.0f);
float CIRCLE_Y_SPEED = random_float_in_range(1.0f, 5.0f);
constexpr int CIRCLE_RADIUS = 25;
int NEW_CIRCLE_RADIUS = CIRCLE_RADIUS;
Color CIRCLE_COLOR = white;
unsigned int CIRCLE_BOUNCE_COUNTER = 0;

Color get_random_color() {
	Color color;
	color.r = static_cast<unsigned char>(random_int_in_range(0, 255));
	color.g = static_cast<unsigned char>(random_int_in_range(0, 255));
	color.b = static_cast<unsigned char>(random_int_in_range(0, 255));
	color.a = static_cast<unsigned char>(random_int_in_range(0, 255));
	return color;
}

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

	void resize_circle()
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

	int window_width = get_window_width();
	int window_height = get_window_height();

	// John Functionality
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

	// Circle Functionality
	if (CIRCLE_BOUNCE_COUNTER <= 12) {
		circle.circleX += circle.circle_x_direction * CIRCLE_X_SPEED;
		circle.circleY += circle.circle_y_direction * CIRCLE_Y_SPEED;

		if (circle.circleX >= window_width - CIRCLE_RADIUS || circle.circleX <= 0.0f + CIRCLE_RADIUS) {
			circle.circle_x_direction *= -1.0f;
			circle.resize_circle();
			CIRCLE_COLOR = get_random_color();
			CIRCLE_BOUNCE_COUNTER++;
		}
		if (circle.circleY >= window_height - CIRCLE_RADIUS || circle.circleY <= 0.0f + CIRCLE_RADIUS) {
			circle.circle_y_direction *= -1.0f;
			circle.resize_circle();
			CIRCLE_COLOR = get_random_color();
			CIRCLE_BOUNCE_COUNTER++;
		}
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
	if (CIRCLE_BOUNCE_COUNTER <= 12) {
		draw_circle(round_to_int(circle.circleX), round_to_int(circle.circleY),
			NEW_CIRCLE_RADIUS, CIRCLE_COLOR);
	}

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


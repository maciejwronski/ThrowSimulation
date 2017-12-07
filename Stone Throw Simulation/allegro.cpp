#include "allegro.h"

ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_TIMER *timer = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;

float DeltaTime = 1.0 / FPS;

Allegro::Allegro() {
	Conditions();
	InitAddons();
	registerQueueEvents();
}
int Allegro::Conditions()
{

	if (!al_init()) {
		//	int error;
		//	printf("Allegro didnt load correctly. Program will exit\nPress any key to continue");
		//	scanf_s("%i", &error);
		return -1;
	}
	display = al_create_display(1024, 600);
	if (!display) {
		//	printf("Display didnt load correctly. Program will exit\nPress any key to continue");
		return -1;
	}

}

void Allegro::InitAddons() {
	al_install_mouse();
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_keyboard();
	al_set_window_title(display, "Throw Simulation");
}

void Allegro::registerQueueEvents() {
	event_queue = al_create_event_queue();
	timer = al_create_timer(DeltaTime);
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_start_timer(timer);
}

Allegro::~Allegro() {
	al_destroy_timer(timer);
	al_destroy_event_queue(event_queue);
	al_destroy_display(display);
}

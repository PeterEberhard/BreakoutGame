/* PETER EBERHARD */

void bad_ball_message(const struct Ball *ball);
void bad_paddle_message(const struct Paddle *paddle_pointer);
void bounce_message(const int color, const char *wall, const double X, const double Y);
void final_output(const double elapsed, const struct Sim* sim_pointer);
void master_output(const double elapsed, const struct Sim* sim_pointer);
void scanf_message(const char *who, const int got, const int wanted);

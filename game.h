#ifndef GAME_H
#define GAME_H

void intro();
void show_options();
void look_around();

int get_key(bool);
int inspect_door(bool);
int make_action(char, bool);

#endif

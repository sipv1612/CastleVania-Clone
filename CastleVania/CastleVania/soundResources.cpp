#include "soundResources.h"

#pragma region AUDIO

CSound *lv2_bg;
CSound *clear;
CSound *end_game;
CSound *game_over;
CSound *intro;
CSound *boss;

#pragma endregion

#pragma region SOUND

CSound *get_hit;
CSound *get_hit_2;
CSound *collect_heart;
CSound *collect_item;
CSound *collect_weapon;
CSound *falling;
CSound *falling_water;
CSound *hit_pillar;
CSound *holy_water;
CSound *cross;
CSound *open_door;
CSound *splash_water;
CSound *attack;
CSound *clock_sound;
CSound *fire_proj;
CSound *knife;
CSound *rosary;

CSound *start_sound;
CSound *axe;

CSound *bg_music;
#pragma endregion

void initSound()
{
	lv2_bg = LoadSound("Data\\music\\lv2_bg.wav");
	clear = LoadSound("Data\\music\\clear.wav");
	end_game = LoadSound("Data\\music\\end_game.wav");
	game_over = LoadSound("Data\\music\\game_over.wav");
	intro = LoadSound("Data\\music\\intro.wav");
	boss = LoadSound("Data\\music\\boss.wav");

	bg_music = LoadSound("Data\\music\\lv1_bg.wav");

	get_hit = LoadSound("Data\\sound\\get_hit.wav");
	get_hit_2 = LoadSound("Data\\sound\\get_hit_2.wav");
	collect_heart = LoadSound("Data\\sound\\collect_heart.wav");
	collect_item = LoadSound("Data\\sound\\collect_item.wav");
	collect_weapon = LoadSound("Data\\sound\\collect_weapon.wav");
	falling = LoadSound("Data\\sound\\falling.wav");
	falling_water = LoadSound("Data\\sound\\falling_water.wav");
	cross = LoadSound("Data\\sound\\cross.wav");
	open_door = LoadSound("Data\\sound\\open_door.wav");
	splash_water = LoadSound("Data\\sound\\splash_water.wav");
	attack = LoadSound("Data\\sound\\attack.wav");
	clock_sound = LoadSound("Data\\sound\\clock.wav");
	hit_pillar = LoadSound("Data\\sound\\hit_pillar.wav");
	fire_proj = LoadSound("Data\\sound\\fire_proj.wav");
	knife = LoadSound("Data\\sound\\knife.wav");
	holy_water = LoadSound("Data\\sound\\holy_water.wav");
	rosary = LoadSound("Data\\sound\\rosary.wav");

	start_sound = LoadSound("Data\\sound\\start.wav");
	axe = LoadSound("Data\\sound\\axe.wav");
}

void deleteSound()
{
	StopSound(lv2_bg);
	StopSound(clear);
	StopSound(end_game);
	StopSound(game_over);
	StopSound(intro);
	StopSound(boss);

	delete lv2_bg;
	delete clear;
	delete end_game;
	delete game_over;
	delete intro;
	delete boss;

	StopSound(get_hit);
	StopSound(get_hit_2);
	StopSound(collect_heart);
	StopSound(collect_item);
	StopSound(collect_weapon);
	StopSound(falling);
	StopSound(falling_water);
	StopSound(cross);
	StopSound(open_door);
	StopSound(splash_water);
	StopSound(attack);
	StopSound(clock_sound);
	StopSound(hit_pillar);
	StopSound(knife);
	StopSound(holy_water);
	StopSound(rosary);

	delete get_hit;
	delete get_hit_2;
	delete collect_heart;
	delete collect_item;
	delete collect_weapon;
	delete falling;
	delete falling_water;
	delete cross;
	delete open_door;
	delete splash_water;
	delete attack;
	delete clock_sound;
	delete hit_pillar;
	delete knife;
	delete holy_water;
	delete rosary;
}

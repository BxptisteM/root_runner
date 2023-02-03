
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System/Time.h>
#include <SFML/System/Vector3.h>
#include <SFML/Audio.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Audio/Types.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/System/Vector3.h>

#ifndef __root_runner
    #define __root_runner

typedef struct sprite_s {
    sfVideoMode mode;
    sfRenderWindow *win;
} sprite_t;

#endif
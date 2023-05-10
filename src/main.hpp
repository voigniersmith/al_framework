#ifndef MAIN_HPP
#define MAIN_HPP

// Raylib Libraries
#include <raylib.h>

// Standard Libraries
#include <stdio.h>
#include <iostream>
#include <assert.h>
#include <string.h>
#include <getopt.h>

// Data Structure Libraries
#include <deque>
#include <map>
#include <set>
#include <vector>

// Algorithm Libraries
#include <algorithm>

// Standard Namespace
using namespace std;

// Include Project Header Files
#include "app.hpp"
#include "window.hpp"
#include "audio.hpp"
#include "game_object.hpp"

// Definitions
#define WINDOW_DEFAULT_W	  640
#define	WINDOW_DEFAULT_H	  480
#define WINDOW_DEFAULT_FPS	   60
#define VOL_DEFAULT_MASTER  0.75f 
#define VOL_DEFAULT_SFX     0.60f
#define VOL_DEFAULT_BGM     0.50f

#endif

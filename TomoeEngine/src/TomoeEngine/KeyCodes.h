#pragma once

// From glfw3.h

/* The unknown key */
#define TOMOE_KEY_UNKNOWN            -1

/* Printable keys */
#define TOMOE_KEY_SPACE              32
#define TOMOE_KEY_APOSTROPHE         39  /* ' */
#define TOMOE_KEY_COMMA              44  /* , */
#define TOMOE_KEY_MINUS              45  /* - */
#define TOMOE_KEY_PERIOD             46  /* . */
#define TOMOE_KEY_SLASH              47  /* / */
#define TOMOE_KEY_0                  48
#define TOMOE_KEY_1                  49
#define TOMOE_KEY_2                  50
#define TOMOE_KEY_3                  51
#define TOMOE_KEY_4                  52
#define TOMOE_KEY_5                  53
#define TOMOE_KEY_6                  54
#define TOMOE_KEY_7                  55
#define TOMOE_KEY_8                  56
#define TOMOE_KEY_9                  57
#define TOMOE_KEY_SEMICOLON          59  /* ; */
#define TOMOE_KEY_EQUAL              61  /* = */
#define TOMOE_KEY_A                  65
#define TOMOE_KEY_B                  66
#define TOMOE_KEY_C                  67
#define TOMOE_KEY_D                  68
#define TOMOE_KEY_E                  69
#define TOMOE_KEY_F                  70
#define TOMOE_KEY_G                  71
#define TOMOE_KEY_H                  72
#define TOMOE_KEY_I                  73
#define TOMOE_KEY_J                  74
#define TOMOE_KEY_K                  75
#define TOMOE_KEY_L                  76
#define TOMOE_KEY_M                  77
#define TOMOE_KEY_N                  78
#define TOMOE_KEY_O                  79
#define TOMOE_KEY_P                  80
#define TOMOE_KEY_Q                  81
#define TOMOE_KEY_R                  82
#define TOMOE_KEY_S                  83
#define TOMOE_KEY_T                  84
#define TOMOE_KEY_U                  85
#define TOMOE_KEY_V                  86
#define TOMOE_KEY_W                  87
#define TOMOE_KEY_X                  88
#define TOMOE_KEY_Y                  89
#define TOMOE_KEY_Z                  90
#define TOMOE_KEY_LEFT_BRACKET       91  /* [ */
#define TOMOE_KEY_BACKSLASH          92  /* \ */
#define TOMOE_KEY_RIGHT_BRACKET      93  /* ] */
#define TOMOE_KEY_GRAVE_ACCENT       96  /* ` */
#define TOMOE_KEY_WORLD_1            161 /* non-US #1 */
#define TOMOE_KEY_WORLD_2            162 /* non-US #2 */

/* Function keys */
#define TOMOE_KEY_ESCAPE             256
#define TOMOE_KEY_ENTER              257
#define TOMOE_KEY_TAB                258
#define TOMOE_KEY_BACKSPACE          259
#define TOMOE_KEY_INSERT             260
#define TOMOE_KEY_DELETE             261
#define TOMOE_KEY_RIGHT              262
#define TOMOE_KEY_LEFT               263
#define TOMOE_KEY_DOWN               264
#define TOMOE_KEY_UP                 265
#define TOMOE_KEY_PAGE_UP            266
#define TOMOE_KEY_PAGE_DOWN          267
#define TOMOE_KEY_HOME               268
#define TOMOE_KEY_END                269
#define TOMOE_KEY_CAPS_LOCK          280
#define TOMOE_KEY_SCROLL_LOCK        281
#define TOMOE_KEY_NUM_LOCK           282
#define TOMOE_KEY_PRINT_SCREEN       283
#define TOMOE_KEY_PAUSE              284
#define TOMOE_KEY_F1                 290
#define TOMOE_KEY_F2                 291
#define TOMOE_KEY_F3                 292
#define TOMOE_KEY_F4                 293
#define TOMOE_KEY_F5                 294
#define TOMOE_KEY_F6                 295
#define TOMOE_KEY_F7                 296
#define TOMOE_KEY_F8                 297
#define TOMOE_KEY_F9                 298
#define TOMOE_KEY_F10                299
#define TOMOE_KEY_F11                300
#define TOMOE_KEY_F12                301
#define TOMOE_KEY_F13                302
#define TOMOE_KEY_F14                303
#define TOMOE_KEY_F15                304
#define TOMOE_KEY_F16                305
#define TOMOE_KEY_F17                306
#define TOMOE_KEY_F18                307
#define TOMOE_KEY_F19                308
#define TOMOE_KEY_F20                309
#define TOMOE_KEY_F21                310
#define TOMOE_KEY_F22                311
#define TOMOE_KEY_F23                312
#define TOMOE_KEY_F24                313
#define TOMOE_KEY_F25                314
#define TOMOE_KEY_KP_0               320
#define TOMOE_KEY_KP_1               321
#define TOMOE_KEY_KP_2               322
#define TOMOE_KEY_KP_3               323
#define TOMOE_KEY_KP_4               324
#define TOMOE_KEY_KP_5               325
#define TOMOE_KEY_KP_6               326
#define TOMOE_KEY_KP_7               327
#define TOMOE_KEY_KP_8               328
#define TOMOE_KEY_KP_9               329
#define TOMOE_KEY_KP_DECIMAL         330
#define TOMOE_KEY_KP_DIVIDE          331
#define TOMOE_KEY_KP_MULTIPLY        332
#define TOMOE_KEY_KP_SUBTRACT        333
#define TOMOE_KEY_KP_ADD             334
#define TOMOE_KEY_KP_ENTER           335
#define TOMOE_KEY_KP_EQUAL           336
#define TOMOE_KEY_LEFT_SHIFT         340
#define TOMOE_KEY_LEFT_CONTROL       341
#define TOMOE_KEY_LEFT_ALT           342

#ifdef TOMOE_PLATFORM_WINDOWS
	#define TOMOE_KEY_LEFT_WINDOWS   343
#elif TOMOE_PLATFORM_MACOS
	#define TOMOE_KEY_LEFT_COMMAND   343
#elif TOMOE_PLATFORM_LINUX
	#define TOMOE_KEY_LEFT_SUPER     343
#endif

#define TOMOE_KEY_RIGHT_SHIFT        344
#define TOMOE_KEY_RIGHT_CONTROL      345
#define TOMOE_KEY_RIGHT_ALT          346
#define TOMOE_KEY_RIGHT_SUPER        347
#define TOMOE_KEY_MENU               348

#define TOMOE_KEY_LAST               TOMOE_KEY_MENU
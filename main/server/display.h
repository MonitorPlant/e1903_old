#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <windows.h>

#define DISPLAY_MAX_CHAR_X 237
#define DISPLAY_MAX_CHAR_Y 66
#define DISPLAY_MAX_RESOLUTION_X 1920
#define DISPLAY_MAX_RESOLUTION_Y 1080

BOOL displayInit( void );
BOOL displayOut( int map[ DISPLAY_MAX_CHAR_Y ][ DISPLAY_MAX_CHAR_X ] );

#endif /* DISPLAY_H_ */

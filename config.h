#ifndef DC_BIND_CONFIG
#define DC_BIND_CONFIG 1

// Dependencies
#include "data/scripts/dc_math/main.c"

// Function macros
#define dc_bind_find_screen_center_x() openborvariant("xpos") + (openborvariant("hresolution") / 2)
#define dc_bind_find_screen_center_y() openborvariant("ypos") + (openborvariant("vresolution") / 2)

// Options.
// -- Positioning. Controls How binds/reposition offsets are applied
// -- for a given axis.
#define DC_BIND_INVERT_X_DISABLED		0
#define DC_BIND_INVERT_X_ENABLED		1
#define DC_BIND_POSITIONING_DISABLED	openborconstant("BINDING_POSITIONING_NONE")
#define DC_BIND_POSITIONING_LEVEL		openborconstant("BINDING_POSITIONING_LEVEL")
#define DC_BIND_POSITIONING_SCREEN		3
#define	DC_BIND_POSITIONING_TARGET		openborconstant("BINDING_POSITIONING_TARGET")

// Default values.
#define DC_BIND_DEFAULT_INSTANCE		0
#define DC_BIND_DEFAULT_ENT				getlocalvar("self")
#define DC_BIND_DEFAULT_INVERT_X		DC_BIND_INVERT_X_ENABLED
#define DC_BIND_DEFAULT_OFFSET_X		0
#define DC_BIND_DEFAULT_OFFSET_Y		0
#define DC_BIND_DEFAULT_OFFSET_Z		0
#define DC_BIND_DEFAULT_POSITIONING_X	DC_BIND_POSITIONING_TARGET
#define DC_BIND_DEFAULT_POSITIONING_Y	DC_BIND_POSITIONING_TARGET
#define DC_BIND_DEFAULT_POSITIONING_Z	DC_BIND_POSITIONING_TARGET
#define DC_BIND_DEFAULT_SCREEN_X		dc_bind_find_screen_center_x()
#define DC_BIND_DEFAULT_SCREEN_Y		dc_bind_find_screen_center_y()
#define DC_BIND_DEFAULT_SCREEN_Z		openborconstant("SCREENPANEL_Z")
#define DC_BIND_DEFAULT_TARGET			getlocalvar("self")

// Variable keys. Used to identify cross function
// variables used throughout library.
#define DC_BIND_VAR_KEY_BASE_ID			"dcbind"	// Base name of every var ID. Must be unique vs. all other libraries.
#define DC_BIND_VAR_KEY_INSTANCE		DC_BIND_VAR_KEY_BASE_ID + 0
#define DC_BIND_VAR_KEY_ENT				DC_BIND_VAR_KEY_BASE_ID + 1
#define DC_BIND_VAR_KEY_INVERT_X		DC_BIND_VAR_KEY_BASE_ID + 2
#define DC_BIND_VAR_KEY_OFFSET_X		DC_BIND_VAR_KEY_BASE_ID + 3
#define DC_BIND_VAR_KEY_OFFSET_Y		DC_BIND_VAR_KEY_BASE_ID + 4
#define DC_BIND_VAR_KEY_OFFSET_Z		DC_BIND_VAR_KEY_BASE_ID + 5
#define DC_BIND_VAR_KEY_POSITIONING_X	DC_BIND_VAR_KEY_BASE_ID + 6
#define DC_BIND_VAR_KEY_POSITIONING_Y	DC_BIND_VAR_KEY_BASE_ID + 7
#define DC_BIND_VAR_KEY_POSITIONING_Z	DC_BIND_VAR_KEY_BASE_ID + 8
#define DC_BIND_VAR_KEY_TARGET			DC_BIND_VAR_KEY_BASE_ID + 9
#define DC_BIND_VAR_KEY_THE_END			10			// Should always last, with a value one higher than previous key ID.

// Misc hard code values
#define DC_BIND_DRAWMETHOD_SCALE_MAX_X	256
#define DC_BIND_DRAWMETHOD_SCALE_MAX_Y	256

#endif // !DC_BIND_CONFIG

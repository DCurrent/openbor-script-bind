#ifndef DC_ELMERS_CONFIG
#define DC_ELMERS_CONFIG 1

// Dependencies
#include "data/scripts/dc_math/main.c"

// Function macros
#define dc_elmers_find_screen_center_x() openborvariant("xpos") + (openborvariant("hresolution") / 2)
#define dc_elmers_find_screen_center_y() openborvariant("ypos") + (openborvariant("vresolution") / 2)

// Options.
// -- Invert. Invert the offset when criteria are met.
#define DC_ELMERS_INVERT_DIRECTION		1	// Target faces left.
#define DC_ELMERS_INVERT_DISABLED			0	// No invert.
#define DC_ELMERS_INVERT_POSITION			2	// Target position is greater along axis.
// -- Positioning. Controls How binds/reposition offsets are applied
// -- for a given axis.
#define DC_ELMERS_MODE_DISABLED	openborconstant("BIND_MODE_NONE")
#define DC_ELMERS_MODE_LEVEL		openborconstant("BIND_MODE_LEVEL")
#define DC_ELMERS_MODE_SCREEN		3
#define	DC_ELMERS_MODE_TARGET		openborconstant("BIND_MODE_TARGET")

// Default values.
#define DC_ELMERS_DEFAULT_INSTANCE		0
#define DC_ELMERS_DEFAULT_ENT				getlocalvar("self")
#define DC_ELMERS_DEFAULT_INVERT_X		DC_ELMERS_INVERT_DIRECTION
#define DC_ELMERS_DEFAULT_INVERT_Y		DC_ELMERS_INVERT_DISABLED
#define DC_ELMERS_DEFAULT_INVERT_Z		DC_ELMERS_INVERT_DISABLED
#define DC_ELMERS_DEFAULT_LEVEL_X			0
#define DC_ELMERS_DEFAULT_LEVEL_Y			0
#define DC_ELMERS_DEFAULT_LEVEL_Z			0
#define DC_ELMERS_DEFAULT_OFFSET_X		0
#define DC_ELMERS_DEFAULT_OFFSET_Y		0
#define DC_ELMERS_DEFAULT_OFFSET_Z		0
#define DC_ELMERS_DEFAULT_POSITION_STATE_X	DC_ELMERS_MODE_TARGET
#define DC_ELMERS_DEFAULT_POSITION_STATE_Y	DC_ELMERS_MODE_TARGET
#define DC_ELMERS_DEFAULT_POSITION_STATE_Z	DC_ELMERS_MODE_TARGET
#define DC_ELMERS_DEFAULT_SCREEN_X		dc_elmers_find_screen_center_x()
#define DC_ELMERS_DEFAULT_SCREEN_Y		dc_elmers_find_screen_center_y()
#define DC_ELMERS_DEFAULT_SCREEN_Z		openborconstant("SCREENPANEL_Z")
#define DC_ELMERS_DEFAULT_TARGET			getlocalvar("self")

// Variable keys. Used to identify cross function
// variables used throughout library.
#define DC_ELMERS_VAR_KEY_BASE_ID			"dcbind"	// Base name of every var ID. Must be unique vs. all other libraries.
#define DC_ELMERS_VAR_KEY_INSTANCE		DC_ELMERS_VAR_KEY_BASE_ID + 0
#define DC_ELMERS_VAR_KEY_ENT				DC_ELMERS_VAR_KEY_BASE_ID + 1
#define DC_ELMERS_VAR_KEY_INVERT_X		DC_ELMERS_VAR_KEY_BASE_ID + 2
#define DC_ELMERS_VAR_KEY_INVERT_Y		DC_ELMERS_VAR_KEY_BASE_ID + 3
#define DC_ELMERS_VAR_KEY_INVERT_Z		DC_ELMERS_VAR_KEY_BASE_ID + 4
#define DC_ELMERS_VAR_KEY_LEVEL_X			DC_ELMERS_VAR_KEY_BASE_ID + 5
#define DC_ELMERS_VAR_KEY_LEVEL_Y			DC_ELMERS_VAR_KEY_BASE_ID + 6
#define DC_ELMERS_VAR_KEY_LEVEL_Z			DC_ELMERS_VAR_KEY_BASE_ID + 7
#define DC_ELMERS_VAR_KEY_OFFSET_X		DC_ELMERS_VAR_KEY_BASE_ID + 8
#define DC_ELMERS_VAR_KEY_OFFSET_Y		DC_ELMERS_VAR_KEY_BASE_ID + 9
#define DC_ELMERS_VAR_KEY_OFFSET_Z		DC_ELMERS_VAR_KEY_BASE_ID + 10
#define DC_ELMERS_VAR_KEY_POSITION_STATE_X	DC_ELMERS_VAR_KEY_BASE_ID + 11
#define DC_ELMERS_VAR_KEY_POSITION_STATE_Y	DC_ELMERS_VAR_KEY_BASE_ID + 12
#define DC_ELMERS_VAR_KEY_POSITION_STATE_Z	DC_ELMERS_VAR_KEY_BASE_ID + 13
#define DC_ELMERS_VAR_KEY_TARGET			DC_ELMERS_VAR_KEY_BASE_ID + 14
#define DC_ELMERS_VAR_KEY_THE_END			15			// Should always last, with a value one higher than previous key ID.

// Misc hard code values
#define DC_ELMERS_DRAWMETHOD_SCALE_MAX_X	256
#define DC_ELMERS_DRAWMETHOD_SCALE_MAX_Y	256

#endif // !DC_ELMERS_CONFIG

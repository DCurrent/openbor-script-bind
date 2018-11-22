#ifndef DC_BIND_CONFIG
#define DC_BIND_CONFIG 1

// Function macros
#define dc_bind_find_screen_center_x() openborvariant("xpos") + (openborvariant("hresolution") / 2)
#define dc_bind_find_screen_center_y() openborvariant("ypos") + (openborvariant("vresolution") / 2)

// Options.
// -- Positioning. Controls How binds/reposition offsets are applied
// -- for a given axis.
#define DC_BIND_POSITIONING_DISABLED	openborconstant("BINDING_POSITIONING_NONE")
#define DC_BIND_POSITIONING_LEVEL		openborconstant("BINDING_POSITIONING_LEVEL")
#define DC_BIND_POSITIONING_SCREEN		3
#define	DC_BIND_POSITIONING_TARGET		openborconstant("BINDING_POSITIONING_TARGET")

// Default values.
#define DC_BIND_DEFAULT_INSTANCE		0
#define DC_BIND_DEFAULT_ENT				getlocalvar("self")
#define DC_BIND_DEFAULT_POSITIONING_X	DC_BIND_POSITIONING_TARGET
#define DC_BIND_DEFAULT_POSITIONING_Y	DC_BIND_POSITIONING_TARGET
#define DC_BIND_DEFAULT_POSITIONING_Z	DC_BIND_POSITIONING_TARGET
#define DC_BIND_DEFAULT_OFFSET_X		0
#define DC_BIND_DEFAULT_OFFSET_Y		0
#define DC_BIND_DEFAULT_OFFSET_Z		0
#define DC_BIND_DEFAULT_TARGET			getlocalvar("self")
#define DC_BIND_DEFAULT_SCREEN_X		dc_bind_find_screen_center_x()
#define DC_BIND_DEFAULT_SCREEN_Y		dc_bind_find_screen_center_y()
#define DC_BIND_DEFAULT_SCREEN_Z		openborconstant("SCREENPANEL_Z")

// Variable keys.
#define DC_BIND_VAR_KEY_INSTANCE		"dcbind_0"
#define DC_BIND_VAR_KEY_ENT				"dcbind_1"
#define DC_BIND_VAR_KEY_POSITIONING_X	"dcbind_2"
#define DC_BIND_VAR_KEY_POSITIONING_Y	"dcbind_3"
#define DC_BIND_VAR_KEY_POSITIONING_Z	"dcbind_4"
#define DC_BIND_VAR_KEY_OFFSET_X		"dcbind_5"
#define DC_BIND_VAR_KEY_OFFSET_Y		"dcbind_6"
#define DC_BIND_VAR_KEY_OFFSET_Z		"dcbind_7"
#define DC_BIND_VAR_KEY_TARGET			"dcbind_8"

// Misc hard code values
#define DC_BIND_DRAWMETHOD_SCALE_MAX_X	256
#define DC_BIND_DRAWMETHOD_SCALE_MAX_Y	256

#endif // !DC_BIND_CONFIG

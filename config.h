#ifndef DC_BIND_CONFIG
#define DC_BIND_CONFIG 1

// Function macros
#define dc_bind_find_screen_center_x() openborvariant("xpos") + (openborvariant("hresolution") / 2)
#define dc_bind_find_screen_center_y() openborvariant("ypos") + (openborvariant("vresolution") / 2)

// Options.
#define	DC_BIND_DISABLED			0
#define	DC_BIND_ENABLED				1
#define	DC_BIND_TARGET_SCREEN		NULL()

// Default values.
#define DC_BIND_DEFAULT_INSTANCE	0
#define DC_BIND_DEFAULT_ENT			DC_BIND_TARGET_SCREEN
#define DC_BIND_DEFAULT_ENABLE_X	DC_BIND_ENABLED
#define DC_BIND_DEFAULT_ENABLE_Y	DC_BIND_ENABLED
#define DC_BIND_DEFAULT_ENABLE_Z	DC_BIND_ENABLED
#define DC_BIND_DEFAULT_OFFSET_X	0
#define DC_BIND_DEFAULT_OFFSET_Y	0
#define DC_BIND_DEFAULT_OFFSET_Z	0
#define DC_BIND_DEFAULT_TARGET		getlocalvar("self")
#define DC_BIND_DEFAULT_SCREEN_X	dc_bind_find_screen_center_x()
#define DC_BIND_DEFAULT_SCREEN_Y	dc_bind_find_screen_center_y()
#define DC_BIND_DEFAULT_SCREEN_Z	openborconstant("SCREENPANEL_Z")

// Variable keys.
#define DC_BIND_VAR_KEY_INSTANCE	"dcbind_0"
#define DC_BIND_VAR_KEY_ENT			"dcbind_1"
#define DC_BIND_VAR_KEY_ENABLE_X	"dcbind_2"
#define DC_BIND_VAR_KEY_ENABLE_Y	"dcbind_3"
#define DC_BIND_VAR_KEY_ENABLE_Z	"dcbind_4"
#define DC_BIND_VAR_KEY_OFFSET_X	"dcbind_5"
#define DC_BIND_VAR_KEY_OFFSET_Y	"dcbind_6"
#define DC_BIND_VAR_KEY_OFFSET_Z	"dcbind_7"
#define DC_BIND_VAR_KEY_TARGET		"dcbind_8"

#endif // !DC_BIND_CONFIG

#ifndef DC_ELMERS_CONFIG
#define DC_ELMERS_CONFIG 1

// Dependencies
#include "data/scripts/dc_math/main.c"

// Name of library. Used mainly as a base for variable IDs. Must
// be unique vs all other libraries. Try to keep it short.
#define DC_ELMERS_BASE_ID	"dcelme"

// Function macros
#define dc_elmers_find_screen_center_x() openborvariant("xpos") + (openborvariant("hresolution") / 2)
#define dc_elmers_find_screen_center_y() openborvariant("ypos") + (openborvariant("vresolution") / 2)

// Options.
// -- Invert. Invert the offset when criteria are met.
#define DC_ELMERS_INVERT_DIRECTION			1	// Target faces left.
#define DC_ELMERS_INVERT_DISABLED			0	// No invert.
#define DC_ELMERS_INVERT_POSITION			2	// Target position is greater along axis.

// -- Positioning. Controls How binds/reposition offsets are applied
// -- for a given axis.
#define DC_ELMERS_MODE_DISABLED				openborconstant("BIND_MODE_NONE")
#define DC_ELMERS_MODE_LEVEL				openborconstant("BIND_MODE_LEVEL")
#define DC_ELMERS_MODE_SCREEN				3
#define	DC_ELMERS_MODE_TARGET				openborconstant("BIND_MODE_TARGET")

#define DC_ELMERS_PALETTE_MATCH_NONE		0
#define DC_ELMERS_PALETTE_MATCH_INDEX		1
#define DC_ELMERS_PALETTE_MATCH_TABLE		2

// Grapple control sub system.

#define DC_ELMERS_DEFAULT_BLAST_STATE		openborconstant("BLAST_ATTACK")

// -- Sorting of grappled entity.
#define DC_ELMERS_SORT_BACK		-1
#define DC_ELMERS_SORT_FRONT	1
#define DC_ELMERS_SORT_SAME		0

// -- Ability to damage other entities when NOT
// being thrown (i.e. blast state).
#define DC_ELMERS_CAN_DAMAGE_NONE 0

// -- Reaction animation (pose collection).
#define DC_ELMERS_REACT_ANIMATION				openborconstant("ANI_FOLLOW10")

// -- Reaction frames (poses).
#define DC_ELMERS_REACT_FALLING_UP_0			0							
#define DC_ELMERS_REACT_FALLING_UP_TILT_0		1
#define DC_ELMERS_REACT_HELD_0					2
#define DC_ELMERS_REACT_HORIZONTAL_DOWN_0		3
// #define DC_ELMERS_REACT_HORIZONTAL_DOWN_PAIN_0	3
// #define DC_ELMERS_REACT_HORIZONTAL_DOWN_PAIN_1	3
// #define DC_ELMERS_REACT_HORIZONTAL_DOWN_PAIN_2	3
#define DC_ELMERS_REACT_HORIZONTAL_UP_0			4
#define DC_ELMERS_REACT_HORIZONTAL_UP_PAIN_0	5
#define DC_ELMERS_REACT_HORIZONTAL_UP_PAIN_1	6
#define DC_ELMERS_REACT_HORIZONTAL_UP_PAIN_2	7
#define DC_ELMERS_REACT_LAYING_UP_0				8
#define DC_ELMERS_REACT_LAYING_UP_PAIN_0		9
#define DC_ELMERS_REACT_LAYING_UP_PAIN_1		10
#define DC_ELMERS_REACT_LAYING_UP_PAIN_2		11
#define DC_ELMERS_REACT_PAIN_0					12
#define DC_ELMERS_REACT_PAIN_1					13
#define DC_ELMERS_REACT_PAIN_2					14
#define DC_ELMERS_REACT_PAIN_MID_0				15
#define DC_ELMERS_REACT_PAIN_MID_1				16
#define DC_ELMERS_REACT_PAIN_MID_2				17
#define DC_ELMERS_REACT_TILT_DOWN_0				18
#define DC_ELMERS_REACT_TILT_UP_0				19
#define DC_ELMERS_REACT_VERTICAL_DOWN_0			20
#define DC_ELMERS_REACT_VERTICAL_DOWN_PAIN_0	21
#define DC_ELMERS_REACT_VERTICAL_DOWN_PAIN_1	22
#define DC_ELMERS_REACT_VERTICAL_DOWN_PAIN_2	23
#define DC_ELMERS_REACT_VERTICAL_UP_0			24
#define DC_ELMERS_REACT_VERTICAL_UP_PAIN_0		25	
#define DC_ELMERS_REACT_VERTICAL_UP_PAIN_1		26
#define DC_ELMERS_REACT_VERTICAL_UP_PAIN_2		27


// Default values.
#define DC_ELMERS_DEFAULT_INSTANCE				0
#define DC_ELMERS_DEFAULT_ATTACKING				openborconstant("ATTACKING_ACTIVE")
#define DC_ELMERS_DEFAULT_BLAST					openborconstant("BLAST_ATTACK")
#define DC_ELMERS_DEFAULT_CAN_DAMAGE			DC_ELMERS_CAN_DAMAGE_NONE
#define DC_ELMERS_DEFAULT_CAN_DAMAGE_OLD		DC_ELMERS_CAN_DAMAGE_NONE
#define DC_ELMERS_DEFAULT_DIRECTION				openborconstant("DIRECTION_ADJUST_SAME")
#define DC_ELMERS_DEFAULT_ENT					getlocalvar("self")
#define DC_ELMERS_DEFAULT_INVERT_X				DC_ELMERS_INVERT_DIRECTION
#define DC_ELMERS_DEFAULT_INVERT_Y				DC_ELMERS_INVERT_DISABLED
#define DC_ELMERS_DEFAULT_INVERT_Z				DC_ELMERS_INVERT_DISABLED
#define DC_ELMERS_DEFAULT_LEVEL_X				0
#define DC_ELMERS_DEFAULT_LEVEL_Y				0
#define DC_ELMERS_DEFAULT_LEVEL_Z				0
#define DC_ELMERS_DEFAULT_OFFSET_X				0
#define DC_ELMERS_DEFAULT_OFFSET_Y				0
#define DC_ELMERS_DEFAULT_OFFSET_Z				0
#define DC_ELMERS_DEFAULT_PALETTE_MATCH			DC_ELMERS_PALETTE_MATCH_NONE
#define DC_ELMERS_DEFAULT_POSITION_QUANTITY_X	1
#define DC_ELMERS_DEFAULT_POSITION_QUANTITY_Y	1
#define DC_ELMERS_DEFAULT_POSITION_QUANTITY_Z	1
#define DC_ELMERS_DEFAULT_ANCHOR_X				DC_ELMERS_MODE_TARGET
#define DC_ELMERS_DEFAULT_ANCHOR_Y				DC_ELMERS_MODE_TARGET
#define DC_ELMERS_DEFAULT_ANCHOR_Z				DC_ELMERS_MODE_TARGET
#define DC_ELMERS_DEFAULT_SCREEN_X				dc_elmers_find_screen_center_x()
#define DC_ELMERS_DEFAULT_SCREEN_Y				dc_elmers_find_screen_center_y()
#define DC_ELMERS_DEFAULT_SCREEN_Z				openborconstant("SCREENPANEL_Z")
#define DC_ELMERS_DEFAULT_TAG					NULL()
#define DC_ELMERS_DEFAULT_TARGET				getlocalvar("self")

// Variable keys. Used to identify cross function
// variables used throughout library.
#define DC_ELMERS_MEMBER_INSTANCE				DC_ELMERS_BASE_ID + 0
#define DC_ELMERS_MEMBER_ATTACKING				DC_ELMERS_BASE_ID + 1
#define DC_ELMERS_MEMBER_BLAST					DC_ELMERS_BASE_ID + 2
#define DC_ELMERS_MEMBER_CAN_DAMAGE				DC_ELMERS_BASE_ID + 3
#define DC_ELMERS_MEMBER_CAN_DAMAGE_OLD			DC_ELMERS_BASE_ID + 4
#define DC_ELMERS_MEMBER_DIRECTION				DC_ELMERS_BASE_ID + 5
#define DC_ELMERS_MEMBER_ENT					DC_ELMERS_BASE_ID + 6
#define DC_ELMERS_MEMBER_INVERT_X				DC_ELMERS_BASE_ID + 7
#define DC_ELMERS_MEMBER_INVERT_Y				DC_ELMERS_BASE_ID + 8
#define DC_ELMERS_MEMBER_INVERT_Z				DC_ELMERS_BASE_ID + 9
#define DC_ELMERS_MEMBER_LEVEL_X				DC_ELMERS_BASE_ID + 10
#define DC_ELMERS_MEMBER_LEVEL_Y				DC_ELMERS_BASE_ID + 11
#define DC_ELMERS_MEMBER_LEVEL_Z				DC_ELMERS_BASE_ID + 12
#define DC_ELMERS_MEMBER_OFFSET_X				DC_ELMERS_BASE_ID + 13
#define DC_ELMERS_MEMBER_OFFSET_Y				DC_ELMERS_BASE_ID + 14
#define DC_ELMERS_MEMBER_OFFSET_Z				DC_ELMERS_BASE_ID + 15
#define DC_ELMERS_MEMBER_PALETTE_MATCH			DC_ELMERS_BASE_ID + 16
#define DC_ELMERS_MEMBER_POSITION_QUANTITY_X	DC_ELMERS_BASE_ID + 17
#define DC_ELMERS_MEMBER_POSITION_QUANTITY_Y	DC_ELMERS_BASE_ID + 18
#define DC_ELMERS_MEMBER_POSITION_QUANTITY_Z	DC_ELMERS_BASE_ID + 19
#define DC_ELMERS_MEMBER_ANCHOR_X				DC_ELMERS_BASE_ID + 20
#define DC_ELMERS_MEMBER_ANCHOR_Y				DC_ELMERS_BASE_ID + 21
#define DC_ELMERS_MEMBER_ANCHOR_Z				DC_ELMERS_BASE_ID + 22
#define DC_ELMERS_MEMBER_TAG					DC_ELMERS_BASE_ID + 23
#define DC_ELMERS_MEMBER_TARGET					DC_ELMERS_BASE_ID + 24
#define DC_ELMERS_MEMBER_THE_END				25				// Should always last, with a value one higher than previous key ID.

// Misc hard code values
#define DC_ELMERS_DRAWMETHOD_SCALE_MAX_X	256
#define DC_ELMERS_DRAWMETHOD_SCALE_MAX_Y	256

// Function macros:
#define dc_elmers_get_targets_opponent()		get_entity_property(dc_elmers_get_target(),"opponent")

#endif // !DC_ELMERS_CONFIG
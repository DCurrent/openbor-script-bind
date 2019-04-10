#include "data/scripts/dc_elmers/config.h"

#import "data/scripts/dc_elmers/entity.c"
#import "data/scripts/dc_elmers/level.c"
#import "data/scripts/dc_elmers/offset.c"

// X axis positioning.
int dc_elmers_get_positioning_x()
{
	int instance;
	int result;

	// Get instance.
	instance = dc_elmers_get_instance();

	result = getlocalvar(instance + DC_ELMERS_VAR_KEY_POSITION_STATE_X);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_ELMERS_DEFAULT_POSITION_STATE_X;
	}

	return result;
}

int dc_elmers_set_positioning_x(int value)
{
	int instance;

	// Get instance.
	instance = dc_elmers_get_instance();

	setlocalvar(instance + DC_ELMERS_VAR_KEY_POSITION_STATE_X, value);
}

// Y axis positioning.
int dc_elmers_get_positioning_y()
{
	int instance;
	int result;

	// Get instance.
	instance = dc_elmers_get_instance();

	result = getlocalvar(instance + DC_ELMERS_VAR_KEY_POSITION_STATE_Y);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_ELMERS_DEFAULT_POSITION_STATE_Y;
	}

	return result;
}

int dc_elmers_set_positioning_y(int value)
{
	int instance;

	// Get instance.
	instance = dc_elmers_get_instance();

	setlocalvar(instance + DC_ELMERS_VAR_KEY_POSITION_STATE_Y, value);
}

// z axis positioning.
int dc_elmers_get_positioning_z()
{
	int instance;
	int result;

	// Get instance.
	instance = dc_elmers_get_instance();

	result = getlocalvar(instance + DC_ELMERS_VAR_KEY_POSITION_STATE_Z);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_ELMERS_DEFAULT_POSITION_STATE_Z;
	}

	return result;
}

int dc_elmers_set_positioning_z(int value)
{
	int instance;

	// Get instance.
	instance = dc_elmers_get_instance();

	setlocalvar(instance + DC_ELMERS_VAR_KEY_POSITION_STATE_Z, value);
}

// Operations.

// Caskey, Damon V.
// 2018-11-23
//
// Return a final position depending on positioning settings
// and offsets. Don't use for native engine bind functions 
// since they already do this.
float dc_elmers_find_target_position_x()
{
	void ent;			// Entity to be repositioned.
	void target;		// Target entity;
	int positioning;	// Positioning type.
	float result;		// Final output.

	// Entities.
	ent = dc_elmers_get_entity();
	target = dc_elmers_get_target();

	// Let's get the positioning setting and decide what to do.
	positioning = dc_elmers_get_positioning_x();

	if (positioning == DC_ELMERS_MODE_DISABLED)
	{
		// Use current position (IOW, no position change).
		result = getentityproperty(ent, "x");
	}
	else if (positioning == DC_ELMERS_MODE_LEVEL)
	{
		result = dc_elmers_get_level_x();
	}
	else if (positioning == DC_ELMERS_MODE_SCREEN)
	{
		result = DC_ELMERS_DEFAULT_SCREEN_X;
	}
	else if (positioning == DC_ELMERS_MODE_TARGET)
	{
		result = getentityproperty(target, "x");
	}

	return result;
}

// Caskey, Damon V.
// 2018-11-23
//
// Return a final position depending on positioning settings
// and offsets. Don't use for native engine bind functions 
// since they already do this.
float dc_elmers_find_target_position_y()
{
	void ent;			// Entity to be repositioned.
	void target;		// Target entity;
	int positioning;	// Positioning type.
	float result;		// Final output.

	// Entities.
	ent = dc_elmers_get_entity();
	target = dc_elmers_get_target();

	// Let's get the positioning setting and decide what to do.
	positioning = dc_elmers_get_positioning_y();

	if (positioning == DC_ELMERS_MODE_DISABLED)
	{
		// Use current position (IOW, no position change).
		result = getentityproperty(ent, "y");
	}
	else if (positioning == DC_ELMERS_MODE_LEVEL)
	{
		result = dc_elmers_get_level_y();
	}
	else if (positioning == DC_ELMERS_MODE_SCREEN)
	{
		result = DC_ELMERS_DEFAULT_SCREEN_Y;
	}
	else if (positioning == DC_ELMERS_MODE_TARGET)
	{
		result = getentityproperty(target, "y");
	}

	return result;
}

// Caskey, Damon V.
// 2018-11-23
//
// Return a final position depending on positioning settings
// and offsets. Don't use for native engine bind functions 
// since they already do this.
float dc_elmers_find_target_position_z()
{
	void ent;			// Entity to be repositioned.
	void target;		// Target entity;
	int positioning;	// Positioning type.
	float result;		// Final output.
	int offset;			// Offset.

	// Entities.
	ent = dc_elmers_get_entity();
	target = dc_elmers_get_target();

	// Let's get the positioning setting and decide what to do.
	positioning = dc_elmers_get_positioning_z();

	if (positioning == DC_ELMERS_MODE_DISABLED)
	{
		// Use current position (IOW, no position change).
		result = getentityproperty(ent, "z");
	}
	else if (positioning == DC_ELMERS_MODE_LEVEL)
	{
		result = dc_elmers_get_level_z();
	}
	else if (positioning == DC_ELMERS_MODE_SCREEN)
	{
		result = DC_ELMERS_DEFAULT_SCREEN_Z;
	}
	else if (positioning == DC_ELMERS_MODE_TARGET)
	{
		// Target position + offset.
		result = getentityproperty(target, "z");
	}

	return result;
}


#include "data/scripts/dc_bind/config.h"

#import "data/scripts/dc_bind/instance.c"
#import "data/scripts/dc_bind/entity.c"
#import "data/scripts/dc_bind/offset.c"

// X axis positioning.
int dc_bind_get_positioning_x()
{
	int instance;
	int result;

	// Get instance.
	instance = dc_bind_get_instance();

	result = getlocalvar(instance + DC_BIND_VAR_KEY_POSITIONING_X);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_BIND_DEFAULT_POSITIONING_X;
	}

	return result;
}

int dc_bind_set_positioning_x(int value)
{
	int instance;

	// Get instance.
	instance = dc_bind_get_instance();

	setlocalvar(instance + DC_BIND_VAR_KEY_POSITIONING_X, value);
}

// Y axis positioning.
int dc_bind_get_positioning_y()
{
	int instance;
	int result;

	// Get instance.
	instance = dc_bind_get_instance();

	result = getlocalvar(instance + DC_BIND_VAR_KEY_POSITIONING_Y);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_BIND_DEFAULT_POSITIONING_Y;
	}

	return result;
}

int dc_bind_set_positioning_y(int value)
{
	int instance;

	// Get instance.
	instance = dc_bind_get_instance();

	setlocalvar(instance + DC_BIND_VAR_KEY_POSITIONING_Y, value);
}

// z axis positioning.
int dc_bind_get_positioning_z()
{
	int instance;
	int result;

	// Get instance.
	instance = dc_bind_get_instance();

	result = getlocalvar(instance + DC_BIND_VAR_KEY_POSITIONING_Z);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_BIND_DEFAULT_POSITIONING_Z;
	}

	return result;
}

int dc_bind_set_positioning_z(int value)
{
	int instance;

	// Get instance.
	instance = dc_bind_get_instance();

	setlocalvar(instance + DC_BIND_VAR_KEY_POSITIONING_Z, value);
}

// Operations.

// Caskey, Damon V.
// 2018-11-23
//
// Return a final position depending on positioning settings
// and offsets. Don't use for native engine bind functions 
// since they already do this.
float dc_bind_find_target_position_x()
{
	void ent;			// Entity to be repositioned.
	void target;		// Target entity;
	int positioning;	// Positioning type.
	float result;		// Final output.

	// Entities.
	ent = dc_bind_get_entity();
	target = dc_bind_get_target();

	// Let's get the positioning setting and decide what to do.
	positioning = dc_bind_get_positioning_x();

	if (positioning == DC_BIND_POSITIONING_DISABLED)
	{
		// Use current position (IOW, no position change).
		result = getentityproperty(ent, "x");
	}
	else if (positioning == DC_BIND_POSITIONING_LEVEL)
	{
		result = 0;
	}
	else if (positioning == DC_BIND_POSITIONING_SCREEN)
	{
		result = DC_BIND_DEFAULT_SCREEN_X;
	}
	else if (positioning == DC_BIND_POSITIONING_TARGET)
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
float dc_bind_find_target_position_y()
{
	void ent;			// Entity to be repositioned.
	void target;		// Target entity;
	int positioning;	// Positioning type.
	float result;		// Final output.

	// Entities.
	ent = dc_bind_get_entity();
	target = dc_bind_get_target();

	// Let's get the positioning setting and decide what to do.
	positioning = dc_bind_get_positioning_y();

	if (positioning == DC_BIND_POSITIONING_DISABLED)
	{
		// Use current position (IOW, no position change).
		result = getentityproperty(ent, "y");
	}
	else if (positioning == DC_BIND_POSITIONING_LEVEL)
	{
		result = 0;
	}
	else if (positioning == DC_BIND_POSITIONING_SCREEN)
	{
		result = DC_BIND_DEFAULT_SCREEN_Y;
	}
	else if (positioning == DC_BIND_POSITIONING_TARGET)
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
float dc_bind_find_target_position_z()
{
	void ent;			// Entity to be repositioned.
	void target;		// Target entity;
	int positioning;	// Positioning type.
	float result;		// Final output.
	int offset;			// Offset.

	// Entities.
	ent = dc_bind_get_entity();
	target = dc_bind_get_target();

	// Let's get the positioning setting and decide what to do.
	positioning = dc_bind_get_positioning_z();

	if (positioning == DC_BIND_POSITIONING_DISABLED)
	{
		// Use current position (IOW, no position change).
		result = getentityproperty(ent, "z");
	}
	else if (positioning == DC_BIND_POSITIONING_LEVEL)
	{
		result = 0;
	}
	else if (positioning == DC_BIND_POSITIONING_SCREEN)
	{
		result = DC_BIND_DEFAULT_SCREEN_Z;
	}
	else if (positioning == DC_BIND_POSITIONING_TARGET)
	{
		// Target position + offset.
		result = getentityproperty(target, "z");
	}

	return result;
}


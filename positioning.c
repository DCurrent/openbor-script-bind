#include "data/scripts/dc_bind/config.h"

#import "data/scripts/dc_bind/instance.c"

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
#include "data/scripts/dc_elmers/config.h"

#import "data/scripts/dc_elmers/instance.c"

// Accessors and Mutators.

// X axis level position.
int dc_elmers_get_level_x()
{
	int instance;
	int result;

	// Get instance.
	instance = dc_elmers_get_instance();

	result = getlocalvar(instance + DC_ELMERS_VAR_KEY_LEVEL_X);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_ELMERS_DEFAULT_LEVEL_X;
	}

	return result;
}

int dc_elmers_set_level_x(int value)
{
	int instance;

	// Get instance.
	instance = dc_elmers_get_instance();

	setlocalvar(instance + DC_ELMERS_VAR_KEY_LEVEL_X, value);
}

// Y axis level position.
int dc_elmers_get_level_y()
{
	int instance;
	int result;

	// Get instance.
	instance = dc_elmers_get_instance();

	result = getlocalvar(instance + DC_ELMERS_VAR_KEY_LEVEL_Y);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_ELMERS_DEFAULT_LEVEL_Y;
	}

	return result;
}

int dc_elmers_set_level_y(int value)
{
	int instance;

	// Get instance.
	instance = dc_elmers_get_instance();

	setlocalvar(instance + DC_ELMERS_VAR_KEY_LEVEL_Y, value);
}

// Z axis level position.
int dc_elmers_get_level_z()
{
	int instance;
	int result;

	// Get instance.
	instance = dc_elmers_get_instance();

	result = getlocalvar(instance + DC_ELMERS_VAR_KEY_LEVEL_Z);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_ELMERS_DEFAULT_LEVEL_Z;
	}

	return result;
}

int dc_elmers_set_level_z(int value)
{
	int instance;

	// Get instance.
	instance = dc_elmers_get_instance();

	setlocalvar(instance + DC_ELMERS_VAR_KEY_LEVEL_Z, value);
}
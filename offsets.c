#include "data/scripts/dc_bind/config.h"

#import "data/scripts/dc_bind/config.c"

// Accessors and Mutators

// X axis.
int dc_bind_get_offset_x()
{
	int instance;
	int result;

	// Get instance.
	instance = dc_bind_get_instance();

	result = getlocalvar(instance + DC_BIND_VAR_KEY_OFFSET_X);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_BIND_DEFAULT_OFFSET_X;
	}

	return result;
}

int dc_bind_set_offset_x(int value)
{
	int instance;

	// Get instance.
	instance = dc_bind_get_instance();

	setlocalvar(instance + DC_BIND_VAR_KEY_OFFSET_X, value);
}

// Y axis.
int dc_bind_get_offset_y()
{
	int instance;
	int result;

	// Get instance.
	instance = dc_bind_get_instance();

	result = getlocalvar(instance + DC_BIND_VAR_KEY_OFFSET_Y);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_BIND_DEFAULT_OFFSET_Y;
	}

	return result;
}

int dc_bind_set_offset_y(int value)
{
	int instance;

	// Get instance.
	instance = dc_bind_get_instance();

	setlocalvar(instance + DC_BIND_VAR_KEY_OFFSET_Y, value);
}

// Z axis.
int dc_bind_get_offset_z()
{
	int instance;
	int result;

	// Get instance.
	instance = dc_bind_get_instance();

	result = getlocalvar(instance + DC_BIND_VAR_KEY_OFFSET_Z);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_BIND_DEFAULT_OFFSET_Z;
	}

	return result;
}

int dc_bind_set_offset_z(int value)
{
	int instance;

	// Get instance.
	instance = dc_bind_get_instance();

	setlocalvar(instance + DC_BIND_VAR_KEY_OFFSET_Z, value);
}

// Operations


int dc_bind_find_scaled_offset_x()
{
	void	target;
	float	scale;
	int		offset;

	// Get target.
	target = dc_bind_get_target();

	offset = dc_bind_get_offset_x();

	// Is target a valid entity?
	if (typeof(target) == openborconstant("VT_PTR"))
	{
		// Get target scale. If it's a valid number,
		// then divide it by max value to get a scale 
		// percentage.
		scale = getdrawmethod(target, "scalex");

		if (scale)
		{
			scale = scale / 256;
		}

		// Multiple offset by scale percentage to get
		// an offset that compensates for the
		// target's current size.
		offset *= scale;
	}	
}
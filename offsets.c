#include "data/scripts/dc_bind/config.h"

#import "data/scripts/dc_bind/config.c"

// Accessors and Mutators

// X axis enable.
int dc_bind_get_enable_x()
{
	int instance;
	int result;

	// Get instance.
	instance = dc_bind_get_instance();

	result = getlocalvar(instance + DC_BIND_VAR_KEY_ENABLE_X);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_BIND_DEFAULT_ENABLE_X;
	}

	return result;
}

int dc_bind_set_enable_x(int value)
{
	int instance;

	// Get instance.
	instance = dc_bind_get_instance();

	setlocalvar(instance + DC_BIND_VAR_KEY_ENABLE_X, value);
}

// Y axis enable.
int dc_bind_get_enable_y()
{
	int instance;
	int result;

	// Get instance.
	instance = dc_bind_get_instance();

	result = getlocalvar(instance + DC_BIND_VAR_KEY_ENABLE_Y);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_BIND_DEFAULT_ENABLE_Y;
	}

	return result;
}

int dc_bind_set_enable_y(int value)
{
	int instance;

	// Get instance.
	instance = dc_bind_get_instance();

	setlocalvar(instance + DC_BIND_VAR_KEY_ENABLE_Y, value);
}

// z axis enable.
int dc_bind_get_enable_z()
{
	int instance;
	int result;

	// Get instance.
	instance = dc_bind_get_instance();

	result = getlocalvar(instance + DC_BIND_VAR_KEY_ENABLE_Z);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_BIND_DEFAULT_ENABLE_Z;
	}

	return result;
}

int dc_bind_set_enable_z(int value)
{
	int instance;

	// Get instance.
	instance = dc_bind_get_instance();

	setlocalvar(instance + DC_BIND_VAR_KEY_ENABLE_Z, value);
}

// X axis offset.
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

// Y axis offset.
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

// Z axis offset.
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

// Caskey, Damon V.
// 2018-11-19
//
// Return an adjusted X offset to compensate for 
// scaling effects target may have applied.
int dc_bind_find_scaled_offset_x()
{
	void	target;
	float	scale;
	int		offset;

	// Get the offset.
	offset = dc_bind_get_offset_x();

	// Is there a valid target entity?
	target = dc_bind_get_target();

	if (typeof(target) == openborconstant("VT_PTR"))
	{
		// Get target scale. If it's a valid number,
		// then divide it by max value to get a scale 
		// percentage.
		scale = getdrawmethod(target, "scalex");

		if (scale)
		{
			scale = scale / DC_BIND_DRAWMETHOD_SCALE_MAX_X;
		}

		// Multiple offset by scale percentage to get
		// an offset that compensates for the
		// target's current size.
		offset *= scale;
	}

	return offset;
}

// Caskey, Damon V.
// 2018-11-19
//
// Return an adjusted X offset to compensate for 
// scaling effects target may have applied.
int dc_bind_find_scaled_offset_y()
{
	void	target;
	float	scale;
	int		offset;

	// Get the offset.
	offset = dc_bind_get_offset_y();

	// Is there a valid target entity?
	target = dc_bind_get_target();

	if (typeof(target) == openborconstant("VT_PTR"))
	{
		// Get target scale. If it's a valid number,
		// then divide it by max value to get a scale 
		// percentage.
		scale = getdrawmethod(target, "scaley");

		if (scale)
		{
			scale = scale / DC_BIND_DRAWMETHOD_SCALE_MAX_Y;
		}

		// Multiply offset by scale percentage to get
		// an offset that compensates for the
		// target's current size.
		offset *= scale;
	}

	return offset;
}
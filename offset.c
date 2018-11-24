#include "data/scripts/dc_bind/config.h"

#import "data/scripts/dc_bind/entity.c"
#import "data/scripts/dc_bind/instance.c"

// Accessors and Mutators
// Invert X offset when target entity faces left.
int dc_bind_get_invert_x()
{
	int instance;
	int result;

	// Get instance.
	instance = dc_bind_get_instance();

	result = getlocalvar(instance + DC_BIND_VAR_KEY_INVERT_X);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_BIND_DEFAULT_INVERT_X;
	}

	return result;
}

int dc_bind_set_invert_x(int value)
{
	int instance;

	// Get instance.
	instance = dc_bind_get_instance();

	setlocalvar(instance + DC_BIND_VAR_KEY_INVERT_X, value);
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

// Caskey, Damon V.
//
// Return a final offset value to use in non native
// bind functions. Don't use this to get an offset
// for OpenBOR's native bind, because it already
// does invert.
int dc_bind_find_offset_with_invert_x()
{
	int offset;			// Offset to output.
	int invert;			// Invert setting.
	void ent;			// Acting entity.
	void target;		// Target entity.
	float target_pos;	// Target location.
	float ent_pos;		// Entity location.	

	// Get invert and offset, we need these right away.
	offset = dc_bind_find_scaled_offset_x();
	invert = dc_bind_get_invert_x();

	if (invert == DC_BIND_INVERT_DISABLED)
	{
		// Do nothig, offset is returned as is.
	}
	else if (invert == DC_BIND_INVERT_DIRECTION)
	{
		// Invert if target is and facing left.
		target = dc_bind_get_target();

		if (getentityproperty(target, "direction") == openborconstant("DIRECTION_LEFT"))
		{
			offset = -offset;
		}
	}
	else if (invert == DC_BIND_INVERT_POSITION)
	{
		// Invert if target is in a greater position.
		ent = dc_bind_get_entity();
		target = dc_bind_get_target();

		ent_pos = getentityproperty(ent, "x");
		target_pos = getentityproperty(target, "x");

		if (target_pos > ent_pos)
		{
			offset = -offset;
		}
	}		

	// Return final offset.
	return offset;
}
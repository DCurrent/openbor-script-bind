#include "data/scripts/dc_elmers/config.h"

#import "data/scripts/dc_elmers/entity.c"

// Accessors and Mutators
// Invert X offset settings.
int dc_elmers_get_invert_x()
{
	int instance;
	int result;

	// Get instance.
	instance = dc_elmers_get_instance();

	result = getlocalvar(instance + DC_ELMERS_VAR_KEY_INVERT_X);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_ELMERS_DEFAULT_INVERT_X;
	}

	return result;
}

int dc_elmers_set_invert_x(int value)
{
	char id;

	// Get ID.
	id = dc_elmers_get_instance() + DC_ELMERS_VAR_KEY_INVERT_X;

	// If value is default, make sure the variable
	// is deleted.
	if (value == DC_ELMERS_DEFAULT_INVERT_X)
	{
		setlocalvar(id, value);
	}
	else
	{
		setlocalvar(id, NULL());
	}	
}

// Invert Y offset settings.
int dc_elmers_get_invert_y()
{
	int instance;
	int result;

	// Get instance.
	instance = dc_elmers_get_instance();

	result = getlocalvar(instance + DC_ELMERS_VAR_KEY_INVERT_Y);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_ELMERS_DEFAULT_INVERT_Y;
	}

	return result;
}

int dc_elmers_set_invert_y(int value)
{
	int instance;

	// Get instance.
	instance = dc_elmers_get_instance();

	setlocalvar(instance + DC_ELMERS_VAR_KEY_INVERT_Y, value);
}

// Invert Z offset settings.
int dc_elmers_get_invert_z()
{
	int instance;
	int result;

	// Get instance.
	instance = dc_elmers_get_instance();

	result = getlocalvar(instance + DC_ELMERS_VAR_KEY_INVERT_Z);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_ELMERS_DEFAULT_INVERT_Z;
	}

	return result;
}

int dc_elmers_set_invert_z(int value)
{
	int instance;

	// Get instance.
	instance = dc_elmers_get_instance();

	setlocalvar(instance + DC_ELMERS_VAR_KEY_INVERT_Z, value);
}

// X axis offset.
int dc_elmers_get_offset_x()
{
	int instance;
	int result;

	// Get instance.
	instance = dc_elmers_get_instance();

	result = getlocalvar(instance + DC_ELMERS_VAR_KEY_OFFSET_X);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_ELMERS_DEFAULT_OFFSET_X;
	}

	return result;
}

int dc_elmers_set_offset_x(int value)
{
	int instance;

	// Get instance.
	instance = dc_elmers_get_instance();

	setlocalvar(instance + DC_ELMERS_VAR_KEY_OFFSET_X, value);
}

// Y axis offset.
int dc_elmers_get_offset_y()
{
	int instance;
	int result;

	// Get instance.
	instance = dc_elmers_get_instance();

	result = getlocalvar(instance + DC_ELMERS_VAR_KEY_OFFSET_Y);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_ELMERS_DEFAULT_OFFSET_Y;
	}

	return result;
}

int dc_elmers_set_offset_y(int value)
{
	int instance;

	// Get instance.
	instance = dc_elmers_get_instance();

	setlocalvar(instance + DC_ELMERS_VAR_KEY_OFFSET_Y, value);
}

// Z axis offset.
int dc_elmers_get_offset_z()
{
	int instance;
	int result;

	// Get instance.
	instance = dc_elmers_get_instance();

	result = getlocalvar(instance + DC_ELMERS_VAR_KEY_OFFSET_Z);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_ELMERS_DEFAULT_OFFSET_Z;
	}

	return result;
}

int dc_elmers_set_offset_z(int value)
{
	int instance;

	// Get instance.
	instance = dc_elmers_get_instance();

	setlocalvar(instance + DC_ELMERS_VAR_KEY_OFFSET_Z, value);
}



// Operations

// Caskey, Damon V.
// 2018-11-19
//
// Return an adjusted X offset to compensate for 
// scaling effects target may have applied.
int dc_elmers_find_scaled_offset_x()
{
	void	target;
	float	scale;
	int		offset;

	// Get the offset.
	offset = dc_elmers_get_offset_x();

	// Is there a valid target entity?
	target = dc_elmers_get_target();

	if (typeof(target) == openborconstant("VT_PTR"))
	{
		// Get target scale. If it's a valid number,
		// then divide it by max value to get a scale 
		// percentage.
		scale = getdrawmethod(target, "scalex");

		if (scale)
		{
			scale = scale / DC_ELMERS_DRAWMETHOD_SCALE_MAX_X;
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
int dc_elmers_find_scaled_offset_y()
{
	void	target;
	float	scale;
	int		offset;

	// Get the offset.
	offset = dc_elmers_get_offset_y();

	// Is there a valid target entity?
	target = dc_elmers_get_target();

	// Is there a valid target entity?
	if (typeof(target) == openborconstant("VT_PTR"))
	{
		// Get target scale. If it's a valid number,
		// then divide it by max value to get a scale 
		// percentage.
		scale = getdrawmethod(target, "scaley");

		if (scale)
		{
			scale = scale / DC_ELMERS_DRAWMETHOD_SCALE_MAX_Y;
		}

		// Multiply offset by scale percentage to get
		// an offset that compensates for the
		// target's current size.
		offset *= scale;
	}

	return offset;
}

// Caskey, Damon V.
// 2018-11-24
//
// Return a final X offset value to use in non native
// bind functions. Don't use this to get an offset
// for OpenBOR's native bind, because it already
// does invert.
int dc_elmers_find_offset_with_invert_x()
{
	int offset;			// Offset to output.
	int invert;			// Invert setting.
	void ent;			// Acting entity.
	void target;		// Target entity.
	float target_pos;	// Target location.
	float ent_pos;		// Entity location.	

	// Get invert and offset, we need these right away.
	offset = dc_elmers_find_scaled_offset_x();
	invert = dc_elmers_get_invert_x();

	if (invert == DC_ELMERS_INVERT_DISABLED)
	{
		// Do nothig, offset is returned as is.
	}
	else if (invert == DC_ELMERS_INVERT_DIRECTION)
	{
		// Invert if target is and facing left.
		target = dc_elmers_get_target();

		if (getentityproperty(target, "direction") == openborconstant("DIRECTION_LEFT"))
		{
			offset = -offset;
		}
	}
	else if (invert == DC_ELMERS_INVERT_POSITION)
	{
		// Invert if target is in a greater position.
		ent = dc_elmers_get_entity();
		target = dc_elmers_get_target();

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

// Caskey, Damon V.
// 2018-11-24
//
// Return a final Y offset value to use in non native
// bind functions. Don't use this to get an offset
// for OpenBOR's native bind, because it already
// does invert.
int dc_elmers_find_offset_with_invert_y()
{
	int offset;			// Offset to output.
	int invert;			// Invert setting.
	void ent;			// Acting entity.
	void target;		// Target entity.
	float target_pos;	// Target location.
	float ent_pos;		// Entity location.	

	// Get invert and offset, we need these right away.
	offset = dc_elmers_find_scaled_offset_y();
	invert = dc_elmers_get_invert_y();

	if (invert == DC_ELMERS_INVERT_DISABLED)
	{
		// Do nothig, offset is returned as is.
	}
	else if (invert == DC_ELMERS_INVERT_DIRECTION)
	{
		// Invert if target is and facing left.
		target = dc_elmers_get_target();

		if (getentityproperty(target, "direction") == openborconstant("DIRECTION_LEFT"))
		{
			offset = -offset;
		}
	}
	else if (invert == DC_ELMERS_INVERT_POSITION)
	{
		// Invert if target is in a greater position.
		ent = dc_elmers_get_entity();
		target = dc_elmers_get_target();

		ent_pos = getentityproperty(ent, "y");
		target_pos = getentityproperty(target, "y");

		if (target_pos > ent_pos)
		{
			offset = -offset;
		}
	}

	// Return final offset.
	return offset;
}

// Caskey, Damon V.
// 2018-11-24
//
// Return a final Z offset value to use in non native
// bind functions. Don't use this to get an offset
// for OpenBOR's native bind, because it already
// does invert.
int dc_elmers_find_offset_with_invert_z()
{
	int offset;			// Offset to output.
	int invert;			// Invert setting.
	void ent;			// Acting entity.
	void target;		// Target entity.
	float target_pos;	// Target location.
	float ent_pos;		// Entity location.	

	// Get invert and offset, we need these right away.
	offset = dc_elmers_get_offset_z();
	invert = dc_elmers_get_invert_z();

	if (invert == DC_ELMERS_INVERT_DISABLED)
	{
		// Do nothig, offset is returned as is.
	}
	else if (invert == DC_ELMERS_INVERT_DIRECTION)
	{
		// Invert if target is and facing left.
		target = dc_elmers_get_target();

		if (getentityproperty(target, "direction") == openborconstant("DIRECTION_LEFT"))
		{
			offset = -offset;
		}
	}
	else if (invert == DC_ELMERS_INVERT_POSITION)
	{
		// Invert if target is in a greater position.
		ent = dc_elmers_get_entity();
		target = dc_elmers_get_target();

		ent_pos = getentityproperty(ent, "z");
		target_pos = getentityproperty(target, "z");

		if (target_pos > ent_pos)
		{
			offset = -offset;
		}
	}

	// Return final offset.
	return offset;
}
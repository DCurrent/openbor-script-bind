#include "data/scripts/dc_elmers/config.h"

#import "data/scripts/dc_elmers/instance.c"

// When adjusting toward or away from a position (as opposed
// to outright warping to new coordinates) these values 
// determine how far the entity is moved.

// X axis.
int dc_elmers_get_position_adjust_quantity_x()
{
	char id;
	int result;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_POSITION_QUANTITY_X;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_ELMERS_DEFAULT_POSITION_QUANTITY_X;
	}

	return result;
}

int dc_elmers_set_position_adjust_quantity_x(int value)
{
	char id;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_POSITION_QUANTITY_X;

	if (value == DC_ELMERS_DEFAULT_POSITION_QUANTITY_X)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

// Y axis.
int dc_elmers_get_position_adjust_quantity_y()
{
	char id;
	int result;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_POSITION_QUANTITY_Y;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_ELMERS_DEFAULT_POSITION_QUANTITY_Y;
	}

	return result;
}

int dc_elmers_set_position_adjust_quantity_y(int value)
{
	char id;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_POSITION_QUANTITY_Y;

	if (value == DC_ELMERS_DEFAULT_POSITION_QUANTITY_Y)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

// Z axis.
int dc_elmers_get_position_adjust_quantity_z()
{
	char id;
	int result;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_POSITION_QUANTITY_Z;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_ELMERS_DEFAULT_POSITION_QUANTITY_Z;
	}

	return result;
}

int dc_elmers_set_position_adjust_quantity_z(int value)
{
	char id;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_POSITION_QUANTITY_Z;

	if (value == DC_ELMERS_DEFAULT_POSITION_QUANTITY_Z)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

// "positioning" controls where we get our
// base target position from (screen, a target entity, etc.).

// X axis.
int dc_elmers_get_positioning_x()
{
	char id;
	int result;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_POSITION_STATE_X;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_ELMERS_DEFAULT_POSITION_STATE_X;
	}

	return result;
}

int dc_elmers_set_positioning_x(int value)
{
	char id;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_POSITION_STATE_X;

	if (value == DC_ELMERS_DEFAULT_POSITION_STATE_X)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

// Y axis.
int dc_elmers_get_positioning_y()
{
	char id;
	int result;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_POSITION_STATE_Y;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_ELMERS_DEFAULT_POSITION_STATE_Y;
	}

	return result;
}

int dc_elmers_set_positioning_y(int value)
{
	char id;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_POSITION_STATE_Y;

	if (value == DC_ELMERS_DEFAULT_POSITION_STATE_Y)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

// z axis.
int dc_elmers_get_positioning_z()
{
	char id;
	int result;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_POSITION_STATE_Z;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_ELMERS_DEFAULT_POSITION_STATE_Z;
	}

	return result;
}

int dc_elmers_set_positioning_z(int value)
{
	char id;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_POSITION_STATE_Z;

	if (value == DC_ELMERS_DEFAULT_POSITION_STATE_Z)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

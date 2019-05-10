#include "data/scripts/dc_elmers/config.h"

#import "data/scripts/dc_elmers/instance.c"

// Bind direction control.

int dc_elmers_get_direction()
{
	char id;
	int result;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_DIRECTION;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_ELMERS_DEFAULT_DIRECTION;
	}

	return result;
}

int dc_elmers_set_direction(int value)
{
	char id;

	// Get ID.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_DIRECTION;	

	// If value is default, make sure the variable
	// is deleted.
	if (value == DC_ELMERS_DEFAULT_DIRECTION)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}
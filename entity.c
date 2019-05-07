#include "data/scripts/dc_elmers/config.h"

#import "data/scripts/dc_elmers/instance.c"


// Base entity functions will act on.
// Get
void dc_elmers_get_entity()
{
	char id;
	void result;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_ENT;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_PTR"))
	{
		result = DC_ELMERS_DEFAULT_ENT;
	}

	return result;
}

// Set
void dc_elmers_set_entity(void value)
{
	char id;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_ENT;

	if (value == DC_ELMERS_DEFAULT_ENT)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

// Target entity (if any).
// Get
void dc_elmers_get_target()
{
	char id;
	void result;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_TARGET;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_PTR"))
	{
		result = DC_ELMERS_DEFAULT_TARGET;
	}

	return result;
}

// Set
void dc_elmers_set_target(void value)
{
	char id;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_TARGET;

	if (value == DC_ELMERS_DEFAULT_TARGET)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

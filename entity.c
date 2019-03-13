#include "data/scripts/dc_elmers/config.h"

#import "data/scripts/dc_elmers/instance.c"

// Base entity functions will act on.
// Get
void dc_elmers_get_entity()
{
	int instance;
	void result;

	// Get instance.
	instance = dc_elmers_get_instance();

	result = getlocalvar(instance + DC_ELMERS_VAR_KEY_ENT);

	if (typeof(result) != openborconstant("VT_PTR"))
	{
		result = DC_ELMERS_DEFAULT_ENT;
	}

	return result;
}

// Set
void dc_elmers_set_entity(void value)
{
	int instance;

	// Get instance.
	instance = dc_elmers_get_instance();

	setlocalvar(instance + DC_ELMERS_VAR_KEY_ENT, value);
}

// Target entity (if any).
// Get
void dc_elmers_get_target()
{
	int instance;
	void result;

	// Get instance.
	instance = dc_elmers_get_instance();

	result = getlocalvar(instance + DC_ELMERS_VAR_KEY_TARGET);

	if (typeof(result) != openborconstant("VT_PTR"))
	{
		result = DC_ELMERS_DEFAULT_TARGET;
	}

	return result;
}

// Set
void dc_elmers_set_target(void value)
{
	int instance;

	// Get instance.
	instance = dc_elmers_get_instance();

	setlocalvar(instance + DC_ELMERS_VAR_KEY_TARGET, value);
}

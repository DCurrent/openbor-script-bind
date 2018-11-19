#include "data/scripts/dc_bind/config.h"

// Which instance is in use?
int dc_bind_get_instance()
{
	void result = getlocalvar(DC_BIND_VAR_KEY_INSTANCE);

	if (!result)
	{
		result = DC_BIND_DEFAULT_INSTANCE;
	}

	return result;
}

void dc_bind_set_instance(int value)
{
	setlocalvar(DC_BIND_VAR_KEY_INSTANCE, value);
}

// Base entity functions will act on.
// Get
void dc_bind_get_entity()
{
	int instance;
	void result;

	// Get instance.
	instance = dc_bind_get_instance();

	result = getlocalvar(instance + DC_BIND_VAR_KEY_ENT);

	if (typeof(result) != openborconstant("VT_PTR"))
	{
		result = DC_BIND_DEFAULT_ENT;
	}

	return result;
}

// Set
void dc_velocity_set_entity(void value)
{
	int instance;

	// Get instance.
	instance = dc_bind_get_instance();

	setlocalvar(instance + DC_BIND_VAR_KEY_ENT, value);
}

// Target entity (if any).
// Get
void dc_bind_get_target()
{
	int instance;
	void result;

	// Get instance.
	instance = dc_bind_get_instance();

	result = getlocalvar(instance + DC_BIND_VAR_KEY_TARGET);

	if (typeof(result) != openborconstant("VT_PTR"))
	{
		result = DC_BIND_DEFAULT_TARGET;
	}

	return result;
}

// Set
void dc_bind_set_target(void value)
{
	int instance;

	// Get instance.
	instance = dc_bind_get_instance();

	setlocalvar(instance + DC_BIND_VAR_KEY_TARGET, value);
}

// Offsets

// X axis.
// Get
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

// Set
int dc_bind_set_offset_x(int value)
{
	int instance;

	// Get instance.
	instance = dc_bind_get_instance();

	setlocalvar(instance + DC_BIND_VAR_KEY_OFFSET_X, value);
}

// Y axis.
// Get
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

// Set
int dc_bind_set_offset_y(int value)
{
	int instance;

	// Get instance.
	instance = dc_bind_get_instance();

	setlocalvar(instance + DC_BIND_VAR_KEY_OFFSET_Y, value);
}

// Z axis.
// Get
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

// Set
int dc_bind_set_offset_z(int value)
{
	int instance;

	// Get instance.
	instance = dc_bind_get_instance();

	setlocalvar(instance + DC_BIND_VAR_KEY_OFFSET_Z, value);
}
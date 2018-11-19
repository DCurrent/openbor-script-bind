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

#include "data/scripts/dc_bind/config.h"

#import "data/scripts/dc_bind/config.c"
#import "data/scripts/dc_bind/offsets.c"

// Caskey, Damon V.
// 2018-11-19
// 
// Move entity to target location with offset,
// of to screen position if target is NULL().
void dc_bind_apply_position()
{
	void ent;
	void target;

	int offset_x;
	int offset_y;
	int offset_z;
	int direction;

	float pos_x;
	float pos_y;
	float pos_z;

	// Get entities.
	ent = dc_bind_get_entity();
	target = dc_bind_get_target();

	// Get target position.
	pos_x = getentityproperty(target, "x");
	pos_y = getentityproperty(target, "y");
	pos_z = getentityproperty(target, "z");

	// Get offsets.
	offset_x = dc_bind_find_scaled_offset_x();
	offset_y = dc_bind_find_scaled_offset_y();
	offset_z = dc_bind_get_offset_z();
	
	// Now apply position according to offset settings.
	//if (dc_bind_get_enable_x() != DC_BIND_OFFSET_DISABLE)
	//{

		// Invert X offset if target faces left.
		direction = getentityproperty(target, "direction");

		if (direction == openborconstant("DIRECTION_LEFT"))
		{
			offset_x = -offset_x;
		}

		pos_x += offset_x;
	//}

	//if (dc_bind_get_enable_x() != DC_BIND_OFFSET_DISABLE)
	//{
		pos_y += offset_y;
	//}

	//if (dc_bind_get_enable_x() != DC_BIND_OFFSET_DISABLE)
	//{
		pos_z += offset_z;
	//}

	// Apply the position change.
	changeentityproperty(ent, "position", pos_x, pos_z, pos_y);
}
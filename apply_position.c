#include "data/scripts/dc_bind/config.h"

#import "data/scripts/dc_bind/entity.c"
#import "data/scripts/dc_bind/offset.c"
#import "data/scripts/dc_bind/positioning.c"

// Caskey, Damon V.
// 2018-11-19
// 
// Move entity to target location with offset,
// of to screen position if target is NULL().
void dc_bind_apply_position()
{
	void ent;
	void target;

	float pos_x;
	float pos_y;
	float pos_z;
	
	// Get entities.
	ent = dc_bind_get_entity();
	target = dc_bind_get_target();

	// Get position for each axis.
	pos_x = dc_bind_find_position_with_offset_x();
	pos_y = dc_bind_find_position_with_offset_y();
	pos_z = dc_bind_find_position_with_offset_z();

	// Apply the position change.
	changeentityproperty(ent, "position", pos_x, pos_z, pos_y);
}

// Caskey, Damon V.
//
// Find position to apply after offset and positioning
// settings are factored.
float dc_bind_find_position_with_offset_x()
{
	int offset;
	float position;
	void target;

	position = dc_bind_find_target_position_x();

	offset = dc_bind_find_scaled_offset_x();

	if (dc_bind_get_positioning_x() != DC_BIND_POSITIONING_DISABLED)
	{
		// If target is facing left and 
		// inverting is enabled, then
		// we invert the offset before
		// applying it to position.	
		target = dc_bind_get_target();

		if (getentityproperty(target, "direction") == openborconstant("DIRECTION_LEFT"))
		{
			if (dc_bind_get_invert_x() == DC_BIND_INVERT_X_ENABLED)
			{
				offset = -offset;
			}
		}

		position += offset;
	}

	// Return final position.
	return position;
}

// Caskey, Damon V.
//
// Find position to apply after offset and positioning
// settings are factored.
float dc_bind_find_position_with_offset_y()
{
	int offset;
	float position;

	position = dc_bind_find_target_position_y();

	offset = dc_bind_find_scaled_offset_y();

	if (dc_bind_get_positioning_x() != DC_BIND_POSITIONING_DISABLED)
	{
		position += offset;
	}

	// Return final position.
	return position;
}

// Caskey, Damon V.
//
// Find position to apply after offset and positioning
// settings are factored.
float dc_bind_find_position_with_offset_z()
{
	int offset;
	float position;

	position = dc_bind_find_target_position_z();

	offset = dc_bind_get_offset_z();

	if (dc_bind_get_positioning_x() != DC_BIND_POSITIONING_DISABLED)
	{
		position += offset;
	}

	// Return final position.
	return position;
}

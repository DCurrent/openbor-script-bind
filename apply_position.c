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

	int offset_x;
	int offset_y;
	int offset_z;

	// Get entities.
	ent = dc_bind_get_entity();
	target = dc_bind_get_target();

	// Get position for each axis.
	pos_x = dc_bind_find_target_position_x();
	pos_y = dc_bind_find_target_position_y();
	pos_z = dc_bind_find_target_position_z();

	// Get offsets.
	offset_x = dc_bind_find_scaled_offset_x();
	offset_y = dc_bind_find_scaled_offset_y();
	offset_z = dc_bind_get_offset_z();

	// If positioning is enabled on axis, apply offset
	// to position.

	// X
	if(dc_bind_get_positioning_x() != DC_BIND_POSITIONING_DISABLED)
	{
		// If target is facing left and 
		// inverting is enabled, then
		// we invert the offset before
		// applying it to position.	
		if (getentityproperty(target, "direction") == openborconstant("DIRECTION_LEFT"))
		{
			if (dc_bind_get_invert_x() == DC_BIND_INVERT_X_ENABLED)
			{
				offset_x = -offset_x;
			}
		}

		pos_x += offset_x;
	}

	// Y
	if (dc_bind_get_positioning_y() != DC_BIND_POSITIONING_DISABLED)
	{
		pos_y += offset_y;
	}

	// Z
	if (dc_bind_get_positioning_z() != DC_BIND_POSITIONING_DISABLED)
	{
		pos_z += offset_z;
	}	

	// Apply the position change.
	changeentityproperty(ent, "position", pos_x, pos_z, pos_y);
}


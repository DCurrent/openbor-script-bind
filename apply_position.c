#include "data/scripts/dc_bind/config.h"

#import "data/scripts/dc_bind/entity.c"
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

	// Get entitiy.
	ent = dc_bind_get_entity();

	// Get position for each axis.
	pos_x = dc_bind_find_target_position_x();
	pos_y = dc_bind_find_target_position_y();
	pos_z = dc_bind_find_target_position_z();

	// Apply the position change.
	changeentityproperty(ent, "position", pos_x, pos_z, pos_y);
}


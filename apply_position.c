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

	float pos_x;
	float pos_y;
	float pos_z;
	
	// Get entities.
	ent = dc_bind_get_entity();

	// Get position for each axis.
	pos_x = dc_bind_find_position_with_offset_x();
	pos_y = dc_bind_find_position_with_offset_y();
	pos_z = dc_bind_find_position_with_offset_z();

	// Apply the position change.
	changeentityproperty(ent, "position", pos_x, pos_z, pos_y);
}

// Caskey, Damon V.
// 2018-11-23
// 
// Move entity to target <offset> closer to
// or father from target.
void dc_bind_adjust_position()
{
	void ent;
	void target;

	// Offsets.
	int offset;
	int offset_check;

	// Position to apply.
	float pos_x;
	float pos_y;
	float pos_z;

	// Difference between entity position vs target.
	float diff;

	// Get entities.
	ent = dc_bind_get_entity();
	target = dc_bind_get_target();

	// Get entity location for each axis.
	pos_x = getentityproperty(ent, "x");
	pos_y = getentityproperty(ent, "y");
	pos_z = getentityproperty(ent, "z");

	// X
	if (dc_bind_get_positioning_x() != DC_BIND_POSITIONING_DISABLED)
	{
			diff = dc_bind_find_distance_to_target_x();
			offset = dc_bind_find_scaled_offset_x();

			// Difference will always be
			// positive va;ue, so we need
			// positive offset to compare.
			if (offset < 0)
			{
				offset_check = -offset;
			}
			else
			{
				offset_check = offset;
			}
				
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

			// If the diffeence exceeds offset, add offset to entity position.
			if (diff > offset_check)
			{
				pos_x += offset;
			}
	}

	// Y
	if (dc_bind_get_positioning_y() != DC_BIND_POSITIONING_DISABLED)
	{
		diff = dc_bind_find_distance_to_target_y();
		offset = dc_bind_find_scaled_offset_y();

		// Difference will always be
		// positive value, so we need
		// positive offset to compare.
		if (offset < 0)
		{
			offset_check = -offset;
		}
		else
		{
			offset_check = offset;
		}

		// If the diffeence exceeds offset, add offset to entity position.
		if (diff > offset_check)
		{
			pos_y += offset;
		}
	}

	// Z
	if (dc_bind_get_positioning_y() != DC_BIND_POSITIONING_DISABLED)
	{
		diff = dc_bind_find_distance_to_target_z();
		offset = dc_bind_get_offset_z();

		// Difference will always be
		// positive value, so we need
		// positive offset to compare.
		if (offset < 0)
		{
			offset_check = -offset;
		}
		else
		{
			offset_check = offset;
		}

		// If the diffeence exceeds offset, add offset to entity position.
		if (diff > offset_check)
		{
			pos_z += offset;
		}
	}
	
	   
	// Apply the position change.
	changeentityproperty(ent, "position", pos_x, pos_z, pos_y);
}

// Caskey, Damon V.
//
// Find distance bewtween target location and entity.
float dc_bind_find_distance_to_target_x()
{
	void ent;
	void target;
	float target_pos;
	float ent_pos;
	
	ent = dc_bind_get_entity();
	target = dc_bind_get_target();

	target_pos = dc_bind_find_target_position_x();

	ent_pos = getentityproperty(ent, "x");

	return dc_math_difference_float(ent_pos, target_pos);
}

// Caskey, Damon V.
//
// Find distance bewtween target location and entity.
float dc_bind_find_distance_to_target_y()
{
	void ent;
	void target;
	float target_pos;
	float ent_pos;

	ent = dc_bind_get_entity();
	target = dc_bind_get_target();

	target_pos = dc_bind_find_target_position_y();

	ent_pos = getentityproperty(ent, "y");

	return dc_math_difference_float(ent_pos, target_pos);
}

// Caskey, Damon V.
//
// Find distance bewtween target location and entity.
float dc_bind_find_distance_to_target_z()
{
	void ent;
	void target;
	float target_pos;
	float ent_pos;

	ent = dc_bind_get_entity();
	target = dc_bind_get_target();

	target_pos = dc_bind_find_target_position_z();

	ent_pos = getentityproperty(ent, "z");

	return dc_math_difference_float(ent_pos, target_pos);
}

// Caskey, Damon V.
// 2018-11-23
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
// 2018-11-23
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
// 2018-11-23
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

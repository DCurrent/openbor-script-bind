#include "data/scripts/dc_elmers/config.h"

#import "data/scripts/dc_elmers/entity.c"
#import "data/scripts/dc_elmers/offset.c"
#import "data/scripts/dc_elmers/positioning.c"

// Caskey, Damon V.
// 2018-11-19
// 
// Move entity to target location with offset,
// or to screen position if target is NULL().
void dc_elmers_apply_position()
{
	void ent;

	float pos_x;
	float pos_y;
	float pos_z;
	
	// Get entities.
	ent = dc_elmers_get_entity();

	// Get position for each axis.
	pos_x = dc_elmers_find_position_with_offset_x();
	pos_y = dc_elmers_find_position_with_offset_y();
	pos_z = dc_elmers_find_position_with_offset_z();

	// Apply the position change.
	changeentityproperty(ent, "position", pos_x, pos_z, pos_y);
}

// Caskey, Damon V.
// 2018-11-23
// 
// Move entity to target <offset> closer to
// or father from target.
void dc_elmers_adjust_position()
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
	ent = dc_elmers_get_entity();
	target = dc_elmers_get_target();

	// Get entity location for each axis.
	pos_x = getentityproperty(ent, "x");
	pos_y = getentityproperty(ent, "y");
	pos_z = getentityproperty(ent, "z");

	// X
	if (dc_elmers_get_positioning_x() != DC_ELMERS_MODE_DISABLED)
	{
		// If the scaled offset is less than distance to target,
		// then get a finalized offset and add it to position.
		if (dc_math_compare_unisgned_float(dc_elmers_find_distance_to_target_x(), dc_elmers_find_scaled_offset_x()))
		{
			pos_x += dc_elmers_find_offset_with_invert_x();
		}
	}

	// Y
	if (dc_elmers_get_positioning_y() != DC_ELMERS_MODE_DISABLED)
	{
		// If the scaled offset is less than distance to target,
		// then get a finalized offset and add it to position.
		if (dc_math_compare_unisgned_float(dc_elmers_find_distance_to_target_y(), dc_elmers_find_scaled_offset_y()))
		{
			pos_y += dc_elmers_find_offset_with_invert_y();
		}
	}

	// Z
	if (dc_elmers_get_positioning_y() != DC_ELMERS_MODE_DISABLED)
	{
		// If the scaled offset is less than distance to target,
		// then get a finalized offset and add it to position.
		if (dc_math_compare_unisgned_float(dc_elmers_find_distance_to_target_z(), dc_elmers_get_offset_z()))
		{
			pos_z += dc_elmers_find_offset_with_invert_z();
		}
	}
	   
	// Apply the position change.
	changeentityproperty(ent, "position", pos_x, pos_z, pos_y);
}

// Caskey, Damon V.
//
// Find distance bewtween target location and entity.
float dc_elmers_find_distance_to_target_x()
{
	void ent;
	void target;
	float target_pos;
	float ent_pos;
	
	ent = dc_elmers_get_entity();
	target = dc_elmers_get_target();

	target_pos = dc_elmers_find_target_position_x();

	ent_pos = get_entity_property(ent, "position_x");

	return dc_math_difference_float(ent_pos, target_pos);
}

// Caskey, Damon V.
//
// Find distance bewtween target location and entity.
float dc_elmers_find_distance_to_target_y()
{
	void ent;
	void target;
	float target_pos;
	float ent_pos;

	ent = dc_elmers_get_entity();
	target = dc_elmers_get_target();

	target_pos = dc_elmers_find_target_position_y();

	ent_pos = get_entity_property(ent, "position_y");

	return dc_math_difference_float(ent_pos, target_pos);
}

// Caskey, Damon V.
//
// Find distance bewtween target location and entity.
float dc_elmers_find_distance_to_target_z()
{
	void ent;
	void target;
	float target_pos;
	float ent_pos;

	ent = dc_elmers_get_entity();
	target = dc_elmers_get_target();

	target_pos = dc_elmers_find_target_position_z();

	ent_pos = get_entity_property(ent, "position_z");

	return dc_math_difference_float(ent_pos, target_pos);
}

// Caskey, Damon V.
// 2018-11-23
//
// Find position to apply after offset and positioning
// settings are factored.
float dc_elmers_find_position_with_offset_x()
{
	int direction;
	int offset;
	float position;
	void target;

	position = dc_elmers_find_target_position_x();

	offset = dc_elmers_find_scaled_offset_x();

	if (dc_elmers_get_positioning_x() != DC_ELMERS_MODE_DISABLED)
	{
		// If target is facing left and 
		// inverting is enabled, then
		// we invert the offset before
		// applying it to position.	
		target = dc_elmers_get_target();

		direction = get_entity_property(target, "position_direction");

		if (direction == openborconstant("DIRECTION_LEFT"))
		{
			if (dc_elmers_get_invert_x() == DC_ELMERS_INVERT_DIRECTION)
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
float dc_elmers_find_position_with_offset_y()
{
	int offset;
	float position;

	position = dc_elmers_find_target_position_y();

	offset = dc_elmers_find_scaled_offset_y();

	if (dc_elmers_get_positioning_x() != DC_ELMERS_MODE_DISABLED)
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
float dc_elmers_find_position_with_offset_z()
{
	int offset;
	float position;

	position = dc_elmers_find_target_position_z();

	offset = dc_elmers_get_offset_z();

	if (dc_elmers_get_positioning_x() != DC_ELMERS_MODE_DISABLED)
	{
		position += offset;
	}

	// Return final position.
	return position;
}

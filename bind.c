#include "data/scripts/dc_elmers/config.h"

#import "data/scripts/dc_elmers/entity.c"
#import "data/scripts/dc_elmers/offset.c"
#import "data/scripts/dc_elmers/palette.c"


void dc_elmers_set_bind_animation_match(int value)
{
	void ent;
	void bind;

	ent = dc_elmers_get_entity();

	// Get bind pointer.
	bind = get_entity_property(ent, "bind");

	set_bind_property(bind, "animation_match", value);

	return bind;
}

void dc_elmers_set_bind_sort_id(int value)
{
	void ent;
	void bind;

	ent = dc_elmers_get_entity();

	// Get bind pointer.
	bind = get_entity_property(ent, "bind");

	set_bind_property(bind, "sort_id", value);

	return bind;
}

void dc_elmers_set_bind_target(void value)
{
	void ent;
	void bind;

	ent = dc_elmers_get_entity();

	// Get bind pointer.
	bind = get_entity_property(ent, "bind");

	set_bind_property(bind, "target", value);

	return bind;
}

int dc_elmers_get_bind_property(char prop_name)
{
	void ent;
	void bind;

	ent = dc_elmers_get_entity();

	// Get bind pointer.
	bind = get_entity_property(ent, "bind");

	return get_bind_property(bind, prop_name);
}

void dc_elmers_set_bind_property(char prop_name, int the_value)
{
	void ent;
	void bind;

	ent = dc_elmers_get_entity();

	// Get bind pointer.
	bind = get_entity_property(ent, "bind");

	set_bind_property(bind, prop_name, the_value);

	return bind;
}

// Caskey, Damon V.
// 2019-03-13
//
// Applies calulated offsets to bind.
void dc_elmers_quick_offset_to_bind()
{
	void ent;
	void bind;

	ent = dc_elmers_get_entity();

	bind = get_entity_property(ent, "bind");

	set_bind_property(bind, "offset_x", dc_elmers_find_scaled_offset_x());
	set_bind_property(bind, "offset_y", dc_elmers_find_scaled_offset_y());
	set_bind_property(bind, "offset_z", dc_elmers_get_offset_z());

	return bind;
}

void dc_elmers_quick_bind()
{
	void ent;
	void target;
	void bind;

	ent = dc_elmers_get_entity();
	target = dc_elmers_get_target();

	bind = get_entity_property(ent, "bind");

	set_bind_property(bind, "target", target);

	set_bind_property(bind, "mode_x", openborconstant("BIND_MODE_TARGET"));
	set_bind_property(bind, "mode_y", openborconstant("BIND_MODE_TARGET"));
	set_bind_property(bind, "mode_z", openborconstant("BIND_MODE_TARGET"));

	set_bind_property(bind, "direction", openborconstant("DIRECTION_ADJUST_SAME"));
	
	dc_elmers_quick_offset_to_bind();	

	dc_elmers_apply_palette_match();

	return bind;
}

// Caskey, Damon V.
// 2019-04-25
//
// Find the first entity bound to ent and 
// return its pointer. Only call this when 
// you know there is a single entity bound to
// the entity you are checking. If there are 
// any others this function will not find them.
void dc_elmers_find_first_bound(void ent)
{
	int ent_count;
	int i;
	void ent_cursor;
	void bind;

	// Get entity count.
	ent_count = openborvariant("count_entities");

	// Loop over each entity index.
	for (i = 0; i < ent_count; i++)
	{
		// Get entity pointer.
		ent_cursor = getentity(i);

		// Now get the cursor entity's bind
		// property, and check the target against
		// our ent pointer. If they match, we've
		// found an entity bound to ent. Return it.
		bind = get_entity_property(ent_cursor, "bind");

		if (ent == get_bind_property(bind, "target"))
		{
			return ent_cursor;
		}		
	}

	// Didn't find any entity bound to 
	// our entity, so return a NULL pointer.
	return NULL();
}
#include "data/scripts/dc_elmers/config.h"


#import "data/scripts/dc_elmers/direction.c"
#import "data/scripts/dc_elmers/entity.c"
#import "data/scripts/dc_elmers/offset.c"
#import "data/scripts/dc_elmers/palette.c"
#import "data/scripts/dc_elmers/position.c"
#import "data/scripts/dc_elmers/position_config.c"

void dc_elmers_set_animation_id(int value)
{
	void ent;
	void bind;

	ent = dc_elmers_get_entity();

	// Get bind pointer.
	bind = get_entity_property(ent, "bind");

	set_bind_property(bind, "animation_id", value);

	return bind;
}

void dc_elmers_set_frame(int value)
{
	void ent;
	void bind;

	ent = dc_elmers_get_entity();

	// Get bind pointer.
	bind = get_entity_property(ent, "bind");

	set_bind_property(bind, "animation_frame", value);

	return bind;
}

void dc_elmers_set_animation_match(int value)
{
	void ent;
	void bind;

	ent = dc_elmers_get_entity();

	// Get bind pointer.
	bind = get_entity_property(ent, "bind");

	set_bind_property(bind, "animation_match", value);

	return bind;
}

void dc_elmers_set_direction(int value)
{
	void ent;
	void bind;

	ent = dc_elmers_get_entity();

	// Get bind pointer.
	bind = get_entity_property(ent, "bind");

	set_bind_property(bind, "direction", value);

	return bind;
}

void dc_elmers_set_sorting(int value)
{
	void ent;
	void bind;

	ent = dc_elmers_get_entity();

	// Get bind pointer.
	bind = get_entity_property(ent, "bind");

	set_bind_property(bind, "sort_id", value);

	return bind;
}

void dc_elmers_set_target(void value)
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

// Caskey, Damon V.
// 2019-~03
//
// Set a bind property by name to ent member.
// used to adjust bind property that does not
// have a specific function defined for it in 
// this library.
void dc_elmers_set_bind_property(void prop_name, int the_value)
{
	void ent;
	void bind;

	ent = dc_elmers_get_entity();

	// Get bind pointer.
	bind = get_entity_property(ent, "bind");

	char hp_prop = "hp_old";

	set_entity_property(ent, hp_prop, 0);

	set_bind_property(bind, prop_name, the_value);

	return bind;
}

// Caskey, Damon V.
// 2019-03-13
//
// Applies calculated offsets to bind.
void dc_elmers_quick_offset_to_bind()
{
	void target;
	void ent;
	void bind;

	ent = dc_elmers_get_entity();
	target = dc_elmers_get_target();

	bind = get_entity_property(ent, "bind");

	set_bind_property(bind, "offset_x", dc_elmers_find_scaled_offset_x(target, dc_elmers_get_offset_x()));
	set_bind_property(bind, "offset_y", dc_elmers_find_scaled_offset_y(target, dc_elmers_get_offset_y()));
	set_bind_property(bind, "offset_z", dc_elmers_get_offset_z());

	return bind;
}

// Caskey, Damon V.
//
// Apply a bind with member properties.
void dc_elmers_quick_bind()
{
	void ent;
	void target;
	void bind;

	ent = dc_elmers_get_entity();
	target = dc_elmers_get_target();

	bind = get_entity_property(ent, "bind");

	set_bind_property(bind, "target", target);

	set_bind_property(bind, "mode_x", dc_elmers_get_anchor_x());
	set_bind_property(bind, "mode_y", dc_elmers_get_anchor_y());
	set_bind_property(bind, "mode_z", dc_elmers_get_anchor_z());

	set_bind_property(bind, "direction", dc_elmers_get_direction());

	dc_elmers_quick_offset_to_bind();

	dc_elmers_apply_palette_match();

	return bind;
}

// Caskey, Damon V.
// 2019-05-09
//
// Release a bind.
void dc_elmers_quick_release()
{
	void ent;
	void bind;

	ent = dc_elmers_get_entity();

	bind = get_entity_property(ent, "bind");

	set_bind_property(bind, "target", NULL());

	dc_elmers_apply_position();

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
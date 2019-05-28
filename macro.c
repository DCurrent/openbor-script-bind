#include "data/scripts/dc_elmers/config.h"

#import "data/scripts/dc_elmers/entity.c"
#import "data/scripts/dc_elmers/offset.c"
#import "data/scripts/dc_elmers/palette.c"
#import "data/scripts/dc_elmers/bind.c"

// Caskey, Damon V.
// 2019-05-02
//
// Single function call to run a bind with settings meant for 
// overlay motion trails, like sword sweeps or fast motion 
// effects (ex. Terry Bogard's crack shoot).
//
// Entity is bound to target's exact location and direction
// with exact animation matching, sorted to appear in front
// of target.
void dc_elmers_quick_motion(void ent)
{	
	void target;
	void bind;

	// Seems redeundant, but gets default if ent is blank.
	dc_elmers_set_entity(ent);	
	ent = dc_elmers_get_entity(ent);		
	
	target = dc_elmers_get_target();

	bind = get_entity_property(ent, "bind");

	set_bind_property(bind, "target", target);

	// Bind X/Y/Z and direction to target.
	set_bind_property(bind, "mode_x", openborconstant("BIND_MODE_TARGET"));
	set_bind_property(bind, "mode_y", openborconstant("BIND_MODE_TARGET"));
	set_bind_property(bind, "mode_z", openborconstant("BIND_MODE_TARGET"));
	set_bind_property(bind, "direction", openborconstant("DIRECTION_ADJUST_SAME"));
	
	// Default sort to front.
	dc_elmers_set_bind_property("sort_id", 1);
	
	// Default bind to animation + frame and remove on no match.
	dc_elmers_set_animation_match(openborconstant("BIND_ANIMATION_TARGET")+openborconstant("BIND_ANIMATION_REMOVE")+openborconstant("BIND_ANIMATION_FRAME_TARGET")+openborconstant("BIND_ANIMATION_FRAME_REMOVE"));

	dc_elmers_quick_offset_to_bind();
	dc_elmers_apply_palette_match();

	return bind;
}


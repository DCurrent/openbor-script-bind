// Grapple functions serve as more or less a shortcut 
// wrapper for the dc_elmers library, centered around
// quickly setting up grappling moves or other types
// of strictly controlled reactions.
//
// It is important to note that in both OpenBOR's native 
// bind and the dc_elmers library "ent" binds itself to "target". 
// Essentially when doing grappling, we are sending "ent" 
// (the grappled) instructions to bind itself to a designated 
// "target" (the grappler) and assume whatever poses we need.
//
// The whole point of having a grapple subset is to avoid some 
// of this possible confusion. To do so, the grapple subset refers
// to the grappled entity (ent) as "controlled", and the grappler
// entity (target) as "controller". But under the hood, the 
// grapple subset is still using the main dc_elmers library 
// and functions and its ent/target member variables. So if you 
// choose to employ the grapple subset along with other functions 
// in or outside of the dc_elmers library, you must never assume 
// "target" means "the target of my grapple move". Otherwise 
// you'll get erroneous (albeit potentially hilarious) results.

#include	"data/scripts/dc_elmers/config.h"
#import		"data/scripts/dc_elmers/attacking.c"
#import		"data/scripts/dc_elmers/bind.c"
#import		"data/scripts/dc_elmers/blast.c"
#import		"data/scripts/dc_elmers/candamage.c"
#import		"data/scripts/dc_elmers/direction.c"
#import		"data/scripts/dc_elmers/entity.c"
#import		"data/scripts/dc_elmers/instance.c"
#import		"data/scripts/dc_elmers/offset.c"

// Caskey, Damon V.
// 2019-05-13
//
// Shortcut to set up default grappling.
//
// - Populate target (grappler), and entity (grappled).
// - Place entity in default blast state so its attack
// box can hit others and not hit target.
// - Disable the native grappling system so it won't
// interfere with sorting or certain bind poses, and
// lets engine know its own job is done.
// - Place entity in reaction animation ready for
// posing by frame.
void dc_elmers_initialize_grapple()
{	
	void target;
	void ent;
	
	// Reset this instance of elmers so we don't have any
	// possible conflicts from previous uses.
	dc_elmers_reset_instance();

	// Get target, and then get target's opponent. We set that
	// the entity we are acting on. As in, the one binding itself
	// to the grapple controller (target).
	target = dc_elmers_get_target();		
	ent = get_entity_property(target, "opponent");

	dc_elmers_set_entity(ent);
	
	// Put us into a thrown state.
	dc_elmers_apply_blast();

	// Break openbor native grab system link if it exists. If we 
	// don't do this, the native grab system overrides binding 
	// sort ID.
	dc_elmers_break_native_link();

	// Set binding to match a manually defined animation ID and
	// animation frame. Then set the manual animation ID property
	// to our default reaction animation. Later we set the frame
	// property to apply whatever specific pose we want.
	dc_elmers_set_animation_match(openborconstant("BIND_ANIMATION_DEFINED") + openborconstant("BIND_ANIMATION_FRAME_DEFINED"));
	dc_elmers_set_animation_id(DC_ELMERS_REACT_ANIMATION);

	// Disable can damage property so we can't hit
	// the grapple controller. Make sure to record
	// the value first as can damage old so we can 
	// restore it when we are finished.
	dc_elmers_set_can_damage_old(getentityproperty(ent, "candamage"));
	dc_elmers_set_can_damage(DC_ELMERS_CAN_DAMAGE_NONE);
	dc_elmers_apply_can_damage();
}

// Caskey, Damon V.
// 2019-05-28
//
// Executes the current grapple/bind settings.
void dc_elmers_apply_grapple()
{	
	dc_elmers_apply_blast();
	dc_elmers_apply_can_damage();

	// Apply bind settings.
	dc_elmers_quick_bind();
}

// Caskey, Damon V.
// 2019-05-28
//
// Release grappled entity and restore relevant
// properties. Return the entity pointer so
// other libraries (like damage) can do their work.
void dc_elmers_end_grapple()
{
	void ent;

	ent = dc_elmers_get_entity();

	// Restore our previous candamage property
	// before the grapple started.
	dc_elmers_apply_can_damage_old();

	// Makes final position adjustment and ends bind.
	dc_elmers_quick_release();

	// Restore old can damage.
	dc_elmers_apply_can_damage_old();

	// Reset the instance. This is both to
	// save memory and ensure we
	// don't have conflicts later.
	dc_elmers_reset_instance();

	// Return our entity pointer.
	return ent;
}

// Caskey, Damon V.
// 2019-05-13
//
// Release target's native grab (presumably from holding us). 
// Based on native internal ent_unlink() function.
void dc_elmers_break_native_link()
{
	void target = dc_elmers_get_target();
	void link;

	link = get_entity_property(target, "link");

	if (link)
	{
		set_entity_property(link, "link", NULL());
		set_entity_property(link, "grab_target", NULL());
	}

	set_entity_property(target, "link", NULL());
	set_entity_property(target, "grab_target", NULL());
}

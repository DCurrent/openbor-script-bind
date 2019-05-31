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
#import		"data/scripts/dc_elmers/tag.c"

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
	dc_elmers_end_native_link();

	// Set binding to match a manually defined animation ID and
	// animation frame. Then set the manual animation ID property
	// to our default reaction animation. Later we set the frame
	// property to apply whatever specific pose we want.
	dc_elmers_set_animation_match(openborconstant("BIND_ANIMATION_DEFINED") + openborconstant("BIND_ANIMATION_FRAME_DEFINED"));
	dc_elmers_set_animation_id(DC_ELMERS_REACT_ANIMATION);

	// Disable can damage property so we can't hit
	// the grapple controller. We need to restore it
	// when finished, and possibly with another script
	// event, so we'll record the old value into bind
	// tag property first.
	dc_elmers_set_tag(getentityproperty(ent, "candamage"));
	dc_elmers_apply_tag();
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

	// Restore the candamage value we stored 
	// in bind tag.
	dc_elmers_set_can_damage(dc_elmers_set_tag_from_property());
	dc_elmers_apply_can_damage();

	// Reset the instance. This is both to
	// save memory and ensure we
	// don't have conflicts later.
	dc_elmers_reset_instance();

	// Return our entity pointer.
	return ent;
}

// Caskey, Damon V.
// 2019-05-31 
// 
// Establish a native grab with following exceptions:
// - No location adjustment. 
// - No direction adjustment.
void dc_elmers_apply_grab()
{
	void ent;
	void target;
	int elapsed_time;

	float pos_x;
	float pos_z;	
	int direction;

	// Entity is us. Target is the entity grabbing us.
	ent = dc_elmers_get_entity();
	target = dc_elmers_get_target();

	// Dograb() takes care of the gazillion flags
	// and actions needed for starting a grapple in 
	// one call, and because its native code can do 
	// the work much faster than we could manage with 
	// script. But it also relocates us and switches 
	// directions, which in this case we don't want.
	//
	// Let's get that information here so we can 
	// restore it soon as the dograb function is complete.
	pos_x = get_entity_property(ent, "position_x");
	pos_z = get_entity_property(ent, "position_z");	
	direction = get_entity_property(ent, "position_direction");

	// Target grabs us!
	dograb(target, ent);

	// Now restore our position and direction.
	set_entity_property(ent, "position_x", pos_x);
	set_entity_property(ent, "position_x", pos_z);
	set_entity_property(ent, "position_direction", direction);
}

// Caskey, Damon V.
// 2019-05-31
//
// Connect target's native grab to us. Similar to dograb, but
// we're only setting the record keeping, not the alignment,
// direction, takeaction, etc.
void dc_elmers_apply_native_link()
{
	void target = dc_elmers_get_target();
	void ent = dc_elmers_get_entity();
	void link;

	link = get_entity_property(target, "link");

	// Target grabs us.
	set_entity_property(target, "grab_target", ent);
	
	// Link target and us together.
	set_entity_property(ent, "link", target);
	set_entity_property(target, "link", ent);
}

// Caskey, Damon V.
// 2019-05-13
//
// Release target's native grab (presumably from holding us). 
// Based on native internal ent_unlink() function.
void dc_elmers_end_native_link()
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

// Caskey, Damon V.
// 2018-08-27
//
// Release all of the target entity's grappled
// targets. Call this when the target is damaged
// or gets interrupted some way before it can finish
// a grapple move.
int dc_elmers_disrupt_grapple()
{
	void target;
	int i;					// Loop cursor.
	int entity_count;		// Entites on screen.
	int entity_exists;		// Entity cursor is not a dangling pointer.
	void entity_cursor;		// Entity in loop.
	int drop;				// Falling state.
	void bind;				// Binding property.
	void bind_target;		// 
	int animation_current;
	int release_count;		// How many entities have been released?

	target = dc_elmers_get_target();

	release_count = 0;
	entity_count = openborvariant("count_entities");

	// Loop through entity collection.
	for (i = 0; i < entity_count; i++)
	{
		// Get entity cursor for this loop increment.
		entity_cursor = getentity(i);

		// Make sure we got a valid target pointer.
		if (!entity_cursor)
		{
			continue;
		}

		// Make sure the entity exists in play. We perform this
		// check because it's possible for an entity to be
		// removed but its pointer is still valid.
		entity_exists = getentityproperty(entity_cursor, "exists");

		if (!entity_exists)
		{
			continue;
		}

		// In a grappled pose?
		animation_current = get_entity_property(entity_cursor, "animation_id");

		if (animation_current != DC_ELMERS_REACT_ANIMATION)
		{
			continue;
		}

		// Bound to target?
		bind = get_entity_property(entity_cursor, "bind");
		bind_target = get_bind_property(bind, "target");

		if (bind_target != target)
		{
			continue;
		}

		// Release bind and knock entity down to ensure
		// it is "reset".
		set_bind_property(bind, "target", NULL());
		damageentity(entity_cursor, target, DC_ELMERS_RESET_ATTACK_FORCE, DC_ELMERS_RESET_ATTACK_DROP, DC_ELMERS_RESET_ATTACK_TYPE);

		// Increment reelase count;
		release_count++;
	}

	return release_count;
}

// Caskey, Damon V.
// 2018-11-01
//
// Verify conditions for switching sides and do it if possible.
void dc_elmers_side_switch()
{
	void target;

	target = dc_elmers_get_target();	

	performattack(target, DC_ELMERS_SWITCH_TO_BACK);

	// Must have a switch to back.
	if (!getentityproperty(target, "animvalid", DC_ELMERS_SWITCH_TO_BACK))
	{
		return 0;
	}

	if (get_entity_property(target, "animation_id") == openborconstant("ANI_GRAB"))
	{
		dc_disney_perform_attack(DC_ELMERS_SWITCH_TO_BACK);
	}
	else if (get_entity_property(target, "animation_id") == DC_ELMERS_GRAB_BACK)
	{
		dc_disney_perform_attack(DC_ELMERS_SWITCH_TO_FRONT);
	}	
}
#include "data/scripts/dc_elmers/config.h"

#import "data/scripts/dc_elmers/entity.c"
// Get
int dc_elmers_get_palette_match()
{
	char id;
	void result;

	// Get id from key and instance.
	id = dc_elmers_get_instance() + DC_ELMERS_VAR_KEY_PALETTE_MATCH;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_ELMERS_DEFAULT_PALETTE_MATCH;
	}

	return result;
}

// Set
int dc_elmers_set_palette_match(void value)
{
	char id;

	// Get id from key and instance.
	id = dc_elmers_get_instance() + DC_ELMERS_VAR_KEY_PALETTE_MATCH;

	if (value == DC_ELMERS_DEFAULT_PALETTE_MATCH)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

// Caskey, Damon V.
// 2019-03-27
//
// Apply palette according to settings.
void dc_elmers_apply_palette_match()
{
	int match;

	void target;
	void entity;

	
	target = dc_elmers_get_target();
	entity = dc_elmers_get_entity();

	if (!target || !entity)
	{
		return;
	}

	match = dc_elmers_get_palette_match();

	switch (match)
	{
		default:
		case DC_ELMERS_PALETTE_MATCH_NONE:
	
			return;
			break;
	
		case DC_ELMERS_PALETTE_MATCH_INDEX:

			// Nothing right now.
			break;

		case DC_ELMERS_PALETTE_MATCH_TABLE:

			void drawmethod = get_entity_property(target, "drawmethod");

			set_drawmethod_property(drawmethod, "enable", 1);

			//set_drawmethod_property(drawmethod, "alpha", openborconstant("BLEND_MODE_AVERAGE"));
			//set_drawmethod_property(drawmethod, "background_transparency", 1);
			//set_drawmethod_property(drawmethod, "channel_red", 255);
			//set_drawmethod_property(drawmethod, "channel_blue", 0);
			//set_drawmethod_property(drawmethod, "channel_green", 0);

			float pos_x = get_entity_property(target, "position_x");
			float pos_y = get_entity_property(target, "position_y");
			float pos_z = get_entity_property(target, "position_z");
			int scroll_x = openborvariant("xpos");
			int scroll_y = openborvariant("ypos");

			set_drawmethod_property(drawmethod, "clip_position_x", -76);
			set_drawmethod_property(drawmethod, "clip_position_y", -155);
			set_drawmethod_property(drawmethod, "clip_size_x", 85);
			set_drawmethod_property(drawmethod, "clip_size_y", 90);
			//set_drawmethod_property(drawmethod, "fill_color", rgbcolor(255, 0, 255));
			//set_drawmethod_property(drawmethod, "fill_color", rgbcolor(0, 255, 255));
			//set_drawmethod_property(drawmethod, "repeat_x", 2);
			//set_drawmethod_property(drawmethod, "rotate", 315);
			//set_drawmethod_property(drawmethod, "rotate_flip", 1);
			//set_drawmethod_property(drawmethod, "shift_x", 180);			
			//set_drawmethod_property(drawmethod, "scale_x", 256);
			//set_drawmethod_property(drawmethod, "scale_y", 512);
			//set_drawmethod_property(drawmethod, "tint_color", rgbcolor(0, 255, 255));
			//set_drawmethod_property(drawmethod, "tint_mode", openborconstant("BLEND_MODE_ALPHA_NEGATIVE"));

			//changedrawmethod(target, "tintmode", 1);
			//changedrawmethod(target, "tintcolor", rgbcolor(0, 255, 255));
						

			log("\n table:" + drawmethod);
			log("\n  get_entity_property:" + get_entity_property(entity, "drawmethod"));

			set_entity_property(entity, "drawmethod", drawmethod);

			log("\n  get_drawmethod_property:" + get_drawmethod_property(drawmethod, "scale_x"));

			break;
	}
}
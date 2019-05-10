if (e->link)
{
	e->link->link = NULL;
	e->link->grabbing = NULL;
}
e->link = NULL;
e->grabbing = NULL;

// Caskey, Damon V.
//
// Unlink entities. Performs same function as native unlink.
void dc_elmers_break_native_link()
{
	ent = dc_elmers_get_entity();
	target = dc_elmers_get_target();

	void link;

	link = get_entity_proerty(target, "link")

	if (link)
	{
		set_entity_property(link, "link", NULL());
		set_entity_property(link, "grab_target", NULL());
	}

	set_entity_property(target, "link", NULL());
	set - entity_property(target, "grab_target", NULL());
}
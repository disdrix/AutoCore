// =============================================================================
// RETIRED scaffold name — do not use as product symbol
// -----------------------------------------------------------------------------
// Former: Mission_Mission_Object_00847240
// Reason: String-weak rename from a single type-4 label ("Mission Object").
//         Function is a full item tooltip type/meta line builder covering many
//         type classes (weapon, armor, craft, gadget, …), not mission-only.
// Canonical: UI_ItemTooltip_AppendTypeMetaLines_Inferred
// VA:        0x00847240 / aa_00847240
// Twin:      FUN_00847240.cpp
// Named:     UI_ItemTooltip_AppendTypeMetaLines_Inferred.cpp
// Retired:   R11-029 2026-08-05
// =============================================================================

// Forward to named surface for any stale include.
// Prefer the named clean unit above.

int UI_ItemTooltip_AppendTypeMetaLines_Inferred(int *item, char showMeta);

int Mission_Mission_Object_00847240(int *param_1, char param_2)
{
    // RETIRED alias — body lives in FUN_00847240.cpp / named unit.
    return UI_ItemTooltip_AppendTypeMetaLines_Inferred(param_1, param_2);
}

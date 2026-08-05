// =============================================================================
// CVOGObjectiveRequirement_Deliver_OnInventoryEvent_Inferred  (FUN_00611290)
// Address: 0x00611290  Stable: aa_00611290
// Cargo readiness on inventory event type 4 → progress float 1.0
// =============================================================================

#include <cstdint>

extern float g_flOne;
extern int __thiscall InventoryGrid_CountItemsByCbid(void* grid, int cbid, char f);
extern void CVOGReaction_BuildTextParams(void* buf);

std::uint32_t __thiscall CVOGObjectiveRequirement_Deliver_OnInventoryEvent(
    int req, int character, int* progressSlots, int eventType,
    float eventItemId, unsigned, unsigned, int npcOrObj)
{
    if (eventType != 4) {
        return 0;
    }
    int vehicle = *(int*)(character + 0x250);
    if (vehicle == 0 || *(int*)(vehicle + 0x2b0) == 0) {
        return 0;
    }
    int count = InventoryGrid_CountItemsByCbid(
        (void*)*(int*)(vehicle + 0x2b0), *(int*)(req + 0x10), 0);
    // Raw: (count >= need) || (flag +0x23 == 0) — zero bypasses quantity gate
    if (((int)eventItemId == *(int*)(req + 0x18)) &&
        ((*(int*)(req + 0x14) <= count) || (*(char*)(req + 0x23) == '\0')))
    {
        progressSlots[*(unsigned char*)(req + 8) + 1] = (int)g_flOne;
        if (*(char*)(req + 0x22) != '\0') {
            // Toast params built from character COID + object TFID (raw)
            (void)npcOrObj;
            // CVOGReaction_BuildTextParams(...);
        }
        return 1;
    }
    return 0;
}

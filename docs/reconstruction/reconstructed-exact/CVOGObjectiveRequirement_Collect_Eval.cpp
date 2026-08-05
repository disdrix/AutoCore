// =============================================================================
// CVOGObjectiveRequirement_Collect_Eval  (was FUN_00611940)
// -----------------------------------------------------------------------------
// Address:  0x00611940
// Stable:   aa_00611940
// System:   missions-progression
//
// Progress fraction from live cargo inventory (not objective-state slot floats):
//   cargo = character+0x250 → InventoryGrid at +0x2b0
//   count = InventoryGrid_CountItemsByCbid(cargo, req+0x10 /*CBID*/, 0 /*includeBroken*/)
//   return min(1.0f, count / (float)(req+0x14 /*NumToCollect*/))
//
// ABI (body sealed 2026-07-29 residual a_00611940.md + dual A/B strengthen):
//   __thiscall; ECX = requirement; stack0 = character; stack1 unread (family
//   Eval formal — UseItem/Kill use it for slot-float state); RET 8.
//   Count CALLs @ 0x00611972 and 0x006119a3 → InventoryGrid_CountItemsByCbid
//   (0x005711c0); second CALL only when ratio < 1.0 (COMISS/JBE; equality
//   completes). SSE ratio math; x87 FLD return (decompiler float10).
//
// Cross-link: inventory-transfer cargo grid is the same type-1 grid used by
// DropResponse place path. Broken stacks excluded (includeBroken=0).
// Server absolute Collect progress remains S2C 0x2071 (separate path).
// =============================================================================

#include <cstdint>

extern float g_flOne;   // 0x00a0f2a0 = 1.0f
extern float g_flZero;  // 0x00a0f518 = 0.0f
extern int __thiscall InventoryGrid_CountItemsByCbid(void* grid, int cbid, char includeBroken);

// Returns float10 in decompiler; model as float progress 0..1
// objState: present in shared Eval ABI (RET 8); unread by Collect.
float __thiscall CVOGObjectiveRequirement_Collect_Eval(
    void* req, int character, void* /*objState*/)
{
    int numToCollect = *(int*)((int)req + 0x14);
    if (numToCollect == 0) {
        return g_flOne;
    }
    int vehicle = *(int*)(character + 0x250);
    if (vehicle == 0 || *(int*)(vehicle + 0x2b0) == 0) {
        return g_flZero;
    }
    void* cargo = (void*)*(int*)(vehicle + 0x2b0);
    int itemCbid = *(int*)((int)req + 0x10);

    // First walk: compare against 1.0 (image always does this when cargo present)
    int count = InventoryGrid_CountItemsByCbid(cargo, itemCbid, /*includeBroken*/ 0);
    float frac = (float)count / (float)numToCollect;
    if (frac >= g_flOne) {
        return g_flOne;
    }
    // Second walk: incomplete path re-counts (real CALL @ 0x006119a3)
    count = InventoryGrid_CountItemsByCbid(cargo, itemCbid, /*includeBroken*/ 0);
    return (float)count / (float)numToCollect;
}

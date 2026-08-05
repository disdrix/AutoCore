// =============================================================================
// CVOGObjectiveRequirement_Deliver_CargoReady_Inferred  (FUN_00610f20)
// Address: 0x00610f20  Stable: aa_00610f20
// =============================================================================

#include <cstdint>

extern int __thiscall InventoryGrid_CountItemsByCbid(void* grid, int cbid, char f);

std::uint32_t __thiscall CVOGObjectiveRequirement_Deliver_CargoReady(
    int req, int matchKey, int character)
{
    if (*(int*)(req + 0x18) != matchKey) {
        return 0;
    }
    int vehicle = *(int*)(character + 0x250);
    if (vehicle == 0 || *(int*)(vehicle + 0x2b0) == 0) {
        return 0;
    }
    int count = InventoryGrid_CountItemsByCbid(
        (void*)*(int*)(vehicle + 0x2b0), *(int*)(req + 0x10), 0);
    // Raw: ready if count >= need OR *(req+0x23) == 0 (default ctor sets +0x23=1 → enforce count)
    if ((*(int*)(req + 0x14) <= count) || (*(char*)(req + 0x23) == '\0')) {
        return 1;
    }
    return 0;
}

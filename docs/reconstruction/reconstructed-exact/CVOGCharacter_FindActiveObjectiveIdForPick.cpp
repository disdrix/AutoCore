// =============================================================================
// CVOGCharacter_FindActiveObjectiveIdForPick  (was FUN_005245d0)
// Address:  0x005245d0
// Stable:   aa_005245d0
// System:   interaction-activation
//
// Walk active objectives (char+0x548). First whose evaluators match the world
// object via FUN_0059da10 (evaluator vtbl+0x44) → return objective id at
// instance+0x10. Sibling of CVOGCharacter_FindActiveObjectiveIdForInteract
// (0x00524520 / FUN_0059d9c0 / vtbl+0x40).
//
// Callers: pick/hover — Client_InteractClickPickTarget (OR with sibling before
// IfInteractable); FUN_00925820 (select-only on match); FUN_00490070 pick filter.
// =============================================================================

#include <cstdint>

// thiscall on objective; argA/argB = (character, worldObject) from walker.
// Iterates [obj+0x158, obj+0x15c); calls evaluator vtable+0x44.
extern char __thiscall FUN_0059da10(void* objective, void* character, void* worldObject);
extern void FUN_007a4480(int, const char*, ...);

std::uint32_t __thiscall CVOGCharacter_FindActiveObjectiveIdForPick(
    int character, int worldObject)
{
    if (worldObject == 0) {
        return 0;
    }
    int hash = *(int*)(character + 0x548);
    std::uint32_t result = 0;
    int node = 0;

    if (*(char*)(hash + 0x1d) != '\0') {
        FUN_007a4480(0, "HashError:TraversalLock, already locked for traversal");
        FUN_007a4480(0, "VOG_DEBUG_STOP");
    }
    *(char*)(hash + 0x1d) = 1;

    for (;;) {
        hash = *(int*)(character + 0x548);
        if (*(char*)(hash + 0x1d) == '\0') {
            FUN_007a4480(0, "HashError:TraverseToNext, not locked for traversal");
            FUN_007a4480(0, "VOG_DEBUG_STOP");
        }
        if (node == 0) {
            node = *(int*)(hash + 0x14);
        } else {
            node = *(int*)(node + 0x14);
        }
        int objInst = (node == 0) ? 0 : *(int*)(node + 8);
        if (objInst == 0) {
            break;
        }
        // Decompiler: FUN_0059da10(param_1, param_2) with this=objective in ECX
        char match = FUN_0059da10((void*)objInst, (void*)character, (void*)worldObject);
        if (match != '\0') {
            result = *(std::uint32_t*)(objInst + 0x10);
            break;
        }
    }

    *(char*)(*(int*)(character + 0x548) + 0x1d) = 0;
    return result;
}

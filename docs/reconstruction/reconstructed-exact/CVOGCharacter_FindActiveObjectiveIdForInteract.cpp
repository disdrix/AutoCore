// =============================================================================
// CVOGCharacter_FindActiveObjectiveIdForInteract  (was FUN_00524520)
// Address:  0x00524520
// Stable:   aa_00524520
// System:   interaction-activation
//
// Walk active objectives (char+0x548). First whose evaluators MatchTarget the
// world object (FUN_0059d9c0 / vtbl+0x40(char, world)) → objective id @+0x10.
// Used by Client_SendUseObject_IfInteractable as objective id (not pure bool).
//
// Byte-sealed 2026-07-29:
//   thiscall ECX=character (saved EBX), stack world, ret 4
//   helper: push world; push character; ECX=objInst; call 0059d9c0 (ret 8)
//   IfInteractable: ECX=*(client+0xE98); packet+0x18 = return EAX
// =============================================================================

#include <cstdint>

// Objective* this, Character* ch, Object* world — ret 8
extern char __thiscall FUN_0059d9c0(void* objective, void* character, void* worldObject);
extern void FUN_007a4480(int, const char*, ...);

std::uint32_t __thiscall CVOGCharacter_FindActiveObjectiveIdForInteract(
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
        // Bytes @ 0x005245a2: push world; push character; mov ecx, objInst; call
        char match = FUN_0059d9c0((void*)objInst, (void*)character, (void*)worldObject);
        if (match != '\0') {
            result = *(std::uint32_t*)(objInst + 0x10);
            break;
        }
    }

    *(char*)(*(int*)(character + 0x548) + 0x1d) = 0;
    return result;
}

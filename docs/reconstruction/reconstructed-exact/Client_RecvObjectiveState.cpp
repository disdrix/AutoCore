// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×4, while×1, return×1.
//  - Notable callees: Client_RecvObjectiveState×2, CNDHash_LookupByKey, FUN_0092ce90.
//  - Return sites: 1.

// =============================================================================
// Client_RecvObjectiveState
// -----------------------------------------------------------------------------
// Purpose:  S2C handler for opcode **0x2071** (ObjectiveState) - progress only.
//           Lookup pending-objective state by id at packet+0x14 in character
//           pending hash (char+0x55c via client+0xe98), write 4 IEEE float slot
//           values from packet +0x18..+0x24 into state[1..4], then for each
//           requirement whose bit is set in the bitmask at packet+0x10 call
//           vtable+0x20 — shared FUN_00637de0 progress toast (not event Action/
//           Eval/SlotAction; not complete).
//           Does **NOT** call CompleteObjective (that is 0x2070 force-complete).
//           Does **NOT** call EvaluatePendingObjectives (residual 2026-07-29).
//
// Address:  0x00809460  (autoassault.exe, image base 0x400000)
// Stable:   aa_00809460
// System:   missions-progression
//
// Convention: packet pointer in stack arg; client/global object in EAX (decompiler
//             `in_EAX`) - typical for registered packet handlers.
//
// Packet layout (opcode at +0, absolute):
//   +0x10  progress bitmask (u32) - bit N selects requirement N toast (vtbl+0x20)
//   +0x14  objective id (u32) - hash key into pending objectives
//   +0x18  slot0 → state[1]  (IEEE float bits; absolute or 0..1 by req type)
//   +0x1c  slot1 → state[2]
//   +0x20  slot2 → state[3]
//   +0x24  slot3 → state[4]
//
// Exactness: Control flow mirrors raw Ghidra decompile (2026-07-23 batch;
// re-checked residual 2026-07-29 — no CF change). Action identity sealed:
// vtbl+0x20 == FUN_00637de0 across sampled requirement classes.
// Dual reviews:
//   reviews/A_aa_00809460_Client_RecvObjectiveState.md
//   reviews/B_aa_00809460_Client_RecvObjectiveState.md
// Dual residual: reviews/a_00809460.md
// =============================================================================

#include <cstdint>

void* CNDHash_LookupByKey(void* hash, unsigned key);
// Client_RefreshMissionRelatedUi (role; original unknown) — refreshes
// client+0x107c / +0x10b8 mission UI panels; does not EvaluatePending.
void  FUN_0092ce90();

void Client_RecvObjectiveState(int pPacket)
{
    int* piUi;
    int iObjDef;
    char cUi;
    int in_EAX; // client / game context (decompiler register param)
    int* pState;
    unsigned uEval;

    // Require local character at client+0xe98 and a pending-objective hit
    if ((*(int*)(in_EAX + 0xe98) != 0) &&
        (pState = (int*)CNDHash_LookupByKey(
             *(void**)(*(int*)(in_EAX + 0xe98) + 0x55c),
             *(unsigned*)(pPacket + 0x14)),
         pState != (int*)0x0))
    {
        // Write 4 progress slots (IEEE float bit patterns) into runtime node [1..4]
        // (state[0] remains objective def pointer from AddActiveObjective)
        pState[1] = *(int*)(pPacket + 0x18);
        pState[2] = *(int*)(pPacket + 0x1c);
        pState[3] = *(int*)(pPacket + 0x20);
        pState[4] = *(int*)(pPacket + 0x24);

        // Optional mission UI root at client+0x107c (same as HideMissionDialogIfOpen)
        if ((*(int*)(in_EAX + 0x107c) != 0) &&
            ((cUi = (**(char (**)())(**(int**)(in_EAX + 0x107c) + 0x3d8))(),
              cUi != '\0' &&
              (piUi = *(int**)(in_EAX + 0x107c), piUi != (int*)0x0))))
        {
            (**(void (**)())(*piUi + 0x448))();
            (**(void (**)())(*piUi + 0x34c))();
        }

        // Bitmask-selected requirement toast: vtable+0x20 == shared FUN_00637de0
        // (progress string via +0x1c→SlotAction text + FUN_0040c5c0). Not complete.
        uEval = 0;
        while (true) {
            iObjDef = *pState; // objective definition*
            if ((*(int*)(iObjDef + 0x158) == 0) ||
                ((unsigned)(*(int*)(iObjDef + 0x15c) - *(int*)(iObjDef + 0x158) >> 2) <=
                 uEval))
            {
                break;
            }
            if ((*(unsigned*)(pPacket + 0x10) & (1u << ((std::uint8_t)uEval & 0x1f))) != 0) {
                // Shared progress toast Action(character, stateNode) — FUN_00637de0
                (**(void (**)(std::uint32_t, int*))(
                    **(int**)(*(int*)(iObjDef + 0x158) + uEval * 4) + 0x20))(
                    *(std::uint32_t*)(in_EAX + 0xe98), pState);
            }
            uEval = uEval + 1;
        }

        FUN_0092ce90(); // Client_RefreshMissionRelatedUi — not EvaluatePending
        // Mark mission-tracker UI dirty: *(client+0x4d0)+4 = 1
        *(std::uint8_t*)(*(int*)(in_EAX + 0x4d0) + 4) = 1;
    }
    return;
}

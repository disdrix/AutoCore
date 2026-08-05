// READABILITY (auto CF):
//  - Body size: ~154 non-empty decompiler lines.
//  - Control keywords: if×19, for×8, goto×2, return×2, while×1.
//  - Notable callees: FUN_007a4480×4, FUN_0059d880×2 (CompleteCount), FUN_004073a0,
//    Client_SendLogicUiPacket, CVOGReaction_CompleteObjective, FUN_005307e0, operator_delete.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP";
//    "HashError:TraverseToNext, not locked for traversal".
//  - Return sites: 2.

// =============================================================================
// CVOGCharacter_EvaluatePendingObjectives
// -----------------------------------------------------------------------------
// Purpose:  Iterate the character's pending-objectives hash (char+0x55c), run
//           each objective's evaluator callbacks, collect objectives that meet
//           CompleteCount (or all-eval-true), then CompleteObjective each id.
//
// Address:  0x00534920  (autoassault.exe, image base 0x400000)
// Stable:   aa_00534920
// System:   missions-progression
//
// Convention: MSVC __thiscall
//   this = CVOGCharacter*
//   p1..p4 + hidden stack arg = context forwarded to evaluator precheck (+0x4)
//
// Algorithm (body-backed; dual residual 2026-07-29):
//   1. Enter only if continent flags: +0x7e != 0 AND +0xf6 == 0
//      (raw plate "bail if set" is wrong for +0x7e)
//   2. Lock pending hash (this+0x55c), traversal byte +0x1d
//   3. Per pending SLOT (node+8): def = *slot  (NOT bare def* like active +0x548)
//        for each evaluator in [def+0x158, def+0x15c):
//          vtable+0x4  precheck(char, slot, ctx) — does NOT skip eval
//          vtable+0x20 action + LogicUI type 4 when precheck & mission/obj flags
//          vtable+0x8  eval(char, slot) → successCount++; sticky allTrue
//        CompleteCount = FUN_0059d880(def) = *(def+0x164)  (dual CALL real in asm)
//          (sealed: objective XML dump writes <CompleteCount> via same getter)
//        twin of CompleteObjective force=0: (count!=0 && count<=succ) || allTrue
//        if that && def+0x138 == 0: push objective id (def+0x10)
//   4. Unlock; CompleteObjective(this, id, -1, -1, force=0) for each
//   5. FUN_005307e0(this) — always; zeros +0x564 vec + +0xd6c/+0xd68 even if empty
//   6. free id vector
//
// Callers (exactly 7): AddCredits(5), CompleteObjective final(6), combat(7),
//   FUN_00535c60(9), FUN_00535ed0(10), Patrol Fn3/Fn6(0xb).
// Exactness: Control flow mirrors raw Ghidra decompile; residuals sealed.
// =============================================================================

#include <cstdint>

extern void* ExceptionList;
void FUN_007a4480(int level, const char* fmt, ...);
void Client_SendLogicUiPacket(void* packet);
// Objective CompleteCount getter: return *(pObjectiveDef + 0x164)
int  FUN_0059d880(void* pObjectiveDef);
void FUN_004073a0(int* end, int count, int* value); // vector push_back grow
// __thiscall character this; force trailing char/bool (0 here)
void __thiscall CVOGReaction_CompleteObjective(
    void* thisCharacter,
    std::uint32_t objectiveId,
    std::uint32_t tfidLo,
    std::uint32_t tfidHi,
    char forceComplete);
// Post-eval: drain character +0x564 mission-end queue (may no-op if empty)
void __fastcall FUN_005307e0(void* thisCharacter);
void operator_delete(void* p);

void __thiscall CVOGCharacter_EvaluatePendingObjectives(
    void* thisCharacter,
    std::uint32_t p1,
    std::uint32_t p2,
    std::uint32_t p3,
    std::uint32_t p4)
{
    int* piCollectedEnd;
    char cPre;
    int iTmp;
    char cAllTrue;
    int* piObjNode;
    void* pvCollectedBegin;
    unsigned uEval;
    std::uint32_t in_stack_00000014; // 5th context dword (decompiler)
    int local_successCount;          // local_15c
    int local_node;                  // local_158
    void* local_vecBegin;            // local_150
    int* local_vecEnd;               // local_14c
    int local_vecCap;                // local_148
    std::uint32_t uStack_logicType;  // uStack_144 = 4 for LogicUI
    void* local_excPrev;             // local_c
    std::uint8_t* puStack_8;
    std::uint32_t local_excGuard;    // local_4
    void* pObjDef;
    int completeCount;

    // SEH frame
    puStack_8       = (std::uint8_t*)&local_excGuard; // LAB_009a3ccb in raw
    (void)puStack_8;
    local_excPrev   = ExceptionList;
    iTmp =
        *(int*)(*(int*)(*(int*)((int)thisCharacter + 4) + 4) + 0xa8 + (int)thisCharacter);

    local_node = 0;
    // Gate: continent flag +0x7e set AND +0xf6 clear (not "bail if either set")
    if ((*(char*)(iTmp + 0x7e) != '\0') && (*(char*)(iTmp + 0xf6) == '\0')) {
        local_vecBegin = (void*)0x0;
        local_vecEnd   = (int*)0x0;
        local_vecCap   = 0;
        iTmp           = *(int*)((int)thisCharacter + 0x55c); // pending hash
        local_excGuard = 0;
        ExceptionList  = &local_excPrev;

        if (*(char*)(iTmp + 0x1d) != '\0') {
            FUN_007a4480(0, "HashError:TraversalLock, already locked for traversal");
            FUN_007a4480(0, "VOG_DEBUG_STOP");
        }
        // Lock
        *(std::uint8_t*)(iTmp + 0x1d) = 1;
        pvCollectedBegin = (void*)0x0;

    LAB_005349b0:
        // Traverse pending-objectives hash
        iTmp = *(int*)((int)thisCharacter + 0x55c);
        if (*(char*)(iTmp + 0x1d) == '\0') {
            FUN_007a4480(0, "HashError:TraverseToNext, not locked for traversal");
            FUN_007a4480(0, "VOG_DEBUG_STOP");
        }
        piCollectedEnd = local_vecEnd;

        if (local_node == 0) {
            local_node = *(int*)(iTmp + 0x14);
            if (local_node == 0) goto LAB_005349ff;
            piObjNode = *(int**)(local_node + 8);
        } else {
            local_node = *(int*)(local_node + 0x14);
            if (local_node == 0) {
            LAB_005349ff:
                piObjNode = (int*)0x0;
            } else {
                piObjNode = *(int**)(local_node + 8);
            }
        }

        if (piObjNode != (int*)0x0) {
            // piObjNode = pending SLOT (node+8). def = *slot (not bare def*).
            // Evaluators receive the slot as 2nd arg; field offsets apply to *slot.
            uEval              = 0;
            cAllTrue           = '\x01';
            local_successCount = 0;
            while (true) {
                iTmp = *(int*)(*piObjNode + 0x158); // evaluator begin on def
                if ((iTmp == 0) ||
                    ((unsigned)(*(int*)(*piObjNode + 0x15c) - iTmp >> 2) <= uEval))
                {
                    break;
                }

                // vtable+0x4: pre-condition check (context filter); 2nd arg = slot
                cPre = (**(char (**)(
                    void*, int*, std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t,
                    std::uint32_t))(**(int**)(iTmp + uEval * 4) + 4))(
                    thisCharacter, piObjNode, p1, p2, p3, p4, in_stack_00000014);

                if ((cPre != '\0') &&
                    ((iTmp = *piObjNode,
                      *(short*)(*(int*)(iTmp + 0x14c) + 0xf8) == 0 ||
                          (*(char*)(iTmp + 0x14) != '\0'))))
                {
                    // vtable+0x20: action callback
                    (**(void (**)(void*, int*))(
                        **(int**)(*(int*)(iTmp + 0x158) + uEval * 4) + 0x20))(
                        thisCharacter, piObjNode);
                    // LogicUI refresh packet type 4
                    uStack_logicType = 4;
                    Client_SendLogicUiPacket((void*)&uStack_logicType /* stack packet */);
                }

                // vtable+0x8: evaluation (always runs; precheck does not skip)
                cPre = (**(char (**)(void*, int*))(
                    **(int**)(*(int*)(*piObjNode + 0x158) + uEval * 4) + 8))(
                    thisCharacter, piObjNode);
                if (cPre != '\0') {
                    local_successCount = local_successCount + 1;
                }
                if (cAllTrue != '\0') {
                    cAllTrue = cPre; // sticky AND — false once any eval fails
                }
                uEval = uEval + 1;
            }

            // CompleteCount at def+0x164 (FUN_0059d880); dual CALL real in asm
            pObjDef       = (void*)*piObjNode;
            completeCount = FUN_0059d880(pObjDef);
            if ((((completeCount != 0) &&
                  (completeCount = FUN_0059d880(pObjDef),
                   completeCount <= local_successCount)) ||
                 (pvCollectedBegin = local_vecBegin, cAllTrue != '\0')) &&
                (pvCollectedBegin = local_vecBegin, *(int*)(*piObjNode + 0x138) == 0))
            {
                // Collect objective id (def+0x10)
                local_successCount = *(int*)(*piObjNode + 0x10);
                if ((local_vecBegin == (void*)0x0) ||
                    ((unsigned)(local_vecCap - (int)local_vecBegin >> 2) <=
                     (unsigned)((int)local_vecEnd - (int)local_vecBegin >> 2)))
                {
                    FUN_004073a0(local_vecEnd, 1, &local_successCount);
                    pvCollectedBegin = local_vecBegin;
                } else {
                    *local_vecEnd = local_successCount;
                    local_vecEnd  = local_vecEnd + 1;
                }
            }
            goto LAB_005349b0;
        }

        // Unlock pending hash
        *(std::uint8_t*)(*(int*)((int)thisCharacter + 0x55c) + 0x1d) = 0;

        // Complete each collected objective id (force=0)
        for (uEval = 0;
             (pvCollectedBegin != (void*)0x0 &&
              (uEval < (unsigned)((int)piCollectedEnd - (int)pvCollectedBegin >> 2)));
             uEval = uEval + 1)
        {
            CVOGReaction_CompleteObjective(
                thisCharacter,
                *(std::uint32_t*)((int)pvCollectedBegin + uEval * 4),
                0xffffffffu,
                0xffffffffu,
                0);
        }

        FUN_005307e0(thisCharacter);
        if (pvCollectedBegin != (void*)0x0) {
            operator_delete(pvCollectedBegin);
        }
    }
    ExceptionList = local_excPrev;
    return;
}

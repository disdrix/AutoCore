// =============================================================================
// FUN_00514ff0 — Object_PurgeSkillHBListChain_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00514ff0
// Address:   0x00514ff0  (autoassault.exe, image base 0x400000)
// System:    skills-abilities / object HB bookkeeping
// Generated: 2026-07-23 scaffold; dual-refined 2026-07-29 W19-N
// Exactness: Behavior-preserving rewrite of decompiler CF + body-byte seals.
//            Not modernization. Not bit-for-bit vs retail EXE (deferred).
// Dual:      reviews/A_aa_00514ff0_Object_PurgeSkillHBListChain_Inferred.md
//            reviews/B_aa_00514ff0_Object_PurgeSkillHBListChain_Inferred.md
// =============================================================================
//
// PURPOSE:
//   If object flag +0x25 is set, walk/remove matching CVOGHBSkillBase entries from
//   the CNDDoubleList at *(this+0xB0) via predicate LAB_00512eb0 (stop vtbl+0x18,
//   optional hb+0x6a4 when ctx != 0). Then, if *(this+0xAC) != 0, recurse on that
//   linked object with stack arg 0.
//
// ABI (byte-sealed):
//   __thiscall: ECX = object*, stack +4 = ctx dword (predicate reads *ctx as u8),
//   RET 4.
//
// Decompiler hazards corrected:
//   - Not bare __fastcall(int) with no stack formals.
//   - CNDDoubleList this = *(this+0xB0), not omitted.
//   - Recurse rebinds ECX to *(this+0xAC); does not call self with this==0.
// =============================================================================

// CNDDoubleList_InvokePredicateAndRemove_Inferred @ 0x004e2600 (sealed dual aa_004e2600)
extern "C" void __thiscall CNDDoubleList_InvokePredicateAndRemove_Inferred(
    void* pList, void* pPredicate, void* pCtx, char nullPayloadFlag);

extern "C" void __thiscall FUN_00514ff0(int param_1 /* this */, int stackArg /* ctx host */)
{
  if (*(char*)(param_1 + 0x25) != '\0') {
    CNDDoubleList_InvokePredicateAndRemove_Inferred(
        *(void**)(param_1 + 0xb0),
        (void*)0x00512eb0, /* LAB_00512eb0 */
        &stackArg,
        0);
  }
  if (*(int*)(param_1 + 0xac) != 0) {
    FUN_00514ff0(*(int*)(param_1 + 0xac), 0);
  }
  return;
}

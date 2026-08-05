// =============================================================================
// FUN_004e23d0 / List_FindByDualKeyWithPred_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004e23d0
// Address:   0x004e23d0  (autoassault.exe, image base 0x400000)
// Body:      0x004e23d0 – 0x004e240c
// System:    shared dual-key list find (reaction / client object resolve consumers)
// Generated: 2026-07-23 scaffold; dual A/B plate 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Dual A/B:  reviews/A_aa_004e23d0_List_FindByDualKeyWithPred_Inferred.md
//            reviews/B_aa_004e23d0_List_FindByDualKeyWithPred_Inferred.md
// =============================================================================

// PURPOSE:
//   Singly-linked list search by dual dword key at node+0x18 / node+0x1c.
//   Head at this+4; next at node+0x10.
//   Writes predecessor to *outPred (0 if match is first / empty).
//   Returns matching node pointer or 0 (EAX — decompiler printed void).
//
//   Leaf; no callees. ret 0xc thiscall (3 stack args).
//   Parent-seed alias Named_CalleeOf_CVOGReaction_SpawnObject_004e23d0 is NOT exclusive
//   (27 xrefs: reaction, client TFID resolve, several FUN_* maps).

// READABILITY:
//  - Body size: ~11 non-empty decompiler lines; 7 BBs; cyclomatic 5.
//  - Control keywords: forx1, returnx1.
//  - Notable callees: none (leaf).
//  - Return sites: 1 (EAX = walk cursor).

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; dual A/B sealed CF + entry bytes 2026-07-29.
 * - int return is asm/caller correction over decompiler void (not modernization).
 * - Remaining FUN_* identifiers at call sites are unresolved product names.
 * - Runtime / differential verification: OPEN.
 *
 * Readability pass:
 * - Control flow and call order preserved from authoritative raw.
 */

int __thiscall FUN_004e23d0(int param_1, int param_2, int param_3, int *param_4)
{
  int iVar1;

  iVar1 = *(int *)(param_1 + 4);   /* list head */
  *param_4 = 0;
  for (; (iVar1 != 0 &&
          ((param_2 != *(int *)(iVar1 + 0x18) ||
            (param_3 != *(int *)(iVar1 + 0x1c)))));
       iVar1 = *(int *)(iVar1 + 0x10)) {
    *param_4 = iVar1;              /* predecessor on mismatch step */
  }
  return iVar1;                    /* match or NULL (EAX) */
}

// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_00415b30
// -----------------------------------------------------------------------------
// Stable ID: aa_00415b30
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x00415b30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×4, return×3, while×1.
//  - Notable callees: FUN_00429310×3, FUN_00415b30.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int __fastcall Named_CalleeOf_Named_VOG_DEBUG_STOP_00415b30(int param_1)

{
  int *piVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(in_EAX + 4);
  iVar2 = 0;
  if (iVar3 != 0) {
    while (param_1 != *(int *)(iVar3 + 0x10)) {
      piVar1 = (int *)(iVar3 + 0xc);
      iVar2 = iVar3;
      iVar3 = *piVar1;
      if (*piVar1 == 0) {
        FUN_00429310();
        return 0;
      }
    }
    if (iVar3 != 0) {
      if (iVar2 != 0) {
        *(uint32_t /* width from decompiler */ *)(iVar2 + 0xc) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0xc);
        FUN_00429310();
        return iVar3;
      }
      *(uint32_t /* width from decompiler */ *)(in_EAX + 4) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0xc);
    }
  }
  FUN_00429310();
  return iVar3;
}

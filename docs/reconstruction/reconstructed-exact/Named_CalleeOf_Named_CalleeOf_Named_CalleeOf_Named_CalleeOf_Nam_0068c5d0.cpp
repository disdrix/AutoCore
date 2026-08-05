// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0068c5d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0068c5d0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x0068c5d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0068bf50, FUN_0068bfe0, FUN_0068c5d0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0068c5d0(int param_1,ushort param_2,uint32_t /* width from decompiler */ param_3,ushort param_4)



{

  int *piVar1;

  int iVar2;

  

  iVar2 = (uint)param_2 * 0x10;

  FUN_0068bfe0(*(ushort *)(param_1 + 0x1e) + 1,0);

  *(ushort *)

   (*(int *)(*(int *)(param_1 + 0x34) + 4 + iVar2) + (uint)*(ushort *)(param_1 + 0x1e) * 2) =

       param_4;

  FUN_0068bf50(*(ushort *)(param_1 + 0x1e) + 1,0);

  *(uint32_t /* width from decompiler */ *)

   (*(int *)(*(int *)(param_1 + 0x44) + 4 + iVar2) + (uint)*(ushort *)(param_1 + 0x1e) * 4) =

       param_3;

  piVar1 = (int *)(*(int *)(param_1 + 0x24) + (uint)param_2 * 4);

  *piVar1 = *piVar1 + (param_4 - 2);

  return;

}

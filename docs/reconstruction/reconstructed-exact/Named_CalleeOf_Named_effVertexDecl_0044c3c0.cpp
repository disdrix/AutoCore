// =============================================================================
// Named_CalleeOf_Named_effVertexDecl_0044c3c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0044c3c0
// Callee of Named_effVertexDecl (+3 other named callers)
// Address:   0x0044c3c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_effVertexDecl: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_effVertexDecl (+3 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×4, return×3.
//  - Notable callees: FUN_00445fa0×2, FUN_0044c3c0, FUN_004645c0.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_effVertexDecl (+3 other named callers)
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

void __fastcall Named_CalleeOf_Named_effVertexDecl_0044c3c0(uint param_1,int param_2)



{

  int iVar1;

  uint uVar2;

  

  iVar1 = *(int *)(param_2 + 4);

  if (iVar1 == 0) {

    uVar2 = 0;

  }

  else {

    uVar2 = *(int *)(param_2 + 8) - iVar1 >> 3;

  }

  if (uVar2 < param_1) {

    if (iVar1 == 0) {

      FUN_00445fa0(*(uint32_t /* width from decompiler */ *)(param_2 + 8),&stack0x00000004);

      return;

    }

    FUN_00445fa0(*(uint32_t /* width from decompiler */ *)(param_2 + 8),&stack0x00000004);

    return;

  }

  if ((iVar1 != 0) && (param_1 < (uint)(*(int *)(param_2 + 8) - iVar1 >> 3))) {

    FUN_004645c0(iVar1 + param_1 * 8,*(int *)(param_2 + 8));

  }

  return;

}

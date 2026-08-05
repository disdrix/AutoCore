// =============================================================================
// Named_CalleeOf_Named_gfxDevice_0096a3f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0096a3f0
// Callee of Named_gfxDevice
// Address:   0x0096a3f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxDevice: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0074fca0, FUN_0096a3f0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_gfxDevice
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

void Named_CalleeOf_Named_gfxDevice_0096a3f0(void)



{

  int iVar1;

  int iVar2;

  int in_EAX;

  

  if (*(int *)(in_EAX + 4) != 0) {

    FUN_0074fca0(3);

    iVar1 = *(int *)(in_EAX + 4);

    iVar2 = *(int *)(iVar1 + 0x28);

    if (-1 < *(int *)(&DAT_00afe00c + iVar2 * 0xc)) {

      (**(code **)(**(int **)(iVar1 + 0xc) + 0x108))(*(int **)(iVar1 + 0xc));

    }

    (**(code **)(**(int **)(iVar1 + 0xc) + 0x100))(*(int **)(iVar1 + 0xc),0);

    *(uint32_t /* width from decompiler */ *)(&DAT_00afe00c + iVar2 * 0xc) = 0;

  }

  return;

}

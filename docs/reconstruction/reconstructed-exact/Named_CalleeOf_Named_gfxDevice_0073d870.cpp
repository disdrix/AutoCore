// =============================================================================
// Named_CalleeOf_Named_gfxDevice_0073d870
// -----------------------------------------------------------------------------
// Stable ID: aa_0073d870
// Callee of Named_gfxDevice
// Address:   0x0073d870  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxDevice: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: for×2, if×1, return×1.
//  - Notable callees: FUN_0073d870, FUN_007525f0.
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_gfxDevice_0073d870(void)



{

  int *piVar1;

  int *piVar2;

  int iVar3;

  int in_EAX;

  int *piVar4;

  int iVar5;

  

  piVar1 = *(int **)(in_EAX + 8);

  for (piVar4 = *(int **)(in_EAX + 4); piVar4 != piVar1; piVar4 = piVar4 + 5) {

    if (*(int *)(*piVar4 + 0xc) != 0) {

      piVar2 = *(int **)(*piVar4 + 0xc);

      (**(code **)(*piVar2 + 0x118))(piVar2);

    }

    iVar3 = piVar4[3];

    for (iVar5 = piVar4[2]; iVar5 != iVar3; iVar5 = iVar5 + 4) {

      FUN_007525f0();

    }

  }

  return 0;

}

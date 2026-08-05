// =============================================================================
// FUN_0073d0a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0073d0a0
// Address:   0x0073d0a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0073d0a0 @ 0x0073d0a0
// Stable ID: aa_0073d0a0
// Embedded strings (evidence for future rename):
//   - "DiffuseMap"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0073c350, FUN_0073cb70, FUN_0073d0a0, FUN_00752310.
//  - Strings: "DiffuseMap".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int * FUN_0073d0a0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  int *piVar1;

  int *piVar2;

  int local_4;

  

  piVar1 = (int *)FUN_0073cb70();

  piVar2 = &local_4;

  if (*(int *)(*(int *)piVar1[0x30] + 0x20) == 0) {

    local_4 = -1;

  }

  else {

    piVar2 = (int *)FUN_00752310(piVar2,"DiffuseMap");

  }

  if (-1 < *piVar2) {

    FUN_0073c350(param_2,param_3);

  }

  (**(code **)(*piVar1 + 0x18))(param_1);

  return piVar1;

}

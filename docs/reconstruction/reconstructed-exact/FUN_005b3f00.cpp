// =============================================================================
// FUN_005b3f00
// -----------------------------------------------------------------------------
// Stable ID: aa_005b3f00
// Address:   0x005b3f00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005b3f00 @ 0x005b3f00
// Stable ID: aa_005b3f00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: fwrite×3, FUN_005b3f00.
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

void __thiscall FUN_005b3f00(int param_1,FILE *param_2)



{

  int *piVar1;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x18);

  fwrite(&local_4,4,1,param_2);

  fwrite((void *)(param_1 + 0x20),0x10,1,param_2);

  piVar1 = (int *)**(int **)(param_1 + 0x14);

  if (piVar1 != *(int **)(param_1 + 0x14)) {

    do {

      fwrite(piVar1 + 8,0x10,1,param_2);

      piVar1 = (int *)*piVar1;

    } while (piVar1 != (int *)*(int *)(param_1 + 0x14));

  }

  return;

}

// =============================================================================
// FUN_0052d030
// -----------------------------------------------------------------------------
// Stable ID: aa_0052d030
// Address:   0x0052d030  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0052d030 @ 0x0052d030
// Stable ID: aa_0052d030
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, for×1.
//  - Notable callees: FUN_0052d030, FUN_00538ab0.
//  - Return sites: 2.

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

int FUN_0052d030(uint32_t /* width from decompiler */ param_1)



{

  int *piVar1;

  int iVar2;

  int *piVar3;

  uint32_t /* width from decompiler */ local_210;

  uint8_t local_20c [4];

  int local_208 [9];

  short local_1e2;

  

  local_210 = param_1;

  piVar1 = (int *)FUN_00538ab0(local_20c,&local_210);

  if (*piVar1 != DAT_00b045b4) {

    piVar1 = (int *)(*piVar1 + 0x10);

    piVar3 = local_208;

    for (iVar2 = 0x7f; iVar2 != 0; iVar2 = iVar2 + -1) {

      *piVar3 = *piVar1;

      piVar1 = piVar1 + 1;

      piVar3 = piVar3 + 1;

    }

    if (local_208[0] != -1) {

      return (int)local_1e2 / 5;

    }

  }

  return 1;

}

// =============================================================================
// FUN_00787410
// -----------------------------------------------------------------------------
// Stable ID: aa_00787410
// Address:   0x00787410  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00787410 @ 0x00787410
// Stable ID: aa_00787410
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: CONCAT31, FUN_00787410.
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

uint32_t /* width from decompiler */ __thiscall FUN_00787410(int *param_1,uint8_t param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  

  iVar1 = param_1[1];

  iVar2 = *param_1;

  iVar3 = 0;

  if (0 < iVar1 * iVar2) {

    do {

      *(uint8_t *)(iVar3 + param_1[2]) = param_2;

      iVar3 = iVar3 + 1;

    } while (iVar3 < iVar1 * iVar2);

  }

  return CONCAT31((int3)((uint)iVar3 >> 8),1);

}

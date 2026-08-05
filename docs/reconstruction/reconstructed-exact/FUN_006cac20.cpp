// =============================================================================
// FUN_006cac20
// -----------------------------------------------------------------------------
// Stable ID: aa_006cac20
// Address:   0x006cac20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006cac20 @ 0x006cac20
// Stable ID: aa_006cac20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: do×1, while×1, return×1.
//  - Notable callees: FUN_006cac20.
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

void __fastcall FUN_006cac20(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  int *piVar2;

  int iVar3;

  

  puVar1 = (uint32_t /* width from decompiler */ *)(param_1 + 0x100);

  *puVar1 = &PTR_LAB_00a0d828;

  piVar2 = (int *)(param_1 + 8);

  iVar3 = 8;

  do {

    piVar2[-2] = (int)puVar1;

    piVar2[-1] = (int)puVar1;

    *piVar2 = (int)puVar1;

    piVar2[1] = (int)puVar1;

    piVar2[2] = (int)puVar1;

    piVar2[3] = (int)puVar1;

    piVar2[4] = (int)puVar1;

    piVar2[5] = (int)puVar1;

    piVar2 = piVar2 + 8;

    iVar3 = iVar3 + -1;

  } while (iVar3 != 0);

  return;

}

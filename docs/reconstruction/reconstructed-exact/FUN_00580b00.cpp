// =============================================================================
// FUN_00580b00
// -----------------------------------------------------------------------------
// Stable ID: aa_00580b00
// Address:   0x00580b00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00580b00 @ 0x00580b00
// Stable ID: aa_00580b00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: while×1, if×1, return×1.
//  - Notable callees: FUN_00580b00.
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

uint __thiscall FUN_00580b00(int param_1,uint32_t /* width from decompiler */ param_2,char param_3)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int local_10;

  uint32_t /* width from decompiler */ local_c;

  char local_8;

  uint local_4;

  

  iVar1 = *(int *)(param_1 + 0x40);

  local_4 = (uint)(param_3 != '\0');

  local_10 = param_1;

  local_c = param_2;

  local_8 = param_3;

  while (iVar1 = iVar1 + -1, -1 < iVar1) {

    puVar2 = *(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 0x3c) + iVar1 * 4);

    if (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

      (**(code **)*puVar2)(&local_10);

    }

  }

  return local_4;

}

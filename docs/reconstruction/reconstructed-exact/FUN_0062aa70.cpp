// =============================================================================
// FUN_0062aa70
// -----------------------------------------------------------------------------
// Stable ID: aa_0062aa70
// Address:   0x0062aa70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0062aa70 @ 0x0062aa70
// Stable ID: aa_0062aa70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_006000c0×2, FUN_0062a610, FUN_0062aa70.
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

void __thiscall FUN_0062aa70(int param_1,uint16_t param_2)



{

  int iVar1;

  int iVar2;

  uint16_t local_14 [2];

  int local_10;

  int local_c;

  int local_8;

  

  iVar1 = *(int *)(param_1 + 0xc);

  iVar2 = *(int *)(param_1 + 0x10);

  local_14[0] = param_2;

  local_10 = param_1;

  local_c = iVar1;

  local_8 = iVar2;

  FUN_0062a610(*(uint32_t /* width from decompiler */ *)(param_1 + 8),local_14);

  if (*(int *)(iVar1 + 100) != 0) {

    FUN_006000c0(iVar1,local_14);

  }

  if (*(int *)(iVar2 + 100) != 0) {

    FUN_006000c0(iVar2,local_14);

  }

  return;

}

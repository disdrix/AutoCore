// =============================================================================
// FUN_0062aff0
// -----------------------------------------------------------------------------
// Stable ID: aa_0062aff0
// Address:   0x0062aff0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0062aff0 @ 0x0062aff0
// Stable ID: aa_0062aff0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_006000c0×2, FUN_0055e860, FUN_0062a610, FUN_0062aff0, FUN_006515a0.
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

void __thiscall FUN_0062aff0(int param_1,uint32_t /* width from decompiler */ param_2)



{

  uint8_t uVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint16_t local_14 [2];

  int local_10;

  int local_c;

  int local_8;

  

  uVar4 = param_2;

  iVar2 = *(int *)(param_1 + 0x20);

  iVar3 = *(int *)(param_1 + 0x1c);

  local_14[0] = (uint16_t)param_2;

  local_10 = param_1;

  local_c = iVar3;

  local_8 = iVar2;

  FUN_0062a610(*(uint32_t /* width from decompiler */ *)(param_1 + 8),local_14);

  if (*(int *)(iVar3 + 100) != 0) {

    FUN_006000c0(iVar3,local_14);

  }

  if (*(int *)(iVar2 + 100) != 0) {

    FUN_006000c0(iVar2,local_14);

  }

  FUN_006515a0(uVar4);

  if (*(int *)(param_1 + 0xa4) == 0) {

    uVar1 = *(uint8_t *)(*(int *)(param_1 + 8) + 300);

    *(uint8_t *)(*(int *)(param_1 + 8) + 300) = 0;

    FUN_0055e860(&param_2,param_1 + 0x10);

    *(uint8_t *)(*(int *)(param_1 + 8) + 300) = uVar1;

  }

  return;

}

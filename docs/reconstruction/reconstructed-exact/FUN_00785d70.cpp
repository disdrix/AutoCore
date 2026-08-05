// =============================================================================
// FUN_00785d70
// -----------------------------------------------------------------------------
// Stable ID: aa_00785d70
// Address:   0x00785d70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00785d70 @ 0x00785d70
// Stable ID: aa_00785d70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×2, for×1, return×1.
//  - Notable callees: FUN_00785d70×2.
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

void __fastcall FUN_00785d70(int param_1)



{

  uint uVar1;

  int iVar2;

  int iVar3;

  

  iVar3 = *(int *)(param_1 + 0x3c);

  uVar1 = *(uint *)(param_1 + 0x28);

  *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + iVar3;

  *(int *)(param_1 + 0x44) = *(int *)(param_1 + 0x44) + iVar3;

  *(int *)(param_1 + 0x34) = *(int *)(param_1 + 0x34) + uVar1;

  *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + uVar1;

  *(int *)(param_1 + 0x40) = iVar3;

  *(uint *)(param_1 + 0x2c) = uVar1;

  if (*(int *)(param_1 + 0x4c) < iVar3) {

    *(int *)(param_1 + 0x4c) = iVar3;

  }

  if (*(uint *)(param_1 + 0x38) < uVar1) {

    *(uint *)(param_1 + 0x38) = uVar1;

  }

  iVar3 = *(int *)(param_1 + 0x10);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = 0;

  *(int *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + 1;

  *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + 1;

  iVar2 = *(int *)(param_1 + 0x14);

  for (; iVar3 != iVar2; iVar3 = iVar3 + 4) {

    FUN_00785d70();

  }

  return;

}

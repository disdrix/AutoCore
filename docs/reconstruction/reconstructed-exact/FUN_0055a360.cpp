// =============================================================================
// FUN_0055a360
// -----------------------------------------------------------------------------
// Stable ID: aa_0055a360
// Address:   0x0055a360  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0055a360 @ 0x0055a360
// Stable ID: aa_0055a360
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_0055a360.
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

void __thiscall FUN_0055a360(int param_1,uint param_2,uint32_t /* width from decompiler */ *param_3,uint32_t /* width from decompiler */ *param_4)



{

  uint uVar1;

  int iVar2;

  int iVar3;

  

  uVar1 = 0;

  if (*(int *)(param_1 + 0x18) != 0) {

    uVar1 = (*(int *)(param_1 + 0x1c) - *(int *)(param_1 + 0x18)) / 0x1c;

  }

  if (uVar1 < param_2) {

    iVar3 = 0;

    if (*(int *)(param_1 + 0x18) != 0) {

      iVar3 = (*(int *)(param_1 + 0x1c) - *(int *)(param_1 + 0x18)) / 0x1c;

    }

    param_2 = iVar3 - 1;

  }

  iVar3 = param_2 * 0x1c;

  iVar2 = *(int *)(param_1 + 0x18) + iVar3;

  *param_3 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x18) + iVar3);

  param_3[1] = *(uint32_t /* width from decompiler */ *)(iVar2 + 4);

  param_3[2] = *(uint32_t /* width from decompiler */ *)(iVar2 + 8);

  iVar3 = *(int *)(param_1 + 0x18) + iVar3;

  *param_4 = *(uint32_t /* width from decompiler */ *)(iVar3 + 0xc);

  param_4[1] = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x10);

  param_4[2] = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x14);

  param_4[3] = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x18);

  return;

}

// =============================================================================
// FUN_00555450
// -----------------------------------------------------------------------------
// Stable ID: aa_00555450
// Address:   0x00555450  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00555450 @ 0x00555450
// Stable ID: aa_00555450
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: FUN_00555450.
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

void __fastcall FUN_00555450(int param_1)



{

  uint uVar1;

  int iVar2;

  

  iVar2 = 0;

  for (uVar1 = 0;

      (*(int *)(param_1 + 0x434) != 0 &&

      (uVar1 < (uint)((*(int *)(param_1 + 0x438) - *(int *)(param_1 + 0x434)) / 0x134)));

      uVar1 = uVar1 + 1) {

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x434) + 0x104 + iVar2) = 0;

    iVar2 = iVar2 + 0x134;

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x544) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x104) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x210) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x31c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x428) = 0;

  return;

}

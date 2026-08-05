// =============================================================================
// FUN_006c0020
// -----------------------------------------------------------------------------
// Stable ID: aa_006c0020
// Address:   0x006c0020  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006c0020 @ 0x006c0020
// Stable ID: aa_006c0020
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_005b3370, FUN_006c0020.
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

void __thiscall FUN_006c0020(int param_1,ushort param_2)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

  local_4 = local_4 & 0xffff0000;

  local_8 = (uint)param_2;

  if (*(uint *)(param_1 + 8) == (*(uint *)(param_1 + 0xc) & 0x7fffffff)) {

    FUN_005b3370((int *)(param_1 + 4),8);

  }

  iVar1 = *(int *)(param_1 + 8);

  iVar2 = *(int *)(param_1 + 4);

  *(uint *)(iVar2 + iVar1 * 8) = local_8;

  *(uint *)(iVar2 + 4 + iVar1 * 8) = local_4;

  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;

  return;

}

// =============================================================================
// FUN_006c0080
// -----------------------------------------------------------------------------
// Stable ID: aa_006c0080
// Address:   0x006c0080  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006c0080 @ 0x006c0080
// Stable ID: aa_006c0080
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: CONCAT22×2, FUN_005b3370×2, FUN_006c0080.
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

void __thiscall FUN_006c0080(int param_1,uint16_t param_2,ushort param_3)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  uint uVar4;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  piVar1 = (int *)(param_1 + 4);

  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

  local_4 = local_4 & 0xffff0000;

  local_10 = CONCAT22(1,param_2);

  local_c = CONCAT22(local_c._2_2_,1);

  local_8 = (uint)param_3;

  if (*(uint *)(param_1 + 8) == (*(uint *)(param_1 + 0xc) & 0x7fffffff)) {

    FUN_005b3370(piVar1,8);

  }

  iVar2 = *(int *)(param_1 + 8);

  iVar3 = *piVar1;

  *(uint32_t /* width from decompiler */ *)(iVar3 + iVar2 * 8) = local_10;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 4 + iVar2 * 8) = local_c;

  uVar4 = *(int *)(param_1 + 8) + 1;

  *(uint *)(param_1 + 8) = uVar4;

  if (uVar4 == (*(uint *)(param_1 + 0xc) & 0x7fffffff)) {

    FUN_005b3370(piVar1,8);

  }

  iVar2 = *(int *)(param_1 + 8);

  iVar3 = *piVar1;

  *(uint *)(iVar3 + iVar2 * 8) = local_8;

  *(uint *)(iVar3 + 4 + iVar2 * 8) = local_4;

  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;

  return;

}

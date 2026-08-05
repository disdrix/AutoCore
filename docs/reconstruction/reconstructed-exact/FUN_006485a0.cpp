// =============================================================================
// FUN_006485a0
// -----------------------------------------------------------------------------
// Stable ID: aa_006485a0
// Address:   0x006485a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006485a0 @ 0x006485a0
// Stable ID: aa_006485a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, return×1.
//  - Notable callees: FUN_005b3300, FUN_00635880, FUN_00635bd0, FUN_006485a0.
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

void __thiscall FUN_006485a0(int param_1,uint32_t /* width from decompiler */ param_2,int param_3)



{

  uint uVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  int iVar5;

  int local_18;

  uint local_14;

  int local_10;

  int local_c [3];

  

  iVar5 = 0;

  local_c[0] = 0;

  local_c[1] = 0;

  local_c[2] = -0x80000000;

  FUN_00635bd0(local_c);

  local_10 = -0x80000000;

  uVar1 = *(uint *)(param_3 + 0x10);

  local_18 = 0;

  local_14 = 0;

  if (0 < (int)uVar1) {

    FUN_005b3300(&local_18,((int)uVar1 < 0) - 1 & uVar1,0x20);

  }

  iVar4 = 0;

  if (0 < (int)uVar1) {

    do {

      puVar3 = (uint32_t /* width from decompiler */ *)(local_18 + iVar5);

      puVar2 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 8) + iVar4 * 4) * 0x20 + local_c[0]);

      iVar4 = iVar4 + 1;

      *puVar3 = *puVar2;

      puVar3[1] = puVar2[1];

      puVar3[2] = puVar2[2];

      puVar3[3] = puVar2[3];

      puVar3[4] = puVar2[4];

      puVar3[5] = puVar2[5];

      puVar3[6] = puVar2[6];

      puVar3[7] = puVar2[7];

      iVar5 = iVar5 + 0x20;

    } while (iVar4 < (int)uVar1);

  }

  local_14 = uVar1;

  FUN_00635880(&local_18);

  if (-1 < local_10) {

    (**(code **)(*DAT_00b05060 + 0x14))(local_18,local_10 << 5,0x12);

  }

  if (-1 < local_c[2]) {

    (**(code **)(*DAT_00b05060 + 0x14))(local_c[0],local_c[2] << 5,0x12);

  }

  return;

}

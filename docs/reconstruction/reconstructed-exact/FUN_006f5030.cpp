// =============================================================================
// FUN_006f5030
// -----------------------------------------------------------------------------
// Stable ID: aa_006f5030
// Address:   0x006f5030  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f5030 @ 0x006f5030
// Stable ID: aa_006f5030
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~76 non-empty decompiler lines.
//  - Control keywords: do×3, while×3, if×1, return×1.
//  - Notable callees: FUN_006f4d20, FUN_006f5030.
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

uint32_t /* width from decompiler */ __thiscall

FUN_006f5030(int param_1,int *param_2,uint32_t /* width from decompiler */ param_3,int *param_4,int param_5,int param_6)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  int iStack_18;

  int iStack_14;

  uint32_t /* width from decompiler */ uStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  

  *(int *)(param_1 + 8) = param_5;

  *(int **)(param_1 + 0x28) = param_2;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = param_3;

  *(int **)(param_1 + 0x24) = param_4;

  iStack_18 = (**(code **)(*param_2 + 4))();

  iStack_14 = *(uint32_t /* width from decompiler */ *)(param_5 + 4);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x38) = 0;

  if (iStack_18 != 0) {

    iVar4 = 0;

    iVar1 = iStack_18;

    do {

      iVar1 = iVar1 >> 1;

      iVar4 = iVar4 + 1;

    } while (iVar1 != 0);

    *(int *)(param_1 + 0x38) = iVar4;

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = 0;

  puVar2 = *(uint32_t /* width from decompiler */ **)(param_6 + 4);

  iVar1 = 0x400;

  do {

    *puVar2 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x10);

    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;

    puVar2[0x3e] = puVar2;

    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;

    puVar2[0x7c] = puVar2 + 0x3e;

    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;

    puVar2[0xba] = puVar2 + 0x7c;

    *(uint32_t /* width from decompiler */ **)(param_1 + 0x10) = puVar2 + 0xba;

    puVar2 = puVar2 + 0xf8;

    iVar1 = iVar1 + -1;

    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;

  } while (iVar1 != 0);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = 0;

  puVar2 = *(uint32_t /* width from decompiler */ **)(param_6 + 8);

  iVar1 = 0x400;

  do {

    *puVar2 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x18);

    *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;

    puVar2[0x2f] = puVar2;

    *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;

    puVar2[0x5e] = puVar2 + 0x2f;

    *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;

    puVar2[0x8d] = puVar2 + 0x5e;

    *(uint32_t /* width from decompiler */ **)(param_1 + 0x18) = puVar2 + 0x8d;

    puVar2 = puVar2 + 0xbc;

    iVar1 = iVar1 + -1;

    *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;

  } while (iVar1 != 0);

  uVar3 = (**(code **)(*param_4 + 4))();

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x30) = uVar3;

  uVar3 = (**(code **)(*param_4 + 8))();

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x34) = uVar3;

  iVar1 = *(int *)(*(int *)(param_1 + 8) + 8) + 2;

  uStack_10 = (**(code **)*DAT_00b05060)(iVar1 * 4,0x23);

  *(int **)(param_1 + 0xc) = &iStack_18;

  iStack_18 = 0;

  uStack_c = 0;

  iStack_14 = iVar1;

  uVar3 = FUN_006f4d20(0,&stack0xffffffdc,0,0);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

  (**(code **)(*DAT_00b05060 + 4))(uStack_10);

  return uVar3;

}

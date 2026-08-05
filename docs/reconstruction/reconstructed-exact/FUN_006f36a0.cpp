// =============================================================================
// FUN_006f36a0
// -----------------------------------------------------------------------------
// Stable ID: aa_006f36a0
// Address:   0x006f36a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f36a0 @ 0x006f36a0
// Stable ID: aa_006f36a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~84 non-empty decompiler lines.
//  - Control keywords: for×3, if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_006f1c80×5, FUN_006f2180×5, FUN_006f2210×5, FUN_006f23d0, FUN_006f30e0, FUN_006f3390, FUN_006f36a0.
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

void __thiscall FUN_006f36a0(int *param_1,int param_2,int param_3,int param_4)



{

  uint uVar1;

  int iVar2;

  int unaff_ESI;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ uStack_b8;

  uint8_t uStack_b4;

  uint32_t /* width from decompiler */ uStack_94;

  uint32_t /* width from decompiler */ uStack_90;

  uint32_t /* width from decompiler */ uStack_8c;

  uint32_t /* width from decompiler */ uStack_88;

  uint32_t /* width from decompiler */ uStack_84;

  uint32_t /* width from decompiler */ uStack_70;

  uint8_t uStack_6c;

  

  param_1[3] = param_3;

  param_1[8] = param_4;

  param_1[9] = 0;

  (**(code **)(*param_1 + 0x10))(param_2,param_1 + 0xc);

  if (param_2 != 0) {

    param_1[5] = 0;

    uVar1 = *(uint *)(param_2 + 0x28);

    if (uVar1 != 0) {

      iVar2 = 0;

      do {

        uVar1 = uVar1 >> 1;

        iVar2 = iVar2 + 1;

      } while (uVar1 != 0);

      param_1[5] = iVar2;

    }

    param_1[6] = param_1[5] >> 1;

    param_1[5] = (param_1[5] / param_1[0x1c] + 2) * param_1[0x1c] + -1;

    FUN_006f2180(param_2,param_1 + 0xc);

    uStack_94 = 0x10;

    uStack_88 = 0;

    uStack_8c = 0;

    uStack_90 = 0;

    uStack_b8 = 0xffffffff;

    uStack_84 = 0;

    uStack_b4 = 0;

    FUN_006f1c80(param_2);

    FUN_006f2210();

    puVar3 = &uStack_b8;

    puVar4 = (uint32_t /* width from decompiler */ *)&stack0xfffffee8;

    for (iVar2 = 0x12; iVar2 != 0; iVar2 = iVar2 + -1) {

      *puVar4 = *puVar3;

      puVar3 = puVar3 + 1;

      puVar4 = puVar4 + 1;

    }

    FUN_006f1c80(param_2);

    FUN_006f2180(param_2,unaff_ESI + 0x30);

    FUN_006f2210();

    FUN_006f23d0(param_2,&uStack_b8,&stack0xfffffee8);

    FUN_006f2180(param_2,unaff_ESI + 0x30);

    FUN_006f1c80(param_2);

    FUN_006f2210();

    puVar3 = (uint32_t /* width from decompiler */ *)&stack0xfffffee8;

    puVar4 = &uStack_70;

    for (iVar2 = 0x12; iVar2 != 0; iVar2 = iVar2 + -1) {

      *puVar4 = *puVar3;

      puVar3 = puVar3 + 1;

      puVar4 = puVar4 + 1;

    }

    FUN_006f1c80(param_2);

    FUN_006f2180(param_2,unaff_ESI + 0x30);

    uStack_70 = 0;

    uStack_6c = 0;

    FUN_006f2210();

    FUN_006f30e0(param_2,&stack0xfffffee8,&uStack_70);

    puVar3 = &uStack_b8;

    puVar4 = (uint32_t /* width from decompiler */ *)&stack0xfffffee8;

    for (iVar2 = 0x12; iVar2 != 0; iVar2 = iVar2 + -1) {

      *puVar4 = *puVar3;

      puVar3 = puVar3 + 1;

      puVar4 = puVar4 + 1;

    }

    FUN_006f1c80(param_2);

    FUN_006f2180(param_2,unaff_ESI + 0x30);

    FUN_006f2210();

    FUN_006f3390(param_2,&uStack_b8,&stack0xfffffee8);

  }

  return;

}

// =============================================================================
// FUN_005c89f0
// -----------------------------------------------------------------------------
// Stable ID: aa_005c89f0
// Address:   0x005c89f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005c89f0 @ 0x005c89f0
// Stable ID: aa_005c89f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×10, return×4.
//  - Notable callees: CONCAT31, FUN_004d2700, FUN_00514ff0, FUN_00515030, FUN_005c8810, FUN_005c89f0.
//  - Return sites: 4.

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

uint __thiscall FUN_005c89f0(int param_1,int param_2)



{

  int iVar1;

  byte bVar2;

  uint uVar3;

  int iVar4;

  

  iVar4 = *(int *)(*(int *)(param_1 + -0xbc) + 4);

  uVar3 = iVar4 + param_1;

  if ((*(uint *)(iVar4 + 0xc0 + param_1) >> 10 & 1) == 0) {

    if (0 < param_2) {

      FUN_00514ff0(1);

      FUN_00515030();

      iVar4 = *(int *)(*(int *)(param_1 + -0xbc) + 4);

      if ((*(uint *)(iVar4 + -0x7c + param_1) & *(uint *)(iVar4 + -0x78 + param_1)) != 0xffffffff) {

        iVar4 = param_2;

        if (*(int *)(param_1 + -0x34) - param_2 < 0) {

          iVar4 = *(int *)(param_1 + -0x34);

        }

        FUN_005c8810((float)iVar4);

      }

    }

    (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0xbc) + 4) + -0xbc + param_1) + 0x240))

              (*(int *)(param_1 + -0x34) - param_2);

    uVar3 = *(int *)(*(int *)(param_1 + -0xbc) + 4) + param_1;

    if ((*(uint *)(uVar3 - 0x8c) & *(uint *)(uVar3 - 0x88)) != 0xffffffff) {

      iVar4 = 0;

      if (param_1 != 0xc0) {

        iVar4 = uVar3 - 0xbc;

      }

      iVar1 = *(int *)(*(int *)(param_1 + -0xbc) + 4);

      uVar3 = FUN_004d2700(iVar4,1,*(uint32_t /* width from decompiler */ *)(iVar1 + param_1 + -0x8c),

                           *(uint32_t /* width from decompiler */ *)(iVar1 + -0x88 + param_1));

    }

    if (*(int *)(param_1 + -0x34) < 1) {

      *(uint32_t /* width from decompiler */ *)(param_1 + -0x34) = 0;

      param_1 = *(int *)(*(int *)(param_1 + -0xbc) + 4) + param_1;

      uVar3 = *(uint *)(param_1 + -8);

      bVar2 = ~(byte)(uVar3 >> 0xd);

      uVar3 = CONCAT31((uint3)(uVar3 >> 0x15),bVar2) & 0xffffff01;

      if ((bVar2 & 1) == 0) {

        return uVar3;

      }

      iVar4 = *(int *)(param_1 + -0x10);

      if (iVar4 == 0) {

        return uVar3;

      }

      if ((*(byte *)(iVar4 + 0xb5) & 0x20) == 0) {

        return uVar3;

      }

    }

  }

  return uVar3 & 0xffffff00;

}

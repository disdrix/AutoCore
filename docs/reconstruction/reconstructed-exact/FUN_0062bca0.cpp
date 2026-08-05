// =============================================================================
// FUN_0062bca0
// -----------------------------------------------------------------------------
// Stable ID: aa_0062bca0
// Address:   0x0062bca0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0062bca0 @ 0x0062bca0
// Stable ID: aa_0062bca0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~75 non-empty decompiler lines.
//  - Control keywords: if×6, for×3, do×2, while×2, return×1.
//  - Notable callees: FUN_0062bca0.
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

void __thiscall

FUN_0062bca0(int param_1,int param_2,int param_3,int param_4,int param_5,uint32_t /* width from decompiler */ *param_6)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  uint uVar7;

  uint32_t /* width from decompiler */ *puVar8;

  int iVar9;

  byte *pbVar10;

  int *local_24;

  int local_20;

  

  iVar2 = *(int *)(param_4 + 0x14);

  iVar3 = *(int *)(param_4 + 0x10);

  if (-1 < param_2 >> 7) {

    iVar9 = (param_2 >> 7) + 1;

    puVar8 = param_6;

    do {

      iVar9 = iVar9 + -1;

      *puVar8 = 0;

      puVar8[1] = 0;

      puVar8[2] = 0;

      puVar8[3] = 0;

      puVar8 = puVar8 + 4;

    } while (iVar9 != 0);

  }

  iVar9 = *(int *)(param_1 + 0x4c);

  uVar7 = iVar9 + 8;

  if ((*(int *)(param_1 + 0x70) != 0) &&

     (param_3 = param_3 >> (0x1fU - (char)*(uint32_t /* width from decompiler */ *)(param_1 + 0x74) & 0x1f), 0 < param_3)) {

    piVar1 = (int *)(*(int *)(param_1 + 0x78) + -0x14 + param_3 * 0x14);

    param_6[*piVar1 >> 5] = param_6[*piVar1 >> 5] ^ 1 << ((byte)*piVar1 & 0x1f);

    local_24 = (int *)piVar1[2];

    local_20 = piVar1[3];

    if (-1 < local_20 + -1) {

      do {

        iVar9 = *local_24;

        if (iVar9 != param_5) {

          param_6[iVar9 >> 5] = param_6[iVar9 >> 5] ^ 1 << ((byte)iVar9 & 0x1f);

        }

        local_24 = local_24 + 1;

        local_20 = local_20 + -1;

      } while (local_20 != 0);

    }

    iVar4 = *piVar1;

    iVar5 = *(int *)(param_1 + 0x40);

    iVar9 = *(int *)(iVar5 + 0x14 + iVar4 * 0x1c);

    iVar6 = *(int *)(param_1 + 0x4c);

    for (pbVar10 = (byte *)(iVar6 + 8 + *(int *)(iVar5 + 0x10 + iVar4 * 0x1c) * 8);

        pbVar10 < (byte *)(iVar6 + iVar9 * 8); pbVar10 = pbVar10 + 8) {

      if ((*pbVar10 & 1) == 0) {

        param_6[*(int *)(pbVar10 + 4) >> 5] =

             param_6[*(int *)(pbVar10 + 4) >> 5] & ~(1 << ((byte)*(int *)(pbVar10 + 4) & 0x1f));

      }

    }

    iVar9 = *(int *)(param_1 + 0x4c);

    uVar7 = iVar9 + 8 + *(int *)(iVar5 + iVar4 * 0x1c + 0x10) * 8;

  }

  for (; uVar7 < (uint)(iVar9 + iVar3 * 8); uVar7 = uVar7 + 8) {

    param_6[*(int *)(uVar7 + 4) >> 5] =

         param_6[*(int *)(uVar7 + 4) >> 5] ^ 1 << ((byte)*(int *)(uVar7 + 4) & 0x1f);

  }

  iVar3 = *(int *)(param_1 + 0x4c);

  for (pbVar10 = (byte *)(uVar7 + 8); pbVar10 < (byte *)(iVar3 + iVar2 * 8); pbVar10 = pbVar10 + 8)

  {

    if ((*pbVar10 & 1) == 0) {

      param_6[*(int *)(pbVar10 + 4) >> 5] =

           param_6[*(int *)(pbVar10 + 4) >> 5] ^ 1 << ((byte)*(int *)(pbVar10 + 4) & 0x1f);

    }

  }

  return;

}

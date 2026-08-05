// =============================================================================
// FUN_0047d450
// -----------------------------------------------------------------------------
// Stable ID: aa_0047d450
// Address:   0x0047d450  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0047d450 @ 0x0047d450
// Stable ID: aa_0047d450
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~113 non-empty decompiler lines.
//  - Control keywords: if×8, return×5, do×4, while×4, for×2, switch×1.
//  - Notable callees: FUN_00476d60, FUN_0047d450.
//  - Return sites: 5.

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

void __fastcall FUN_0047d450(byte *param_1,int param_2,uint32_t /* width from decompiler */ param_3,byte *param_4)



{

  byte bVar1;

  byte bVar2;

  uint32_t /* width from decompiler */ in_EAX;

  uint uVar3;

  uint uVar4;

  int iVar5;

  int iVar6;

  byte bVar7;

  byte *pbVar8;

  int iVar9;

  byte *local_14;

  int local_10;

  int local_c;

  

  switch(in_EAX) {

  case 0:

    break;

  case 1:

    uVar3 = (int)(*(byte *)(param_2 + 0xb) + 7) >> 3;

    param_4 = param_4 + uVar3;

    if (uVar3 < *(uint *)(param_2 + 4)) {

      pbVar8 = param_4 + -uVar3;

      iVar5 = *(uint *)(param_2 + 4) - uVar3;

      do {

        *param_4 = *param_4 + *pbVar8;

        param_4 = param_4 + 1;

        pbVar8 = pbVar8 + 1;

        iVar5 = iVar5 + -1;

      } while (iVar5 != 0);

      return;

    }

    break;

  case 2:

    uVar3 = *(uint *)(param_2 + 4);

    uVar4 = 0;

    if (uVar3 != 0) {

      do {

        *param_4 = *param_4 + param_1[uVar4];

        uVar4 = uVar4 + 1;

        param_4 = param_4 + 1;

      } while (uVar4 < uVar3);

      return;

    }

    break;

  case 3:

    iVar5 = (int)(*(byte *)(param_2 + 0xb) + 7) >> 3;

    iVar6 = *(int *)(param_2 + 4) - iVar5;

    pbVar8 = param_4;

    for (; iVar5 != 0; iVar5 = iVar5 + -1) {

      *pbVar8 = *pbVar8 + (*param_1 >> 1);

      param_1 = param_1 + 1;

      pbVar8 = pbVar8 + 1;

    }

    if (iVar6 != 0) {

      do {

        *pbVar8 = *pbVar8 + (char)(((uint)*param_4 + (uint)*param_1) / 2);

        param_4 = param_4 + 1;

        param_1 = param_1 + 1;

        pbVar8 = pbVar8 + 1;

        iVar6 = iVar6 + -1;

      } while (iVar6 != 0);

      return;

    }

    break;

  case 4:

    iVar5 = (int)(*(byte *)(param_2 + 0xb) + 7) >> 3;

    local_c = *(int *)(param_2 + 4) - iVar5;

    pbVar8 = param_1;

    local_14 = param_4;

    for (; iVar5 != 0; iVar5 = iVar5 + -1) {

      *local_14 = *local_14 + *pbVar8;

      local_14 = local_14 + 1;

      pbVar8 = pbVar8 + 1;

    }

    if (local_c != 0) {

      do {

        bVar1 = *param_1;

        bVar2 = *pbVar8;

        bVar7 = *param_4;

        param_1 = param_1 + 1;

        param_4 = param_4 + 1;

        iVar5 = (uint)bVar2 - (uint)bVar1;

        pbVar8 = pbVar8 + 1;

        iVar6 = (uint)bVar7 - (uint)bVar1;

        local_10 = iVar5;

        if (iVar5 < 0) {

          local_10 = -iVar5;

        }

        iVar9 = iVar6;

        if (iVar6 < 0) {

          iVar9 = -iVar6;

        }

        iVar5 = iVar5 + iVar6;

        if (iVar5 < 0) {

          iVar5 = -iVar5;

        }

        if (((iVar9 < local_10) || (iVar5 < local_10)) && (bVar7 = bVar1, iVar9 <= iVar5)) {

          bVar7 = bVar2;

        }

        *local_14 = *local_14 + bVar7;

        local_14 = local_14 + 1;

        local_c = local_c + -1;

      } while (local_c != 0);

      return;

    }

    break;

  default:

    FUN_00476d60();

    *param_4 = 0;

  }

  return;

}

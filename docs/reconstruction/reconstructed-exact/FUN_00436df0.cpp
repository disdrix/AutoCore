// =============================================================================
// FUN_00436df0
// -----------------------------------------------------------------------------
// Stable ID: aa_00436df0
// Address:   0x00436df0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00436df0 @ 0x00436df0
// Stable ID: aa_00436df0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~78 non-empty decompiler lines.
//  - Control keywords: if×11, goto×5, while×3, return×3, do×2.
//  - Notable callees: FUN_00436df0, FUN_007662b0.
//  - Return sites: 3.

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

void FUN_00436df0(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  byte bVar1;

  uint uVar2;

  uint32_t /* width from decompiler */ *in_EAX;

  uint uVar3;

  byte *pbVar4;

  int iVar5;

  byte *pbVar6;

  int iVar7;

  byte *pbVar8;

  int *piVar9;

  bool bVar10;

  

  pbVar6 = (byte *)*in_EAX;

  uVar2 = *(uint *)(param_1 + 0x20);

  uVar3 = FUN_007662b0();

  uVar3 = uVar3 & uVar2;

  if (*(uint *)(param_1 + 0x24) <= uVar3) {

    uVar3 = uVar3 + (-1 - (uVar2 >> 1));

  }

  iVar7 = *(int *)(param_1 + 0x14);

  piVar9 = *(int **)(iVar7 + uVar3 * 4);

  if (piVar9 != *(int **)(iVar7 + 4 + uVar3 * 4)) {

    do {

      pbVar4 = (byte *)piVar9[2];

      pbVar8 = pbVar6;

      do {

        bVar1 = *pbVar4;

        bVar10 = bVar1 < *pbVar8;

        if (bVar1 != *pbVar8) {

LAB_00436e59:

          iVar5 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);

          goto LAB_00436e5e;

        }

        if (bVar1 == 0) break;

        bVar1 = pbVar4[1];

        bVar10 = bVar1 < pbVar8[1];

        if (bVar1 != pbVar8[1]) goto LAB_00436e59;

        pbVar4 = pbVar4 + 2;

        pbVar8 = pbVar8 + 2;

      } while (bVar1 != 0);

      iVar5 = 0;

LAB_00436e5e:

      if (-1 < iVar5) {

        pbVar4 = (byte *)piVar9[2];

        goto LAB_00436e90;

      }

      piVar9 = (int *)*piVar9;

    } while (piVar9 != (int *)*(int *)(iVar7 + uVar3 * 4 + 4));

  }

  *param_2 = *(uint32_t /* width from decompiler */ *)(param_1 + 8);

  return;

  while( true ) {

    bVar1 = pbVar6[1];

    bVar10 = bVar1 < pbVar4[1];

    if (bVar1 != pbVar4[1]) goto LAB_00436eb4;

    pbVar6 = pbVar6 + 2;

    pbVar4 = pbVar4 + 2;

    if (bVar1 == 0) break;

LAB_00436e90:

    bVar1 = *pbVar6;

    bVar10 = bVar1 < *pbVar4;

    if (bVar1 != *pbVar4) {

LAB_00436eb4:

      iVar7 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);

      goto LAB_00436eb9;

    }

    if (bVar1 == 0) break;

  }

  iVar7 = 0;

LAB_00436eb9:

  if (-1 < iVar7) {

    *param_2 = piVar9;

    return;

  }

  *param_2 = *(uint32_t /* width from decompiler */ *)(param_1 + 8);

  return;

}

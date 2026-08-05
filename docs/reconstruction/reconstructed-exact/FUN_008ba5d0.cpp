// =============================================================================
// FUN_008ba5d0
// -----------------------------------------------------------------------------
// Stable ID: aa_008ba5d0
// Address:   0x008ba5d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008ba5d0 @ 0x008ba5d0
// Stable ID: aa_008ba5d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~87 non-empty decompiler lines.
//  - Control keywords: if×14, goto×6, do×3, while×3, return×1.
//  - Notable callees: FUN_00791f30, FUN_008b92f0, FUN_008b9370, FUN_008ba5d0.
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

void __thiscall FUN_008ba5d0(int param_1,uint32_t /* width from decompiler */ param_2)



{

  byte bVar1;

  byte *pbVar2;

  byte *pbVar3;

  int iVar4;

  int *piVar5;

  bool bVar6;

  int local_10;

  

  iVar4 = *(int *)(param_1 + 0x5b0);

  if (((-1 < iVar4) && (iVar4 < 0xf)) && (*(int *)(param_1 + 0x568 + iVar4 * 4) != 0)) {

    piVar5 = (int *)(param_1 + 0x54c);

    local_10 = 0;

    do {

      if ((local_10 < 0) || (4 < local_10)) {

        pbVar3 = (byte *)0x0;

      }

      else {

        pbVar3 = *(byte **)(*(int *)(param_1 + 0x568 + *(int *)(param_1 + 0x5b0) * 4) +

                            (-0x48 - param_1) + (int)piVar5);

      }

      if (*piVar5 == 0) {

        pbVar2 = (byte *)0x0;

      }

      else {

        pbVar2 = (byte *)(**(code **)(*(int *)*piVar5 + 0x1dc))();

      }

      if ((pbVar3 == (byte *)0x0) || (pbVar2 == (byte *)0x0)) {

LAB_008ba696:

        FUN_008b9370(*(uint32_t /* width from decompiler */ *)(param_1 + 0x5b0));

      }

      else {

        do {

          bVar1 = *pbVar3;

          bVar6 = bVar1 < *pbVar2;

          if (bVar1 != *pbVar2) {

LAB_008ba685:

            iVar4 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);

            goto LAB_008ba68a;

          }

          if (bVar1 == 0) break;

          bVar1 = pbVar3[1];

          bVar6 = bVar1 < pbVar2[1];

          if (bVar1 != pbVar2[1]) goto LAB_008ba685;

          pbVar3 = pbVar3 + 2;

          pbVar2 = pbVar2 + 2;

        } while (bVar1 != 0);

        iVar4 = 0;

LAB_008ba68a:

        if (iVar4 != 0) goto LAB_008ba696;

      }

      local_10 = local_10 + 1;

      piVar5 = piVar5 + 1;

    } while (local_10 < 5);

    pbVar3 = *(byte **)(*(int *)(param_1 + 0x568 + *(int *)(param_1 + 0x5b0) * 4) + 0x518);

    if (*(int *)(param_1 + 0x564) == 0) {

      pbVar2 = (byte *)0x0;

    }

    else {

      pbVar2 = (byte *)(**(code **)(**(int **)(param_1 + 0x564) + 0x1dc))();

    }

    if ((pbVar3 != (byte *)0x0) && (pbVar2 != (byte *)0x0)) {

      do {

        bVar1 = *pbVar3;

        bVar6 = bVar1 < *pbVar2;

        if (bVar1 != *pbVar2) {

LAB_008ba724:

          iVar4 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);

          goto LAB_008ba729;

        }

        if (bVar1 == 0) break;

        bVar1 = pbVar3[1];

        bVar6 = bVar1 < pbVar2[1];

        if (bVar1 != pbVar2[1]) goto LAB_008ba724;

        pbVar3 = pbVar3 + 2;

        pbVar2 = pbVar2 + 2;

      } while (bVar1 != 0);

      iVar4 = 0;

LAB_008ba729:

      if (iVar4 == 0) goto LAB_008ba745;

    }

    FUN_008b92f0();

  }

LAB_008ba745:

  FUN_00791f30(param_2);

  return;

}

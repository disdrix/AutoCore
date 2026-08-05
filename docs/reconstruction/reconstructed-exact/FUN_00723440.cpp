// =============================================================================
// FUN_00723440
// -----------------------------------------------------------------------------
// Stable ID: aa_00723440
// Address:   0x00723440  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00723440 @ 0x00723440
// Stable ID: aa_00723440
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×8, return×3, do×2, goto×2, while×2.
//  - Notable callees: FUN_004801a0, FUN_00723440.
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

bool FUN_00723440(int param_1,byte *param_2,uint param_3,uint param_4,uint32_t /* width from decompiler */ param_5)



{

  byte bVar1;

  byte *pbVar2;

  int iVar3;

  int *piVar4;

  byte *pbVar5;

  int iVar6;

  bool bVar7;

  

  if ((*(char *)(param_1 + 600) == '\0') || (param_2 == (byte *)0x0)) {

    return true;

  }

  iVar6 = 0;

  if (0 < *(int *)(param_1 + 0x210)) {

    piVar4 = (int *)(param_1 + 0x31c);

    do {

      iVar3 = *piVar4;

      if (iVar3 != 0) {

        if (((*(uint *)(iVar3 + 0x40) == param_3) && (*(uint *)(iVar3 + 0x44) == param_4)) &&

           ((*(uint *)(iVar3 + 0x40) & *(uint *)(iVar3 + 0x44)) != 0xffffffff)) {

          pbVar5 = (byte *)(iVar3 + 0x48);

          pbVar2 = param_2;

          do {

            bVar1 = *pbVar2;

            bVar7 = bVar1 < *pbVar5;

            if (bVar1 != *pbVar5) {

LAB_007234bb:

              iVar3 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);

              goto LAB_007234c0;

            }

            if (bVar1 == 0) break;

            bVar1 = pbVar2[1];

            bVar7 = bVar1 < pbVar5[1];

            if (bVar1 != pbVar5[1]) goto LAB_007234bb;

            pbVar2 = pbVar2 + 2;

            pbVar5 = pbVar5 + 2;

          } while (bVar1 != 0);

          iVar3 = 0;

LAB_007234c0:

          if (iVar3 != 0) {

            FUN_004801a0(param_5);

            return *(char *)(*(int *)(param_1 + 0x31c + iVar6 * 4) + 0x1c5) != '\0';

          }

        }

      }

      iVar6 = iVar6 + 1;

      piVar4 = piVar4 + 1;

    } while (iVar6 < *(int *)(param_1 + 0x210));

  }

  return true;

}

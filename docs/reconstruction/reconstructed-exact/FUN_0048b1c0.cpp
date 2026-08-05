// =============================================================================
// FUN_0048b1c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0048b1c0
// Address:   0x0048b1c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0048b1c0 @ 0x0048b1c0
// Stable ID: aa_0048b1c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×6, do×2, goto×2, while×2, return×2.
//  - Notable callees: FUN_0048b1c0.
//  - Return sites: 2.

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

int __thiscall FUN_0048b1c0(int param_1,int *param_2)



{

  byte bVar1;

  byte *pbVar2;

  int iVar3;

  byte *pbVar4;

  int iVar5;

  bool bVar6;

  

  iVar5 = *(int *)(param_1 + 0x20);

  if (iVar5 != param_1) {

    do {

      if (**(int **)(iVar5 + 0x14) == *(int *)*param_2) {

        pbVar4 = (byte *)((int *)*param_2 + 2);

        pbVar2 = (byte *)(*(int **)(iVar5 + 0x14) + 2);

        do {

          bVar1 = *pbVar2;

          bVar6 = bVar1 < *pbVar4;

          if (bVar1 != *pbVar4) {

LAB_0048b214:

            iVar3 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);

            goto LAB_0048b219;

          }

          if (bVar1 == 0) break;

          bVar1 = pbVar2[1];

          bVar6 = bVar1 < pbVar4[1];

          if (bVar1 != pbVar4[1]) goto LAB_0048b214;

          pbVar2 = pbVar2 + 2;

          pbVar4 = pbVar4 + 2;

        } while (bVar1 != 0);

        iVar3 = 0;

LAB_0048b219:

        if (iVar3 == 0) {

          return iVar5;

        }

      }

      iVar5 = *(int *)(iVar5 + 0x20);

    } while (iVar5 != param_1);

  }

  return 0;

}

// =============================================================================
// FUN_005dc260
// -----------------------------------------------------------------------------
// Stable ID: aa_005dc260
// Address:   0x005dc260  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005dc260 @ 0x005dc260
// Stable ID: aa_005dc260
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×6, goto×5, while×2, do×1, for×1, return×1.
//  - Notable callees: FUN_005dc260.
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

void FUN_005dc260(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  uint *puVar3;

  uint *puVar4;

  uint *puVar5;

  uint *puVar6;

  

  puVar6 = *(uint **)(param_1 + 4);

  if (puVar6 != *(uint **)(param_1 + 8)) {

    do {

      iVar1 = *(int *)(param_2 + 0xe508);

      for (iVar2 = *(int *)(*(int *)(*(int *)(iVar1 + 0x10) + (*(uint *)(iVar1 + 8) & *puVar6) * 4)

                           + 4); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0xc)) {

        if (*puVar6 == *(uint *)(iVar2 + 0x10)) {

          if ((iVar2 != 0) && (*(int *)(iVar2 + 8) != 0)) {

            iVar1 = *(int *)(*(int *)(*(int *)(iVar1 + 0x10) +

                                     (*(uint *)(iVar1 + 8) & puVar6[1]) * 4) + 4);

            goto joined_r0x005dc2f5;

          }

          break;

        }

      }

LAB_005dc29c:

      puVar3 = *(uint **)(param_1 + 8);

      puVar4 = puVar6;

      puVar5 = puVar6;

      while (puVar5 = puVar5 + 3, puVar5 != puVar3) {

        *puVar4 = *puVar5;

        puVar4[1] = puVar5[1];

        puVar4[2] = puVar5[2];

        puVar4 = puVar4 + 3;

      }

      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0xc;

LAB_005dc2ce:

    } while (puVar6 != *(uint **)(param_1 + 8));

  }

  return;

joined_r0x005dc2f5:

  if (iVar1 == 0) goto LAB_005dc29c;

  if (puVar6[1] == *(uint *)(iVar1 + 0x10)) {

    if ((iVar1 != 0) && (*(int *)(iVar1 + 8) != 0)) {

      puVar6 = puVar6 + 3;

      goto LAB_005dc2ce;

    }

    goto LAB_005dc29c;

  }

  iVar1 = *(int *)(iVar1 + 0xc);

  goto joined_r0x005dc2f5;

}

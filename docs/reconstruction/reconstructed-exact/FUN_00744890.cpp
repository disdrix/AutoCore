// =============================================================================
// FUN_00744890
// -----------------------------------------------------------------------------
// Stable ID: aa_00744890
// Address:   0x00744890  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00744890 @ 0x00744890
// Stable ID: aa_00744890
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~58 non-empty decompiler lines.
//  - Control keywords: if×6, while×4, return×3, do×2.
//  - Notable callees: FUN_00426f60, FUN_0044d960, FUN_0044dc00, FUN_00744890.
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

int FUN_00744890(int param_1)



{

  char cVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int *piVar5;

  int *piVar6;

  int *in_EAX;

  int *piVar7;

  int *piVar8;

  

  FUN_00426f60();

  piVar7 = (int *)FUN_0044d960();

  iVar2 = *piVar7;

  iVar3 = piVar7[1];

  if (iVar2 != iVar3) {

    iVar4 = *in_EAX;

    do {

      if (*(int *)(iVar2 + 0xc) == iVar4) {

        return *(int *)(iVar2 + 0x10);

      }

      FUN_0044dc00();

    } while (iVar2 != iVar3);

  }

  piVar7 = *(int **)(param_1 + 0x14);

  piVar8 = (int *)*piVar7;

  if (piVar8 != piVar7) {

    do {

      if (piVar8[6] == *in_EAX) {

        return piVar8[7];

      }

      if (*(char *)((int)piVar8 + 0x25) == '\0') {

        piVar5 = (int *)piVar8[2];

        if (*(char *)((int)piVar5 + 0x25) == '\0') {

          cVar1 = *(char *)(*piVar5 + 0x25);

          piVar8 = piVar5;

          piVar5 = (int *)*piVar5;

          while (cVar1 == '\0') {

            cVar1 = *(char *)(*piVar5 + 0x25);

            piVar8 = piVar5;

            piVar5 = (int *)*piVar5;

          }

        }

        else {

          cVar1 = *(char *)(piVar8[1] + 0x25);

          piVar6 = (int *)piVar8[1];

          piVar5 = piVar8;

          while ((piVar8 = piVar6, cVar1 == '\0' && (piVar5 == (int *)piVar8[2]))) {

            cVar1 = *(char *)(piVar8[1] + 0x25);

            piVar6 = (int *)piVar8[1];

            piVar5 = piVar8;

          }

        }

      }

    } while (piVar8 != piVar7);

  }

  return 0;

}

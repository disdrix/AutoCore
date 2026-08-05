// =============================================================================
// FUN_004c9380
// -----------------------------------------------------------------------------
// Stable ID: aa_004c9380
// Address:   0x004c9380  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004c9380 @ 0x004c9380
// Stable ID: aa_004c9380
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~48 non-empty decompiler lines.
//  - Control keywords: if×3, while×3, do×1, return×1.
//  - Notable callees: FUN_004c9380, FUN_004cbe20.
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

void __fastcall FUN_004c9380(int param_1)



{

  char cVar1;

  int *piVar2;

  int *piVar3;

  int *piVar4;

  uint8_t local_20 [8];

  int local_18 [2];

  int local_10;

  int local_c;

  int local_8;

  int local_4;

  

  piVar4 = (int *)**(int **)(param_1 + 0x158);

  if (piVar4 != *(int **)(param_1 + 0x158)) {

    do {

      local_18[0] = piVar4[8];

      local_10 = piVar4[4];

      local_c = piVar4[5];

      local_8 = piVar4[6];

      local_4 = piVar4[7];

      FUN_004cbe20(local_20,local_18);

      if (*(char *)((int)piVar4 + 0x29) == '\0') {

        piVar2 = (int *)piVar4[2];

        if (*(char *)((int)piVar2 + 0x29) == '\0') {

          cVar1 = *(char *)(*piVar2 + 0x29);

          piVar4 = piVar2;

          piVar2 = (int *)*piVar2;

          while (cVar1 == '\0') {

            cVar1 = *(char *)(*piVar2 + 0x29);

            piVar4 = piVar2;

            piVar2 = (int *)*piVar2;

          }

        }

        else {

          cVar1 = *(char *)(piVar4[1] + 0x29);

          piVar3 = (int *)piVar4[1];

          piVar2 = piVar4;

          while ((piVar4 = piVar3, cVar1 == '\0' && (piVar2 == (int *)piVar4[2]))) {

            cVar1 = *(char *)(piVar4[1] + 0x29);

            piVar3 = (int *)piVar4[1];

            piVar2 = piVar4;

          }

        }

      }

    } while (piVar4 != *(int **)(param_1 + 0x158));

  }

  return;

}

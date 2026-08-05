// =============================================================================
// FUN_004a0470
// -----------------------------------------------------------------------------
// Stable ID: aa_004a0470
// Address:   0x004a0470  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004a0470 @ 0x004a0470
// Stable ID: aa_004a0470
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×3, while×3, do×1, return×1.
//  - Notable callees: FUN_004a0470, FUN_004b6ab0.
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

void __thiscall FUN_004a0470(int *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  char cVar1;

  int *piVar2;

  int *piVar3;

  int *piVar4;

  

  piVar4 = (int *)**(int **)(*param_1 + 4);

  if (piVar4 != *(int **)(*param_1 + 4)) {

    do {

      FUN_004b6ab0(param_2,param_3);

      if (*(char *)((int)piVar4 + 0x15) == '\0') {

        piVar2 = (int *)piVar4[2];

        if (*(char *)((int)piVar2 + 0x15) == '\0') {

          cVar1 = *(char *)(*piVar2 + 0x15);

          piVar4 = piVar2;

          piVar2 = (int *)*piVar2;

          while (cVar1 == '\0') {

            cVar1 = *(char *)(*piVar2 + 0x15);

            piVar4 = piVar2;

            piVar2 = (int *)*piVar2;

          }

        }

        else {

          cVar1 = *(char *)(piVar4[1] + 0x15);

          piVar3 = (int *)piVar4[1];

          piVar2 = piVar4;

          while ((piVar4 = piVar3, cVar1 == '\0' && (piVar2 == (int *)piVar4[2]))) {

            cVar1 = *(char *)(piVar4[1] + 0x15);

            piVar3 = (int *)piVar4[1];

            piVar2 = piVar4;

          }

        }

      }

    } while (piVar4 != *(int **)(*param_1 + 4));

  }

  return;

}

// =============================================================================
// FUN_00791260
// -----------------------------------------------------------------------------
// Stable ID: aa_00791260
// Address:   0x00791260  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00791260 @ 0x00791260
// Stable ID: aa_00791260
// Embedded strings (evidence for future rename):
//   - "HashError:TraverseToNext, not locked for traversal"
//   - "VOG_DEBUG_STOP"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~71 non-empty decompiler lines.
//  - Control keywords: if×9, while×2, return×2, for×1, do×1.
//  - Notable callees: FUN_007a4480×2, FUN_00411e10, FUN_00791260.
//  - Strings: "HashError:TraverseToNext, not locked for traversal"; "VOG_DEBUG_STOP".
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

int * __thiscall

FUN_00791260(int *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

            uint32_t /* width from decompiler */ param_5)



{

  int iVar1;

  int *piVar2;

  char cVar3;

  int *piVar4;

  int *piVar5;

  int iVar6;

  uint32_t /* width from decompiler */ unaff_retaddr;

  uint32_t /* width from decompiler */ uStack_8;

  

  uStack_8 = 0x79126c;

  cVar3 = (**(code **)(*param_1 + 0x3d8))();

  if ((cVar3 != '\0') && (param_1[0x130] != 0)) {

    uStack_8 = param_5;

    cVar3 = (**(code **)(*param_1 + 0x14c))(&param_2,param_4);

    if (cVar3 != '\0') {

      iVar6 = 0;

      FUN_00411e10();

      piVar4 = (int *)0x0;

      while( true ) {

        iVar1 = param_1[0x130];

        if (*(char *)(iVar1 + 0x1d) == '\0') {

          FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

          FUN_007a4480(0,"VOG_DEBUG_STOP");

        }

        if (iVar6 == 0) {

          iVar6 = *(int *)(iVar1 + 0x14);

        }

        else {

          iVar6 = *(int *)(iVar6 + 0x14);

        }

        if (iVar6 == 0) {

          piVar5 = (int *)0x0;

        }

        else {

          piVar5 = *(int **)(iVar6 + 8);

        }

        if (piVar5 == (int *)0x0) break;

        cVar3 = (**(code **)(*piVar5 + 0xd0))();

        if ((((cVar3 != '\0') && (cVar3 = (**(code **)(*piVar5 + 0x304))(), cVar3 == '\0')) &&

            (cVar3 = (**(code **)(*piVar5 + 0xd8))(), cVar3 != '\0')) &&

           ((cVar3 = (**(code **)(*piVar5 + 0x148))(&uStack_8,unaff_retaddr,param_2), cVar3 != '\0'

            && (((piVar4 == (int *)0x0 || (cVar3 = (**(code **)(*piVar5 + 200))(), cVar3 != '\0'))

                || (cVar3 = (**(code **)(*piVar4 + 200))(), cVar3 == '\0')))))) {

          piVar4 = piVar5;

        }

      }

      *(uint8_t *)(param_1[0x130] + 0x1d) = 0;

      piVar5 = *(int **)param_1[0x138];

      if (piVar5 != (int *)param_1[0x138]) {

        do {

          piVar2 = (int *)piVar5[2];

          cVar3 = (**(code **)(*piVar2 + 0xd0))();

          if (((cVar3 != '\0') && (cVar3 = (**(code **)(*piVar2 + 0x304))(), cVar3 == '\0')) &&

             (((cVar3 = (**(code **)(*piVar2 + 0xd8))(), cVar3 != '\0' &&

               (cVar3 = (**(code **)(*piVar2 + 0x148))(&uStack_8,unaff_retaddr,param_2),

               cVar3 != '\0')) &&

              (((piVar4 == (int *)0x0 || (cVar3 = (**(code **)(*piVar2 + 200))(), cVar3 != '\0')) ||

               (cVar3 = (**(code **)(*piVar4 + 200))(), cVar3 == '\0')))))) {

            piVar4 = piVar2;

          }

          piVar5 = (int *)*piVar5;

        } while (piVar5 != (int *)param_1[0x138]);

      }

      return piVar4;

    }

  }

  return (int *)0x0;

}

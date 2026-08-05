// =============================================================================
// FUN_00826f90
// -----------------------------------------------------------------------------
// Stable ID: aa_00826f90
// Address:   0x00826f90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00826f90 @ 0x00826f90
// Stable ID: aa_00826f90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×8, return×2.
//  - Notable callees: CNDHash_LookupByKey, FUN_005711c0, FUN_00826f90, sprintf.
//  - Strings: " %i".
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

void FUN_00826f90(void)



{

  uint key;

  char cVar1;

  int iVar2;

  void *pvVar3;

  int unaff_ESI;

  uint32_t /* width from decompiler */ uStack_44;

  char acStack_40 [64];

  

  if (*(int *)(unaff_ESI + 0x564) != 0) {

    iVar2 = *(int *)(unaff_ESI + 0x548);

    if (iVar2 == 2) {

      iVar2 = 0;

      key = *(uint *)(unaff_ESI + 0x550);

      if (((DAT_00d1b6d8 != 0) && (*(int *)(DAT_00d1b6d8 + 0x250) != 0)) &&

         (*(int *)(*(int *)(DAT_00d1b6d8 + 0x250) + 0x2b0) != 0)) {

        iVar2 = FUN_005711c0(key,0);

      }

      cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x564) + 0xf8))();

      if (cVar1 == '\0') {

        if (iVar2 < 1) {

          uStack_44 = 0x68ffffff;

          (**(code **)(**(int **)(unaff_ESI + 0x564) + 0x15c))(0,&uStack_44);

          (**(code **)(**(int **)(unaff_ESI + 0x564) + 0x15c))(1,&DAT_00afdf08);

        }

        else {

          uStack_44 = 0xffffffff;

          (**(code **)(**(int **)(unaff_ESI + 0x564) + 0x15c))(0,&uStack_44);

          (**(code **)(**(int **)(unaff_ESI + 0x564) + 0x15c))(1,&DAT_00afdf0c);

        }

      }

      pvVar3 = CNDHash_LookupByKey(*(void **)(DAT_00b041fc + 0xf10),key);

      if (((pvVar3 == (void *)0x0) || (*(int *)((int)pvVar3 + 0x3c) == 0)) ||

         ((*(byte *)(*(int *)((int)pvVar3 + 0x3c) + 0x3f2) & 0x40) != 0)) {

        sprintf(acStack_40," %i",iVar2);

      }

      else {

        acStack_40[0] = '\0';

      }

      (**(code **)(**(int **)(unaff_ESI + 0x564) + 0x1d8))(acStack_40,1,1);

      (**(code **)(**(int **)(unaff_ESI + 0x564) + 0x34c))();

    }

    else if (((iVar2 != 5) && (iVar2 != 4)) && (iVar2 != 3)) {

      iVar2 = (**(code **)(**(int **)(unaff_ESI + 0x564) + 0x1dc))();

      if (iVar2 != 0) {

        (**(code **)(**(int **)(unaff_ESI + 0x564) + 0x1d8))(&DAT_00a1419b,1,1);

        (**(code **)(**(int **)(unaff_ESI + 0x564) + 0x34c))();

        return;

      }

    }

  }

  return;

}

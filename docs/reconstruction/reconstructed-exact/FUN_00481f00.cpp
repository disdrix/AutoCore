// =============================================================================
// FUN_00481f00
// -----------------------------------------------------------------------------
// Stable ID: aa_00481f00
// Address:   0x00481f00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00481f00 @ 0x00481f00
// Stable ID: aa_00481f00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~71 non-empty decompiler lines.
//  - Control keywords: if×10, return×3.
//  - Notable callees: FUN_00481eb0, FUN_00481f00.
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

uint32_t /* width from decompiler */ FUN_00481f00(int param_1,int param_2,int param_3)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  int unaff_EDI;

  

  if ((((unaff_EDI != 0) && (0 < param_1)) && (param_1 < 10)) &&

     ((-1 < param_3 && (param_3 < 0xfb)))) {

    if (param_3 == 0) {

      param_3 = 0x1e;

    }

    if (*(int *)(unaff_EDI + 0x24) == 0) {

      *(code **)(unaff_EDI + 0x24) = FUN_0047f700;

    }

    if (*(int *)(unaff_EDI + 0x28) == 0) {

      *(code **)(unaff_EDI + 0x28) = FUN_00481e90;

    }

    piVar1 = (int *)(**(code **)(unaff_EDI + 0x24))(*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x2c),0xd9b0,1);

    if (piVar1 != (int *)0x0) {

      *piVar1 = unaff_EDI;

      piVar1[4] = 0;

      piVar1[5] = 0;

      piVar1[6] = 0;

      iVar2 = (**(code **)(unaff_EDI + 0x24))(*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x2c),param_1 * 400000,1);

      piVar1[4] = iVar2;

      iVar2 = (**(code **)(unaff_EDI + 0x24))

                        (*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x2c),param_1 * 400000 + 0x88,1);

      piVar1[5] = iVar2;

      iVar3 = (**(code **)(unaff_EDI + 0x24))(*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x2c),0x40004,1);

      iVar2 = piVar1[4];

      piVar1[6] = iVar3;

      if (iVar2 != 0) {

        if ((piVar1[5] != 0) && (iVar3 != 0)) {

          piVar1[2] = 2;

          piVar1[1] = 2;

          piVar1[0x9c] = param_1;

          piVar1[0x9a] = param_2;

          piVar1[9] = piVar1[5];

          piVar1[0x9b] = 0;

          piVar1[0x99] = 0;

          piVar1[0xc] = param_3;

          piVar1[10] = iVar2;

          piVar1[0xb] = 0;

          piVar1[8] = iVar2;

          piVar1[0x12] = param_1 * 100000 + -0x13;

          *(int **)(unaff_EDI + 0x20) = piVar1;

          *(uint32_t /* width from decompiler */ *)(unaff_EDI + 8) = 0;

          *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0xc) = 0;

          *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x18) = 0;

          *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x1c) = 0;

          piVar1[0xd] = 0x100;

          piVar1[0xe] = 0;

          FUN_00481eb0();

          return 0;

        }

        if (iVar2 != 0) {

          (**(code **)(unaff_EDI + 0x28))(*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x2c),iVar2);

        }

      }

      if (piVar1[5] != 0) {

        (**(code **)(unaff_EDI + 0x28))(*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x2c),piVar1[5]);

      }

      if (piVar1[6] != 0) {

        (**(code **)(unaff_EDI + 0x28))(*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x2c),piVar1[6]);

      }

      (**(code **)(unaff_EDI + 0x28))(*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x2c),piVar1);

    }

    return 0xfffffffd;

  }

  return 0xfffffffe;

}

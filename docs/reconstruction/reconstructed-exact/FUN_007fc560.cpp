// =============================================================================
// FUN_007fc560
// -----------------------------------------------------------------------------
// Stable ID: aa_007fc560
// Address:   0x007fc560  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007fc560 @ 0x007fc560
// Stable ID: aa_007fc560
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~52 non-empty decompiler lines.
//  - Control keywords: if×7, return×2.
//  - Notable callees: FUN_007fc490, FUN_007fc560.
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

void FUN_007fc560(void)



{

  int iVar1;

  int *piVar2;

  int unaff_ESI;

  uint32_t /* width from decompiler */ uVar3;

  

  FUN_007fc490(unaff_ESI);

  if (**(int **)(unaff_ESI + 0xf40) != 0) {

    (**(code **)(*(int *)**(int **)(unaff_ESI + 0xf40) + 0x3ec))();

    uVar3 = 1;

    (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0xf40) + 0x3f4))(1);

    (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0xf40) + 0xa8))

              (*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x111c));

    if (*(int **)(unaff_ESI + 0x111c) != (int *)0x0) {

      (**(code **)(**(int **)(unaff_ESI + 0x111c) + 0x43c))();

      iVar1 = *(int *)(unaff_ESI + 0x111c);

      *(uint8_t *)(iVar1 + 0x4fc) = 1;

      piVar2 = *(int **)(iVar1 + 0x530);

      if (piVar2 != (int *)0x0) {

        (**(code **)(*piVar2 + 0xcc))(1);

      }

      (**(code **)(**(int **)(unaff_ESI + 0x111c) + 0x444))(uVar3);

      iVar1 = *(int *)(unaff_ESI + 0x111c);

      if (*(int *)(iVar1 + 0x550) != 0) {

        (**(code **)(**(int **)(iVar1 + 0x550) + 0x74))(0xffffffff);

        (**(code **)(**(int **)(iVar1 + 0x550) + 0xcc))(0);

        (**(code **)(**(int **)(iVar1 + 0x550) + 0x34c))();

      }

      iVar1 = *(int *)(unaff_ESI + 0x111c);

      if (*(int *)(iVar1 + 0x554) != 0) {

        (**(code **)(**(int **)(iVar1 + 0x554) + 0x74))(0xffffffff);

        (**(code **)(**(int **)(iVar1 + 0x554) + 0xcc))(0);

        (**(code **)(**(int **)(iVar1 + 0x554) + 0x34c))();

      }

      (**(code **)(**(int **)(unaff_ESI + 0x111c) + 0x34c))();

    }

    piVar2 = *(int **)(unaff_ESI + 0xf38);

    if (piVar2 != (int *)0x0) {

      if (*(char *)(unaff_ESI + 0x31d9) == '\0') {

        *(uint8_t *)(unaff_ESI + 0x31d8) = 1;

      }

      else {

        *(uint8_t *)(unaff_ESI + 0x31d8) = *(uint8_t *)((int)piVar2 + 0x493);

      }

                    /* WARNING: Could not recover jumptable at 0x007fc6aa. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (**(code **)(*piVar2 + 0x3c4))(1);

      return;

    }

  }

  return;

}

// =============================================================================
// FUN_00831460
// -----------------------------------------------------------------------------
// Stable ID: aa_00831460
// Address:   0x00831460  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00831460 @ 0x00831460
// Stable ID: aa_00831460
// Embedded strings (evidence for future rename):
//   - "HashError:TraversalLock, already locked for traversal"
//   - "VOG_DEBUG_STOP"
//   - "HashError:TraverseToNext, not locked for traversal"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: if×7, for×2, while×1, return×1.
//  - Notable callees: FUN_007a4480×4, FUN_00831460, __RTDynamicCast.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal".
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

void __thiscall FUN_00831460(int *param_1,int *param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  int *piVar3;

  int iVar4;

  int *piVar5;

  

  iVar1 = param_1[0x14d];

  iVar4 = 0;

  if (*(char *)(iVar1 + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  *(uint8_t *)(iVar1 + 0x1d) = 1;

  while( true ) {

    iVar1 = param_1[0x14d];

    if (*(char *)(iVar1 + 0x1d) == '\0') {

      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    if (iVar4 == 0) {

      iVar4 = *(int *)(iVar1 + 0x14);

    }

    else {

      iVar4 = *(int *)(iVar4 + 0x14);

    }

    if (iVar4 == 0) {

      piVar5 = (int *)0x0;

    }

    else {

      piVar5 = *(int **)(iVar4 + 8);

    }

    if (piVar5 == (int *)0x0) break;

    if ((piVar5 != param_2) && (*param_2 <= *piVar5)) {

      uVar2 = (**(code **)(*param_1 + 0x3cc))

                        (piVar5[1],0,&CNDUIWindow::RTTI_Type_Descriptor,

                         &CNDUICtrlButton::RTTI_Type_Descriptor,0);

      piVar3 = (int *)__RTDynamicCast(uVar2);

      if (piVar3 != (int *)0x0) {

        (**(code **)(*piVar3 + 0x34c))();

      }

      (**(code **)(*param_1 + 0x458))(piVar5);

    }

  }

  *(uint8_t *)(param_1[0x14d] + 0x1d) = 0;

  return;

}

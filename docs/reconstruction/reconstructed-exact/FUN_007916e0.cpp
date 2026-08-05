// =============================================================================
// FUN_007916e0
// -----------------------------------------------------------------------------
// Stable ID: aa_007916e0
// Address:   0x007916e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007916e0 @ 0x007916e0
// Stable ID: aa_007916e0
// Embedded strings (evidence for future rename):
//   - "HashError:TraversalLock, already locked for traversal"
//   - "VOG_DEBUG_STOP"
//   - "HashError:TraverseToNext, not locked for traversal"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×8, goto×3, for×2, return×1.
//  - Notable callees: FUN_007a4480×4, FUN_007916e0, FUN_007a7a70.
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

void __thiscall FUN_007916e0(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  char cVar1;

  int iVar2;

  int *piVar3;

  int *piVar4;

  int iVar5;

  

  FUN_007a7a70(param_2);

  cVar1 = (**(code **)(*param_1 + 0x3d8))();

  if ((cVar1 != '\0') && (iVar2 = param_1[0x130], iVar2 != 0)) {

    iVar5 = 0;

    if (*(char *)(iVar2 + 0x1d) != '\0') {

      FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    *(uint8_t *)(iVar2 + 0x1d) = 1;

LAB_00791740:

    iVar2 = param_1[0x130];

    if (*(char *)(iVar2 + 0x1d) == '\0') {

      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    if (iVar5 == 0) {

      iVar5 = *(int *)(iVar2 + 0x14);

    }

    else {

      iVar5 = *(int *)(iVar5 + 0x14);

    }

    if (iVar5 == 0) {

      piVar4 = (int *)0x0;

    }

    else {

      piVar4 = *(int **)(iVar5 + 8);

    }

    if (piVar4 != (int *)0x0) {

      iVar2 = (**(code **)(*piVar4 + 0x34))();

      if (iVar2 != 0) goto code_r0x0079178d;

      goto LAB_007917a2;

    }

    *(uint8_t *)(param_1[0x130] + 0x1d) = 0;

  }

  return;

code_r0x0079178d:

  piVar3 = (int *)(**(code **)(*piVar4 + 0x34))();

  cVar1 = (**(code **)(*piVar3 + 0x3d8))();

  if (cVar1 != '\0') {

LAB_007917a2:

    (**(code **)(*piVar4 + 0xcc))(param_2);

  }

  goto LAB_00791740;

}

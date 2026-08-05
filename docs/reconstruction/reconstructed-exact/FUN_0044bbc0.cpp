// =============================================================================
// FUN_0044bbc0
// -----------------------------------------------------------------------------
// Stable ID: aa_0044bbc0
// Address:   0x0044bbc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0044bbc0 @ 0x0044bbc0
// Stable ID: aa_0044bbc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: FUN_00414cd0, FUN_0044bbc0, FUN_00999960, FUN_0099a3b0.
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

void FUN_0044bbc0(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int *piVar1;

  int *piVar2;

  int iVar3;

  int *piVar4;

  int unaff_EDI;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009bf04b;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  if (*(int *)(unaff_EDI + 4) == 0) {

    ExceptionList = &pvStack_c;

    iVar3 = FUN_00414cd0();

    local_4 = 0;

    if (iVar3 == 0) {

      piVar4 = (int *)0x0;

    }

    else {

      piVar4 = (int *)FUN_00999960();

    }

    local_4 = 0xffffffff;

    if ((piVar4 != (int *)0x0) && (piVar4[1] = piVar4[1] + 1, piVar4[1] == 1)) {

      (**(code **)(*piVar4 + 4))();

    }

    piVar2 = *(int **)(unaff_EDI + 4);

    if (piVar2 != (int *)0x0) {

      piVar1 = piVar2 + 1;

      *piVar1 = *piVar1 + -1;

      if (*piVar1 == 0) {

        (**(code **)(*piVar2 + 8))();

      }

    }

    *(int **)(unaff_EDI + 4) = piVar4;

  }

  FUN_0099a3b0(*(uint32_t /* width from decompiler */ *)(unaff_EDI + 4),*(uint32_t /* width from decompiler */ *)(param_1 + 4),param_2);

  ExceptionList = pvStack_c;

  return;

}

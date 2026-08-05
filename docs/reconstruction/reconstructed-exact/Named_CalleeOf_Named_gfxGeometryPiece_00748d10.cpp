// =============================================================================
// Named_CalleeOf_Named_gfxGeometryPiece_00748d10
// -----------------------------------------------------------------------------
// Stable ID: aa_00748d10
// Callee of Named_gfxGeometryPiece
// Address:   0x00748d10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxGeometryPiece: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~88 non-empty decompiler lines.
//  - Control keywords: if×18, return×1.
//  - Notable callees: FUN_00414a50×2, FUN_0044ba80, FUN_00748d10.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_gfxGeometryPiece
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_CalleeOf_Named_gfxGeometryPiece_00748d10(uint32_t /* width from decompiler */ *param_1)



{

  int *piVar1;

  int *piVar2;

  void *pvStack_c;

  uint8_t *puStack_8;

  int local_4;

  

  puStack_8 = &LAB_009b08b5;

  pvStack_c = ExceptionList;

  local_4 = 2;

  ExceptionList = &pvStack_c;

  if (param_1[1] != 0) {

    ExceptionList = &pvStack_c;

    if (*(char *)(param_1 + 6) != '\0') {

      ExceptionList = &pvStack_c;

      FUN_0044ba80();

    }

    piVar2 = (int *)param_1[1];

    if (piVar2 != (int *)0x0) {

      piVar1 = piVar2 + 1;

      *piVar1 = *piVar1 + -1;

      if (*piVar1 == 0) {

        (**(code **)(*piVar2 + 8))();

      }

      param_1[1] = 0;

    }

  }

  if (param_1[3] != 0) {

    if (*(char *)((int)param_1 + 0x19) != '\0') {

      FUN_00414a50();

    }

    piVar2 = (int *)param_1[3];

    if (piVar2 != (int *)0x0) {

      piVar1 = piVar2 + 1;

      *piVar1 = *piVar1 + -1;

      if (*piVar1 == 0) {

        (**(code **)(*piVar2 + 8))();

      }

      param_1[3] = 0;

    }

  }

  if (param_1[5] != 0) {

    if (*(char *)((int)param_1 + 0x1a) != '\0') {

      FUN_00414a50();

    }

    piVar2 = (int *)param_1[5];

    if (piVar2 != (int *)0x0) {

      piVar1 = piVar2 + 1;

      *piVar1 = *piVar1 + -1;

      if (*piVar1 == 0) {

        (**(code **)(*piVar2 + 8))();

      }

      param_1[5] = 0;

    }

  }

  local_4._0_1_ = 1;

  param_1[4] = &PTR_FUN_00a9db18;

  piVar2 = (int *)param_1[5];

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

  }

  local_4 = (uint)local_4._1_3_ << 8;

  param_1[2] = &PTR_FUN_00a9db18;

  piVar2 = (int *)param_1[3];

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

  }

  local_4 = 0xffffffff;

  *param_1 = &PTR_FUN_00a9da80;

  piVar2 = (int *)param_1[1];

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

  }

  ExceptionList = pvStack_c;

  return;

}

// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_anmTrackMaster_inl_0045cd30
// -----------------------------------------------------------------------------
// Stable ID: aa_0045cd30
// Callee of Named_CalleeOf_Named_anmTrackMaster_inl
// Address:   0x0045cd30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_anmTrackMaster_inl: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~95 non-empty decompiler lines.
//  - Control keywords: if×12, return×3.
//  - Notable callees: FUN_0045f360×4, FUN_0045f150×2, FUN_004540b0, FUN_0045cd30, FUN_0045efe0, FUN_00469c50, FUN_0046a240.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_anmTrackMaster_inl
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_anmTrackMaster_inl_0045cd30(uint param_1,int param_2,int param_3)



{

  void *pvVar1;

  int iVar2;

  void *pvVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint uVar5;

  uint extraout_ECX;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009bddf0;

  local_10 = ExceptionList;

  iVar2 = *(int *)(param_2 + 4);

  if (iVar2 == 0) {

    uVar5 = 0;

  }

  else {

    uVar5 = (*(int *)(param_2 + 0xc) - iVar2) / 0x1c;

  }

  if (param_1 != 0) {

    if (iVar2 == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = (*(int *)(param_2 + 8) - *(int *)(param_2 + 4)) / 0x1c;

    }

    ExceptionList = &local_10;

    if (0x9249249U - iVar2 < param_1) {

      ExceptionList = &local_10;

      FUN_004540b0();

      uVar5 = extraout_ECX;

    }

    if (*(int *)(param_2 + 4) == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = (*(int *)(param_2 + 8) - *(int *)(param_2 + 4)) / 0x1c;

    }

    if (uVar5 < iVar2 + param_1) {

      if (0x9249249 - (uVar5 >> 1) < uVar5) {

        uVar5 = 0;

      }

      else {

        uVar5 = uVar5 + (uVar5 >> 1);

      }

      if (*(int *)(param_2 + 4) == 0) {

        iVar2 = 0;

      }

      else {

        iVar2 = (*(int *)(param_2 + 8) - *(int *)(param_2 + 4)) / 0x1c;

      }

      if (uVar5 < iVar2 + param_1) {

        iVar2 = FUN_00469c50();

        uVar5 = iVar2 + param_1;

      }

      pvVar3 = operator_new(uVar5 * 0x1c);

      local_8 = 0;

      FUN_0045f360(param_3);

      FUN_0045f150(param_3);

      FUN_0045f360(param_3);

      pvVar1 = *(void **)(param_2 + 4);

      if (pvVar1 == (void *)0x0) {

        iVar2 = 0;

      }

      else {

        iVar2 = (*(int *)(param_2 + 8) - (int)pvVar1) / 0x1c;

      }

      if (pvVar1 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar1);

      }

      *(void **)(param_2 + 0xc) = (void *)(uVar5 * 0x1c + (int)pvVar3);

      *(void **)(param_2 + 8) = (void *)((int)pvVar3 + (param_1 + iVar2) * 0x1c);

      *(void **)(param_2 + 4) = pvVar3;

      ExceptionList = local_10;

      return;

    }

    if ((uint)((*(int *)(param_2 + 8) - param_3) / 0x1c) < param_1) {

      FUN_0045f360(param_3);

      local_8 = 2;

      FUN_0045f150(param_3);

      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + param_1 * 0x1c;

    }

    else {

      uVar4 = FUN_0045f360(param_3);

      *(uint32_t /* width from decompiler */ *)(param_2 + 8) = uVar4;

      FUN_0046a240();

    }

    FUN_0045efe0();

  }

  ExceptionList = local_10;

  return;

}

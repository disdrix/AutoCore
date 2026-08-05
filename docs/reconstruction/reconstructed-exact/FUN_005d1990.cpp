// =============================================================================
// FUN_005d1990
// -----------------------------------------------------------------------------
// Stable ID: aa_005d1990
// Address:   0x005d1990  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005d1990 @ 0x005d1990
// Stable ID: aa_005d1990
// Embedded strings (evidence for future rename):
//   - "HashError:TraversalLock, already locked for traversal"
//   - "VOG_DEBUG_STOP"
//   - "HashError:TraverseToNext, not locked for traversal"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~110 non-empty decompiler lines.
//  - Control keywords: if×8, do×2, while×2, for×2, return×2, goto×1.
//  - Notable callees: FUN_007a4480×4, CONCAT31, CVOGHBBase_AttachOwnerObject, CVOGHBBase_SetPeriodAndCounter, FUN_00439770, FUN_005ccf00, FUN_005d1990, FUN_006389c0.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal".
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

uint32_t /* width from decompiler */ * __thiscall FUN_005d1990(uint32_t /* width from decompiler */ *param_1,int param_2)



{

  int iVar1;

  int iVar2;

  void *pOwnerObject;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  int *piVar5;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a7000;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_006389c0();

  local_4 = 0;

  *param_1 = &PTR_FUN_009da984;

  param_1[0xc] = 0;

  param_1[0xe] = 0;

  param_1[0xf] = 0;

  *(uint8_t *)(param_1 + 0x18) = 0;

  param_1[0x19] = param_2;

  param_1[0x1a] = 0;

  *(uint8_t *)(param_1 + 0x1b) = 0;

  *(uint8_t *)((int)param_1 + 0x6d) = 0;

  *(uint8_t *)(param_1 + 0x25) = 0;

  *(uint8_t *)((int)param_1 + 0x95) = 0;

  *(uint8_t *)((int)param_1 + 0x96) = 0;

  iVar2 = FUN_00439770();

  param_1[0x27] = iVar2;

  *(uint8_t *)(iVar2 + 0x15) = 1;

  *(uint32_t /* width from decompiler */ *)(param_1[0x27] + 4) = param_1[0x27];

  *(uint32_t /* width from decompiler */ *)param_1[0x27] = param_1[0x27];

  *(uint32_t /* width from decompiler */ *)(param_1[0x27] + 8) = param_1[0x27];

  param_1[0x28] = 0;

  local_4 = CONCAT31(local_4._1_3_,1);

  CVOGHBBase_SetPeriodAndCounter(param_1,-1000,true);

  if (param_2 == 0) {

    pOwnerObject = (void *)0x0;

  }

  else {

    pOwnerObject = (void *)(*(int *)(*(int *)(param_2 + 4) + 4) + 4 + param_2);

  }

  CVOGHBBase_AttachOwnerObject(param_1,pOwnerObject);

  iVar2 = 3000;

  puVar3 = param_1 + 0x1c;

  do {

    puVar3[1] = iVar2;

    *(uint8_t *)(puVar3 + 2) = 0;

    *puVar3 = 0;

    iVar2 = iVar2 + 3000;

    puVar3 = puVar3 + 3;

  } while (iVar2 < 12000);

  param_1[0xd] = (float)(int)*(short *)(*(int *)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 0xac

                                                         + param_2) + 0x3c) + 0x4ec) *

                 g_flMsToSeconds_Inferred;

  param_1[0x14] = 0;

  param_1[0x15] = 0;

  param_1[0x16] = 0;

  param_1[0x17] = 0;

  iVar2 = *(int *)(*(int *)(*(int *)(param_1[0x19] + 4) + 4) + 0x74 + param_1[0x19]);

  if (*(char *)(iVar2 + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  *(uint8_t *)(iVar2 + 0x1d) = 1;

  iVar2 = 0;

  do {

    iVar4 = *(int *)(*(int *)(*(int *)(param_1[0x19] + 4) + 4) + 0x74 + param_1[0x19]);

    if (*(char *)(iVar4 + 0x1d) == '\0') {

      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    if (iVar2 == 0) {

      iVar2 = *(int *)(iVar4 + 0x14);

    }

    else {

      iVar2 = *(int *)(iVar2 + 0x14);

    }

    if (iVar2 == 0) {

      iVar4 = 0;

    }

    else {

      iVar4 = *(int *)(iVar2 + 8);

    }

    if (iVar4 == 0) goto LAB_005d1b36;

  } while ((*(byte *)(iVar4 + 0x614) & 8) == 0);

  *(uint8_t *)(param_1 + 0x25) = 1;

LAB_005d1b36:

  *(uint8_t *)(*(int *)(*(int *)(*(int *)(param_1[0x19] + 4) + 4) + 0x74 + param_1[0x19]) + 0x1d)

       = 0;

  FUN_005ccf00();

  iVar2 = param_1[0x19];

  iVar4 = *(int *)(*(int *)(iVar2 + 4) + 4);

  iVar1 = *(int *)(iVar2 + 0xa8 + iVar4);

  piVar5 = (int *)(iVar1 + 0x10);

  iVar2 = (**(code **)(*(int *)(iVar2 + iVar4 + 4) + 0x1dc))();

  if (iVar2 == 0) {

    if (*(int *)(param_1[0x19] + 0x250) != 0) {

      piVar5 = (int *)(iVar1 + 0x14);

      *piVar5 = *piVar5 + 1;

      ExceptionList = pvStack_c;

      return param_1;

    }

    *piVar5 = *piVar5 + 1;

  }

  ExceptionList = pvStack_c;

  return param_1;

}

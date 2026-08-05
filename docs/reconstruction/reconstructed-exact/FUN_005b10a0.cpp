// =============================================================================
// FUN_005b10a0
// -----------------------------------------------------------------------------
// Stable ID: aa_005b10a0
// Address:   0x005b10a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005b10a0 @ 0x005b10a0
// Stable ID: aa_005b10a0
// Embedded strings (evidence for future rename):
//   - "GhostObject::getUpdatePriority"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~62 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, goto×1.
//  - Notable callees: FUN_0076cef0×2, FUN_0040aff0, FUN_005b10a0, FUN_0076cf00, SQRT, TFID_EqualsObjectId.
//  - Strings: "GhostObject::getUpdatePriority".
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

float10 __thiscall

FUN_005b10a0(int param_1,int param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,int param_5)



{

  float fVar1;

  float fVar2;

  int *piVar3;

  int *piVar4;

  int iVar5;

  void *pA;

  float *pfVar6;

  uint8_t *puVar7;

  int *pB;

  float local_44;

  uint8_t auStack_30 [20];

  void *pvStack_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ local_14;

  

  local_14 = 0xffffffff;

  puStack_18 = &LAB_009a6748;

  pvStack_1c = ExceptionList;

  ExceptionList = &pvStack_1c;

  FUN_0076cf00("GhostObject::getUpdatePriority");

  piVar3 = *(int **)(param_1 + 0x50);

  local_14 = 0;

  if ((piVar3 == (int *)0x0) || (piVar4 = *(int **)(param_2 + 0x50), piVar4 == (int *)0x0)) {

    local_44 = (float)param_5 * DAT_00aaa7b8;

  }

  else {

    if ((((int *)piVar4[0x28] == piVar3) || (piVar4 == piVar3)) || (piVar4 == (int *)piVar3[0x2b]))

    {

LAB_005b122d:

      local_14 = 0xffffffff;

      FUN_0076cef0();

      ExceptionList = pvStack_1c;

      return (float10)g_flOne;

    }

    iVar5 = (**(code **)(*piVar3 + 0x1d8))();

    if (iVar5 != 0) {

      pB = piVar4 + 0x58;

      puVar7 = auStack_30;

      (**(code **)(*piVar3 + 0x1d8))(puVar7);

      pA = (void *)FUN_0040aff0(puVar7);

      iVar5 = TFID_EqualsObjectId(pA,pB);

      if ((char)iVar5 != '\0') goto LAB_005b122d;

    }

    pfVar6 = (float *)(**(code **)(*piVar4 + 0x1a0))();

    fVar1 = *pfVar6;

    fVar2 = pfVar6[2];

    pfVar6 = (float *)(**(code **)(*piVar3 + 0x1a0))();

    local_44 = *(float *)(param_1 + 0x58) *

               ((g_flOne -

                SQRT((fVar2 - pfVar6[2]) * (fVar2 - pfVar6[2]) +

                     (fVar1 - *pfVar6) * (fVar1 - *pfVar6)) /

                ((float)*(int *)(piVar4[0x29] + 0xe7d0) *

                 *(float *)(*(int *)(piVar4[0x29] + 0xe4f8) + 0x18) * DAT_00aaab3c)) * DAT_00a0f298

               + (float)param_5 * g_flMsToSeconds_Inferred);

  }

  local_14 = 0xffffffff;

  FUN_0076cef0();

  ExceptionList = pvStack_1c;

  return (float10)local_44;

}

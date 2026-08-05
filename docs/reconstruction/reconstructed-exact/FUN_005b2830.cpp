// =============================================================================
// FUN_005b2830
// -----------------------------------------------------------------------------
// Stable ID: aa_005b2830
// Address:   0x005b2830  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005b2830 @ 0x005b2830
// Stable ID: aa_005b2830
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~91 non-empty decompiler lines.
//  - Control keywords: if×6, return×4, while×1.
//  - Notable callees: BitStream_writeBits×2, CONCAT22×2, FUN_004022a0×2, CONCAT31, CVOGHBBase_GetRemainingSeconds, FUN_004294f0, FUN_005b13f0, FUN_005b2830.
//  - Return sites: 4.

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

void FUN_005b2830(uint32_t /* width from decompiler */ param_1,CVOGHBBase *param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  uint16_t *puVar3;

  CVOGHBBase *this;

  CVOGHBBase *pCVar4;

  uint16_t uVar5;

  void *pvVar6;

  uint16_t extraout_var;

  char cVar7;

  int iVar8;

  float fVar9;

  uint32_t /* width from decompiler */ local_38 [2];

  uint32_t /* width from decompiler */ uStack_30;

  uint32_t /* width from decompiler */ uStack_28;

  uint32_t /* width from decompiler */ uStack_24;

  void *pvStack_20;

  uint16_t *local_18;

  int local_14;

  uint32_t /* width from decompiler */ local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  pCVar4 = param_2;

  puStack_8 = &LAB_009a678c;

  pvStack_c = ExceptionList;

  iVar8 = 0;

  local_18 = (uint16_t *)0x0;

  local_14 = 0;

  local_10 = 0;

  local_4 = 0;

  local_38[0] = 0;

  ExceptionList = &pvStack_c;

  FUN_004294f0();

  FUN_004022a0(local_38,&param_2);

  puVar3 = (uint16_t *)0x0;

  this = param_2;

  while (param_2 = this, this != (CVOGHBBase *)0x0) {

    if ((this->nUnusedOrFlags == 1) &&

       ((this->nPeriodSentinel == -1000 ||

        (fVar9 = CVOGHBBase_GetRemainingSeconds(this), DAT_00a0f298 < fVar9)))) {

      pvVar6 = (void *)(**(code **)((int)this->pVTable + 0x28))();

      uVar5 = (**(code **)((int)this->pVTable + 0x20))(pvVar6);

      if (*(char *)((int)pvVar6 + 0x21) == -1) {

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar6);

      }

      uStack_24._0_1_ = this[0x27].cStopped;

      uStack_24._1_1_ = this[0x27].fDormant;

      uStack_24._2_1_ = this[0x27].cPad22;

      uStack_24._3_1_ = this[0x27].cPad23;

      uStack_30 = CONCAT22(uStack_30._2_2_,uVar5);

      uStack_28 = uStack_30;

      pvStack_20 = pvVar6;

      FUN_005b3110(&uStack_28);

      iVar8 = local_14;

    }

    FUN_004022a0(local_38,&param_2);

    puVar3 = local_18;

    this = param_2;

  }

  iVar2 = pCVar4[4].nPeriodCounter;

  if (*(char *)(iVar2 + 0x28) != '\0') {

    *(uint8_t *)(iVar2 + 0x28) = 0;

    LeaveCriticalSection((LPCRITICAL_SECTION)(iVar2 + 4));

  }

  if (puVar3 == (uint16_t *)0x0) {

    cVar7 = '\0';

  }

  else {

    cVar7 = (char)((iVar8 - (int)puVar3) / 0xc);

  }

  param_2 = (CVOGHBBase *)CONCAT31(param_2._1_3_,cVar7);

  BitStream_writeBits(8,&param_2);

  puVar3 = local_18;

  if (cVar7 != '\0') {

    puVar1 = (uint32_t /* width from decompiler */ *)(local_18 + 4);

    param_2 = (CVOGHBBase *)CONCAT22(extraout_var,*local_18);

    BitStream_writeBits(0x10,&param_2);

    FUN_005b13f0(param_1,*puVar1,*puVar3,*(uint32_t /* width from decompiler */ *)(puVar3 + 2));

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)*puVar1);

  }

  if (local_18 != (uint16_t *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(local_18);

  }

  ExceptionList = pvStack_c;

  return;

}

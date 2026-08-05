// =============================================================================
// CVOGSectorMap_StepTriggers
// -----------------------------------------------------------------------------
// Stable ID: aa_004d3980
// Address:   0x004d3980  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Domain alias CVOGSectorMap_StepTriggers for FUN_004d3980 @ 0x004d3980
// Stable ID: aa_004d3980
// Embedded strings (evidence for future rename):
//   - "CVOGSectorMap::StepTriggers"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~63 non-empty decompiler lines.
//  - Control keywords: if×5, return×2, while×1.
//  - Notable callees: FUN_004022a0×2, CVOGReaction_ResolveObjectTarget, FUN_00404bc0, FUN_004294f0, CVOGSectorMap_StepTriggers, FUN_004e3330, FUN_0076cef0, FUN_0076cf00.
//  - Strings: "CVOGSectorMap::StepTriggers".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "CVOGSectorMap::StepTriggers"
 * Domain alias of FUN_004d3980 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void CVOGSectorMap_StepTriggers(void)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ uVar5;

  void *pvVar6;

  int *unaff_EBX;

  uint32_t /* width from decompiler */ uVar7;

  TypeDescriptor *pTVar8;

  TypeDescriptor *pTVar9;

  uint32_t /* width from decompiler */ uVar10;

  uint8_t auStack_18 [4];

  uint32_t /* width from decompiler */ local_14;

  void *local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a2047;

  pvStack_c = ExceptionList;

  local_10 = DAT_00d1f040;

  ExceptionList = &pvStack_c;

  FUN_0076cf00("CVOGSectorMap::StepTriggers");

  local_4 = 0;

  local_14 = 0;

  iVar1 = FUN_00404bc0(0x38);

  if (iVar1 != 0) {

    FUN_004294f0();

    iVar2 = FUN_004022a0(auStack_18,&stack0xffffffe4);

    while (iVar2 == 0) {

      piVar3 = (int *)(**(code **)(*unaff_EBX + 0x1e8))();

      if ((char)piVar3[0x58] != '\0') {

        (**(code **)(*piVar3 + 0x50))();

      }

      iVar2 = FUN_004022a0(auStack_18,&stack0xffffffe4);

    }

    if (*(char *)(iVar1 + 0x28) != '\0') {

      *(uint8_t *)(iVar1 + 0x28) = 0;

      LeaveCriticalSection((LPCRITICAL_SECTION)(iVar1 + 4));

    }

  }

  puVar4 = (uint32_t /* width from decompiler */ *)FUN_004e3330();

  if (puVar4 != (uint32_t /* width from decompiler */ *)0x0) {

    uVar10 = 0;

    pTVar9 = &CVOGTrigger::RTTI_Type_Descriptor;

    pTVar8 = &CVOGClonedObjectBase::RTTI_Type_Descriptor;

    uVar7 = 0;

    uVar5 = CVOGReaction_ResolveObjectTarget(0,*puVar4,puVar4[1]);

    iVar1 = __RTDynamicCast(uVar5,uVar7,pTVar8,pTVar9,uVar10);

    if (iVar1 != 0) {

      pvVar6 = Object_ResolveFromTFID((TFID_16 *)(puVar4 + 2));

      (**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1) + 0x114))(pvVar6);

    }

                    /* WARNING: Subroutine does not return */

    operator_delete(puVar4);

  }

  puStack_8 = (uint8_t *)0xffffffff;

  FUN_0076cef0();

  ExceptionList = local_10;

  return;

}

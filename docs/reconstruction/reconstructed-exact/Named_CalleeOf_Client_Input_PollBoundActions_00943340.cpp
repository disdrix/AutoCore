// =============================================================================
// Named_CalleeOf_Client_Input_PollBoundActions_00943340
// -----------------------------------------------------------------------------
// Stable ID: aa_00943340
// Callee of Client_Input_PollBoundActions
// Address:   0x00943340  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_Input_PollBoundActions: input/binding helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~99 non-empty decompiler lines.
//  - Control keywords: if×9, return×3, goto×2, do×1, while×1.
//  - Notable callees: FUN_00930360, FUN_0093e120, FUN_00943340, Object_ResolveFromTFID.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Client_Input_PollBoundActions
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

void Named_CalleeOf_Client_Input_PollBoundActions_00943340(uint32_t /* width from decompiler */ param_1,char param_2)



{

  int iVar1;

  uint uVar2;

  int in_EAX;

  uint32_t /* width from decompiler */ *puVar3;

  uint uVar4;

  TFID_16 *pTVar5;

  void *pvVar6;

  int iVar7;

  uint uVar8;

  uint uStack_354;

  uint uStack_350;

  uint uStack_34c;

  int local_344;

  uint32_t /* width from decompiler */ uStack_340;

  uint32_t /* width from decompiler */ uStack_33c;

  uint32_t /* width from decompiler */ uStack_338;

  uint32_t /* width from decompiler */ uStack_334;

  TFID_16 aTStack_330 [50];

  

  iVar7 = *(int *)(in_EAX + 0xe98);

  if (*(char *)(iVar7 + 0x4f1) != '\0') {

    return;

  }

  iVar1 = *(int *)(in_EAX + 0x3048);

  local_344 = iVar1;

  puVar3 = (uint32_t /* width from decompiler */ *)

           (**(code **)(*(int *)(*(int *)(*(int *)(iVar7 + 4) + 4) + 4 + iVar7) + 0x1a0))();

  uStack_340 = *puVar3;

  uStack_33c = puVar3[1];

  uStack_338 = puVar3[2];

  uStack_334 = puVar3[3];

  aTStack_330[0].dwCoidLo._0_1_ = g_abTfidInvalid_A15870[0];

  aTStack_330[0].dwCoidLo._1_1_ = g_abTfidInvalid_A15870[1];

  aTStack_330[0].dwCoidLo._2_1_ = g_abTfidInvalid_A15870[2];

  aTStack_330[0].dwCoidLo._3_1_ = g_abTfidInvalid_A15870[3];

  aTStack_330[0].dwCoidHi._0_1_ = g_abTfidInvalid_A15870[4];

  aTStack_330[0].dwCoidHi._1_1_ = g_abTfidInvalid_A15870[5];

  aTStack_330[0].dwCoidHi._2_1_ = g_abTfidInvalid_A15870[6];

  aTStack_330[0].dwCoidHi._3_1_ = g_abTfidInvalid_A15870[7];

  aTStack_330[0].bGlobal = g_abTfidInvalid_A15870[8];

  aTStack_330[0].bPad0 = g_abTfidInvalid_A15870[9];

  aTStack_330[0].bPad1 = g_abTfidInvalid_A15870[10];

  aTStack_330[0].bPad2 = g_abTfidInvalid_A15870[0xb];

  aTStack_330[0].bPad3 = g_abTfidInvalid_A15870[0xc];

  aTStack_330[0].bPad4 = g_abTfidInvalid_A15870[0xd];

  aTStack_330[0].bPad5 = g_abTfidInvalid_A15870[0xe];

  aTStack_330[0].bPad6 = g_abTfidInvalid_A15870[0xf];

  if (*(int *)(in_EAX + 0xe98) == 0) {

    iVar7 = 0;

  }

  else {

    iVar7 = *(int *)(*(int *)(*(int *)(in_EAX + 0xe98) + 4) + 4) + 4 + *(int *)(in_EAX + 0xe98);

  }

  uStack_354 = Skill_GatherTargetsInArea

                         (aTStack_330,0,

                          *(uint32_t /* width from decompiler */ *)

                           (*(int *)(*(int *)(*(int *)(in_EAX + 0xe98) + 4) + 4) + 0xa8 +

                           *(int *)(in_EAX + 0xe98)),iVar7,&uStack_340,param_1,0x32,2,0,0,1,0,0,0,

                          0xbf800000);

  FUN_00930360(in_EAX,aTStack_330,&uStack_354);

  uVar2 = uStack_354;

  if (uStack_354 == 0) {

    return;

  }

  uVar4 = 0;

  uStack_354 = 0;

  if (iVar1 != 0) {

    uVar8 = 0;

    if (uVar2 != 0) {

      uStack_350 = *(uint *)(iVar1 + 0x160);

      uStack_34c = *(uint *)(iVar1 + 0x164);

      pTVar5 = aTStack_330;

      do {

        if (((pTVar5->dwCoidLo == uStack_350) && (pTVar5->dwCoidHi == uStack_34c)) &&

           (pTVar5->bGlobal == *(byte *)(local_344 + 0x168))) {

          uVar4 = (uint)(param_2 == '\0') * 2 + -1 + uVar8;

          if ((int)uVar4 < 0) {

            uVar4 = uVar4 + uVar2;

          }

          goto LAB_009434ae;

        }

        uVar8 = uVar8 + 1;

        pTVar5 = pTVar5 + 1;

      } while (uVar8 < uVar2);

      uVar4 = 0;

LAB_009434ae:

      if (uVar4 < uVar2) goto LAB_009434b4;

    }

    uVar4 = uVar4 - uVar2;

  }

LAB_009434b4:

  if ((((aTStack_330[uVar4].dwCoidLo & aTStack_330[uVar4].dwCoidHi) != 0xffffffff) ||

      (aTStack_330[uVar4].bGlobal != 0)) &&

     (pvVar6 = Object_ResolveFromTFID(aTStack_330 + uVar4), pvVar6 != (void *)0x0)) {

    FUN_0093e120(pvVar6);

  }

  return;

}

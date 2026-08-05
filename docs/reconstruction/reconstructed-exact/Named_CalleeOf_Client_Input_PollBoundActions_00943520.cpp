// =============================================================================
// Named_CalleeOf_Client_Input_PollBoundActions_00943520
// -----------------------------------------------------------------------------
// Stable ID: aa_00943520
// Callee of Client_Input_PollBoundActions
// Address:   0x00943520  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_Input_PollBoundActions: input/binding helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~71 non-empty decompiler lines.
//  - Control keywords: if×6, return×2.
//  - Notable callees: FUN_0093e120, FUN_00943520, Object_ResolveFromTFID.
//  - Return sites: 2.

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

void Named_CalleeOf_Client_Input_PollBoundActions_00943520(uint32_t /* width from decompiler */ param_1)



{

  int in_EAX;

  uint32_t /* width from decompiler */ *puVar1;

  void *pvVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uStack_40;

  uint32_t /* width from decompiler */ uStack_3c;

  uint32_t /* width from decompiler */ uStack_38;

  uint32_t /* width from decompiler */ uStack_34;

  TFID_16 aTStack_30 [2];

  

  iVar3 = *(int *)(in_EAX + 0xe98);

  if (*(char *)(iVar3 + 0x4f1) == '\0') {

    puVar1 = (uint32_t /* width from decompiler */ *)

             (**(code **)(*(int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3) + 0x1a0))();

    uStack_40 = *puVar1;

    uStack_3c = puVar1[1];

    uStack_38 = puVar1[2];

    uStack_34 = puVar1[3];

    aTStack_30[0].dwCoidLo._0_1_ = g_abTfidInvalid_A15870[0];

    aTStack_30[0].dwCoidLo._1_1_ = g_abTfidInvalid_A15870[1];

    aTStack_30[0].dwCoidLo._2_1_ = g_abTfidInvalid_A15870[2];

    aTStack_30[0].dwCoidLo._3_1_ = g_abTfidInvalid_A15870[3];

    aTStack_30[0].dwCoidHi._0_1_ = g_abTfidInvalid_A15870[4];

    aTStack_30[0].dwCoidHi._1_1_ = g_abTfidInvalid_A15870[5];

    aTStack_30[0].dwCoidHi._2_1_ = g_abTfidInvalid_A15870[6];

    aTStack_30[0].dwCoidHi._3_1_ = g_abTfidInvalid_A15870[7];

    aTStack_30[0].bGlobal = g_abTfidInvalid_A15870[8];

    aTStack_30[0].bPad0 = g_abTfidInvalid_A15870[9];

    aTStack_30[0].bPad1 = g_abTfidInvalid_A15870[10];

    aTStack_30[0].bPad2 = g_abTfidInvalid_A15870[0xb];

    aTStack_30[0].bPad3 = g_abTfidInvalid_A15870[0xc];

    aTStack_30[0].bPad4 = g_abTfidInvalid_A15870[0xd];

    aTStack_30[0].bPad5 = g_abTfidInvalid_A15870[0xe];

    aTStack_30[0].bPad6 = g_abTfidInvalid_A15870[0xf];

    if (*(int *)(in_EAX + 0xe98) == 0) {

      iVar3 = 0;

    }

    else {

      iVar3 = *(int *)(*(int *)(*(int *)(in_EAX + 0xe98) + 4) + 4) + 4 + *(int *)(in_EAX + 0xe98);

    }

    Skill_GatherTargetsInArea

              (aTStack_30,0,

               *(uint32_t /* width from decompiler */ *)

                (*(int *)(*(int *)(*(int *)(in_EAX + 0xe98) + 4) + 4) + 0xa8 +

                *(int *)(in_EAX + 0xe98)),iVar3,&uStack_40,param_1,1,2,0,0,1,0,1,1,0xbf800000);

    if (((aTStack_30[0].dwCoidLo & aTStack_30[0].dwCoidHi) == 0xffffffff) &&

       (aTStack_30[0].bGlobal == 0)) {

      if (*(int *)(in_EAX + 0xe98) == 0) {

        iVar3 = 0;

      }

      else {

        iVar3 = *(int *)(*(int *)(*(int *)(in_EAX + 0xe98) + 4) + 4) + 4 + *(int *)(in_EAX + 0xe98);

      }

      Skill_GatherTargetsInArea

                (aTStack_30,0,

                 *(uint32_t /* width from decompiler */ *)

                  (*(int *)(*(int *)(*(int *)(in_EAX + 0xe98) + 4) + 4) + 0xa8 +

                  *(int *)(in_EAX + 0xe98)),iVar3,&uStack_40,param_1,1,2,0,0,1,0,1,0,0xbf800000);

      if (((aTStack_30[0].dwCoidLo & aTStack_30[0].dwCoidHi) == 0xffffffff) &&

         (aTStack_30[0].bGlobal == 0)) {

        return;

      }

    }

    pvVar2 = Object_ResolveFromTFID(aTStack_30);

    if (pvVar2 != (void *)0x0) {

      FUN_0093e120(pvVar2);

    }

  }

  return;

}

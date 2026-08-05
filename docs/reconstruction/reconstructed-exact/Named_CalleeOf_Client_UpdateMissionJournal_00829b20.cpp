// =============================================================================
// Named_CalleeOf_Client_UpdateMissionJournal_00829b20
// -----------------------------------------------------------------------------
// Stable ID: aa_00829b20
// Callee of Client_UpdateMissionJournal
// Address:   0x00829b20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_UpdateMissionJournal: mission/objective helper. Evidence string: "[%d] %s". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "[%d] %s"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~54 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: FUN_006a3db0×3, CONCAT11, CONCAT12, CONCAT13, CONCAT31, FUN_0052b3b0, FUN_007a69d0, FUN_007a6de0.
//  - Strings: "[%d] %s".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_UpdateMissionJournal
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

void Named_CalleeOf_Client_UpdateMissionJournal_00829b20(void)



{

  uint8_t uVar1;

  char cVar2;

  uint8_t uVar3;

  int *in_EAX;

  int iVar4;

  int *unaff_EDI;

  uint32_t /* width from decompiler */ uStack_218;

  char acStack_1f4 [500];

  

  cVar2 = (**(code **)(*in_EAX + 0x3d8))();

  if ((cVar2 != '\0') && (unaff_EDI != (int *)0x0)) {

    if (in_EAX[0x142] != 0) {

      uStack_218 = unaff_EDI[0x53];

      iVar4 = unaff_EDI[0x47];

      FUN_007a69d0();

      FUN_007a6de0();

      uStack_218 = (int)(short)iVar4;

      sprintf(acStack_1f4,"[%d] %s");

      uStack_218 = 1;

      (**(code **)(*(int *)in_EAX[0x142] + 0x1d8))(acStack_1f4);

      (**(code **)(*(int *)in_EAX[0x142] + 0x21c))();

      (**(code **)(*(int *)in_EAX[0x142] + 0x34c))();

      if (DAT_00d1b6d8 != 0) {

        (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8) + 0x27c))

                  ();

      }

      FUN_0092d580();

      iVar4 = (**(code **)(*(int *)in_EAX[0x142] + 0x164))(1);

      uVar1 = *(uint8_t *)(iVar4 + 3);

      uVar3 = FUN_006a3db0();

      uStack_218._0_3_ = CONCAT12(uVar3,(uint16_t)uStack_218);

      uVar3 = FUN_006a3db0();

      uStack_218._0_2_ = CONCAT11(uVar3,(uint8_t)uStack_218);

      uVar3 = FUN_006a3db0();

      uStack_218 = CONCAT31(uStack_218._1_3_,uVar3);

      uStack_218 = CONCAT13(uVar1,(undefined3)uStack_218);

      (**(code **)(*(int *)in_EAX[0x142] + 0x15c))(1,&uStack_218);

    }

    if (DAT_00d1b6d8 != 0) {

      uStack_218 = 0x829c61;

      FUN_0052b3b0();

      FUN_00829ac0();

    }

    if (((int *)in_EAX[0x143] != (int *)0x0) && ((int *)in_EAX[0x142] != (int *)0x0)) {

      iVar4 = *(int *)in_EAX[0x143];

      uStack_218 = 0x829c86;

      uStack_218 = (**(code **)(*(int *)in_EAX[0x142] + 0x164))();

      (**(code **)(iVar4 + 0x154))(1);

    }

    in_EAX[0x140] = *unaff_EDI;

  }

  return;

}

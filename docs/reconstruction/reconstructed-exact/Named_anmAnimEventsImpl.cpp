// READABILITY (auto CF):
//  - Body size: ~94 non-empty decompiler lines.
//  - Control keywords: if×12, return×5, do×1, while×1.
//  - Notable callees: FUN_00769e40×5, vog_LogMessage×4, FUN_00437050, FUN_00450020, FUN_0073fad0, FUN_00768760, stoChunkReader_EnterChunkScope.
//  - Strings: ",0x111

                       ,3,"; ",0x115

                       ,3,"; ",

                           0x11b,3,".
//  - Return sites: 5.

// =============================================================================
// Named_anmAnimEventsImpl
// -----------------------------------------------------------------------------
// Stable ID: aa_0073fad0
// Address:   0x0073fad0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "anmAnimEventsImpl"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint Named_anmAnimEventsImpl(int param_1)



{

  uint uVar1;

  uint uVar2;

  int unaff_EBX;

  int unaff_EBP;

  int iVar3;

  int iVar4;

  int unaff_retaddr;

  uint32_t /* width from decompiler */ uVar5;

  char cStack_1c;

  char local_18;

  int local_14;

  void *local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b1950;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  stoChunkReader_EnterChunkScope();

  local_4 = 0;

  if (local_14 == 0x41455654) {

    if (local_10 == (void *)0x1) {

      uVar1 = (**(code **)(*(int *)(param_1 + 8) + 4))();

      if ((int)uVar1 < 0) {

        vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\animation\\anmAnimEventsImpl.cpp",0x111

                       ,3,"anmAnimEventsImpl: Error Reading Anim Events!");

        puStack_8 = (uint8_t *)0xffffffff;

        if (cStack_1c != '\0') {

          FUN_00769e40();

        }

        ExceptionList = local_10;

        return 0xffffffff;

      }

      if (*(int *)(unaff_EBX + 0x4044) == 0) {

        uVar2 = FUN_00437050(&stack0xffffffd8);

      }

      else {

        uVar2 = FUN_00768760(&stack0xffffffd8);

      }

      uVar1 = uVar1 | uVar2;

      if ((int)uVar1 < 0) {

        vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\animation\\anmAnimEventsImpl.cpp",0x115

                       ,3,"anmAnimEventsImpl: Error Reading track count!");

        puStack_8 = (uint8_t *)0xffffffff;

        if (cStack_1c != '\0') {

          FUN_00769e40();

        }

        ExceptionList = local_10;

        return 0xffffffff;

      }

      FUN_00450020(unaff_EBP);

      iVar4 = 0;

      if (0 < unaff_EBP) {

        iVar3 = 0;

        do {

          uVar2 = (**(code **)(*(int *)(iVar3 + *(int *)(unaff_retaddr + 0x28)) + 4))();

          uVar1 = uVar1 | uVar2;

          if ((int)uVar1 < 0) {

            vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\animation\\anmAnimEventsImpl.cpp",

                           0x11b,3,"anmTrackEvents: Error Reading track events!");

            puStack_8 = (uint8_t *)0xffffffff;

            if (cStack_1c != '\0') {

              FUN_00769e40();

            }

            ExceptionList = local_10;

            return 0xffffffff;

          }

          iVar4 = iVar4 + 1;

          iVar3 = iVar3 + 0x1c;

        } while (iVar4 < unaff_EBP);

      }

      puStack_8 = (uint8_t *)0xffffffff;

      if (cStack_1c != '\0') {

        FUN_00769e40();

      }

      ExceptionList = local_10;

      return uVar1;

    }

    uVar5 = 0x123;

  }

  else {

    uVar5 = 0x106;

  }

  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\animation\\anmAnimEventsImpl.cpp",uVar5,3);

  local_4 = 0xffffffff;

  if (local_18 != '\0') {

    FUN_00769e40();

  }

  ExceptionList = local_c;

  return 0xffffffff;

}

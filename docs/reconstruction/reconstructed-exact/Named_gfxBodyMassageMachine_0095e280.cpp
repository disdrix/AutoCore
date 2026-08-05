// READABILITY (auto CF):
//  - Body size: ~69 non-empty decompiler lines.
//  - Control keywords: if×6, return×2, do×1, while×1.
//  - Notable callees: FUN_00769e40×2, vog_LogMessage×2, FUN_00437050, FUN_00768760, FUN_0095d7b0, FUN_0095dc70, FUN_0095e280, FUN_0096ac60.
//  - Strings: ",

                       0x27e,2,"; "Invalid chunk version unserializing phySkeletonMaster"; "Invalid TAG unserializing phySkeletonMaster".
//  - Return sites: 2.

// =============================================================================
// Named_gfxBodyMassageMachine_0095e280
// -----------------------------------------------------------------------------
// Stable ID: aa_0095e280
// Address:   0x0095e280  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "gfxBodyMassageMachine"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint __thiscall Named_gfxBodyMassageMachine_0095e280(int param_1,int param_2)



{

  int iVar1;

  uint uVar2;

  uint uVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  char *pcVar6;

  int local_24 [3];

  char local_18;

  int local_14;

  int local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b1faf;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  stoChunkReader_EnterChunkScope(param_1);

  iVar4 = 0;

  local_4 = 0;

  if (local_14 == 0x534b454c) {

    if (local_10 == 1) {

      if (*(int *)(param_1 + 0x4044) == 0) {

        uVar2 = FUN_00437050(local_24);

      }

      else {

        uVar2 = FUN_00768760(local_24);

      }

      FUN_0096b150(param_2,local_24[0]);

      if (local_24[0] < 1) {

        vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxBodyMassageMachine.cpp",

                       0x27e,2,"no bones in skeleton");

      }

      else {

        do {

          iVar1 = *(int *)(*(int *)(param_2 + 0xc) + iVar4 * 4);

          *(int *)(iVar1 + 0x144) = iVar4;

          uVar3 = FUN_0095dc70(iVar1);

          iVar4 = iVar4 + 1;

          uVar2 = uVar2 | uVar3;

        } while (iVar4 < local_24[0]);

      }

      FUN_0096ac60();

      FUN_0095d7b0();

      local_4 = 0xffffffff;

      if (local_18 != '\0') {

        FUN_00769e40();

      }

      ExceptionList = local_c;

      return uVar2;

    }

    pcVar6 = "Invalid chunk version unserializing phySkeletonMaster";

    uVar5 = 0x28d;

  }

  else {

    pcVar6 = "Invalid TAG unserializing phySkeletonMaster";

    uVar5 = 0x271;

  }

  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxBodyMassageMachine.cpp",uVar5,3,

                 pcVar6);

  local_4 = 0xffffffff;

  if (local_18 != '\0') {

    FUN_00769e40();

  }

  ExceptionList = local_c;

  return 0xffffffff;

}

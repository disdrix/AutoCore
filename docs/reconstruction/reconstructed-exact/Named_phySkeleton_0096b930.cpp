// READABILITY (auto CF):
//  - Body size: ~62 non-empty decompiler lines.
//  - Control keywords: if×6, return×2, do×1, while×1.
//  - Notable callees: FUN_00769e40×2, vog_LogMessage×2, FUN_00437050, FUN_007689e0, FUN_0076cec0, FUN_0096b150, FUN_0096b930, phyBone_unserialize.
//  - Strings: "Invalid chunk version (%i) unserializing phySkeleton"; "C:\\vog\\1_code\\palantir\\palantir\\physics\\phySkeleton.cpp"; "Invalid TAG unserializing phySkeleton".
//  - Return sites: 2.

// =============================================================================
// Named_phySkeleton_0096b930
// -----------------------------------------------------------------------------
// Stable ID: aa_0096b930
// Address:   0x0096b930  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "phySkeleton"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Named_phySkeleton_0096b930(int param_1,int param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  int *piVar3;

  int iVar4;

  char local_18;

  int local_14;

  int local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  iVar4 = param_2;

  iVar1 = param_1;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b3077;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  stoChunkReader_EnterChunkScope(param_2);

  local_4 = 0;

  if (local_14 == 0x50534b45) {

    if (local_10 == 1) {

      if (*(int *)(iVar4 + 0x4044) == 0) {

        uVar2 = FUN_00437050(&param_1);

      }

      else {

        uVar2 = FUN_007689e0(&param_1);

      }

      FUN_0096b150(iVar1,param_1);

      piVar3 = *(int **)(iVar1 + 0xc);

      iVar4 = 0;

      if (piVar3 != *(int **)(iVar1 + 0x10)) {

        do {

          phyBone_unserialize();

          *(int *)(*piVar3 + 0x144) = iVar4;

          piVar3 = piVar3 + 1;

          iVar4 = iVar4 + 1;

        } while (piVar3 != *(int **)(iVar1 + 0x10));

      }

      *(int *)(iVar1 + 0x1c) = *(int *)(iVar1 + 0x1c) + 1;

      *(uint *)(iVar1 + 4) = *(uint *)(iVar1 + 4) | 3;

      local_4 = 0xffffffff;

      if (local_18 != '\0') {

        FUN_00769e40();

      }

      ExceptionList = local_c;

      return uVar2;

    }

    uVar2 = FUN_0076cec0(&param_2,"Invalid chunk version (%i) unserializing phySkeleton",local_10);

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\physics\\phySkeleton.cpp",0x53,3,uVar2);

  }

  else {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\physics\\phySkeleton.cpp",0x3a,3,

                   "Invalid TAG unserializing phySkeleton");

  }

  local_4 = 0xffffffff;

  if (local_18 != '\0') {

    FUN_00769e40();

  }

  ExceptionList = local_c;

  return 0xffffffff;

}

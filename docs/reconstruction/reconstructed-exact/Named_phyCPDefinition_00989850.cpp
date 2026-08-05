// READABILITY (auto CF):
//  - Body size: ~73 non-empty decompiler lines.
//  - Control keywords: if×6, return×2, do×1, while×1.
//  - Notable callees: FUN_00769e40×2, FUN_00437050, FUN_00437150, FUN_0043fe60, FUN_0044b0b0, FUN_0044b150, FUN_00768760, FUN_00989850.
//  - Strings: "Invalid version unserializing phyCPDefinitionImpl"; "Invalid TAG unserializing phyCPDefinitionGroupImpl"; "C:\\vog\\1_code\\palantir\\palantir\\physics\\phyCPDefinition.cpp".
//  - Return sites: 2.

// =============================================================================
// Named_phyCPDefinition_00989850
// -----------------------------------------------------------------------------
// Stable ID: aa_00989850
// Address:   0x00989850  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "phyCPDefinition"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint Named_phyCPDefinition_00989850(int param_1)



{

  int iVar1;

  int iVar2;

  uint uVar3;

  int iVar4;

  int unaff_EBX;

  uint32_t /* width from decompiler */ uVar5;

  char *pcVar6;

  uint32_t /* width from decompiler */ local_2c;

  uint local_28;

  int local_24 [3];

  char local_18;

  int local_14;

  int local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint local_4;

  

  iVar2 = param_1;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b243c;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  stoChunkReader_EnterChunkScope(unaff_EBX);

  local_4 = 0;

  if (local_14 == 0x43504447) {

    if (local_10 == 1) {

      local_2c = 0;

      local_4 = 1;

      if (*(int *)(unaff_EBX + 0x4044) == 0) {

        local_28 = FUN_00437050(local_24);

      }

      else {

        local_28 = FUN_00768760(local_24);

      }

      if (0 < local_24[0]) {

        param_1 = local_24[0];

        do {

          uVar3 = FUN_0044b0b0(unaff_EBX);

          iVar1 = *(int *)(iVar2 + 0xc);

          local_28 = local_28 | uVar3;

          iVar4 = FUN_0044b150(iVar1,*(uint32_t /* width from decompiler */ *)(iVar1 + 4));

          FUN_0043fe60();

          param_1 = param_1 + -1;

          *(int *)(iVar1 + 4) = iVar4;

          **(int **)(iVar4 + 4) = iVar4;

        } while (param_1 != 0);

      }

      local_4 = local_4 & 0xffffff00;

      FUN_00437150(&local_2c);

      local_4 = 0xffffffff;

      if (local_18 != '\0') {

        FUN_00769e40();

      }

      ExceptionList = local_c;

      return local_28;

    }

    pcVar6 = "Invalid version unserializing phyCPDefinitionImpl";

    uVar5 = 0xf7;

  }

  else {

    pcVar6 = "Invalid TAG unserializing phyCPDefinitionGroupImpl";

    uVar5 = 0xe0;

  }

  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\physics\\phyCPDefinition.cpp",uVar5,3,pcVar6)

  ;

  local_4 = 0xffffffff;

  if (local_18 != '\0') {

    FUN_00769e40();

  }

  ExceptionList = local_c;

  return 0xffffffff;

}

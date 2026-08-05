// READABILITY (auto CF):
//  - Body size: ~68 non-empty decompiler lines.
//  - Control keywords: if×7, return×2, do×1, while×1.
//  - Notable callees: FUN_00769e40×2, FUN_0096a7f0×2, FUN_00437050, FUN_007450b0, FUN_00745760, FUN_00745a30, FUN_00745bd0, FUN_00768760.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\assets\\assCatalog.cpp"; "Invalid TAG unserializing assCatalog".
//  - Return sites: 2.

// =============================================================================
// Named_assCatalog_00745bd0
// -----------------------------------------------------------------------------
// Stable ID: aa_00745bd0
// Address:   0x00745bd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "assCatalog"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall Named_assCatalog_00745bd0(uint32_t /* width from decompiler */ param_1,int param_2)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ local_3c;

  uint32_t /* width from decompiler */ local_38;

  uint32_t /* width from decompiler */ local_34;

  uint32_t /* width from decompiler */ local_30;

  int local_2c [5];

  char local_18;

  int local_14;

  int local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  iVar1 = param_2;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b236c;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  stoChunkReader_EnterChunkScope(param_2);

  local_4 = 0;

  if (local_14 == 0x43544c47) {

    if (local_10 == 1) {

      if (*(int *)(iVar1 + 0x4044) == 0) {

        FUN_00437050(&param_2);

      }

      else {

        FUN_00768760(&param_2);

      }

      if (param_2 != 0) {

        local_2c[1] = 0;

        local_2c[2] = 0;

        local_34 = 0;

        local_30 = 0;

        iVar2 = param_2;

        do {

          param_2 = 0;

          local_3c = 0;

          FUN_0096a7f0(&param_2,iVar1);

          FUN_0096a7f0(&local_3c,iVar1);

          local_2c[0] = param_2;

          local_38 = local_3c;

          FUN_007450b0(param_1,local_2c,&local_38);

          iVar2 = iVar2 + -1;

        } while (iVar2 != 0);

      }

    }

    else if (local_10 == 2) {

      FUN_00745a30(param_1);

      FUN_00745760(param_1,iVar1);

    }

    local_4 = 0xffffffff;

    if (local_18 != '\0') {

      FUN_00769e40();

    }

    ExceptionList = local_c;

    return 0;

  }

  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\assets\\assCatalog.cpp",0x15d,3,

                 "Invalid TAG unserializing assCatalog");

  local_4 = 0xffffffff;

  if (local_18 != '\0') {

    FUN_00769e40();

  }

  ExceptionList = local_c;

  return 0xffffffff;

}

// READABILITY (auto CF):
//  - Body size: ~52 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_00769e40×2, FUN_0076cef0×2, FUN_00435fe0, FUN_006346d0, FUN_00767fd0, FUN_0076cf00, stoChunkReader_EnterChunkScope, vog_LogMessage.
//  - Strings: "anmEventBase::Unserialize"; "Invalid chunk version unserializing anmEventBase"; "Invalid TAG unserializing anmEventBase"; "..\\..\\palantir\\palantir/animation/anmEventBase.h".
//  - Return sites: 2.

// =============================================================================
// Named_anmEventBase_006346d0
// -----------------------------------------------------------------------------
// Stable ID: aa_006346d0
// Address:   0x006346d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "anmEventBase"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall Named_anmEventBase_006346d0(int param_1,int param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  char *pcVar2;

  char local_18;

  int local_14;

  int local_10;

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a8c50;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0076cf00("anmEventBase::Unserialize");

  local_4 = 0;

  stoChunkReader_EnterChunkScope(param_2);

  local_4._0_1_ = 1;

  if (local_14 == 0x45565442) {

    if (local_10 == 1) {

      if (*(int *)(param_2 + 0x4044) == 0) {

        uVar1 = FUN_00435fe0(param_1 + 4);

      }

      else {

        uVar1 = FUN_00767fd0(param_1 + 4);

      }

      local_4 = (uint)local_4._1_3_ << 8;

      if (local_18 != '\0') {

        FUN_00769e40();

      }

      local_4 = 0xffffffff;

      FUN_0076cef0();

      ExceptionList = local_c;

      return uVar1;

    }

    pcVar2 = "Invalid chunk version unserializing anmEventBase";

    uVar1 = 0xbe;

  }

  else {

    pcVar2 = "Invalid TAG unserializing anmEventBase";

    uVar1 = 0xb0;

  }

  vog_LogMessage("..\\..\\palantir\\palantir/animation/anmEventBase.h",uVar1,3,pcVar2);

  local_4 = (uint)local_4._1_3_ << 8;

  if (local_18 != '\0') {

    FUN_00769e40();

  }

  local_4 = 0xffffffff;

  FUN_0076cef0();

  ExceptionList = local_c;

  return 0xffffffff;

}

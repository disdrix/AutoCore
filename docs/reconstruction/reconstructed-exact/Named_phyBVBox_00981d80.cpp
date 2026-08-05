// READABILITY (auto CF):
//  - Body size: ~54 non-empty decompiler lines.
//  - Control keywords: if×7, return×4.
//  - Notable callees: FUN_00769e40×4, stoChunkReader_readF32Array×2, vog_LogMessage×2, FUN_0072cde0, FUN_00981d80, stoChunkReader_EnterChunkScope.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\physics\\phyBVBox.cpp"; "Invalid TAG unserializing phyBVBox"; "Invalid chunk version unserializing phyBVBox".
//  - Return sites: 4.

// =============================================================================
// Named_phyBVBox_00981d80
// -----------------------------------------------------------------------------
// Stable ID: aa_00981d80
// Address:   0x00981d80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "phyBVBox"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int Named_phyBVBox_00981d80(int param_1)



{

  int iVar1;

  char local_18;

  int local_14;

  int local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b1df1;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  stoChunkReader_EnterChunkScope(param_1);

  local_4 = 0;

  if (local_14 != 0x42564258) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\physics\\phyBVBox.cpp",0x3b,3,

                   "Invalid TAG unserializing phyBVBox");

    local_4 = 0xffffffff;

    if (local_18 != '\0') {

      FUN_00769e40();

    }

    ExceptionList = local_c;

    return -1;

  }

  iVar1 = FUN_0072cde0(param_1);

  if (iVar1 != 0) {

    local_4 = 0xffffffff;

    if (local_18 != '\0') {

      FUN_00769e40();

    }

    ExceptionList = local_c;

    return iVar1;

  }

  if (local_10 != 1) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\physics\\phyBVBox.cpp",0x52,3,

                   "Invalid chunk version unserializing phyBVBox");

    local_4 = 0xffffffff;

    if (local_18 != '\0') {

      FUN_00769e40();

    }

    ExceptionList = local_c;

    return -1;

  }

  stoChunkReader_readF32Array(param_1);

  stoChunkReader_readF32Array(param_1);

  iVar1 = *(int *)(param_1 + 0x402c);

  local_4 = 0xffffffff;

  if (local_18 != '\0') {

    FUN_00769e40();

  }

  ExceptionList = local_c;

  return iVar1;

}

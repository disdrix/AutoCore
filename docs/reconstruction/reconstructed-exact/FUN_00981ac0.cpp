// =============================================================================
// FUN_00981ac0
// -----------------------------------------------------------------------------
// Stable ID: aa_00981ac0
// Address:   0x00981ac0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00981ac0 @ 0x00981ac0
// Stable ID: aa_00981ac0
// Embedded strings (evidence for future rename):
//   - "C:\\vog\\1_code\\palantir\\palantir\\physics\\phyBVSphere.cpp"
//   - "Invalid TAG unserializing phyBVSphere"
//   - "Invalid chunk version unserializing phyBVSphere"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: if×8, return×4.
//  - Notable callees: FUN_00769e40×4, vog_LogMessage×2, FUN_00435fe0, FUN_0072cde0, FUN_00767fd0, FUN_00981ac0, stoChunkReader_EnterChunkScope, stoChunkReader_readF32Array.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\physics\\phyBVSphere.cpp"; "Invalid TAG unserializing phyBVSphere"; "Invalid chunk version unserializing phyBVSphere".
//  - Return sites: 4.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int __thiscall FUN_00981ac0(int param_1,int param_2)



{

  int iVar1;

  char local_18;

  int local_14;

  int local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b1ddf;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  stoChunkReader_EnterChunkScope(param_2);

  local_4 = 0;

  if (local_14 != 0x42565350) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\physics\\phyBVSphere.cpp",0x39,3,

                   "Invalid TAG unserializing phyBVSphere");

    local_4 = 0xffffffff;

    if (local_18 != '\0') {

      FUN_00769e40();

    }

    ExceptionList = local_c;

    return -1;

  }

  iVar1 = FUN_0072cde0(param_2);

  if (iVar1 != 0) {

    local_4 = 0xffffffff;

    if (local_18 != '\0') {

      FUN_00769e40();

    }

    ExceptionList = local_c;

    return iVar1;

  }

  if (local_10 != 1) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\physics\\phyBVSphere.cpp",0x50,3,

                   "Invalid chunk version unserializing phyBVSphere");

    local_4 = 0xffffffff;

    if (local_18 != '\0') {

      FUN_00769e40();

    }

    ExceptionList = local_c;

    return -1;

  }

  stoChunkReader_readF32Array(param_2);

  if (*(int *)(param_2 + 0x4044) == 0) {

    FUN_00435fe0(param_1 + 0x14);

  }

  else {

    FUN_00767fd0(param_1 + 0x14);

  }

  iVar1 = *(int *)(param_2 + 0x402c);

  local_4 = 0xffffffff;

  if (local_18 != '\0') {

    FUN_00769e40();

  }

  ExceptionList = local_c;

  return (-1 < iVar1) - 1;

}

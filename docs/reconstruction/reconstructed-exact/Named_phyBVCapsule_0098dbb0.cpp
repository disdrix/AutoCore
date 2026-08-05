// READABILITY (auto CF):
//  - Body size: ~66 non-empty decompiler lines.
//  - Control keywords: if×8, return×4.
//  - Notable callees: FUN_00769e40×4, stoChunkReader_readF32Array×2, vog_LogMessage×2, FUN_00435fe0, FUN_0072cde0, FUN_00767fd0, FUN_0098dbb0, SQRT.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\physics\\phyBVCapsule.cpp"; "Invalid TAG unserializing phyBVCapsule"; "Invalid chunk version unserializing phyBVCapsule".
//  - Return sites: 4.

// =============================================================================
// Named_phyBVCapsule_0098dbb0
// -----------------------------------------------------------------------------
// Stable ID: aa_0098dbb0
// Address:   0x0098dbb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "phyBVCapsule"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int __thiscall Named_phyBVCapsule_0098dbb0(int param_1,int param_2)



{

  float *pfVar1;

  int iVar2;

  char local_18;

  int local_14;

  int local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b1788;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  stoChunkReader_EnterChunkScope(param_2);

  local_4 = 0;

  if (local_14 != 0x42564350) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\physics\\phyBVCapsule.cpp",0x3c,3,

                   "Invalid TAG unserializing phyBVCapsule");

    local_4 = 0xffffffff;

    if (local_18 != '\0') {

      FUN_00769e40();

    }

    ExceptionList = local_c;

    return -1;

  }

  iVar2 = FUN_0072cde0(param_2);

  if (iVar2 != 0) {

    local_4 = 0xffffffff;

    if (local_18 != '\0') {

      FUN_00769e40();

    }

    ExceptionList = local_c;

    return iVar2;

  }

  if (local_10 != 1) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\physics\\phyBVCapsule.cpp",0x55,3,

                   "Invalid chunk version unserializing phyBVCapsule");

    local_4 = 0xffffffff;

    if (local_18 != '\0') {

      FUN_00769e40();

    }

    ExceptionList = local_c;

    return -1;

  }

  stoChunkReader_readF32Array(param_2);

  stoChunkReader_readF32Array(param_2);

  pfVar1 = (float *)(param_1 + 0x20);

  if (*(int *)(param_2 + 0x4044) == 0) {

    FUN_00435fe0(pfVar1);

  }

  else {

    FUN_00767fd0(pfVar1);

  }

  *(float *)(param_1 + 0x24) =

       SQRT(*(float *)(param_1 + 0x14) * *(float *)(param_1 + 0x14) +

            *(float *)(param_1 + 0x18) * *(float *)(param_1 + 0x18) +

            *(float *)(param_1 + 0x1c) * *(float *)(param_1 + 0x1c)) + *pfVar1;

  iVar2 = *(int *)(param_2 + 0x402c);

  local_4 = 0xffffffff;

  if (local_18 != '\0') {

    FUN_00769e40();

  }

  ExceptionList = local_c;

  return iVar2;

}

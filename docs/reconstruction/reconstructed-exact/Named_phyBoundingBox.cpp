// READABILITY (auto CF):
//  - Body size: ~80 non-empty decompiler lines.
//  - Control keywords: if×9, return×3.
//  - Notable callees: stoChunkReader_readF32Array×6, FUN_00769e40×3, ABS×2, FUN_00435fe0×2, FUN_00767fd0×2, SQRT×2, vog_LogMessage×2, FUN_00437000.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\physics\\phyBoundingBox.cpp"; "Invalid TAG unserializing phyBoundingBox"; "Invalid chunk version unserializing phyBoundingBox".
//  - Return sites: 3.

// =============================================================================
// Named_phyBoundingBox
// -----------------------------------------------------------------------------
// Stable ID: aa_0074ce60
// Address:   0x0074ce60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "phyBoundingBox"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int __fastcall Named_phyBoundingBox(float *param_1)



{

  float *pfVar1;

  int iVar2;

  int unaff_EBX;

  char local_18;

  int local_14;

  int local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b1ab3;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  stoChunkReader_EnterChunkScope(unaff_EBX);

  local_4 = 0;

  if (local_14 != 0x42424f58) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\physics\\phyBoundingBox.cpp",0x7e,3,

                   "Invalid TAG unserializing phyBoundingBox");

    local_4 = 0xffffffff;

    if (local_18 != '\0') {

      FUN_00769e40();

    }

    ExceptionList = local_c;

    return -1;

  }

  if (local_10 == 1) {

    stoChunkReader_readF32Array(unaff_EBX);

    stoChunkReader_readF32Array(unaff_EBX);

    stoChunkReader_readF32Array(unaff_EBX);

    pfVar1 = param_1 + 3;

    if (*(int *)(unaff_EBX + 0x4044) == 0) {

      FUN_00435fe0(pfVar1);

    }

    else {

      FUN_00767fd0(pfVar1);

    }

    param_1[4] = ABS(SQRT((param_1[10] - param_1[2]) * (param_1[10] - param_1[2]) +

                          (param_1[8] - *param_1) * (param_1[8] - *param_1)));

    *(bool *)(param_1 + 0xb) = *pfVar1 <= 0.0;

    iVar2 = *(int *)(unaff_EBX + 0x402c);

  }

  else {

    if (local_10 != 2) {

      vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\physics\\phyBoundingBox.cpp",0x9c,3,

                     "Invalid chunk version unserializing phyBoundingBox");

      local_4 = 0xffffffff;

      if (local_18 != '\0') {

        FUN_00769e40();

      }

      ExceptionList = local_c;

      return -1;

    }

    if (*(int *)(unaff_EBX + 0x4044) == 0) {

      FUN_00437000();

    }

    else {

      FUN_00769660(param_1 + 0xb);

    }

    stoChunkReader_readF32Array(unaff_EBX);

    stoChunkReader_readF32Array(unaff_EBX);

    stoChunkReader_readF32Array(unaff_EBX);

    if (*(int *)(unaff_EBX + 0x4044) == 0) {

      FUN_00435fe0(param_1 + 3);

    }

    else {

      FUN_00767fd0(param_1 + 3);

    }

    param_1[4] = ABS(SQRT((param_1[10] - param_1[2]) * (param_1[10] - param_1[2]) +

                          (param_1[8] - *param_1) * (param_1[8] - *param_1)));

    iVar2 = *(int *)(unaff_EBX + 0x402c);

  }

  local_4 = 0xffffffff;

  if (local_18 != '\0') {

    FUN_00769e40();

  }

  ExceptionList = local_c;

  return (-1 < iVar2) - 1;

}

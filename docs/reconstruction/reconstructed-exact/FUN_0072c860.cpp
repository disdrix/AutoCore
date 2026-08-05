// =============================================================================
// FUN_0072c860
// -----------------------------------------------------------------------------
// Stable ID: aa_0072c860
// Address:   0x0072c860  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0072c860 @ 0x0072c860
// Stable ID: aa_0072c860
// Embedded strings (evidence for future rename):
//   - "C:\\vog\\1_code\\palantir\\palantir\\physics\\phyBVWalkableSurface.cpp"
//   - "Invalid TAG unserializing phyBVWalkableSurface"
//   - "Invalid chunk version unserializing phyBVWalkableSurface"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~84 non-empty decompiler lines.
//  - Control keywords: if×12, return×4.
//  - Notable callees: FUN_00769e40×4, FUN_00437050×2, FUN_007689e0×2, vog_LogMessage×2, FUN_00437000, FUN_0044ed70, FUN_0072c860, FUN_0072cde0.
//  - Strings: ",0x180,3,

                   "; ",0x1a1,3,

                   ".
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

int __thiscall FUN_0072c860(int *param_1,int param_2)



{

  int *piVar1;

  int iVar2;

  void *pvVar3;

  char cStack_18;

  int iStack_14;

  uint uStack_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009b1e03;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  (**(code **)(*param_1 + 8))();

  stoChunkReader_EnterChunkScope(param_2);

  uStack_4 = 0;

  if (iStack_14 != 0x42565753) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\physics\\phyBVWalkableSurface.cpp",0x180,3,

                   "Invalid TAG unserializing phyBVWalkableSurface");

    uStack_4 = 0xffffffff;

    if (cStack_18 != '\0') {

      FUN_00769e40();

    }

    ExceptionList = pvStack_c;

    return -1;

  }

  iVar2 = FUN_0072cde0(param_2);

  if (iVar2 != 0) {

    uStack_4 = 0xffffffff;

    if (cStack_18 != '\0') {

      FUN_00769e40();

    }

    ExceptionList = pvStack_c;

    return iVar2;

  }

  if (uStack_10 != 0) {

    if (*(int *)(param_2 + 0x4044) == 0) {

      FUN_00437050(param_1 + 3);

    }

    else {

      FUN_007689e0(param_1 + 3);

    }

    piVar1 = param_1 + 4;

    if (*(int *)(param_2 + 0x4044) == 0) {

      FUN_00437050(piVar1);

    }

    else {

      FUN_007689e0(piVar1);

    }

    pvVar3 = operator_new__(*piVar1 * 0xc);

    param_1[5] = (int)pvVar3;

    stoChunkReader_readF32Array(param_2);

    pvVar3 = operator_new__(param_1[3] * 6);

    param_1[6] = (int)pvVar3;

    FUN_0044ed70();

  }

  if (uStack_10 == 2) {

    if (*(int *)(param_2 + 0x4044) == 0) {

      FUN_00437000();

    }

    else {

      FUN_00769660(param_1 + 0x3c);

    }

  }

  else if (2 < uStack_10) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\physics\\phyBVWalkableSurface.cpp",0x1a1,3,

                   "Invalid chunk version unserializing phyBVWalkableSurface");

    uStack_4 = 0xffffffff;

    if (cStack_18 != '\0') {

      FUN_00769e40();

    }

    ExceptionList = pvStack_c;

    return -1;

  }

  iVar2 = *(int *)(param_2 + 0x402c);

  uStack_4 = 0xffffffff;

  if (cStack_18 != '\0') {

    FUN_00769e40();

  }

  ExceptionList = pvStack_c;

  return (-1 < iVar2) - 1;

}

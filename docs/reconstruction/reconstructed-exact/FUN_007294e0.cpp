// =============================================================================
// FUN_007294e0
// -----------------------------------------------------------------------------
// Stable ID: aa_007294e0
// Address:   0x007294e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007294e0 @ 0x007294e0
// Stable ID: aa_007294e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~58 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_0043d4a0×2, free×2, CONCAT31, FUN_00445170, FUN_0046e390, FUN_007294e0, FUN_007679e0, FUN_007693e0.
//  - Return sites: 2.

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

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



uint32_t /* width from decompiler */ FUN_007294e0(uint32_t /* width from decompiler */ param_1,ushort param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint8_t local_408d;

  undefined **local_408c;

  void *local_4088;

  uint32_t /* width from decompiler */ local_4084;

  uint local_4080;

  uint local_407c;

  char local_4078;

  uint8_t local_4077;

  uint8_t local_4074 [16452];

  int local_30;

  uint32_t /* width from decompiler */ uStack_10;

  void *local_c;

  uint8_t *puStack_8;

  uint local_4;

  

  puStack_8 = &LAB_009b10ff;

  local_c = ExceptionList;

  uStack_10 = 0x7294ff;

  local_4080 = (uint)param_2;

  local_408c = &PTR_FUN_00a9d184;

  local_4084 = 0;

  local_4078 = '\0';

  local_4077 = 1;

  local_4 = 0;

  ExceptionList = &local_c;

  local_407c = local_4080;

  FUN_007679e0(local_4074,0,0);

  local_4 = CONCAT31(local_4._1_3_,1);

  if (local_30 == 0) {

    iVar1 = FUN_00445170(&local_408d);

  }

  else {

    iVar1 = FUN_007693e0(&local_408d);

  }

  if (-1 < iVar1) {

    uVar2 = FUN_0046e390(param_1);

    local_4 = local_4 & 0xffffff00;

    FUN_0043d4a0();

    local_408c = &PTR_FUN_00a9d184;

    if (local_4078 != '\0') {

      free(local_4088);

    }

    ExceptionList = local_c;

    return uVar2;

  }

  local_4 = local_4 & 0xffffff00;

  FUN_0043d4a0();

  local_408c = &PTR_FUN_00a9d184;

  if (local_4078 != '\0') {

    free(local_4088);

  }

  ExceptionList = local_c;

  return 0xffffffff;

}

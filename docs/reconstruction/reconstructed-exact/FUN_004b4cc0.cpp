// =============================================================================
// FUN_004b4cc0
// -----------------------------------------------------------------------------
// Stable ID: aa_004b4cc0
// Address:   0x004b4cc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004b4cc0 @ 0x004b4cc0
// Stable ID: aa_004b4cc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_004b4cc0, FUN_005c65c0, FUN_005c65e0, FUN_005c6610, FUN_005c6630, NxCloseCooking, NxCookClothMesh, NxInitCooking.
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

uint32_t /* width from decompiler */ __thiscall FUN_004b4cc0(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  char cVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint8_t local_1c [12];

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a144b;

  local_c = ExceptionList;

  uVar2 = 0;

  if (*param_1 == 0) {

    return 0;

  }

  ExceptionList = &local_c;

  NxInitCooking(0,0);

  FUN_005c65c0();

  local_4 = 0;

  cVar1 = NxCookClothMesh(param_2,local_1c);

  NxCloseCooking();

  if (cVar1 != '\0') {

    uVar2 = FUN_005c6610(local_10);

    local_4._0_1_ = 1;

    uVar2 = (**(code **)(*(int *)*param_1 + 0x44))(uVar2);

    local_4 = (uint)local_4._1_3_ << 8;

    FUN_005c6630();

  }

  local_4 = 0xffffffff;

  FUN_005c65e0();

  ExceptionList = local_c;

  return uVar2;

}

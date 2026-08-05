// =============================================================================
// FUN_004b4bf0
// -----------------------------------------------------------------------------
// Stable ID: aa_004b4bf0
// Address:   0x004b4bf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004b4bf0 @ 0x004b4bf0
// Stable ID: aa_004b4bf0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: CONCAT31, FUN_004b4bf0, FUN_005c65c0, FUN_005c65e0, FUN_005c6610, FUN_005c6630, NxCloseCooking, NxCookConvexMesh.
//  - Return sites: 1.

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

uint32_t /* width from decompiler */ __thiscall FUN_004b4bf0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  char cVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint8_t local_1c [12];

  uint32_t /* width from decompiler */ local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a1431;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  NxInitCooking(0,0);

  FUN_005c65c0();

  local_4 = 0;

  cVar1 = NxCookConvexMesh(param_2,local_1c);

  NxCloseCooking();

  if (cVar1 == '\0') {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_005c6610(local_10);

    local_4 = CONCAT31(local_4._1_3_,1);

    uVar2 = (**(code **)(*(int *)*param_1 + 0x3c))(uVar2);

  }

  local_4 = 0;

  if (cVar1 != '\0') {

    FUN_005c6630();

  }

  local_4 = 0xffffffff;

  FUN_005c65e0();

  ExceptionList = pvStack_c;

  return uVar2;

}

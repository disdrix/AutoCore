// =============================================================================
// Inv_GenerateLootItem_type
// -----------------------------------------------------------------------------
// Stable ID: aa_004d0cf0
// Address:   0x004d0cf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Inv_GenerateLootItem_type @ 0x004d0cf0
// Stable ID: aa_004d0cf0
// Embedded strings (evidence for future rename):
//   - "GenerateLootItem (type)"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~66 non-empty decompiler lines.
//  - Control keywords: if×3, for×1, return×1.
//  - Notable callees: Inv_GenerateLootItem_type, FUN_0050b6c0, FUN_005e0580, FUN_005e1030, FUN_0076cef0, FUN_0076cf00, GenerateLootItem.
//  - Strings: "GenerateLootItem (type)".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "GenerateLootItem (type)"
 * Domain alias of FUN_004d0cf0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int * Inv_GenerateLootItem_type(uint32_t /* width from decompiler */ param_1,int param_2,uint32_t /* width from decompiler */ param_3)



{

  int *piVar1;

  int iVar2;

  uint *puVar3;

  uint *puVar4;

  uint auStack_64 [5];

  uint32_t /* width from decompiler */ uStack_50;

  uint32_t /* width from decompiler */ uStack_4c;

  uint32_t /* width from decompiler */ uStack_48;

  char *pcStack_44;

  uint local_2c [4];

  uint32_t /* width from decompiler */ local_1c;

  uint8_t local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a1f8f;

  pvStack_c = ExceptionList;

  pcStack_44 = "GenerateLootItem (type)";

  uStack_48 = 0x4d0d22;

  ExceptionList = &pvStack_c;

  FUN_0076cf00();

  local_4 = 0;

  if (param_2 < 1) {

    param_2 = 1;

  }

  local_2c[3] = param_1;

  local_2c[0] = 0;

  local_1c = 0;

  local_14 = 0;

  local_10 = 0;

  local_18 = 0;

  local_2c[1] = ((int)(param_2 - 5U) < 1) - 1 & param_2 - 5U;

  local_2c[2] = param_2 + 5;

  if (0x4f < param_2 + 5) {

    local_2c[2] = 0x50;

  }

  pcStack_44 = (char *)0x1;

  puVar3 = local_2c;

  puVar4 = auStack_64;

  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar4 = *puVar3;

    puVar3 = puVar3 + 1;

    puVar4 = puVar4 + 1;

  }

  FUN_005e0580();

  uStack_50 = FUN_005e1030();

  pcStack_44 = (char *)0x0;

  uStack_48 = 0x3f000000;

  uStack_4c = param_3;

  auStack_64[3] = 0x4d0daf;

  piVar1 = (int *)FUN_0050b6c0();

  if (piVar1 != (int *)0x0) {

    uStack_48 = 0x4d0dc0;

    (**(code **)(*piVar1 + 0x218))();

  }

  local_4 = 0xffffffff;

  pcStack_44 = (char *)0x4d0dd1;

  FUN_0076cef0();

  ExceptionList = pvStack_c;

  return piVar1;

}

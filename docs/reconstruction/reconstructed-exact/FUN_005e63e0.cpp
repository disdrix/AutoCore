// =============================================================================
// FUN_005e63e0
// -----------------------------------------------------------------------------
// Stable ID: aa_005e63e0
// Address:   0x005e63e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005e63e0 @ 0x005e63e0
// Stable ID: aa_005e63e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~79 non-empty decompiler lines.
//  - Control keywords: if×3, do×2, while×2, return×1.
//  - Notable callees: FUN_004367f0×2, FUN_00442ed0×2, FUN_004507a0×2, FUN_00451230×2, FUN_005c53b0×2, FUN_005e6a20×2, FUN_00493830, FUN_00493e00.
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

uint32_t /* width from decompiler */ * __fastcall FUN_005e63e0(uint32_t /* width from decompiler */ *param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iStack00000004;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a7663;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_005a66e0();

  *param_1 = &PTR_FUN_009dca4c;

  param_1[0x5a] = 0;

  param_1[0x5b] = 0;

  param_1[0x5c] = 0;

  param_1[0x5e] = 0;

  param_1[0x5f] = 0;

  param_1[0x60] = 0;

  param_1[0x66] = 0;

  param_1[0x67] = 0;

  param_1[0x68] = 0;

  local_4 = 3;

  FUN_00493e00();

  FUN_00493f40();

  param_1[0x58] = DAT_00aaa664;

  iStack00000004 = 6;

  do {

    iVar1 = param_1[5];

    if ((iVar1 == 0) || ((uint)(param_1[7] - iVar1 >> 2) <= (uint)(param_1[6] - iVar1 >> 2))) {

      FUN_00493830();

    }

    else {

      puVar2 = (uint32_t /* width from decompiler */ *)param_1[6];

      *puVar2 = 0;

      param_1[6] = puVar2 + 1;

    }

    iStack00000004 = iStack00000004 + -1;

  } while (iStack00000004 != 0);

  FUN_004367f0();

  FUN_00442ed0();

  FUN_005c53b0(0);

  FUN_005e6a20();

  FUN_005c53b0(0);

  FUN_005e6a20();

  FUN_004367f0();

  FUN_00442ed0();

  iStack00000004 = 0;

  do {

    iVar1 = param_1[0x55];

    if ((iVar1 == 0) || ((uint)(param_1[0x57] - iVar1 >> 2) <= (uint)(param_1[0x56] - iVar1 >> 2)))

    {

      FUN_004507a0();

    }

    else {

      puVar2 = (uint32_t /* width from decompiler */ *)param_1[0x56];

      *puVar2 = 0;

      param_1[0x56] = puVar2 + 1;

    }

    FUN_00451230();

    FUN_00451230();

    *(uint8_t *)(iStack00000004 + 0x1a4 + (int)param_1) = 0;

    iVar1 = param_1[0x66];

    if ((iVar1 == 0) || ((uint)(param_1[0x68] - iVar1 >> 2) <= (uint)(param_1[0x67] - iVar1 >> 2)))

    {

      FUN_004507a0();

    }

    else {

      puVar2 = (uint32_t /* width from decompiler */ *)param_1[0x67];

      *puVar2 = 0;

      param_1[0x67] = puVar2 + 1;

    }

    iStack00000004 = iStack00000004 + 1;

  } while (iStack00000004 < 6);

  FUN_0076f900();

  ExceptionList = local_c;

  return param_1;

}

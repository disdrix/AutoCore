// =============================================================================
// FUN_005fc320
// -----------------------------------------------------------------------------
// Stable ID: aa_005fc320
// Address:   0x005fc320  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005fc320 @ 0x005fc320
// Stable ID: aa_005fc320
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_005fc320, FUN_0064aee0, FUN_0064af60.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_005fc320(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ uStack_44;

  uint32_t /* width from decompiler */ uStack_40;

  uint32_t /* width from decompiler */ local_3c;

  uint32_t /* width from decompiler */ local_38;

  float local_34;

  uint32_t /* width from decompiler */ local_30;

  void *pvStack_14;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a7bf3;

  pvStack_c = ExceptionList;

  uStack_40 = 0x5fc340;

  ExceptionList = &pvStack_c;

  FUN_0064af60();

  local_34 = g_flOne;

  uStack_40 = 10;

  local_38 = 200;

  local_30 = _DAT_009dd310;

  local_3c = param_2;

  uStack_44 = 0x4c;

  iVar1 = (**(code **)(*DAT_00b05060 + 0x10))();

  *(uint16_t *)(iVar1 + 4) = 0x4c;

  pvStack_c = (void *)0x0;

  FUN_0064aee0(&uStack_44);

  ExceptionList = pvStack_14;

  return;

}

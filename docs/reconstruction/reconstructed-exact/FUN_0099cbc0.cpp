// =============================================================================
// FUN_0099cbc0
// -----------------------------------------------------------------------------
// Stable ID: aa_0099cbc0
// Address:   0x0099cbc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0099cbc0 @ 0x0099cbc0
// Stable ID: aa_0099cbc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0040add0×2, FUN_0040aef0, FUN_0099cae0, FUN_0099cbc0, FUN_0099ed40.
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

uint32_t /* width from decompiler */

FUN_0099cbc0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

            uint32_t /* width from decompiler */ param_5)



{

  int iVar1;

  uint32_t /* width from decompiler */ uStack_24;

  uint32_t /* width from decompiler */ uStack_20;

  uint32_t /* width from decompiler */ uStack_1c;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009b1211;

  local_c = ExceptionList;

  uStack_1c = param_2;

  local_4 = 1;

  uStack_20 = 0x99cbfa;

  ExceptionList = &local_c;

  iVar1 = FUN_0099ed40();

  if (iVar1 < 0) {

    local_4 = 0xffffffff;

    uStack_1c = 0x99cc0d;

    FUN_0040add0();

    ExceptionList = local_c;

    return 0xffffffff;

  }

  uStack_1c = param_5;

  uStack_20 = param_4;

  uStack_24 = param_5;

  FUN_0040aef0(&uStack_24);

  FUN_0099cae0();

  local_4 = 0xffffffff;

  uStack_1c = 0x99cc56;

  FUN_0040add0();

  ExceptionList = local_c;

  return 0;

}

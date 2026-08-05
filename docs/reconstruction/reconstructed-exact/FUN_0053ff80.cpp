// =============================================================================
// FUN_0053ff80
// -----------------------------------------------------------------------------
// Stable ID: aa_0053ff80
// Address:   0x0053ff80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0053ff80 @ 0x0053ff80
// Stable ID: aa_0053ff80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0053ff80, FUN_0056e4e0, FUN_0060b870.
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

void __fastcall FUN_0053ff80(int param_1)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ uVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a3f7b;

  local_c = ExceptionList;

  if (*(int *)(param_1 + 0xf18) == 0) {

    ExceptionList = &local_c;

    FUN_0056e4e0();

    pvVar1 = operator_new(0x10);

    local_4 = 0;

    if (pvVar1 == (void *)0x0) {

      uVar2 = 0;

    }

    else {

      uVar2 = FUN_0060b870();

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xf18) = uVar2;

  }

  ExceptionList = local_c;

  return;

}

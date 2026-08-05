// =============================================================================
// FUN_005c9a00
// -----------------------------------------------------------------------------
// Stable ID: aa_005c9a00
// Address:   0x005c9a00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005c9a00 @ 0x005c9a00
// Stable ID: aa_005c9a00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_005c9a00.
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

uint32_t /* width from decompiler */ __fastcall FUN_005c9a00(int param_1)



{

  void *pvVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a6f6b;

  local_c = ExceptionList;

  if (*(int *)(param_1 + 0x7c) == 0) {

    ExceptionList = &local_c;

    pvVar1 = operator_new(0x10);

    if (pvVar1 == (void *)0x0) {

      pvVar1 = (void *)0x0;

    }

    else {

      *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 4) = 0;

      *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 8) = 0;

      *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 0xc) = 0;

    }

    *(void **)(param_1 + 0x7c) = pvVar1;

  }

  ExceptionList = local_c;

  return *(uint32_t /* width from decompiler */ *)(param_1 + 0x7c);

}

// =============================================================================
// FUN_0048b3f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0048b3f0
// Address:   0x0048b3f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0048b3f0 @ 0x0048b3f0
// Stable ID: aa_0048b3f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: return×2, while×1, if×1.
//  - Notable callees: FUN_0048b3f0.
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

void __fastcall FUN_0048b3f0(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint local_4;

  

  pvStack_c = ExceptionList;

  puStack_8 = &LAB_009a0543;

  ExceptionList = &pvStack_c;

  *param_1 = &PTR_FUN_009c6e18;

  puVar1 = (uint32_t /* width from decompiler */ *)param_1[6];

  local_4 = 1;

  while (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

    puVar2 = (uint32_t /* width from decompiler */ *)*puVar1;

    puVar1 = (uint32_t /* width from decompiler */ *)puVar1[10];

    (*(code *)*puVar2)(1);

  }

  local_4 = local_4 & 0xffffff00;

  if ((uint32_t /* width from decompiler */ *)param_1[8] == &DAT_00b03504) {

    *param_1 = &PTR_LAB_009c6d9c;

    ExceptionList = pvStack_c;

    return;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete((uint32_t /* width from decompiler */ *)param_1[8]);

}

// =============================================================================
// FUN_006793f0
// -----------------------------------------------------------------------------
// Stable ID: aa_006793f0
// Address:   0x006793f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006793f0 @ 0x006793f0
// Stable ID: aa_006793f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: FUN_006793f0.
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

void __fastcall FUN_006793f0(uint32_t /* width from decompiler */ *param_1)



{

  int *piVar1;

  

  piVar1 = (int *)param_1[5];

  if (piVar1 != (int *)0x0) {

    (**(code **)(*piVar1 + 8))(piVar1);

  }

  piVar1 = (int *)param_1[4];

  if (piVar1 != (int *)0x0) {

    (**(code **)(*piVar1 + 0x48))(piVar1);

    (**(code **)(*(int *)param_1[4] + 8))((int *)param_1[4]);

    param_1[4] = 0;

  }

  if ((void *)*param_1 != (void *)0x0) {

    operator_delete__((void *)*param_1);

    *param_1 = 0;

  }

  if ((void *)param_1[0xc] != (void *)0x0) {

    operator_delete__((void *)param_1[0xc]);

    param_1[0xc] = 0;

  }

  if ((uint32_t /* width from decompiler */ *)param_1[0x1b] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x1b])(1);

  }

  param_1[0x1b] = 0;

  if ((void *)param_1[0x22] != (void *)0x0) {

    operator_delete__((void *)param_1[0x22]);

  }

  return;

}

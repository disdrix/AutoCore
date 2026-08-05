// =============================================================================
// FUN_0044b150
// -----------------------------------------------------------------------------
// Stable ID: aa_0044b150
// Address:   0x0044b150  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0044b150 @ 0x0044b150
// Stable ID: aa_0044b150
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0044b150.
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

uint32_t /* width from decompiler */ * __thiscall FUN_0044b150(int *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  int *piVar1;

  uint32_t /* width from decompiler */ *puVar2;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009bcaa1;

  local_10 = ExceptionList;

  ExceptionList = &local_10;

  puVar2 = operator_new(0xc);

  local_8 = 1;

  if (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

    *puVar2 = param_2;

    puVar2[1] = param_3;

    piVar1 = (int *)*param_1;

    if ((piVar1 != (int *)0x0) && (piVar1[1] = piVar1[1] + 1, piVar1[1] == 1)) {

      (**(code **)(*piVar1 + 4))();

    }

    puVar2[2] = *param_1;

  }

  ExceptionList = local_10;

  return puVar2;

}

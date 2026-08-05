// =============================================================================
// FUN_00581ab0
// -----------------------------------------------------------------------------
// Stable ID: aa_00581ab0
// Address:   0x00581ab0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00581ab0 @ 0x00581ab0
// Stable ID: aa_00581ab0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_00581ab0.
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

uint32_t /* width from decompiler */ __thiscall FUN_00581ab0(int param_1,int *param_2,int param_3)



{

  int *piVar1;

  void *pvVar2;

  int unaff_ESI;

  

  piVar1 = param_2;

  if (param_2 == (int *)0x0) {

    return 0;

  }

  if (0x15 < param_3) {

    (**(code **)(*param_2 + 0x14))(&param_2);

    if (unaff_ESI != 0) {

      if (*(void **)(param_1 + 0x1c) != (void *)0x0) {

        operator_delete__(*(void **)(param_1 + 0x1c));

      }

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = 0;

      pvVar2 = operator_new__(unaff_ESI + 1);

      *(void **)(param_1 + 0x1c) = pvVar2;

      (**(code **)(*piVar1 + 0x14))(pvVar2,unaff_ESI);

      *(uint8_t *)(*(int *)(param_1 + 0x1c) + 4) = 0;

    }

  }

  return 1;

}

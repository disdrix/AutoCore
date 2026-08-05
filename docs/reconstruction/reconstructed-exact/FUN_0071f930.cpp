// =============================================================================
// FUN_0071f930
// -----------------------------------------------------------------------------
// Stable ID: aa_0071f930
// Address:   0x0071f930  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0071f930 @ 0x0071f930
// Stable ID: aa_0071f930
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, return×1.
//  - Notable callees: FUN_0071f930.
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

void __fastcall FUN_0071f930(uint32_t /* width from decompiler */ *param_1)



{

  int *piVar1;

  uint uVar2;

  

  piVar1 = (int *)param_1[0x72];

  *param_1 = &PTR_FUN_00aa952c;

  if (piVar1 != (int *)0x0) {

    (**(code **)(*piVar1 + 8))(piVar1);

    param_1[0x72] = 0;

  }

  uVar2 = 0;

  if (param_1[7] != 0) {

    do {

      piVar1 = *(int **)(param_1[4] + uVar2 * 4);

      (**(code **)(*piVar1 + 0x48))(piVar1);

      if (*(int *)(param_1[4] + uVar2 * 4) != 0) {

        piVar1 = *(int **)(param_1[4] + uVar2 * 4);

        (**(code **)(*piVar1 + 8))(piVar1);

        *(uint32_t /* width from decompiler */ *)(param_1[4] + uVar2 * 4) = 0;

      }

      uVar2 = uVar2 + 1;

    } while (uVar2 < (uint)param_1[7]);

  }

  if ((void *)param_1[4] != (void *)0x0) {

    operator_delete__((void *)param_1[4]);

  }

  param_1[4] = 0;

  return;

}

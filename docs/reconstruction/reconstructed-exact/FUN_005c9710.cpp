// =============================================================================
// FUN_005c9710
// -----------------------------------------------------------------------------
// Stable ID: aa_005c9710
// Address:   0x005c9710  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005c9710 @ 0x005c9710
// Stable ID: aa_005c9710
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_005c9710.
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

void __thiscall FUN_005c9710(int param_1,int *param_2)



{

  int iVar1;

  void *pvVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  iVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x60))();

  if (iVar1 != 0) {

    iVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x60))();

    pvVar2 = operator_new__(iVar1 * 4);

    *param_2 = (int)pvVar2;

    puVar3 = *(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 0x7c) + 4);

    if (puVar3 != *(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 0x7c) + 8)) {

      iVar1 = 0;

      do {

        *(uint32_t /* width from decompiler */ *)(iVar1 + *param_2) = *puVar3;

        puVar3 = puVar3 + 1;

        iVar1 = iVar1 + 4;

      } while (puVar3 != *(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 0x7c) + 8));

    }

  }

  return;

}

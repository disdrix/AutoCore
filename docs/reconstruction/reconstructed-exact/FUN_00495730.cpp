// =============================================================================
// FUN_00495730
// -----------------------------------------------------------------------------
// Stable ID: aa_00495730
// Address:   0x00495730  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00495730 @ 0x00495730
// Stable ID: aa_00495730
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×3, do×2, while×2, return×1.
//  - Notable callees: FUN_00494620, FUN_00495730.
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

void __thiscall FUN_00495730(int param_1,uint32_t /* width from decompiler */ param_2,int *param_3)



{

  int iVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  piVar2 = *(int **)(param_1 + 0x9c);

  if (piVar2 != *(int **)(param_1 + 0xa0)) {

    do {

      iVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(*piVar2 + 4) + 4) + 4 + *piVar2) + 0x1d4))();

      if (iVar1 != 0) {

        *param_3 = *param_3 + 1;

        FUN_00494620(param_2,iVar1,param_3);

      }

      piVar2 = piVar2 + 1;

    } while (piVar2 != *(int **)(param_1 + 0xa0));

  }

  puVar3 = *(uint32_t /* width from decompiler */ **)(param_1 + 0xbc);

  if (puVar3 != *(uint32_t /* width from decompiler */ **)(param_1 + 0xc0)) {

    do {

      (**(code **)(*(int *)*puVar3 + 0x40))(param_2);

      puVar3 = puVar3 + 1;

    } while (puVar3 != *(uint32_t /* width from decompiler */ **)(param_1 + 0xc0));

  }

  return;

}

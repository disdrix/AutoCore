// =============================================================================
// FUN_0053dac0
// -----------------------------------------------------------------------------
// Stable ID: aa_0053dac0
// Address:   0x0053dac0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0053dac0 @ 0x0053dac0
// Stable ID: aa_0053dac0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: CONCAT22, FUN_0053dac0.
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

void __fastcall FUN_0053dac0(int param_1)



{

  int iVar1;

  uint uVar2;

  uint16_t extraout_var;

  uint uVar3;

  

  if (*(int *)(param_1 + 8) != 0) {

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 8) + 0x28) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x18);

  }

  if (*(int *)(param_1 + 0xc) != 0) {

    uVar3 = 0;

    iVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x4c))();

    if (iVar1 != 0) {

      do {

        iVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x50))();

        (**(code **)(**(int **)(iVar1 + uVar3 * 4) + 8))

                  (CONCAT22(extraout_var,*(uint16_t *)(param_1 + 0x1c)));

        uVar3 = uVar3 + 1;

        uVar2 = (**(code **)(**(int **)(param_1 + 0xc) + 0x4c))();

      } while (uVar3 < uVar2);

    }

  }

  return;

}

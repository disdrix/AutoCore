// =============================================================================
// FUN_004b73c0
// -----------------------------------------------------------------------------
// Stable ID: aa_004b73c0
// Address:   0x004b73c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004b73c0 @ 0x004b73c0
// Stable ID: aa_004b73c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: FUN_004b73c0, FUN_0058e370.
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

void __thiscall FUN_004b73c0(int param_1,int param_2)



{

  int *piVar1;

  

  *(int *)(param_1 + 0x10) = param_2;

  if (param_2 == 0) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = DAT_009cb2a0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = DAT_009cb2a4;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = DAT_009cb2a8;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = DAT_009cb2ac;

    return;

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x160);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x164);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x168);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x16c);

  piVar1 = (int *)**(int **)(param_1 + 0x204);

  if (piVar1 != *(int **)(param_1 + 0x204)) {

    do {

      if (piVar1[2] != 0) {

        FUN_0058e370(param_2);

      }

      piVar1 = (int *)*piVar1;

    } while (piVar1 != (int *)*(int *)(param_1 + 0x204));

  }

  return;

}

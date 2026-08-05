// =============================================================================
// FUN_005bbb90
// -----------------------------------------------------------------------------
// Stable ID: aa_005bbb90
// Address:   0x005bbb90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005bbb90 @ 0x005bbb90
// Stable ID: aa_005bbb90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: FUN_005bbb90.
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

void __thiscall FUN_005bbb90(int param_1,char param_2,char param_3)



{

  int iVar1;

  int *piVar2;

  

  *(char *)(param_1 + 0x7f8) = param_2;

  if (param_2 == '\0') {

    if ((((DAT_00aaa66c < *(float *)(param_1 + 0x900) || DAT_00aaa66c == *(float *)(param_1 + 0x900)

          ) && (*(int *)(*(int *)(param_1 + 4) + 0x28) != 4)) && (param_3 == '\0')) &&

       (piVar2 = (int *)**(int **)(param_1 + 0xa24), piVar2 != *(int **)(param_1 + 0xa24))) {

      do {

        iVar1 = piVar2[2];

        *(uint32_t /* width from decompiler */ *)(iVar1 + 0x16c) = 0;

        *(uint32_t /* width from decompiler */ *)(iVar1 + 0x170) = 0;

        piVar2 = (int *)*piVar2;

      } while (piVar2 != (int *)*(int *)(param_1 + 0xa24));

    }

  }

  else {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x804) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x810) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x8fc);

    if ((*(byte *)(param_1 + 0x989) & 0x10) != 0) {

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x808) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x900);

      return;

    }

  }

  return;

}

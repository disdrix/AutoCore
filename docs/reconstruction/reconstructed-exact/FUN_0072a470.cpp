// =============================================================================
// FUN_0072a470
// -----------------------------------------------------------------------------
// Stable ID: aa_0072a470
// Address:   0x0072a470  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0072a470 @ 0x0072a470
// Stable ID: aa_0072a470
// Embedded strings (evidence for future rename):
//   - "Phase"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_0072a470.
//  - Strings: "Phase".
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

uint32_t /* width from decompiler */ __thiscall FUN_0072a470(int *param_1,int param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  int *piVar3;

  

  if (*(int *)(param_2 + 0xc) != 0) {

    piVar3 = *(int **)(param_2 + 0xc);

    iVar1 = (**(code **)(*piVar3 + 0x24))(piVar3,0,"Phase");

    if (iVar1 != 0) {

      (**(code **)(**(int **)(param_2 + 0xc) + 0xcc))

                (*(int **)(param_2 + 0xc),iVar1,&stack0xfffffff8);

      if (piVar3 != (int *)0x0) {

        uVar2 = (**(code **)(*param_1 + 4))(piVar3);

        return uVar2;

      }

    }

  }

  return 0xffff;

}

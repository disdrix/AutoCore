// =============================================================================
// FUN_00790bf0
// -----------------------------------------------------------------------------
// Stable ID: aa_00790bf0
// Address:   0x00790bf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00790bf0 @ 0x00790bf0
// Stable ID: aa_00790bf0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×4, return×4.
//  - Notable callees: FUN_00790bf0, FUN_007a7eb0.
//  - Return sites: 4.

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

uint32_t /* width from decompiler */ __thiscall FUN_00790bf0(int *param_1,int param_2)



{

  char cVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ uVar3;

  

  cVar1 = (**(code **)(*param_1 + 0x3d8))();

  if (cVar1 != '\0') {

    piVar2 = *(int **)(param_2 + 0x20);

    if (piVar2 != (int *)0x0) {

      if (piVar2 != param_1) {

        (**(code **)(*piVar2 + 0x360))(param_2);

        return 1;

      }

      piVar2 = (int *)(**(code **)(*param_1 + 0x3d0))

                                (*(uint32_t /* width from decompiler */ *)(param_2 + 0xc),*(uint32_t /* width from decompiler */ *)(param_2 + 0x10),1,1)

      ;

      if (piVar2 != (int *)0x0) {

        *(int **)(param_2 + 0x20) = piVar2;

        (**(code **)(*piVar2 + 0x360))();

        return 1;

      }

      uVar3 = FUN_007a7eb0(param_2);

      return uVar3;

    }

  }

  return 0;

}

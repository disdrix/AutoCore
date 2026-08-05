// =============================================================================
// FUN_00804f50
// -----------------------------------------------------------------------------
// Stable ID: aa_00804f50
// Address:   0x00804f50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00804f50 @ 0x00804f50
// Stable ID: aa_00804f50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×6, return×2, do×1, while×1.
//  - Notable callees: FUN_00804aa0, FUN_00804e60, FUN_00804f50.
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

void __thiscall FUN_00804f50(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  int *piVar1;

  int iVar2;

  int *piVar3;

  

  if ((int *)param_1[0x1c] != (int *)0x0) {

    (**(code **)(*(int *)param_1[0x1c] + 0x70))(param_2);

  }

  if (((int *)param_1[0x1c] != (int *)0x0) &&

     (iVar2 = (**(code **)(*(int *)param_1[0x1c] + 0x7c))(), iVar2 != 0)) {

    param_1[0x1c] = 0;

    (**(code **)(*param_1 + 0x80))(0);

    piVar3 = (int *)param_1[0x1e];

    if (piVar3 != (int *)param_1[0x1f]) {

      do {

        piVar1 = (int *)*piVar3;

        iVar2 = (**(code **)(*piVar1 + 0x7c))();

        if (iVar2 == 0) {

          if (param_1[0x24] == 0) {

            param_1[0x1c] = (int)piVar1;

          }

          break;

        }

        piVar3 = piVar3 + 1;

      } while (piVar3 != (int *)param_1[0x1f]);

    }

  }

  if (param_1[0x22] != -1) {

    FUN_00804e60();

    return;

  }

  FUN_00804aa0();

  return;

}

// =============================================================================
// FUN_005e6f50
// -----------------------------------------------------------------------------
// Stable ID: aa_005e6f50
// Address:   0x005e6f50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005e6f50 @ 0x005e6f50
// Stable ID: aa_005e6f50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×5, while×1, return×1.
//  - Notable callees: FUN_005e6f50.
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

void __thiscall FUN_005e6f50(int *param_1,int param_2,int param_3,int *param_4)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  

  if (param_1 != param_4) {

    if (param_3 == 0) {

      param_4 = param_1;

    }

    (**(code **)(*param_1 + 0x74))(param_2);

    (**(code **)(*param_1 + 0x78))();

    iVar3 = 0;

    while( true ) {

      if (param_1[5] == 0) {

        iVar2 = 0;

      }

      else {

        iVar2 = param_1[6] - param_1[5] >> 2;

      }

      if (iVar2 <= iVar3) break;

      piVar1 = (int *)(param_1[5] + iVar3 * 4);

      if ((param_2 != *(int *)(param_1[5] + iVar3 * 4)) && (*piVar1 != 0)) {

        (**(code **)(*(int *)*piVar1 + 0x88))(param_2,param_1,param_4);

      }

      iVar3 = iVar3 + 1;

    }

  }

  return;

}

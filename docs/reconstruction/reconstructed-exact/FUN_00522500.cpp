// =============================================================================
// FUN_00522500
// -----------------------------------------------------------------------------
// Stable ID: aa_00522500
// Address:   0x00522500  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00522500 @ 0x00522500
// Stable ID: aa_00522500
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~61 non-empty decompiler lines.
//  - Control keywords: if×8, do×1, while×1, return×1.
//  - Notable callees: FUN_0079d330×2, FUN_00522500, FUN_0079d1e0, FUN_0079d290.
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

void __thiscall FUN_00522500(int param_1,int *param_2)



{

  int *piVar1;

  int iVar2;

  

  FUN_0079d290(1,0);

  if (*(char *)((int)param_2 + 5) == '\0') {

    (**(code **)(*param_2 + 8))(param_1,4);

  }

  else {

    (**(code **)(*param_2 + 4))();

  }

  if (*(char *)((int)param_2 + 5) == '\0') {

    (**(code **)(*param_2 + 8))(param_1 + 4,1);

  }

  else {

    (**(code **)(*param_2 + 4))();

  }

  if (*(char *)((int)param_2 + 5) == '\0') {

    (**(code **)(*param_2 + 8))(param_1 + 0x10,4);

  }

  else {

    (**(code **)(*param_2 + 4))();

  }

  if (*(char *)((int)param_2 + 5) == '\0') {

    (**(code **)(*param_2 + 8))(param_1 + 0x14,4);

  }

  else {

    (**(code **)(*param_2 + 4))();

  }

  if (*(char *)((int)param_2 + 5) == '\0') {

    (**(code **)(*param_2 + 8))(param_1 + 0x18,4);

  }

  else {

    (**(code **)(*param_2 + 4))();

  }

  FUN_0079d330(param_1 + 8,8);

  FUN_0079d330(param_1 + 0x20,8);

  piVar1 = (int *)(param_1 + 0x28);

  if (*(char *)((int)param_2 + 5) == '\0') {

    (**(code **)(*param_2 + 8))(piVar1,4);

  }

  else {

    (**(code **)(*param_2 + 4))();

  }

  iVar2 = 0;

  if (0 < *piVar1) {

    param_1 = param_1 + 0x2c;

    do {

      if (*(char *)((int)param_2 + 5) == '\0') {

        (**(code **)(*param_2 + 8))(param_1,4);

      }

      else {

        (**(code **)(*param_2 + 4))();

      }

      iVar2 = iVar2 + 1;

      param_1 = param_1 + 4;

    } while (iVar2 < *piVar1);

  }

  FUN_0079d1e0();

  return;

}

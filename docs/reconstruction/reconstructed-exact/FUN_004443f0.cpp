// =============================================================================
// FUN_004443f0
// -----------------------------------------------------------------------------
// Stable ID: aa_004443f0
// Address:   0x004443f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004443f0 @ 0x004443f0
// Stable ID: aa_004443f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×4, for×1, return×1.
//  - Notable callees: FUN_004442c0, FUN_004443f0.
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

int * __thiscall FUN_004443f0(int *param_1,int *param_2)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  int *in_EAX;

  

  for (; param_1 != param_2; param_1 = param_1 + 5) {

    iVar2 = *param_1;

    if (iVar2 != 0) {

      *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) + 1;

      if (*(int *)(iVar2 + 8) == 1) {

        (**(code **)(*(int *)(iVar2 + 4) + 4))();

      }

    }

    iVar3 = *in_EAX;

    if (iVar3 != 0) {

      piVar1 = (int *)(iVar3 + 8);

      *piVar1 = *piVar1 + -1;

      if (*piVar1 == 0) {

        (**(code **)(*(int *)(iVar3 + 4) + 8))();

      }

    }

    *in_EAX = iVar2;

    FUN_004442c0();

    in_EAX = in_EAX + 5;

  }

  return in_EAX;

}

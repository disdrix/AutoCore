// =============================================================================
// FUN_0088d010
// -----------------------------------------------------------------------------
// Stable ID: aa_0088d010
// Address:   0x0088d010  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0088d010 @ 0x0088d010
// Stable ID: aa_0088d010
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_0088d010.
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

void __fastcall FUN_0088d010(int *param_1)



{

  int iVar1;

  char cVar2;

  uint32_t /* width from decompiler */ uVar3;

  

  if ((param_1[0x168] != 0) && (*(int *)(param_1[0x168] + 0x35c) != 0)) {

    cVar2 = (**(code **)(*param_1 + 0x3d8))();

    if (cVar2 != '\0') {

      iVar1 = *(int *)(*(int *)(param_1[0x168] + 0x35c) + 0x50);

      param_1[0x157] = iVar1;

      if (iVar1 <= param_1[0x156]) {

        param_1[0x156] = iVar1 + -1;

      }

      if (param_1[0x156] < 0) {

        param_1[0x156] = 0;

      }

      iVar1 = *param_1;

      uVar3 = (**(code **)(iVar1 + 0x450))(param_1[0x156]);

      (**(code **)(iVar1 + 0x454))(uVar3);

      if ((int *)param_1[0x17c] != (int *)0x0) {

        (**(code **)(*(int *)param_1[0x17c] + 0x444))();

      }

                    /* WARNING: Could not recover jumptable at 0x0088d0a2. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (**(code **)(*param_1 + 0x460))();

      return;

    }

  }

  return;

}

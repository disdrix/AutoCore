// =============================================================================
// FUN_00792a50
// -----------------------------------------------------------------------------
// Stable ID: aa_00792a50
// Address:   0x00792a50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00792a50 @ 0x00792a50
// Stable ID: aa_00792a50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00758c80, FUN_00759090, FUN_00792a50.
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

void __fastcall FUN_00792a50(int *param_1)



{

  int iVar1;

  char cVar2;

  

  FUN_00758c80();

  if (*(char *)((int)param_1 + 0x495) != '\0') {

    cVar2 = (**(code **)(*param_1 + 0xd0))();

    if (cVar2 != '\0') {

      (**(code **)(*param_1 + 0x188))();

      param_1[0x1a] = param_1[0x1a] + 1;

      iVar1 = param_1[0x1a];

      param_1[0x1d] = (int)(float)-iVar1;

      if (param_1[0x1c] < iVar1) {

        param_1[0x1c] = iVar1;

      }

      (**(code **)(*param_1 + 0x184))();

    }

  }

  FUN_00759090();

  (**(code **)(*param_1 + 0xe0))(0);

  return;

}

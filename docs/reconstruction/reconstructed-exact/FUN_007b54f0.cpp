// =============================================================================
// FUN_007b54f0
// -----------------------------------------------------------------------------
// Stable ID: aa_007b54f0
// Address:   0x007b54f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007b54f0 @ 0x007b54f0
// Stable ID: aa_007b54f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_00440680, FUN_00757230, FUN_00758c80, FUN_00759090, FUN_007b54f0.
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

void __fastcall FUN_007b54f0(int *param_1)



{

  int iVar1;

  char cVar2;

  

  FUN_00758c80();

  cVar2 = (**(code **)(*param_1 + 0xd0))();

  if (cVar2 != '\0') {

    if ((char)param_1[0x36] == '\0') {

      (**(code **)(*param_1 + 0x188))();

      param_1[0x1a] = param_1[0x1a] + 1;

      iVar1 = param_1[0x1a];

      param_1[0x1d] = (int)(float)-iVar1;

      if (param_1[0x1c] < iVar1) {

        param_1[0x1c] = iVar1;

      }

      (**(code **)(*param_1 + 0x184))();

    }

    else {

      FUN_00440680();

      param_1[0x12] = param_1[100];

      param_1[0x13] = param_1[0x65];

      param_1[0x14] = param_1[0x66];

      param_1[0x15] = param_1[0x67];

      (**(code **)(*param_1 + 0x188))();

      param_1[0x1a] = param_1[0x1a] + 1;

      iVar1 = param_1[0x1a];

      param_1[0x1d] = (int)(float)-iVar1;

      if (param_1[0x1c] < iVar1) {

        param_1[0x1c] = iVar1;

      }

      (**(code **)(*param_1 + 0x184))();

      FUN_00757230();

    }

  }

  FUN_00759090();

  (**(code **)(*param_1 + 0xe0))(0);

  return;

}

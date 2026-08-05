// =============================================================================
// FUN_007ac010
// -----------------------------------------------------------------------------
// Stable ID: aa_007ac010
// Address:   0x007ac010  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007ac010 @ 0x007ac010
// Stable ID: aa_007ac010
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~60 non-empty decompiler lines.
//  - Control keywords: if×10, return×3.
//  - Notable callees: FUN_007ac010.
//  - Return sites: 3.

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

void __fastcall FUN_007ac010(int *param_1)



{

  char cVar1;

  

  if (param_1[0x88] == 1) {

    (**(code **)(*param_1 + 0x350))(1);

    cVar1 = (**(code **)(*param_1 + 0xf0))(1);

    if (cVar1 != '\0') {

      *(char *)((int)param_1 + 0x22b) = (char)param_1[0x3e];

      *(char *)((int)param_1 + 0x22f) = (char)param_1[0x3f];

      *(char *)((int)param_1 + 0x233) = (char)param_1[0x40];

    }

    cVar1 = (**(code **)(*param_1 + 0xf0))(2);

    if (cVar1 != '\0') {

      (**(code **)(*param_1 + 0x11c))(param_1 + 0x5a);

    }

    cVar1 = (**(code **)(*param_1 + 0xf0))(4);

    if (cVar1 != '\0') {

      param_1[0x8a] = param_1[0x41];

      param_1[0x8b] = param_1[0x42];

      param_1[0x8c] = param_1[0x43];

    }

    cVar1 = (**(code **)(*param_1 + 0xf0))(8);

    if (cVar1 != '\0') {

      (**(code **)(*param_1 + 0x11c))(param_1 + 0x5a);

    }

                    /* WARNING: Could not recover jumptable at 0x007ac0db. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(*param_1 + 0x34c))();

    return;

  }

  if (param_1[0x88] == -1) {

    (**(code **)(*param_1 + 0x350))(0xffffffff);

    cVar1 = (**(code **)(*param_1 + 0xf0))(1);

    if (cVar1 != '\0') {

      *(char *)((int)param_1 + 0x22b) = (char)param_1[0x3e];

      *(char *)((int)param_1 + 0x22f) = (char)param_1[0x3f];

      *(char *)((int)param_1 + 0x233) = (char)param_1[0x40];

    }

    cVar1 = (**(code **)(*param_1 + 0xf0))(2);

    if (cVar1 != '\0') {

      (**(code **)(*param_1 + 0x11c))(param_1 + 0x58);

    }

    cVar1 = (**(code **)(*param_1 + 0xf0))(4);

    if (cVar1 != '\0') {

      param_1[0x8a] = param_1[0x41];

      param_1[0x8b] = param_1[0x42];

      param_1[0x8c] = param_1[0x43];

    }

    cVar1 = (**(code **)(*param_1 + 0xf0))(8);

    if (cVar1 != '\0') {

      (**(code **)(*param_1 + 0x11c))(param_1 + 0x58);

    }

    (**(code **)(*param_1 + 0xcc))(0);

                    /* WARNING: Could not recover jumptable at 0x007ac1b1. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(*param_1 + 0x34c))();

    return;

  }

  return;

}

// =============================================================================
// FUN_007f9a90
// -----------------------------------------------------------------------------
// Stable ID: aa_007f9a90
// Address:   0x007f9a90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007f9a90 @ 0x007f9a90
// Stable ID: aa_007f9a90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, do×2, while×2.
//  - Notable callees: ShowCursor×2, FUN_007f9a90.
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

void __thiscall FUN_007f9a90(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  char cVar1;

  int iVar2;

  

  if (*(char *)((int)param_1 + 0x489) == '\0') {

    cVar1 = (**(code **)(*param_1 + 0xd0))();

    if (cVar1 != (char)param_2) {

      (**(code **)(*param_1 + 0xcc))(param_2);

      (**(code **)(*param_1 + 0x34c))();

      return;

    }

  }

  else {

    *(char *)((int)param_1 + 0x48a) = (char)param_2;

    if ((char)param_2 == '\0') {

      do {

        iVar2 = ShowCursor(0);

      } while (0 < iVar2);

    }

    else {

      do {

        iVar2 = ShowCursor(1);

      } while (iVar2 < 1);

    }

    if (DAT_00d1f044 != (uint32_t /* width from decompiler */ *)0x0) {

      (**(code **)(*(int *)*DAT_00d1f044 + 0x30))((int *)*DAT_00d1f044,(char)param_2 != '\0');

    }

  }

  return;

}

// =============================================================================
// FUN_00862b70
// -----------------------------------------------------------------------------
// Stable ID: aa_00862b70
// Address:   0x00862b70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00862b70 @ 0x00862b70
// Stable ID: aa_00862b70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_004fabc0, FUN_00862860, FUN_00862b70.
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

void FUN_00862b70(void)



{

  int iVar1;

  char cVar2;

  int *in_EAX;

  int iVar3;

  int unaff_EDI;

  uint32_t /* width from decompiler */ local_4;

  

  if (DAT_00d1b6d8 != 0) {

    iVar1 = in_EAX[0x148];

    local_4 = 0;

    if (unaff_EDI == 0) {

      in_EAX[0x148] = 0;

    }

    else {

      cVar2 = FUN_00862860();

      if (((cVar2 == '\0') || (*(int *)(DAT_00d1b6d8 + 0x250) == 0)) ||

         (iVar3 = FUN_004fabc0(unaff_EDI,&local_4), iVar3 != 0)) {

        in_EAX[0x148] = 1;

      }

      else {

        in_EAX[0x148] = 2;

      }

    }

    if (iVar1 != in_EAX[0x148]) {

      (**(code **)(*in_EAX + 0x3b4))();

      (**(code **)(*in_EAX + 0x34c))();

    }

    return;

  }

  return;

}

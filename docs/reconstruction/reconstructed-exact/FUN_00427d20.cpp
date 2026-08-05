// =============================================================================
// FUN_00427d20
// -----------------------------------------------------------------------------
// Stable ID: aa_00427d20
// Address:   0x00427d20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00427d20 @ 0x00427d20
// Stable ID: aa_00427d20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×4, return×3, do×1, goto×1, while×1.
//  - Notable callees: LeaveCriticalSection×2, EnterCriticalSection, FUN_00427d20.
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

uint32_t /* width from decompiler */ FUN_00427d20(uint param_1,uint32_t /* width from decompiler */ *param_2)



{

  LPCRITICAL_SECTION lpCriticalSection;

  int iVar1;

  uint uVar2;

  int unaff_EDI;

  

  if (((param_2 == (uint32_t /* width from decompiler */ *)0x0) || (*(uint *)(unaff_EDI + 0x24) == 0)) ||

     (*(uint *)(unaff_EDI + 0x24) < param_1)) {

    return 0;

  }

  lpCriticalSection = (LPCRITICAL_SECTION)(unaff_EDI + 4);

  EnterCriticalSection(lpCriticalSection);

  iVar1 = *(int *)(unaff_EDI + 0x1c);

  uVar2 = 0;

  do {

    if (iVar1 == 0) {

LAB_00427d60:

      *param_2 = 0;

      LeaveCriticalSection(lpCriticalSection);

      return 1;

    }

    if (uVar2 == param_1) {

      if (iVar1 != 0) {

        *param_2 = *(uint32_t /* width from decompiler */ *)(iVar1 + 4);

        LeaveCriticalSection(lpCriticalSection);

        return 1;

      }

      goto LAB_00427d60;

    }

    iVar1 = *(int *)(iVar1 + 8);

    uVar2 = uVar2 + 1;

  } while( true );

}

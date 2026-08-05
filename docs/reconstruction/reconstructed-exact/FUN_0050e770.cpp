// =============================================================================
// FUN_0050e770
// -----------------------------------------------------------------------------
// Stable ID: aa_0050e770
// Address:   0x0050e770  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0050e770 @ 0x0050e770
// Stable ID: aa_0050e770
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, goto×2, do×1, while×1.
//  - Notable callees: EnterCriticalSection, FUN_0050e770, LeaveCriticalSection.
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

uint32_t /* width from decompiler */ __thiscall FUN_0050e770(int param_1,uint param_2,uint32_t /* width from decompiler */ *param_3)



{

  int iVar1;

  uint uVar2;

  uint32_t /* width from decompiler */ uVar3;

  

  if (((param_3 == (uint32_t /* width from decompiler */ *)0x0) || (*(uint *)(param_1 + 0x24) == 0)) ||

     (*(uint *)(param_1 + 0x24) < param_2)) {

    return 0;

  }

  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));

  iVar1 = *(int *)(param_1 + 0x1c);

  uVar2 = 0;

  do {

    if (iVar1 == 0) {

LAB_0050e7b0:

      uVar3 = 0;

LAB_0050e7b2:

      *param_3 = uVar3;

      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));

      return 1;

    }

    if (uVar2 == param_2) {

      if (iVar1 != 0) {

        uVar3 = *(uint32_t /* width from decompiler */ *)(iVar1 + 4);

        goto LAB_0050e7b2;

      }

      goto LAB_0050e7b0;

    }

    iVar1 = *(int *)(iVar1 + 8);

    uVar2 = uVar2 + 1;

  } while( true );

}

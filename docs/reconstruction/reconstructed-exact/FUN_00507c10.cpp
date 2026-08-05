// =============================================================================
// FUN_00507c10
// -----------------------------------------------------------------------------
// Stable ID: aa_00507c10
// Address:   0x00507c10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00507c10 @ 0x00507c10
// Stable ID: aa_00507c10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×8, do×2, while×2, return×1.
//  - Notable callees: DeleteCriticalSection, EnterCriticalSection, FUN_00507c10, LeaveCriticalSection.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __fastcall FUN_00507c10(uint32_t /* width from decompiler */ *param_1)



{

  LPCRITICAL_SECTION lpCriticalSection;

  int *piVar1;

  

  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 1);

  *param_1 = &PTR_FUN_009cda94;

  EnterCriticalSection(lpCriticalSection);

  piVar1 = (int *)param_1[7];

  if (piVar1 != piVar1 + param_1[8]) {

    do {

      if ((uint32_t /* width from decompiler */ *)*piVar1 != (uint32_t /* width from decompiler */ *)0x0) {

        (*(code *)**(uint32_t /* width from decompiler */ **)*piVar1)(1);

      }

      piVar1 = piVar1 + 1;

    } while (piVar1 != (int *)(param_1[7] + param_1[8] * 4));

  }

  piVar1 = (int *)param_1[10];

  param_1[8] = 0;

  if (piVar1 != piVar1 + param_1[0xb]) {

    do {

      if ((uint32_t /* width from decompiler */ *)*piVar1 != (uint32_t /* width from decompiler */ *)0x0) {

        (*(code *)**(uint32_t /* width from decompiler */ **)*piVar1)(1);

      }

      piVar1 = piVar1 + 1;

    } while (piVar1 != (int *)(param_1[10] + param_1[0xb] * 4));

  }

  param_1[0xb] = 0;

  LeaveCriticalSection(lpCriticalSection);

  DeleteCriticalSection(lpCriticalSection);

  _DAT_00b041c0 = _DAT_00b041c0 + -1;

  if (_DAT_00b041c0 == 0) {

    if (DAT_00b041c8 != (uint32_t /* width from decompiler */ *)0x0) {

      (**(code **)*DAT_00b041c8)(1);

    }

    DAT_00b041c8 = (uint32_t /* width from decompiler */ *)0x0;

  }

  if (-1 < (int)param_1[0xc]) {

    (**(code **)(*DAT_00b05060 + 0x14))(param_1[10],param_1[0xc] * 4,0x12);

  }

  if (-1 < (int)param_1[9]) {

    (**(code **)(*DAT_00b05060 + 0x14))(param_1[7],param_1[9] * 4,0x12);

  }

  return;

}

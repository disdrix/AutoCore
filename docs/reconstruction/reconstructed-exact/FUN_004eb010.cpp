// =============================================================================
// FUN_004eb010
// -----------------------------------------------------------------------------
// Stable ID: aa_004eb010
// Address:   0x004eb010  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004eb010 @ 0x004eb010
// Stable ID: aa_004eb010
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: EnterCriticalSection, FUN_004a2670, FUN_004eaf30, FUN_004eb010, LeaveCriticalSection.
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

void __fastcall FUN_004eb010(int param_1)



{

  int *piVar1;

  void *pvVar2;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a2738;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x10));

  piVar1 = (int *)(param_1 + 0x30);

  *piVar1 = *piVar1 + -1;

  local_4 = 0;

  if (*piVar1 == 0) {

    if (*(char *)(param_1 + 0x2c) == '\0') {

      FUN_004eaf30();

      if ((DAT_00b04694 == '\0') && (*(uint32_t /* width from decompiler */ **)(param_1 + 0x3c) != (uint32_t /* width from decompiler */ *)0x0)) {

        (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x3c))(1);

      }

      pvVar2 = *(void **)(param_1 + 0x88);

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c) = 0;

      if (pvVar2 != (void *)0x0) {

        FUN_004a2670();

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar2);

      }

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x88) = 0;

      *(uint8_t *)(param_1 + 0x29) = 0;

      *(uint8_t *)(param_1 + 0x28) = 0;

    }

    else {

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x30) = 1;

    }

  }

  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x10));

  ExceptionList = pvStack_c;

  return;

}

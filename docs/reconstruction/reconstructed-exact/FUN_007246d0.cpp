// =============================================================================
// FUN_007246d0
// -----------------------------------------------------------------------------
// Stable ID: aa_007246d0
// Address:   0x007246d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007246d0 @ 0x007246d0
// Stable ID: aa_007246d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: return×2, do×1, if×1, while×1.
//  - Notable callees: EnterCriticalSection×2, LeaveCriticalSection×2, FUN_0071f010, FUN_00720d40, FUN_007223d0, FUN_00723dc0, FUN_007243a0, FUN_007246d0.
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

void __fastcall FUN_007246d0(int param_1)



{

  void *pvVar1;

  uint8_t *puVar2;

  int iVar3;

  int *piVar4;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009af12e;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x3f8));

  local_4 = 0;

  FUN_00723dc0(param_1);

  iVar3 = FUN_00720d40();

  EnterCriticalSection((LPCRITICAL_SECTION)(iVar3 + 0x158));

  *(uint8_t *)(iVar3 + 0x11) = 1;

  LeaveCriticalSection((LPCRITICAL_SECTION)(iVar3 + 0x158));

  FUN_007243a0();

  FUN_007223d0();

  piVar4 = (int *)(param_1 + 0x70);

  iVar3 = 100;

  do {

    pvVar1 = *(void **)(*piVar4 + 0x104);

    if (pvVar1 != (void *)0x0) {

      FUN_0071f010();

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar1);

    }

    *(uint32_t /* width from decompiler */ *)(*piVar4 + 0x104) = 0;

    puVar2 = (uint8_t *)*piVar4;

    piVar4 = piVar4 + 1;

    iVar3 = iVar3 + -1;

    *puVar2 = 0;

  } while (iVar3 != 0);

  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x3f8));

  ExceptionList = local_c;

  return;

}

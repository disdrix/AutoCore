// =============================================================================
// FUN_00427f10
// -----------------------------------------------------------------------------
// Stable ID: aa_00427f10
// Address:   0x00427f10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00427f10 @ 0x00427f10
// Stable ID: aa_00427f10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: return×2, if×1, while×1.
//  - Notable callees: LeaveCriticalSection×2, EnterCriticalSection, FUN_00427f10, _CxxThrowException.
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

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



void __fastcall FUN_00427f10(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ local_18;

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  puStack_c = &LAB_009be220;

  local_10 = ExceptionList;

  local_18 = 0x427f33;

  local_14 = &stack0xffffefdc;

  local_8 = 0;

  ExceptionList = &local_10;

  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));

  puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x1c);

  if (*(char *)(param_1 + 0x28) != '\0') {

    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));

    local_18 = 0x80070005;

                    /* WARNING: Subroutine does not return */

    _CxxThrowException(&local_18,(ThrowInfo *)&DAT_00acc430);

  }

  while (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = puVar1[2];

    puVar1[1] = 0;

    (**(code **)*puVar1)(1);

    puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x1c);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = 0;

  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));

  ExceptionList = local_10;

  return;

}

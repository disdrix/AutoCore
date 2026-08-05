// =============================================================================
// FUN_00416c90
// -----------------------------------------------------------------------------
// Stable ID: aa_00416c90
// Address:   0x00416c90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00416c90 @ 0x00416c90
// Stable ID: aa_00416c90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: return×2, if×1, while×1.
//  - Notable callees: LeaveCriticalSection×2, EnterCriticalSection, FUN_00416c90, _CxxThrowException.
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



void __fastcall FUN_00416c90(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ local_18;

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  puStack_c = &LAB_009bd880;

  local_10 = ExceptionList;

  local_18 = 0x416cb3;

  local_14 = &stack0xffffefcc;

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

    (**(code **)*puVar1)(1);

    puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x1c);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = 0;

  local_8 = 0xffffffff;

  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));

  ExceptionList = local_10;

  return;

}

// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_00424060
// -----------------------------------------------------------------------------
// Stable ID: aa_00424060
// Callee of Named_VOG_DEBUG_STOP (+1 other named callers)
// Address:   0x00424060  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_VOG_DEBUG_STOP (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: return×2, if×1, while×1.
//  - Notable callees: LeaveCriticalSection×2, EnterCriticalSection, FUN_00424060, _CxxThrowException.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP (+1 other named callers)
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



void __fastcall Named_CalleeOf_Named_VOG_DEBUG_STOP_00424060(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ local_18;

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  puStack_c = &LAB_009bd790;

  local_10 = ExceptionList;

  local_18 = 0x424083;

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

// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOGClient_00871690
// -----------------------------------------------------------------------------
// Stable ID: aa_00871690
// Callee of Named_CalleeOf_Named_VOGClient (+1 other named callers)
// Address:   0x00871690  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOGClient: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Named_VOGClient (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, while×1.
//  - Notable callees: FUN_004113b0×2, LeaveCriticalSection×2, FUN_004294f0, FUN_00871690.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_VOGClient (+1 other named callers)
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

int __thiscall Named_CalleeOf_Named_CalleeOf_Named_VOGClient_00871690(int param_1,int param_2,int param_3)



{

  int iVar1;

  int iVar2;

  int local_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0;

  local_8 = 0;

  FUN_004294f0();

  iVar2 = FUN_004113b0(param_1 + 0x628,&local_8);

  iVar1 = local_8;

  while( true ) {

    local_8 = iVar1;

    if (iVar2 != 0) {

      if (*(char *)(param_1 + 0x650) != '\0') {

        *(uint8_t *)(param_1 + 0x650) = 0;

        LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x62c));

      }

      return 0;

    }

    if (((iVar1 != 0) && (*(int *)(iVar1 + 8) == param_2)) && (*(int *)(iVar1 + 0xc) == param_3))

    break;

    iVar2 = FUN_004113b0(param_1 + 0x628,&local_8);

    iVar1 = local_8;

  }

  if (*(char *)(param_1 + 0x650) != '\0') {

    *(uint8_t *)(param_1 + 0x650) = 0;

    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x62c));

  }

  return iVar1;

}

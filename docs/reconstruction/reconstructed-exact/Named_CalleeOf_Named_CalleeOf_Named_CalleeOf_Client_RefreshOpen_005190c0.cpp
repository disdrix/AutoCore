// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RefreshOpen_005190c0
// -----------------------------------------------------------------------------
// Stable ID: aa_005190c0
// Callee of Named_CalleeOf_Named_CalleeOf_Client_RefreshOpenMissionUiWindow
// Address:   0x005190c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_RefreshOpenMissionUiWindow: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0040f400, FUN_005190c0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_RefreshOpenMissionUiWindow
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

uint32_t /* width from decompiler */ __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RefreshOpen_005190c0(int param_1)



{

  void *pvVar1;

  int iVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a363c;

  local_c = ExceptionList;

  if (*(int *)(param_1 + 0x15c) == 0) {

    ExceptionList = &local_c;

    pvVar1 = operator_new(0xc);

    local_4 = 0;

    if (pvVar1 == (void *)0x0) {

      pvVar1 = (void *)0x0;

    }

    else {

      iVar2 = FUN_0040f400();

      *(int *)((int)pvVar1 + 4) = iVar2;

      *(uint8_t *)(iVar2 + 0x15) = 1;

      *(int *)(*(int *)((int)pvVar1 + 4) + 4) = *(int *)((int)pvVar1 + 4);

      *(uint32_t /* width from decompiler */ *)*(uint32_t /* width from decompiler */ *)((int)pvVar1 + 4) = *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 4);

      *(int *)(*(int *)((int)pvVar1 + 4) + 8) = *(int *)((int)pvVar1 + 4);

      *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 8) = 0;

    }

    *(void **)(param_1 + 0x15c) = pvVar1;

  }

  ExceptionList = local_c;

  return *(uint32_t /* width from decompiler */ *)(param_1 + 0x15c);

}

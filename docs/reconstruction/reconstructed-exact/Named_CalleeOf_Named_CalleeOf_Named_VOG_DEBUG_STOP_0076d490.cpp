// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_0076d490
// -----------------------------------------------------------------------------
// Stable ID: aa_0076d490
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x0076d490  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, for×1.
//  - Notable callees: FUN_0076d490, strncpy.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
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

uint32_t /* width from decompiler */ __fastcall Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_0076d490(uint32_t /* width from decompiler */ param_1,char *param_2,size_t param_3)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  char *unaff_ESI;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ local_128;

  

  *unaff_ESI = '\0';

  if (*param_2 != '\0') {

    uVar1 = *(uint32_t /* width from decompiler */ *)(param_2 + 4);

    puVar3 = &local_128;

    for (iVar2 = 0x47; iVar2 != 0; iVar2 = iVar2 + -1) {

      *puVar3 = 0;

      puVar3 = puVar3 + 1;

    }

    local_128 = 0x18;

    iVar2 = (*DAT_00d0dfbc)(uVar1);

    if (iVar2 != 0) {

      strncpy(unaff_ESI,&stack0xfffffedc,param_3);

      unaff_ESI[param_3 - 1] = '\0';

      return 1;

    }

  }

  return 0;

}

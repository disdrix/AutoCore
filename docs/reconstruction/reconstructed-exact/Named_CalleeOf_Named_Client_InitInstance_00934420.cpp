// =============================================================================
// Named_CalleeOf_Named_Client_InitInstance_00934420
// -----------------------------------------------------------------------------
// Stable ID: aa_00934420
// Callee of Named_Client_InitInstance
// Address:   0x00934420  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Client_InitInstance: callee helper. Evidence string: "Preloading enabled.\n". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "Preloading enabled.\n"
//   - "Preloading disabled.\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×4, return×3.
//  - Notable callees: FUN_007a4480×2, FUN_00754230, FUN_00754280, FUN_0075d3c0, FUN_00934420, FUN_00971050, FUN_00971180.
//  - Strings: "Preloading enabled.\n"; "Preloading disabled.\n".
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_Client_InitInstance
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

void __fastcall Named_CalleeOf_Named_Client_InitInstance_00934420(int param_1)



{

  void *pvVar1;

  char in_AL;

  uint32_t /* width from decompiler */ *puVar2;

  

  if (in_AL != *(char *)(param_1 + 0xb2)) {

    *(char *)(param_1 + 0xb2) = in_AL;

    if (in_AL != '\0') {

      FUN_007a4480(0,"Preloading enabled.\n");

      FUN_0075d3c0(DAT_00d1f050);

      FUN_00754280();

      return;

    }

    FUN_007a4480(0,"Preloading disabled.\n");

    FUN_00754230();

    puVar2 = (uint32_t /* width from decompiler */ *)(DAT_00d1f050 + 0x6c);

    if (*(int *)(DAT_00d1f050 + 0x6c) != 0) {

      FUN_00971050();

      pvVar1 = (void *)*puVar2;

      if (pvVar1 != (void *)0x0) {

        FUN_00971180(pvVar1);

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar1);

      }

      *puVar2 = 0;

    }

  }

  return;

}

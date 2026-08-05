// =============================================================================
// Named_CalleeOf_Named_gfxUIWindow_00440290
// -----------------------------------------------------------------------------
// Stable ID: aa_00440290
// Callee of Named_gfxUIWindow
// Address:   0x00440290  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxUIWindow: UI/dialog helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×4, return×3.
//  - Notable callees: FUN_00440290, FUN_00442ab0, FUN_004540b0.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_gfxUIWindow
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

void __fastcall Named_CalleeOf_Named_gfxUIWindow_00440290(uint param_1,int param_2)



{

  uint uVar1;

  void *pvVar2;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009bcb60;

  local_10 = ExceptionList;

  if (0xaaaaaaa < param_1) {

    ExceptionList = &local_10;

    FUN_004540b0();

    return;

  }

  uVar1 = 0;

  if (*(int *)(param_2 + 4) != 0) {

    uVar1 = (*(int *)(param_2 + 0xc) - *(int *)(param_2 + 4)) / 0x18;

  }

  if (uVar1 < param_1) {

    ExceptionList = &local_10;

    pvVar2 = operator_new(param_1 * 0x18);

    local_8 = 0;

    FUN_00442ab0(*(uint32_t /* width from decompiler */ *)(param_2 + 4),*(uint32_t /* width from decompiler */ *)(param_2 + 8),pvVar2);

    if (*(void **)(param_2 + 4) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(*(void **)(param_2 + 4));

    }

    *(void **)(param_2 + 0xc) = (void *)(param_1 * 0x18 + (int)pvVar2);

    *(void **)(param_2 + 8) = pvVar2;

    *(void **)(param_2 + 4) = pvVar2;

  }

  ExceptionList = local_10;

  return;

}

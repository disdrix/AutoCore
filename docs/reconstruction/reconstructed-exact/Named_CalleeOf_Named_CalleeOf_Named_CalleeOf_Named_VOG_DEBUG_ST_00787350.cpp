// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_00787350
// -----------------------------------------------------------------------------
// Stable ID: aa_00787350
// Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x00787350  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, do×1, while×1.
//  - Notable callees: FUN_00429850, FUN_00787350.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_00787350(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  void **ppvVar2;

  uint32_t /* width from decompiler */ *puVar3;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009ac2c3;

  pvStack_c = ExceptionList;

  local_4 = 0;

  puVar3 = *(uint32_t /* width from decompiler */ **)(param_1 + 4);

  ExceptionList = &pvStack_c;

  ppvVar2 = &pvStack_c;

  if (puVar3 != *(uint32_t /* width from decompiler */ **)(param_1 + 8)) {

    do {

      puVar1 = (uint32_t /* width from decompiler */ *)*puVar3;

      if (*(code **)(param_1 + 0x14) != (code *)0x0) {

        (**(code **)(param_1 + 0x14))(*(uint32_t /* width from decompiler */ *)(param_1 + 0x18),puVar1[3]);

      }

      if ((code *)puVar1[2] != (code *)0x0) {

        (*(code *)puVar1[2])(*(uint32_t /* width from decompiler */ *)(param_1 + 0x18),puVar1[3]);

      }

      puVar3 = puVar3 + 1;

      *puVar1 = 0;

      ppvVar2 = ExceptionList;

    } while (puVar3 != *(uint32_t /* width from decompiler */ **)(param_1 + 8));

  }

  ExceptionList = ppvVar2;

  FUN_00429850(0);

  if (*(void **)(param_1 + 4) == (void *)0x0) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 4) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

    ExceptionList = pvStack_c;

    return;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(*(void **)(param_1 + 4));

}

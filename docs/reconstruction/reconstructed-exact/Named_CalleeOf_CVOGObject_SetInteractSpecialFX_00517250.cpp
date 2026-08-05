// =============================================================================
// Named_CalleeOf_CVOGObject_SetInteractSpecialFX_00517250
// -----------------------------------------------------------------------------
// Stable ID: aa_00517250
// Callee of CVOGObject_SetInteractSpecialFX
// Address:   0x00517250  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGObject_SetInteractSpecialFX: event/reaction helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×4, return×3, while×1.
//  - Notable callees: FUN_004b99c0, FUN_00517250, memmove.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of CVOGObject_SetInteractSpecialFX
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

void __thiscall Named_CalleeOf_CVOGObject_SetInteractSpecialFX_00517250(int param_1,void *param_2)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ *_Dst;

  

  if ((param_2 != (void *)0x0) && (*(char *)((int)param_2 + 9) == '\0')) {

    _Dst = *(uint32_t /* width from decompiler */ **)(param_1 + 0x124);

    if (_Dst != *(uint32_t /* width from decompiler */ **)(param_1 + 0x128)) {

      while (pvVar1 = (void *)*_Dst, pvVar1 != param_2) {

        _Dst = _Dst + 1;

        if (_Dst == *(uint32_t /* width from decompiler */ **)(param_1 + 0x128)) {

          return;

        }

      }

      memmove(_Dst,_Dst + 1,(*(int *)(param_1 + 0x128) - (int)(_Dst + 1) >> 2) * 4);

      *(int *)(param_1 + 0x128) = *(int *)(param_1 + 0x128) + -4;

      if (pvVar1 != (void *)0x0) {

        FUN_004b99c0();

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar1);

      }

    }

  }

  return;

}

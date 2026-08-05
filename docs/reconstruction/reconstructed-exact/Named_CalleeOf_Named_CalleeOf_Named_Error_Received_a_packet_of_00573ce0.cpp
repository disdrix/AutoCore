// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Error_Received_a_packet_of_00573ce0
// -----------------------------------------------------------------------------
// Stable ID: aa_00573ce0
// Callee of Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d
// Address:   0x00573ce0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: FUN_00573ce0, memmove.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d
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

uint32_t /* width from decompiler */ __thiscall

Named_CalleeOf_Named_CalleeOf_Named_Error_Received_a_packet_of_00573ce0(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,int param_4,int param_5)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ *_Src;

  uint32_t /* width from decompiler */ *_Dst;

  

  _Dst = *(uint32_t /* width from decompiler */ **)(param_1 + 0x38);

  if (_Dst != *(uint32_t /* width from decompiler */ **)(param_1 + 0x3c)) {

    _Src = _Dst + 1;

    do {

      pvVar1 = (void *)*_Dst;

      if ((*(int *)((int)pvVar1 + 8) == param_4) && (*(int *)((int)pvVar1 + 0xc) == param_5)) {

        if (pvVar1 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

          operator_delete(pvVar1);

        }

        *_Dst = 0;

        memmove(_Dst,_Src,(*(int *)(param_1 + 0x3c) - (int)_Src >> 2) * 4);

        *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + -4;

      }

      else {

        _Dst = _Dst + 1;

        _Src = _Src + 1;

      }

    } while (_Dst != *(uint32_t /* width from decompiler */ **)(param_1 + 0x3c));

  }

  return 0;

}

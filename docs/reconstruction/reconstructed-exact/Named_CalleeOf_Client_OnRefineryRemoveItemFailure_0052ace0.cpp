// =============================================================================
// Named_CalleeOf_Client_OnRefineryRemoveItemFailure_0052ace0
// -----------------------------------------------------------------------------
// Stable ID: aa_0052ace0
// Callee of Client_OnRefineryRemoveItemFailure
// Address:   0x0052ace0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_OnRefineryRemoveItemFailure: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_004d4790, FUN_0052ace0, memmove.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_OnRefineryRemoveItemFailure
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

void __fastcall Named_CalleeOf_Client_OnRefineryRemoveItemFailure_0052ace0(int param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ *_Src;

  uint32_t /* width from decompiler */ *_Dst;

  

  _Dst = *(uint32_t /* width from decompiler */ **)(param_1 + 0xd80);

  if (_Dst != *(uint32_t /* width from decompiler */ **)(param_1 + 0xd84)) {

    _Src = _Dst + 1;

    do {

      iVar1 = (**(code **)(*(int *)*_Dst + 0x25c))();

      if (iVar1 < 1) {

        FUN_004d4790(*_Dst);

        memmove(_Dst,_Src,(*(int *)(param_1 + 0xd84) - (int)_Src >> 2) * 4);

        *(int *)(param_1 + 0xd84) = *(int *)(param_1 + 0xd84) + -4;

      }

      else {

        _Dst = _Dst + 1;

        _Src = _Src + 1;

      }

    } while (_Dst != *(uint32_t /* width from decompiler */ **)(param_1 + 0xd84));

  }

  return;

}

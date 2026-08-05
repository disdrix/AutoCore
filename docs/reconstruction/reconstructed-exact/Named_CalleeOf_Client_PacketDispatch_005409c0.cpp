// =============================================================================
// Named_CalleeOf_Client_PacketDispatch_005409c0
// -----------------------------------------------------------------------------
// Stable ID: aa_005409c0
// Callee of Client_PacketDispatch
// Address:   0x005409c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_PacketDispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, while×1.
//  - Notable callees: FUN_005409c0, memmove.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Client_PacketDispatch
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

void Named_CalleeOf_Client_PacketDispatch_005409c0(int param_1)



{

  int *_Dst;

  

  _Dst = DAT_00b04718;

  if (DAT_00b04718 != DAT_00b0471c) {

    while (*_Dst != param_1) {

      _Dst = _Dst + 1;

      if (_Dst == DAT_00b0471c) {

        return;

      }

    }

    memmove(_Dst,_Dst + 1,((int)DAT_00b0471c - (int)(_Dst + 1) >> 2) * 4);

    DAT_00b0471c = DAT_00b0471c + -1;

  }

  return;

}

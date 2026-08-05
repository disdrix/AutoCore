// =============================================================================
// FUN_00718280
// -----------------------------------------------------------------------------
// Stable ID: aa_00718280
// Address:   0x00718280  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00718280 @ 0x00718280
// Stable ID: aa_00718280
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: _com_error::_com_error×2.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* Library Function - Single Match

    public: __thiscall _com_error::_com_error(class _com_error const &)

   

   Library: Visual Studio 2003 Debug */



_com_error * __thiscall _com_error::_com_error(_com_error *this,_com_error *param_1)



{

  *(undefined ***)this = &PTR_FUN_00a14034;

  *(uint32_t /* width from decompiler */ *)(this + 4) = *(uint32_t /* width from decompiler */ *)(param_1 + 4);

  *(uint32_t /* width from decompiler */ *)(this + 8) = *(uint32_t /* width from decompiler */ *)(param_1 + 8);

  *(uint32_t /* width from decompiler */ *)(this + 0xc) = 0;

  if (*(int *)(this + 8) != 0) {

    (**(code **)(**(int **)(this + 8) + 4))(*(uint32_t /* width from decompiler */ *)(this + 8));

  }

  return this;

}

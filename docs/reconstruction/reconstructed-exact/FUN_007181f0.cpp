// =============================================================================
// FUN_007181f0
// -----------------------------------------------------------------------------
// Stable ID: aa_007181f0
// Address:   0x007181f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007181f0 @ 0x007181f0
// Stable ID: aa_007181f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
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

    public: __thiscall _com_error::_com_error(long,struct IErrorInfo *,bool)

   

   Library: Visual Studio 2003 Debug */



_com_error * __thiscall

_com_error::_com_error(_com_error *this,long param_1,IErrorInfo *param_2,bool param_3)



{

  *(undefined ***)this = &PTR_FUN_00a14034;

  *(long *)(this + 4) = param_1;

  *(IErrorInfo **)(this + 8) = param_2;

  *(uint32_t /* width from decompiler */ *)(this + 0xc) = 0;

  if ((*(int *)(this + 8) != 0) && (param_3)) {

    (**(code **)(**(int **)(this + 8) + 4))(*(uint32_t /* width from decompiler */ *)(this + 8));

  }

  return this;

}

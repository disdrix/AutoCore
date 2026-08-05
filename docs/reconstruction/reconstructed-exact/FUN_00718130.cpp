// =============================================================================
// FUN_00718130
// -----------------------------------------------------------------------------
// Stable ID: aa_00718130
// Address:   0x00718130  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00718130 @ 0x00718130
// Stable ID: aa_00718130
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: _variant_t::_variant_t×2, _com_issue_error.
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

    public: __thiscall _variant_t::_variant_t(long,unsigned short)

   

   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug */



_variant_t * __thiscall _variant_t::_variant_t(_variant_t *this,long param_1,ushort param_2)



{

  if (((param_2 == 3) || (param_2 == 10)) || (param_2 == 0xb)) {

    if (param_2 == 10) {

      *(uint16_t *)this = 10;

      *(long *)(this + 8) = param_1;

    }

    else if (param_2 == 0xb) {

      *(uint16_t *)this = 0xb;

      *(ushort *)(this + 8) = -(ushort)(param_1 != 0);

    }

    else {

      *(uint16_t *)this = 3;

      *(long *)(this + 8) = param_1;

    }

  }

  else {

    _com_issue_error(-0x7ff8ffa9);

  }

  return this;

}

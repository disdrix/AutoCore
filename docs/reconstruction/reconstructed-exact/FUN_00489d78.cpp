// =============================================================================
// FUN_00489d78
// -----------------------------------------------------------------------------
// Stable ID: aa_00489d78
// Address:   0x00489d78  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00489d78 @ 0x00489d78
// Stable ID: aa_00489d78
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: RemoveAll×2, free.
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

    public: void __thiscall ATL::CSimpleArray<struct HINSTANCE__ *,class

   ATL::CSimpleArrayEqualHelper<struct HINSTANCE__ *> >::RemoveAll(void)

   

   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release, Visual Studio 2008 Release,

   Visual Studio 2010 Release */



void __thiscall

ATL::CSimpleArray<struct_HINSTANCE__*,class_ATL::CSimpleArrayEqualHelper<struct_HINSTANCE__*>_>::

RemoveAll(CSimpleArray<struct_HINSTANCE__*,class_ATL::CSimpleArrayEqualHelper<struct_HINSTANCE__*>_>

          *this)



{

  if (*(void **)this != (void *)0x0) {

    free(*(void **)this);

    *(uint32_t /* width from decompiler */ *)this = 0;

  }

  *(uint32_t /* width from decompiler */ *)(this + 4) = 0;

  *(uint32_t /* width from decompiler */ *)(this + 8) = 0;

  return;

}

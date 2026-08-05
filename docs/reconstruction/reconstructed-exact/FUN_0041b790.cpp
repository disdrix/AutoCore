// =============================================================================
// FUN_0041b790
// -----------------------------------------------------------------------------
// Stable ID: aa_0041b790
// Address:   0x0041b790  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0041b790 @ 0x0041b790
// Stable ID: aa_0041b790
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00422d10×2, FUN_0041b790, FUN_00421cd0, MultiByteToWideChar, lstrlenA.
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

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



void FUN_0041b790(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

                 uint32_t /* width from decompiler */ param_5)



{

  LPCSTR in_EAX;

  UINT CodePage;

  int iVar1;

  uint uVar2;

  

  CodePage = (*(code *)PTR_FUN_00af8c9c)();

  if (in_EAX == (LPCSTR)0x0) {

    iVar1 = FUN_00422d10(0,param_5);

  }

  else {

    iVar1 = lstrlenA(in_EAX);

    if (&stack0x00000000 == (uint8_t *)0x14) {

      uVar2 = 0;

    }

    else {

      iVar1 = MultiByteToWideChar(CodePage,0,in_EAX,-1,(LPWSTR)&stack0xffffffec,iVar1 + 1);

      uVar2 = -(uint)(iVar1 != 0) & (uint)&stack0xffffffec;

    }

    iVar1 = FUN_00422d10(uVar2,param_5);

  }

  if (-1 < iVar1) {

    FUN_00421cd0(param_1,0,0,param_4);

  }

  return;

}

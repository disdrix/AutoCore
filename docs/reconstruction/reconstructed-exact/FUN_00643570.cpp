// =============================================================================
// FUN_00643570
// -----------------------------------------------------------------------------
// Stable ID: aa_00643570
// Address:   0x00643570  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00643570 @ 0x00643570
// Stable ID: aa_00643570
// Embedded strings (evidence for future rename):
//   - "imagehlp.dll"
//   - "SymInitialize"
//   - "SymGetOptions"
//   - "SymSetOptions"
//   - "SymGetSymFromAddr"
//   - "StackWalk"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: GetProcAddress×8, FUN_00643570, GetCurrentProcess, LoadLibraryA.
//  - Strings: "imagehlp.dll"; "SymInitialize"; "SymGetOptions"; "SymSetOptions".
//  - Return sites: 2.

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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ * __fastcall FUN_00643570(uint32_t /* width from decompiler */ *param_1)



{

  HANDLE pvVar1;

  uint uVar2;

  bool bVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ uVar5;

  

  bVar3 = DAT_00d03118 == (HMODULE)0x0;

  *(uint16_t *)((int)param_1 + 6) = 1;

  *param_1 = &PTR_FUN_009e4480;

  if (bVar3) {

    DAT_00d03118 = LoadLibraryA("imagehlp.dll");

    _DAT_00d03114 = 1;

    DAT_00d03110 = GetProcAddress(DAT_00d03118,"SymInitialize");

    DAT_00d0310c = GetProcAddress(DAT_00d03118,"SymGetOptions");

    DAT_00d03108 = GetProcAddress(DAT_00d03118,"SymSetOptions");

    DAT_00d03104 = GetProcAddress(DAT_00d03118,"SymGetSymFromAddr");

    DAT_00d03100 = GetProcAddress(DAT_00d03118,"StackWalk");

    DAT_00d030fc = GetProcAddress(DAT_00d03118,"SymFunctionTableAccess");

    DAT_00d030f8 = GetProcAddress(DAT_00d03118,"SymGetModuleBase");

    DAT_00d030f4 = GetProcAddress(DAT_00d03118,"SymGetLineFromAddr");

    uVar5 = 1;

    uVar4 = 0;

    pvVar1 = GetCurrentProcess();

    (*DAT_00d03110)(pvVar1,uVar4,uVar5);

    uVar2 = (*DAT_00d0310c)();

    (*DAT_00d03108)(uVar2 | 0x10);

    return param_1;

  }

  _DAT_00d03114 = _DAT_00d03114 + 1;

  return param_1;

}

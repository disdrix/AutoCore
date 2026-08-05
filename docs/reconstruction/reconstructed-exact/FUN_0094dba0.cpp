// =============================================================================
// FUN_0094dba0
// -----------------------------------------------------------------------------
// Stable ID: aa_0094dba0
// Address:   0x0094dba0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0094dba0 @ 0x0094dba0
// Stable ID: aa_0094dba0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_0094dba0, atoi, strtok.
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

uint32_t /* width from decompiler */ __thiscall FUN_0094dba0(int param_1,uint32_t /* width from decompiler */ param_2,char *param_3)



{

  char cVar1;

  char *_Str;

  uint32_t /* width from decompiler */ local_c;

  uint8_t local_8;

  int local_4;

  

  local_c = 0x9021;

  _Str = strtok((char *)0x0,param_3);

  local_8 = 0;

  if (_Str == (char *)0x0) {

    local_4 = -1;

  }

  else {

    local_4 = atoi(_Str);

  }

  if (*(int *)(param_1 + 0xc7c) != 0) {

    cVar1 = (**(code **)(**(int **)(param_1 + 0xc7c) + 8))();

    if (cVar1 != '\0') {

      (**(code **)(**(int **)(param_1 + 0xc7c) + 0x18))(0xffffffff,&local_c,0xc,0);

    }

  }

  return 1;

}

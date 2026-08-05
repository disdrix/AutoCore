// =============================================================================
// FUN_0096ae20
// -----------------------------------------------------------------------------
// Stable ID: aa_0096ae20
// Address:   0x0096ae20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0096ae20 @ 0x0096ae20
// Stable ID: aa_0096ae20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: FUN_0096aa20, FUN_0096ae20, FUN_00989b60.
//  - Return sites: 3.

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

uint32_t /* width from decompiler */ __fastcall FUN_0096ae20(int *param_1)



{

  char cVar1;

  char *in_EAX;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  int *local_4;

  

  iVar2 = DAT_00d1eac0;

  local_4 = param_1;

  if ((in_EAX != (char *)0x0) && (*in_EAX != '\0')) {

    local_4 = (int *)0x0;

    cVar1 = FUN_00989b60(in_EAX,&local_4);

    if (cVar1 == '\0') {

      return 0xffffffff;

    }

    iVar2 = *local_4;

  }

  if (iVar2 == 0) {

    return 0xffffffff;

  }

  uVar3 = FUN_0096aa20(iVar2);

  return uVar3;

}

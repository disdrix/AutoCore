// =============================================================================
// FUN_00891e80
// -----------------------------------------------------------------------------
// Stable ID: aa_00891e80
// Address:   0x00891e80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00891e80 @ 0x00891e80
// Stable ID: aa_00891e80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_008904a0, FUN_00891480, FUN_00891e80, GetTickCount.
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

void FUN_00891e80(int param_1,int param_2,int param_3,int param_4)



{

  bool bVar1;

  char cVar2;

  int *in_EAX;

  DWORD DVar3;

  

  bVar1 = false;

  cVar2 = (**(code **)(*in_EAX + 0x3d8))();

  if ((cVar2 != '\0') && (in_EAX[0x16b] != 1)) {

    bVar1 = true;

  }

  in_EAX[0x16c] = param_1;

  in_EAX[0x16d] = param_2;

  in_EAX[0x16b] = 1;

  FUN_008904a0();

  in_EAX[0x169] = param_4;

  DVar3 = GetTickCount();

  in_EAX[0x168] = DVar3;

  in_EAX[0x14a] = param_3;

  in_EAX[0x149] = param_3;

  if (bVar1) {

    FUN_00891480(in_EAX);

  }

  return;

}

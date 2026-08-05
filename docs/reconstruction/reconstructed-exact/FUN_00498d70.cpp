// =============================================================================
// FUN_00498d70
// -----------------------------------------------------------------------------
// Stable ID: aa_00498d70
// Address:   0x00498d70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00498d70 @ 0x00498d70
// Stable ID: aa_00498d70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00498d70, FUN_0049c5f0, memmove.
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

void FUN_00498d70(void)



{

  size_t _Size;

  int _Src;

  uint32_t /* width from decompiler */ *puVar1;

  void *pvVar2;

  uint8_t local_4 [4];

  

  _Src = DAT_00b035dc;

  puVar1 = (uint32_t /* width from decompiler */ *)FUN_0049c5f0(local_4,DAT_00b035d8,DAT_00b035dc,&stack0x00000004);

  if ((void *)*puVar1 != (void *)_Src) {

    _Size = (DAT_00b035dc - _Src >> 2) * 4;

    pvVar2 = memmove((void *)*puVar1,(void *)_Src,_Size);

    DAT_00b035dc = (int)pvVar2 + _Size;

  }

  return;

}

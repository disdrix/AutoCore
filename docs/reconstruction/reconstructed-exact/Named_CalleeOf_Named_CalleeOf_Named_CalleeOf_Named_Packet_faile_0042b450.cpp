// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Packet_faile_0042b450
// -----------------------------------------------------------------------------
// Stable ID: aa_0042b450
// Callee of Named_CalleeOf_Named_CalleeOf_Named_Packet_failed_crypto
// Address:   0x0042b450  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_Packet_failed_crypto: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: CONCAT31, FUN_0042b450, realloc.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_Packet_failed_crypto
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Packet_faile_0042b450(int param_1)



{

  int iVar1;

  void *pvVar2;

  uint _NewSize;

  int unaff_EDI;

  

  _NewSize = (param_1 + 7 + *(uint *)(unaff_EDI + 0x30) >> 3) + 0x5dc;

  if (*(uint *)(unaff_EDI + 0x10) < _NewSize) {

    if (*(char *)(unaff_EDI + 0x14) != '\0') {

      *(uint *)(unaff_EDI + 0x10) = _NewSize;

      pvVar2 = realloc(*(void **)(unaff_EDI + 0xc),_NewSize);

      *(void **)(unaff_EDI + 0xc) = pvVar2;

      iVar1 = _NewSize * 8;

      *(int *)(unaff_EDI + 0x2c) = iVar1;

      *(int *)(unaff_EDI + 0x30) = iVar1;

      return CONCAT31((int3)((uint)iVar1 >> 8),1);

    }

  }

  else {

    *(uint *)(unaff_EDI + 0x10) = _NewSize;

  }

  *(uint8_t *)(unaff_EDI + 0x1c) = 1;

  return *(uint *)(unaff_EDI + 0x30) & 0xffffff00;

}

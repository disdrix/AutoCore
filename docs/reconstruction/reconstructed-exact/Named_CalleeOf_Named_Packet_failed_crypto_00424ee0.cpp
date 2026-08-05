// =============================================================================
// Named_CalleeOf_Named_Packet_failed_crypto_00424ee0
// -----------------------------------------------------------------------------
// Stable ID: aa_00424ee0
// Callee of Named_Packet_failed_crypto
// Address:   0x00424ee0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Packet_failed_crypto: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: BitStream_readBits, FUN_00424ee0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_Packet_failed_crypto
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void Named_CalleeOf_Named_Packet_failed_crypto_00424ee0(int param_1,uint param_2)



{

  float fVar1;

  uint uVar2;

  uint uVar3;

  byte bVar4;

  int unaff_EDI;

  

  uVar2 = param_2;

  uVar3 = (param_2 - unaff_EDI) + 1;

  fVar1 = (float)(int)uVar3;

  if ((int)uVar3 < 0) {

    fVar1 = fVar1 + _DAT_00aaa5dc;

  }

  uVar3 = (((param_2 - unaff_EDI & uVar3) != 0) - 0x7f) + ((uint)fVar1 >> 0x17);

  param_2 = 0;

  BitStream_readBits(uVar3 & 0xff,&param_2);

  bVar4 = (byte)uVar3;

  if (bVar4 != 0x20) {

    param_2 = (1 << (bVar4 & 0x1f)) - 1U & param_2;

  }

  if (uVar2 < param_2 + unaff_EDI) {

    *(uint8_t *)(param_1 + 0x1c) = 1;

  }

  return;

}

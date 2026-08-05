// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Packet_faile_00426760
// -----------------------------------------------------------------------------
// Stable ID: aa_00426760
// Callee of Named_CalleeOf_Named_CalleeOf_Named_Packet_failed_crypto
// Address:   0x00426760  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_Packet_failed_crypto: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×4, return×4.
//  - Notable callees: CONCAT31, FUN_00426760.
//  - Return sites: 4.

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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



int __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Packet_faile_00426760(int param_1,ushort param_2)



{

  float fVar1;

  uint uVar2;

  uint3 uVar3;

  

  uVar2 = *(int *)(param_1 + 0x94) - *(int *)(param_1 + 0x90);

  uVar3 = (uint3)(uVar2 >> 8);

  if (0x20 - param_2 <= uVar2) {

    return CONCAT31(uVar3,1);

  }

  if ((*(byte *)(param_1 + 0xb4) & 0xc) != 0) {

    fVar1 = (float)(int)uVar2;

    if ((int)uVar2 < 0) {

      fVar1 = fVar1 + _DAT_00aaa5dc;

    }

    if (*(float *)(param_1 + 0x1bc) <= fVar1) {

      return 1;

    }

    return 0;

  }

  return (uint)uVar3 << 8;

}

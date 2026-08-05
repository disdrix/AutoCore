// =============================================================================
// FUN_005b1360
// -----------------------------------------------------------------------------
// Stable ID: aa_005b1360
// Address:   0x005b1360  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005b1360 @ 0x005b1360
// Stable ID: aa_005b1360
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: BitStream_readBits×3, BitStream_readInt×2, BitStream_readFlag, FUN_005b1360.
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

void FUN_005b1360(short param_1,int param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  BitStream_readBits(0x40,&local_8);

  iVar1 = param_2;

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x90) = local_8;

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x94) = local_4;

  BitStream_readFlag(param_2 + 0x98);

  uVar2 = BitStream_readInt(0x14);

  *(uint32_t /* width from decompiler */ *)(iVar1 + 4) = uVar2;

  uVar2 = BitStream_readInt(0x12);

  *(uint32_t /* width from decompiler */ *)(iVar1 + 0x14) = uVar2;

  BitStream_readBits(0x10,&param_1);

  *(int *)(iVar1 + 0x1c) = (int)param_1;

  BitStream_readBits(0x10,&param_1);

  *(int *)(iVar1 + 0x20) = (int)param_1;

  return;

}

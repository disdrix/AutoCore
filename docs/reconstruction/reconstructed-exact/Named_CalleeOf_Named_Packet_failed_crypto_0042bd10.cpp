// =============================================================================
// Named_CalleeOf_Named_Packet_failed_crypto_0042bd10
// -----------------------------------------------------------------------------
// Stable ID: aa_0042bd10
// Callee of Named_Packet_failed_crypto (+3 other named callers)
// Address:   0x0042bd10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Packet_failed_crypto: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_Packet_failed_crypto (+3 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: FUN_0042b360, FUN_0042bd10, FUN_0077dcb0, FUN_0077f960, FUN_0077fb80, FUN_00783770.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_Packet_failed_crypto (+3 other named callers)
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

bool __thiscall Named_CalleeOf_Named_Packet_failed_crypto_0042bd10(int param_1,int param_2,int param_3)



{

  uint uVar1;

  int iVar2;

  int iVar3;

  char *pcVar4;

  char *pcVar5;

  bool bVar6;

  char local_130 [32];

  uint8_t local_110 [272];

  

  uVar1 = *(uint *)(param_2 + 0x10);

  iVar2 = *(int *)(param_2 + 0xc);

  if (uVar1 < (uint)(param_1 + param_3)) {

    return false;

  }

  FUN_00783770(uVar1 - param_1);

  FUN_0077dcb0(local_110);

  iVar3 = uVar1 - param_3;

  FUN_0077fb80(local_110,iVar2,iVar3);

  FUN_0077f960(local_110,local_130);

  bVar6 = true;

  pcVar4 = (char *)((iVar2 - param_3) + uVar1);

  pcVar5 = local_130;

  do {

    if (param_3 == 0) break;

    param_3 = param_3 + -1;

    bVar6 = *pcVar4 == *pcVar5;

    pcVar4 = pcVar4 + 1;

    pcVar5 = pcVar5 + 1;

  } while (bVar6);

  if (bVar6 != false) {

    FUN_0042b360(iVar3);

  }

  return bVar6;

}

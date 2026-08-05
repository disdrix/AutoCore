// =============================================================================
// FUN_0040b330
// -----------------------------------------------------------------------------
// Stable ID: aa_0040b330
// Address:   0x0040b330  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0040b330 @ 0x0040b330
// Stable ID: aa_0040b330
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: return×2, for×2, if×1.
//  - Notable callees: FUN_0040b330, FUN_0040b720, FUN_0040bbe0.
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

int __thiscall FUN_0040b330(int param_1,int *param_2)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint8_t local_310 [4];

  int local_30c;

  uint32_t /* width from decompiler */ local_308 [96];

  uint32_t /* width from decompiler */ local_188 [97];

  

  iVar1 = FUN_0040bbe0(param_2);

  if ((iVar1 != *(int *)(param_1 + 4)) && (*(int *)(iVar1 + 0xc) <= *param_2)) {

    return iVar1 + 0x10;

  }

  puVar4 = local_188;

  for (iVar3 = 0x60; iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar4 = 0;

    puVar4 = puVar4 + 1;

  }

  local_30c = *param_2;

  puVar4 = local_188;

  puVar5 = local_308;

  for (iVar3 = 0x60; iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar5 = *puVar4;

    puVar4 = puVar4 + 1;

    puVar5 = puVar5 + 1;

  }

  piVar2 = (int *)FUN_0040b720(local_310,iVar1,&local_30c);

  return *piVar2 + 0x10;

}

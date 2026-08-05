// =============================================================================
// FUN_00796760
// -----------------------------------------------------------------------------
// Stable ID: aa_00796760
// Address:   0x00796760  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00796760 @ 0x00796760
// Stable ID: aa_00796760
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×2, for×1, return×1.
//  - Notable callees: FUN_007966b0, FUN_00796760.
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

uint32_t /* width from decompiler */

FUN_00796760(int param_1,int *param_2,byte param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ *param_5)



{

  char cVar1;

  int iVar2;

  int unaff_ESI;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ local_1c [7];

  

  cVar1 = *(char *)(param_1 + 0x24);

  puVar3 = local_1c;

  for (iVar2 = 7; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar3 = *param_5;

    param_5 = param_5 + 1;

    puVar3 = puVar3 + 1;

  }

  if ((cVar1 != '\x19') && ((param_3 & 0x31) != 0)) {

    iVar2 = (**(code **)(*param_2 + 0x34))(param_2,local_1c[2],6);

    if (-1 < iVar2) {

      (**(code **)(*param_2 + 0x74))(param_2,local_1c[2],local_1c[1],-(unaff_ESI != 0) & 4);

      (**(code **)(*param_2 + 0x78))(param_2,local_1c[2],local_1c[1],0);

      FUN_007966b0();

    }

  }

  return 1;

}

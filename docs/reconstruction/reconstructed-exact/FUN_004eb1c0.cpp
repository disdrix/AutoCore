// =============================================================================
// FUN_004eb1c0
// -----------------------------------------------------------------------------
// Stable ID: aa_004eb1c0
// Address:   0x004eb1c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004eb1c0 @ 0x004eb1c0
// Stable ID: aa_004eb1c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: do×2, while×2, return×1.
//  - Notable callees: FUN_004eb1c0, FUN_00989e00.
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

uint32_t /* width from decompiler */ __thiscall FUN_004eb1c0(int param_1,uint32_t /* width from decompiler */ param_2)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  char *pcVar4;

  uint32_t /* width from decompiler */ *puVar5;

  char local_104 [4];

  uint8_t local_100 [256];

  

  pcVar4 = (char *)(param_1 + 0x188);

  iVar2 = -(int)pcVar4;

  do {

    cVar1 = *pcVar4;

    pcVar4[(int)(local_104 + iVar2)] = cVar1;

    pcVar4 = pcVar4 + 1;

  } while (cVar1 != '\0');

  puVar3 = (uint32_t /* width from decompiler */ *)&stack0xfffffefb;

  do {

    puVar5 = puVar3;

    puVar3 = (uint32_t /* width from decompiler */ *)((int)puVar5 + 1);

  } while (*(char *)((int)puVar5 + 1) != '\0');

  *(uint32_t /* width from decompiler */ *)((int)puVar5 + 1) = DAT_00a28904;

  *(uint8_t *)((int)puVar5 + 5) = DAT_00a28908;

  FUN_00989e00(param_2,local_104);

  return param_2;

}

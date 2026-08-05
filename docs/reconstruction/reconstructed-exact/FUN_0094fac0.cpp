// =============================================================================
// FUN_0094fac0
// -----------------------------------------------------------------------------
// Stable ID: aa_0094fac0
// Address:   0x0094fac0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0094fac0 @ 0x0094fac0
// Stable ID: aa_0094fac0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: strtok×2, Client_SendSectorPacket, FUN_0094fac0, atoi.
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

uint32_t /* width from decompiler */ __thiscall FUN_0094fac0(void *param_1,uint32_t /* width from decompiler */ param_2,char *param_3)



{

  int iVar1;

  uint uVar2;

  char *pcVar3;

  uint uVar4;

  uint *puVar5;

  uint32_t /* width from decompiler */ local_20 [2];

  uint local_18;

  uint local_14;

  uint8_t local_10;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  pcVar3 = strtok((char *)0x0,param_3);

  if (pcVar3 != (char *)0x0) {

    uVar4 = atoi(pcVar3);

    iVar1 = *(int *)(*(int *)((int)param_1 + 0xe98) + 0x1bc);

    if ((iVar1 == 0) ||

       ((uint)(*(int *)(*(int *)((int)param_1 + 0xe98) + 0x1c0) - iVar1 >> 4) <= uVar4)) {

      puVar5 = &DAT_00a15858;

    }

    else {

      puVar5 = (uint *)(uVar4 * 0x10 + iVar1);

    }

    uVar4 = *puVar5;

    uVar2 = puVar5[1];

    if ((((uVar4 & uVar2) != 0xffffffff) || ((char)puVar5[2] != '\0')) &&

       (pcVar3 = strtok((char *)0x0,param_3), pcVar3 != (char *)0x0)) {

      local_20[0] = 0x20a4;

      local_10 = 0;

      local_8 = 0;

      local_4 = 0;

      local_18 = uVar4;

      local_14 = uVar2;

      Client_SendSectorPacket(param_1,0x20,local_20);

    }

  }

  return 1;

}

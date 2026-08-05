// =============================================================================
// FUN_0094fbe0
// -----------------------------------------------------------------------------
// Stable ID: aa_0094fbe0
// Address:   0x0094fbe0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0094fbe0 @ 0x0094fbe0
// Stable ID: aa_0094fbe0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~56 non-empty decompiler lines.
//  - Control keywords: if×3, return×3, do×1, while×1.
//  - Notable callees: FUN_0094fbe0, strtok.
//  - Return sites: 3.

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

uint32_t /* width from decompiler */ __thiscall FUN_0094fbe0(int param_1,int param_2,char *param_3)



{

  int iVar1;

  int iVar2;

  char cVar3;

  uint32_t /* width from decompiler */ *puVar4;

  char *pcVar5;

  uint32_t /* width from decompiler */ uStack_60;

  uint8_t local_5c;

  uint32_t /* width from decompiler */ local_48;

  uint32_t /* width from decompiler */ local_44;

  uint32_t /* width from decompiler */ uStack_40;

  uint32_t /* width from decompiler */ uStack_3c;

  uint32_t /* width from decompiler */ uStack_38;

  uint32_t /* width from decompiler */ uStack_34;

  char local_30 [24];

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  

  *(uint8_t *)(param_2 + 0x2e) = 0;

  local_18 = 0;

  local_14 = 0;

  local_48 = 0;

  local_44 = 0;

  local_30[0] = '\0';

  local_5c = 0;

  puVar4 = (uint32_t /* width from decompiler */ *)

           (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0xe98) + 4) + 4) + 4 +

                                *(int *)(param_1 + 0xe98)) + 0x1a0))();

  uStack_40 = *puVar4;

  uStack_3c = puVar4[1];

  uStack_38 = puVar4[2];

  uStack_34 = puVar4[3];

  iVar1 = *(int *)(param_1 + 0xe98);

  iVar2 = *(int *)(*(int *)(iVar1 + 4) + 4);

  local_48 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x164 + iVar1);

  local_44 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x168 + iVar1);

  pcVar5 = strtok((char *)0x0,param_3);

  if (pcVar5 == (char *)0x0) {

    return 1;

  }

  iVar1 = -(int)pcVar5;

  do {

    cVar3 = *pcVar5;

    pcVar5[(int)(local_30 + iVar1)] = cVar3;

    pcVar5 = pcVar5 + 1;

  } while (cVar3 != '\0');

  uStack_60 = 0x8019;

  if (*(int *)(param_1 + 0xc7c) != 0) {

    cVar3 = (**(code **)(**(int **)(param_1 + 0xc7c) + 8))();

    if (cVar3 != '\0') {

      (**(code **)(**(int **)(param_1 + 0xc7c) + 0x18))(0xffffffff,&uStack_60,0x50,0);

      return 0;

    }

  }

  return 0x80004005;

}

// =============================================================================
// FUN_0094fcf0
// -----------------------------------------------------------------------------
// Stable ID: aa_0094fcf0
// Address:   0x0094fcf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0094fcf0 @ 0x0094fcf0
// Stable ID: aa_0094fcf0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×3, return×3, do×1, while×1.
//  - Notable callees: FUN_0094fcf0, strtok.
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

uint32_t /* width from decompiler */ __thiscall FUN_0094fcf0(int param_1,int param_2,char *param_3)



{

  int iVar1;

  int iVar2;

  char cVar3;

  char *pcVar4;

  uint32_t /* width from decompiler */ local_60;

  char local_5c [20];

  uint32_t /* width from decompiler */ local_48;

  uint32_t /* width from decompiler */ local_44;

  uint8_t local_30;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  

  *(uint8_t *)(param_2 + 0x2e) = 0;

  local_18 = 0;

  local_14 = 0;

  local_48 = 0;

  local_44 = 0;

  local_30 = 0;

  local_5c[0] = '\0';

  pcVar4 = strtok((char *)0x0,param_3);

  if (pcVar4 == (char *)0x0) {

    return 1;

  }

  iVar1 = -(int)pcVar4;

  do {

    cVar3 = *pcVar4;

    pcVar4[(int)(local_5c + iVar1)] = cVar3;

    pcVar4 = pcVar4 + 1;

  } while (cVar3 != '\0');

  iVar1 = *(int *)(param_1 + 0xe98);

  iVar2 = *(int *)(*(int *)(iVar1 + 4) + 4);

  local_18 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x164 + iVar1);

  local_14 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x168 + iVar1);

  local_60 = 0x8019;

  if (*(int *)(param_1 + 0xc7c) != 0) {

    cVar3 = (**(code **)(**(int **)(param_1 + 0xc7c) + 8))();

    if (cVar3 != '\0') {

      (**(code **)(**(int **)(param_1 + 0xc7c) + 0x18))(0xffffffff,&local_60,0x50,0);

      return 0;

    }

  }

  return 0x80004005;

}

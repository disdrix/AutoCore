// =============================================================================
// FUN_006515a0
// -----------------------------------------------------------------------------
// Stable ID: aa_006515a0
// Address:   0x006515a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006515a0 @ 0x006515a0
// Stable ID: aa_006515a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~62 non-empty decompiler lines.
//  - Control keywords: if×3, while×2, do×1, for×1, return×1.
//  - Notable callees: FUN_006515a0.
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

void __thiscall FUN_006515a0(int param_1,ushort param_2)



{

  char *pcVar1;

  byte bVar2;

  byte *pbVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  uint32_t /* width from decompiler */ *puVar8;

  uint uVar9;

  uint32_t /* width from decompiler */ *puVar10;

  uint32_t /* width from decompiler */ local_10;

  int local_c;

  int local_8;

  uint local_4;

  

  pbVar3 = (byte *)((uint)param_2 + *(int *)(param_1 + 0x20));

  uVar9 = (uint)*pbVar3;

  *pbVar3 = 0xff;

  iVar7 = *(int *)(param_1 + 0x94);

  local_10 = 0;

  local_c = 0;

  local_8 = 0;

  if (iVar7 == 2) {

    local_8 = 4;

    local_c = 0x20;

  }

  local_4 = (uint)(iVar7 == 2);

  iVar7 = iVar7 + -1;

  if ((int)uVar9 < iVar7) {

    iVar4 = uVar9 * 0x1c;

    iVar6 = iVar7 - uVar9;

    do {

      puVar10 = (uint32_t /* width from decompiler */ *)(iVar4 + *(int *)(param_1 + 0x90));

      iVar4 = iVar4 + 0x1c;

      iVar6 = iVar6 + -1;

      puVar8 = puVar10 + 7;

      for (iVar5 = 7; iVar5 != 0; iVar5 = iVar5 + -1) {

        *puVar10 = *puVar8;

        puVar8 = puVar8 + 1;

        puVar10 = puVar10 + 1;

      }

    } while (iVar6 != 0);

  }

  *(uint16_t *)(*(int *)(param_1 + 0x90) + 0x18 + uVar9 * 0x1c) = 0;

  *(int *)(param_1 + 0x94) = iVar7;

  *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + -1;

  iVar7 = *(int *)(param_1 + 0x24);

  while (iVar7 = iVar7 + -1, -1 < iVar7) {

    bVar2 = *(byte *)(*(int *)(param_1 + 0x20) + iVar7);

    pcVar1 = (char *)(*(int *)(param_1 + 0x20) + iVar7);

    if ((bVar2 != 0xff) && (uVar9 < bVar2)) {

      *pcVar1 = *pcVar1 + -1;

    }

  }

  local_8 = local_8 + 4;

  local_c = local_c + 0x30;

  local_4 = local_4 + 1;

  (**(code **)(**(int **)(param_1 + 0x14) + 0xc))(param_1,&local_10);

  *(uint *)(param_1 + 0x50) = *(uint *)(param_1 + 0x50) | 5;

  return;

}

// =============================================================================
// FUN_0065ec10
// -----------------------------------------------------------------------------
// Stable ID: aa_0065ec10
// Address:   0x0065ec10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0065ec10 @ 0x0065ec10
// Stable ID: aa_0065ec10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~72 non-empty decompiler lines.
//  - Control keywords: if×6, do×3, while×3, return×1.
//  - Notable callees: FUN_005b3300, FUN_005d68f0, FUN_0065ec10.
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

void __thiscall FUN_0065ec10(int param_1,int *param_2)



{

  uint uVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int iVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint local_a8;

  uint local_a4;

  float local_a0;

  float local_9c;

  float local_98;

  uint32_t /* width from decompiler */ local_94;

  uint32_t /* width from decompiler */ local_90 [35];

  

  uVar1 = param_2[2] & 0x7fffffff;

  if (uVar1 < 0x18) {

    iVar2 = uVar1 * 2;

    if (uVar1 == 0xc || iVar2 < 0x18) {

      iVar2 = 0x18;

    }

    FUN_005b3300(param_2,iVar2,0x10);

  }

  param_2[1] = 0x18;

  uVar1 = 0;

  do {

    local_94 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x6c);

    local_a0 = *(float *)(param_1 + 0x60);

    local_9c = *(float *)(param_1 + 100);

    local_98 = *(float *)(param_1 + 0x68);

    if ((uVar1 & 1) != 0) {

      local_a0 = local_a0 * DAT_00aaa668;

    }

    if ((uVar1 & 2) != 0) {

      local_9c = local_9c * DAT_00aaa668;

    }

    if ((uVar1 & 4) != 0) {

      local_98 = local_98 * DAT_00aaa668;

    }

    FUN_005d68f0(param_1 + 0x10,&local_a0);

    uVar1 = uVar1 + 1;

  } while ((int)uVar1 < 8);

  iVar2 = 0;

  local_a8 = 0;

  puVar6 = local_90 + 2;

  do {

    local_a4 = 1;

    iVar5 = iVar2 << 4;

    do {

      uVar1 = local_a4 ^ local_a8;

      if ((int)local_a8 < (int)uVar1) {

        iVar3 = *param_2;

        *(uint32_t /* width from decompiler */ *)(iVar3 + iVar5) = puVar6[-2];

        iVar3 = iVar3 + iVar5;

        *(uint32_t /* width from decompiler */ *)(iVar3 + 4) = puVar6[-1];

        *(uint32_t /* width from decompiler */ *)(iVar3 + 8) = *puVar6;

        *(uint32_t /* width from decompiler */ *)(iVar3 + 0xc) = puVar6[1];

        puVar4 = (uint32_t /* width from decompiler */ *)(*param_2 + iVar5 + 0x10);

        iVar2 = iVar2 + 2;

        iVar5 = iVar5 + 0x20;

        *puVar4 = local_90[uVar1 * 4];

        puVar4[1] = local_90[uVar1 * 4 + 1];

        puVar4[2] = local_90[uVar1 * 4 + 2];

        puVar4[3] = local_90[uVar1 * 4 + 3];

      }

      local_a4 = local_a4 * 2;

    } while ((int)local_a4 < 8);

    local_a8 = local_a8 + 1;

    puVar6 = puVar6 + 4;

  } while ((int)local_a8 < 8);

  return;

}

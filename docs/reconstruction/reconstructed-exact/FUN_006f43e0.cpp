// =============================================================================
// FUN_006f43e0
// -----------------------------------------------------------------------------
// Stable ID: aa_006f43e0
// Address:   0x006f43e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f43e0 @ 0x006f43e0
// Stable ID: aa_006f43e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~80 non-empty decompiler lines.
//  - Control keywords: if×5, while×3, do×1, return×1.
//  - Notable callees: FUN_006f3ec0, FUN_006f3fd0, FUN_006f43e0.
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

void __thiscall

FUN_006f43e0(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,int *param_4,float *param_5,

            uint32_t /* width from decompiler */ param_6)



{

  int iVar1;

  int *piVar2;

  int *piVar3;

  uint *puVar4;

  int iVar5;

  int iVar6;

  uint32_t /* width from decompiler */ local_40;

  uint32_t /* width from decompiler */ local_3c;

  uint32_t /* width from decompiler */ local_38;

  float local_34;

  float local_30;

  float local_2c;

  int local_28;

  int local_24;

  float local_20;

  uint local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint local_14;

  uint local_10;

  

  piVar3 = param_4;

  local_38 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x38);

  local_3c = param_6;

  local_30 = param_5[1];

  local_24 = param_4[1];

  local_34 = *param_5;

  local_20 = g_flOne / (float)local_24;

  local_18 = param_3;

  iVar6 = 0;

  local_40 = 0;

  local_14 = *(uint *)*param_4;

  local_10 = *(uint *)*param_4;

  if (g_flMsToSeconds_Inferred <= param_5[1] - *param_5) {

    local_2c = g_flOne / (param_5[1] - *param_5);

  }

  else {

    local_2c = 1.0;

  }

  iVar1 = *(int *)(*(int *)(param_1 + 8) + 8);

  iVar5 = param_4[2];

  if (iVar1 < param_4[2]) {

    iVar5 = iVar1;

  }

  if (0 < param_4[1]) {

    param_4 = (int *)0x0;

    do {

      puVar4 = (uint *)(*piVar3 + (int)param_4);

      local_1c = puVar4[2];

      if (*puVar4 <= local_14) {

        local_14 = *puVar4;

      }

      if (local_10 <= *puVar4) {

        local_10 = *puVar4;

      }

      local_28 = iVar6;

      FUN_006f3ec0(local_1c);

      piVar2 = *(int **)(param_1 + 0xc);

      iVar1 = *piVar2;

      while (iVar1 = iVar1 + -1, iVar5 < iVar1) {

        piVar2[3] = *(int *)(piVar2[2] + iVar1 * 4);

        *(uint32_t /* width from decompiler */ *)(piVar2[2] + iVar1 * 4) = 0;

        *piVar2 = *piVar2 + -1;

      }

      FUN_006f3fd0(iVar6,param_2,&local_40,&local_3c,piVar3);

      iVar6 = iVar6 + 1;

      param_4 = (int *)((int)param_4 + 0x10);

    } while (iVar6 < piVar3[1]);

  }

  piVar3 = *(int **)(param_1 + 0xc);

  iVar6 = *piVar3;

  while (iVar6 = iVar6 + -1, 0 < iVar6) {

    *(uint32_t /* width from decompiler */ *)(piVar3[2] + iVar6 * 4) = 0;

  }

  piVar3[3] = 0;

  *piVar3 = 0;

  return;

}

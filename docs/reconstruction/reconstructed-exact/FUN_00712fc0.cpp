// =============================================================================
// FUN_00712fc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00712fc0
// Address:   0x00712fc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00712fc0 @ 0x00712fc0
// Stable ID: aa_00712fc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~57 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_00713360×2, FUN_00712fc0, FUN_00713130, FUN_007131f0, FUN_00713230, FUN_00713290, FUN_007132c0, FUN_00713300.
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

void FUN_00712fc0(uint32_t /* width from decompiler */ *param_1,float *param_2,uint32_t /* width from decompiler */ *param_3,uint32_t /* width from decompiler */ param_4,

                 uint32_t /* width from decompiler */ param_5,uint32_t /* width from decompiler */ param_6,uint32_t /* width from decompiler */ param_7,uint32_t /* width from decompiler */ param_8,

                 uint32_t /* width from decompiler */ param_9,uint32_t /* width from decompiler */ param_10,uint32_t /* width from decompiler */ param_11)



{

  uint32_t /* width from decompiler */ uVar1;

  float *pfVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ uVar5;

  float10 fVar6;

  float local_2c;

  float local_28;

  float local_24;

  float local_20;

  float local_1c;

  uint8_t local_18 [8];

  float local_10;

  float local_c;

  uint32_t /* width from decompiler */ local_8 [2];

  

  pfVar2 = param_2;

  local_2c = 3.40282e+38;

  FUN_00713130(param_2,param_5,param_4,local_8,param_3);

  if (0 < (int)param_3) {

    param_2 = (float *)param_3;

    param_3 = local_8;

    do {

      uVar1 = *param_3;

      FUN_00713360(uVar1,param_5,param_4,&local_28);

      local_20 = *pfVar2 - local_28;

      local_1c = pfVar2[1] - local_24;

      FUN_007131f0(&local_20,param_6,uVar1,local_18);

      iVar3 = FUN_00713290(param_11,param_10,uVar1);

      uVar5 = param_9;

      if (iVar3 != 1) {

        uVar5 = param_8;

      }

      uVar4 = FUN_00713300(local_18,uVar5,param_7);

      FUN_00713360(uVar4,uVar5,param_7,local_18);

      FUN_00713230(local_18,param_6,uVar1,&local_20);

      local_28 = local_20 + local_28;

      local_24 = local_1c + local_24;

      fVar6 = (float10)FUN_007132c0(pfVar2,&local_28);

      if (fVar6 < (float10)local_2c) {

        local_2c = (float)fVar6;

        *param_1 = uVar1;

        param_1[1] = uVar4;

        local_c = local_24;

        local_10 = local_28;

      }

      param_3 = param_3 + 1;

      param_2 = (float *)((int)param_2 + -1);

    } while (param_2 != (float *)0x0);

  }

  *pfVar2 = local_10;

  pfVar2[1] = local_c;

  return;

}

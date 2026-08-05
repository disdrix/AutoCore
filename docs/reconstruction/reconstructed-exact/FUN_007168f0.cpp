// =============================================================================
// FUN_007168f0
// -----------------------------------------------------------------------------
// Stable ID: aa_007168f0
// Address:   0x007168f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007168f0 @ 0x007168f0
// Stable ID: aa_007168f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~87 non-empty decompiler lines.
//  - Control keywords: if×5, do×3, while×3, goto×2, return×1.
//  - Notable callees: FUN_007144b0, FUN_007168f0, FUN_00716b10, FUN_00716bc0, FUN_00716cc0, FUN_00716e00, FUN_00716ef0, FUN_00717c10.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_007168f0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

                 int param_5,float *param_6,uint32_t /* width from decompiler */ param_7,float param_8,int *param_9)



{

  float fVar1;

  float *pfVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  float10 fVar8;

  int local_164;

  float local_160;

  int local_15c;

  int *local_158;

  float local_154;

  int local_150;

  float local_14c;

  int local_148;

  int local_144;

  int local_140 [6];

  float local_128 [74];

  

  fVar8 = (float10)FUN_007144b0(param_1,param_1,param_2);

  iVar7 = 0;

  local_14c = (float)((float10)DAT_00a110d8 / (fVar8 + (float10)_DAT_00a110e4));

  do {

    fVar8 = (float10)FUN_00717c10(*(uint32_t /* width from decompiler */ *)((int)&DAT_00a10e7c + iVar7),param_3,param_4,

                                  param_1,param_2,local_14c);

    *(float *)((int)local_128 + iVar7) = (float)fVar8;

    iVar7 = iVar7 + 8;

  } while (iVar7 < 0x128);

  pfVar2 = local_128 + 1;

  iVar7 = 0x25;

  do {

    *pfVar2 = pfVar2[-1];

    pfVar2 = pfVar2 + 2;

    iVar7 = iVar7 + -1;

  } while (iVar7 != 0);

  iVar7 = FUN_00716b10(local_128,param_7,param_8,&local_160);

  fVar1 = local_128[iVar7];

  local_128[iVar7] = local_160;

  local_160 = fVar1;

  local_164 = FUN_00716bc0(local_128,local_140,&local_15c);

  FUN_00716cc0(local_128,local_140,&local_164,&local_15c);

  FUN_00716e00(local_128,iVar7,local_140,&local_164,&local_15c);

  fVar1 = local_128[iVar7];

  local_128[iVar7] = local_160;

  iVar3 = 0;

  local_148 = local_164 + -1;

  iVar6 = 0;

  local_150 = 0;

  if (0 < local_164) {

    local_158 = local_140;

    local_144 = param_5 - (int)param_6;

    iVar4 = local_164;

    iVar5 = local_15c;

    local_160 = fVar1;

    do {

      if ((iVar6 == 0) || (iVar6 == local_148)) {

        if (iVar6 == iVar5) goto LAB_00716a56;

LAB_00716a5f:

        iVar3 = *local_158;

        local_154 = local_128[iVar3];

        fVar8 = (float10)FUN_00716ef0(iVar3,param_3,param_4,param_1,param_2,local_14c,&local_154);

        *(float *)(local_144 + (int)param_6) = (float)fVar8;

        if ((iVar3 == iVar7) && (local_154 < param_8)) {

          local_154 = (local_154 + param_8) * DAT_00a0f298;

        }

        *param_6 = local_154;

        iVar3 = local_150 + 1;

        param_6 = param_6 + 1;

        iVar4 = local_164;

        iVar5 = local_15c;

        local_150 = iVar3;

      }

      else if (iVar6 == iVar5) {

LAB_00716a56:

        *param_9 = iVar3;

        goto LAB_00716a5f;

      }

      iVar6 = iVar6 + 1;

      local_158 = local_158 + 1;

    } while (iVar6 < iVar4);

  }

  return;

}

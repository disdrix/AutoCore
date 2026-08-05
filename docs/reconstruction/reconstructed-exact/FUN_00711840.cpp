// =============================================================================
// FUN_00711840
// -----------------------------------------------------------------------------
// Stable ID: aa_00711840
// Address:   0x00711840  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00711840 @ 0x00711840
// Stable ID: aa_00711840
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~82 non-empty decompiler lines.
//  - Control keywords: if×6, do×2, goto×2, while×2, return×1.
//  - Notable callees: FUN_00711840, FUN_00711af0, FUN_00713880, FUN_00714560, FUN_007147a0, FUN_00714a10, FUN_00714db0, FUN_00714f30.
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



void FUN_00711840(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,int param_4,int param_5,

                 uint32_t /* width from decompiler */ param_6,int param_7,uint32_t /* width from decompiler */ param_8,uint32_t /* width from decompiler */ *param_9)



{

  float *pfVar1;

  float fVar2;

  int iVar3;

  int iVar4;

  float fVar5;

  float *pfVar6;

  int iVar7;

  float10 extraout_ST0;

  float10 fVar8;

  float10 extraout_ST1;

  uint32_t /* width from decompiler */ local_fb4;

  float *local_fb0;

  uint8_t local_fac [400];

  float local_e1c [256];

  uint8_t local_a1c [400];

  float local_88c [256];

  uint8_t auStack_48c [1164];

  

  iVar3 = *(int *)(param_5 + 0x48);

  pfVar1 = (float *)(param_4 + 8);

  FUN_007156b0(param_2,param_3,local_e1c,local_a1c,local_fac,&local_fb4,100);

  fVar5 = _DAT_00a0f51c / *pfVar1;

  FUN_007153d0(local_e1c,local_a1c,local_fac,local_fb4,local_e1c,fVar5,100);

  local_fb0 = (float *)(param_4 + 0xc);

  FUN_00714a10(param_5 + 8,local_e1c,pfVar1,local_fb0,local_a1c,local_fac,local_fb4,100);

  FUN_00711af0(fVar5,local_e1c,0x100);

  if (*(int *)(param_5 + 0x44) != 0) {

    iVar7 = 0;

    do {

      iVar4 = ftol();

      iVar4 = iVar4 + *(short *)(iVar3 + 0x14);

      if (iVar7 < *(short *)(iVar3 + 0x1c)) {

        fVar5 = local_e1c[iVar7];

LAB_0071199b:

        pfVar6 = local_88c + iVar7;

        *pfVar6 = fVar5;

      }

      else {

        fVar5 = local_e1c[0xff];

        if (iVar4 < 0) {

          if (0xff < iVar4) goto LAB_0071199b;

          pfVar6 = local_88c + iVar7;

          *pfVar6 = local_e1c[iVar7];

        }

        else {

          if (0xff < iVar4) goto LAB_0071199b;

          pfVar6 = local_88c + iVar7;

          *pfVar6 = local_e1c[iVar4];

        }

      }

      fVar5 = local_e1c[iVar7];

      fVar2 = *pfVar6;

      iVar7 = iVar7 + 1;

    } while (iVar7 < 0x100);

    iVar7 = 0x100;

    pfVar6 = local_88c;

    do {

      iVar7 = iVar7 + -1;

      *pfVar6 = (float)(((extraout_ST1 + (float10)fVar5) - (extraout_ST0 + (float10)fVar2)) *

                        (float10)DAT_00a0f514 + (float10)*pfVar6);

      pfVar6 = pfVar6 + 1;

    } while (iVar7 != 0);

    (*(code *)PTR_memcpy_00af8a54)(local_e1c,local_88c,0x100);

  }

  FUN_00715090(local_e1c,0xc,param_4 + 0x10,local_a1c,local_fac);

  if (*(int *)(param_5 + 0x44) != 0) {

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0x20) = 0x3f800000;

  }

  FUN_007151d0(0xc,local_fac,param_4 + 0x14);

  FUN_00713880(param_1,param_7 + 0x91,param_6,auStack_48c);

  FUN_00714560(auStack_48c,param_6,0x40000000,auStack_48c);

  FUN_007147a0(auStack_48c,param_6);

  FUN_00714f30(auStack_48c,param_6,*pfVar1,param_9,0);

  pfVar6 = local_fb0;

  fVar8 = (float10)FUN_00714db0(*param_9,*local_fb0,*(uint32_t /* width from decompiler */ *)(param_5 + 0x30),*pfVar1,

                                *(uint32_t /* width from decompiler */ *)(param_5 + 0x34));

  *pfVar6 = (float)fVar8;

  return;

}

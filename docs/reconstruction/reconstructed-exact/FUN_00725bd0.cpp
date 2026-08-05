// =============================================================================
// FUN_00725bd0
// -----------------------------------------------------------------------------
// Stable ID: aa_00725bd0
// Address:   0x00725bd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00725bd0 @ 0x00725bd0
// Stable ID: aa_00725bd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~137 non-empty decompiler lines.
//  - Control keywords: if×13, return×5, goto×3, do×2, while×2.
//  - Notable callees: CONCAT31×2, ABS, FUN_0043fe60, FUN_00480460, FUN_006759b0, FUN_007249c0, FUN_00725bd0, SQRT.
//  - Return sites: 5.

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



uint __thiscall FUN_00725bd0(int param_1,int *param_2,float *param_3,float param_4)



{

  byte bVar1;

  uint uVar2;

  int *piVar3;

  float fVar4;

  float fVar5;

  bool bVar6;

  uint in_EAX;

  uint3 uVar11;

  byte *_Source;

  byte *pbVar7;

  int iVar8;

  char *_Dest;

  uint uVar9;

  int iVar10;

  int iVar12;

  byte *pbVar13;

  float *pfVar14;

  bool bVar15;

  int local_10;

  

  pfVar14 = param_3;

  if (*(char *)(param_1 + 600) == '\0') {

    return in_EAX & 0xffffff00;

  }

  uVar11 = (uint3)(in_EAX >> 8);

  if ((g_flZero < SQRT(param_3[2] * param_3[2] + param_3[1] * param_3[1] + *param_3 * *param_3)) &&

     (fVar4 = *(float *)(param_1 + 0x220) - *param_3,

     fVar5 = *(float *)(param_1 + 0x228) - param_3[2],

     _DAT_00aaab0c < ABS(fVar4 * fVar4 + fVar5 * fVar5))) {

    return (uint)uVar11 << 8;

  }

  _Source = (byte *)FUN_007249c0(param_2,CONCAT31(uVar11,DAT_00d1a614));

  iVar12 = 0;

  if (_Source == (byte *)0x0) {

    return 0;

  }

  uVar2 = *(uint *)(param_1 + 0x210);

  local_10 = 0;

  if (0 < (int)uVar2) {

    param_2 = (int *)(param_1 + 0x31c);

    do {

      iVar10 = *param_2;

      if (iVar10 != 0) {

        if ((*(char *)(iVar10 + 0x1c5) == '\0') && (*(char *)(iVar10 + 0x3a) == '\0')) {

          bVar6 = false;

        }

        else {

          bVar6 = true;

          pbVar7 = (byte *)(iVar10 + 0x48);

          pbVar13 = _Source;

          do {

            bVar1 = *pbVar7;

            bVar15 = bVar1 < *pbVar13;

            if (bVar1 != *pbVar13) {

LAB_00725ceb:

              iVar8 = (1 - (uint)bVar15) - (uint)(bVar15 != 0);

              goto LAB_00725cf0;

            }

            if (bVar1 == 0) break;

            bVar1 = pbVar7[1];

            bVar15 = bVar1 < pbVar13[1];

            if (bVar1 != pbVar13[1]) goto LAB_00725ceb;

            pbVar7 = pbVar7 + 2;

            pbVar13 = pbVar13 + 2;

          } while (bVar1 != 0);

          iVar8 = 0;

LAB_00725cf0:

          uVar9 = 0;

          pfVar14 = param_3;

          if (iVar8 == 0) goto LAB_00725d64;

        }

        if ((*(int *)(iVar10 + 0x2c) == 0x28) && (bVar6)) {

          local_10 = local_10 + 1;

        }

      }

      param_2 = param_2 + 1;

      iVar12 = iVar12 + 1;

    } while (iVar12 < (int)uVar2);

    uVar9 = uVar2;

    if (3 < local_10) {

LAB_00725d64:

      return uVar9 & 0xffffff00;

    }

  }

  _Dest = (char *)FUN_00480460();

  if (_Dest == (char *)0x0) {

    _Dest = (char *)0x0;

  }

  else {

    *(float *)(_Dest + 0x140) = *pfVar14;

    *(float *)(_Dest + 0x144) = pfVar14[1];

    *(float *)(_Dest + 0x148) = pfVar14[2];

    *(float *)(_Dest + 0x14c) = pfVar14[3];

    _Dest[0x158] = -1;

    _Dest[0x159] = -1;

    _Dest[0x15a] = -1;

    _Dest[0x15b] = -1;

  }

  param_3 = (float *)_Dest;

  strncpy(_Dest,(char *)_Source,0x104);

  _Dest[0x120] = -1;

  _Dest[0x121] = -1;

  _Dest[0x122] = -1;

  _Dest[0x123] = -1;

  _Dest[0x124] = -1;

  _Dest[0x125] = -1;

  _Dest[0x126] = -1;

  _Dest[0x127] = -1;

  _Dest[0x128] = '\x01';

  _Dest[0x10b] = '\0';

  _Dest[0x131] = '\0';

  _Dest[0x104] = '(';

  _Dest[0x105] = '\0';

  _Dest[0x106] = '\0';

  _Dest[0x107] = '\0';

  _Dest[0x150] = '\0';

  _Dest[0x151] = '\0';

  _Dest[0x152] = '\0';

  _Dest[0x153] = '\0';

  _Dest[0x118] = '\0';

  _Dest[0x119] = '\0';

  _Dest[0x11a] = '\0';

  _Dest[0x11b] = '\0';

  *(float *)(_Dest + 0x154) = param_4 * DAT_00a110d8;

  *(uint32_t /* width from decompiler */ *)(_Dest + 0x110) = DAT_00aaa688;

  *(float *)(_Dest + 0x11c) = g_flOne;

  *(uint32_t /* width from decompiler */ *)(_Dest + 0x114) = DAT_00aaa950;

  iVar12 = *(int *)(param_1 + 0x314);

  iVar10 = FUN_006759b0(iVar12,*(uint32_t /* width from decompiler */ *)(iVar12 + 4),&param_3);

  FUN_0043fe60();

  *(int *)(iVar12 + 4) = iVar10;

  piVar3 = *(int **)(iVar10 + 4);

  *piVar3 = iVar10;

  return CONCAT31((int3)((uint)piVar3 >> 8),1);

}

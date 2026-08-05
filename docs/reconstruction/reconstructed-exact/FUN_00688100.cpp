// =============================================================================
// FUN_00688100
// -----------------------------------------------------------------------------
// Stable ID: aa_00688100
// Address:   0x00688100  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00688100 @ 0x00688100
// Stable ID: aa_00688100
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~100 non-empty decompiler lines.
//  - Control keywords: if×10, return×4.
//  - Notable callees: FUN_0068f0e0×5, FUN_00687660, FUN_00687da0, FUN_00688100, _CIasin, fpatan.
//  - Return sites: 4.

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



void __thiscall FUN_00688100(int *param_1,int param_2,uint32_t /* width from decompiler */ param_3)



{

  float fVar1;

  float fVar2;

  byte bVar3;

  uint uVar4;

  int iVar5;

  uint32_t /* width from decompiler */ uVar6;

  char cVar7;

  float10 fVar8;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint local_14;

  uint local_10;

  float local_c;

  uint32_t /* width from decompiler */ local_8;

  float local_4;

  

  uVar4 = *(uint *)(*param_1 + 0xb4);

  if (((DAT_00d08e54 == '\0') || (param_1[0x13] == 0)) || (*(int *)(param_1[0x13] + 8) < 1)) {

    iVar5 = 0;

  }

  else {

    iVar5 = 1;

  }

  local_c = DAT_00af5598;

  local_4 = DAT_00af55a0;

  local_8 = DAT_00af559c;

  fVar8 = (float10)fpatan((float10)DAT_00af55a0,-(float10)DAT_00af5598);

  fVar1 = (float)(fVar8 * (float10)_DAT_009ea7bc);

  local_10 = uVar4;

  fVar8 = (float10)_CIasin();

  fVar2 = (float)(fVar8 * (float10)_DAT_009eae2c);

  if (-1 < (short)param_3) {

    FUN_0068f0e0((uint8_t *)(param_2 + 0x78),param_3,fVar1,fVar2,param_1[9]);

    *(uint8_t *)(param_2 + 0x78) = 1;

    bVar3 = *(byte *)(param_1 + 0x11);

    *(uint8_t *)(param_2 + 0xb4) = 0;

    *(float *)(param_2 + 0x7c) = (float)bVar3;

    return;

  }

  if (param_1[6] == 1) {

    local_20 = 0xbf800000;

    local_18 = 0xbf800000;

    local_24 = 0xffffffff;

    local_1c = 0xffffffff;

    if (param_1[0xd] == 0) {

      param_3 = *(uint32_t /* width from decompiler */ *)(*param_1 + 0x14);

    }

    else {

      param_3 = *(uint32_t /* width from decompiler */ *)(param_1[0xd] + 0x10);

    }

    local_14 = (uint)*(byte *)(param_1 + 0x11);

    FUN_00687660(param_3,iVar5 + uVar4,param_1[7],param_1[10],param_1[8],(float)local_14,&local_20,

                 &local_18,&local_24,&local_1c);

    if (((short)local_24 == -1) || ((int)(uVar4 & 0xffff) <= (int)(short)local_24)) {

      cVar7 = '\0';

    }

    else {

      cVar7 = '\x01';

    }

    *(char *)(param_2 + 0x78) = cVar7;

    if (cVar7 != '\0') {

      FUN_0068f0e0((char *)(param_2 + 0x78),local_24,fVar1,fVar2,param_1[9]);

      *(uint32_t /* width from decompiler */ *)(param_2 + 0x7c) = local_20;

    }

    if (((short)local_1c == -1) || ((int)(local_10 & 0xffff) <= (int)(short)local_1c)) {

      cVar7 = '\0';

    }

    else {

      cVar7 = '\x01';

    }

    *(char *)(param_2 + 0xb4) = cVar7;

    if (cVar7 != '\0') {

      FUN_0068f0e0((char *)(param_2 + 0xb4),local_1c,fVar1,fVar2,param_1[9]);

      *(uint32_t /* width from decompiler */ *)(param_2 + 0xb8) = local_18;

      return;

    }

  }

  else {

    if (param_1[6] == 3) {

      FUN_0068f0e0((uint8_t *)(param_2 + 0x78),0,fVar1,fVar2,param_1[9]);

      *(uint8_t *)(param_2 + 0x78) = 1;

      bVar3 = *(byte *)(param_1 + 0x11);

      *(uint8_t *)(param_2 + 0xb4) = 0;

      *(float *)(param_2 + 0x7c) = (float)bVar3;

      return;

    }

    uVar6 = FUN_00687da0(0xbf800000);

    if ((ushort)uVar6 < (ushort)uVar4) {

      FUN_0068f0e0((uint8_t *)(param_2 + 0x78),uVar6,fVar1,fVar2,param_1[9]);

      *(uint8_t *)(param_2 + 0x78) = 1;

      *(float *)(param_2 + 0x7c) = (float)*(byte *)(param_1 + 0x11);

    }

    *(uint8_t *)(param_2 + 0xb4) = 0;

  }

  return;

}

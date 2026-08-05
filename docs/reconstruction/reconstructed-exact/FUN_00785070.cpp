// =============================================================================
// FUN_00785070
// -----------------------------------------------------------------------------
// Stable ID: aa_00785070
// Address:   0x00785070  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00785070 @ 0x00785070
// Stable ID: aa_00785070
// Embedded strings (evidence for future rename):
//   - "Socket::recvfrom"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~139 non-empty decompiler lines.
//  - Control keywords: if×16, return×9.
//  - Notable callees: BitStream_readBits×8, BitStream_writeBits×8, FUN_007803f0×3, swi×3, CONCAT22×2, CONCAT31×2, FUN_0042adb0×2, FUN_0042b450×2.
//  - Strings: "Socket::recvfrom".
//  - Return sites: 9.

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



uint32_t /* width from decompiler */ FUN_00785070(SOCKET *param_1,uint16_t *param_2,char *param_3,int param_4,uint *param_5)



{

  code *pcVar1;

  SOCKET *pSVar2;

  uint16_t *puVar3;

  uint *puVar4;

  char cVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint uVar7;

  byte *pbVar8;

  uint16_t extraout_var;

  uint local_18;

  uint32_t /* width from decompiler */ local_14;

  sockaddr local_10;

  

  puVar3 = param_2;

  pSVar2 = param_1;

  if ((DAT_00d179e4 != 2) || (DAT_00d179e0 == '\0')) {

    param_2 = (uint16_t *)0x10;

    uVar7 = recvfrom(*param_1,param_3,param_4,0,&local_10,(int *)&param_2);

    if ((uVar7 == 0xffffffff) && (pSVar2[3] == 0)) {

      if ((DAT_00d179e4 == 1) && (DAT_00d179e0 != '\0')) {

        if ((_DAT_00d20858 & 2) == 0) {

          _DAT_00d20858 = _DAT_00d20858 | 2;

          _DAT_00d20840 = "Socket::recvfrom";

          _DAT_00d20848 = DAT_00d17a00;

          DAT_00d17a00 = &DAT_00d20840;

          _DAT_00d20844 = 0xffffffff;

        }

        local_18 = CONCAT31(local_18._1_3_,1);

        local_14 = FUN_007803f0(&DAT_00d20840);

        if ((DAT_00afdc98 + 1 <= DAT_00afdcb0) || (cVar5 = FUN_0042b450(), cVar5 != '\0')) {

          pbVar8 = (byte *)((DAT_00afdc98 >> 3) + DAT_00afdc8c);

          *pbVar8 = *pbVar8 | '\x01' << ((byte)DAT_00afdc98 & 7);

          DAT_00afdc98 = DAT_00afdc98 + 1;

        }

        FUN_0042adb0();

      }

      return 2;

    }

    FUN_007843e0();

    pSVar2 = param_1;

    FUN_00784bd0();

    if (pSVar2[3] == 0) {

      *param_5 = uVar7;

    }

    else {

      local_18 = uVar7;

      if (((uVar7 != 0xffffffff) && (uVar7 != 0)) &&

         (cVar5 = FUN_00784340(param_3,uVar7,0), cVar5 == '\0')) {

        return 2;

      }

      cVar5 = FUN_00784140(param_3,&local_18,1);

      if (cVar5 == '\0') {

        return 2;

      }

      *param_5 = local_18 & 0xffff;

    }

    puVar4 = param_5;

    if ((DAT_00d179e4 == 1) && (DAT_00d179e0 != '\0')) {

      if ((_DAT_00d20858 & 4) == 0) {

        _DAT_00d20858 = _DAT_00d20858 | 4;

        _DAT_00d20834 = "Socket::recvfrom";

        _DAT_00d20838 = 0xffffffff;

        _DAT_00d2083c = DAT_00d17a00;

        DAT_00d17a00 = &DAT_00d20834;

      }

      local_18 = CONCAT31(local_18._1_3_,1);

      local_14 = FUN_007803f0(&DAT_00d20834);

      if ((DAT_00afdc98 + 1 <= DAT_00afdcb0) ||

         (pbVar8 = (byte *)FUN_0042b450(), (char)pbVar8 != '\0')) {

        pbVar8 = (byte *)((DAT_00afdc98 >> 3) + DAT_00afdc8c);

        *pbVar8 = *pbVar8 & ~('\x01' << ((byte)DAT_00afdc98 & 7));

        DAT_00afdc98 = DAT_00afdc98 + 1;

      }

      param_5 = (uint *)CONCAT22((short)((uint)pbVar8 >> 0x10),*puVar3);

      BitStream_writeBits(0x10,&param_5);

      param_5 = (uint *)CONCAT22(extraout_var,puVar3[1]);

      BitStream_writeBits(0x10,&param_5);

      param_5 = *(uint **)(puVar3 + 2);

      BitStream_writeBits(0x20,&param_5);

      param_5 = *(uint **)(puVar3 + 4);

      BitStream_writeBits(0x20,&param_5);

      param_5 = *(uint **)(puVar3 + 6);

      BitStream_writeBits(0x20,&param_5);

      param_5 = *(uint **)(puVar3 + 8);

      BitStream_writeBits(0x20,&param_5);

      param_5 = (uint *)*puVar4;

      BitStream_writeBits(0x20,&param_5);

      BitStream_writeBits(*puVar4 * 8,param_3);

      FUN_0042adb0();

    }

    return 0;

  }

  if ((_DAT_00d20858 & 1) == 0) {

    _DAT_00d20858 = _DAT_00d20858 | 1;

    _DAT_00d2084c = "Socket::recvfrom";

    _DAT_00d20850 = 0xffffffff;

    _DAT_00d20854 = DAT_00d17a00;

    DAT_00d17a00 = &DAT_00d2084c;

  }

  FUN_007803f0(&DAT_00d2084c);

  DAT_00d179fc = DAT_00d179fc + 1;

  if ((DAT_00d179f8 != 0) && (DAT_00d179f8 <= DAT_00d179fc)) {

    pcVar1 = (code *)swi(3);

    uVar6 = (*pcVar1)();

    return uVar6;

  }

  BitStream_readFlag(&param_1);

  if ((char)param_1 == '\0') {

    BitStream_readBits(0x10,&param_1);

    *puVar3 = param_1._0_2_;

    BitStream_readBits(0x10,&param_1);

    puVar3[1] = param_1._0_2_;

    BitStream_readBits(0x20,&param_1);

    *(SOCKET **)(puVar3 + 2) = param_1;

    BitStream_readBits(0x20,&param_1);

    *(SOCKET **)(puVar3 + 4) = param_1;

    BitStream_readBits(0x20,&param_1);

    *(SOCKET **)(puVar3 + 6) = param_1;

    BitStream_readBits(0x20,&param_1);

    *(SOCKET **)(puVar3 + 8) = param_1;

    BitStream_readBits(0x20,&param_1);

    *param_5 = (uint)param_1;

    BitStream_readBits((int)param_1 * 8,param_3);

    if ((DAT_00afddd4 == '\0') && (DAT_00afddd0 < DAT_00d179e8)) {

      return 0;

    }

    pcVar1 = (code *)swi(3);

    uVar6 = (*pcVar1)();

    return uVar6;

  }

  if ((DAT_00afddd4 == '\0') && (DAT_00afddd0 < DAT_00d179e8)) {

    return 2;

  }

  pcVar1 = (code *)swi(3);

  uVar6 = (*pcVar1)();

  return uVar6;

}

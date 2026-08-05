// =============================================================================
// FUN_0071f2e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0071f2e0
// Address:   0x0071f2e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0071f2e0 @ 0x0071f2e0
// Stable ID: aa_0071f2e0
// Embedded strings (evidence for future rename):
//   - "MakeVorbisInfo ov_open_callbacks reported OV_EVERSION:Vorbis version mismatch.\n"
//   - "MakeVorbisInfo ov_open_callbacks reported OV_EBADHEADER:Invalid Vorbis bitstream header.\n"
//   - "MakeVorbisInfo ov_open_callbacks reported OV_ENOTVORBIS:Bitstream is not Vorbis data.\n"
//   - "MakeVorbisInfo ov_open_callbacks reported OV_READ error:A read from media returned an erro"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~92 non-empty decompiler lines.
//  - Control keywords: return×8, if×5, switch×1, goto×1.
//  - Notable callees: FUN_007a4480×5, CONCAT31, FUN_0071f140, FUN_0071f2e0, fopen, ov_info, ov_open, ov_open_callbacks.
//  - Return sites: 8.

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

uint __thiscall FUN_0071f2e0(uint8_t *param_1,char param_2)



{

  ushort uVar1;

  char cVar2;

  char *in_EAX;

  void *pvVar3;

  FILE *pFVar4;

  uint32_t /* width from decompiler */ uVar5;

  int iVar6;

  uint uVar7;

  

  pvVar3 = operator_new(0x2d0);

  *(void **)(param_1 + 0x40) = pvVar3;

  if (param_2 == '\0') {

    cVar2 = FUN_0071f140();

    if (cVar2 == '\0') {

      if (*(void **)(param_1 + 0x40) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(*(void **)(param_1 + 0x40));

      }

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x40) = 0;

      return 0;

    }

    *(uint8_t **)(param_1 + 0x44) = &LAB_0071ee00;

    *(uint8_t **)(param_1 + 0x4c) = &LAB_0071ed30;

    *(uint8_t **)(param_1 + 0x48) = &LAB_0071ed40;

    *(uint8_t **)(param_1 + 0x50) = &LAB_0071ed20;

    iVar6 = ov_open_callbacks(param_1 + 0x28,*(uint32_t /* width from decompiler */ *)(param_1 + 0x40),0,0,

                              *(uint32_t /* width from decompiler */ *)(param_1 + 0x44),*(uint32_t /* width from decompiler */ *)(param_1 + 0x48),

                              *(uint32_t /* width from decompiler */ *)(param_1 + 0x4c),*(uint32_t /* width from decompiler */ *)(param_1 + 0x50));

    if (iVar6 != 0) {

      uVar7 = iVar6 + 0x86;

      switch(uVar7) {

      case 0:

        uVar7 = FUN_007a4480(0,

                             "MakeVorbisInfo ov_open_callbacks reported OV_EVERSION:Vorbis version mismatch.\n"

                            );

        return uVar7 & 0xffffff00;

      case 1:

        uVar7 = FUN_007a4480(0,

                             "MakeVorbisInfo ov_open_callbacks reported OV_EBADHEADER:Invalid Vorbis bitstream header.\n"

                            );

        return uVar7 & 0xffffff00;

      case 2:

        uVar7 = FUN_007a4480(0,

                             "MakeVorbisInfo ov_open_callbacks reported OV_ENOTVORBIS:Bitstream is not Vorbis data.\n"

                            );

        return uVar7 & 0xffffff00;

      case 5:

        uVar7 = FUN_007a4480(0,

                             "MakeVorbisInfo ov_open_callbacks reported OV_EFAULT:Internal logic fault; indicates a bug or heap/stack corruption. .\n"

                            );

        break;

      case 6:

        uVar7 = FUN_007a4480(0,

                             "MakeVorbisInfo ov_open_callbacks reported OV_READ error:A read from media returned an error. \n"

                            );

        return uVar7 & 0xffffff00;

      }

      goto switchD_0071f431_caseD_3;

    }

  }

  else {

    pFVar4 = fopen(in_EAX,"rb");

    uVar7 = 0;

    if (pFVar4 == (FILE *)0x0) {

switchD_0071f431_caseD_3:

      return uVar7 & 0xffffff00;

    }

    ov_open(pFVar4,*(uint32_t /* width from decompiler */ *)(param_1 + 0x40),0,0);

  }

  uVar5 = ov_info(*(uint32_t /* width from decompiler */ *)(param_1 + 0x40),0xffffffff);

  *(uint32_t /* width from decompiler */ *)(param_1 + 4) = uVar5;

  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = 0;

  *(uint16_t *)(param_1 + 0x18) = 0;

  *(uint16_t *)(param_1 + 0x18) = 0x12;

  uVar1 = *(ushort *)(*(int *)(param_1 + 4) + 4);

  *(ushort *)(param_1 + 10) = uVar1;

  *(uint16_t *)(param_1 + 0x16) = 0x10;

  iVar6 = *(int *)(*(int *)(param_1 + 4) + 8);

  *(int *)(param_1 + 0xc) = iVar6;

  *(uint *)(param_1 + 0x10) = (uint)uVar1 * iVar6 * 2;

  *(ushort *)(param_1 + 0x14) = uVar1 * 2;

  *(uint16_t *)(param_1 + 8) = 1;

  iVar6 = ov_pcm_total(*(uint32_t /* width from decompiler */ *)(param_1 + 0x40),0xffffffff);

  iVar6 = iVar6 * (uint)*(ushort *)(param_1 + 10) * 2;

  *(int *)(param_1 + 0x1c) = iVar6;

  *param_1 = 1;

  return CONCAT31((int3)((uint)iVar6 >> 8),1);

}

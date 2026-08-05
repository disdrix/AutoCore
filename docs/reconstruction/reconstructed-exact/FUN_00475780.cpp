// =============================================================================
// FUN_00475780
// -----------------------------------------------------------------------------
// Stable ID: aa_00475780
// Address:   0x00475780  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00475780 @ 0x00475780
// Stable ID: aa_00475780
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~201 non-empty decompiler lines.
//  - Control keywords: if×40, goto×16, return×8, while×2, for×2, switch×1, do×1.
//  - Notable callees: FUN_00476cc0×6, FUN_0047ccf0×4, FUN_0047d620×2, FUN_0046d130, FUN_00471820, FUN_00474fb0, FUN_00475780, FUN_00478f50.
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

void FUN_00475780(uint param_1,int param_2,int param_3)



{

  byte *pbVar1;

  byte bVar2;

  uint uVar3;

  uint uVar4;

  int iVar5;

  uint uVar6;

  uint32_t /* width from decompiler */ *puVar7;

  uint32_t /* width from decompiler */ *puVar8;

  uint32_t /* width from decompiler */ uVar9;

  

  iVar5 = param_3;

  uVar3 = param_1;

  if ((*(byte *)(param_1 + 0x6c) & 0x40) == 0) {

    FUN_0047d930();

  }

  if ((*(char *)(uVar3 + 0x123) != '\0') && ((*(byte *)(uVar3 + 0x70) & 2) != 0)) {

    switch(*(uint8_t *)(uVar3 + 0x124)) {

    case 0:

      if ((*(byte *)(uVar3 + 0xe4) & 7) != 0) {

        if (iVar5 == 0) goto LAB_00475885;

        uVar9 = 0xff;

LAB_00475879:

        FUN_0047ccf0(uVar9);

LAB_00475885:

        FUN_0047d620();

        return;

      }

      break;

    case 1:

      if (((*(byte *)(uVar3 + 0xe4) & 7) != 0) || (*(uint *)(uVar3 + 200) < 5)) {

        if (iVar5 == 0) goto LAB_00475885;

        uVar9 = 0xf;

        goto LAB_00475879;

      }

      break;

    case 2:

      if (((byte)*(uint *)(uVar3 + 0xe4) & 7) != 4) {

        if ((iVar5 == 0) || ((*(uint *)(uVar3 + 0xe4) & 4) == 0)) goto LAB_00475885;

        uVar9 = 0xff;

        goto LAB_00475879;

      }

      break;

    case 3:

      if (((*(byte *)(uVar3 + 0xe4) & 3) != 0) || (*(uint *)(uVar3 + 200) < 3)) {

        if (iVar5 == 0) goto LAB_00475885;

        uVar9 = 0x33;

        goto LAB_00475879;

      }

      break;

    case 4:

      if (((byte)*(uint *)(uVar3 + 0xe4) & 3) != 2) {

        if ((iVar5 == 0) || ((*(uint *)(uVar3 + 0xe4) & 2) == 0)) goto LAB_00475885;

        uVar9 = 0xff;

        goto LAB_00475879;

      }

      break;

    case 5:

      if (((*(byte *)(uVar3 + 0xe4) & 1) != 0) || (*(uint *)(uVar3 + 200) < 2)) {

        if (iVar5 == 0) goto LAB_00475885;

        uVar9 = 0x55;

        goto LAB_00475879;

      }

      break;

    case 6:

      if ((*(byte *)(uVar3 + 0xe4) & 1) == 0) goto LAB_00475885;

    }

  }

  if ((*(byte *)(uVar3 + 0x68) & 4) == 0) {

                    /* WARNING: Subroutine does not return */

    FUN_00476cc0(uVar3);

  }

  *(uint32_t /* width from decompiler */ *)(uVar3 + 0x80) = *(uint32_t /* width from decompiler */ *)(uVar3 + 0xec);

  *(uint32_t /* width from decompiler */ *)(uVar3 + 0x84) = *(uint32_t /* width from decompiler */ *)(uVar3 + 0xdc);

  do {

    if (*(int *)(uVar3 + 0x78) == 0) {

      iVar5 = *(int *)(uVar3 + 0x10c);

      while (iVar5 == 0) {

        FUN_0047a480();

        if (*(code **)(uVar3 + 0x50) == (code *)0x0) {

LAB_00475a76:

                    /* WARNING: Subroutine does not return */

          FUN_00476cc0(uVar3);

        }

        (**(code **)(uVar3 + 0x50))(uVar3,&param_1,4);

        uVar4 = (((param_1 & 0xff) * 0x100 + (param_1 >> 8 & 0xff)) * 0x100 + (param_1._2_2_ & 0xff)

                ) * 0x100 + (uint)(param_1._2_2_ >> 8);

        if (0x7fffffff < uVar4) {

                    /* WARNING: Subroutine does not return */

          FUN_00476cc0(uVar3);

        }

        *(uint *)(uVar3 + 0x10c) = uVar4;

        *(uint32_t /* width from decompiler */ *)(uVar3 + 0x110) = 0;

        pbVar1 = (byte *)(uVar3 + 0x11c);

        if (*(code **)(uVar3 + 0x50) == (code *)0x0) goto LAB_00475a76;

        (**(code **)(uVar3 + 0x50))(uVar3,pbVar1,4);

        if ((*pbVar1 & 0x20) == 0) {

          if ((*(uint *)(uVar3 + 0x6c) & 0x800) == 0) goto LAB_00475973;

        }

        else if ((*(uint *)(uVar3 + 0x6c) & 0x300) != 0x300) {

LAB_00475973:

          if (pbVar1 == (byte *)0x0) {

            uVar9 = 0;

          }

          else {

            uVar9 = FUN_0046d130();

          }

          *(uint32_t /* width from decompiler */ *)(uVar3 + 0x110) = uVar9;

        }

        if (*(int *)pbVar1 != DAT_00a265a0) {

                    /* WARNING: Subroutine does not return */

          FUN_00476cc0(uVar3);

        }

        iVar5 = *(int *)(uVar3 + 0x10c);

      }

      *(uint *)(uVar3 + 0x78) = *(uint *)(uVar3 + 0xb0);

      *(uint32_t /* width from decompiler */ *)(uVar3 + 0x74) = *(uint32_t /* width from decompiler */ *)(uVar3 + 0xac);

      if (*(uint *)(uVar3 + 0x10c) < *(uint *)(uVar3 + 0xb0)) {

        *(uint *)(uVar3 + 0x78) = *(uint *)(uVar3 + 0x10c);

      }

      FUN_0047a420();

      *(int *)(uVar3 + 0x10c) = *(int *)(uVar3 + 0x10c) - *(int *)(uVar3 + 0x78);

    }

    iVar5 = FUN_00478f50(uVar3 + 0x74,1);

    if (iVar5 == 1) {

      if (((*(int *)(uVar3 + 0x84) != 0) || (*(int *)(uVar3 + 0x78) != 0)) ||

         (*(int *)(uVar3 + 0x10c) != 0)) {

                    /* WARNING: Subroutine does not return */

        FUN_00476cc0(uVar3);

      }

      *(uint *)(uVar3 + 0x68) = *(uint *)(uVar3 + 0x68) | 8;

      *(uint *)(uVar3 + 0x6c) = *(uint *)(uVar3 + 0x6c) | 0x20;

      break;

    }

    if (iVar5 != 0) {

                    /* WARNING: Subroutine does not return */

      FUN_00476cc0(uVar3);

    }

  } while (*(int *)(uVar3 + 0x84) != 0);

  *(uint8_t *)(uVar3 + 0x109) = *(uint8_t *)(uVar3 + 0x127);

  bVar2 = *(byte *)(uVar3 + 0x129);

  *(uint8_t *)(uVar3 + 0x108) = *(uint8_t *)(uVar3 + 0x126);

  iVar5 = *(int *)(uVar3 + 0xe0);

  *(byte *)(uVar3 + 0x10b) = bVar2;

  *(int *)(uVar3 + 0x100) = iVar5;

  *(uint8_t *)(uVar3 + 0x10a) = *(uint8_t *)(uVar3 + 0x12a);

  if (bVar2 < 8) {

    uVar4 = (uint)bVar2 * iVar5 + 7 >> 3;

  }

  else {

    uVar4 = (uint)(bVar2 >> 3) * iVar5;

  }

  *(uint *)(uVar3 + 0x104) = uVar4;

  if (**(char **)(uVar3 + 0xec) != '\0') {

    FUN_0047d450(uVar3,*(char **)(uVar3 + 0xec) + 1);

  }

  uVar6 = *(int *)(uVar3 + 0xd8) + 1;

  puVar7 = *(uint32_t /* width from decompiler */ **)(uVar3 + 0xec);

  puVar8 = *(uint32_t /* width from decompiler */ **)(uVar3 + 0xe8);

  for (uVar4 = uVar6 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {

    *puVar8 = *puVar7;

    puVar7 = puVar7 + 1;

    puVar8 = puVar8 + 1;

  }

  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {

    *(uint8_t *)puVar8 = *(uint8_t *)puVar7;

    puVar7 = (uint32_t /* width from decompiler */ *)((int)puVar7 + 1);

    puVar8 = (uint32_t /* width from decompiler */ *)((int)puVar8 + 1);

  }

  if (((*(byte *)(uVar3 + 0x230) & 4) != 0) && (*(char *)(uVar3 + 0x238) == '@')) {

    FUN_00474fb0();

  }

  if ((*(int *)(uVar3 + 0x70) != 0) || ((*(byte *)(uVar3 + 0x6e) & 0x40) != 0)) {

    FUN_00471820(uVar3);

  }

  if ((*(char *)(uVar3 + 0x123) == '\0') || ((*(byte *)(uVar3 + 0x70) & 2) == 0)) {

    if (param_2 != 0) {

      FUN_0047ccf0(0xff);

    }

    if (param_3 == 0) goto LAB_00475be6;

    uVar9 = 0xff;

  }

  else {

    if (*(byte *)(uVar3 + 0x124) < 6) {

      FUN_0047d000();

    }

    if (param_3 != 0) {

      FUN_0047ccf0(*(uint32_t /* width from decompiler */ *)(&DAT_00a266cc + (uint)*(byte *)(uVar3 + 0x124) * 4));

    }

    if (param_2 == 0) goto LAB_00475be6;

    uVar9 = *(uint32_t /* width from decompiler */ *)(&DAT_00a266b0 + (uint)*(byte *)(uVar3 + 0x124) * 4);

  }

  FUN_0047ccf0(uVar9);

LAB_00475be6:

  FUN_0047d620();

  if (*(code **)(uVar3 + 0x198) != (code *)0x0) {

    (**(code **)(uVar3 + 0x198))(uVar3,*(uint32_t /* width from decompiler */ *)(uVar3 + 0xe4),*(uint8_t *)(uVar3 + 0x124))

    ;

  }

  return;

}

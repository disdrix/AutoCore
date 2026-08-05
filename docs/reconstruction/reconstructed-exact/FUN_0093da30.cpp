// =============================================================================
// FUN_0093da30
// -----------------------------------------------------------------------------
// Stable ID: aa_0093da30
// Address:   0x0093da30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0093da30 @ 0x0093da30
// Stable ID: aa_0093da30
// Embedded strings (evidence for future rename):
//   - "Distance:"
//   - "\n%s %0.1f %s!"
//   - "Height:"
//   - "Hang Time:"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~228 non-empty decompiler lines.
//  - Control keywords: if×15, do×7, while×7, for×6, return×1.
//  - Notable callees: FUN_007a69d0×7, FUN_007a6de0×7, sprintf×3, Client_MaybeShowFirstTimeTip, Client_SendSectorPacket, FUN_0040acb0, FUN_004fb130, FUN_0079a120.
//  - Strings: "Distance:"; "\n%s %0.1f %s!"; "Height:"; "Hang Time:".
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



uint32_t /* width from decompiler */ FUN_0093da30(void)



{

  float fVar1;

  char cVar2;

  int iVar3;

  int iVar4;

  bool bVar5;

  bool bVar6;

  bool bVar7;

  char *pcVar8;

  uint32_t /* width from decompiler */ uVar9;

  uint uVar10;

  uint uVar11;

  char *pcVar12;

  void *unaff_EBX;

  uint32_t /* width from decompiler */ uVar13;

  uint8_t uStack_194;

  uint8_t uStack_193;

  uint8_t uStack_192;

  uint8_t uStack_191;

  char acStack_190 [16];

  uint32_t /* width from decompiler */ uStack_180;

  uint32_t /* width from decompiler */ uStack_17c;

  uint32_t /* width from decompiler */ uStack_178;

  uint32_t /* width from decompiler */ uStack_174;

  uint32_t /* width from decompiler */ uStack_170;

  uint32_t /* width from decompiler */ uStack_16c;

  uint32_t /* width from decompiler */ uStack_168;

  uint32_t /* width from decompiler */ uStack_164;

  uint32_t /* width from decompiler */ uStack_160;

  uint32_t /* width from decompiler */ uStack_15c;

  uint32_t /* width from decompiler */ uStack_158;

  char cStack_111;

  char acStack_110 [268];

  

  if ((((*(char *)((int)unaff_EBX + 0x13) != '\0') &&

       (iVar3 = *(int *)((int)unaff_EBX + 0xe04), iVar3 != 0)) && (*(int *)(iVar3 + 0xe4a4) != 0))

     && (((*(int *)(iVar3 + 0xe894) != 0 && (*(char *)(*(int *)(iVar3 + 0xe894) + 0x8c) != '\0')) &&

         (*(float *)((int)unaff_EBX + 0xd88) <= 0.0 && *(float *)((int)unaff_EBX + 0xd88) != 0.0))))

  {

    FUN_0079a1c0(4);

    iVar3 = DAT_00d09874;

    if ((*(int **)((int)unaff_EBX + 0xf40) != (int *)0x0) &&

       (**(int **)((int)unaff_EBX + 0xf40) == *(int *)((int)unaff_EBX + 0xf38))) {

      *(uint32_t /* width from decompiler */ *)((int)unaff_EBX + 0x148) = 1;

      fVar1 = *(float *)(iVar3 + 0x30);

      if (_DAT_00aaab14 < fVar1) {

        if (fVar1 <= DAT_00aaac18) {

          *(uint32_t /* width from decompiler */ *)((int)unaff_EBX + 0x148) = 2;

        }

        else if (fVar1 <= g_flMultiKillCountBlend) {

          *(uint32_t /* width from decompiler */ *)((int)unaff_EBX + 0x148) = 3;

        }

        else {

          *(uint32_t /* width from decompiler */ *)((int)unaff_EBX + 0x148) = 4;

        }

      }

      if (g_flZero < *(float *)(iVar3 + 0x30)) {

        *(int *)((int)unaff_EBX + 0x1b0) = *(int *)((int)unaff_EBX + 0x1b0) + 1;

        if (*(int *)((int)unaff_EBX + 0x148) < 1) {

          *(int *)((int)unaff_EBX + 0x1b4) = *(int *)((int)unaff_EBX + 0x1b4) + 1;

        }

        else {

          *(float *)((int)unaff_EBX + 0x9b0) = g_flOne;

          (**(code **)(**(int **)((int)unaff_EBX + 0xe04) + 0x10))();

        }

        if (((*(int *)((int)unaff_EBX + 0xe98) != 0) &&

            (iVar3 = *(int *)(*(int *)((int)unaff_EBX + 0xe98) + 0x250), iVar3 != 0)) &&

           (*(int *)(iVar3 + 8) != 0)) {

          *(uint32_t /* width from decompiler */ *)(iVar3 + 0x13c) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x138);

          FUN_0040acb0();

          FUN_004fb130(*(uint32_t /* width from decompiler */ *)(DAT_00d09874 + 0x30));

          iVar3 = *(int *)(*(int *)((int)unaff_EBX + 0xe98) + 0x250);

          if (*(int *)(iVar3 + 0x118) == 2) {

            *(uint32_t /* width from decompiler */ *)(iVar3 + 0x118) = 0;

            pcVar12 = *(char **)(*(int *)(*(int *)((int)unaff_EBX + 0xe98) + 0x250) + 0x1a4);

            if (*pcVar12 != '\0') {

              *pcVar12 = '\0';

              iVar3 = *(int *)((int)unaff_EBX + 0xe98);

              iVar4 = *(int *)(*(int *)(iVar3 + 0x250) + 0x1a4);

              bVar5 = *(float *)(iVar4 + 0x7c) == *(float *)(iVar4 + 0x90);

              iVar4 = *(int *)(*(int *)(iVar3 + 0x250) + 0x1a4);

              bVar6 = *(float *)(iVar4 + 0x80) == *(float *)(iVar4 + 0x94);

              iVar3 = *(int *)(*(int *)(iVar3 + 0x250) + 0x1a4);

              bVar7 = *(float *)(iVar3 + 0x84) == *(float *)(iVar3 + 0x98);

              if (((bVar5) || (bVar6)) || (bVar7)) {

                Client_MaybeShowFirstTimeTip(0x1a);

              }

              if (*(char *)((int)unaff_EBX + 0x9e4) != '\0') {

                FUN_007a69d0();

                pcVar8 = (char *)FUN_007a6de0();

                pcVar12 = acStack_110;

                do {

                  cVar2 = *pcVar8;

                  *pcVar12 = cVar2;

                  pcVar8 = pcVar8 + 1;

                  pcVar12 = pcVar12 + 1;

                } while (cVar2 != '\0');

                if (bVar5) {

                  iVar3 = *(int *)(*(int *)(*(int *)((int)unaff_EBX + 0xe98) + 0x250) + 0x1a4);

                  FUN_007a69d0();

                  uVar9 = FUN_007a6de0();

                  uVar13 = 0xffffffff;

                  pcVar12 = "Distance:";

                  FUN_007a69d0("Distance:",0xffffffff,(double)*(float *)(iVar3 + 0x7c),uVar9);

                  uVar9 = FUN_007a6de0(pcVar12,uVar13);

                  sprintf(acStack_190,"\n%s %0.1f %s!",uVar9);

                  pcVar12 = acStack_190;

                  do {

                    cVar2 = *pcVar12;

                    pcVar12 = pcVar12 + 1;

                  } while (cVar2 != '\0');

                  uVar10 = (int)pcVar12 - (int)acStack_190;

                  pcVar12 = &cStack_111;

                  do {

                    pcVar8 = pcVar12 + 1;

                    pcVar12 = pcVar12 + 1;

                  } while (*pcVar8 != '\0');

                  pcVar8 = acStack_190;

                  for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {

                    *(uint32_t /* width from decompiler */ *)pcVar12 = *(uint32_t /* width from decompiler */ *)pcVar8;

                    pcVar8 = pcVar8 + 4;

                    pcVar12 = pcVar12 + 4;

                  }

                  for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {

                    *pcVar12 = *pcVar8;

                    pcVar8 = pcVar8 + 1;

                    pcVar12 = pcVar12 + 1;

                  }

                }

                if (bVar6) {

                  iVar3 = *(int *)(*(int *)(*(int *)((int)unaff_EBX + 0xe98) + 0x250) + 0x1a4);

                  FUN_007a69d0();

                  uVar9 = FUN_007a6de0();

                  uVar13 = 0xffffffff;

                  pcVar12 = "Height:";

                  FUN_007a69d0("Height:",0xffffffff,(double)*(float *)(iVar3 + 0x80),uVar9);

                  uVar9 = FUN_007a6de0(pcVar12,uVar13);

                  sprintf(acStack_190,"\n%s %0.1f %s!",uVar9);

                  pcVar12 = acStack_190;

                  do {

                    cVar2 = *pcVar12;

                    pcVar12 = pcVar12 + 1;

                  } while (cVar2 != '\0');

                  uVar10 = (int)pcVar12 - (int)acStack_190;

                  pcVar12 = &cStack_111;

                  do {

                    pcVar8 = pcVar12 + 1;

                    pcVar12 = pcVar12 + 1;

                  } while (*pcVar8 != '\0');

                  pcVar8 = acStack_190;

                  for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {

                    *(uint32_t /* width from decompiler */ *)pcVar12 = *(uint32_t /* width from decompiler */ *)pcVar8;

                    pcVar8 = pcVar8 + 4;

                    pcVar12 = pcVar12 + 4;

                  }

                  for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {

                    *pcVar12 = *pcVar8;

                    pcVar8 = pcVar8 + 1;

                    pcVar12 = pcVar12 + 1;

                  }

                }

                if (bVar7) {

                  iVar3 = *(int *)(*(int *)(*(int *)((int)unaff_EBX + 0xe98) + 0x250) + 0x1a4);

                  FUN_007a69d0();

                  uVar9 = FUN_007a6de0();

                  uVar13 = 0xffffffff;

                  pcVar12 = "Hang Time:";

                  FUN_007a69d0("Hang Time:",0xffffffff,(double)*(float *)(iVar3 + 0x84),uVar9);

                  uVar9 = FUN_007a6de0(pcVar12,uVar13);

                  sprintf(acStack_190,"\n%s %0.1f %s!",uVar9);

                  pcVar12 = acStack_190;

                  do {

                    cVar2 = *pcVar12;

                    pcVar12 = pcVar12 + 1;

                  } while (cVar2 != '\0');

                  uVar10 = (int)pcVar12 - (int)acStack_190;

                  pcVar12 = &cStack_111;

                  do {

                    pcVar8 = pcVar12 + 1;

                    pcVar12 = pcVar12 + 1;

                  } while (*pcVar8 != '\0');

                  pcVar8 = acStack_190;

                  for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {

                    *(uint32_t /* width from decompiler */ *)pcVar12 = *(uint32_t /* width from decompiler */ *)pcVar8;

                    pcVar8 = pcVar8 + 4;

                    pcVar12 = pcVar12 + 4;

                  }

                  for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {

                    *pcVar12 = *pcVar8;

                    pcVar8 = pcVar8 + 1;

                    pcVar12 = pcVar12 + 1;

                  }

                }

                uStack_192 = 0xff;

                uStack_191 = 0xff;

                uStack_193 = 0xf5;

                uStack_194 = 0xeb;

                FUN_007fde80(acStack_110,&uStack_194,0x40800000,0x3f000000,5);

              }

            }

            iVar3 = *(int *)((int)unaff_EBX + 0xe98);

            acStack_190[0] = 'c';

            acStack_190[1] = ' ';

            acStack_190[2] = '\0';

            acStack_190[3] = '\0';

            uStack_160 = *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar3 + 0x250) + 0x1a4) + 0x7c);

            uStack_158 = *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar3 + 0x250) + 0x1a4) + 0x84);

            uStack_15c = *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar3 + 0x250) + 0x1a4) + 0x80);

            iVar4 = *(int *)(*(int *)(iVar3 + 0x250) + 0x1a4);

            uStack_180 = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x10);

            uStack_17c = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x14);

            uStack_178 = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x18);

            uStack_174 = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x1c);

            iVar3 = *(int *)(*(int *)(iVar3 + 0x250) + 0x1a4);

            uStack_170 = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x40);

            uStack_16c = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x44);

            uStack_168 = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x48);

            uStack_164 = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x4c);

            Client_SendSectorPacket(unaff_EBX,0x40,acStack_190);

          }

        }

      }

    }

    FUN_0079a120(4);

  }

  return 0;

}

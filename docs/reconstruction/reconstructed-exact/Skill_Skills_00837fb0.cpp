// READABILITY (auto CF):
//  - Body size: ~431 non-empty decompiler lines.
//  - Control keywords: do×25, while×25, for×22, if×10, return×1.
//  - Notable callees: block×80, FUN_007a6de0×12, sprintf×5, FUN_00837cd0×3, FUN_005122c0×2, FUN_004c3300, FUN_007a69d0, FUN_00837fb0.
//  - Strings: "Level"; "%s: %i\n"; "Level Diff"; "%s: %i/%i\n".
//  - Return sites: 1.

// =============================================================================
// Skill_Skills_00837fb0
// -----------------------------------------------------------------------------
// Stable ID: aa_00837fb0
// Address:   0x00837fb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "Skills: "
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Removing unreachable block (ram,0x00838786) */

/* WARNING: Removing unreachable block (ram,0x00838796) */

/* WARNING: Removing unreachable block (ram,0x0083879f) */

/* WARNING: Removing unreachable block (ram,0x008387b0) */

/* WARNING: Removing unreachable block (ram,0x008387ba) */

/* WARNING: Removing unreachable block (ram,0x008387bf) */

/* WARNING: Removing unreachable block (ram,0x008387c1) */

/* WARNING: Removing unreachable block (ram,0x008387c6) */

/* WARNING: Removing unreachable block (ram,0x008386f6) */

/* WARNING: Removing unreachable block (ram,0x00838706) */

/* WARNING: Removing unreachable block (ram,0x0083870f) */

/* WARNING: Removing unreachable block (ram,0x00838720) */

/* WARNING: Removing unreachable block (ram,0x0083872a) */

/* WARNING: Removing unreachable block (ram,0x0083872f) */

/* WARNING: Removing unreachable block (ram,0x00838731) */

/* WARNING: Removing unreachable block (ram,0x00838736) */

/* WARNING: Removing unreachable block (ram,0x00838666) */

/* WARNING: Removing unreachable block (ram,0x00838676) */

/* WARNING: Removing unreachable block (ram,0x0083867f) */

/* WARNING: Removing unreachable block (ram,0x00838690) */

/* WARNING: Removing unreachable block (ram,0x0083869a) */

/* WARNING: Removing unreachable block (ram,0x0083869f) */

/* WARNING: Removing unreachable block (ram,0x008386a1) */

/* WARNING: Removing unreachable block (ram,0x008386a6) */

/* WARNING: Removing unreachable block (ram,0x008385d6) */

/* WARNING: Removing unreachable block (ram,0x008385e6) */

/* WARNING: Removing unreachable block (ram,0x008385ef) */

/* WARNING: Removing unreachable block (ram,0x00838600) */

/* WARNING: Removing unreachable block (ram,0x0083860a) */

/* WARNING: Removing unreachable block (ram,0x0083860f) */

/* WARNING: Removing unreachable block (ram,0x00838611) */

/* WARNING: Removing unreachable block (ram,0x00838616) */

/* WARNING: Removing unreachable block (ram,0x00838548) */

/* WARNING: Removing unreachable block (ram,0x00838558) */

/* WARNING: Removing unreachable block (ram,0x00838561) */

/* WARNING: Removing unreachable block (ram,0x00838570) */

/* WARNING: Removing unreachable block (ram,0x0083857a) */

/* WARNING: Removing unreachable block (ram,0x0083857f) */

/* WARNING: Removing unreachable block (ram,0x00838581) */

/* WARNING: Removing unreachable block (ram,0x00838586) */

/* WARNING: Removing unreachable block (ram,0x0083858f) */

/* WARNING: Removing unreachable block (ram,0x008385a0) */

/* WARNING: Removing unreachable block (ram,0x008385a9) */

/* WARNING: Removing unreachable block (ram,0x008385b7) */

/* WARNING: Removing unreachable block (ram,0x008385c1) */

/* WARNING: Removing unreachable block (ram,0x008385c6) */

/* WARNING: Removing unreachable block (ram,0x008385c8) */

/* WARNING: Removing unreachable block (ram,0x008385cd) */

/* WARNING: Removing unreachable block (ram,0x0083861f) */

/* WARNING: Removing unreachable block (ram,0x00838630) */

/* WARNING: Removing unreachable block (ram,0x00838639) */

/* WARNING: Removing unreachable block (ram,0x00838647) */

/* WARNING: Removing unreachable block (ram,0x00838651) */

/* WARNING: Removing unreachable block (ram,0x00838656) */

/* WARNING: Removing unreachable block (ram,0x00838658) */

/* WARNING: Removing unreachable block (ram,0x0083865d) */

/* WARNING: Removing unreachable block (ram,0x008386af) */

/* WARNING: Removing unreachable block (ram,0x008386c0) */

/* WARNING: Removing unreachable block (ram,0x008386c9) */

/* WARNING: Removing unreachable block (ram,0x008386d7) */

/* WARNING: Removing unreachable block (ram,0x008386e1) */

/* WARNING: Removing unreachable block (ram,0x008386e6) */

/* WARNING: Removing unreachable block (ram,0x008386e8) */

/* WARNING: Removing unreachable block (ram,0x008386ed) */

/* WARNING: Removing unreachable block (ram,0x0083873f) */

/* WARNING: Removing unreachable block (ram,0x00838750) */

/* WARNING: Removing unreachable block (ram,0x00838759) */

/* WARNING: Removing unreachable block (ram,0x00838767) */

/* WARNING: Removing unreachable block (ram,0x00838771) */

/* WARNING: Removing unreachable block (ram,0x00838776) */

/* WARNING: Removing unreachable block (ram,0x00838778) */

/* WARNING: Removing unreachable block (ram,0x0083877d) */

/* WARNING: Removing unreachable block (ram,0x008387cf) */

/* WARNING: Removing unreachable block (ram,0x008387e0) */

/* WARNING: Removing unreachable block (ram,0x008387e9) */

/* WARNING: Removing unreachable block (ram,0x008387f7) */

/* WARNING: Removing unreachable block (ram,0x00838801) */

/* WARNING: Removing unreachable block (ram,0x00838806) */

/* WARNING: Removing unreachable block (ram,0x00838808) */

/* WARNING: Removing unreachable block (ram,0x0083880d) */



void Skill_Skills_00837fb0(void)



{

  int *piVar1;

  short sVar2;

  char cVar3;

  int in_EAX;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  int iVar7;

  int iVar8;

  char *pcVar9;

  uint uVar10;

  char *pcVar11;

  uint uVar12;

  char *pcVar13;

  char *pcVar14;

  uint32_t /* width from decompiler */ uVar15;

  char local_888 [127];

  char cStack_809;

  char acStack_808 [2056];

  

  if (*(int *)(in_EAX + 0x518) != 0) {

    FUN_007a69d0();

    iVar4 = *(int *)(in_EAX + 0x518);

    iVar7 = *(int *)(*(int *)(iVar4 + 0xa8) + 0x38);

    if ((((iVar7 == 0x12) || ((iVar7 == 0xe && (iVar4 = *(int *)(iVar4 + 0xac), iVar4 != 0)))) &&

        (iVar4 = __RTDynamicCast(iVar4,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,

                                 &CVOGCreature::RTTI_Type_Descriptor,0), iVar4 != 0)) &&

       (cVar3 = FUN_004c3300(*(uint8_t *)

                              (*(int *)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xac +

                                                DAT_00d1b6d8) + 0x3c) + 0x532)), cVar3 != '\0')) {

      uVar5 = FUN_005122c0();

      uVar6 = FUN_007a6de0("Level",0xffffffff);

      sprintf(local_888,"%s: %i\n",uVar6,uVar5);

      iVar7 = 0;

      do {

        pcVar9 = local_888 + iVar7;

        acStack_808[iVar7] = *pcVar9;

        iVar7 = iVar7 + 1;

      } while (*pcVar9 != '\0');

      piVar1 = (int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8);

      iVar7 = FUN_005122c0();

      iVar8 = (**(code **)(*piVar1 + 0x27c))();

      iVar7 = iVar7 - iVar8;

      uVar5 = FUN_007a6de0("Level Diff",0xffffffff);

      sprintf(local_888,"%s: %i\n",uVar5,iVar7);

      pcVar9 = local_888;

      do {

        cVar3 = *pcVar9;

        pcVar9 = pcVar9 + 1;

      } while (cVar3 != '\0');

      uVar10 = (int)pcVar9 - (int)local_888;

      pcVar9 = &cStack_809;

      do {

        pcVar11 = pcVar9 + 1;

        pcVar9 = pcVar9 + 1;

      } while (*pcVar11 != '\0');

      pcVar11 = local_888;

      for (uVar12 = uVar10 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {

        *(uint32_t /* width from decompiler */ *)pcVar9 = *(uint32_t /* width from decompiler */ *)pcVar11;

        pcVar11 = pcVar11 + 4;

        pcVar9 = pcVar9 + 4;

      }

      for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {

        *pcVar9 = *pcVar11;

        pcVar11 = pcVar11 + 1;

        pcVar9 = pcVar9 + 1;

      }

      iVar8 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x19c))();

      iVar7 = *(int *)(*(int *)(iVar8 + 4) + 4);

      uVar5 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar8 + 4) + 4) + 4 + iVar8) + 0x244))();

      uVar5 = (**(code **)(*(int *)(iVar7 + 4 + iVar8) + 0x23c))(uVar5);

      uVar6 = FUN_007a6de0(&DAT_00a2dbbc,0xffffffff);

      sprintf(local_888,"%s: %i/%i\n",uVar6,uVar5);

      pcVar9 = local_888;

      do {

        cVar3 = *pcVar9;

        pcVar9 = pcVar9 + 1;

      } while (cVar3 != '\0');

      uVar10 = (int)pcVar9 - (int)local_888;

      pcVar9 = &cStack_809;

      do {

        pcVar11 = pcVar9 + 1;

        pcVar9 = pcVar9 + 1;

      } while (*pcVar11 != '\0');

      pcVar11 = local_888;

      for (uVar12 = uVar10 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {

        *(uint32_t /* width from decompiler */ *)pcVar9 = *(uint32_t /* width from decompiler */ *)pcVar11;

        pcVar11 = pcVar11 + 4;

        pcVar9 = pcVar9 + 4;

      }

      sVar2 = *(short *)(iVar4 + 0x12e);

      for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {

        *pcVar9 = *pcVar11;

        pcVar11 = pcVar11 + 1;

        pcVar9 = pcVar9 + 1;

      }

      iVar8 = (int)sVar2;

      iVar7 = (int)*(short *)(iVar4 + 300);

      uVar5 = FUN_007a6de0(&DAT_00a6e4d0,0xffffffff);

      sprintf(local_888,"%s: %i/%i\n",uVar5,iVar7,iVar8);

      pcVar9 = local_888;

      do {

        cVar3 = *pcVar9;

        pcVar9 = pcVar9 + 1;

      } while (cVar3 != '\0');

      uVar10 = (int)pcVar9 - (int)local_888;

      pcVar9 = &cStack_809;

      do {

        pcVar11 = pcVar9 + 1;

        pcVar9 = pcVar9 + 1;

      } while (*pcVar11 != '\0');

      pcVar11 = local_888;

      for (uVar12 = uVar10 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {

        *(uint32_t /* width from decompiler */ *)pcVar9 = *(uint32_t /* width from decompiler */ *)pcVar11;

        pcVar11 = pcVar11 + 4;

        pcVar9 = pcVar9 + 4;

      }

      for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {

        *pcVar9 = *pcVar11;

        pcVar11 = pcVar11 + 1;

        pcVar9 = pcVar9 + 1;

      }

      pcVar11 = (char *)FUN_007a6de0("Resists: ",0xffffffff);

      pcVar9 = pcVar11;

      do {

        cVar3 = *pcVar9;

        pcVar9 = pcVar9 + 1;

      } while (cVar3 != '\0');

      pcVar14 = &cStack_809;

      do {

        pcVar13 = pcVar14 + 1;

        pcVar14 = pcVar14 + 1;

      } while (*pcVar13 != '\0');

      pcVar13 = pcVar11;

      for (uVar10 = (uint)((int)pcVar9 - (int)pcVar11) >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {

        *(uint32_t /* width from decompiler */ *)pcVar14 = *(uint32_t /* width from decompiler */ *)pcVar13;

        pcVar13 = pcVar13 + 4;

        pcVar14 = pcVar14 + 4;

      }

      sVar2 = *(short *)(iVar4 + 0x1ac);

      for (uVar10 = (int)pcVar9 - (int)pcVar11 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {

        *pcVar14 = *pcVar13;

        pcVar13 = pcVar13 + 1;

        pcVar14 = pcVar14 + 1;

      }

      if (sVar2 != 0) {

        pcVar11 = (char *)FUN_007a6de0("Physical ",0xffffffff);

        pcVar9 = pcVar11;

        do {

          cVar3 = *pcVar9;

          pcVar9 = pcVar9 + 1;

        } while (cVar3 != '\0');

        pcVar14 = &cStack_809;

        do {

          pcVar13 = pcVar14 + 1;

          pcVar14 = pcVar14 + 1;

        } while (*pcVar13 != '\0');

        pcVar13 = pcVar11;

        for (uVar10 = (uint)((int)pcVar9 - (int)pcVar11) >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {

          *(uint32_t /* width from decompiler */ *)pcVar14 = *(uint32_t /* width from decompiler */ *)pcVar13;

          pcVar13 = pcVar13 + 4;

          pcVar14 = pcVar14 + 4;

        }

        for (uVar10 = (int)pcVar9 - (int)pcVar11 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {

          *pcVar14 = *pcVar13;

          pcVar13 = pcVar13 + 1;

          pcVar14 = pcVar14 + 1;

        }

      }

      if (*(short *)(iVar4 + 0x1ae) != 0) {

        pcVar11 = (char *)FUN_007a6de0("Fire ",0xffffffff);

        pcVar9 = pcVar11;

        do {

          cVar3 = *pcVar9;

          pcVar9 = pcVar9 + 1;

        } while (cVar3 != '\0');

        pcVar14 = &cStack_809;

        do {

          pcVar13 = pcVar14 + 1;

          pcVar14 = pcVar14 + 1;

        } while (*pcVar13 != '\0');

        pcVar13 = pcVar11;

        for (uVar10 = (uint)((int)pcVar9 - (int)pcVar11) >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {

          *(uint32_t /* width from decompiler */ *)pcVar14 = *(uint32_t /* width from decompiler */ *)pcVar13;

          pcVar13 = pcVar13 + 4;

          pcVar14 = pcVar14 + 4;

        }

        for (uVar10 = (int)pcVar9 - (int)pcVar11 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {

          *pcVar14 = *pcVar13;

          pcVar13 = pcVar13 + 1;

          pcVar14 = pcVar14 + 1;

        }

      }

      if (*(short *)(iVar4 + 0x1b2) != 0) {

        pcVar11 = (char *)FUN_007a6de0("Corrosive ",0xffffffff);

        pcVar9 = pcVar11;

        do {

          cVar3 = *pcVar9;

          pcVar9 = pcVar9 + 1;

        } while (cVar3 != '\0');

        pcVar14 = &cStack_809;

        do {

          pcVar13 = pcVar14 + 1;

          pcVar14 = pcVar14 + 1;

        } while (*pcVar13 != '\0');

        pcVar13 = pcVar11;

        for (uVar10 = (uint)((int)pcVar9 - (int)pcVar11) >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {

          *(uint32_t /* width from decompiler */ *)pcVar14 = *(uint32_t /* width from decompiler */ *)pcVar13;

          pcVar13 = pcVar13 + 4;

          pcVar14 = pcVar14 + 4;

        }

        for (uVar10 = (int)pcVar9 - (int)pcVar11 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {

          *pcVar14 = *pcVar13;

          pcVar13 = pcVar13 + 1;

          pcVar14 = pcVar14 + 1;

        }

      }

      if (*(short *)(iVar4 + 0x1b4) != 0) {

        pcVar11 = (char *)FUN_007a6de0("Contamination ",0xffffffff);

        pcVar9 = pcVar11;

        do {

          cVar3 = *pcVar9;

          pcVar9 = pcVar9 + 1;

        } while (cVar3 != '\0');

        pcVar14 = &cStack_809;

        do {

          pcVar13 = pcVar14 + 1;

          pcVar14 = pcVar14 + 1;

        } while (*pcVar13 != '\0');

        pcVar13 = pcVar11;

        for (uVar10 = (uint)((int)pcVar9 - (int)pcVar11) >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {

          *(uint32_t /* width from decompiler */ *)pcVar14 = *(uint32_t /* width from decompiler */ *)pcVar13;

          pcVar13 = pcVar13 + 4;

          pcVar14 = pcVar14 + 4;

        }

        for (uVar10 = (int)pcVar9 - (int)pcVar11 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {

          *pcVar14 = *pcVar13;

          pcVar13 = pcVar13 + 1;

          pcVar14 = pcVar14 + 1;

        }

      }

      if (*(short *)(iVar4 + 0x1b6) != 0) {

        pcVar11 = (char *)FUN_007a6de0("Energy ",0xffffffff);

        pcVar9 = pcVar11;

        do {

          cVar3 = *pcVar9;

          pcVar9 = pcVar9 + 1;

        } while (cVar3 != '\0');

        pcVar14 = &cStack_809;

        do {

          pcVar13 = pcVar14 + 1;

          pcVar14 = pcVar14 + 1;

        } while (*pcVar13 != '\0');

        pcVar13 = pcVar11;

        for (uVar10 = (uint)((int)pcVar9 - (int)pcVar11) >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {

          *(uint32_t /* width from decompiler */ *)pcVar14 = *(uint32_t /* width from decompiler */ *)pcVar13;

          pcVar13 = pcVar13 + 4;

          pcVar14 = pcVar14 + 4;

        }

        for (uVar10 = (int)pcVar9 - (int)pcVar11 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {

          *pcVar14 = *pcVar13;

          pcVar13 = pcVar13 + 1;

          pcVar14 = pcVar14 + 1;

        }

      }

      pcVar9 = &cStack_809;

      do {

        pcVar11 = pcVar9 + 1;

        pcVar9 = pcVar9 + 1;

      } while (*pcVar11 != '\0');

      *(uint16_t *)pcVar9 = DAT_00a15104;

      pcVar11 = (char *)FUN_007a6de0("Skills: ",0xffffffff);

      pcVar9 = pcVar11;

      do {

        cVar3 = *pcVar9;

        pcVar9 = pcVar9 + 1;

      } while (cVar3 != '\0');

      pcVar14 = &cStack_809;

      do {

        pcVar13 = pcVar14 + 1;

        pcVar14 = pcVar14 + 1;

      } while (*pcVar13 != '\0');

      pcVar13 = pcVar11;

      for (uVar10 = (uint)((int)pcVar9 - (int)pcVar11) >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {

        *(uint32_t /* width from decompiler */ *)pcVar14 = *(uint32_t /* width from decompiler */ *)pcVar13;

        pcVar13 = pcVar13 + 4;

        pcVar14 = pcVar14 + 4;

      }

      iVar7 = *(int *)(iVar4 + 4);

      for (uVar10 = (int)pcVar9 - (int)pcVar11 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {

        *pcVar14 = *pcVar13;

        pcVar13 = pcVar13 + 1;

        pcVar14 = pcVar14 + 1;

      }

      if (*(int *)(*(int *)(*(int *)(*(int *)(iVar7 + 4) + 0xac + iVar4) + 0x3c) + 0x3bc) != -1) {

        iVar7 = *(int *)(*(int *)(iVar4 + 4) + 4);

        (**(code **)(*(int *)(iVar7 + iVar4 + 4) + 0x234))

                  (*(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar7 + 0xac + iVar4) + 0x3c) + 0x3bc));

        FUN_00837cd0();

      }

      if (*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 0xac + iVar4) + 0x3c) +

                  0x3c0) != -1) {

        iVar7 = *(int *)(*(int *)(iVar4 + 4) + 4);

        (**(code **)(*(int *)(iVar7 + iVar4 + 4) + 0x234))

                  (*(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar7 + 0xac + iVar4) + 0x3c) + 0x3c0));

        FUN_00837cd0();

      }

      if (*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 0xac + iVar4) + 0x3c) +

                  0x3c4) != -1) {

        iVar7 = *(int *)(*(int *)(iVar4 + 4) + 4);

        (**(code **)(*(int *)(iVar7 + iVar4 + 4) + 0x234))

                  (*(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar7 + 0xac + iVar4) + 0x3c) + 0x3c4));

        FUN_00837cd0();

      }

      pcVar9 = &cStack_809;

      do {

        pcVar11 = pcVar9 + 1;

        pcVar9 = pcVar9 + 1;

      } while (*pcVar11 != '\0');

      uVar15 = 0;

      uVar6 = 0;

      *(uint16_t *)pcVar9 = DAT_00a15104;

      uVar5 = FUN_007a6de0("Damage",0xffffffff);

      sprintf(local_888,"%s: %i-%i\n",uVar5,uVar6,uVar15);

      pcVar9 = local_888;

      do {

        cVar3 = *pcVar9;

        pcVar9 = pcVar9 + 1;

      } while (cVar3 != '\0');

      uVar10 = (int)pcVar9 - (int)local_888;

      pcVar9 = &cStack_809;

      do {

        pcVar11 = pcVar9 + 1;

        pcVar9 = pcVar9 + 1;

      } while (*pcVar11 != '\0');

      pcVar11 = local_888;

      for (uVar12 = uVar10 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {

        *(uint32_t /* width from decompiler */ *)pcVar9 = *(uint32_t /* width from decompiler */ *)pcVar11;

        pcVar11 = pcVar11 + 4;

        pcVar9 = pcVar9 + 4;

      }

      for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {

        *pcVar9 = *pcVar11;

        pcVar11 = pcVar11 + 1;

        pcVar9 = pcVar9 + 1;

      }

    }

  }

  return;

}

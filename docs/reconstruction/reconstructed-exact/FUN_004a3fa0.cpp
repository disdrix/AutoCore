// =============================================================================
// FUN_004a3fa0
// -----------------------------------------------------------------------------
// Stable ID: aa_004a3fa0
// Address:   0x004a3fa0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004a3fa0 @ 0x004a3fa0
// Stable ID: aa_004a3fa0
// Embedded strings (evidence for future rename):
//   - "VOG_DEBUG_STOP"
//   - "onlyNonPhysX"
//   - "filename"
//   - "numberOfGeos"
//   - "loopingKeyframe"
//   - "duration"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~500 non-empty decompiler lines.
//  - Control keywords: if×61, goto×9, return×6, for×2, do×1, while×1.
//  - Notable callees: FUN_007996d0×10, FUN_00799300×9, FUN_004a6910×5, SysFreeString×5, FUN_005be2f0×4, FUN_00691630×4, CONCAT31×3, FUN_004a79e0×3.
//  - Strings: "VOG_DEBUG_STOP"; "onlyNonPhysX"; "filename"; "numberOfGeos".
//  - Return sites: 6.

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

/* WARNING: Removing unreachable block (ram,0x004a42bf) */

/* WARNING: Removing unreachable block (ram,0x004a4348) */



uint8_t * FUN_004a3fa0(int *param_1)



{

  uint8_t *puVar1;

  int *piVar2;

  ushort uVar3;

  float fVar4;

  char cVar5;

  char cVar6;

  byte bVar7;

  uint16_t uVar8;

  uint8_t *puVar9;

  uint32_t /* width from decompiler */ uVar10;

  float *pfVar11;

  int **ppiVar12;

  int iVar13;

  int iVar14;

  int *unaff_EBX;

  uint unaff_EDI;

  uint32_t /* width from decompiler */ *puVar15;

  code *pcVar16;

  void *pvVar17;

  int unaff_retaddr;

  int *piVar18;

  int *piVar19;

  BSTR pOStack_300;

  uint32_t /* width from decompiler */ local_2fc;

  BSTR local_2f8;

  int *piStack_2f4;

  uint32_t /* width from decompiler */ uStack_2f0;

  uint32_t /* width from decompiler */ uStack_2ec;

  int *piStack_2e8;

  char cStack_2e1;

  void *apvStack_2e0 [2];

  void *pvStack_2d8;

  int iStack_2d4;

  int iStack_2d0;

  int iStack_2cc;

  uint8_t auStack_2c8 [8];

  uint32_t /* width from decompiler */ uStack_2c0;

  uint uStack_2bc;

  uint32_t /* width from decompiler */ uStack_2b8;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_2b4 [28];

  char *pcStack_298;

  char acStack_294 [128];

  uint8_t auStack_214 [8];

  uint32_t /* width from decompiler */ local_20c;

  uint32_t /* width from decompiler */ local_208 [125];

  void *pvStack_14;

  void *local_c;

  uint8_t *puStack_8;

  int *local_4;

  

  puStack_8 = &LAB_009a110c;

  local_c = ExceptionList;

  local_2f8 = (BSTR)0x0;

  local_20c = 0;

  puVar15 = local_208;

  for (iVar14 = 0x7f; iVar14 != 0; iVar14 = iVar14 + -1) {

    *puVar15 = 0;

    puVar15 = puVar15 + 1;

  }

  local_4 = (int *)0x0;

  local_2b4[0] = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>)0x1;

  if (param_1 == (int *)0x0) {

    ExceptionList = &local_c;

    FUN_007a4480(0,"VOG_DEBUG_STOP");

    SysFreeString(local_2f8);

    ExceptionList = local_c;

    return (uint8_t *)0x0;

  }

  piVar19 = &local_2fc;

  ExceptionList = &local_c;

  piVar18 = param_1;

  iVar14 = (**(code **)(*param_1 + 0x44))();

  if ((iVar14 != 0) || (unaff_EBX == (int *)0x0)) {

    FUN_007a4480(0,"VOG_DEBUG_STOP");

    SysFreeString(pOStack_300);

    ExceptionList = pvStack_14;

    return (uint8_t *)0x0;

  }

  puVar9 = (uint8_t *)FUN_005be400();

  puVar9[0x90e] = puVar9[0x90e] | 8;

  puVar1 = puVar9 + 0x34;

  *(int **)(puVar9 + 0x904) = param_1;

  *(uint32_t /* width from decompiler */ *)(puVar9 + 0x908) = 0;

  puVar9[0x911] = 1;

  *(uint8_t **)(puVar9 + 0x38) = puVar1;

  *(uint8_t **)puVar1 = puVar1;

  cVar5 = FUN_007996d0(unaff_EBX,L"onlyNonPhysX",&stack0xfffffcfb);

  if (((cVar5 == '\0') || ((char)(unaff_EDI >> 0x18) != '\x01')) ||

     (cVar5 = FUN_004a6910(), cVar5 == '\0')) {

    FUN_00798bb0(unaff_EBX,L"filename",auStack_214);

    pcStack_298 = acStack_294;

    uVar10 = (*(code *)PTR_FUN_00af8c9c)();

    FUN_00403450(auStack_214,uVar10);

    strncpy(puVar9 + 0x33d,pcStack_298,0x7e);

    if (pcStack_298 != acStack_294) {

      free(pcStack_298);

    }

    *(uint16_t *)(puVar9 + 700) = 1;

    puVar9[0x90e] = puVar9[0x90e] ^ ((puVar9[0x33d] == '_') << 6 ^ puVar9[0x90e]) & 0x40U;

    cVar5 = FUN_007998d0(unaff_EBX,L"numberOfGeos",puVar9 + 700,10);

    if (cVar5 != '\0') {

      unaff_EDI = unaff_EDI & 0xffffff;

    }

    FUN_007996d0(unaff_EBX,L"loopingKeyframe",&stack0xfffffcfb);

    cVar5 = (char)(unaff_EDI >> 0x18);

    if (cVar5 != '\0') {

      puVar9[0x911] = 0;

    }

    puVar9[0x90e] = puVar9[0x90e] ^ (cVar5 << 4 ^ puVar9[0x90e]) & 0x10U;

    FUN_00799300(unaff_EBX,L"duration",puVar9 + 0x790);

    uStack_2c0 = 0;

    cStack_2e1 = FUN_00799300(unaff_EBX,L"deathFadeTime",&uStack_2c0);

    if (cStack_2e1 != '\0') {

      *(uint32_t /* width from decompiler */ *)(puVar9 + 0x798) = uStack_2c0;

    }

    FUN_007996d0(unaff_EBX,L"deleteIfCulled",puVar9 + 0x794);

    FUN_007994c0(unaff_EBX,L"offset",puVar9 + 0x860,puVar9 + 0x86c,puVar9 + 0x878,0);

    FUN_007996d0(unaff_EBX,L"useOwnerGfx",&stack0xfffffcfb);

    puVar9[0x90e] = puVar9[0x90e] ^ puVar9[0x90e] & 0x20;

    puVar9[0x90c] = puVar9[0x90c] & 0xfe;

    FUN_007996d0(unaff_EBX,L"skybox",&stack0xfffffcfb);

    puVar9[0x90c] = puVar9[0x90c] ^ puVar9[0x90c] & 2;

    puVar9[0x90c] = puVar9[0x90c] & 0xfe;

    FUN_00799300(unaff_EBX,L"treeStartPercent",puVar9 + 0x8d4);

    FUN_007996d0(unaff_EBX,L"lockToBody",&stack0xfffffcfb);

    puVar9[0x90f] = puVar9[0x90f] ^ puVar9[0x90f] & 0x20;

    FUN_007996d0(unaff_EBX,L"HACKDontMoveToBodyOnDeath",&stack0xfffffcfb);

    *puVar9 = 0;

    FUN_007996d0(unaff_EBX,L"offsetWorld",&stack0xfffffcfb);

    puVar9[0x8dc] = 0;

    FUN_007996d0(unaff_EBX,L"ignoreObjectScale",&stack0xfffffcfb);

    puVar9[0x90f] = puVar9[0x90f] & 0x7f;

    cVar5 = FUN_00799460(unaff_EBX,L"CPAttacherID",puVar9 + 0x254,10);

    cVar6 = FUN_00799460(unaff_EBX,L"CPAttacheeID",puVar9 + 600,10);

    if ((cVar5 != '\0') && (cVar6 != '\0')) {

      puVar9[0x90e] = puVar9[0x90e] | 0x80;

      puVar9[0x911] = 0;

    }

    piVar2 = (int *)(puVar9 + 0x25c);

    *piVar2 = -1;

    FUN_00799460(unaff_EBX,L"lAltConnection",piVar2,10);

    if (3 < *piVar2) {

      *piVar2 = -1;

    }

    fVar4 = g_flOne;

    puVar15 = (uint32_t /* width from decompiler */ *)(puVar9 + 0x8a4);

    local_2fc._3_1_ = '\0';

    uStack_2f0 = (int *)((uint)uStack_2f0 & 0xffffff);

    *puVar15 = 0;

    *(float *)(puVar9 + 0x8a8) = fVar4;

    *(uint32_t /* width from decompiler */ *)(puVar9 + 0x8ac) = 0;

    local_2fc._2_1_ =

         FUN_007995a0(unaff_EBX,&iStack_2cc,L"orientationAxis",puVar15,puVar9 + 0x8b0,

                      (int)&local_2fc + 3,(int)&uStack_2f0 + 3);

    FUN_005b8370(iStack_2cc,0xc,puVar15,puVar9);

    puVar9[0x90d] = puVar9[0x90d] ^ (local_2fc._3_1_ << 6 ^ puVar9[0x90d]) & 0x40U;

    local_2fc._3_1_ = '\0';

    uStack_2f0 = (int *)((uint)uStack_2f0 & 0xffffff);

    *(uint32_t /* width from decompiler */ *)(puVar9 + 0x8bc) = 0;

    cVar5 = FUN_00798f30(unaff_EBX,&iStack_2cc,L"orientationAngle",puVar9 + 0x8bc,puVar9 + 0x8c0,

                         (int)&local_2fc + 3);

    FUN_005b8370(iStack_2cc,4,puVar9 + 0x8c0,puVar9);

    if ((cVar5 == '\0') && (local_2fc._2_1_ == '\0')) {

      cVar5 = '\0';

    }

    else {

      cVar5 = '\x01';

    }

    puVar9[0x90d] = puVar9[0x90d] ^ (cVar5 << 5 ^ puVar9[0x90d]) & 0x20U;

    puVar9[0x90d] = puVar9[0x90d] & 0x7f | local_2fc._3_1_ << 7;

    cVar5 = FUN_00798bb0(unaff_EBX,L"ragdoll",auStack_214);

    pcStack_298 = acStack_294;

    uVar10 = (*(code *)PTR_FUN_00af8c9c)();

    FUN_00403450(auStack_214,uVar10);

    strncpy(puVar9 + 0x1d0,pcStack_298,0x7e);

    if (pcStack_298 != acStack_294) {

      free(pcStack_298);

    }

    puVar9[0x90d] = puVar9[0x90d] ^ (cVar5 * '\x04' ^ puVar9[0x90d]) & 4U;

    if (cVar5 != '\0') {

      puVar9[0x911] = 0;

    }

    cVar5 = FUN_00799300(unaff_EBX,L"physxStartDelay",&uStack_2b8);

    if (cVar5 != '\0') {

      *(uint32_t /* width from decompiler */ *)(puVar9 + 0xbc) = uStack_2b8;

    }

    cVar5 = FUN_007996d0(unaff_EBX,L"dontKillParent",&stack0xfffffcfb);

    if (cVar5 != '\0') {

      puVar9[0x910] = puVar9[0x910] ^ puVar9[0x910] & 8;

    }

    *(int *)(puVar9 + 0x14) = unaff_retaddr;

    pvStack_2d8 = (void *)0x0;

    iStack_2d4 = 0;

    iStack_2d0 = 0;

    local_c = (void *)CONCAT31(local_c._1_3_,1);

    uStack_2ec = (int *)0x0;

    (**(code **)(*local_4 + 0x30))(local_4,&uStack_2ec);

    if (uStack_2ec != (int *)0x0) {

      (**(code **)(*uStack_2ec + 0x20))(uStack_2ec,auStack_2c8);

      iStack_2cc = 0;

      pvVar17 = (void *)0x0;

      pcVar16 = _wcsicmp_exref;

      if (0 < iStack_2d0) {

        do {

          iVar14 = (**(code **)(*piStack_2f4 + 0x1c))(piStack_2f4,iStack_2cc,&pOStack_300);

          if ((iVar14 < 0) || (local_2f8 == (BSTR)0x0)) {

            FUN_007a4480(0,"VOG_DEBUG_STOP");

            pvVar17 = pvStack_2d8;

            if (pvStack_2d8 == (void *)0x0) goto LAB_004a4ca4;

            goto LAB_004a4c97;

          }

          SysFreeString(pOStack_300);

          pOStack_300 = (BSTR)0x0;

          (**(code **)(*(int *)local_2f8 + 0x1c))(local_2f8,&pOStack_300);

          iVar14 = (*pcVar16)(L"Include",unaff_EDI & 0xffffff);

          if (iVar14 == 0) {

            cVar5 = FUN_0049f9a0(local_2f8,&uStack_2ec,auStack_2c8);

            if (cVar5 == '\0') {

              FUN_005be2f0(puVar9);

              if (local_2f8 != (BSTR)0x0) {

                (**(code **)(*(int *)local_2f8 + 8))(local_2f8);

                local_2f8 = (BSTR)0x0;

              }

              if (uStack_2ec != (int *)0x0) {

                (**(code **)(*uStack_2ec + 8))(uStack_2ec);

                uStack_2ec = (int *)0x0;

              }

              if (unaff_EBX != (int *)0x0) {

                (**(code **)(*unaff_EBX + 8))(unaff_EBX);

              }

              FUN_00691630();

              goto LAB_004a4ca4;

            }

          }

          else {

            iVar14 = (*pcVar16)(L"Keyframe",pOStack_300);

            if (iVar14 == 0) {

              cVar5 = FUN_004a0630(puVar9,local_2f8,uStack_2bc);

              if (cVar5 == '\0') goto LAB_004a4c3c;

              *(uint32_t /* width from decompiler */ *)(puVar9 + 0x788) = *(uint32_t /* width from decompiler */ *)(puVar9 + 0x3bc);

              if ((puVar9[0x5a0] & 4) != 0) {

                iVar14 = CVOGReaction_RandomUnitScalar();

                if (0xfffff < *(int *)(iVar14 + 0xc)) {

                  *(uint32_t /* width from decompiler */ *)(iVar14 + 0xc) = 0;

                }

                uVar3 = *(ushort *)(*(int *)(iVar14 + 8) + *(int *)(iVar14 + 0xc) * 2);

                *(int *)(iVar14 + 0xc) = *(int *)(iVar14 + 0xc) + 1;

                *(float *)(puVar9 + 0x788) =

                     (float)uVar3 * *(float *)(puVar9 + 0x3c0) * DAT_00aaa638 +

                     *(float *)(puVar9 + 0x788);

              }

              *(uint32_t /* width from decompiler */ *)(puVar9 + 0x78c) = *(uint32_t /* width from decompiler */ *)(puVar9 + 0x788);

              uStack_2bc = uStack_2bc & 0xffffff00;

            }

            else {

              iVar14 = (*pcVar16)(L"Particle",pOStack_300);

              if (iVar14 == 0) {

                cVar5 = FUN_004a34f0(local_2f8,unaff_retaddr,apvStack_2e0);

                if (cVar5 == '\0') {

                  FUN_00691630();

                  goto LAB_004a4ca4;

                }

                if (apvStack_2e0[0] != (void *)0x0) {

                  *(int *)((int)apvStack_2e0[0] + 4) = unaff_retaddr;

                  *(uint8_t **)((int)apvStack_2e0[0] + 8) = puVar9;

                  FUN_004a79e0(apvStack_2e0);

                }

              }

              else {

                iVar14 = (*pcVar16)(L"Trail",pOStack_300);

                if (iVar14 == 0) {

                  piStack_2e8 = (int *)FUN_0049e540(local_2f8,unaff_retaddr);

                  if (piStack_2e8 == (int *)0x0) {

LAB_004a4c70:

                    FUN_00691630();

                    goto LAB_004a4ca4;

                  }

                  *piStack_2e8 = unaff_retaddr;

                  piStack_2e8[1] = (int)puVar9;

                  FUN_004a79e0(&piStack_2e8);

                  puVar9[0x911] = 0;

                }

                else {

                  iVar14 = (*pcVar16)(L"Lightning",pOStack_300);

                  if (iVar14 == 0) {

                    piStack_2e8 = (int *)FUN_0049e830(local_2f8,unaff_retaddr);

                    if (piStack_2e8 == (int *)0x0) goto LAB_004a4c3c;

                    *piStack_2e8 = unaff_retaddr;

                    piStack_2e8[1] = (int)puVar9;

                    FUN_004a79e0(&piStack_2e8);

                  }

                  else {

                    iVar14 = (*pcVar16)(L"Light",pOStack_300);

                    if (iVar14 == 0) {

                      iVar14 = (**(code **)(*(int *)local_2f8 + 0x44))(local_2f8,&piStack_2f4);

                      if ((-1 < iVar14) && (piStack_2f4 != (int *)0x0)) {

                        puVar9[0x90f] = puVar9[0x90f] | 2;

                        FUN_00798d00(piStack_2f4,L"color",puVar9 + 0x8e0);

                        FUN_00799300(piStack_2f4,L"radius",puVar9 + 0x8f0);

                        *(float *)(puVar9 + 0x8f8) = g_flOne;

                        *(float *)(puVar9 + 0x8fc) = g_flMultiKillCountBlend;

                        FUN_00799300(piStack_2f4,L"atten1",puVar9 + 0x8f8);

                        FUN_00799300(piStack_2f4,L"atten2",puVar9 + 0x8fc);

                        cVar5 = FUN_00798d00(piStack_2f4,L"pulseEndColor",puVar9 + 0x8e4);

                        if (cVar5 != '\0') {

                          puVar9[0x90f] = puVar9[0x90f] | 4;

                        }

                        cVar5 = FUN_00799300(piStack_2f4,L"pulseEndRadius",puVar9 + 0x8f4);

                        if (cVar5 != '\0') {

                          puVar9[0x90f] = puVar9[0x90f] | 8;

                        }

                        FUN_00799300(piStack_2f4,L"pulseTime",puVar9 + 0x8e8);

                        *(uint32_t /* width from decompiler */ *)(puVar9 + 0x8ec) = *(uint32_t /* width from decompiler */ *)(puVar9 + 0x8e8);

                        (**(code **)(*piStack_2f4 + 8))(piStack_2f4);

                        pcVar16 = _wcsicmp_exref;

                      }

                    }

                    else {

                      iVar14 = (*pcVar16)(L"RigidBody",pOStack_300);

                      if ((iVar14 == 0) && ((puVar9[0x90c] & 2) == 0)) {

                        FUN_0049fcd0(puVar9,local_2f8,1);

                      }

                      else {

                        iVar14 = (*pcVar16)(L"Cloth",pOStack_300);

                        if ((iVar14 == 0) && ((puVar9[0x90c] & 2) == 0)) {

                          cVar5 = FUN_004a6910();

                          if ((cVar5 == '\0') || (DAT_00af06ea == '\0')) {

LAB_004a4c47:

                            FUN_005be2f0(puVar9);

                            (**(code **)(*(int *)local_2f8 + 8))(local_2f8);

                            (**(code **)(*uStack_2f0 + 8))(uStack_2f0);

                            (**(code **)(*piVar19 + 8))(piVar19);

                            goto LAB_004a4c70;

                          }

                          FUN_004a1f20(puVar9,local_2f8);

                        }

                        else {

                          iVar14 = (*pcVar16)(L"PhysXBody",pOStack_300);

                          if ((iVar14 == 0) && ((puVar9[0x90c] & 2) == 0)) {

                            cVar5 = FUN_004a6910();

                            if ((cVar5 == '\0') || (DAT_00af06e9 == '\0')) goto LAB_004a4c47;

                            FUN_0049fcd0(puVar9,local_2f8,0);

                          }

                          else {

                            iVar14 = (*pcVar16)(L"Geometry",pOStack_300);

                            if ((iVar14 == 0) && ((puVar9[0x90c] & 2) == 0)) {

                              cVar5 = FUN_004a6910();

                              if (((cVar5 != '\0') && (DAT_00af06e9 != '\0')) &&

                                 (piStack_2e8 = (int *)FUN_004a3fa0(local_2f8,unaff_retaddr,param_1)

                                 , piStack_2e8 != (int *)0x0)) {

                                FUN_004a7a20(&piStack_2e8);

                              }

                            }

                            else {

                              iVar14 = (*pcVar16)(L"VolumeEmitter",pOStack_300);

                              if (((iVar14 == 0) && ((puVar9[0x90c] & 2) == 0)) &&

                                 (cVar5 = FUN_004a6910(), cVar5 != '\0')) {

                                pfVar11 = operator_new(4);

                                if (pfVar11 == (float *)0x0) {

                                  pfVar11 = (float *)0x0;

                                }

                                else {

                                  *pfVar11 = g_flOne;

                                }

                                *(float **)(puVar9 + 0xe0) = pfVar11;

                                FUN_0049d930(puVar9,local_2f8,pfVar11);

                              }

                            }

                          }

                        }

                      }

                    }

                  }

                }

              }

            }

          }

          (**(code **)(*(int *)local_2f8 + 8))(local_2f8);

          iStack_2cc = iStack_2cc + 1;

          pvVar17 = apvStack_2e0[0];

        } while (iStack_2cc < iStack_2d0);

      }

      if (uStack_2ec._3_1_ == '\0') {

        uVar10 = 0;

        if ((puVar9[0x90c] & 0x80) != 0) {

          uVar10 = DAT_00aaa68c;

        }

        *(uint32_t /* width from decompiler */ *)(puVar9 + 0x798) = uVar10;

      }

      (**(code **)(*piStack_2f4 + 8))(piStack_2f4);

      (**(code **)(*piVar18 + 8))(piVar18);

      if ((pvVar17 == (void *)0x0) ||

         (apvStack_2e0[0] = (void *)(iStack_2d4 - (int)pvVar17 >> 2), apvStack_2e0[0] == (void *)0x0

         )) {

        FUN_004b8890(puVar9);

        if (pvVar17 == (void *)0x0) {

          SysFreeString(pOStack_300);

          ExceptionList = pvStack_14;

          return puVar9;

        }

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar17);

      }

      if ((puVar9[0x90c] & 0x80) == 0) {

        FUN_005be2f0(puVar9);

      }

      else {

        local_2fc._2_1_ = '\0';

        for (piStack_2f4 = (int *)0x0; (int)piStack_2f4 < (int)apvStack_2e0[0];

            piStack_2f4 = (int *)((int)piStack_2f4 + 1)) {

          iVar14 = *(int *)((int)pvStack_2d8 + (int)piStack_2f4 * 4);

          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

          basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_2b4);

          local_c = (void *)CONCAT31(local_c._1_3_,2);

          FUN_00559be0(unaff_retaddr + 0xd5,puVar9 + 0x2be,iVar14 + 0x2be,local_2b4);

          piStack_2e8 = (int *)g_flOne;

          **(float **)(iVar14 + 0xe0) = DAT_00aefb3c * **(float **)(iVar14 + 0xe0);

          ppiVar12 = *(int ***)(iVar14 + 0xe0);

          if (ppiVar12 == (int **)0x0) {

            ppiVar12 = &piStack_2e8;

          }

          iVar13 = FUN_0055b270(local_2b4,puVar9 + 0x2be,iVar14 + 0x2be,ppiVar12);

          if (iVar13 != 0) {

            if ((*(byte *)(iVar14 + 0x910) & 8) != 0) {

              local_2fc._2_1_ = '\x01';

            }

            if (g_flZero < *(float *)(iVar14 + 0xbc)) {

              local_2fc._2_1_ = '\x01';

              FUN_00787310(iVar13);

              FUN_0058e1f0(*(uint32_t /* width from decompiler */ *)(iVar14 + 0xbc));

            }

            *(int *)(iVar14 + 0xdc) = iVar13;

            uVar8 = 0;

            if (*(int *)(iVar13 + 0x18) != 0) {

              uVar8 = (uint16_t)((*(int *)(iVar13 + 0x1c) - *(int *)(iVar13 + 0x18)) / 0x1c);

            }

            *(uint16_t *)(iVar14 + 700) = uVar8;

            *(uint32_t /* width from decompiler */ *)(iVar14 + 0x860) = *(uint32_t /* width from decompiler */ *)(puVar9 + 0x860);

            *(uint32_t /* width from decompiler */ *)(iVar14 + 0x864) = *(uint32_t /* width from decompiler */ *)(puVar9 + 0x864);

            *(uint32_t /* width from decompiler */ *)(iVar14 + 0x868) = *(uint32_t /* width from decompiler */ *)(puVar9 + 0x868);

            *(uint32_t /* width from decompiler */ *)(iVar14 + 0x86c) = *(uint32_t /* width from decompiler */ *)(puVar9 + 0x86c);

            *(uint32_t /* width from decompiler */ *)(iVar14 + 0x870) = *(uint32_t /* width from decompiler */ *)(puVar9 + 0x870);

            *(uint32_t /* width from decompiler */ *)(iVar14 + 0x874) = *(uint32_t /* width from decompiler */ *)(puVar9 + 0x874);

            *(uint8_t *)(iVar14 + 0x878) = puVar9[0x878];

            if ((*(byte *)(iVar14 + 0x910) & 2) != 0) {

              *(uint32_t /* width from decompiler */ *)(iVar14 + 0x28c) = *(uint32_t /* width from decompiler */ *)(puVar9 + 0x28c);

              *(uint32_t /* width from decompiler */ *)(iVar14 + 0x290) = *(uint32_t /* width from decompiler */ *)(puVar9 + 0x290);

              *(uint32_t /* width from decompiler */ *)(iVar14 + 0x294) = *(uint32_t /* width from decompiler */ *)(puVar9 + 0x294);

              *(uint32_t /* width from decompiler */ *)(iVar14 + 0x298) = *(uint32_t /* width from decompiler */ *)(puVar9 + 0x298);

              *(uint32_t /* width from decompiler */ *)(iVar14 + 0x29c) = *(uint32_t /* width from decompiler */ *)(puVar9 + 0x29c);

              *(uint32_t /* width from decompiler */ *)(iVar14 + 0x2a0) = *(uint32_t /* width from decompiler */ *)(puVar9 + 0x2a0);

              *(byte *)(iVar14 + 0x90c) =

                   *(byte *)(iVar14 + 0x90c) ^ (puVar9[0x90c] ^ *(byte *)(iVar14 + 0x90c)) & 0x20;

              bVar7 = (puVar9[0x90c] ^ *(byte *)(iVar14 + 0x90c)) & 8 ^ *(byte *)(iVar14 + 0x90c);

              *(byte *)(iVar14 + 0x90c) = bVar7;

              *(byte *)(iVar14 + 0x90c) = (puVar9[0x90c] ^ bVar7) & 0x10 ^ bVar7;

            }

            if ((*(byte *)(iVar14 + 0x910) & 4) != 0) {

              *(uint32_t /* width from decompiler */ *)(iVar14 + 0x2a4) = *(uint32_t /* width from decompiler */ *)(puVar9 + 0x2a4);

              *(uint32_t /* width from decompiler */ *)(iVar14 + 0x2a8) = *(uint32_t /* width from decompiler */ *)(puVar9 + 0x2a8);

              *(uint32_t /* width from decompiler */ *)(iVar14 + 0x2ac) = *(uint32_t /* width from decompiler */ *)(puVar9 + 0x2ac);

              *(uint32_t /* width from decompiler */ *)(iVar14 + 0x2b0) = *(uint32_t /* width from decompiler */ *)(puVar9 + 0x2b0);

              *(uint32_t /* width from decompiler */ *)(iVar14 + 0x2b4) = *(uint32_t /* width from decompiler */ *)(puVar9 + 0x2b4);

              *(uint32_t /* width from decompiler */ *)(iVar14 + 0x2b8) = *(uint32_t /* width from decompiler */ *)(puVar9 + 0x2b8);

              *(byte *)(iVar14 + 0x90c) =

                   *(byte *)(iVar14 + 0x90c) ^ (puVar9[0x90c] ^ *(byte *)(iVar14 + 0x90c)) & 0x40;

              *(byte *)(iVar14 + 0x90c) =

                   (puVar9[0x90c] ^ *(byte *)(iVar14 + 0x90c)) & 4 ^ *(byte *)(iVar14 + 0x90c);

            }

          }

          local_c = (void *)CONCAT31(local_c._1_3_,1);

          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

          ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_2b4);

          pvVar17 = pvStack_2d8;

        }

        if (local_2fc._2_1_ != '\0') {

          FUN_004b8890(puVar9);

        }

      }

LAB_004a4c97:

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar17);

    }

LAB_004a4c3c:

    FUN_00691630();

  }

  else {

    FUN_005be2f0(puVar9);

    if (unaff_EBX != (int *)0x0) {

      (**(code **)(*unaff_EBX + 8))(unaff_EBX);

    }

  }

LAB_004a4ca4:

  SysFreeString(pOStack_300);

  ExceptionList = pvStack_14;

  return (uint8_t *)0x0;

}

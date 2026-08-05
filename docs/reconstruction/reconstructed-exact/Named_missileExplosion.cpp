// READABILITY (auto CF):
//  - Body size: ~378 non-empty decompiler lines.
//  - Control keywords: if×46, return×8, goto×4, for×2, do×1, while×1.
//  - Notable callees: wcsstr×13, FUN_007996d0×10, _wcsicmp×9, FUN_005be310×7, CONCAT12×5, FUN_00798bb0×5, SysFreeString×5, FUN_007a4480×3.
//  - Strings: "VOG_DEBUG_STOP"; "type"; "Billboard"; "Kite".
//  - Return sites: 8.

// =============================================================================
// Named_missileExplosion
// -----------------------------------------------------------------------------
// Stable ID: aa_004a34f0
// Address:   0x004a34f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "missileExplosion"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Named_missileExplosion(int *param_1,uint32_t /* width from decompiler */ param_2,int *param_3)



{

  float fVar1;

  char cVar2;

  int iVar3;

  wchar_t *pwVar4;

  long lVar5;

  int iVar6;

  int iVar7;

  BSTR unaff_EBX;

  BSTR unaff_EDI;

  uint32_t /* width from decompiler */ *puVar8;

  code *pcVar9;

  BSTR pOStack_244;

  uint32_t /* width from decompiler */ uStack_240;

  int *local_23c;

  char cStack_236;

  char acStack_235 [5];

  uint32_t /* width from decompiler */ uStack_230;

  byte bStack_22c;

  byte bStack_22b;

  char cStack_22a;

  char cStack_229;

  int *piStack_228;

  wchar_t *pwStack_224;

  int *piStack_220;

  uint8_t auStack_21c [4];

  wchar_t awStack_218 [2];

  uint32_t /* width from decompiler */ auStack_214 [121];

  void *pvStack_30;

  void *pvStack_28;

  void *pvStack_24;

  void *pvStack_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  

  uStack_c = 0xffffffff;

  puStack_10 = &LAB_009a10e0;

  pvStack_14 = ExceptionList;

  ExceptionList = &pvStack_14;

  *param_3 = 0;

  if (param_1 == (int *)0x0) {

LAB_004a3f6e:

    FUN_007a4480(0,"VOG_DEBUG_STOP");

    ExceptionList = pvStack_14;

    return 0;

  }

  local_23c = (int *)0x0;

  iVar3 = (**(code **)(*param_1 + 0x44))(param_1,&local_23c);

  if ((iVar3 != 0) || (local_23c == (int *)0x0)) goto LAB_004a3f6e;

  iVar3 = FUN_005be460(param_2);

  *(uint8_t *)(iVar3 + 0x7f8) = 1;

  awStack_218[0] = L'\0';

  awStack_218[1] = L'\0';

  puVar8 = auStack_214;

  for (iVar7 = 0x7f; iVar7 != 0; iVar7 = iVar7 + -1) {

    *puVar8 = 0;

    puVar8 = puVar8 + 1;

  }

  cVar2 = FUN_00798bb0(local_23c,L"type",awStack_218);

  uStack_240._0_3_ = CONCAT12(cVar2,(ushort)uStack_240);

  if (cVar2 == '\0') goto LAB_004a3cf7;

  iVar7 = _wcsicmp(L"Billboard",awStack_218);

  if (iVar7 == 0) {

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0x8d4) = 0;

  }

  else {

    iVar7 = _wcsicmp(L"Kite",awStack_218);

    if (iVar7 == 0) {

      *(uint32_t /* width from decompiler */ *)(iVar3 + 0x8d4) = 1;

    }

    else {

      iVar7 = _wcsicmp(L"Decal",awStack_218);

      if (iVar7 == 0) {

        *(uint32_t /* width from decompiler */ *)(iVar3 + 0x8d4) = 2;

      }

      else {

        iVar7 = _wcsicmp(L"Beam",awStack_218);

        if (iVar7 == 0) {

          *(uint32_t /* width from decompiler */ *)(iVar3 + 0x8d4) = 3;

        }

        else {

          iVar7 = _wcsicmp(L"CenterBeam",awStack_218);

          if (iVar7 == 0) {

            *(uint32_t /* width from decompiler */ *)(iVar3 + 0x8d4) = 4;

          }

          else {

            iVar7 = _wcsicmp(L"Fluid",awStack_218);

            if (iVar7 != 0) {

              FUN_005be310(iVar3);

              goto LAB_004a3f6e;

            }

            *(uint32_t /* width from decompiler */ *)(iVar3 + 0x8d4) = 5;

          }

        }

      }

    }

  }

  if (((DAT_00af06e8 == '\0') || (cVar2 = FUN_004a6910(), cVar2 == '\0')) &&

     (*(int *)(iVar3 + 0x8d4) == 5)) {

    FUN_005be310(iVar3);

    ExceptionList = pvStack_14;

    return 1;

  }

  *(uint16_t *)(iVar3 + 0x8d8) = 0;

  cVar2 = FUN_00798bb0(local_23c,L"restrictedTime",awStack_218);

  uStack_240._0_3_ = CONCAT12(cVar2,(ushort)uStack_240);

  if (cVar2 != '\0') {

    pwVar4 = wcsstr(awStack_218,L"Dawn");

    if (pwVar4 != (wchar_t *)0x0) {

      *(uint16_t *)(iVar3 + 0x8d8) = 1;

    }

    pwVar4 = wcsstr(awStack_218,L"Midday");

    if (pwVar4 != (wchar_t *)0x0) {

      *(byte *)(iVar3 + 0x8d8) = *(byte *)(iVar3 + 0x8d8) | 2;

    }

    pwVar4 = wcsstr(awStack_218,L"Sunset");

    if (pwVar4 != (wchar_t *)0x0) {

      *(byte *)(iVar3 + 0x8d8) = *(byte *)(iVar3 + 0x8d8) | 4;

    }

    pwVar4 = wcsstr(awStack_218,L"Night");

    if (pwVar4 != (wchar_t *)0x0) {

      *(ushort *)(iVar3 + 0x8d8) = *(ushort *)(iVar3 + 0x8d8) | 8;

    }

  }

  cVar2 = FUN_00798bb0(local_23c,L"cardPivot",awStack_218);

  uStack_240._0_3_ = CONCAT12(cVar2,(ushort)uStack_240);

  if (cVar2 != '\0') {

    pwVar4 = wcsstr(awStack_218,L"NW");

    if (pwVar4 == (wchar_t *)0x0) {

      pwVar4 = wcsstr(awStack_218,L"N");

      if (pwVar4 == (wchar_t *)0x0) {

        pwVar4 = wcsstr(awStack_218,L"NE");

        if (pwVar4 == (wchar_t *)0x0) {

          pwVar4 = wcsstr(awStack_218,L"W");

          if (pwVar4 == (wchar_t *)0x0) {

            pwVar4 = wcsstr(awStack_218,L"Center");

            if (pwVar4 == (wchar_t *)0x0) {

              pwVar4 = wcsstr(awStack_218,L"E");

              if (pwVar4 == (wchar_t *)0x0) {

                pwVar4 = wcsstr(awStack_218,L"SW");

                if (pwVar4 == (wchar_t *)0x0) {

                  pwVar4 = wcsstr(awStack_218,L"S");

                  if (pwVar4 == (wchar_t *)0x0) {

                    pwVar4 = wcsstr(awStack_218,L"SE");

                    if (pwVar4 == (wchar_t *)0x0) {

                      FUN_007a4480(1,

                                   "ParseParticle couldn\'t find a valid direction for cardPivot, read <%S> is not a direction"

                                   ,awStack_218);

                    }

                    else {

                      *(uint32_t /* width from decompiler */ *)(iVar3 + 0x8f4) = 3;

                    }

                  }

                  else {

                    *(uint32_t /* width from decompiler */ *)(iVar3 + 0x8f4) = 2;

                  }

                }

                else {

                  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x8f4) = 1;

                }

              }

              else {

                *(uint32_t /* width from decompiler */ *)(iVar3 + 0x8f4) = 5;

              }

            }

            else {

              *(uint32_t /* width from decompiler */ *)(iVar3 + 0x8f4) = 0;

            }

          }

          else {

            *(uint32_t /* width from decompiler */ *)(iVar3 + 0x8f4) = 4;

          }

        }

        else {

          *(uint32_t /* width from decompiler */ *)(iVar3 + 0x8f4) = 8;

        }

      }

      else {

        *(uint32_t /* width from decompiler */ *)(iVar3 + 0x8f4) = 7;

      }

    }

    else {

      *(uint32_t /* width from decompiler */ *)(iVar3 + 0x8f4) = 6;

    }

  }

  cStack_22a = '\0';

  FUN_007996d0(local_23c,L"bright",&cStack_22a);

  *(byte *)(iVar3 + 0x989) =

       *(byte *)(iVar3 + 0x989) ^ (cStack_22a << 6 ^ *(byte *)(iVar3 + 0x989)) & 0x40;

  bStack_22c = 0;

  FUN_007996d0(local_23c,L"doubleSided",&bStack_22c);

  *(byte *)(iVar3 + 0x989) = *(byte *)(iVar3 + 0x989) ^ (*(byte *)(iVar3 + 0x989) ^ bStack_22c) & 1;

  cStack_236 = '\0';

  FUN_007996d0(local_23c,L"skybox",&cStack_236);

  *(byte *)(iVar3 + 0x989) = *(byte *)(iVar3 + 0x989) & 0x7f | cStack_236 << 7;

  bStack_22b = 0;

  if (cStack_236 != '\0') {

    FUN_007996d0(local_23c,L"skyboxScaled",&bStack_22b);

  }

  *(byte *)(iVar3 + 0x98a) = *(byte *)(iVar3 + 0x98a) ^ (*(byte *)(iVar3 + 0x98a) ^ bStack_22b) & 1;

  uStack_230 = uStack_230 & 0xffffff;

  FUN_007996d0(local_23c,L"terrain",(int)&uStack_230 + 3);

  *(byte *)(iVar3 + 0x98a) =

       *(byte *)(iVar3 + 0x98a) ^ (uStack_230._3_1_ * '\x02' ^ *(byte *)(iVar3 + 0x98a)) & 2;

  cStack_229 = '\0';

  FUN_007996d0(local_23c,L"distort",&cStack_229);

  *(byte *)(iVar3 + 0x98a) =

       *(byte *)(iVar3 + 0x98a) ^ (cStack_229 * '\x04' ^ *(byte *)(iVar3 + 0x98a)) & 4;

  acStack_235[0] = '\0';

  FUN_007996d0(local_23c,L"glow",acStack_235);

  *(byte *)(iVar3 + 0x98a) =

       *(byte *)(iVar3 + 0x98a) ^ (acStack_235[0] * '\b' ^ *(byte *)(iVar3 + 0x98a)) & 8;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x8d0) = 0;

  cVar2 = FUN_00798bb0(local_23c,L"filter",awStack_218);

  uStack_240._0_3_ = CONCAT12(cVar2,(ushort)uStack_240);

  if (cVar2 != '\0') {

    iVar7 = _wcsnicmp(awStack_218,L"per",3);

    if (iVar7 == 0) {

      *(uint32_t /* width from decompiler */ *)(iVar3 + 0x8d0) = 2;

    }

    else {

      iVar7 = _wcsnicmp(awStack_218,L"pub",3);

      if (iVar7 == 0) {

        *(uint32_t /* width from decompiler */ *)(iVar3 + 0x8d0) = 1;

      }

      iVar7 = _wcsnicmp(awStack_218,L"fac",3);

      if (iVar7 == 0) {

        *(uint32_t /* width from decompiler */ *)(iVar3 + 0x8d0) = 4;

      }

    }

  }

  uStack_240._0_3_ = (uint3)(ushort)uStack_240;

  FUN_007996d0(local_23c,L"missileExplosion",(int)&uStack_240 + 2);

  *(byte *)(iVar3 + 0x989) =

       *(byte *)(iVar3 + 0x989) ^ (uStack_240._2_1_ * '\b' ^ *(byte *)(iVar3 + 0x989)) & 8;

  uStack_240._0_3_ = (uint3)(ushort)uStack_240;

  FUN_007996d0(local_23c,L"destroyOnEmitterDeath",(int)&uStack_240 + 2);

  *(byte *)(iVar3 + 0x98c) =

       *(byte *)(iVar3 + 0x98c) ^ (uStack_240._2_1_ << 6 ^ *(byte *)(iVar3 + 0x98c)) & 0x40;

  uStack_240._0_3_ = (uint3)(ushort)uStack_240;

  cVar2 = FUN_007996d0(local_23c,L"ignoreObjectScale",(int)&uStack_240 + 2);

  if (cVar2 == '\0') {

    *(byte *)(iVar3 + 0x98d) = *(byte *)(iVar3 + 0x98d) | 2;

  }

  else {

    *(byte *)(iVar3 + 0x98d) =

         *(byte *)(iVar3 + 0x98d) ^ (uStack_240._2_1_ * '\x02' ^ *(byte *)(iVar3 + 0x98d)) & 2;

  }

  cVar2 = FUN_00798bb0(local_23c,L"heading",awStack_218);

  uStack_240._0_3_ = CONCAT12(cVar2,(ushort)uStack_240);

  if (cVar2 == '\0') {

LAB_004a3ccf:

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0x984) = 0;

  }

  else if ((awStack_218[0] == 0x70) || (awStack_218[0] == 0x50)) {

    lVar5 = _wtol(awStack_218 + 1);

    FUN_005b8370(lVar5,0xc,iVar3 + 0x844,iVar3);

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0x984) = 4;

  }

  else {

    iVar7 = _wcsicmp(L"Velocity",awStack_218);

    fVar1 = g_flOne;

    if (iVar7 == 0) {

      *(uint32_t /* width from decompiler */ *)(iVar3 + 0x844) = 0;

      *(float *)(iVar3 + 0x848) = fVar1;

      *(uint32_t /* width from decompiler */ *)(iVar3 + 0x84c) = 0;

      *(uint32_t /* width from decompiler */ *)(iVar3 + 0x984) = 2;

    }

    else {

      iVar7 = _wcsicmp(L"Body",awStack_218);

      if (iVar7 == 0) goto LAB_004a3ccf;

      iVar7 = _wcsicmp(L"invBody",awStack_218);

      fVar1 = g_flOne;

      if (iVar7 == 0) {

        *(uint32_t /* width from decompiler */ *)(iVar3 + 0x984) = 3;

      }

      else if ((awStack_218[0] == 0x68) || (awStack_218[0] == 0x48)) {

        *(uint32_t /* width from decompiler */ *)(iVar3 + 0x984) = 5;

        *(uint32_t /* width from decompiler */ *)(iVar3 + 0x844) = 0;

        *(float *)(iVar3 + 0x848) = fVar1;

        *(uint32_t /* width from decompiler */ *)(iVar3 + 0x84c) = 0;

        pwStack_224 = awStack_218 + 1;

        uStack_240 = uStack_240 & 0xffffff;

        FUN_00798880(&pwStack_224,(uint32_t /* width from decompiler */ *)(iVar3 + 0x844),(int)&uStack_240 + 3);

        *(byte *)(iVar3 + 0x98c) =

             *(byte *)(iVar3 + 0x98c) ^ (uStack_240._3_1_ << 4 ^ *(byte *)(iVar3 + 0x98c)) & 0x10;

      }

      else {

        pwStack_224 = awStack_218;

        *(uint32_t /* width from decompiler */ *)(iVar3 + 0x984) = 1;

        *(uint32_t /* width from decompiler */ *)(iVar3 + 0x844) = 0;

        *(float *)(iVar3 + 0x848) = fVar1;

        *(uint32_t /* width from decompiler */ *)(iVar3 + 0x84c) = 0;

        uStack_240 = uStack_240 & 0xffffff;

        FUN_00798880(&pwStack_224,(uint32_t /* width from decompiler */ *)(iVar3 + 0x844),(int)&uStack_240 + 3);

        *(byte *)(iVar3 + 0x98c) =

             *(byte *)(iVar3 + 0x98c) ^ (uStack_240._3_1_ << 4 ^ *(byte *)(iVar3 + 0x98c)) & 0x10;

      }

    }

  }

  piStack_220 = (int *)0x0;

  (**(code **)(*param_1 + 0x30))(param_1,&piStack_220);

  if (piStack_220 != (int *)0x0) {

    (**(code **)(*piStack_220 + 0x20))(piStack_220,auStack_21c);

    local_23c = (int *)0x0;

    iVar7 = 0;

    pvStack_14 = (void *)0x0;

    bStack_22c = 1;

    pcVar9 = _wcsicmp_exref;

    if (0 < (int)pwStack_224) {

      do {

        uStack_230 = 0;

        iVar6 = (**(code **)(*piStack_228 + 0x1c))(piStack_228,iVar7,&uStack_230);

        if ((iVar6 < 0) || (local_23c == (int *)0x0)) {

          FUN_005be310(iVar3);

          FUN_007a4480(0,"VOG_DEBUG_STOP");

          SysFreeString(unaff_EBX);

          ExceptionList = pvStack_28;

          return 0;

        }

        FUN_0040d230();

        (**(code **)(*local_23c + 0x1c))(local_23c,&stack0xfffffdb8);

        iVar6 = (*pcVar9)(L"Keyframe",unaff_EDI);

        if (iVar6 == 0) {

          cVar2 = FUN_004a2a80(iVar3,pOStack_244,uStack_240);

          if (cVar2 == '\0') {

            FUN_005be310(iVar3);

            SysFreeString(unaff_EDI);

            ExceptionList = pvStack_30;

            return 0;

          }

          uStack_240 = uStack_240 & 0xffffff00;

        }

        else {

          iVar6 = (*pcVar9)(L"EmitterInfo",unaff_EDI);

          if (iVar6 == 0) {

            cVar2 = FUN_004a2ed0(iVar3,pOStack_244);

            if (cVar2 == '\0') {

              FUN_005be310(iVar3);

              SysFreeString(unaff_EDI);

              ExceptionList = pvStack_30;

              return 0;

            }

          }

          else {

            iVar6 = (*pcVar9)(L"Fluid",unaff_EDI);

            if ((iVar6 == 0) && (cVar2 = FUN_004a6910(), cVar2 != '\0')) {

              iVar6 = FUN_0049f430(pOStack_244,param_2);

              if (iVar6 == 0) {

                FUN_005be310(iVar3);

                SysFreeString(unaff_EDI);

                ExceptionList = pvStack_30;

                return 0;

              }

              *(uint8_t *)(iVar6 + 0x178) = 0;

              FUN_005b8230(iVar6);

              FUN_004b92b0(iVar6);

              pcVar9 = _wcsicmp_exref;

            }

          }

        }

        (**(code **)(*(int *)pOStack_244 + 8))(pOStack_244);

        FUN_0040d230();

        iVar7 = iVar7 + 1;

      } while (iVar7 < (int)pwStack_224);

    }

    (**(code **)(*piStack_228 + 8))(piStack_228);

    (**(code **)(*(int *)unaff_EBX + 8))(unaff_EBX);

    *param_3 = iVar3;

    SysFreeString(pOStack_244);

    ExceptionList = pvStack_24;

    return 1;

  }

LAB_004a3cf7:

  FUN_005be310(iVar3);

  ExceptionList = pvStack_14;

  return 0;

}

// READABILITY (auto CF):
//  - Body size: ~182 non-empty decompiler lines.
//  - Control keywords: if×16, goto×4, return×2, for×1, do×1, while×1.
//  - Notable callees: FUN_007996d0×10, FUN_00799300×5, FUN_005b8370×3, SysFreeString×3, _wcsicmp×3, FUN_007a4480×2, CONCAT31, FUN_0049cc50.
//  - Strings: "VOG_DEBUG_STOP"; "loopingKeyframes"; "alwaysAddBodyVelocity"; "particleDuration".
//  - Return sites: 2.

// =============================================================================
// Mission_numberPerEmission_004a2ed0
// -----------------------------------------------------------------------------
// Stable ID: aa_004a2ed0
// Address:   0x004a2ed0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "numberPerEmission"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Mission_numberPerEmission_004a2ed0(int param_1,int *param_2)



{

  float fVar1;

  char cVar2;

  byte bVar3;

  int iVar4;

  BSTR unaff_EBX;

  uint32_t /* width from decompiler */ *puVar5;

  byte bStack_24e;

  char cStack_24d;

  int local_24c;

  BSTR local_248;

  uint8_t auStack_244 [3];

  char cStack_241;

  int *piStack_240;

  int *piStack_23c;

  int *apiStack_238 [2];

  float fStack_230;

  uint local_22c;

  uint8_t auStack_228 [4];

  float fStack_224;

  uint32_t /* width from decompiler */ uStack_220;

  uint32_t /* width from decompiler */ auStack_21c [126];

  void *pvStack_24;

  void *pvStack_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ local_c;

  

  puStack_10 = &LAB_009a10cb;

  pvStack_14 = ExceptionList;

  local_248 = (BSTR)0x0;

  local_c = 0;

  local_22c = CONCAT31(local_22c._1_3_,1);

  ExceptionList = &pvStack_14;

  if (param_2 == (int *)0x0) {

LAB_004a34a6:

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  else {

    ExceptionList = &pvStack_14;

    iVar4 = (**(code **)(*param_2 + 0x44))(param_2,&local_24c);

    if ((iVar4 == 0) && (local_24c != 0)) {

      FUN_007996d0(local_24c,L"loopingKeyframes",param_1 + 0x7fb);

      cVar2 = FUN_007996d0(local_24c,L"alwaysAddBodyVelocity",&cStack_24d);

      if (cVar2 != '\0') {

        *(char *)(param_1 + 0x7fd) = cStack_24d;

      }

      FUN_00799300(local_24c,L"particleDuration",param_1 + 0x80c);

      FUN_00799460(local_24c,L"minParticles",param_1 + 0x97c,10);

      FUN_00799300(local_24c,L"deathRange",param_1 + 0x980);

      cStack_24d = '\0';

      FUN_007996d0(local_24c,L"deathRangeKill",&cStack_24d);

      *(byte *)(param_1 + 0x989) =

           *(byte *)(param_1 + 0x989) ^ (cStack_24d * '\x02' ^ *(byte *)(param_1 + 0x989)) & 2;

      cStack_24d = '\0';

      FUN_007996d0(local_24c,L"addAllEmitterMovement",&cStack_24d);

      *(byte *)(param_1 + 0x98a) =

           *(byte *)(param_1 + 0x98a) ^ (cStack_24d << 5 ^ *(byte *)(param_1 + 0x98a)) & 0x20;

      FUN_00799300(local_24c,L"duration",(uint32_t /* width from decompiler */ *)(param_1 + 0x900));

      fStack_224 = g_flOne;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x808) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x900);

      cStack_241 = '\0';

      piStack_240 = (int *)0x0;

      fStack_230 = fStack_224;

      FUN_00798f30(local_24c,&piStack_240,L"particlesPerSecond",&fStack_224,&fStack_230,&cStack_241)

      ;

      FUN_005b8370(piStack_240,4,param_1 + 0x8dc,param_1);

      fVar1 = g_flOne;

      if ((int)piStack_240 < 0) {

        if (fStack_224 != 0.0) {

          *(float *)(param_1 + 0x8dc) = g_flOne / fStack_224;

        }

        if ((cStack_241 == '\0') || (fStack_230 == 0.0)) {

          *(uint32_t /* width from decompiler */ *)(param_1 + 0x8e0) = 0;

        }

        else {

          *(float *)(param_1 + 0x8e0) = fVar1 / fStack_230 - *(float *)(param_1 + 0x8dc);

        }

      }

      FUN_00798e50(local_24c,&piStack_240,L"numberPerEmission",param_1 + 0x8e4,0,0);

      FUN_005b8370(piStack_240,2,param_1 + 0x8e4,param_1);

      FUN_007995a0(local_24c,&piStack_240,L"offset",param_1 + 0x8e8,0,0,0);

      FUN_005b8370(piStack_240,0xc,param_1 + 0x8e8,param_1);

      *(uint16_t *)(param_1 + 0x8f8) = 1;

      FUN_007998d0(local_24c,L"numberOfEmitters",(uint16_t *)(param_1 + 0x8f8),10);

      FUN_00799300(local_24c,L"startDelay",(uint32_t /* width from decompiler */ *)(param_1 + 0x8fc));

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x810) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x8fc);

      bStack_24e = 0;

      FUN_007996d0(local_24c,L"useTerrainHeight",&bStack_24e);

      *(byte *)(param_1 + 0x989) =

           *(byte *)(param_1 + 0x989) ^ (bStack_24e * '\x04' ^ *(byte *)(param_1 + 0x989)) & 4;

      bStack_24e = 0;

      FUN_007996d0(local_24c,L"continuousFire",&bStack_24e);

      bVar3 = bStack_24e << 4;

      bStack_24e = 0;

      *(byte *)(param_1 + 0x989) =

           *(byte *)(param_1 + 0x989) ^ (bVar3 ^ *(byte *)(param_1 + 0x989)) & 0x10;

      FUN_007996d0(local_24c,L"neverTimeout",&bStack_24e);

      *(byte *)(param_1 + 0x989) =

           *(byte *)(param_1 + 0x989) ^ (bStack_24e << 5 ^ *(byte *)(param_1 + 0x989)) & 0x20;

      bStack_24e = 0;

      FUN_007996d0(local_24c,L"neverCull",&bStack_24e);

      *(byte *)(param_1 + 0x988) = bStack_24e;

      bStack_24e = 0;

      FUN_007996d0(local_24c,L"terrainCollision",&bStack_24e);

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x904) = DAT_00aaa680;

      *(byte *)(param_1 + 0x98c) =

           *(byte *)(param_1 + 0x98c) ^ (bStack_24e << 5 ^ *(byte *)(param_1 + 0x98c)) & 0x20;

      FUN_00799300(local_24c,L"bounceEnergy",param_1 + 0x904);

      bStack_24e = 0;

      FUN_007996d0(local_24c,L"doVertexEmission",&bStack_24e);

      *(byte *)(param_1 + 0x98d) =

           *(byte *)(param_1 + 0x98d) ^ (*(byte *)(param_1 + 0x98d) ^ bStack_24e) & 1;

      if ((*(byte *)(param_1 + 0x98d) & 1) != 0) {

        *(byte *)(param_1 + 0x98c) = *(byte *)(param_1 + 0x98c) | 0x80;

      }

      uStack_220 = 0;

      puVar5 = auStack_21c;

      for (iVar4 = 0x81; iVar4 != 0; iVar4 = iVar4 + -1) {

        *puVar5 = 0;

        puVar5 = puVar5 + 1;

      }

      bStack_24e = FUN_00798bb0(local_24c,L"shadowTextureID",&uStack_220);

      FUN_0049dab0(&uStack_220,param_1 + 0x958,(int *)(param_1 + 0x954));

      if ((bStack_24e == 0) || (*(int *)(param_1 + 0x954) < 1)) {

        *(byte *)(param_1 + 0x98d) = *(byte *)(param_1 + 0x98d) & 0xfb;

      }

      else {

        *(byte *)(param_1 + 0x98d) = *(byte *)(param_1 + 0x98d) | 4;

      }

      apiStack_238[0] = (int *)0x0;

      (**(code **)(*param_2 + 0x30))(param_2,apiStack_238);

      if (apiStack_238[0] != (int *)0x0) {

        (**(code **)(*apiStack_238[0] + 0x20))(apiStack_238[0],auStack_228);

        piStack_23c = (int *)0x0;

        if (0 < (int)fStack_230) {

          do {

            iVar4 = (**(code **)(*piStack_240 + 0x1c))(piStack_240,piStack_23c,auStack_244);

            if ((iVar4 < 0) || (piStack_23c == (int *)0x0)) goto LAB_004a34a6;

            SysFreeString(local_248);

            local_248 = (wchar_t *)0x0;

            (**(code **)(*piStack_23c + 0x1c))(piStack_23c,&local_248);

            iVar4 = _wcsicmp(L"Ray",local_248);

            if (iVar4 == 0) {

              cVar2 = FUN_0049cc50(param_1,piStack_23c);

joined_r0x004a3404:

              if (cVar2 == '\0') goto LAB_004a34ce;

            }

            else {

              iVar4 = _wcsicmp(L"Circle",local_248);

              if (iVar4 == 0) {

                cVar2 = FUN_0049cde0(param_1,piStack_23c);

                goto joined_r0x004a3404;

              }

              iVar4 = _wcsicmp(L"Keyframe",local_248);

              if (iVar4 == 0) {

                cVar2 = FUN_004a2710(param_1,piStack_23c,local_22c);

                if (cVar2 == '\0') goto LAB_004a34ce;

                local_22c = local_22c & 0xffffff00;

                *(uint8_t *)(param_1 + 0x7fc) = 1;

                *(int *)(param_1 + 0x10) = param_1 + 0x3f8;

              }

            }

            (**(code **)(*piStack_23c + 8))(piStack_23c);

            piStack_23c = (int *)((int)piStack_23c + 1);

          } while ((int)piStack_23c < (int)fStack_230);

        }

        (**(code **)(*piStack_240 + 8))(piStack_240);

        (**(code **)(*(int *)unaff_EBX + 8))(unaff_EBX);

        SysFreeString(unaff_EBX);

        ExceptionList = pvStack_24;

        return 1;

      }

    }

    else {

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

  }

LAB_004a34ce:

  SysFreeString(local_248);

  ExceptionList = pvStack_14;

  return 0;

}

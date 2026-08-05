// =============================================================================
// FUN_0049f430
// -----------------------------------------------------------------------------
// Stable ID: aa_0049f430
// Address:   0x0049f430  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0049f430 @ 0x0049f430
// Stable ID: aa_0049f430
// Embedded strings (evidence for future rename):
//   - "VOG_DEBUG_STOP"
//   - "maxParticles"
//   - "accountForFrameDelay"
//   - "lifetime"
//   - "stiffness"
//   - "viscosity"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~183 non-empty decompiler lines.
//  - Control keywords: if×30, return×4, goto×2, do×1, while×1.
//  - Notable callees: FUN_00799300×14, _wcsicmp×5, SysFreeString×3, FUN_00499e20×2, FUN_007a4480×2, FUN_00499580, FUN_0049ec90, FUN_0049f430.
//  - Strings: "VOG_DEBUG_STOP"; "maxParticles"; "accountForFrameDelay"; "lifetime".
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

void * FUN_0049f430(int *param_1)



{

  char cVar1;

  int iVar2;

  void *pvVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int iVar5;

  int *piStack_244;

  wchar_t *local_240;

  uint32_t /* width from decompiler */ uStack_23c;

  uint32_t /* width from decompiler */ auStack_234 [2];

  void *pvStack_22c;

  uint32_t /* width from decompiler */ uStack_224;

  uint8_t auStack_220 [12];

  wchar_t awStack_214 [254];

  void *pvStack_18;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a0fb1;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  if (((param_1 == (int *)0x0) ||

      (ExceptionList = &pvStack_c, iVar2 = (**(code **)(*param_1 + 0x44))(param_1,&local_240),

      iVar2 != 0)) || (local_240 == (BSTR)0x0)) {

    FUN_007a4480(0,"VOG_DEBUG_STOP");

    ExceptionList = pvStack_c;

    return (void *)0x0;

  }

  pvStack_22c = operator_new(0x1e0);

  uStack_4 = 0;

  if (pvStack_22c == (void *)0x0) {

    pvVar3 = (void *)0x0;

  }

  else {

    pvVar3 = (void *)FUN_00499580();

  }

  uStack_4 = 0xffffffff;

  cVar1 = FUN_00799460(local_240,L"maxParticles",&uStack_224,10);

  if (cVar1 != '\0') {

    *(uint32_t /* width from decompiler */ *)((int)pvVar3 + 0x84) = uStack_224;

  }

  cVar1 = FUN_007996d0(local_240,L"accountForFrameDelay",(int)&uStack_23c + 3);

  if (cVar1 != '\0') {

    *(uint8_t *)((int)pvVar3 + 0x179) = uStack_23c._3_1_;

  }

  cVar1 = FUN_00799300(local_240,L"lifetime",&piStack_244);

  if (cVar1 != '\0') {

    *(int **)((int)pvVar3 + 0x174) = piStack_244;

  }

  cVar1 = FUN_00799300(local_240,L"stiffness",&piStack_244);

  if (cVar1 != '\0') {

    *(int **)((int)pvVar3 + 0xa0) = piStack_244;

  }

  cVar1 = FUN_00799300(local_240,L"viscosity",&piStack_244);

  if (cVar1 != '\0') {

    *(int **)((int)pvVar3 + 0xa4) = piStack_244;

  }

  cVar1 = FUN_00799300(local_240,L"restDensity",&piStack_244);

  if (cVar1 != '\0') {

    *(int **)((int)pvVar3 + 0x8c) = piStack_244;

  }

  cVar1 = FUN_00799300(local_240,L"damping",&piStack_244);

  if (cVar1 != '\0') {

    *(int **)((int)pvVar3 + 0xa8) = piStack_244;

  }

  cVar1 = FUN_00799300(local_240,L"restParticlesPerMeter",&piStack_244);

  if (cVar1 != '\0') {

    *(int **)((int)pvVar3 + 0x88) = piStack_244;

  }

  cVar1 = FUN_00799300(local_240,L"kernelRadiusMultiplier",&piStack_244);

  if (cVar1 != '\0') {

    *(int **)((int)pvVar3 + 0x90) = piStack_244;

  }

  cVar1 = FUN_00799300(local_240,L"motionLimitMultiplier",&piStack_244);

  if (cVar1 != '\0') {

    *(int **)((int)pvVar3 + 0x94) = piStack_244;

  }

  cVar1 = FUN_00799300(local_240,L"collisionDistanceMultiplier",&piStack_244);

  if (cVar1 != '\0') {

    *(int **)((int)pvVar3 + 0x98) = piStack_244;

  }

  cVar1 = FUN_00799300(local_240,L"packetSizeMultiplier",&piStack_244);

  if (cVar1 != '\0') {

    pvStack_22c = (void *)(int)ROUND((float)piStack_244);

    *(void **)((int)pvVar3 + 0x9c) = pvStack_22c;

  }

  cVar1 = FUN_00799300(local_240,L"staticCollisionRestitution",&piStack_244);

  if (cVar1 != '\0') {

    *(int **)((int)pvVar3 + 0xb8) = piStack_244;

  }

  cVar1 = FUN_00799300(local_240,L"staticCollisionAdhesion",&piStack_244);

  if (cVar1 != '\0') {

    *(int **)((int)pvVar3 + 0xbc) = piStack_244;

  }

  cVar1 = FUN_00799300(local_240,L"dynamicCollisionAdhesion",&piStack_244);

  if (cVar1 != '\0') {

    *(int **)((int)pvVar3 + 0xc4) = piStack_244;

  }

  cVar1 = FUN_00799300(local_240,L"dynamicCollisionResitution",&piStack_244);

  if (cVar1 != '\0') {

    *(int **)((int)pvVar3 + 0xc0) = piStack_244;

  }

  cVar1 = FUN_00798bb0(local_240,L"type",awStack_214);

  if (cVar1 != '\0') {

    iVar2 = _wcsicmp(awStack_214,L"water");

    if (iVar2 == 0) {

      *(uint32_t /* width from decompiler */ *)((int)pvVar3 + 0x170) = 0;

    }

    else {

      iVar2 = _wcsicmp(awStack_214,L"goo");

      if (iVar2 == 0) {

        *(uint32_t /* width from decompiler */ *)((int)pvVar3 + 0x170) = 2;

      }

      else {

        iVar2 = _wcsicmp(awStack_214,L"oil");

        if (iVar2 == 0) {

          *(uint32_t /* width from decompiler */ *)((int)pvVar3 + 0x170) = 1;

        }

        else {

          iVar2 = _wcsicmp(awStack_214,L"mud");

          if (iVar2 == 0) {

            *(uint32_t /* width from decompiler */ *)((int)pvVar3 + 0x170) = 3;

          }

        }

      }

    }

  }

  cVar1 = FUN_007994c0(local_240,L"externalAcceleration",auStack_220,0,0,0);

  if (cVar1 != '\0') {

    puVar4 = (uint32_t /* width from decompiler */ *)FUN_004a6930(auStack_220);

    *(uint32_t /* width from decompiler */ *)((int)pvVar3 + 0xac) = *puVar4;

    *(uint32_t /* width from decompiler */ *)((int)pvVar3 + 0xb0) = puVar4[1];

    *(uint32_t /* width from decompiler */ *)((int)pvVar3 + 0xb4) = puVar4[2];

  }

  (**(code **)(*(int *)local_240 + 8))(local_240);

  auStack_234[0] = 0;

  (**(code **)(*param_1 + 0x30))(param_1,auStack_234);

  if (uStack_23c == (int *)0x0) {

LAB_0049f92f:

    pvVar3 = (void *)0x0;

  }

  else {

    (**(code **)(*uStack_23c + 0x20))(uStack_23c,auStack_234);

    iVar2 = 0;

    pvStack_18 = (void *)0x1;

    if (0 < (int)uStack_23c) {

      do {

        iVar5 = (**(code **)(*piStack_244 + 0x1c))(piStack_244,iVar2,&stack0xfffffdb4);

        if ((iVar5 < 0) || (piStack_244 == (int *)0x0)) {

          FUN_007a4480(0,"VOG_DEBUG_STOP");

          if (pvVar3 != (void *)0x0) {

            FUN_00499e20();

                    /* WARNING: Subroutine does not return */

            operator_delete(pvVar3);

          }

LAB_0049f92d:

          SysFreeString(local_240);

          goto LAB_0049f92f;

        }

        SysFreeString(local_240);

        local_240 = (wchar_t *)0x0;

        (**(code **)(*piStack_244 + 0x1c))(piStack_244,&local_240);

        iVar5 = _wcsicmp(L"Emitter",local_240);

        if ((iVar5 == 0) && (cVar1 = FUN_0049ec90(piStack_244,pvVar3), cVar1 == '\0')) {

          if (pvVar3 != (void *)0x0) {

            FUN_00499e20();

                    /* WARNING: Subroutine does not return */

            operator_delete(pvVar3);

          }

          goto LAB_0049f92d;

        }

        (**(code **)(*piStack_244 + 8))(piStack_244);

        iVar2 = iVar2 + 1;

      } while (iVar2 < (int)uStack_23c);

    }

    (**(code **)(*piStack_244 + 8))(piStack_244);

    SysFreeString(local_240);

  }

  ExceptionList = pvStack_18;

  return pvVar3;

}

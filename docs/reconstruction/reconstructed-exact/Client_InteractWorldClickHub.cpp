// =============================================================================
// Client_InteractWorldClickHub
// -----------------------------------------------------------------------------
// Stable ID: aa_00925820
// Address:   0x00925820  (autoassault.exe, image base 0x400000)
// System:    interaction-activation / client input
// Generated: 2026-07-29 W17-C dual A/B seal (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Client virtual mouse/world-click hub (vtable DATA @ 0x00a2f420):
//     - early mode/flag gate
//     - mouse UI vtbl+0x430 / +0x428 dispatch
//     - optional CVOGHBBase_Stop + VehicleEntity_SetLongitudinalInput(0)
//     - selected-object vtbl+0x37C consume
//     - dead/UI modal gates
//     - alt path FUN_0091a350 when DAT_00d1a860==0
//     - drop-destroy modal when char+0xCD0 != 0
//     - else ray (100.0f) + gather (20.0f mode 6):
//         * miss TFID → hit-list walk → ForPick select / ForInteract+IfInteractable
//         * hit TFID  → Client_SendItemPickup; clear select[0x1d6]; FUN_0093e120(0)
//
// ABI: thiscall ECX=client*; stack (param_2, packedMouse param_3); ret 8.
// SEALED: gate, constants 100f/20f, stage order, ItemPickup clear-select, vtbl install.
// =============================================================================

#include <cstdint>

extern int   DAT_00d1b644;
extern int*  DAT_00d1b6d8;
extern int*  DAT_00d1b958;
extern int*  DAT_00d1b95c;
extern char  DAT_00d1a860;
extern char  DAT_00d1a859;
extern char  DAT_00d1b205;
extern char  DAT_00d1a840;
extern int   DAT_00d1d86c;
extern int   DAT_00d1d870;
extern float DAT_00aaa7ac; // 100.0f @ 0x00aaa7ac
extern float g_flOne;      // 1.0f  @ 0x00a0f2a0

// Sealed / named callees
extern void  __fastcall CVOGHBBase_Stop(void* hb /*ECX*/);
extern void  VehicleEntity_SetLongitudinalInput(float v);
extern int   CVOGCharacter_FindActiveObjectiveIdForPick(int obj);
extern int   FUN_00524520(int obj); // FindActiveObjectiveIdForInteract
extern void  Client_SendUseObject_IfInteractable(void);
extern void  Client_SendItemPickup(void); // ESI = TFID pair* at call sites
extern void  Client_ShowModalPrompt(void* a, const char* msg, int id, int b, int c);
extern void  FUN_0093e120(int objOrZero);
extern uint32_t FUN_0091a350(void);
extern void  FUN_00914c20(void);
extern void  FUN_0075c340(void* a, float* b, float* c);
extern void  FUN_0055e530(void* ray, void* out);
extern void  FUN_0055e1e0(void* ray, void* list);
extern void  FUN_0058cd60(void* tfidOut, int a, uint32_t b, int body, float* pt,
                          float radius, int c, int mode, int d, int e, int f);
extern void  FUN_0040c410(void* list);
extern void  FUN_0040c510(void);
extern void  FUN_0048a060(void);
extern int*  FUN_0040afb0(void* a, int b);

// Ghidra EH frame omitted; control flow preserved.
uint32_t __thiscall Client_InteractWorldClickHub(int* self, uint32_t param_2, uint32_t param_3)
{
  int iVar1;
  char cVar2;
  uint32_t uVar3;
  int* piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  float fVar8;
  int iStack_28c;
  uint32_t uStack_288;
  uint32_t uStack_284;
  float fStack_280, fStack_27c, fStack_278, fStack_274;
  float fStack_270, fStack_26c, fStack_268, fStack_264;
  uint8_t uStack_260;
  uint32_t uStack_25c;
  float fStack_248, fStack_244, fStack_240;
  float fStack_23c, fStack_238, fStack_234;
  float fStack_230, fStack_22c, fStack_228, fStack_224;
  uint32_t uStack_220, uStack_21c;
  uint8_t auStack_1f0[20];
  float fStack_1dc;
  int iStack_1d0;
  uint8_t auStack_1c0[16];
  int iStack_1b0;
  int iStack_1ac;

  // Early gate: enter body unless (mode==6 && +0x493==0 && world+0xf5==0)
  if ((self[0x331] != 6) ||
      (*(char*)((uint8_t*)self + 0x493) != '\0') ||
      (*(char*)(DAT_00d1b644 + 0xf5) != '\0')) {

    iVar7 = (int)(int16_t)(param_3 >> 16); // sy
    // mouse UI pair
    ((void(__thiscall*)(void*, int, int, int))(*(int*)(*self + 0x430)))(
        self, self[0x12e], (int)(int16_t)param_3, iVar7);
    ((void(__thiscall*)(void*, int, int, int))(*(int*)(*self + 0x428)))(
        self, self[0x12e], (int)(int16_t)param_3, iVar7);

    iVar7 = 0;
    if ((DAT_00d1a860 != '\0') && (self[0x31c] != 0)) {
      *(uint8_t*)((uint8_t*)self + 0xa35) = 0;
      CVOGHBBase_Stop(); // ECX from caller convention in retail
      if ((DAT_00d1b6d8 != nullptr) && (*(int*)((uint8_t*)DAT_00d1b6d8 + 0x250) != 0)) {
        VehicleEntity_SetLongitudinalInput(0.0f);
      }
    }

    if ((self[0x12e] != 0) &&
        (cVar2 = ((char(__thiscall*)(void*, uint32_t, uint32_t))(
                      *(int*)(*(int*)self[0x12e] + 0x37c)))(
             (void*)self[0x12e], param_2, param_3),
         cVar2 != '\0')) {
      return 1;
    }

    if ((DAT_00d1b6d8 != nullptr) &&
        (cVar2 = ((char(__thiscall*)(void*))(
                      *(int*)(*(int*)((uint8_t*)DAT_00d1b6d8 +
                                      *(int*)(*(int*)((uint8_t*)DAT_00d1b6d8 + 4) + 4) + 4) +
                               0x194)))(
             (void*)((uint8_t*)DAT_00d1b6d8 +
                     *(int*)(*(int*)((uint8_t*)DAT_00d1b6d8 + 4) + 4) + 4)),
         cVar2 == '\0') &&
        (cVar2 = ((char(__thiscall*)(void*))(*(int*)(*DAT_00d1b958 + 0x3d8)))(DAT_00d1b958),
         cVar2 == '\0') &&
        (cVar2 = ((char(__thiscall*)(void*))(*(int*)(*DAT_00d1b95c + 0x3d8)))(DAT_00d1b95c),
         cVar2 == '\0')) {

      if (DAT_00d1a860 == '\0') {
        uVar3 = FUN_0091a350();
        return uVar3;
      }

      if (*(int*)((uint8_t*)DAT_00d1b6d8 + 0xcd0) != 0) {
        FUN_00914c20();
        DAT_00d1a859 = 0;
        *(uint8_t*)((uint8_t*)DAT_00d1b6d8 + 0x304) = 0;
        Client_ShowModalPrompt(&DAT_00d1a840,
            "Dropping this item will permanently destroy it. Are you sure?!",
            0x4e4b, 1, 0);
        return 1;
      }

      // Raycast / gather interact
      uStack_284 = (uint32_t)DAT_00d1d870;
      uStack_220 = 0xffffffffu;
      uStack_21c = 0xffffffffu;
      uStack_288 = (uint32_t)DAT_00d1d86c;
      FUN_0075c340(&uStack_288, &fStack_248, &fStack_23c);
      fStack_270 = fStack_23c * DAT_00aaa7ac + fStack_248;
      fStack_26c = fStack_238 * DAT_00aaa7ac + fStack_244;
      fStack_268 = fStack_234 * DAT_00aaa7ac + fStack_240;
      fStack_280 = fStack_248;
      fStack_27c = fStack_244;
      fStack_278 = fStack_240;
      fStack_274 = 0.0f;
      uStack_260 = 1;
      uStack_25c = 5;
      fStack_264 = 0.0f;
      fStack_1dc = g_flOne;
      iStack_1d0 = 0;

      if (*(int*)(DAT_00d1b644 + 0xe4a4) != 0) {
        FUN_0055e530(&fStack_280, auStack_1f0);
        if (iStack_1d0 != 0) {
          fVar8 = g_flOne - fStack_1dc;
          fStack_230 = fVar8 * fStack_280 + fStack_270 * fStack_1dc;
          fStack_22c = fStack_27c * fVar8 + fStack_26c * fStack_1dc;
          fStack_228 = fStack_278 * fVar8 + fStack_268 * fStack_1dc;
          fStack_224 = fStack_274 * fVar8 + fStack_264 * fStack_1dc;
          if (DAT_00d1b6d8 == nullptr) {
            iVar6 = 0;
          } else {
            iVar6 = *(int*)(*(int*)((uint8_t*)DAT_00d1b6d8 + 4) + 4) + 4 +
                    (int)(intptr_t)DAT_00d1b6d8;
          }
          FUN_0058cd60(&uStack_220, 0,
                       *(uint32_t*)((uint8_t*)DAT_00d1b6d8 +
                                    *(int*)(*(int*)((uint8_t*)DAT_00d1b6d8 + 4) + 4) + 0xa8),
                       iVar6, &fStack_230, 20.0f /*0x41a00000*/, 1, 6, 0, 0, 1);
        }

        if ((uStack_220 & uStack_21c) == 0xffffffffu) {
          FUN_0040c410(auStack_1c0);
          uStack_25c = 1;
          FUN_0055e1e0(&fStack_280, auStack_1c0);
          FUN_0048a060();
          if ((iStack_1ac != 0) && (iStack_28c = 0, iVar6 = (int)(intptr_t)DAT_00d1b6d8,
                                   iStack_1ac > 0)) {
            do {
              if (*(int*)(iVar7 + 0x20 + iStack_1b0) != 0) {
                piVar4 = FUN_0040afb0(&uStack_288, 1);
                iVar1 = *piVar4;
                if (iVar1 != 0) {
                  if (DAT_00d1b205 == '\0') {
                    if (iVar6 == 0) {
                      iVar5 = 0;
                    } else {
                      iVar5 = *(int*)(*(int*)(iVar6 + 4) + 4) + 4 + iVar6;
                    }
                    if (iVar1 != iVar5) {
                      iVar5 = *(int*)(iVar6 + 0x250);
                      if (iVar5 != 0) {
                        iVar5 = *(int*)(*(int*)(iVar5 + 4) + 4) + 4 + iVar5;
                      }
                      if (iVar1 != iVar5)
                        goto LAB_pick;
                    }
                  } else {
                  LAB_pick:
                    iVar6 = CVOGCharacter_FindActiveObjectiveIdForPick(iVar1);
                    if (iVar6 != 0) {
                      FUN_0093e120(iVar1);
                    }
                    iVar5 = FUN_00524520(iVar1);
                    iVar6 = (int)(intptr_t)DAT_00d1b6d8;
                    if (iVar5 != 0) {
                      FUN_0093e120(iVar1);
                      Client_SendUseObject_IfInteractable();
                      iVar6 = (int)(intptr_t)DAT_00d1b6d8;
                    }
                  }
                }
              }
              iStack_28c = iStack_28c + 1;
              iVar7 = iVar7 + 0x30;
            } while (iStack_28c < iStack_1ac);
          }
          FUN_0040c510();
        } else {
          // Valid gather TFID → ItemPickup 0x2055; clear select
          Client_SendItemPickup(); // retail: ESI → &uStack_220 pair
          self[0x1d6] = 0;
          FUN_0093e120(0);
        }
      }
    }
  }
  return 0;
}

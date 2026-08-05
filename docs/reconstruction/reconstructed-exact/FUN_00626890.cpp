// =============================================================================
// FUN_00626890  (decompiler-faithful twin)
// -----------------------------------------------------------------------------
// Stable ID: aa_00626890
// Address:   0x00626890 – 0x00626a46  (autoassault.exe, image base 0x400000)
// Structural: Object_ActivatePlayerEnqueueHB_Inferred
// Generated: 2026-07-29 W27-F — line-faithful mirror of live decompile
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

struct CVOGHBBase {
  void *pOwnerObject;
};

extern void *ExceptionList;
extern uint8_t LAB_009a8b27;

void FUN_0053d970(int mode);
int FUN_00578270(void);
void FUN_004c4880(int expr);
void FUN_0051f890(int flag);
void Object_SetSelectedTarget(void *a, void *b, void *c);
void *operator_new(uint32_t size);
CVOGHBBase *FUN_006264e0(int a, int b, int c);
void CVOGHBList_Enqueue(void *list, CVOGHBBase *action);
void CVOGHBBase_Start(CVOGHBBase *action);
void FUN_00578b30(void);

typedef int (*code)(...);

void __fastcall FUN_00626890(int param_1)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  void *pvVar4;
  CVOGHBBase *pAction;
  void *unaff_ESI;
  void *pvStack_c;
  uint8_t *puStack_8;
  uint32_t uStack_4;

  uStack_4 = 0xffffffffu;
  puStack_8 = &LAB_009a8b27;
  pvStack_c = ExceptionList;
  if (*(int **)(param_1 + 0x18) == (int *)0x0) {
    iVar1 = 0;
    ExceptionList = &pvStack_c;
  } else {
    ExceptionList = &pvStack_c;
    iVar1 = (**(code **)(**(int **)(param_1 + 0x18) + 0x214))();
    if (iVar1 != 0) {
      FUN_0053d970(0);
    }
  }
  iVar2 = FUN_00578270();
  if (iVar2 != 0) {
    piVar3 = (int *)FUN_00578270();
    iVar2 = (**(code **)(*piVar3 + 0x210))(0);
    if (iVar2 != 0) {
      FUN_004c4880(*(int *)(*(int *)(iVar2 + 4) + 4) + 0x164 + iVar2);
      FUN_0051f890(1);
      if (*(float *)(param_1 + 0x184) != 0.0f) {
        *(uint8_t *)(iVar2 + 0x6ba) = 1;
      }
      if (*(int *)(iVar2 + 0x250) != 0) {
        if (*(float *)(param_1 + 0x188) == 0.0f) {
          (**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) + 0x188))(4);
        } else {
          (**(code **)(*(int *)(*(int *)(iVar2 + 0x250) + 0x40) + 0x1c))(0);
          (**(code **)(**(int **)(iVar2 + 0x250) + 4))();
          *(uint8_t *)(*(int *)(iVar2 + 0x250) + 0x101) = 1;
        }
      }
      if (iVar1 == 0) {
        pvVar4 = (void *)0x0;
      } else {
        pvVar4 = (void *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1);
      }
      Object_SetSelectedTarget(
          (void *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2), pvVar4, unaff_ESI);
      *(uint8_t *)(iVar2 + 0xd78) = 1;
      pvVar4 = operator_new(0x2c);
      uStack_4 = 0;
      if (pvVar4 == (void *)0x0) {
        pAction = (CVOGHBBase *)0x0;
      } else {
        pAction = (CVOGHBBase *)FUN_006264e0(
            param_1 + 0x24, *(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2, param_1);
      }
      uStack_4 = 0xffffffffu;
      if (pAction->pOwnerObject != (void *)0x0) {
        *(CVOGHBBase **)(param_1 + 0x6c4) = pAction;
        CVOGHBList_Enqueue(
            *(void **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 0xa8 + iVar2) + 0xe4ec),
            pAction);
        CVOGHBBase_Start(pAction);
      }
      *(uint8_t *)(iVar2 + 0x6bb) = 0;
    }
  }
  FUN_00578b30();
  ExceptionList = pvStack_c;
  return;
}

// =============================================================================
// Object_ActivatePlayerEnqueueHB_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00626890
// Address:   0x00626890 – 0x00626a46  (autoassault.exe, image base 0x400000)
// Size:      438 B / 0x1B6  (pad CC after plain RET)
// System:    object / player bind / CVOGHB activate
// Generated: 2026-07-29 W27-F dual seal (decompile + read_memory)
// Exactness: Behavior-preserving CF reconstruction. Twin FUN_00626890.cpp is the
//            line-faithful decompiler mirror.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Vtable method on a host object: resolve optional related entity from +0x18,
//   resolve local player via FUN_00578270 + vfunc +0x210, apply TFID/phys rebind
//   (Object_SetTFID_ApplyPhysMode_Rebind), set selection / flags, construct a
//   0x2c CVOGHBBase action (FUN_006264e0), enqueue + Start when owner bound,
//   always run FUN_00578b30 fire-tail.
//
// ABI:
//   __thiscall (ECX = host; Ghidra surface __fastcall); MSVC SEH; void; plain RET.
//
// RELATED (sealed peers):
//   FUN_004c4880 = Object_SetTFID_ApplyPhysMode_Rebind (W26-F; sole caller site)
//   FUN_0053d970 = Object_SetPhysBodyTypeIfNotReady_Inferred
//   FUN_005172d0 = Object_SetSelectedTarget
//   CVOGHBList_Enqueue / CVOGHBBase_Start
// =============================================================================

#include <cstdint>

struct CVOGHBBase {
  void *pOwnerObject;
  // remaining fields unresolved
};

extern void *ExceptionList;
extern uint8_t LAB_009a8b27;

void FUN_0053d970(int mode);
int FUN_00578270(void);
void FUN_004c4880(int obj_plus_tfid_this /*thiscall*/, /*src*/ int src_expr);
void FUN_0051f890(int flag);
void Object_SetSelectedTarget(void *player_obj, void *related_obj, void *residual);
void *operator_new(uint32_t size);
CVOGHBBase *FUN_006264e0(int host_plus_24, int player_obj, int host);
void CVOGHBList_Enqueue(void *list, CVOGHBBase *action);
void CVOGHBBase_Start(CVOGHBBase *action);
void FUN_00578b30(void);

// MSVC thiscall helper typedef used for vtable dispatch surfaces
typedef int (*code)(...);

// Ghidra surface: __fastcall; machine: thiscall ECX=host
void __fastcall Object_ActivatePlayerEnqueueHB_Inferred(int param_1)
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
  if (*reinterpret_cast<int **>(param_1 + 0x18) == nullptr) {
    iVar1 = 0;
    ExceptionList = &pvStack_c;
  } else {
    ExceptionList = &pvStack_c;
    iVar1 = (**(code **)(**reinterpret_cast<int **>(param_1 + 0x18) + 0x214))();
    if (iVar1 != 0) {
      FUN_0053d970(0);
    }
  }
  iVar2 = FUN_00578270();
  if (iVar2 != 0) {
    piVar3 = reinterpret_cast<int *>(FUN_00578270());
    iVar2 = (**(code **)(*piVar3 + 0x210))(0);
    if (iVar2 != 0) {
      FUN_004c4880(*reinterpret_cast<int *>(*reinterpret_cast<int *>(iVar2 + 4) + 4) + 0x164 +
                   iVar2);
      FUN_0051f890(1);
      if (*reinterpret_cast<float *>(param_1 + 0x184) != 0.0f) {
        *reinterpret_cast<uint8_t *>(iVar2 + 0x6ba) = 1;
      }
      if (*reinterpret_cast<int *>(iVar2 + 0x250) != 0) {
        if (*reinterpret_cast<float *>(param_1 + 0x188) == 0.0f) {
          (**(code **)(*reinterpret_cast<int *>(
                           *reinterpret_cast<int *>(*reinterpret_cast<int *>(iVar2 + 4) + 4) + 4 +
                           iVar2) +
                       0x188))(4);
        } else {
          (**(code **)(*reinterpret_cast<int *>(*reinterpret_cast<int *>(iVar2 + 0x250) + 0x40) +
                       0x1c))(0);
          (**(code **)(**reinterpret_cast<int **>(iVar2 + 0x250) + 4))();
          *reinterpret_cast<uint8_t *>(*reinterpret_cast<int *>(iVar2 + 0x250) + 0x101) = 1;
        }
      }
      if (iVar1 == 0) {
        pvVar4 = nullptr;
      } else {
        pvVar4 = reinterpret_cast<void *>(
            *reinterpret_cast<int *>(*reinterpret_cast<int *>(iVar1 + 4) + 4) + 4 + iVar1);
      }
      Object_SetSelectedTarget(
          reinterpret_cast<void *>(
              *reinterpret_cast<int *>(*reinterpret_cast<int *>(iVar2 + 4) + 4) + 4 + iVar2),
          pvVar4, unaff_ESI);
      *reinterpret_cast<uint8_t *>(iVar2 + 0xd78) = 1;
      pvVar4 = operator_new(0x2c);
      uStack_4 = 0;
      if (pvVar4 == nullptr) {
        pAction = nullptr;
      } else {
        pAction = FUN_006264e0(
            param_1 + 0x24,
            *reinterpret_cast<int *>(*reinterpret_cast<int *>(iVar2 + 4) + 4) + 4 + iVar2,
            param_1);
      }
      uStack_4 = 0xffffffffu;
      if (pAction->pOwnerObject != nullptr) {
        *reinterpret_cast<CVOGHBBase **>(param_1 + 0x6c4) = pAction;
        CVOGHBList_Enqueue(
            *reinterpret_cast<void **>(
                *reinterpret_cast<int *>(
                    *reinterpret_cast<int *>(*reinterpret_cast<int *>(iVar2 + 4) + 4) + 0xa8 +
                    iVar2) +
                0xe4ec),
            pAction);
        CVOGHBBase_Start(pAction);
      }
      *reinterpret_cast<uint8_t *>(iVar2 + 0x6bb) = 0;
    }
  }
  FUN_00578b30();
  ExceptionList = pvStack_c;
  return;
}

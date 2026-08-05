// =============================================================================
// FUN_0055fa40  (alias of WorldObj_BindLinks_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0055fa40
// Address:   0x0055fa40  (autoassault.exe, image base 0x400000)
// System:    world-object / phys bind
// Generated: 2026-07-29 W26-E dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// =============================================================================

// Twin named clean: WorldObj_BindLinks_Inferred.cpp
// Ghidra symbol retained for scaffold compatibility.

#include <cstdint>

extern float DAT_00a0f298;
extern int *DAT_00b05060;
extern void *PTR_FUN_009d2820;

extern void __thiscall FUN_0062d960(void *scratch, uint32_t field);
extern void __thiscall FUN_006297e0(void *pose, float scale, int a, int b);
extern void FUN_006caaa0(void *pose, float scale, int a, int b, int ctx);
extern void __fastcall FUN_0055f4c0(void *container);

void __thiscall FUN_0055fa40(int param_1, int param_2)
{
  int iVar1;
  int iVar2;
  float fVar3;
  uint8_t auStack_6c[12];
  uint8_t local_60[20];
  void **ppuStack_4c;
  uint32_t *puStack_48;
  uint8_t *puStack_44;
  int iStack_40;
  int iStack_3c;
  uint8_t auStack_38[52];

  if (*(int *)(param_2 + 0xc) != 0) {
    FUN_0062d960(/*scratch*/, *(uint32_t *)(param_1 + 0x234));
    fVar3 = *(float *)(*(int *)(param_1 + 0xcc) + 8) * DAT_00a0f298;
    iVar1 = *(int *)(param_2 + 0x14) + 0x20;
    (**(void (**)(int, float, void *))(**(int **)(param_2 + 0xc) + 0x18))(
        iVar1, fVar3, local_60);
    (**(void (**)(int, void *, void *))(**(int **)(param_1 + 0xc4) + 4))(
        param_2 + 0x1c, auStack_6c, nullptr);
    if (0 < (int)fVar3) {
      if (*(char *)(param_2 + 0x40) == '\0') {
        FUN_006297e0(reinterpret_cast<void *>(iVar1), fVar3, 0, 0);
      } else {
        puStack_44 = auStack_38;
        ppuStack_4c = &PTR_FUN_009d2820;
        iStack_40 = 0;
        iStack_3c = -0x7ffffffc;
        *(void ****)(*(int *)(param_1 + 0x138) + 0x24) = &ppuStack_4c;
        if (*(int *)(param_1 + 0xd0) == 0) {
          iVar2 = 0;
        } else {
          iVar2 = *(int *)(param_1 + 0xd0) + 8;
        }
        puStack_48 = (uint32_t *)(param_2 + 0xc);
        FUN_006caaa0(reinterpret_cast<void *>(iVar1), fVar3, 0, 0, iVar2);
        *(int *)(*(int *)(param_1 + 0x138) + 0x24) =
            *(int *)(param_1 + 0x138) + 0x100;
        if (0 < iStack_40) {
          iVar1 = 0;
          do {
            iVar2 = *(int *)(puStack_44 + iVar1 * 4);
            FUN_006297e0(*(void **)(iVar2 + 0x80),
                         *reinterpret_cast<float *>(iVar2 + 0x84), 0, 0);
            iVar1 = iVar1 + 1;
            *(uint32_t *)(iVar2 + 0x84) = 0;
          } while (iVar1 < iStack_40);
        }
        if (-1 < iStack_3c) {
          (**(void (**)(void *, int, int))(*DAT_00b05060 + 0x14))(
              puStack_44, iStack_3c * 4, 0x12);
          FUN_0055f4c0(&ppuStack_4c);
          return;
        }
      }
    }
    FUN_0055f4c0(&ppuStack_4c);
  }
}

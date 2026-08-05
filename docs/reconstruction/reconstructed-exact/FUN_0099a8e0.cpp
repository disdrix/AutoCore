// =============================================================================
// FUN_0099a8e0  (scaffold twin of gfxVertexBufferImpl_Allocate)
// -----------------------------------------------------------------------------
// Stable ID: aa_0099a8e0
// Address:   0x0099a8e0  (autoassault.exe, image base 0x400000)
// System:    graphics / gfxVertexBufferImpl
// Generated: 2026-07-29 W22-L dual seal (scaffold keeps Ghidra name)
// Exactness: Behavior-preserving rewrite of decompiler + byte seal.
// Bit-for-bit vs retail EXE: DEFERRED.
// Canonical clean: gfxVertexBufferImpl_Allocate.cpp
// =============================================================================

#include <stdint.h>

extern void FUN_0099a820(void);
extern void FUN_00447ea0(void);
extern int FUN_00986a60(void *device, void *vb, uint32_t arg2);
extern void FUN_0044c3c0(int a, int b);
extern void vog_LogMessage(const char *file, int line, int level, const char *msg);

extern void *DAT_00d1f634;
extern int *DAT_00d1f614;

int __thiscall FUN_0099a8e0(void *param_1,
                            uint32_t param_2,
                            void *param_3,
                            uint32_t param_4,
                            void *param_5)
{
  int *piVar1;
  int iVar2;
  int iVar4;

  FUN_0099a820();
  *(uint32_t *)((uint8_t *)param_1 + 0x18) = param_2;
  *(void **)((uint8_t *)param_1 + 0x1c) = param_5;
  FUN_00447ea0();
  *(uint32_t *)((uint8_t *)param_1 + 0x34) =
      *(uint32_t *)((uint8_t *)param_3 + 0x10);
  *(uint32_t *)((uint8_t *)param_1 + 0x38) =
      *(uint32_t *)((uint8_t *)param_3 + 0x14);
  iVar4 = FUN_00986a60(DAT_00d1f634, param_1, param_4);
  if (iVar4 < 0) {
    *(uint32_t *)((uint8_t *)param_1 + 0x18) = 0;
    *(uint32_t *)((uint8_t *)param_1 + 0x1c) = 0;
    *(uint32_t *)((uint8_t *)param_1 + 0x34) = 0;
    *(uint32_t *)((uint8_t *)param_1 + 0x38) = 0;
    FUN_0044c3c0(0, 0);
    vog_LogMessage(
        "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxVertexBufferImpl.cpp",
        0x66, 3, "Failed to Allocate Vertex Buffer");
    iVar4 = -1;
  } else {
    if (param_5 != 0) {
      iVar4 = (*(int (__thiscall **)(void *, void *))(*(uint32_t *)param_5))(
          param_5, param_1);
    }
    iVar2 = (int)DAT_00d1f614;
    if (DAT_00d1f614 != 0) {
      *(int *)((uint8_t *)DAT_00d1f614 + 0x388) =
          *(int *)((uint8_t *)DAT_00d1f614 + 0x388) +
          *(int *)(*(int *)((uint8_t *)param_1 + 0x10) + 8) *
              *(int *)((uint8_t *)param_1 + 0x18);
      piVar1 = (int *)((uint8_t *)(intptr_t)iVar2 + 0x338);
      *piVar1 = *piVar1 + *(int *)((uint8_t *)param_1 + 0x18);
      piVar1 = (int *)((uint8_t *)(intptr_t)iVar2 + 0x334);
      *piVar1 = *piVar1 + 1;
      return iVar4;
    }
  }
  return iVar4;
}

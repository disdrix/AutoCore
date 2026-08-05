// =============================================================================
// FUN_00435df0  (alias plate — see stoChunkStreamWindow_Ensure.cpp)
// -----------------------------------------------------------------------------
// Stable ID: aa_00435df0
// Address:   0x00435df0–0x00435f24  (autoassault.exe, image base 0x400000)
// System:    storage / arda2 stoChunk
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29 (W18-A)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Canonical clean: reconstructed-exact/stoChunkStreamWindow_Ensure.cpp
// =============================================================================

#include <cstdint>
#include <cstring>

// Faithful decompiler-shaped body (types tightened; no modernization of arms).
// ABI: __thiscall, ret 4; EAX = last vtbl+0x14 call (callers test signed).

void __thiscall FUN_00435df0(uint32_t* param_1, size_t param_2)
{
  int iVar1;
  size_t sVar2;
  int* piVar3;
  size_t* psVar4;
  size_t _Size;
  size_t local_rem;

  sVar2 = param_2;
  iVar1 = (int)param_1[2];
  if (iVar1 <= (int)param_2) {
    if ((int)param_2 < (int)param_1[3] + iVar1) {
      _Size = (size_t)((int)param_1[3] - ((int)param_2 - iVar1));
      memmove(param_1 + 6, (void*)(((int)param_2 - iVar1) + 0x18 + (int)param_1), _Size);
      piVar3 = (int*)(param_1 + 4);
      param_1[2] = (uint32_t)sVar2;
      local_rem = (size_t)((int)param_1[5] - (int)sVar2);
      if ((int)((int)param_1[5] - (int)sVar2) <= *piVar3) {
        piVar3 = (int*)&local_rem;
      }
      iVar1 = *piVar3;
      param_1[3] = (uint32_t)iVar1;
      param_1[1] = 0;
      (**(int(__thiscall***)(void*, size_t, int))(*(int*)*param_1 + 4))(
          (void*)*param_1, _Size + sVar2, 0);
      (**(int(__thiscall***)(void*, void*, int))(*(int*)*param_1 + 0x14))(
          (void*)*param_1, (void*)(_Size + 0x18 + (int)param_1), iVar1 - (int)_Size);
      return;
    }
    if (iVar1 <= (int)param_2) goto LAB_00435ee4;
  }
  if (iVar1 <= (int)(param_1[4] + param_2)) {
    param_2 = (size_t)(((int)param_1[4] - iVar1) + (int)param_2);
    psVar4 = (size_t*)(param_1 + 3);
    if ((int)param_2 < (int)param_1[3]) {
      psVar4 = &param_2;
    }
    memmove((void*)((iVar1 - (int)sVar2) + 0x18 + (int)param_1), param_1 + 6, *psVar4);
    piVar3 = (int*)(param_1 + 4);
    param_1[2] = (uint32_t)sVar2;
    local_rem = (size_t)((int)param_1[5] - (int)sVar2);
    if ((int)((int)param_1[5] - (int)sVar2) <= *piVar3) {
      piVar3 = (int*)&local_rem;
    }
    param_1[3] = (uint32_t)*piVar3;
    param_1[1] = 0;
    (**(int(__thiscall***)(void*, size_t, int))(*(int*)*param_1 + 4))(
        (void*)*param_1, sVar2, 0);
    (**(int(__thiscall***)(void*, void*, int))(*(int*)*param_1 + 0x14))(
        (void*)*param_1, param_1 + 6, iVar1 - (int)sVar2);
    return;
  }
LAB_00435ee4:
  param_1[2] = (uint32_t)param_2;
  param_1[1] = 0;
  (**(int(__thiscall***)(void*, size_t, int))(*(int*)*param_1 + 4))(
      (void*)*param_1, param_2, 0);
  piVar3 = (int*)(param_1 + 4);
  local_rem = (size_t)((int)param_1[5] - (int)param_1[2]);
  if ((int)((int)param_1[5] - (int)param_1[2]) <= *piVar3) {
    piVar3 = (int*)&local_rem;
  }
  iVar1 = *piVar3;
  param_1[3] = (uint32_t)iVar1;
  (**(int(__thiscall***)(void*, void*, int))(*(int*)*param_1 + 0x14))(
      (void*)*param_1, param_1 + 6, iVar1);
  return;
}

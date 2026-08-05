// =============================================================================
// FUN_0092adf0  (scaffold twin of TargetFilter_FindNearestWorldObjByCbidList_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0092adf0
// Address:   0x0092adf0
// See named clean: TargetFilter_FindNearestWorldObjByCbidList_Inferred.cpp
// WQ8R-I 2026-08-04: twin kept for FUN_* path stability.
// =============================================================================

#include <cstdint>

extern "C" {
void FUN_004294f0();
int  FUN_004022a0(void *state, void **outObj);
void *FUN_00571010(int coidLo, int coidHi); // thiscall grid in ECX
void __stdcall LeaveCriticalSection(void *cs);
}

// EDI = filter ctx; ret 0x0C
std::uint32_t FUN_0092adf0(float *param_1, void **param_2, float *param_3)
{
  void *unaff_EDI = /* EDI */;
  void *local_18 = nullptr;
  std::uint32_t local_14[4] = {};
  local_14[0] = 0;

  FUN_004294f0();
  int iVar2 = FUN_004022a0(local_14, &local_18);
  int *piVar1 = reinterpret_cast<int *>(local_18);

  while (iVar2 == 0) {
    if (piVar1 != nullptr) {
      int *client = *reinterpret_cast<int **>(unaff_EDI);
      int *ch = *reinterpret_cast<int **>(reinterpret_cast<char *>(client) + 0xE98);
      int host = *reinterpret_cast<int *>(reinterpret_cast<char *>(ch) + 0x250);
      int selfAdj = 0;
      if (host != 0) {
        selfAdj = *reinterpret_cast<int *>(*reinterpret_cast<int *>(host + 4) + 4) + 4 + host;
      }
      // ECX = *(ch+0xCBC) for FindItemByCoid (bytes; not shown in old decompiler)
      if (piVar1[0x2b] != selfAdj
          && FUN_00571010(piVar1[0x58], piVar1[0x59]) == nullptr
          && *reinterpret_cast<int *>(reinterpret_cast<char *>(unaff_EDI) + 0x28) > 0) {
        int *local_1c =
            reinterpret_cast<int *>(reinterpret_cast<char *>(unaff_EDI) + 0x2C);
        int i = 0;
        int count = *reinterpret_cast<int *>(reinterpret_cast<char *>(unaff_EDI) + 0x28);
        do {
          if (*local_1c == *reinterpret_cast<int *>(piVar1[0x2a] + 0x34)) {
            reinterpret_cast<void(__thiscall *)(int *)>(*reinterpret_cast<int *>(*piVar1 + 0x144))(
                piVar1);
            float fVar3 =
                (static_cast<float>(piVar1[0x22]) - param_1[2]) *
                    (static_cast<float>(piVar1[0x22]) - param_1[2]) +
                (static_cast<float>(piVar1[0x21]) - param_1[1]) *
                    (static_cast<float>(piVar1[0x21]) - param_1[1]) +
                (static_cast<float>(piVar1[0x20]) - param_1[0]) *
                    (static_cast<float>(piVar1[0x20]) - param_1[0]);
            if (fVar3 < *param_3) {
              *param_3 = fVar3;
              *param_2 = piVar1;
            }
          }
          ++local_1c;
          ++i;
        } while (i < count);
      }
    }
    iVar2 = FUN_004022a0(local_14, &local_18);
    piVar1 = reinterpret_cast<int *>(local_18);
  }

  int *client = *reinterpret_cast<int **>(unaff_EDI);
  int iVar2b = *reinterpret_cast<int *>(
      *reinterpret_cast<int *>(reinterpret_cast<char *>(client) + 0xD34) + 0x20);
  if (*reinterpret_cast<char *>(iVar2b + 0x28) != 0) {
    *reinterpret_cast<char *>(iVar2b + 0x28) = 0;
    LeaveCriticalSection(reinterpret_cast<void *>(iVar2b + 4));
  }
  return 1;
}

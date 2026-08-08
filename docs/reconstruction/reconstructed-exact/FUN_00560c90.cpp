// =============================================================================
// FUN_00560c90  (clean twin of LthkWorld_GetPenetrations_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00560c90
// Address:   0x00560c90  (autoassault.exe, image base 0x400000)
// Range:     0x00560c90–0x00560e33 inclusive (420 B / 0x1A4)
// System:    interaction-activation
// Generated: 2026-08-05 R12-024 dual seal
// Canonical clean: LthkWorld_GetPenetrations_Inferred.cpp
// Exactness: Behavior-preserving; assembly-corrected filter host.
// Bit-for-bit vs retail EXE: DEFERRED.
// Runtime Confirmed: OPEN.
// =============================================================================

#include <cstdint>

extern uint32_t *DAT_00bc5644;
extern uint32_t *DAT_00bc5648;
extern uint32_t *DAT_00b05060;
extern const char DAT_009d2840[];
extern const char DAT_009d2830[];
extern const char DAT_009d282c[];

// Ghidra symbol name twin — same ABI/CF as LthkWorld_GetPenetrations_Inferred.
void __thiscall FUN_00560c90(
    int param_1 /* ECX self */,
    int *param_2 /* query_obj */,
    uint32_t param_3 /* user_ctx */,
    int *param_4 /* dispatch_table */)
{
  uint8_t local_440[12];
  uint8_t auStack_420[1052];
  uint8_t auStack_44c[8];
  char filter_byte = 0;

  void *puStack_42c = auStack_420;
  int iStack_count = 0;
  int iStack_cap = static_cast<int>(0x80000080u);
  void *iStack_434 = puStack_42c;

  if (DAT_00bc5644 < DAT_00bc5648) {
    *DAT_00bc5644 = reinterpret_cast<uint32_t>(
        reinterpret_cast<uintptr_t>(DAT_009d2840));
    DAT_00bc5644[1] = 0;
    DAT_00bc5644 += 3;
  }

  if (param_4 == nullptr) {
    param_4 = *reinterpret_cast<int **>(param_1 + 0xCC);
  }

  // shape extents vcall +0x18
  {
    int *inner = reinterpret_cast<int *>(*param_2);
    auto **vtbl = reinterpret_cast<void **>(*inner);
    auto fn = reinterpret_cast<void(__stdcall *)(int, int, void *)>(vtbl[6]);
    fn(param_2[2] + 0x20, param_4[2], local_440);
  }

  // broadphase vcall *(self+0xC4) +0x24
  {
    int *collector = *reinterpret_cast<int **>(param_1 + 0xC4);
    auto **vtbl = reinterpret_cast<void **>(*collector);
    struct Triad { void *b; int c; int cap; } t{puStack_42c, iStack_count, iStack_cap};
    auto fn = reinterpret_cast<void(__thiscall *)(int *, void *, Triad *)>(vtbl[9]);
    fn(collector, auStack_44c, &t);
    iStack_434 = t.b;
    iStack_count = t.c;
    iStack_cap = t.cap;
    puStack_42c = t.b;
  }

  int iVar2;
  {
    int *inner = reinterpret_cast<int *>(*param_2);
    auto **vtbl = reinterpret_cast<void **>(*inner);
    auto fn = reinterpret_cast<int(__thiscall *)(int *)>(vtbl[5]);
    iVar2 = fn(inner);
  }

  if (DAT_00bc5644 < DAT_00bc5648) {
    *DAT_00bc5644 = reinterpret_cast<uint32_t>(
        reinterpret_cast<uintptr_t>(DAT_009d2830));
    DAT_00bc5644[1] = 0;
    DAT_00bc5644 += 3;
  }

  if (iStack_count - 1 >= 0) {
    int *piVar5 = reinterpret_cast<int *>(
        reinterpret_cast<uint8_t *>(iStack_434) + 4);
    int iVar7 = iStack_count;
    do {
      int *piVar6 = (*piVar5 == 0)
                        ? nullptr
                        : reinterpret_cast<int *>(*piVar5 - 0x10);

      // CORRECTED: self = param_1 (not unaff_EBX)
      if (param_2 != piVar6 && piVar6 != nullptr) {
        int *filter_host = *reinterpret_cast<int **>(param_1 + 0xD0);
        int *filter_sub = filter_host + 2;
        auto **fvtbl = reinterpret_cast<void **>(*filter_sub);
        auto filter = reinterpret_cast<char *(__thiscall *)(
            int *, char *, int *, int *)>(fvtbl[0]);
        char *pcVar3 = filter(filter_sub, &filter_byte, param_2, piVar6);

        if (pcVar3 != nullptr && *pcVar3 != '\0' &&
            reinterpret_cast<int *>(*piVar6) != nullptr) {
          int *cand_inner = reinterpret_cast<int *>(*piVar6);
          auto **cvtbl = reinterpret_cast<void **>(*cand_inner);
          auto type_fn =
              reinterpret_cast<int(__thiscall *)(int *)>(cvtbl[5]);
          int iVar4 = type_fn(cand_inner);

          auto **dvtbl = reinterpret_cast<void **>(*param_4);
          auto handler = reinterpret_cast<void(__cdecl *)(
              int *, int *, int *, uint32_t)>(
              dvtbl[0x118c / 4 + (iVar2 * 0x20 + iVar4)]);
          handler(param_2, piVar6, param_4, param_3);
        }
      }
      piVar5 += 2;
      iVar7 -= 1;
    } while (iVar7 != 0);
  }

  if (DAT_00bc5644 < DAT_00bc5648) {
    *DAT_00bc5644 = reinterpret_cast<uint32_t>(
        reinterpret_cast<uintptr_t>(DAT_009d282c));
    DAT_00bc5644[1] = 0;
    DAT_00bc5644 += 3;
  }

  if (iStack_cap >= 0) {
    auto **avtbl = reinterpret_cast<void **>(*DAT_00b05060);
    auto free_fn = reinterpret_cast<void(__thiscall *)(
        uint32_t *, void *, int, int)>(avtbl[5]);
    free_fn(DAT_00b05060, iStack_434, (iStack_cap & 0x7fffffff) * 8, 0x12);
  }
}

// =============================================================================
// FUN_0055ff20  — clean twin of PhysMgr_AttachBody_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0055ff20
// Address:   0x0055ff20
// Dual:      W29-R 2026-07-29
// See:       PhysMgr_AttachBody_Inferred.cpp for named clean.
// =============================================================================

#include <cstdint>

extern "C" void __thiscall FUN_0062d960(std::uint32_t *desc /*ECX*/, std::uint32_t count);
extern "C" void __fastcall FUN_0055f4c0(std::uint32_t *desc /*ECX*/);
extern "C" void FUN_006cad30(void *pairs, int count);
extern "C" void __thiscall FUN_006caaa0(
    int handler_table /*ECX*/,
    void *left_pairs, int left_count,
    void *right_pairs, int right_count,
    int predicate_or_ctx);
extern "C" void FUN_0062a4d0(int manager, int *body);
extern "C" void FUN_005b3370(int *vec_desc, int stride);

int *__thiscall FUN_0055ff20(int param_1 /*ECX*/, int *param_2 /*stack*/)
{
  int *piVar1;
  int iVar2;
  int unaff_EDI; // pair count from vcall outs
  std::uint8_t *puVar3;
  std::uint8_t auStack_34[4];
  std::uint8_t local_30[44];
  std::uint32_t wl[5];

  param_2[2] = param_1;
  FUN_0062d960(wl, *reinterpret_cast<std::uint32_t *>(param_1 + 0x234));
  puVar3 = local_30;
  (**(void (***)(std::uint8_t *))(*param_2 + 0x18))(puVar3);

  if (param_2 == reinterpret_cast<int *>(-0xc)) {
    piVar1 = nullptr;
  } else {
    piVar1 = param_2 + 7;
  }
  (**(void (***)(int *, void *, void *))(
      **reinterpret_cast<int **>(param_1 + 0xc4) + 4))(
      piVar1, auStack_34, &unaff_EDI);

  iVar2 = *reinterpret_cast<int *>(param_1 + 0x130);
  *reinterpret_cast<int *>(param_1 + 0x130) = iVar2 + 1;
  param_2[8] = iVar2;

  if (unaff_EDI != 0) {
    FUN_006cad30(puVar3, unaff_EDI);
    if (*reinterpret_cast<int *>(param_1 + 0xd0) == 0) {
      iVar2 = 0;
    } else {
      iVar2 = *reinterpret_cast<int *>(param_1 + 0xd0) + 8;
    }
    FUN_006caaa0(*reinterpret_cast<int *>(param_1 + 0x138), puVar3, unaff_EDI,
                 nullptr, 0, iVar2);
  }

  *reinterpret_cast<std::int16_t *>(reinterpret_cast<char *>(param_2) + 6) =
      static_cast<std::int16_t>(
          *reinterpret_cast<std::int16_t *>(reinterpret_cast<char *>(param_2) + 6) +
          1);

  if (*reinterpret_cast<std::uint32_t *>(param_1 + 0x124) ==
      (*reinterpret_cast<std::uint32_t *>(param_1 + 0x128) & 0x7fffffffu)) {
    FUN_005b3370(reinterpret_cast<int *>(param_1 + 0x120), 4);
  }
  *reinterpret_cast<int **>(
      *reinterpret_cast<int *>(param_1 + 0x120) +
      *reinterpret_cast<int *>(param_1 + 0x124) * 4) = param_2;
  *reinterpret_cast<int *>(param_1 + 0x124) =
      *reinterpret_cast<int *>(param_1 + 0x124) + 1;

  FUN_0062a4d0(param_1, param_2);
  FUN_0055f4c0(wl);
  return param_2;
}

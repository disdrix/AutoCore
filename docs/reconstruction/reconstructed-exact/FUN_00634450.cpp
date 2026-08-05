// =============================================================================
// FUN_00634450  — clean twin of PhysHost_ReconcileLinkPairs_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00634450
// Address:   0x00634450
// Dual:      W29-R 2026-07-29
// See:       PhysHost_ReconcileLinkPairs_Inferred.cpp for named clean.
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
extern "C" void FUN_005fff20(void);

void __thiscall FUN_00634450(int param_1 /*ECX*/, std::uint32_t param_2 /*stack*/)
{
  int iVar1;
  std::uint32_t uVar2;
  std::uint8_t *puVar3;
  int local_2c;
  std::uint32_t local_28;
  int iStack_24;
  std::uint8_t local_14[20];
  std::uint32_t wl_a[5];
  std::uint32_t wl_b[5];
  int mgr;

  if (*reinterpret_cast<int *>(param_1 + 8) != 0) {
    mgr = *reinterpret_cast<int *>(param_1 + 8);
    FUN_0062d960(wl_a, *reinterpret_cast<std::uint32_t *>(mgr + 0x238));
    FUN_0062d960(wl_b, *reinterpret_cast<std::uint32_t *>(mgr + 0x238));

    if (param_1 == -0xc) {
      local_2c = 0;
    } else {
      local_2c = param_1 + 0x1c;
    }
    puVar3 = local_14;
    uVar2 = 1; // vcall flag residual on decompiler surface
    (**(void (***)(int *, std::uint32_t, std::uint32_t, std::uint8_t *,
                   std::uint32_t *))(
        **reinterpret_cast<int **>(mgr + 0xc4) + 0x14))(
        &local_2c, param_2, uVar2, puVar3, &local_28);

    // Gate: either list non-empty (decompiler: iStack_24 || puVar3)
    if ((iStack_24 != 0) || (puVar3 != nullptr)) {
      FUN_006cad30(reinterpret_cast<void *>(static_cast<std::uintptr_t>(local_28)),
                   iStack_24);
      FUN_006cad30(puVar3, static_cast<int>(uVar2)); // residual pairing — see named clean

      if (*reinterpret_cast<int *>(mgr + 0xd0) == 0) {
        iVar1 = 0;
      } else {
        iVar1 = *reinterpret_cast<int *>(mgr + 0xd0) + 8;
      }
      // Machine ECX = *(mgr+0x138)
      FUN_006caaa0(*reinterpret_cast<int *>(mgr + 0x138),
                   reinterpret_cast<void *>(static_cast<std::uintptr_t>(local_28)),
                   iStack_24, puVar3, static_cast<int>(uVar2), iVar1);
      FUN_005fff20(); // EAX = param_1+0x3c
    }
    FUN_0055f4c0(wl_b);
    FUN_0055f4c0(wl_a);
  }
}

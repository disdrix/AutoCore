// =============================================================================
// FUN_00792c20 — twin of CNDUIDialog_CompleteDtor (aa_00792c20)
// See: CNDUIDialog_CompleteDtor.cpp for named plate + member-offset map.
// Wave: WQ9K-G 2026-08-05
// NOTE: Decompiler historically ends at operator_delete(member); bytes continue
//       through zero +0x4e0 and CALL FUN_007b5be0 to RET @ 0x00792d12.
// =============================================================================

#include <cstdint>

extern "C" void __fastcall FUN_007917c0(void* self);
extern "C" void __fastcall FUN_00415e90(void);
extern "C" void __cdecl operator_delete(void* p);
extern "C" void __fastcall FUN_007b5be0(void* self);
extern "C" void* PTR_FUN_00a98f44;

static inline void scalar_delete_owned(void** slot)
{
  void* p = *slot;
  if (p != nullptr) {
    auto** vtbl = *reinterpret_cast<void***>(p);
    auto fn = reinterpret_cast<void*(__thiscall*)(void*, int)>(vtbl[0]);
    fn(p, 1);
  }
  *slot = nullptr;
}

extern "C" void __fastcall FUN_00792c20(void* self)
{
  auto* base = reinterpret_cast<std::uint8_t*>(self);
  *reinterpret_cast<void**>(self) = &PTR_FUN_00a98f44;
  FUN_007917c0(self);
  scalar_delete_owned(reinterpret_cast<void**>(base + 0x4c0));
  scalar_delete_owned(reinterpret_cast<void**>(base + 0x4c8));
  scalar_delete_owned(reinterpret_cast<void**>(base + 0x4cc));
  scalar_delete_owned(reinterpret_cast<void**>(base + 0x4d0));
  scalar_delete_owned(reinterpret_cast<void**>(base + 0x4d4));
  scalar_delete_owned(reinterpret_cast<void**>(base + 0x4d8));
  // FUN_00415e90 with ESI = self+0x4dc
  operator_delete(*reinterpret_cast<void**>(base + 0x4e0));
  *reinterpret_cast<void**>(base + 0x4e0) = nullptr;
  FUN_007b5be0(self);
}

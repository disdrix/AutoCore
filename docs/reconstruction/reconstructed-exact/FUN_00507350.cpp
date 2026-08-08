// =============================================================================
// FUN_00507350  (scaffold twin of VOGPhysics_QueryObject_Dtor_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00507350
// Address:   0x00507350  (autoassault.exe, image base 0x400000)
// System:    interaction-activation
// Generated: 2026-08-05 R13-028 dual seal
// Exactness: Behavior-preserving rewrite. Prefer named clean source.
// Bit-for-bit vs retail EXE: DEFERRED.
// Runtime Confirmed: OPEN.
// =============================================================================

#include <cstdint>

extern uint32_t PTR_FUN_009cd99c;
extern uint32_t PTR_FUN_009d81e8;
extern uint32_t PTR_LAB_009cc290;
extern uint32_t *DAT_00b05060;
void __thiscall FUN_005ffdb0(uint32_t *self, int set_bit);

// Canonical: VOGPhysics_QueryObject_Dtor_Inferred
void __thiscall FUN_00507350(uint32_t *param_1 /* ECX */)
{
  uint32_t *puVar1 = reinterpret_cast<uint32_t *>(
      static_cast<uintptr_t>(param_1[3]));

  *param_1 = reinterpret_cast<uint32_t>(
      reinterpret_cast<uintptr_t>(&PTR_FUN_009cd99c));

  if (puVar1 != nullptr) {
    int16_t *rc = reinterpret_cast<int16_t *>(
        reinterpret_cast<uint8_t *>(puVar1) + 6);
    *rc = static_cast<int16_t>(*rc - 1);
    if (*rc == 0) {
      auto **vtbl = reinterpret_cast<void ***>(puVar1);
      auto fn = reinterpret_cast<void(__stdcall *)(int)>(**vtbl);
      fn(1);
    }
  }

  if (static_cast<int32_t>(param_1[0xe]) >= 0) {
    uint32_t nbytes =
        (param_1[0xe] & 0x7FFFFFFFu) * 8u;
    auto **alloc_vtbl = reinterpret_cast<void ***>(*DAT_00b05060);
    auto free_fn = reinterpret_cast<void(__stdcall *)(uint32_t, uint32_t, int)>(
        alloc_vtbl[0x14 / 4]);
    free_fn(param_1[0xc], nbytes, 0x12);
  }

  *param_1 = reinterpret_cast<uint32_t>(
      reinterpret_cast<uintptr_t>(&PTR_FUN_009d81e8));

  uint16_t flags = *reinterpret_cast<uint16_t *>(param_1 + 1);
  if (static_cast<int16_t>(flags) < 0) {
    flags = static_cast<uint16_t>(flags & 0x7FFFu);
    *reinterpret_cast<uint16_t *>(param_1 + 1) = flags;
    FUN_005ffdb0(param_1, 0);
  }

  *param_1 = reinterpret_cast<uint32_t>(
      reinterpret_cast<uintptr_t>(&PTR_LAB_009cc290));
}

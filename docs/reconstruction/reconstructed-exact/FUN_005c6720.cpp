// =============================================================================
// FUN_005c6720  (twin of TrackPayload_MatchObject_TfidOrPtrIdentity_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_005c6720
// Address:   0x005c6720  (autoassault.exe, image base 0x400000)
// Body:      0x005c6720–0x005c6788 exclusive (104 B); pad CC
// Wave:      W38-S (2026-08-04)
// Exactness: Behavior-preserving rewrite. Bit-for-bit: DEFERRED.
// =============================================================================

#include <cstdint>

// __thiscall; ECX = payload; stack (object*); bool AL; ret 4
extern "C" uint8_t __thiscall FUN_005c6720(void *param_1 /* payload */, void *param_2 /* object */)
{
  const uint32_t plo = *reinterpret_cast<uint32_t *>(static_cast<char *>(param_1) + 0x18);
  const uint32_t phi = *reinterpret_cast<uint32_t *>(static_cast<char *>(param_1) + 0x1c);
  const int adj = *reinterpret_cast<int *>(*reinterpret_cast<int *>(static_cast<char *>(param_2) + 4) + 4);
  auto *const ot = reinterpret_cast<uint32_t *>(static_cast<char *>(param_2) + adj + 0x164);

  if ((plo & phi) == 0xFFFFFFFFu && (ot[0] & ot[1]) == 0xFFFFFFFFu) {
    return *reinterpret_cast<void **>(static_cast<char *>(param_1) + 0x10) == param_2 ? 1u : 0u;
  }

  if (ot[0] == plo && ot[1] == phi &&
      *reinterpret_cast<int8_t *>(reinterpret_cast<char *>(ot) + 8) ==
          *reinterpret_cast<int8_t *>(static_cast<char *>(param_1) + 0x20)) {
    return 1u;
  }
  return 0u;
}

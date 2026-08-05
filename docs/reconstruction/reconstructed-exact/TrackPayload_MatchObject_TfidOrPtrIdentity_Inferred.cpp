// =============================================================================
// TrackPayload_MatchObject_TfidOrPtrIdentity_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005c6720
// Address:   0x005c6720  (autoassault.exe, image base 0x400000)
// Body:      0x005c6720–0x005c6788 exclusive (104 B / 0x68); pad CC
// System:    track-manager payload match
// Wave:      W38-S dual A/B (2026-08-04)
// Exactness: Behavior-preserving rewrite of decompile + read_memory CF/ABI.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Match a track-list payload against a live object.
//   - If both payload TFID and object TFID are fully invalid (lo&hi == -1):
//       compare payload's stored object pointer (+0x10) to the object arg.
//   - Else: compare TFID triple (i32 lo, i32 hi, i8 global) stored on the
//       payload (+0x18/+0x1c/+0x20) to the object's TFID at
//       object + *(*(object+4)+4) + 0x164  (same 9-byte equality as
//       TFID_EqualsObjectId @ 0x00404aa0).
//
// ABI: __thiscall; ECX = payload; stack (object*); returns bool in AL; ret 4.
// Leaf: no callees.
// Callers: FUN_004bfd10 (untrack), FUN_004bfdb0 (set payload+0x51).
// =============================================================================

#include <cstdint>

struct Tfid9 {
  uint32_t lo;
  uint32_t hi;
  int8_t global;
  // pad not compared
};

// Returns true if payload matches object.
extern "C" uint8_t __thiscall TrackPayload_MatchObject_TfidOrPtrIdentity_Inferred(
    void *payload,
    void *object)
{
  auto *const p = static_cast<uint8_t *>(payload);
  auto *const o = static_cast<uint8_t *>(object);

  const uint32_t payload_lo = *reinterpret_cast<uint32_t *>(p + 0x18);
  const uint32_t payload_hi = *reinterpret_cast<uint32_t *>(p + 0x1c);
  const int8_t payload_g = *reinterpret_cast<int8_t *>(p + 0x20);

  // MI / secondary-base adjustment used by client object TFID locate.
  const int adj = *reinterpret_cast<int *>(*reinterpret_cast<int *>(o + 4) + 4);
  auto *const obj_tfid = reinterpret_cast<Tfid9 *>(o + adj + 0x164);

  if ((payload_lo & payload_hi) == 0xFFFFFFFFu &&
      (obj_tfid->lo & obj_tfid->hi) == 0xFFFFFFFFu) {
    return *reinterpret_cast<void **>(p + 0x10) == object ? 1u : 0u;
  }

  if (obj_tfid->lo == payload_lo && obj_tfid->hi == payload_hi &&
      obj_tfid->global == payload_g) {
    return 1u;
  }
  return 0u;
}

// Ghidra twin symbol
extern "C" uint8_t __thiscall FUN_005c6720(void *payload, void *object)
{
  return TrackPayload_MatchObject_TfidOrPtrIdentity_Inferred(payload, object);
}

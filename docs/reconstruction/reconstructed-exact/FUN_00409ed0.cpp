// =============================================================================
// FUN_00409ed0  (scaffold twin — prefer SkillSet_CopyBackward_0x18.cpp)
// -----------------------------------------------------------------------------
// Stable ID: aa_00409ed0
// Address:   0x00409ed0–0x00409f0a inclusive (59 B; autoassault.exe base 0x400000)
// System:    skills-abilities / SkillSet vector
// Generated: 2026-08-05 MEGA-054 OWN dual (ABI-corrected twin of clean named)
// Exactness: Behavior-preserving; decompiler void/phantom filled from bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// Canonical: reconstructed-exact/SkillSet_CopyBackward_0x18.cpp
// =============================================================================

#include <cstdint>

// EAX=dest_end, ECX=src_end, EDX=src_begin; returns EAX=dest_begin; RET 0
extern "C" void *FUN_00409ed0(void *src_end /*ECX*/,
                              void *src_begin /*EDX*/,
                              void *dest_end /*EAX — register, not stack*/)
{
  // Note: C prototype cannot express EAX arg/return portably.
  // Body mirrors sealed CF for documentation; see named clean for struct form.
  std::uint32_t *s = static_cast<std::uint32_t *>(src_end);
  std::uint32_t *b = static_cast<std::uint32_t *>(src_begin);
  std::uint32_t *d = static_cast<std::uint32_t *>(dest_end);

  if (b == s) {
    return d;
  }

  do {
    s -= 6;
    d -= 6;
    d[0] = s[0];
    d[1] = s[1];
    d[2] = s[2];
    d[3] = s[3];
    d[4] = s[4];
    d[5] = s[5];
  } while (s != b);

  return d;
}

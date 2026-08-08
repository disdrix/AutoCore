// =============================================================================
// FUN_00756be0  (twin of gfxUIWindow_DetachParent_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00756be0
// Address:   0x00756be0–0x00756c44 inclusive (101 B / 0x65)
// Module:    autoassault.exe (image base 0x400000)
// System:    gfxUIWindow / CNDUIDialog child-list unlink
// Generated: 2026-08-05 MEGA-121 dual seal (replaces 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Canonical named unit: gfxUIWindow_DetachParent_Inferred.cpp
// Scaffold Named_CalleeOf_Named_gfxUIWindow_00756be0.cpp RETIRED.

#include <cstdint>
#include <cstring>

// __thiscall: ECX = parent; stack = child*; RET 4
// 0 = erased from parent vector + cleared child+0x88; 0xffffffff = not found
extern "C" std::uint32_t __thiscall FUN_00756be0(void *parent, void *child)
{
  auto *const p = reinterpret_cast<std::uint8_t *>(parent);
  auto *const c = reinterpret_cast<std::uint8_t *>(child);

  auto **end = *reinterpret_cast<void ***>(p + 0x98);
  auto **it  = *reinterpret_cast<void ***>(p + 0x94);

  if (it != end) {
    do {
      if (*it == child) {
        break;
      }
      ++it;
    } while (it != end);

    if (it != end) {
      void **const found = it;
      void **const src   = found + 1;
      const auto end_bytes =
          reinterpret_cast<std::uintptr_t>(
              *reinterpret_cast<void ***>(p + 0x98));
      const auto src_bytes = reinterpret_cast<std::uintptr_t>(src);
      const std::size_t nbytes =
          static_cast<std::size_t>(((end_bytes - src_bytes) >> 2) * 4);

      std::memmove(found, src, nbytes);
      *reinterpret_cast<std::uint32_t *>(p + 0x98) =
          *reinterpret_cast<std::uint32_t *>(p + 0x98) - 4;
      *reinterpret_cast<std::uint32_t *>(c + 0x88) = 0;
      return 0;
    }
  }

  return 0xffffffffu;
}

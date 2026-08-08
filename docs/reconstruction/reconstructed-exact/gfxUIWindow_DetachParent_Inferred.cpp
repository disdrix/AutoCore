// =============================================================================
// gfxUIWindow_DetachParent_Inferred  (FUN_00756be0)
// -----------------------------------------------------------------------------
// Stable ID: aa_00756be0
// Address:   0x00756be0–0x00756c44 inclusive (101 B / 0x65); pad CC after
// Module:    autoassault.exe (image base 0x400000)
// System:    gfxUIWindow / CNDUIDialog child-list unlink (skills-abilities UI)
// Generated: 2026-08-05 MEGA-121 dual seal
//            (decompile + disassemble_function + read_memory + callers/xrefs
//             + assembly_context @ dualed 00759de0 / 007917c0 sites)
// Exactness: Behavior-preserving rewrite from decompile + body bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: Detach a child window from its parent's child-pointer vector.
//
// Parent (this / ECX) owns a dense pointer vector:
//   begin @ +0x94, end @ +0x98  (element size 4).
// Child (stack arg) carries a parent back-pointer at +0x88.
//
// On success: erase the matching child* by memmove-compact, shrink end by 4,
//             zero child+0x88, return 0.
// On miss:    return 0xffffffff (vector empty or pointer not present).
//
// Dualed parents:
//   - gfxUIWindow_CompleteDtor (0x00759de0) — if self+0x88: ECX=parent, PUSH self
//   - CNDUIDialog_TeardownChildHash_Inferred (0x007917c0) — ECX=dialog, PUSH child
// Peer residual: FUN_00756c50 (attach/reparent; calls this to leave old parent).
//
// Does NOT free child or parent. Does NOT walk remaining children.
// Product method demangle open → _Inferred. Class family sealed via dualed
// gfxUIWindow.cpp complete-dtor path string on 0x00759de0.

#include <cstdint>
#include <cstring>

// Layout fragment shared with dualed gfxUIWindow_CompleteDtor.
struct GfxUIWindow_ChildLinkView {
  // ... vtbl and fields through +0x87 ...
  // std::uint32_t parent_link; // +0x88  (this field on the *child*)
  // ...
  // GfxUIWindow** children_begin; // +0x94  (on the *parent*)
  // GfxUIWindow** children_end;   // +0x98
};

// __thiscall: ECX = parent; stack = child*; RET 4
// returns 0 on erase, 0xffffffff if not found
extern "C" std::uint32_t __thiscall gfxUIWindow_DetachParent_Inferred(
    void *parent,
    void *child)
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
      // memmove(it, it+1, (end - (it+1)) * sizeof(void*))
      // Byte math mirrors SAR/ADD*2 sequence in body:
      //   size = ((end_bytes - (found+4)) >> 2) * 4
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

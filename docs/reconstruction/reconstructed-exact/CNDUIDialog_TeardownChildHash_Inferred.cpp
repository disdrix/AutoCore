// =============================================================================
// CNDUIDialog_TeardownChildHash_Inferred  (aa_007917c0)
// -----------------------------------------------------------------------------
// Address:   0x007917c0 – 0x007918e1 inclusive (290 B / 0x122)
//            autoassault.exe, image base 0x400000
// Wave:      WQ9L-I OWN-ONLY dual 2026-08-05
// Exactness: Behavior-preserving rewrite from decompile + disassemble_function
//            + read_memory + callers/xrefs.
// Bit-for-bit vs retail EXE: DEFERRED.
// ABI:       ECX=this; bare RET; void; does not free this or hash*
// Parent:    CNDUIDialog_CompleteDtor (0x00792c20) sole CALL @ 0x00792c4d
// =============================================================================

#include <cstdint>

// External (image) — register ABIs noted where decompiler hides them
extern "C" void FUN_007a4480(int level, const char *msg);
extern "C" std::uint32_t __thiscall FUN_00756be0(void *dialog, void *child);
// FUN_004133c0: ESI = list shell (this+0x4dc); EAX = 0; stack arg 0
extern "C" void FUN_004133c0(int zero);
// FUN_004281d0: EAX = hash*; BL = recreate width log2 (here 5)
extern "C" void FUN_004281d0(void);

// ECX = CNDUIDialog*. Bare RET. Teardown leaf — does not free this or hash*.
extern "C" void __fastcall CNDUIDialog_TeardownChildHash_Inferred(void *self)
{
  auto *base = reinterpret_cast<std::uint8_t *>(self);
  auto **vtbl = *reinterpret_cast<void ***>(self);

  void *hash = *reinterpret_cast<void **>(base + 0x4c0);
  if (hash == nullptr) {
    return;
  }

  // vtbl[+0x3c0](0) — clear selection / focus
  {
    auto fn = reinterpret_cast<void(__thiscall *)(void *, int)>(vtbl[0x3c0 / 4]);
    fn(self, 0);
  }

  // optional helper at +0x4b8 via vtbl[+0x318], then zero
  void **helper_slot = reinterpret_cast<void **>(base + 0x4b8);
  if (*helper_slot != nullptr) {
    auto fn = reinterpret_cast<void(__thiscall *)(void *)>(vtbl[0x318 / 4]);
    fn(self);
    *helper_slot = nullptr;
  }

  auto *hash_b = reinterpret_cast<std::uint8_t *>(hash);
  if (hash_b[0x1d] != 0) {
    FUN_007a4480(0, "HashError:TraversalLock, already locked for traversal");
    FUN_007a4480(0, "VOG_DEBUG_STOP");
  }
  hash_b[0x1d] = 1;

  void *cursor = nullptr;
  for (;;) {
    hash_b = reinterpret_cast<std::uint8_t *>(
        *reinterpret_cast<void **>(base + 0x4c0));
    if (hash_b[0x1d] == 0) {
      FUN_007a4480(0, "HashError:TraverseToNext, not locked for traversal");
      FUN_007a4480(0, "VOG_DEBUG_STOP");
    }

    if (cursor == nullptr) {
      cursor = *reinterpret_cast<void **>(hash_b + 0x14);
    } else {
      cursor = *reinterpret_cast<void **>(reinterpret_cast<std::uint8_t *>(cursor) + 0x14);
    }

    void *child = nullptr;
    if (cursor != nullptr) {
      child = *reinterpret_cast<void **>(reinterpret_cast<std::uint8_t *>(cursor) + 8);
    }
    if (child == nullptr) {
      break;
    }

    auto **child_vtbl = *reinterpret_cast<void ***>(child);
    auto get_nested = reinterpret_cast<void *(__thiscall *)(void *)>(child_vtbl[0x34 / 4]);
    void *nested = get_nested(child);
    if (nested != nullptr) {
      nested = get_nested(child);
      auto **nv = *reinterpret_cast<void ***>(nested);
      auto gate = reinterpret_cast<std::uint8_t(__thiscall *)(void *)>(nv[0x3d8 / 4]);
      if (gate(nested) != 0) {
        nested = get_nested(child);
        nv = *reinterpret_cast<void ***>(nested);
        auto tear = reinterpret_cast<void(__thiscall *)(void *)>(nv[0x440 / 4]);
        tear(nested);
      }
    }

    {
      auto release = reinterpret_cast<void(__thiscall *)(void *, int)>(child_vtbl[0x334 / 4]);
      release(child, 0);
    }
    *reinterpret_cast<std::uint32_t *>(reinterpret_cast<std::uint8_t *>(child) + 0x2b0) = 0;
    FUN_00756be0(self, child); // erase child* from dialog vector +0x94..+0x98
  }

  // unlock
  hash_b = reinterpret_cast<std::uint8_t *>(*reinterpret_cast<void **>(base + 0x4c0));
  hash_b[0x1d] = 0;

  // FUN_004133c0: ESI = this+0x4dc; EAX = 0; stack 0  (register ABI — plate)
  // FUN_004281d0: EAX = hash; BL = 5  (HashError:Recreate empty buckets)
  FUN_004133c0(0);
  FUN_004281d0();

  *reinterpret_cast<std::uint32_t *>(base + 0x4c4) = 1;
}

// Scaffold / Ghidra alias
extern "C" void __fastcall FUN_007917c0(void *self)
{
  CNDUIDialog_TeardownChildHash_Inferred(self);
}

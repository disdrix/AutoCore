// =============================================================================
// CVOGMenu_CNDHash_TraverseNotifyThenScalarDelete_At534_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0082ce20
// Address:   0x0082ce20 – 0x0082cf28 exclusive (264 B / 0x108); RET @ 0x0082cf27
//            autoassault.exe, image base 0x400000
// Wave:      WQ9L-H2 OWN-ONLY dual 2026-08-05 (scaffold WQ9L-H)
// Exactness: Behavior-preserving rewrite from live decompile + read_memory
//            + callee decompiles (004294f0 / 004113b0 / 00410d60) + parent
//            complete call site. Nested-list ECX restored from bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// ABI:       ECX = CVOGMenu* this; SUB ESP,8 frame; bare RET; void
// Parent:    CVOGMenu_CompleteDtor @ 0x0082d540
// =============================================================================
//
// PURPOSE:
//   If menu-owned CNDHash* at this+0x534 is non-null:
//     1. Soft-assert TraversalLock @ hash+0x1d; force lock = 1
//     2. Walk ordered node list (head @ hash+0x14, next @ node+0x14)
//     3. For each entry* @ node+8:
//          lock nested list @ entry+8 (FUN_004294f0)
//          for each value from FUN_004113b0: menu->vtbl[+0xbc](value)
//          unlock nested CS if held; FUN_00410d60 destroy owned chain
//     4. Unlock TraversalLock
//     5. Scalar-delete hash (vtbl[0](1)); null this+0x534
//   Does NOT free CVOGMenu this; does NOT run CNDUIDialog base dtor.
//
// REJECT:
//   - Host_CNDHash_TraverseTeardownThenRecreate_BL2 merge (different host
//     offset, next@+0x20, recreate not scalar-delete)
//   - Complete/scalar of CVOGMenu (parents)
//   - Hard-abort on lock errors (logs only; continues)
// =============================================================================

#include <cstdint>

extern "C" void FUN_007a4480(int level, const char* msg);
extern "C" void __fastcall FUN_004294f0(void* list_shell /*ECX*/);
// Iterate next under lock; returns 0 while more values. Full prototype residual.
extern "C" int FUN_004113b0(void* /*state*/, void* list_shell, void* out_value);
extern "C" void __fastcall FUN_00410d60(void* list_shell /*ECX*/);
extern "C" void __stdcall LeaveCriticalSection(void* cs);

// ECX = CVOGMenu* this.
extern "C" void __fastcall CVOGMenu_CNDHash_TraverseNotifyThenScalarDelete_At534_Inferred(
    void* self)
{
  auto* base = reinterpret_cast<std::uint8_t*>(self);
  void** hash_slot = reinterpret_cast<void**>(base + 0x534);
  void* hash = *hash_slot;
  if (hash == nullptr) {
    return;
  }

  // Soft-assert TraversalLock; force lock
  auto* hash_b = reinterpret_cast<std::uint8_t*>(hash);
  if (hash_b[0x1d] != 0) {
    FUN_007a4480(0, "HashError:TraversalLock, already locked for traversal");
    FUN_007a4480(0, "VOG_DEBUG_STOP");
  }
  hash_b[0x1d] = 1;

  void* cursor = nullptr;
  for (;;) {
    hash = *hash_slot;
    hash_b = reinterpret_cast<std::uint8_t*>(hash);

    if (hash_b[0x1d] == 0) {
      FUN_007a4480(0, "HashError:TraverseToNext, not locked for traversal");
      FUN_007a4480(0, "VOG_DEBUG_STOP");
    }

    // ordered list: first node at hash+0x14; successor at node+0x14
    if (cursor == nullptr) {
      cursor = *reinterpret_cast<void**>(hash_b + 0x14);
    } else {
      cursor = *reinterpret_cast<void**>(reinterpret_cast<std::uint8_t*>(cursor) + 0x14);
    }

    void* entry = nullptr;
    if (cursor != nullptr) {
      entry = *reinterpret_cast<void**>(reinterpret_cast<std::uint8_t*>(cursor) + 8);
    }
    if (entry == nullptr) {
      break;
    }

    // Nested locked list shell at entry+8
    auto* list = reinterpret_cast<std::uint8_t*>(entry) + 8;
    FUN_004294f0(list);

    // Walk values; notify menu via vtbl[+0xbc]
    void* value = nullptr;
    // Cursor state is a stack local in retail; plate uses a single void* slot.
    void* iter_state = nullptr;
    int done = FUN_004113b0(&iter_state, list, &value);
    while (done == 0) {
      auto** vtbl = *reinterpret_cast<void***>(self);
      auto notify = reinterpret_cast<void(__thiscall*)(void*, void*)>(vtbl[0xbc / 4]);
      notify(self, value);
      done = FUN_004113b0(&iter_state, list, &value);
    }

    // Unlock if TraversalLock held on nested list (flag @ list+0x28 = entry+0x30)
    if (list[0x28] != 0) {
      list[0x28] = 0;
      LeaveCriticalSection(list + 4);
    }
    FUN_00410d60(list);
  }

  // Unlock hash TraversalLock; scalar-delete hash; null slot
  hash = *hash_slot;
  if (hash != nullptr) {
    reinterpret_cast<std::uint8_t*>(hash)[0x1d] = 0;
    auto** hvtbl = *reinterpret_cast<void***>(hash);
    auto scalar = reinterpret_cast<void*(__thiscall*)(void*, int)>(hvtbl[0]);
    scalar(hash, 1);
  }
  *hash_slot = nullptr;
}

// Scaffold / Ghidra alias
extern "C" void __fastcall FUN_0082ce20(void* self)
{
  CVOGMenu_CNDHash_TraverseNotifyThenScalarDelete_At534_Inferred(self);
}

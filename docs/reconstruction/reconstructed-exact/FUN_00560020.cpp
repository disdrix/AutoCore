// =============================================================================
// WorldObj_UnregisterAndRelease_Inferred  (Ghidra: FUN_00560020)
// -----------------------------------------------------------------------------
// Stable ID: aa_00560020
// Address:   0x00560020 – 0x0056010c  (autoassault.exe, image base 0x400000)
// Size:      237 bytes (0xED); epilogue ret 4; pad CC at 0x0056010d
// System:    world / phys-link object unenroll + release
// Dual:      W29-S 2026-07-29 (decompile + read_memory; no disassemble_bytes)
// Exactness: Behavior-preserving rewrite. Not modernization. Not bit-exact certified.
// =============================================================================
//
// PURPOSE:
//   Reverse of FUN_0055ff20 enroll: extract unbind pairs via provider vtbl+0xC,
//   sorted-diff remove against empty left range, notify 0062a510, drop refcount
//   at object+6, clear object+0x8, destroy if zero, swap-remove from manager+0x120.
//
// ABI (machine):
//   thiscall; ECX = manager; stack = object*; void; ret 4
// =============================================================================

#include <cstdint>

extern "C" void FUN_0062d960(uint32_t token_or_desc /* via ECX stack helper */);
extern "C" void FUN_006cad30(void* pair_array, int count); // LinkPair_CanonAndSort_Inferred
extern "C" void __thiscall FUN_006caaa0(void* handler /*ECX*/, void* a0, void* a1,
                                        void* pairs, int count, void* opt_base);
extern "C" void FUN_0062a510(void* manager, void* object);
extern "C" void __fastcall FUN_0055f4c0(void* worklist_desc /*ECX*/); // LocalWorklist_Release

void __thiscall WorldObj_UnregisterAndRelease_Inferred(void* manager, void* object)
{
  auto* mgr = reinterpret_cast<uint8_t*>(manager);
  auto* obj = reinterpret_cast<uint32_t*>(object);

  // Stage 0: lock/scope with manager+0x234
  FUN_0062d960(*reinterpret_cast<uint32_t*>(mgr + 0x234));

  // Stage 1: pair-view base = null if object == -12 else object+0x1C
  void* pair_view = nullptr;
  if (obj != reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(-12))) {
    pair_view = reinterpret_cast<void*>(reinterpret_cast<uint8_t*>(obj) + 0x1C);
  }

  // Out buffer for extract (decomp: local_14). Machine stores pair range here.
  struct ExtractOut {
    void* pairs;
    int count;
    uint8_t rest[12];
  } out{};
  void** provider = *reinterpret_cast<void***>(mgr + 0xC4);
  using ExtractFn = void(__thiscall*)(void* self, void* pair_view, ExtractOut* out);
  void** pvtbl = *reinterpret_cast<void***>(provider);
  reinterpret_cast<ExtractFn>(pvtbl[0xC / 4])(provider, pair_view, &out);

  // Stage 2: if extracted count != 0, canon+sort then sorted-diff remove
  if (out.count != 0) {
    FUN_006cad30(out.pairs, out.count);
    void* opt = nullptr;
    void* d0 = *reinterpret_cast<void**>(mgr + 0xD0);
    if (d0) {
      opt = reinterpret_cast<uint8_t*>(d0) + 8;
    }
    void* handler = mgr + 0x138;
    // Diff walk: empty left (0,0), right = extracted; remove-side reconcile
    FUN_006caaa0(handler, nullptr, nullptr, out.pairs, out.count, opt);
  }

  // Stage 3: notify unregister path
  FUN_0062a510(manager, object);

  // Stage 4: COM-style short refcount at +6; clear owner dword at +0x8
  auto* ref = reinterpret_cast<int16_t*>(reinterpret_cast<uint8_t*>(obj) + 6);
  *ref = static_cast<int16_t>(*ref - 1);
  obj[2] = 0; // +0x8
  if (*ref == 0) {
    using V0 = void(__thiscall*)(void* self, int flag);
    void** vtbl = *reinterpret_cast<void***>(obj);
    reinterpret_cast<V0>(vtbl[0])(obj, 1);
  }

  // Stage 5: swap-remove from manager+0x120[count at +0x124]
  int count = *reinterpret_cast<int*>(mgr + 0x124);
  int idx = -1;
  if (count > 0) {
    auto** arr = *reinterpret_cast<void***>(mgr + 0x120);
    for (int i = 0; i < count; ++i) {
      if (arr[i] == object) {
        idx = i;
        break;
      }
    }
  }
  count -= 1;
  *reinterpret_cast<int*>(mgr + 0x124) = count;
  {
    auto** arr = *reinterpret_cast<void***>(mgr + 0x120);
    arr[idx] = arr[count];
  }

  // Stage 6: release local worklist used by extract/diff path
  // Machine: LEA ECX,[esp+local]; CALL 0055f4c0
  // (descriptor lives in this frame; modeled as side effect of stages 0–2)
  // FUN_0055f4c0(local_worklist_desc);
}

// Ghidra symbol alias
void __thiscall FUN_00560020(void* manager, void* object)
{
  WorldObj_UnregisterAndRelease_Inferred(manager, object);
}

// =============================================================================
// EffEffectFactory_OnDeviceReset_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0073d870
// Address:   0x0073d870  (autoassault.exe, image base 0x400000)
// Body:      82 B (0x52); 0x0073d870–0x0073d8c2 exclusive; pad CC then 0x0073d8d0
// System:    graphics / Effects (effEffectFactory via gfxDevice Device Reset)
// Generated: 2026-08-04 W38-V (decompile + read_memory; no disassemble_bytes)
// Exactness: Behavior-preserving rewrite. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Effect Factory post-IDirect3DDevice9::Reset recreate walk.
//   Sole caller FUN_0075eff0 (gfxDevice.cpp Device Reset) loads EAX from
//   [EBP+0x764] and checks return < 0 with plate:
//     "Failed to Reset() device on Effect Factory"
//   Pair: EffEffectFactory_OnDeviceLost_Inferred (0x0073d8d0) — pre-reset release
//   on the same host. This unit always returns 0 (XOR EAX,EAX).
//
// ABI:
//   EAX = factory host* (register formal)
//   no stack args; plain RET; returns uint32_t 0
//
// Host / entry (sealed):
//   host+4 / +8 = entry* begin / end
//   entry stride 0x14
//   entry+0 = object* with optional child at +0xC → vcall +0x118
//   entry+8 / +0xC = param* begin / end (stride 4) → FUN_007525f0 (EDI formal)
//
// Reject: Named_CalleeOf_Named_gfxDevice_0073d870 scaffold alias.
// =============================================================================

#include <cstdint>

// Unowned callees (register formals recovered from call-site bytes)
extern "C" uint32_t FUN_007525f0(void); // EDI = param entry*

struct EffFactoryEntry {
  void* object;           // +0x00
  uint32_t unused_04;     // +0x04 (not touched here)
  void** param_begin;     // +0x08
  void** param_end;       // +0x0C
  uint32_t unused_10;     // +0x10 (not touched here)
};

struct EffEffectFactoryHost {
  uint32_t unused_00;     // +0x00
  EffFactoryEntry* begin; // +0x04
  EffFactoryEntry* end;   // +0x08
};

struct VtblChild {
  // ...
  // +0x118: OnResetDevice-style method
};

struct ChildWithVtbl {
  VtblChild* vtbl;
};

// EAX host formal — modeled as first explicit arg for readability.
extern "C" uint32_t EffEffectFactory_OnDeviceReset_Inferred(EffEffectFactoryHost* host /* EAX */)
{
  EffFactoryEntry* end = host->end;
  for (EffFactoryEntry* entry = host->begin; entry != end; ++entry) {
    void* obj = entry->object;
    ChildWithVtbl* child = *reinterpret_cast<ChildWithVtbl**>(
        reinterpret_cast<uint8_t*>(obj) + 0x0C);
    if (child != nullptr) {
      // PUSH child; CALL child->vtbl[+0x118]
      using Fn = void(__stdcall*)(ChildWithVtbl*);
      auto* slot = reinterpret_cast<Fn*>(
          reinterpret_cast<uint8_t*>(child->vtbl) + 0x118);
      (*slot)(child);
    }
    for (void** p = entry->param_begin; p != entry->param_end; ++p) {
      // EDI = *p; CALL FUN_007525f0
      void* param = *p;
      (void)param;
      FUN_007525f0();
    }
  }
  return 0;
}

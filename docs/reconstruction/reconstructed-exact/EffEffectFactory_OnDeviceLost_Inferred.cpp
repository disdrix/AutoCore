// =============================================================================
// EffEffectFactory_OnDeviceLost_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0073d8d0
// Address:   0x0073d8d0  (autoassault.exe, image base 0x400000)
// Body:      103 B (0x67); 0x0073d8d0–0x0073d937 exclusive; pad CC then 0x0073d940
// System:    graphics / Effects (effEffectFactory via gfxDevice Device Reset)
// Generated: 2026-08-04 W38-V (decompile + read_memory; no disassemble_bytes)
// Exactness: Behavior-preserving rewrite. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Effect Factory pre-reset / device-lost release walk.
//   Sole caller FUN_0075eff0 (gfxDevice.cpp Device Reset) loads EAX from
//   [EBP+0x764] (same host as OnDeviceReset) during
//   "Beginning shutdown for Device Reset()" before IDirect3DDevice9::Reset.
//   Pair: EffEffectFactory_OnDeviceReset_Inferred (0x0073d870).
//
// ABI:
//   EAX = factory host* (register formal)
//   no stack args; plain RET; void
//
// Host / entry (sealed): same 0x14 table as OnDeviceReset.
//   Per entry: FUN_0074f0c0 (ESI=*entry); FUN_00752640 over param range (EBX).
// Tail:
//   DAT_00d1f048[+0xC] = 0
//   if DAT_00d1f044[+0x77C] == 1: device->vtbl[+0x134](device, 0)
//
// Reject: Named_CalleeOf_Named_gfxDevice_0073d8d0 scaffold alias.
// =============================================================================

#include <cstdint>

extern "C" void FUN_0074f0c0(void); // ESI = entry object*
extern "C" void FUN_00752640(void); // EBX = param entry*

// Global graphics state (names retained as Ghidra DAT_*)
extern "C" uint8_t* DAT_00d1f048;
extern "C" uint32_t* DAT_00d1f044; // points at device-like host

struct EffFactoryEntry {
  void* object;           // +0x00
  uint32_t unused_04;     // +0x04
  void** param_begin;     // +0x08
  void** param_end;       // +0x0C
  uint32_t unused_10;     // +0x10
};

struct EffEffectFactoryHost {
  uint32_t unused_00;
  EffFactoryEntry* begin; // +0x04
  EffFactoryEntry* end;   // +0x08
};

struct DeviceVtbl {
  // +0x134 used as software-VP style toggle in gfxDevice Reset path
};

struct DeviceIface {
  DeviceVtbl* vtbl;
};

extern "C" void EffEffectFactory_OnDeviceLost_Inferred(EffEffectFactoryHost* host /* EAX */)
{
  EffFactoryEntry* end = host->end;
  for (EffFactoryEntry* entry = host->begin; entry != end; ++entry) {
    void* obj = entry->object;
    (void)obj;
    // ESI = *entry; CALL FUN_0074f0c0
    FUN_0074f0c0();
    for (void** p = entry->param_begin; p != entry->param_end; ++p) {
      void* param = *p;
      (void)param;
      // EBX = *p; CALL FUN_00752640
      FUN_00752640();
    }
  }

  DAT_00d1f048[0x0C] = 0;

  // DAT_00d1f044[0x1df] == field at +0x77C
  if (DAT_00d1f044[0x1df] == 1) {
    auto* iface = reinterpret_cast<DeviceIface*>(*reinterpret_cast<void**>(DAT_00d1f044));
    using Fn = void(__stdcall*)(DeviceIface*, uint32_t);
    auto* slot = reinterpret_cast<Fn*>(
        reinterpret_cast<uint8_t*>(iface->vtbl) + 0x134);
    (*slot)(iface, 0);
  }
}

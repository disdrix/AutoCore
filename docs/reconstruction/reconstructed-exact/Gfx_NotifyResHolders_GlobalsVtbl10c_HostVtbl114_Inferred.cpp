// =============================================================================
// Gfx_NotifyResHolders_GlobalsVtbl10c_HostVtbl114_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0074f0c0
// Address:   0x0074f0c0  (autoassault.exe, image base 0x400000)
// System:    client / gfxDevice resource holders
// Wave:      W38-X OWN-ONLY dual (2026-08-04)
// Exactness: Behavior-preserving rewrite of decompiler + sealed machine bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Notify optional ifaces on three global resource holders (vtbl+0x10c) and
//   one ESI host holder (vtbl+0x114). Leaf under GfxDevice_Reset and a
//   stride-0x14 vector walk (FUN_0073d8d0).
//
// ABI:
//   ESI = host object with optional iface* at +0xc
//   Bare RET (C3); void
//
// REJECT: scaffold Named_CalleeOf_Named_gfxDevice_0074f0c0
// =============================================================================

#include <cstdint>

// External BSS holders (runtime pointers; image zeroes).
extern "C" uint8_t* DAT_00afe034;
extern "C" uint8_t* DAT_00afe01c;
extern "C" uint8_t* DAT_00afe010;

struct IfaceVtable {
  // ... low methods omitted ...
  // +0x104, +0x10c, +0x114 used by this family (see also FUN_0040d340 @ +0x104)
};

struct Iface {
  IfaceVtable* vtbl;
};

struct ResHolder {
  // +0x00 .. +0x08 unknown
  Iface* iface; // +0x0c
};

// MSVC thiscall vcall: push this; call [vtbl+off]
using Vcall0 = void(__thiscall*)(Iface* self);

void Gfx_NotifyResHolders_GlobalsVtbl10c_HostVtbl114_Inferred(/* ESI */ ResHolder* host)
{
  auto notify_global_10c = [](uint8_t* holder_raw) {
    if (holder_raw == nullptr) {
      return;
    }
    auto* holder = reinterpret_cast<ResHolder*>(holder_raw);
    Iface* iface = holder->iface; // +0xc
    if (iface == nullptr) {
      return;
    }
    auto** vtbl = reinterpret_cast<Vcall0**>(iface->vtbl);
    // vtbl slot +0x10c / 4 = index 0x43
    vtbl[0x10c / 4](iface);
  };

  notify_global_10c(DAT_00afe034);
  notify_global_10c(DAT_00afe01c);
  notify_global_10c(DAT_00afe010);

  if (host != nullptr && host->iface != nullptr) {
    Iface* iface = host->iface;
    auto** vtbl = reinterpret_cast<Vcall0**>(iface->vtbl);
    // vtbl slot +0x114 / 4 = index 0x45 (distinct from global +0x10c)
    vtbl[0x114 / 4](iface);
  }
}

// Ghidra twin alias
void FUN_0074f0c0(void)
{
  ResHolder* host;
  __asm { mov host, esi }
  Gfx_NotifyResHolders_GlobalsVtbl10c_HostVtbl114_Inferred(host);
}

// =============================================================================
// Phys_IslandHost_Ctor_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_006295f0
// Address:   0x006295f0–0x006296a2 (178 B / 0xB2); ret 4
// Module:    autoassault.exe (image base 0x400000)
// Ghidra:    FUN_006295f0
// System:    phys / island host construct
// Dual:      2026-07-29 W30-J OWN-ONLY
// =============================================================================
//
// ABI: __thiscall  ECX = Host* (0xa8 arena block); stack = Manager*; void; ret 4
//      EAX returns this (MSVC ctor convention).
//
// CF: zero header fields; install primary vtbl 009e331c + secondary 009e3310;
//     store manager at +0x20; set flag bytes; init empty growable list
//     descriptors with capacity sentinels 0x80000000 / 0x80000001.
//
// Callers: WorldObj_AttachRegisterHost (0055e760) x2 island/empty paths;
//          FUN_00560110 (island split); FUN_00561e20 (manager-family ctor path).
// Sibling dtor-like: FUN_006296c0 frees list slots with allocator tag 0x12.
//
// No callees. No invented product type name — _Inferred only.

#include <cstdint>

// Rdata vtable anchors (image)
extern "C" void *PTR_FUN_009e331c;
extern "C" void *PTR_LAB_009e3310;
extern "C" void *PTR_LAB_009d2794;

void __thiscall Phys_IslandHost_Ctor_Inferred(uint32_t *host, uint32_t manager)
{
  host[2] = 0;
  host[3] = 0;
  host[4] = 0;
  host[5] = 0;
  host[6] = 0;
  host[7] = (uint32_t)&PTR_LAB_009d2794;
  host[8] = manager;
  *host = (uint32_t)&PTR_FUN_009e331c;
  host[7] = (uint32_t)&PTR_LAB_009e3310;
  *(uint8_t *)(host + 10) = 0;                 // +0x28
  *(uint8_t *)((uint8_t *)host + 0x29) = 1;    // +0x29
  *(uint8_t *)(host + 0xb) = 0;                // +0x2c
  *(uint8_t *)(host + 0xc) = 1;                // +0x30
  host[0xd] = 0;                               // +0x34 (float 0 via MOVSS)
  host[0xe] = 0;                               // +0x38
  host[0x10] = 0;
  host[0x11] = 0x80000001;
  host[0xf] = (uint32_t)(host + 0x12);         // +0x3c → +0x48
  host[0x13] = 0;
  host[0x14] = 0;
  host[0x15] = 0x80000000;
  host[0x17] = 0;
  host[0x18] = 0x80000001;
  host[0x16] = (uint32_t)(host + 0x19);        // +0x58 → +0x64
  host[0x1a] = 0;
  host[0x1b] = 0;
  host[0x1c] = 0x80000000;
  host[0x1d] = 0;
  host[0x1e] = 0;
  host[0x1f] = 0x80000000;
  host[0x20] = 0;
  host[0x21] = 0;
  host[0x22] = 0x80000000;
  host[0x23] = 0;
  host[0x24] = 0;
  host[0x25] = 0x80000000;
  return; // ret 4
}

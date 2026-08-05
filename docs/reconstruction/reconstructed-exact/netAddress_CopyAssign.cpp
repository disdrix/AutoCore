// =============================================================================
// netAddress_CopyAssign
// -----------------------------------------------------------------------------
// Stable ID: aa_0067b0e0
// Address:   0x0067b0e0  (autoassault.exe, image base 0x400000)
// System:    network-nazgul-netAddress
// Ghidra:    FUN_0067b0e0
// Generated: 2026-07-29 W25-P OWN-ONLY dual seal
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// ROLE (High, product English open):
//   Copy-assign / copy-from for the nazgul 16-byte Address POD (sockaddr-compatible).
//   Four sequential dword stores: dest[0..3] = src[0..3].
//
// ABI:
//   __thiscall  ECX = dest Address*
//   stack arg0  = src Address*
//   ret 4       (C2 04 00)
//   void return
//
// Evidence:
//   decompile_function @ 0x0067b0e0
//   read_memory body hex:
//     8bc18b4c2404568b318bd089328b71048972048b71088972088b490c894a0c5ec20400
//   Callers: FUN_0067ba30, FUN_0067b9a0, FUN_00671570, FUN_0067c060, FUN_0067c120
//
// Gaps:
//   Product class spelling (netAddress vs Address). Runtime / bit-exact open.

#include <cstdint>

// 16-byte Address overlay (4 dwords). Field English not sealed here.
struct NetAddress16 {
  uint32_t w[4];
};

void __thiscall netAddress_CopyAssign(NetAddress16 *dest /* this */, const NetAddress16 *src)
{
  dest->w[0] = src->w[0];
  dest->w[1] = src->w[1];
  dest->w[2] = src->w[2];
  dest->w[3] = src->w[3];
}

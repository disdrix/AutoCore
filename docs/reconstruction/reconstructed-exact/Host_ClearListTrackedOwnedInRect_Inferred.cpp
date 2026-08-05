// =============================================================================
// Host_ClearListTrackedOwnedInRect_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00494530
// Address:   0x00494530–0x0049459d  (110 B / 0x6E, autoassault.exe base 0x400000)
// System:    host / grid elem0x28 owned ListTrackedObj* @ +0x24 (rect clear)
// Generated: 2026-07-29 W31-D dual A/B (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler CF + body hex seal.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_00494530
// =============================================================================
//
// PURPOSE:
//   For each grid cell in the host's half-open dirty rect
//   [x0@+0x64, x1@+0x6C) x [y0@+0x68, y1@+0x70), destroy and free the owned
//   ListTrackedObj* at elem+0x24 (stride 0x28 array at host+0x28) and null the
//   slot. Does not free the elem array itself.
//
// ABI:
//   ECX = host. No stack formals. Bare RET. Void.
//   (Ghidra __fastcall ≡ thiscall ECX-this.)
//
// CALLEES:
//   ListTrackedObj_CompleteDtor (FUN_004be2a0, W30-P)
//   operator_delete
//
// CALLERS:
//   Thin wrapper @ 0x0094ece0: host = *(*(this+0xE04)+0xE898); call; return 1; ret 8.
//   DATA xref to wrapper from FUN_00959230 @ 0x009596a5.
// =============================================================================

#include <cstdint>

extern "C" void __thiscall ListTrackedObj_CompleteDtor(void* self);  // FUN_004be2a0
extern "C" void operator_delete(void* p);

// Machine: void __fastcall FUN_00494530(int host)
extern "C" void __fastcall Host_ClearListTrackedOwnedInRect_Inferred(void* host)
{
  auto* h = reinterpret_cast<uint8_t*>(host);

  uint32_t x = *reinterpret_cast<uint32_t*>(h + 0x64);
  uint32_t xEnd = *reinterpret_cast<uint32_t*>(h + 0x6C);
  if (x >= xEnd) {
    return;
  }

  do {
    uint32_t y = *reinterpret_cast<uint32_t*>(h + 0x68);
    uint32_t yEnd = *reinterpret_cast<uint32_t*>(h + 0x70);
    if (y < yEnd) {
      do {
        int dimX = *reinterpret_cast<int*>(h + 4);
        int index = dimX * static_cast<int>(y) + static_cast<int>(x);
        auto* arr = *reinterpret_cast<uint8_t**>(h + 0x28);
        auto* elem = arr + index * 0x28;
        void* owned = *reinterpret_cast<void**>(elem + 0x24);
        if (owned != nullptr) {
          ListTrackedObj_CompleteDtor(owned);
          operator_delete(owned);
        }
        *reinterpret_cast<void**>(elem + 0x24) = nullptr;
        ++y;
      } while (y < *reinterpret_cast<uint32_t*>(h + 0x70));
    }
    ++x;
  } while (x < *reinterpret_cast<uint32_t*>(h + 0x6C));
}

// =============================================================================
// Host_EnsureRegionCellOwned_Inferred  (aa_00494700)
// -----------------------------------------------------------------------------
// Address:   0x00494700  (autoassault.exe, image base 0x400000)
// Wave:      W31-C OWN-ONLY dual 2026-07-29
// Exactness: Behavior-preserving rewrite from decompile + full-body read_memory.
//            Ignore Ghidra false-noreturn on operator_delete (bytes fall through).
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

extern "C" void* __cdecl operator_new(uint32_t size);
extern "C" void __cdecl operator_delete(void* p);

// ListTrackedObj ctor: size 0x5E0; dual base vtbl 009cb5cc; list-track globals.
extern "C" void* __thiscall FUN_004becb0(void* self, void* cell, char mode);
extern "C" void __thiscall FUN_004bd890(void* owned, uint32_t x, uint32_t y);
extern "C" void __fastcall FUN_004bf690(void* owned);
extern "C" uint8_t FUN_004bd660(void** out_victim);
extern "C" void __fastcall ListTrackedObj_CompleteDtor(void* owned); // 0x004be2a0 W30-P
extern "C" void __fastcall FUN_004bd6f0(void* owned);

// Host with 0x28-stride cell grid (see W30-Q rebuild / W29-F Elem0x28).
// Ensures each cell in the active region has a ListTrackedObj* at cell+0x24.
// ECX = host; stack arg = context (stored at owned+0x5D4). RET 4.
extern "C" void __thiscall Host_EnsureRegionCellOwned_Inferred(uint8_t* host, void* ctx)
{
  // SEH: LAB_009a0bd0 (omitted structural detail).

  *reinterpret_cast<uint8_t*>(host + 0x53) = 0;

  uint32_t x = *reinterpret_cast<uint32_t*>(host + 0x64);
  const uint32_t x_end = *reinterpret_cast<uint32_t*>(host + 0x6c);
  const int32_t dim_x = *reinterpret_cast<int32_t*>(host + 4);
  uint8_t* cells = *reinterpret_cast<uint8_t**>(host + 0x28);

  if (x < x_end) {
    do {
      uint32_t y = *reinterpret_cast<uint32_t*>(host + 0x68);
      const uint32_t y_end = *reinterpret_cast<uint32_t*>(host + 0x70);
      if (y < y_end) {
        do {
          uint8_t* cell = cells + (dim_x * static_cast<int32_t>(y) + static_cast<int32_t>(x)) * 0x28;
          void* owned = *reinterpret_cast<void**>(cell + 0x24);

          if (owned == nullptr) {
            void* mem = operator_new(0x5E0);
            void* obj = nullptr;
            if (mem != nullptr) {
              obj = FUN_004becb0(mem, cell, 0);
            }
            *reinterpret_cast<void**>(reinterpret_cast<char*>(obj) + 0x5D4) = ctx;
            FUN_004bd890(obj, x, y);
            FUN_004bf690(obj);
            *reinterpret_cast<void**>(cell + 0x24) = obj;

            void* victim = nullptr;
            if (FUN_004bd660(&victim) != 0) {
              const int32_t vx = *reinterpret_cast<int32_t*>(reinterpret_cast<char*>(victim) + 0x5A8);
              const int32_t vy = *reinterpret_cast<int32_t*>(reinterpret_cast<char*>(victim) + 0x5AC);
              const int32_t vidx = vy * dim_x + vx;
              uint8_t* vcell = cells + vidx * 0x28;
              void* vowned = *reinterpret_cast<void**>(vcell + 0x24);

              if (vowned != nullptr &&
                  *reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(ctx) + 0x7D) == 0) {
                *reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(vowned) + 0x5D0) = 1;
              }

              void* to_free = *reinterpret_cast<void**>(vcell + 0x24);
              *reinterpret_cast<void**>(vcell + 0x24) = nullptr;
              if (to_free != nullptr) {
                ListTrackedObj_CompleteDtor(to_free);
                operator_delete(to_free);
              }
            }
          } else {
            FUN_004bd6f0(owned);
          }

          y += 1;
        } while (y < *reinterpret_cast<uint32_t*>(host + 0x70));
      }
      x += 1;
    } while (x < *reinterpret_cast<uint32_t*>(host + 0x6c));
  }

  *reinterpret_cast<uint8_t*>(host + 0x53) = 1;
}

// Scaffold alias
extern "C" void __thiscall FUN_00494700(uint8_t* host, void* ctx)
{
  Host_EnsureRegionCellOwned_Inferred(host, ctx);
}

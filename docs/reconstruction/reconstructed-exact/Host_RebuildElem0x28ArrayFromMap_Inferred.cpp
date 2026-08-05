// =============================================================================
// Host_RebuildElem0x28ArrayFromMap_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004941b0
// Address:   0x004941b0–0x00494304  (341 B / 0x155, autoassault.exe base 0x400000)
// System:    host / cookie-vector rebuild from map dims (stride 0x28)
// Generated: 2026-07-29 W30-Q dual A/B (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler CF + constants seal.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_004941b0
// =============================================================================
//
// PURPOSE:
//   Free any existing 0x28-stride cookie-vector at host+0x28, then rebuild it
//   from map extents at *(mapCtx+0xe4f8):
//     scale = 64.0f (DAT_00a11088) if mapCtx+0xf5 != 0, else 32.0f (DAT_00aaa8a4)
//     dimX  = ROUND( (float)map[+0x10] / scale * map[+0x18] ) + 1  → host+4
//     dimY  = ROUND( (float)map[+0x14] / scale * map[+0x18] ) + 1  → host+8
//     count = dimX * dimY
//     alloc cookie-vector count × 0x28; ctor FUN_005b7db0 / dtor FUN_005b8000
//
// ABI:
//   __thiscall; ECX=host; stack mapCtx; RET 4; void.
//   SEH LAB_009a0bbb.
//
// CALLER (sole):
//   FUN_004ac100 @ 0x004ac12e:
//     eax = *[caller+0x340]; ecx = *[eax+0xe898]; push eax; call
//
// NOTE:
//   Reject scaffold Named_VOG_DEBUG_STOP_004941b0 — string is null-map assert only.
//   Product map/host English open.
// =============================================================================

#include <cstdint>
#include <cmath>

extern "C" void _eh_vector_destructor_iterator_(
    void* arr, uint32_t stride, int count, void* dtor);
extern "C" void _eh_vector_constructor_iterator_(
    void* arr, uint32_t stride, int count, void* ctor, void* dtor);
extern "C" void operator_delete[](void* p);
extern "C" void* operator_new[](uint32_t size);
extern "C" void FUN_007a4480(int a, const char* msg);
extern "C" void __thiscall FUN_005b8000(void* elem);  // Elem0x28_CompleteDtor
extern "C" void __fastcall FUN_005b7db0(void* elem);  // element default ctor

// Image globals (read_memory sealed)
extern "C" float DAT_00a11088;  // 64.0f  @ 0x00a11088 (dword 0x42800000)
extern "C" float DAT_00aaa8a4;  // 32.0f  @ 0x00aaa8a4 (dword 0x42000000)
extern "C" float DAT_00aefa50;  // scratch scale

// Machine: void __thiscall FUN_004941b0(int host, int mapCtx)
extern "C" void __thiscall Host_RebuildElem0x28ArrayFromMap_Inferred(
    void* host, void* mapCtx)
{
  auto* h = reinterpret_cast<uint8_t*>(host);
  auto* ctx = reinterpret_cast<uint8_t*>(mapCtx);

  void* arr = *reinterpret_cast<void**>(h + 0x28);
  int* storage = nullptr;

  if (arr != nullptr) {
    int oldCount = *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(arr) - 4);
    _eh_vector_destructor_iterator_(arr, 0x28, oldCount,
                                    reinterpret_cast<void*>(&FUN_005b8000));
    operator_delete[](reinterpret_cast<uint8_t*>(arr) - 4);
  }
  *reinterpret_cast<uint32_t*>(h + 0x28) = 0;

  if (*reinterpret_cast<int*>(ctx + 0xe4f8) == 0) {
    FUN_007a4480(0, "VOG_DEBUG_STOP");
    return;  // RET 4
  }

  DAT_00aefa50 = DAT_00a11088;  // 64.0f
  if (*reinterpret_cast<char*>(ctx + 0xf5) == '\0') {
    DAT_00aefa50 = DAT_00aaa8a4;  // 32.0f
  }

  auto* map = *reinterpret_cast<uint8_t**>(ctx + 0xe4f8);
  int mapX = *reinterpret_cast<int*>(map + 0x10);
  int mapY = *reinterpret_cast<int*>(map + 0x14);
  float mapScale = *reinterpret_cast<float*>(map + 0x18);

  int dimX = static_cast<int>(
                 std::round((static_cast<float>(mapX) / DAT_00aefa50) * mapScale)) +
             1;
  *reinterpret_cast<int*>(h + 4) = dimX;

  int dimY = static_cast<int>(
                 std::round((static_cast<float>(mapY) / DAT_00aefa50) * mapScale)) +
             1;
  *reinterpret_cast<int*>(h + 8) = dimY;

  int count = dimY * dimX;
  auto* raw = static_cast<int*>(operator_new[](static_cast<uint32_t>(count * 0x28 + 4)));
  if (raw != nullptr) {
    storage = raw + 1;
    *raw = count;
    _eh_vector_constructor_iterator_(
        storage, 0x28, count,
        reinterpret_cast<void*>(&FUN_005b7db0),
        reinterpret_cast<void*>(&FUN_005b8000));
  }
  *reinterpret_cast<int**>(h + 0x28) = storage;
}

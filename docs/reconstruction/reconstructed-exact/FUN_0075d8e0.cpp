// =============================================================================
// FUN_0075d8e0 — Ghidra-named twin of NDResourceCache_CompleteDtor (aa_0075d8e0)
// Prefer: reconstructed-exact/NDResourceCache_CompleteDtor.cpp
// W35-I 2026-07-29 — stack self*; RET 4; void; 223 B @ 0x0075d8e0 (bytes authority)
// =============================================================================

#include <cstdint>

extern "C" void* DAT_00d1f050;
extern "C" void __fastcall FUN_0075d6f0(void*);
extern "C" void __fastcall FUN_00971050(void* preloader);
extern "C" void __stdcall FUN_00971180(void* preloader);
extern "C" void __cdecl operator_delete(void* p);
extern "C" void* __stdcall FUN_0043c220(void* out, void* begin, void* end);
extern "C" void __stdcall DeleteCriticalSection(void* cs);
extern "C" void __fastcall FUN_0040d9c0(void);
extern "C" void __fastcall FUN_00415e90(void);

extern "C" void __stdcall FUN_0075d8e0(void* self)
{
  uint8_t* base = reinterpret_cast<uint8_t*>(self);

  FUN_0075d6f0(nullptr);

  void* pre = *reinterpret_cast<void**>(base + 0x6c);
  if (pre != nullptr) {
    FUN_00971050(pre);
    pre = *reinterpret_cast<void**>(base + 0x6c);
    if (pre != nullptr) {
      FUN_00971180(pre);
      operator_delete(pre);
    }
    *reinterpret_cast<void**>(base + 0x6c) = nullptr;
  }

  void** tree = reinterpret_cast<void**>(base + 0x58);
  void* head = tree[1];
  void* begin = *reinterpret_cast<void**>(head);
  uint8_t out_it[4];
  FUN_0043c220(out_it, begin, head);
  operator_delete(tree[1]);
  tree[1] = nullptr;
  tree[2] = nullptr;

  DeleteCriticalSection(base + 0x3c);
  base[0x54] = 0;
  FUN_0040d9c0();

  void* blk = *reinterpret_cast<void**>(base + 0x14);
  if (blk != nullptr) {
    operator_delete(blk);
  }
  *reinterpret_cast<void**>(base + 0x14) = nullptr;
  *reinterpret_cast<uint32_t*>(base + 0x18) = 0;
  *reinterpret_cast<uint32_t*>(base + 0x1C) = 0;

  FUN_00415e90();
  operator_delete(*reinterpret_cast<void**>(base + 0x08));
  *reinterpret_cast<void**>(base + 0x08) = nullptr;

  DAT_00d1f050 = nullptr;
}

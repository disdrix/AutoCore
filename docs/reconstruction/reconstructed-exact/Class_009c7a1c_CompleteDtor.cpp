// =============================================================================
// Class_009c7a1c_CompleteDtor
// -----------------------------------------------------------------------------
// Stable ID: aa_004970b0
// Address:   0x004970b0  (autoassault.exe, image base 0x400000)
// Body:      0x004970b0–0x004971e0 exclusive (304 B / 0x130)
// System:    class complete-object destructor (vtbl PTR_FUN_009c7a1c)
// Generated: 2026-07-29 W28-M dual seal
// Exactness: Behavior-preserving rewrite from decompile + read_memory.
//            LEA list target and operator_delete fall-through sealed by bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE:
// MSVC complete-object destructor for class family PTR_FUN_009c7a1c.
// Installs own vtbl, destroys cookie-vector of 0x28-byte elements (dtor
// FUN_005b8000), frees six begin/end/cap buffer triples, destroys StdList at
// this+0x0C via StdList_Destroy_FreeHead (aa_00497360).
//
// Scalar deleting wrapper (vtbl[0]): FUN_004975e0 @ 0x004975e0.

#include <cstdint>

extern "C" void *__cdecl operator_delete(void *p);
extern "C" void *__cdecl operator_delete__(void *p); // operator delete[]
extern "C" void __cdecl _eh_vector_destructor_iterator_(
    void *array, unsigned size, int count, void (__thiscall *dtor)(void *));
extern "C" void __thiscall FUN_005b8000(void *elem); // element dtor, stride 0x28
extern "C" void __thiscall StdList_Destroy_FreeHead(void *list); // FUN_00497360
extern "C" void *PTR_FUN_009c7a1c;

static void free_buf_triple(uint8_t *self, unsigned begin_off)
{
  void *begin = *reinterpret_cast<void **>(self + begin_off);
  if (begin != nullptr) {
    operator_delete(begin);
  }
  *reinterpret_cast<void **>(self + begin_off) = nullptr;
  *reinterpret_cast<void **>(self + begin_off + 4) = nullptr;
  *reinterpret_cast<void **>(self + begin_off + 8) = nullptr;
}

// __thiscall; ECX = this; void; bare RET (SEH epilogue omitted in clean)
void __thiscall Class_009c7a1c_CompleteDtor(void *self)
{
  auto *base = reinterpret_cast<uint8_t *>(self);

  *reinterpret_cast<void **>(base + 0) = &PTR_FUN_009c7a1c;

  void *arr = *reinterpret_cast<void **>(base + 0x28);
  if (arr != nullptr) {
    int count = *reinterpret_cast<int *>(reinterpret_cast<uint8_t *>(arr) - 4);
    _eh_vector_destructor_iterator_(arr, 0x28, count, FUN_005b8000);
    operator_delete__(reinterpret_cast<uint8_t *>(arr) - 4);
  }
  *reinterpret_cast<void **>(base + 0x28) = nullptr;
  *reinterpret_cast<void **>(base + 0x04) = nullptr;
  *reinterpret_cast<void **>(base + 0x08) = nullptr;

  free_buf_triple(base, 0xBC);
  free_buf_triple(base, 0xAC);
  free_buf_triple(base, 0x9C);
  free_buf_triple(base, 0x40);
  free_buf_triple(base, 0x30);
  free_buf_triple(base, 0x1C);

  // image: lea ecx, [esi+0x0C]; call StdList_Destroy_FreeHead
  StdList_Destroy_FreeHead(base + 0x0C);
}

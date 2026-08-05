// =============================================================================
// FUN_004e7350  (scaffold alias → StdMap_Dtor_Val12)
// -----------------------------------------------------------------------------
// Stable ID: aa_004e7350
// Address:   0x004e7350  (autoassault.exe, image base 0x400000)
// System:    std map Val12 destructor
// Wave:      W29-M (2026-07-29) — refined from 2026-07-23 scaffold
// Exactness: Behavior-preserving. Bit-for-bit: DEFERRED.
// =============================================================================
// Named clean: docs/reconstruction/reconstructed-exact/StdMap_Dtor_Val12.cpp
//
// Byte-sealed algorithm (read_memory; no disassemble_bytes):
//   erase_range(map, begin=*head, end=head);
//   operator_delete(head);
//   head=0; size=0;
//   ret (C3)
// Body: 0x004e7350–0x004e737e exclusive (46 B). Ghidra end 0x004e736f stale.
// Decompiler false-noreturn on operator_delete — post-delete nulls are real.
// =============================================================================

#include <cstdint>

// FUN_004e5120
extern "C" void __thiscall FUN_004e5120(void* map, void* outIt, void* first, void* last);
extern "C" void __cdecl operator_delete(void* p);

// Ghidra symbol preserved for scaffold cross-ref
void __thiscall FUN_004e7350(std::uint8_t* map /* ECX */)
{
  void* outIt = map; // local slot; value unused after erase
  void* head = *reinterpret_cast<void**>(map + 4);
  void* begin = *reinterpret_cast<void**>(head);

  FUN_004e5120(map, &outIt, begin, head);

  operator_delete(*reinterpret_cast<void**>(map + 4));
  *reinterpret_cast<void**>(map + 4) = nullptr;       // head
  *reinterpret_cast<std::uint32_t*>(map + 8) = 0;     // size
}

// =============================================================================
// StdList_Destroy_FreeHead  (named twin of FUN_00497360)
// -----------------------------------------------------------------------------
// Stable ID: aa_00497360
// Address:   0x00497360  (autoassault.exe, image base 0x400000)
// Body:      72 B; bare RET
// System:    shared / MSVC std::list
// Refined:   2026-07-29 W27-K
// =============================================================================

#include <cstdint>

extern "C" void operator_delete(void *p);

void __fastcall StdList_Destroy_FreeHead(void *list)
{
  uint8_t *l = reinterpret_cast<uint8_t *>(list);
  uint32_t *head = *reinterpret_cast<uint32_t **>(l + 4);
  void *node = reinterpret_cast<void *>(*head);

  *head = reinterpret_cast<uint32_t>(head);
  *reinterpret_cast<uint32_t *>(*reinterpret_cast<int *>(l + 4) + 4) =
      *reinterpret_cast<uint32_t *>(l + 4);
  *reinterpret_cast<uint32_t *>(l + 8) = 0;

  if (node != *reinterpret_cast<void **>(l + 4)) {
    do {
      void *next = *reinterpret_cast<void **>(node);
      operator_delete(node);
      node = next;
    } while (node != *reinterpret_cast<void **>(l + 4));
  }

  operator_delete(*reinterpret_cast<void **>(l + 4));
  *reinterpret_cast<uint32_t *>(l + 4) = 0;
}

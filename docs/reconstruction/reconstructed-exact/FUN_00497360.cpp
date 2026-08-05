// =============================================================================
// FUN_00497360 / StdList_Destroy_FreeHead
// -----------------------------------------------------------------------------
// Stable ID: aa_00497360
// Address:   0x00497360  (autoassault.exe, image base 0x400000)
// Body:      0x00497360–0x004973a7 (72 B); bare RET
// System:    shared / MSVC std::list
// Generated: 2026-07-23 scaffold; refined 2026-07-29 W27-K (read_memory seals loop)
// Exactness: Byte-level CF (decompiler collapsed free-loop + false noreturn).
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: Destroy MSVC circular list object: orphan head, free all nodes,
//          free sentinel, null list+4. Not clear-only (sentinel is deleted).
// Layout: list+4 = head/sentinel*, list+8 = size.
// Sibling: StdList_Destroy_FreeHead_Inferred @ 0x00403430 (clear helper + free head).

#include <cstdint>

extern "C" void operator_delete(void *p);

// ECX = list*; void; bare RET
void __fastcall FUN_00497360(void *list)
{
  uint8_t *l = reinterpret_cast<uint8_t *>(list);
  uint32_t *head = *reinterpret_cast<uint32_t **>(l + 4);
  void *node = reinterpret_cast<void *>(*head); // first = head->_Next

  *head = reinterpret_cast<uint32_t>(head); // head->_Next = head
  *reinterpret_cast<uint32_t *>(
      *reinterpret_cast<int *>(l + 4) + 4) =
      *reinterpret_cast<uint32_t *>(l + 4); // head->_Prev = head
  *reinterpret_cast<uint32_t *>(l + 8) = 0; // size = 0

  if (node != *reinterpret_cast<void **>(l + 4)) {
    do {
      void *next = *reinterpret_cast<void **>(node); // node->_Next
      operator_delete(node);
      node = next;
    } while (node != *reinterpret_cast<void **>(l + 4));
  }

  operator_delete(*reinterpret_cast<void **>(l + 4)); // free sentinel
  *reinterpret_cast<uint32_t *>(l + 4) = 0;           // null head
}

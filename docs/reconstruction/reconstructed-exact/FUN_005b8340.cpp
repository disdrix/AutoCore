// =============================================================================
// FUN_005b8340  (scaffold twin of CircularListHead_ClearFreeNodes_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_005b8340
// Address:   0x005b8340–0x005b8369 exclusive (41 B)
// Wave:      W37-AC 2026-08-04 — keeps FUN_* surface; prefer named clean.
// NOTE: Scaffold decompile collapsed the free-loop; this twin restores it.
// =============================================================================

#include <cstdint>

extern "C" void operator_delete(void* p);

// ECX = list head; bare C3
extern "C" void __fastcall FUN_005b8340(void* head)
{
    void* first = *reinterpret_cast<void**>(static_cast<char*>(head) + 4);
    *reinterpret_cast<void**>(static_cast<char*>(head) + 4) = head;
    *reinterpret_cast<void**>(head) = head;

    if (first == nullptr || first == head)
        return;

    void* node = first;
    do {
        void* next = *reinterpret_cast<void**>(static_cast<char*>(node) + 4);
        operator_delete(node);  // cdecl; continues (not noreturn)
        node = next;
    } while (node != head);
}

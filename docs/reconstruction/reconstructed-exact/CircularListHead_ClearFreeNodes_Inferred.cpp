// =============================================================================
// CircularListHead_ClearFreeNodes_Inferred  (aa_005b8340)
// -----------------------------------------------------------------------------
// Address:   0x005b8340–0x005b8369 exclusive (41 B / 0x29); pad CC
// Module:    autoassault.exe @ 0x400000
// Wave:      W37-AC OWN-ONLY dual 2026-08-04
// Exactness: Behavior-preserving from decompile + read_memory free-loop restore.
//            Not modernization. Bit-for-bit / runtime / differential: DEFERRED.
// =============================================================================

#include <cstdint>

// Minimal circular list head / sentinel. Callers pass ECX = this node.
// Empty: link0 == link4 == this. Nodes beyond the head are heap blocks.
struct CircularListHead {
    CircularListHead* link0;  // +0  (likely prev; not walked)
    CircularListHead* link4;  // +4  (walk / next-or-prev direction)
};

extern "C" void operator_delete(void* p);  // cdecl

// ECX = head/sentinel; bare RET; void.
// Re-ring head to empty circular, then operator_delete every former node
// reached via +4 until back at head. No element destructor. Head not freed.
extern "C" void __fastcall CircularListHead_ClearFreeNodes_Inferred(
    CircularListHead* head)
{
    CircularListHead* first = head->link4;
    head->link4 = head;
    head->link0 = head;

    if (first == nullptr || first == head)
        return;

    CircularListHead* node = first;
    do {
        CircularListHead* next = node->link4;
        operator_delete(node);
        node = next;
    } while (node != head);
}

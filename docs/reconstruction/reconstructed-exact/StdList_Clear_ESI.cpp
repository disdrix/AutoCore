// =============================================================================
// StdList_Clear_ESI  (aa_00415e90)
// -----------------------------------------------------------------------------
// Address:   0x00415e90 – 0x00415ec6 exclusive (54 B / 0x36)
//            autoassault.exe, image base 0x400000
// Wave:      WQ9L-H OWN-ONLY dual 2026-08-05
// Exactness: Behavior-preserving rewrite from decompile + full-body
//            read_memory (free loop restored; decompiler false-noreturn
//            on operator_delete truncates pseudocode).
// Bit-for-bit vs retail EXE: DEFERRED.
// ABI:       ESI = list*; bare RET; void. No stack formals.
// Twin:      StdList_Clear_Inferred @ 0x00404060 (ECX thiscall → ESI body)
// Parent:    CNDUIDialog_CompleteDtor @ 0x00792c20 (ESI = this+0x4dc)
// =============================================================================
//
// PURPOSE:
//   Clear MSVC circular std::list shell without freeing the list object or
//   the sentinel: re-ring head next/prev to self, size=0, operator_delete
//   every former element node until back at head.
//
// ABI (machine):
//   ESI = list*  (head @ +4, size @ +8). Bare RET. void.
//   Not ECX thiscall — twin 0x00404060 is the ECX form.
//
// REJECT:
//   - Freeing sentinel (parents may delete *(list+4) after)
//   - Value/element dtors (only operator_delete on node*)
//   - Merge with StdList_Destroy_FreeHead (frees head after clear)
//   - Merge with ECX twin as same VA
// =============================================================================

#include <cstdint>

extern "C" void __cdecl operator_delete(void* p);

// MSVC-style circular list node. Payload after +8 not destroyed here.
struct StdListNode_ClearEsi {
  StdListNode_ClearEsi* next; // +0
  StdListNode_ClearEsi* prev; // +4
};

// MSVC-style list shell used by this leaf: +4 head, +8 size.
struct StdListShell_ClearEsi {
  void* unused0;              // +0 (not touched by this unit)
  StdListNode_ClearEsi* head; // +4 sentinel*
  std::uint32_t size;         // +8
};

// Port form: explicit list*. Retail entry expects list* already in ESI.
extern "C" void StdList_Clear_ESI(StdListShell_ClearEsi* list)
{
  StdListNode_ClearEsi* head = list->head;
  StdListNode_ClearEsi* node = head->next;

  head->next = head;
  head->prev = head;
  list->size = 0;

  // Bytes seal multi-node free (decompiler shows only first delete).
  while (node != head) {
    StdListNode_ClearEsi* next = node->next;
    operator_delete(node);
    node = next;
  }
}

// =============================================================================
// StdList_Destroy_FreeHead_ViaClearEsi_Inferred  (aa_00402280)
// -----------------------------------------------------------------------------
// Address:   0x00402280 – 0x0040229c inclusive (29 B / 0x1D)
//            autoassault.exe, image base 0x400000
// Wave:      MEGA-067 OWN-ONLY dual 2026-08-05
// Exactness: Behavior-preserving rewrite from decompile + full-body
//            read_memory (null-head store restored; decompiler false-noreturn
//            on operator_delete truncates pseudocode).
// Bit-for-bit vs retail EXE: DEFERRED.
// ABI:       ECX = list shell*; bare RET; void. No stack formals.
// Clear:     StdList_Clear_ESI @ 0x00415e90 (ESI = list*)
// Twin:      StdList_Destroy_FreeHead_Inferred @ 0x00403430 (via Clear ECX)
// Ctor pair: FUN_004023f0 (alloc sentinel 0040fb90, size=0)
// =============================================================================
//
// PURPOSE:
//   Complete destroy of an MSVC circular std::list shell: clear all element
//   nodes (sentinel re-ringed, size=0), operator_delete the sentinel head at
//   list+4, then null list+4. Does not free the list shell object itself.
//
// ABI (machine):
//   ECX = list*. PUSH ESI; MOV ESI,ECX; CALL clear-ESI; free head; null; POP; RET.
//
// REJECT:
//   - Named_CalleeOf_*Mission_createNDUI* scaffold (shared util)
//   - Freeing the list shell (only sentinel + nodes)
//   - Merge with 00403430 / 00497360 as same VA
//   - Treating Ghidra "does not return" as real CF
// =============================================================================

#include <cstdint>

extern "C" void __cdecl operator_delete(void* p);

// Dualed clear leaf — retail expects list* already in ESI.
// Port form takes explicit pointer (see StdList_Clear_ESI.cpp).
extern "C" void StdList_Clear_ESI(/* ESI */ struct StdListShell_DestroyFreeHeadEsi* list);

struct StdListNode_DestroyFreeHeadEsi {
  StdListNode_DestroyFreeHeadEsi* next; // +0
  StdListNode_DestroyFreeHeadEsi* prev; // +4
  // payload after +8 not destroyed here (nodes freed as blobs)
};

// MSVC-style list shell: +4 head, +8 size; shell size 0xC at eh_vector sites.
struct StdListShell_DestroyFreeHeadEsi {
  void* unused0;                          // +0 (untouched)
  StdListNode_DestroyFreeHeadEsi* head;   // +4 sentinel*
  std::uint32_t size;                     // +8
};

// Retail: thiscall ECX = list*.
extern "C" void __fastcall StdList_Destroy_FreeHead_ViaClearEsi_Inferred(
    StdListShell_DestroyFreeHeadEsi* list)
{
  // 00402280: PUSH ESI; MOV ESI,ECX; CALL 00415e90
  StdList_Clear_ESI(list);

  // 00402288..00402291: operator_delete(*(list+4)); ADD ESP,4
  operator_delete(list->head);

  // 00402294: MOV dword ptr [ESI+4], 0  (decomp-hidden)
  list->head = nullptr;

  // 0040229b..9c: POP ESI; RET
}

// =============================================================================
// UiOwnedBlock_CompleteBeforeDelete_Inferred  (aa_00988710)
// -----------------------------------------------------------------------------
// Address:   0x00988710  (autoassault.exe, image base 0x400000)
// Body:      0x00988710–0x0098879e inclusive (143 B / 0x8F); pad CC @ 0x0098879f
// Wave:      MEGA-123 OWN-ONLY dual 2026-08-05
// System:    UI owned-block complete destructor (parent: gfxUIWindow_CompleteDtor)
// Exactness: Behavior-preserving rewrite from live decompile + disassemble_function
//            + read_memory (false-noreturn corrected). Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Complete destructor for a heap-owned UI block that embeds:
//     - tree/map shell  (head @ +0x04, size @ +0x08, isnil@node+0x25)
//     - refcounted iface (@ +0x0C; refcount @ iface+4; destroy vtbl[+8])
//   Does NOT free the host block — every caller pairs with operator_delete(host).
//   Partition hint: UiOwnedBlock_CompleteBeforeDelete. Product demangle open → _Inferred.
//
// ABI:
//   __fastcall / thiscall: ECX = this. SEH LAB_009ad7cd. bare RET (C3). void.
//
// PEERS:
//   Ctor twin: FUN_009886d0 (installs empty tree + null iface)
//   Tree erase: FUN_0044f3c0 (EDI = container)
//   Parent: gfxUIWindow_CompleteDtor 0x00759de0 frees slots +0xB0 / +0xB4
// =============================================================================

#include <cstdint>

struct UiOwnedBlock_Inferred {
  // +0x00 unused in this body
  void* head;                 // +0x04 tree sentinel
  std::uint32_t size;         // +0x08
  void* iface;                // +0x0C refcounted*
};

// Tree erase-range / clear; EDI = container (MSVC tree owner with head@+4).
// Signature sketch: iterator* out, node* first, node* last.
extern "C" void* __cdecl FUN_0044f3c0(void* out_it, void* first, void* last);
extern "C" void __cdecl operator_delete(void* p);

// Complete dtor only — does not free self.
extern "C" void __fastcall UiOwnedBlock_CompleteBeforeDelete_Inferred(UiOwnedBlock_Inferred* self)
{
  // SEH: PUSH -1; PUSH LAB_009ad7cd; FS:[0]=frame
  // EDI = self; EH state = 1; EBX = 0

  void* iface = self->iface;
  if (iface != nullptr) {
    // ADD dword [iface+4], -1
    std::uint32_t* ref = reinterpret_cast<std::uint32_t*>(
        reinterpret_cast<std::uint8_t*>(iface) + 4);
    *ref = *ref - 1;
    if (*ref == 0) {
      // CALL [ [iface] + 8 ]  — vtbl slot 2 destroy
      auto** vtbl = *reinterpret_cast<void***>(iface);
      auto destroy = reinterpret_cast<void(__fastcall*)(void*)>(vtbl[2]);
      destroy(iface);
    }
    self->iface = nullptr;
  }

  // EH state = 0 — residual release of same member (normally null after above)
  iface = self->iface;
  if (iface != nullptr) {
    std::uint32_t* ref = reinterpret_cast<std::uint32_t*>(
        reinterpret_cast<std::uint8_t*>(iface) + 4);
    *ref = *ref - 1;
    if (*ref == 0) {
      auto** vtbl = *reinterpret_cast<void***>(iface);
      auto destroy = reinterpret_cast<void(__fastcall*)(void*)>(vtbl[2]);
      destroy(iface);
    }
  }

  // EH state = -1
  // Machine: EDI remains self for FUN_0044f3c0 (unaff_EDI container)
  void* head = self->head;
  void* begin = *reinterpret_cast<void**>(head);  // head->left / begin
  void* it_storage = nullptr;
  FUN_0044f3c0(&it_storage, begin, head);

  operator_delete(head);  // free sentinel only; NOT host
  self->head = nullptr;
  self->size = 0;

  // SEH restore; bare RET
}

// Ghidra twin name
extern "C" void __fastcall FUN_00988710(UiOwnedBlock_Inferred* self)
{
  UiOwnedBlock_CompleteBeforeDelete_Inferred(self);
}

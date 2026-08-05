// =============================================================================
// GfxBufferedViews_ReleaseDeviceTextures_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_009686e0
// Address:   0x009686e0–0x00968715 exclusive (53 B / 0x35, autoassault.exe base 0x400000)
// System:    palantir/graphics — gfxBufferedView global list / Device Reset shutdown
// Generated: 2026-08-04 W38-AA dual A/B (decompile + read_memory + call-site context)
// Exactness: Behavior-preserving CF + ABI. Nested FUN_0096c8e0 summarized.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_009686e0
// =============================================================================
//
// PURPOSE:
//   During GfxDevice_Reset shutdown, walk the process-wide gfxBufferedView list
//   (DAT_00d1ee30) and release device-dependent textures for views whose texture
//   reset gate (*(tex+0x30)==0) is set. Does not destroy views or unlink nodes.
//
// ABI:
//   No stack formals; plain RET; ESI scratch (push/pop).
//   Callee FUN_0096c8e0 is thiscall ECX = texture at view+0x44.
//
// CALLER (sole):
//   GfxDevice_Reset (FUN_0075eff0) @ 0x0075f0ec — shutdown chain after IB/VB/Texture
//   factory shutdown helpers, before Effect-related teardown.
// =============================================================================

#include <cstdint>

struct ListNode {
  ListNode* next;     // +0x00
  ListNode* prev;     // +0x04 (unused here)
  void*     payload;  // +0x08  GfxBufferedView*
};

// Sentinel head pointer storage (MSVC list _Myhead style).
extern "C" ListNode* DAT_00d1ee30;

// effTextureImpl device-resource release / accounting (not owned).
extern "C" void __fastcall FUN_0096c8e0(void* tex_this);

extern "C" void GfxBufferedViews_ReleaseDeviceTextures_Inferred(void)
{
  ListNode* head = DAT_00d1ee30;
  // Retail: first = *head; compare to head (circular sentinel list).
  ListNode* node = reinterpret_cast<ListNode*>(*reinterpret_cast<void**>(head));
  if (node != head) {
    do {
      void* view = node->payload; // node[2] at +0x08
      if (view != nullptr) {
        void* tex = *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(view) + 0x44);
        if (*reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(tex) + 0x30) == 0) {
          FUN_0096c8e0(tex); // MOV ECX,tex; CALL
          head = DAT_00d1ee30;
        }
      }
      node = node->next; // *node
    } while (node != head);
  }
}

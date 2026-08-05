// =============================================================================
// GfxBufferedView_Ctor_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00968a50
// Address:   0x00968a50–0x00968b14 inclusive (197 B / 0xC5, autoassault.exe base 0x400000)
// System:    palantir/graphics — gfxBufferedView
// Generated: 2026-08-04 W37-I dual A/B (decompile + read_memory + caller context)
// Exactness: Behavior-preserving CF + ABI + layout zeros. Timer/list helpers summarized.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_00968a50
// Product:   C:\vog\1_code\palantir\palantir\graphics\gfxBufferedView.cpp
//            (vtbl-adjacent plates; "gfxBufferedView render target")
// =============================================================================
//
// PURPOSE:
//   Complete ctor for gfxBufferedView on a pre-allocated 0x198 block:
//     1) GfxView base ctor (0x150);
//     2) install derived vtbl PTR_FUN_00aa22a8;
//     3) init + start timer subobject at +0x150 (period 1000);
//     4) zero derived tail (+0x180..+0x194 defaults);
//     5) register this into process-wide std::list (*DAT_00d1ee30 / list@0x00d1ee2c);
//     6) return this.
//
// ABI:
//   ECX = this; 0 stack formals; returns this; SEH LAB_009b3023;
//   epilogue ADD ESP,0x14; RET.
//
// CALLERS (all new(0x198); MOV ECX,eax; CALL):
//   FUN_004c0a90 @ 0x004c0ae5 → phase+0x9c
//   FUN_0055ca90 @ 0x0055cae5 → host+0x90
//   FUN_005b3420 @ 0x005b3466 → host+0x158
//   FUN_0078c780 @ 0x0078c80c → host+0x2a4
// =============================================================================

#include <cstdint>

struct GfxBufferedView {
  void*    vtbl;           // +0x00  → PTR_FUN_00aa22a8 after base ctor
  uint8_t  gfx_view[0x14C]; // +0x04 … remainder of 0x150 GfxView base (opaque here)
  // +0x150: timer subobject (FUN_0076c500 / FUN_0076c4d0)
  // +0x180: uint32_t = 1
  // +0x184: uint32_t = 1
  // +0x188: float = 0
  // +0x18c: float = 0
  // +0x190: uint8_t = 0
  // +0x191: uint8_t = 0
  // +0x194: uint32_t = 0
  // size 0x198
};

extern "C" void* PTR_FUN_00aa22a8;
extern "C" void** DAT_00d1ee30; // &_Myhead-style head pointer storage
// list object for StdList_Incsize lives at 0x00d1ee2c (EDX)

extern "C" GfxBufferedView* __fastcall GfxView_Ctor_Inferred(GfxBufferedView* self);
extern "C" void* __thiscall FUN_0076c500(void* timer, uint32_t period);
extern "C" void  __fastcall FUN_0076c4d0(void* timer);
extern "C" void* FUN_006759b0(void* head, void* head_next, void** payload);
extern "C" void  __fastcall StdList_Incsize(uint32_t count, void* list); // FUN_0043fe60

// Retail: ECX=this; returns this
extern "C" GfxBufferedView* __fastcall GfxBufferedView_Ctor_Inferred(GfxBufferedView* self)
{
  // SEH LAB_009b3023 omitted

  GfxView_Ctor_Inferred(self); // FUN_0075ceb0 — base 0x150

  self->vtbl = &PTR_FUN_00aa22a8;

  void* timer = reinterpret_cast<uint8_t*>(self) + 0x150;
  FUN_0076c500(timer, 1000);
  *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(self) + 0x180) = 1;
  *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(self) + 0x184) = 1;
  FUN_0076c4d0(timer);

  *reinterpret_cast<float*>(reinterpret_cast<uint8_t*>(self) + 0x188) = 0.f;
  *reinterpret_cast<float*>(reinterpret_cast<uint8_t*>(self) + 0x18c) = 0.f;
  *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(self) + 0x190) = 0;
  *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(self) + 0x191) = 0;
  *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(self) + 0x194) = 0;

  void* head = *DAT_00d1ee30;
  void* head_next = *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(head) + 4);
  GfxBufferedView* payload = self;
  void* node = FUN_006759b0(head, head_next, reinterpret_cast<void**>(&payload));
  StdList_Incsize(1, reinterpret_cast<void*>(0x00d1ee2c));
  *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(head) + 4) = node;
  void* node_next = *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(node) + 4);
  *reinterpret_cast<void**>(node_next) = node; // node->next->prev = node (MSVC list link)

  return self;
}

// =============================================================================
// FUN_00968720
// -----------------------------------------------------------------------------
// Stable ID: aa_00968720
// Address:   0x00968720–0x00968831 exclusive (273 B / 0x111, autoassault.exe base 0x400000)
// System:    palantir/graphics — gfxBufferedView global list / Device Reset rebuild
// Generated: 2026-08-04 W38-AA dual A/B (decompile + read_memory + call-site context)
// Exactness: Behavior-preserving CF + ABI + product log plates. Nested helpers summarized.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_00968720
// Product:   C:\vog\1_code\palantir\palantir\graphics\gfxBufferedView.cpp : 0xCA
//            "Failure on ReCreate() of effTextureImpl %s for gfxBufferedView render target"
// =============================================================================
//
// PURPOSE:
//   During GfxDevice_Reset rebuild (after D3D Reset + IB/VB/Texture factories),
//   walk g_BufferedViewList and re-create render-target textures for views whose
//   texture gate (*(tex+0x30)==0). Always returns 0 (parent fail plate unreachable).
//
// ABI:
//   No stack formals; SEH LAB_009b11e5; returns 0 in EAX (XOR EAX,EAX); plain RET.
//
// CALLER (sole):
//   GfxDevice_Reset (FUN_0075eff0) @ 0x0075f2d9 — rebuild chain; parent tests EAX<0
//   against "Failed to Reset() device on gfxBufferedViews" (dead given always-0 return).
// =============================================================================

#include <cstdint>

struct ListNode {
  ListNode* next;
  ListNode* prev;
  void*     payload; // GfxBufferedView*
};

extern "C" ListNode* DAT_00d1ee30;
extern "C" void*     DAT_00d1ed24; // empty-name fallback

// ReCreate: thiscall ECX=tex; returns HRESULT-like int (<0 fail).
extern "C" int32_t __fastcall FUN_0096cad0(
    void* tex_this,
    uint32_t a_24, int32_t a_1c, uint32_t a_20,
    uint32_t a_34, uint32_t a_30, void* a_0c);

// Build "assId: [%s]" into out string; thiscall ECX = name source.
extern "C" void* __fastcall FUN_0096a630(void* name_src, void* out_basic_string);

extern "C" void* FUN_0076cec0(void* out, const char* fmt, const char* name);
extern "C" void  vog_LogMessage(const char* file, int line, int level, void* msg);

// MSVC basic_string dtor (IAT).
extern "C" void basic_string_dtor(void* s);

struct IUnknownVtbl {
  void* QueryInterface; // +0
  void* AddRef;         // +4
  int32_t (__stdcall* Release)(void* self); // +8
};

extern "C" int32_t FUN_00968720(void)
{
  // SEH LAB_009b11e5 + local basic_string omitted in structural port

  ListNode* head = DAT_00d1ee30;
  ListNode* node = reinterpret_cast<ListNode*>(*reinterpret_cast<void**>(head));

  if (node != head) {
    do {
      void* view = node->payload;
      if (view != nullptr) {
        uint8_t* tex = *reinterpret_cast<uint8_t**>(reinterpret_cast<uint8_t*>(view) + 0x44);
        head = DAT_00d1ee30;
        if (*reinterpret_cast<int32_t*>(tex + 0x30) == 0) {
          uint32_t flags = *reinterpret_cast<uint32_t*>(tex + 0x2c);
          if ((flags & 0x3000u) == 0) {
            int32_t hr = FUN_0096cad0(
                tex,
                *reinterpret_cast<uint32_t*>(tex + 0x24),
                *reinterpret_cast<int32_t*>(tex + 0x1c),
                *reinterpret_cast<uint32_t*>(tex + 0x20),
                *reinterpret_cast<uint32_t*>(tex + 0x34),
                *reinterpret_cast<uint32_t*>(tex + 0x30),
                *reinterpret_cast<void**>(tex + 0x0c));
            head = DAT_00d1ee30;
            if (hr < 0) {
              // name object at tex+0x4c; fallback DAT_00d1ed24; SSO c_str
              // sprintf + vog_LogMessage(gfxBufferedView.cpp, 0xCA, 5, msg)
              // ~basic_string
              (void)FUN_0096a630; // name helper used on fail path
              (void)FUN_0076cec0;
              (void)vog_LogMessage;
              (void)basic_string_dtor;
              (void)DAT_00d1ed24;
              head = DAT_00d1ee30;
            }
          } else {
            void** pobj = *reinterpret_cast<void***>(tex + 0x4c);
            IUnknownVtbl* vt = *reinterpret_cast<IUnknownVtbl**>(pobj);
            vt->Release(pobj);
            head = DAT_00d1ee30;
          }
        }
      }
      node = node->next;
    } while (node != head);
  }
  return 0;
}

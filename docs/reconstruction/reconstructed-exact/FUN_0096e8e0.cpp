// =============================================================================
// FUN_0096e8e0 — twin of EffTextureFactory_ReCreateDefaultPool_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0096e8e0
// Address:   0x0096e8e0–0x0096e9e4 exclusive (260 B / 0x104)
// Wave:      W38-AB 2026-08-04
// See:       EffTextureFactory_ReCreateDefaultPool_Inferred.cpp
// =============================================================================

#include <cstdint>

struct ListNode {
  ListNode* next;
  uint32_t  pad4;
  void*     value;
};

struct EffTextureFactory {
  uint8_t pad00[0x8];
  ListNode* head;
};

struct IUnknownVtbl {
  void* QueryInterface;
  void* AddRef;
  int (__stdcall *Release)(void* self);
};

struct IUnknownLike {
  IUnknownVtbl* vtbl;
};

struct EffTextureImpl {
  uint8_t pad00[0xc];
  void*   field_0c;
  uint8_t pad10[0xc];
  int32_t width;
  int32_t height;
  int32_t format;
  uint8_t pad28[0x4];
  uint32_t flags;
  int32_t  poolOrState;
  int32_t  levelsOrDepth;
  uint8_t pad38[0x14];
  IUnknownLike* sideIface;
};

struct BasicString {
  union {
    char* ptr;
    char  buf[16];
  };
  uint32_t size;
  uint32_t capacity;
};

extern "C" int __fastcall FUN_0096cad0(EffTextureImpl* self, int format, int width,
                                       int height, int levelsOrDepth, int zero, void* field0c);
extern "C" BasicString* __thiscall FUN_0096a630(EffTextureImpl* self, BasicString* out);
extern "C" void* FUN_0076cec0(void* scratch, const char* fmt, ...);
extern "C" void vog_LogMessage(const char* file, int line, int level, void* msg);
extern "C" void basic_string_char_dtor(BasicString* s);

static const char* CStr(BasicString* s) {
  if (s->capacity < 0x10u) {
    return reinterpret_cast<const char*>(reinterpret_cast<uint8_t*>(s) + 4);
  }
  return s->ptr;
}

// stack factory*; RET 4; returns hr
extern "C" int __stdcall FUN_0096e8e0(EffTextureFactory* factory) {
  ListNode* head = factory->head;
  ListNode* node = head->next;
  int hr = 0;

  if (node != head) {
    do {
      auto* impl = static_cast<EffTextureImpl*>(node->value);
      if (impl->poolOrState == 0) {
        hr = 0;
        if ((impl->flags & 0x3000u) == 0) {
          hr = FUN_0096cad0(impl, impl->format, impl->width, impl->height,
                            impl->levelsOrDepth, 0, impl->field_0c);
        } else if (impl->sideIface != nullptr) {
          impl->sideIface->vtbl->Release(impl->sideIface);
        }
        if (hr < 0) {
          BasicString name{};
          BasicString* built = FUN_0096a630(impl, &name);
          const char* cstr = CStr(built);
          void* msg = FUN_0076cec0(
              &factory, "Failure on ReCreate() of effTextureImpl %s at <%x>", cstr, impl);
          vog_LogMessage(
              "C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effTextureFactory.cpp",
              0x159, 5, msg);
          basic_string_char_dtor(&name);
          return hr;
        }
      }
      node = node->next;
    } while (node != head);
  }
  return hr;
}

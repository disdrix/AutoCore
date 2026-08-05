// =============================================================================
// EffTextureFactory_ReCreateDefaultPool_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0096e8e0
// Address:   0x0096e8e0–0x0096e9e4 exclusive (260 B / 0x104)
// Module:    autoassault.exe (image base 0x400000)
// System:    palantir graphics Effects — effTextureFactory ReCreate
// Wave:      W38-AB 2026-08-04
// Exactness: Behavior-preserving rewrite of decompiler CF + body hex.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Device-reset rebuild for DEFAULT-pool effect textures owned by an
//   effTextureFactory list. Walks circular intrusive list at factory+0x8;
//   for each impl with pool field +0x30 == 0, either re-creates GPU resources
//   via FUN_0096cad0 (create path releases first via FUN_0096c8e0) or Releases
//   a side interface at +0x4c when (flags & 0x3000). On first failure logs
//   effTextureFactory.cpp:0x159 and returns hr.
//
// ABI:
//   Stack factory*. Returns int hr in EAX. RET 4 (C2 04 00). SEH LAB_009b09a1.
//
// PARENT:
//   GfxDevice_Reset (FUN_0075eff0) @ 0x0075f2c2 — push device[+0x754], call.
//   Fail plate: "Failed to Reset() device on Texture Factory".
//
// STRINGS:
//   "Failure on ReCreate() of effTextureImpl %s at <%x>"
//   "C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effTextureFactory.cpp" : 0x159
//
// BYTES: see raw W38-AB append (260 B).
// REJECT: scaffold Named_effTextureFactory_0096e8e0 as sole product plate.
// =============================================================================

#include <cstdint>

struct ListNode {
  ListNode* next;     // +0
  uint32_t  pad4;     // +4
  void*     value;    // +8  → EffTextureImpl*
};

struct EffTextureFactory {
  uint8_t pad00[0x8];
  ListNode* head;     // +0x8  circular sentinel
};

struct IUnknownVtbl {
  void* QueryInterface;
  void* AddRef;
  int (__stdcall *Release)(void* self);
};

struct IUnknownLike {
  IUnknownVtbl* vtbl;
};

// Fields used by this VA (partial).
struct EffTextureImpl {
  uint8_t pad00[0xc];
  void*   field_0c;         // +0x0c → recreate arg
  uint8_t pad10[0xc];
  int32_t width;            // +0x1c
  int32_t height;           // +0x20
  int32_t format;           // +0x24
  uint8_t pad28[0x4];
  uint32_t flags;           // +0x2c
  int32_t  poolOrState;     // +0x30  (0 ⇒ DEFAULT / recreate)
  int32_t  levelsOrDepth;   // +0x34
  uint8_t pad38[0x14];
  IUnknownLike* sideIface;  // +0x4c  (0x3000 path)
};

// MSVC basic_string<char> shell (0x1c) — SSO threshold 0x10.
struct BasicString {
  union {
    char* ptr;
    char  buf[16];
  };
  uint32_t size;
  uint32_t capacity; // when capacity >= 0x10, data at ptr
};

extern "C" int __fastcall FUN_0096cad0(
    EffTextureImpl* self /*ECX*/,
    int format,
    int width,
    int height,
    int levelsOrDepth,
    int zero,
    void* field0c);

extern "C" BasicString* __thiscall FUN_0096a630(EffTextureImpl* self, BasicString* out);
extern "C" void* FUN_0076cec0(void* scratch, const char* fmt, ...);
extern "C" void vog_LogMessage(const char* file, int line, int level, void* msg);
extern "C" void basic_string_char_dtor(BasicString* s); // IAT

static const char* CStr(BasicString* s) {
  if (s->capacity < 0x10u) {
    return reinterpret_cast<const char*>(reinterpret_cast<uint8_t*>(s) + 4);
  }
  return s->ptr;
}

// stack factory*; RET 4
extern "C" int __stdcall EffTextureFactory_ReCreateDefaultPool_Inferred(EffTextureFactory* factory) {
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
        } else {
          // Release side interface; hr remains 0 on this branch.
          IUnknownLike* side = impl->sideIface;
          // decompiler: (**(code **)(**(int **)(iVar1 + 0x4c) + 8))();
          // load [impl+0x4c] then [*]+0 → call vtbl[2]
          (void)side; // call via side->vtbl->Release(side) — retail uses ECX/stack per COM
          if (side != nullptr) {
            side->vtbl->Release(side);
          }
        }
        if (hr < 0) {
          BasicString name{};
          BasicString* built = FUN_0096a630(impl, &name);
          const char* cstr = CStr(built);
          // FUN_0076cec0 reuses stack slot of factory* as format scratch in retail.
          void* msg = FUN_0076cec0(&factory,
                                   "Failure on ReCreate() of effTextureImpl %s at <%x>",
                                   cstr, impl);
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

extern "C" int __stdcall FUN_0096e8e0(EffTextureFactory* factory) {
  return EffTextureFactory_ReCreateDefaultPool_Inferred(factory);
}

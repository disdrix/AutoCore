// =============================================================================
// UI_CraftHost_BindResolvedObject_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Bind an already-resolved inventory object* (or null) into a craft /
//           reverse-engineering host UI panel: store selection, clear five
//           material/recipe slots, show/hide selection chrome, rebuild name
//           chrome widget (append ".geo"), attach to host, optionally fill
//           recipe rows, then refresh host chrome helpers.
//
// Address:  0x008e5990  (autoassault.exe, image base 0x400000)
// Stable:   aa_008e5990
// System:   inventory-transfer
//
// ABI (bytes + callers):
//   thiscall RET 4
//   ECX  = craft/UI host*
//   stack arg0 = resolved object* (nullable)
//
// Parent dual (not OWN): Client_UI_CraftHost_BindObjectByTfid_Inferred (0x008e5ce0)
//   resolves TFID → object* then calls this unit (null for invalid sentinel).
//
// Exactness: Behavior-preserving rewrite of sealed CF + ABI.
// Bit-for-bit / runtime / differential: OPEN (no Launcher).
// Dual: MEGA-032 2026-08-05
// Retired scaffold: Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RefreshOpen_008e5990
// =============================================================================

#include <cstdint>
#include <cstring>

// --- residual callees (not OWN this dual) ------------------------------------
extern void __thiscall FUN_008e2d60(void* host);
extern void*           operator_new(std::uint32_t size);
extern void* __fastcall FUN_00764030(void* self);  // chrome ctor size 0x14c
// basic_string-like fill: ECX = string*, stack (src_cstr?, helper)
extern void __thiscall FUN_00403450(void* str_this, void* a, void* b);
extern void* (__cdecl* PTR_FUN_00af8c9c)(void);  // string-related helper
extern void            free(void* p);
// ECX = 0x00d1eac8 (global string arena / helper this)
extern void __thiscall FUN_00989e00(void* self, void* out_str, char* cstr);
extern void            FUN_007afe80(void* chrome, int flag);
// assembly: MOV ECX, [[obj+0xa8]+0x3c]; CALL — thiscall on template*
extern int  __thiscall FUN_00599dd0(void* template_ptr);
// assembly: ECX=template+0x498; PUSH recipe; EAX=host+0x57c
extern void __fastcall FUN_008e5120(void* ecx, int recipe, void* eax_host_57c);
extern int             FUN_004ce940(void);
// assembly: PUSH slot; MOV EAX,host; CALL
extern void            FUN_008e5220(void* host_via_eax, void* slot_stack);
extern void            FUN_008e4ea0(void);
extern void __thiscall FUN_008e55e0(void* host);
extern void __thiscall FUN_008e47d0(void* host);

extern char DAT_00a28904[];  // ".geo\0" at 0x00a28904

static constexpr int kSlotCount     = 5;
static constexpr int kChromeSize    = 0x14c;
static constexpr int kTypeTagDirect = 0xc;

// Host offsets
static constexpr int off_attach   = 0x520;
static constexpr int off_w530     = 0x530;
static constexpr int off_w54c     = 0x54c;
static constexpr int off_slots    = 0x568;  // 5 ptr widgets
// companions: from slot base pointer pi at +0x568, pi[5] is first companion
static constexpr int off_tfid     = 0x590;  // 5 × {u32,u32}
static constexpr int off_recipe   = 0x61c;  // 5 × 0x14
static constexpr int off_preview  = 0x754;
static constexpr int off_bound    = 0x7cc;
static constexpr int off_chrome   = 0x7d0;
static constexpr int off_status   = 0x7da;

// Object offsets
static constexpr int off_obj_lo   = 0x160;
static constexpr int off_obj_hi   = 0x164;
static constexpr int off_obj_aux  = 0xa8;   // param_2[0x2a]

// Aux offsets (*aux)
static constexpr int off_aux_type = 0x38;
static constexpr int off_aux_tmpl = 0x3c;

// Vtable byte offsets
static constexpr int vt_dtor      = 0x00;
static constexpr int vt_show      = 0x04;
static constexpr int vt_attach    = 0x40;
static constexpr int vt_detach    = 0x44;
static constexpr int vt_clear58   = 0x58;
static constexpr int vt_setname   = 0x5c;
static constexpr int vt_count     = 0x60;
static constexpr int vt_getname   = 0x1c0;
static constexpr int vt_query2bc  = 0x2bc;
static constexpr int vt_preview   = 0x448;

static inline void** vtbl(void* o) {
  return *reinterpret_cast<void***>(o);
}
static inline void* vslot(void* o, int off) {
  return *reinterpret_cast<void**>(reinterpret_cast<char*>(vtbl(o)) + off);
}

static void append_geo(char* buf) {
  char* p = buf;
  while (*p) ++p;
  // retail: store dword DAT_00a28904 (".geo") then byte DAT_00a28908 ('\0')
  *reinterpret_cast<std::uint32_t*>(p) =
      *reinterpret_cast<const std::uint32_t*>(DAT_00a28904);
  p[4] = DAT_00a28904[4];
}

void __thiscall UI_CraftHost_BindResolvedObject_Inferred(void* host, int* object) {
  auto* h = reinterpret_cast<std::uint8_t*>(host);

  // 1) Store bound object first (assembly: MOV [ESI+0x7cc],EAX before chrome test)
  *reinterpret_cast<int**>(h + off_bound) = object;

  // 2) Orphan chrome delete when attach root missing
  void* chrome = *reinterpret_cast<void**>(h + off_chrome);
  if (chrome != nullptr && *reinterpret_cast<void**>(h + off_attach) == nullptr) {
    auto dtor = reinterpret_cast<void(__thiscall*)(void*, int)>(vslot(chrome, vt_dtor));
    dtor(chrome, 1);
    *reinterpret_cast<void**>(h + off_chrome) = nullptr;
  }

  FUN_008e2d60(host);

  // 3) Clear five slots: widgets @ +0x568, companions @ widget_row+0x14, pairs @ +0x590
  auto* widgets = reinterpret_cast<void**>(h + off_slots);
  auto* pairs   = reinterpret_cast<std::uint32_t*>(h + off_tfid);
  for (int i = 0; i < kSlotCount; ++i) {
    void* w = widgets[i];
    if (w != nullptr) {
      auto q = reinterpret_cast<int(__thiscall*)(void*)>(vslot(w, vt_query2bc));
      if (q(w) != 0) {
        auto c = reinterpret_cast<void(__thiscall*)(void*)>(vslot(w, vt_clear58));
        c(w);
      }
      auto sh = reinterpret_cast<void(__thiscall*)(void*, int)>(vslot(w, vt_show));
      sh(w, 0);
    }
    // piVar8[5] with piVar8 = &widgets[i] → companion at widgets[i+5]
    void* companion = widgets[i + 5];
    if (companion != nullptr) {
      auto dtor = reinterpret_cast<void(__thiscall*)(void*, int)>(vslot(companion, vt_dtor));
      dtor(companion, 1);
    }
    widgets[i + 5] = nullptr;
    pairs[i * 2 + 0] = 0xFFFFFFFFu;
    pairs[i * 2 + 1] = 0xFFFFFFFFu;
  }

  // 4) Clear status blob +0x7da..+0x7e0 (4 + 2 + 1)
  *reinterpret_cast<std::uint32_t*>(h + off_status) = 0;
  *reinterpret_cast<std::uint16_t*>(h + off_status + 4) = 0;
  *(h + off_status + 6) = 0;

  void* w530    = *reinterpret_cast<void**>(h + off_w530);
  void* w54c    = *reinterpret_cast<void**>(h + off_w54c);
  void* attach  = *reinterpret_cast<void**>(h + off_attach);
  void* preview = *reinterpret_cast<void**>(h + off_preview);

  if (object == nullptr) {
    // ---- clear / hide path ----
    if (w530) {
      auto sh = reinterpret_cast<void(__thiscall*)(void*, int)>(vslot(w530, vt_show));
      sh(w530, 0);
    }
    if (w54c) {
      auto sh = reinterpret_cast<void(__thiscall*)(void*, int)>(vslot(w54c, vt_show));
      sh(w54c, 0);
    }
    if (attach) {
      auto det = reinterpret_cast<void(__thiscall*)(void*)>(vslot(attach, vt_detach));
      det(attach);
    }
    if (preview) {
      auto pr = reinterpret_cast<void(__thiscall*)(void*, int, int)>(vslot(preview, vt_preview));
      pr(preview, -1, -1);
    }
  } else {
    // ---- bind path ----
    if (w530) {
      auto sh = reinterpret_cast<void(__thiscall*)(void*, int)>(vslot(w530, vt_show));
      sh(w530, 1);
    }
    if (w54c) {
      auto sh = reinterpret_cast<void(__thiscall*)(void*, int)>(vslot(w54c, vt_show));
      sh(w54c, 1);
    }
    if (preview) {
      auto pr = reinterpret_cast<void(__thiscall*)(void*, int, int)>(vslot(preview, vt_preview));
      int lo = *reinterpret_cast<int*>(reinterpret_cast<char*>(object) + off_obj_lo);
      int hi = *reinterpret_cast<int*>(reinterpret_cast<char*>(object) + off_obj_hi);
      pr(preview, lo, hi);
    }

    // Allocate chrome 0x14c + FUN_00764030
    void* mem = operator_new(static_cast<std::uint32_t>(kChromeSize));
    void* newChrome = (mem != nullptr) ? FUN_00764030(mem) : nullptr;
    *reinterpret_cast<void**>(h + off_chrome) = newChrome;

    // Name buffer (retail stack ~[ESP+0x98], capacity covers .geo append)
    char nameBuf[0x100];
    nameBuf[0] = '\0';

    void* aux = *reinterpret_cast<void**>(reinterpret_cast<char*>(object) + off_obj_aux);
    int typeTag = *reinterpret_cast<int*>(reinterpret_cast<char*>(aux) + off_aux_type);

    if (typeTag == kTypeTagDirect) {
      auto getn = reinterpret_cast<char*(__thiscall*)(void*)>(vslot(object, vt_getname));
      const char* src = getn(object);
      char* d = nameBuf;
      char c;
      do {
        c = *src++;
        *d++ = c;
      } while (c != '\0');
    } else {
      // Template string: FUN_00403450 on SSO/heap string from *(aux+0x3c)+0x10
      void* tmpl = *reinterpret_cast<void**>(reinterpret_cast<char*>(aux) + off_aux_tmpl);
      char sso[128];
      char* heapOrSso = sso;
      void* helper = PTR_FUN_00af8c9c ? PTR_FUN_00af8c9c() : nullptr;
      // thiscall string fill: ECX = &heapOrSso wrapper — retail uses stack string object
      // Keep call shape from disasm: PUSH helper; PUSH tmpl+0x10; LEA ECX,str; CALL 00403450
      struct {
        char* p;
        char buf[127];
      } strObj;
      strObj.p = strObj.buf;
      FUN_00403450(&strObj, reinterpret_cast<char*>(tmpl) + 0x10, helper);
      // copy strObj.p → nameBuf
      {
        const char* src = strObj.p;
        char* d = nameBuf;
        char c;
        do {
          c = *src++;
          *d++ = c;
        } while (c != '\0');
      }
      if (strObj.p != strObj.buf) {
        free(strObj.p);
      }
      (void)heapOrSso;
    }

    append_geo(nameBuf);

    // FUN_00989e00 with ECX=0x00d1eac8; chrome vtbl+0x5c(tmpStr)
    if (newChrome != nullptr) {
      void* tmpStr = nullptr;
      // retail: MOV ECX,0xd1eac8; PUSH nameBuf; PUSH &tmpStr; CALL 00989e00
      FUN_00989e00(reinterpret_cast<void*>(0x00d1eac8), &tmpStr, nameBuf);
      auto setn = reinterpret_cast<void(__thiscall*)(void*, void*)>(vslot(newChrome, vt_setname));
      setn(newChrome, &tmpStr);
    }

    if (attach != nullptr && newChrome != nullptr) {
      auto at = reinterpret_cast<void(__thiscall*)(void*, void*, int)>(vslot(attach, vt_attach));
      at(attach, newChrome, 1);
    }
    if (newChrome != nullptr) {
      FUN_007afe80(newChrome, 1);
    }

    // FUN_00599dd0(thiscall ECX = *(aux+0x3c) == template)
    void* template_ptr =
        *reinterpret_cast<void**>(reinterpret_cast<char*>(aux) + off_aux_tmpl);
    int recipe = FUN_00599dd0(template_ptr);
    if (recipe == 0) {
      // Early SEH exit — does NOT call FUN_008e55e0 / FUN_008e47d0
      return;
    }

    // FUN_008e5120(ECX=template+0x498, push recipe, EAX=host+0x57c)
    FUN_008e5120(reinterpret_cast<char*>(template_ptr) + 0x498, recipe, h + 0x57c);
    h[off_status] = 1;  // +0x7da = 1

    int gate = FUN_004ce940();
    auto cnt = reinterpret_cast<int(__thiscall*)(void*)>(vslot(object, vt_count));
    int n = cnt(object);
    if (gate != 0 && n > 0) {
      auto* slot = h + off_recipe;  // +0x61c
      for (int i = 0; i < kSlotCount; ++i) {
        FUN_008e5220(host, slot);
        slot += 0x14;
      }
    }
    FUN_008e4ea0();
  }

  // Common path (skipped only by 599dd0 early return)
  FUN_008e55e0(host);
  FUN_008e47d0(host);
  // RET 4
}

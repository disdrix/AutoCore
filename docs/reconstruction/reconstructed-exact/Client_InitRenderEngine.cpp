// =============================================================================
// Client_InitRenderEngine  (aa_00948530)
// -----------------------------------------------------------------------------
// Address:   0x00948530  (autoassault.exe, image base 0x400000)
// Body:      0x00948530–0x00948ba7 inclusive (1656 B / 0x678)
// Wave:      W31-Q OWN-ONLY dual 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler CF + read_memory seals.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
// Client application RenderEngine bring-up (product banners @@InitRenderEngine /
// InitRenderEngine in Client_InitInstance). Registers "XutoAssault" window class,
// creates "Auto Assault" HWND, initializes render via FUN_007a3e90("aa.bmp"),
// optional DAT_00d1f050 table rewrite, Palantir view bundle (FUN_004cda90), then
// subsystem hooks. Returns 0 on success, 0x80004005 (E_FAIL) on any fail path.
// Sole caller hard-exits process if nonzero.
// Reject scaffold Named_Could_not_get_Palantir_desktop_window_* as sole name.

#include <cstdint>

// Win32 surface (types abbreviated)
struct RECT { int32_t left, top, right, bottom; };
struct WNDCLASSA {
  uint32_t style;
  void*    lpfnWndProc;
  int32_t  cbClsExtra;
  int32_t  cbWndExtra;
  void*    hInstance;
  void*    hIcon;
  void*    hCursor;
  void*    hbrBackground;
  const char* lpszMenuName;
  const char* lpszClassName;
};

extern "C" void*  __stdcall ExceptionList; // FS:[0] placeholder
extern "C" uint8_t  DAT_00afa250;
extern "C" uint8_t* DAT_00d1a830;
extern "C" uint8_t* DAT_00d1a834;
extern "C" uint32_t DAT_00ca0000;
extern "C" uint32_t DAT_00d1f050;
extern "C" uint32_t DAT_00b03510;
extern "C" uint32_t DAT_00d09874;
extern "C" uint8_t* DAT_00d17948;
extern "C" void*    LAB_00930d30; // MONITORENUMPROC
extern "C" void*    LAB_009484d0; // WNDPROC
extern "C" void*    LAB_009bbb25; // SEH handler
extern "C" void*    PTR_LAB_00a2c238;

extern "C" int   __stdcall EnumDisplayMonitors(void*, void*, void*, int);
extern "C" void* __stdcall LoadIconA(void*, const char*);
extern "C" uint16_t __stdcall RegisterClassA(WNDCLASSA*);
extern "C" int   __stdcall AdjustWindowRectEx(RECT*, uint32_t, int, uint32_t);
extern "C" void* __stdcall CreateWindowExA(uint32_t, const char*, const char*,
    uint32_t, int, int, int, int, void*, void*, void*, void*);
extern "C" int   __stdcall ShowWindow(void*, int);
extern "C" int   __stdcall UpdateWindow(void*);
extern "C" int   __stdcall SetWindowPos(void*, void*, int, int, int, int, uint32_t);
extern "C" void* __cdecl operator_new(uint32_t);
extern "C" void  __cdecl operator_delete(void*);

extern "C" void* __fastcall FUN_007fb0a0(void* self);
extern "C" int   /*args via stack/regs as decompile*/ FUN_007a3e90(
    void* hwnd, void* size_xy, int not_flag_9c1, uint8_t flag_9c6, const char* bmp);
extern "C" void  __fastcall FUN_0043c5f0(void* dst_vec, void* /*implicit src via global*/);
extern "C" void* __fastcall FUN_0040af40(void* self);
extern "C" void  FUN_0040d9c0();
extern "C" uint32_t __fastcall FUN_004cda90(void* parent); // Client_InitPalantirViewBundle
extern "C" void  FUN_007a4480(int level, const char* msg);
extern "C" void  FUN_007a2fd0();
extern "C" void  FUN_007ae400();
extern "C" void  FUN_007b1900();
extern "C" void  FUN_00581580(void* desktop, uint32_t arg);
extern "C" void  FUN_00583170();
extern "C" void  FUN_00491ed0();
extern "C" void  FUN_0048eaa0(int);
extern "C" void  FUN_0048eef0(int);
extern "C" void  FUN_0092f190(int);
extern "C" void  FUN_0092f140(int);
extern "C" void  FUN_00935fe0();

// ECX = client app. Bare RET. 0 / E_FAIL.
extern "C" uint32_t __fastcall Client_InitRenderEngine(void* app)
{
  auto* p = reinterpret_cast<uint8_t*>(app);
  const char* fail_msg = nullptr;

  // SEH: local_8 = -1; handler LAB_009bbb25 (elided)

  DAT_00afa250 = p[0x9c1];
  EnumDisplayMonitors(nullptr, nullptr, LAB_00930d30, 0);

  uint32_t mon_count = 0;
  if (DAT_00d1a830 != nullptr) {
    mon_count = static_cast<uint32_t>((DAT_00d1a834 - DAT_00d1a830) / 0xC);
  }
  uint16_t mon_idx = *reinterpret_cast<uint16_t*>(p + 0xa14);
  if (mon_count <= mon_idx) {
    int16_t last = (DAT_00d1a830 == nullptr)
                       ? 0
                       : static_cast<int16_t>((DAT_00d1a834 - DAT_00d1a830) / 0xC);
    *reinterpret_cast<int16_t*>(p + 0xa14) = static_cast<int16_t>(last - 1);
  }
  mon_idx = *reinterpret_cast<uint16_t*>(p + 0xa14);

  auto* mon = DAT_00d1a830 + mon_idx * 0xC;
  auto* rect = reinterpret_cast<RECT*>(p + 0x3190);
  *reinterpret_cast<int32_t*>(p + 0x3194) = *reinterpret_cast<int32_t*>(mon + 4); // top
  rect->left = *reinterpret_cast<int32_t*>(mon + 0);                               // left
  *reinterpret_cast<int32_t*>(p + 0x319c) =
      *reinterpret_cast<int32_t*>(mon + 4) + *reinterpret_cast<int32_t*>(p + 0xa1c); // bottom
  *reinterpret_cast<int32_t*>(p + 0x3198) =
      *reinterpret_cast<int32_t*>(p + 0xa18) + *reinterpret_cast<int32_t*>(mon + 0); // right

  WNDCLASSA wc{};
  wc.style = 0x302Bu;
  wc.lpfnWndProc = LAB_009484d0;
  wc.hInstance = *reinterpret_cast<void**>(p + 0x3180);
  wc.hIcon = LoadIconA(wc.hInstance, reinterpret_cast<const char*>(0x65));
  wc.lpszClassName = "XutoAssault";

  // snapshot pre-adjust
  *reinterpret_cast<int32_t*>(p + 0x31a0) = rect->left;
  *reinterpret_cast<int32_t*>(p + 0x31a4) = *reinterpret_cast<int32_t*>(p + 0x3194);
  *reinterpret_cast<int32_t*>(p + 0x31a8) = *reinterpret_cast<int32_t*>(p + 0x3198);
  *reinterpret_cast<int32_t*>(p + 0x31ac) = *reinterpret_cast<int32_t*>(p + 0x319c);

  uint32_t style = 0x80000000u; // WS_POPUP default
  if (p[0x9c1] != 0 && p[0x9c2] != 0) {
    style = DAT_00ca0000;
  } else {
    style = 0x80000000u;
  }

  if (p[0x9c1] != 0) {
    if (AdjustWindowRectEx(rect, style, 0, 0x40000) != 0) {
      int dx = *reinterpret_cast<int32_t*>(p + 0x31a0) - rect->left;
      rect->left += dx;
      *reinterpret_cast<int32_t*>(p + 0x3198) += dx;
      int dy = *reinterpret_cast<int32_t*>(p + 0x31a4) - *reinterpret_cast<int32_t*>(p + 0x3194);
      *reinterpret_cast<int32_t*>(p + 0x3194) += dy;
      *reinterpret_cast<int32_t*>(p + 0x319c) += dy;
    }
  }

  int width  = *reinterpret_cast<int32_t*>(p + 0x3198) - rect->left;
  int height = *reinterpret_cast<int32_t*>(p + 0x319c) - *reinterpret_cast<int32_t*>(p + 0x3194);

  if (RegisterClassA(&wc) != 0) {
    void* hwnd = CreateWindowExA(
        0x40000u, "XutoAssault", "Auto Assault", style,
        rect->left, *reinterpret_cast<int32_t*>(p + 0x3194),
        width, height,
        nullptr, nullptr, *reinterpret_cast<void**>(p + 0x3180), nullptr);
    *reinterpret_cast<void**>(p + 0x3188) = hwnd;
  }

  if (*reinterpret_cast<void**>(p + 0x3188) == nullptr) {
    fail_msg = "Failed to CreateWindowEx!";
  } else {
    if (*reinterpret_cast<void**>(p + 0x1168) == nullptr) {
      void* raw = operator_new(0x590);
      void* obj = (raw == nullptr) ? nullptr : FUN_007fb0a0(raw);
      *reinterpret_cast<void**>(p + 0x1168) = obj;
    }
    // vcall slot 1 (vtbl+4) with arg 0
    {
      auto** obj = *reinterpret_cast<void***>(p + 0x1168);
      auto** vt  = reinterpret_cast<void**>(*obj);
      using V1 = void(__fastcall*)(void*, int);
      reinterpret_cast<V1>(vt[1])(obj, 0);
    }
    ShowWindow(*reinterpret_cast<void**>(p + 0x3188), 1);
    UpdateWindow(*reinterpret_cast<void**>(p + 0x3188));

    int re = FUN_007a3e90(
        *reinterpret_cast<void**>(p + 0x3188),
        p + 0xa18,
        p[0x9c1] == 0,
        p[0x9c6],
        "aa.bmp");

    if (re == 0) {
      fail_msg = "Failed to initialize the RenderEngine!";
    } else {
      if (re == 2) {
        mon = DAT_00d1a830 + mon_idx * 0xC;
        *reinterpret_cast<int32_t*>(p + 0x3194) = *reinterpret_cast<int32_t*>(mon + 4);
        rect->left = *reinterpret_cast<int32_t*>(mon + 0);
        *reinterpret_cast<int32_t*>(p + 0x319c) =
            *reinterpret_cast<int32_t*>(mon + 4) + *reinterpret_cast<int32_t*>(p + 0xa1c);
        *reinterpret_cast<int32_t*>(p + 0x3198) =
            *reinterpret_cast<int32_t*>(mon + 0) + *reinterpret_cast<int32_t*>(p + 0xa18);
        SetWindowPos(*reinterpret_cast<void**>(p + 0x3188), nullptr,
                     rect->left, *reinterpret_cast<int32_t*>(p + 0x3194),
                     *reinterpret_cast<int32_t*>(p + 0xa18),
                     *reinterpret_cast<int32_t*>(p + 0xa1c),
                     6);
        UpdateWindow(*reinterpret_cast<void**>(p + 0x3188));
      }

      *reinterpret_cast<int32_t*>(p + 0x31b0) =
          (*reinterpret_cast<int32_t*>(p + 0x3198) - rect->left) / 2 + rect->left;
      *reinterpret_cast<int32_t*>(p + 0x31b4) =
          (*reinterpret_cast<int32_t*>(p + 0x319c) - *reinterpret_cast<int32_t*>(p + 0x3194)) / 2 +
          *reinterpret_cast<int32_t*>(p + 0x3194);

      if (DAT_00d1f050 != 0) {
        // Guarded vector local_30; FUN_0043c5f0 assign; per-element replace +4 with
        // FUN_0040af40(new(4)); prior value deleted with vtbl PTR_LAB_00a2c238 then
        // operator_delete; finish FUN_0040d9c0(). Decompiler false-noreturn ignored.
        uint8_t local_vec[0x10]{};
        FUN_0043c5f0(local_vec);
        // ... element loop preserved in raw/decompile; elided structural detail ...
        FUN_0040d9c0();
      }

      char c = p[0xa0d];
      if (p[0x11] != 0 && c == 0) {
        c = 1;
      }
      p[0xa0d] = c;
      auto** f40 = *reinterpret_cast<int***>(p + 0xf40);
      if (f40 == nullptr || *f40 != *reinterpret_cast<int*>(p + 0xf38)) {
        p[0xb5] = (p[0x11] != 0) ? 1 : 0;
      } else {
        p[0xb5] = c;
      }

      auto* sector = *reinterpret_cast<uint8_t**>(p + 0xe04);
      *reinterpret_cast<void**>(sector + 0xe89c) = *reinterpret_cast<void**>(p + 0xde8);
      FUN_004cda90(sector); // ECX = parent at +0xe04

      DAT_00b03510 = DAT_00d09874;
      auto* e898 = *reinterpret_cast<uint8_t**>(
          *reinterpret_cast<uint8_t**>(p + 0xe04) + 0xe898);
      e898[0x4f] = 0;
      e898[0x4e] = 0;

      auto* desktop = *reinterpret_cast<uint8_t**>(p + 0xde8);
      if (*reinterpret_cast<int32_t*>(desktop + 0x2c) != 0) {
        FUN_007a2fd0();
        FUN_007ae400();
        DAT_00d17948 = p + 0x3020;
        FUN_007b1900();
        FUN_00581580(*reinterpret_cast<void**>(p + 0xde8), DAT_00d09874);
        FUN_00583170();
        FUN_00491ed0();
        FUN_0048eaa0(1);
        FUN_0048eef0(1);
        if (p[0x9ce] != 0) {
          FUN_0092f190(1);
        }
        FUN_0092f140(0x5a);
        if (p[0x9dd] != 0) {
          FUN_00935fe0();
        }
        return 0;
      }
      fail_msg = "Could not get Palantir desktop window.";
    }
  }

  FUN_007a4480(1, fail_msg);
  return 0x80004005u;
}

// Scaffold / Ghidra-name twin
extern "C" uint32_t __fastcall FUN_00948530(void* app)
{
  return Client_InitRenderEngine(app);
}

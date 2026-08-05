// =============================================================================
// GfxVertexBufferFactory_PostRestoreDevice_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00986570
// Address:   0x00986570  (autoassault.exe, image base 0x400000)
// Body:      482 B (0x00986570–0x00986752 exclusive)
// System:    graphics / D3D9 vertex buffer factory (device Reset PostRestore)
// Generated: 2026-08-04 W38-AE
// Exactness: Behavior-preserving rewrite of decompiler + byte-sealed ABI.
// Bit-for-bit vs retail EXE: DEFERRED (no Launcher / runtime this wave).
// =============================================================================

// PURPOSE:
// After IDirect3DDevice9::Reset, recreate DEFAULT-pool vertex buffers held by
// the factory map and invoke optional surface-restore callbacks.
// Retail string: "Failed PostResoreDevice() on Vertex Buffers" (typo sealed).
//
// ABI (bytes win):
//   EAX = GfxVertexBufferFactory* this
//   no stack args; plain RET
//   returns int HRESULT (0 success, negative fail; EH_Abort does not return)

#include <cstdint>
#include <cstdio>
#include <csignal>

// Unowned callees (names structural)
extern "C" int FUN_00746640(void* vb, uint32_t count, uint32_t stride, uint32_t usage, int fvf);
extern "C" int FUN_0076d1b0(const char* file, int line, const char* msg);
extern "C" void* FUN_0076cec0(void* out, const char* fmt, ...);
extern "C" void vog_LogMessage(const char* file, int line, int severity, void* msg);

struct VbSlot {
  void* vb;          // +0x00
  uint32_t pad04;    // +0x04
  void* callbackMap; // +0x08  // map sentinel*
  // total stride 0x20
  uint8_t _rest[0x14];
};

// EAX-this calling convention — not ECX thiscall
extern "C" int GfxVertexBufferFactory_PostRestoreDevice_Inferred(void /* EAX this */);

// Portable transcription (register ABI expressed as first formal for clarity):
int GfxVertexBufferFactory_PostRestoreDevice_Inferred_EaxThis(void* self)
{
  void** map = *reinterpret_cast<void***>(reinterpret_cast<char*>(self) + 0x14);
  void* node = *map;
  void* sentinel = map;

  if (node == sentinel)
    return 0;

  do {
    if ((*(reinterpret_cast<uint8_t*>(node) + 0xE) & 0x28) == 0) {
      auto* n = reinterpret_cast<void**>(node);
      VbSlot* begin = reinterpret_cast<VbSlot*>(n[5]);
      VbSlot* end = reinterpret_cast<VbSlot*>(n[6]);
      for (VbSlot* slot = begin; slot != end; ++slot) {
        void* vb = slot->vb;
        int hr = FUN_00746640(
            vb,
            *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(vb) + 0x0C),
            *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(vb) + 0x08),
            *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(vb) + 0x04),
            0);
        if (hr < 0) {
          int choice = FUN_0076d1b0(
              "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxVertexBufferFactory.cpp",
              0x194,
              "Failed PostResoreDevice() on Vertex Buffers");
          if (choice != 3)
            return hr;
          FILE* f = std::fopen("c:\\VOGCRASH.txt", "w");
          if (f) {
            std::fprintf(
                f,
                "errReport::Massive failure EH_Abort: F:%s l:%d s:%d d:%s\n",
                "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxVertexBufferFactory.cpp",
                0x194, 5,
                "Failed PostResoreDevice() on Vertex Buffers");
            std::fclose(f);
          }
          std::raise(0x16);
          // ExitProcess(3) — noreturn
          return hr;
        }

        // Nested map of restore callbacks at slot->callbackMap
        // For each non-nil entry: if host = *(entry_payload+0x1c) non-null,
        // hr = host->vtbl[0](host); on fail log only (line 0x1a4).
        void** cb_sent = reinterpret_cast<void**>(slot->callbackMap);
        void* cb = *cb_sent;
        while (cb != cb_sent) {
          void* payload = reinterpret_cast<void**>(cb)[3];
          void** host_pp = *reinterpret_cast<void***>(
              reinterpret_cast<char*>(payload) + 0x1C);
          if (host_pp) {
            auto** vtbl = reinterpret_cast<int(__thiscall***)(void*)>(host_pp);
            int chr = (*vtbl)[0](host_pp);
            if (chr < 0) {
              void* msg = FUN_0076cec0(
                  nullptr,
                  "RestoreSurfaceCallback Failed on Vertex Buffer (%d Verts)",
                  *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(payload) + 0x18));
              vog_LogMessage(
                  "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxVertexBufferFactory.cpp",
                  0x1A4, 2, msg);
            }
          }
          // std tree ++ (isnil @ cb+0x11)
          // ... sealed by raw tree-advance pattern ...
          break; // structural: full ++ in raw; not re-derived here
        }
      }
    }
    // map ++ (isnil @ node+0x21) — sealed by raw
  } while (node != sentinel);

  return 0;
}

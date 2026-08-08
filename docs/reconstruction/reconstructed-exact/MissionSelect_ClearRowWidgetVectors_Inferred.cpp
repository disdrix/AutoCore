// =============================================================================
// MissionSelect_ClearRowWidgetVectors_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_008ab340
// Address:   0x008ab340  (autoassault.exe, image base 0x400000)
// System:    missions-progression / Select-a-Mission list chrome
// Wave:      MEGA-105 (2026-08-05)
// Exactness: Behavior-preserving rewrite of decompiler control flow + sealed ABI.
// Bit-for-bit vs retail EXE: DEFERRED. Runtime / differential: OPEN.
// =============================================================================
//
// PURPOSE:
//   Destroy every non-null list-row widget in two MSVC pointer vectors on the
//   Select-a-Mission host, then clear each vector's used range (end = begin).
//   Capacity buffers are retained here; host dtor frees them after this call.
//
// ABI (sealed):
//   ESI = MissionSelectHost*
//   no stack args; plain RET
//   Frame: push ecx/ebx/ebp/edi … pop edi/ebp/ebx/ecx; ret
//
// Body: 0x008ab340–0x008ab549 exclusive (521 B / 0x209)
// Full hex: see raw MEGA-105 re-verify append
// =============================================================================

#include <cstdint>
#include <cstring>

struct Widget {
  void **vtbl;  // +0x000
  // +0x2b0: non-zero gates host unregister
};

struct MissionSelectHost {
  void **vtbl;  // +0x000
  // +0x72c / +0x730 / +0x734 : vector A begin/end/cap (T**)
  // +0x73c / +0x740 / +0x744 : vector B begin/end/cap (T**)
};

// Widget vtbl +0x3d8 : bool query (product open)
// Widget vtbl +0x440 : follow-up if query true (product open)
// Host   vtbl +0x0B0 : unregister/release child (product open)
// Widget vtbl +0x000 : scalar deleting destructor (arg=1)

static void DestroyClearOneVector(MissionSelectHost *host, Widget ***p_begin, Widget ***p_end)
{
  Widget **begin = *p_begin;
  Widget **end = *p_end;
  int count = 0;
  if (begin != nullptr)
    count = (int)(end - begin);

  for (int i = 0; i < count; ++i) {
    Widget *w = begin[i];
    if (w == nullptr)
      continue;

    using BoolFn = bool(__thiscall *)(Widget *);
    using VoidFn = void(__thiscall *)(Widget *);
    using HostFn = void(__thiscall *)(MissionSelectHost *, Widget *);
    using DtorFn = void(__thiscall *)(Widget *, int);

    BoolFn query = *reinterpret_cast<BoolFn *>(reinterpret_cast<uint8_t *>(w->vtbl) + 0x3d8);
    if (query(w)) {
      VoidFn follow = *reinterpret_cast<VoidFn *>(reinterpret_cast<uint8_t *>(w->vtbl) + 0x440);
      follow(w);
    }

    int gate = *reinterpret_cast<int *>(reinterpret_cast<uint8_t *>(w) + 0x2b0);
    if (gate != 0) {
      HostFn unreg = *reinterpret_cast<HostFn *>(reinterpret_cast<uint8_t *>(host->vtbl) + 0xb0);
      unreg(host, w);
    }

    w = begin[i];
    if (w != nullptr) {
      DtorFn dtor = *reinterpret_cast<DtorFn *>(w->vtbl);  // vtbl[0]
      dtor(w, 1);
    }
    begin[i] = nullptr;
  }

  if (begin != nullptr && count != 0 && begin != end) {
    // Image: memmove(begin, end, 0); *p_end = begin + 0
    // Effect: used-range clear; capacity untouched.
    *p_end = begin;
  }
}

// Register this: ESI = host (image). Modeled as explicit arg for readability.
void MissionSelect_ClearRowWidgetVectors_Inferred(/* ESI */ MissionSelectHost *host)
{
  auto *base = reinterpret_cast<uint8_t *>(host);
  auto **vecA_begin = reinterpret_cast<Widget ***>(base + 0x72c);
  auto **vecA_end   = reinterpret_cast<Widget ***>(base + 0x730);
  auto **vecB_begin = reinterpret_cast<Widget ***>(base + 0x73c);
  auto **vecB_end   = reinterpret_cast<Widget ***>(base + 0x740);

  DestroyClearOneVector(host, vecA_begin, vecA_end);
  DestroyClearOneVector(host, vecB_begin, vecB_end);
}

// Ghidra twin symbol
void FUN_008ab340(void)
{
  // ESI = host at entry (set by caller)
  MissionSelectHost *host = nullptr; // = ESI
  MissionSelect_ClearRowWidgetVectors_Inferred(host);
}

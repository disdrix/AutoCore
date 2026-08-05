// =============================================================================
// UI_MissionPanel_SyncListScrollbar_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_008aa610
// Address:   0x008aa610 – 0x008aa758 exclusive (328 B)
// Module:    autoassault.exe (image base 0x400000)
// System:    client UI / mission panel list scrollbar
// Dual:      WQ7R-B 2026-08-04 accept-with-gaps
// Exactness: Behavior-preserving from decompile + read_memory.
//            Not modernization. Bit-for-bit vs retail: DEFERRED.
// =============================================================================
//
// ABI: ESI = MissionUiPanel*; bare RET; frame sub esp,0x18.
// Caller: FUN_008aaf60 (after list at +0x6E0 is rebuilt).
//
// pages = (lineStep - viewport + content - 1) / lineStep
//       = ceil-ish steps of overflow; clamp min 1 at panel+0x704.

#include <cstdint>

struct UiVtable;

struct MissionUiPanel {
  // ...
  void* list;        // +0x6E0  scrollable list host
  void* scrollbar;   // +0x700
  int   page_count;  // +0x704
};

extern float g_flOne; // 1.0f @ 0x00a0f2a0

// Ghidra: FUN_008aa610
void UI_MissionPanel_SyncListScrollbar_Inferred()
{
  MissionUiPanel* panel = /* ESI */ nullptr;

  void* bar = panel->scrollbar;
  if (bar == nullptr) {
    return;
  }

  void* list = panel->list;
  // list vtbl+0x1B8 → metrics host; null / fail → bar.vtbl+0x04() hide; return
  if (list == nullptr) {
    // (**bar.vtbl+4)();
    return;
  }

  // metrics = list.vtbl+0x1B8(); if !metrics: hide; return
  // pair = list.vtbl+0x140(&scratch); viewport = pair[1]
  // content_local = 1; list.vtbl+0x204(&content_local)
  int viewport = 0; // pair[1]
  int content = 0;  // after +0x204

  if (content <= viewport) {
    // bar.vtbl+0x04(0); return
    return;
  }

  // metrics = list.vtbl+0x1B8(); lineStep = *(int*)(*metrics + 0x7C)
  int line_step = 1;
  int pages = (line_step - viewport + content - 1) / line_step;
  if (pages < 1) {
    pages = 1;
  }
  panel->page_count = pages;

  // if !bar.vtbl+0xD0(): bar.vtbl+0xFC(1, 0x3F000000 /* 0.5f */)
  // bar.vtbl+0x460(g_flOne / (float)pages)
  // scroll_metric = list.vtbl+0x218(0)
  // bar.vtbl+0x454((float)scroll_metric / (float)pages)
  (void)g_flOne;
}

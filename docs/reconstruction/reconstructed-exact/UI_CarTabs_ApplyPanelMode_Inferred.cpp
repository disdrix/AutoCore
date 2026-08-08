// =============================================================================
// UI_CarTabs_ApplyPanelMode_Inferred  (Ghidra: FUN_00889fb0)
// -----------------------------------------------------------------------------
// Stable ID: aa_00889fb0
// Address:   0x00889fb0–0x0088a12e (autoassault.exe, image base 0x400000)
// Body:      383 B (0x17F); pad CC @ 0x0088a12f
// System:    inventory-transfer
// Generated: 2026-08-05 R11-033 dual (live Ghidra decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow + byte seals.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Apply binary panel mode on the car-tabs dialog host (singleton
//   DAT_00d1b880 / i_d_tabs_car_2d_* family):
//     mode 0 → show chrome A, hide chrome B; expand+layout cargo tab;
//              collapse mission tab + list-detach
//     mode 1 → hide chrome A, show chrome B; collapse cargo + detach;
//              expand+layout mission tab
//
// ABI (bytes-sealed):
//   EAX     = panelMode {0,1}  (other values: store mode, no child work)
//   [ESP+4] = host window*
//   [ESP+8] = force (low byte; non-zero forces apply even if mode unchanged)
//   RET 8   (stdcall 2 stack dwords); void return
//
// HOST OFFSETS:
//   +0x50c [0x143] chrome A
//   +0x510 [0x144] chrome B
//   +0x514 [0x145] cargo tab   (i_d_tabs_car_2d_tab_cargo.xml via FUN_0088a290)
//   +0x518 [0x146] mission tab (i_d_tabs_car_2d_tab_mission.xml)
//   +0x528 [0x14a] current mode dword
//
// CALLEES:
//   FUN_00822cb0  — child expand/collapse (ESI=child, BL=show, stack force)
//   FUN_00756c90  — remove child from parent list +0x88 (EDI=child)
//
// CALLERS (representative):
//   FUN_0082f510 class-8 case 0xb; Client_Input_PollBoundActions;
//   FUN_0088a290 init tail; FUN_0080c240; tab OnCommand sites
//
// Retired scaffold primary:
//   Named_CalleeOf_Client_Input_PollBoundActions_00889fb0
// =============================================================================

#include <cstdint>

extern "C" void FUN_00822cb0(char force /* + ESI child, BL show */);
extern "C" uint32_t FUN_00756c90(void /* EDI = child */);

using VtblFn_IsVisible = char(__thiscall *)(void *self);
using VtblFn_ShowHide = void(__thiscall *)(void *self);
using VtblFn_SetVisible = void(__thiscall *)(void *self, int visible);
using VtblFn_Layout = void(__thiscall *)(void *self);

static inline void **Vtbl(void *obj) {
  return *reinterpret_cast<void ***>(obj);
}

static inline char Child_IsVisible(void *child) {
  return reinterpret_cast<VtblFn_IsVisible>(Vtbl(child)[0x3d8 / 4])(child);
}

static inline void Child_Show(void *child) {
  reinterpret_cast<VtblFn_ShowHide>(Vtbl(child)[0x43c / 4])(child);
}

static inline void Child_Hide(void *child) {
  reinterpret_cast<VtblFn_ShowHide>(Vtbl(child)[0x440 / 4])(child);
}

static inline void Child_SetVisible(void *child, int visible) {
  reinterpret_cast<VtblFn_SetVisible>(Vtbl(child)[1])(child, visible); // vtbl+4
}

static inline void Child_Layout(void *child) {
  reinterpret_cast<VtblFn_Layout>(Vtbl(child)[0x94 / 4])(child);
}

// Register contract: EAX = mode; stack (host, force)
void UI_CarTabs_ApplyPanelMode_Inferred(int *host /* stack */, int force /* stack */,
                                        int mode /* EAX */) {
  // Ghidra: cVar1 = host.vtbl+0x3d8(); gate visible
  if (reinterpret_cast<VtblFn_IsVisible>(Vtbl(host)[0x3d8 / 4])(host) == 0) {
    return;
  }
  // force OR mode != host[0x14a] (+0x528)
  if ((static_cast<char>(force) == 0) && (mode == host[0x14a])) {
    return;
  }

  host[0x14a] = mode;

  void *chromeA = reinterpret_cast<void *>(host[0x143]); // +0x50c
  void *chromeB = reinterpret_cast<void *>(host[0x144]); // +0x510
  void *cargo = reinterpret_cast<void *>(host[0x145]);   // +0x514
  void *mission = reinterpret_cast<void *>(host[0x146]); // +0x518

  if (mode == 0) {
    if (Child_IsVisible(chromeA) == 0) {
      Child_Show(chromeA);
      Child_SetVisible(chromeA, 1);
    }
    if (Child_IsVisible(chromeB) != 0) {
      Child_SetVisible(chromeB, 0);
      Child_Hide(chromeB);
    }
    // Expand cargo, layout; collapse mission + detach
    // Machine: ESI=cargo BL=1; layout cargo; ESI=mission BL=0; EDI=mission detach
    // (register args to FUN_00822cb0 / FUN_00756c90 — see raw append)
    FUN_00822cb0(static_cast<char>(force)); // ESI=cargo, BL=1
    Child_Layout(cargo);
    FUN_00822cb0(static_cast<char>(force)); // ESI=mission, BL=0
    FUN_00756c90();                         // EDI=mission
  } else if (mode == 1) {
    if (Child_IsVisible(chromeA) != 0) {
      Child_SetVisible(chromeA, 0);
      Child_Hide(chromeA);
    }
    if (Child_IsVisible(chromeB) == 0) {
      Child_Show(chromeB);
      Child_SetVisible(chromeB, 1);
    }
    // Collapse cargo + detach; expand mission + layout
    FUN_00822cb0(static_cast<char>(force)); // ESI=cargo, BL=0
    FUN_00756c90();                         // EDI=cargo
    FUN_00822cb0(static_cast<char>(force)); // ESI=mission, BL=1
    Child_Layout(mission);
  }
  // mode ∉ {0,1}: mode already stored; no child ops
}

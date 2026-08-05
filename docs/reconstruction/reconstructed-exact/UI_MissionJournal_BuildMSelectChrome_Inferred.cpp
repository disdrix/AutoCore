// =============================================================================
// UI_MissionJournal_BuildMSelectChrome_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00829ce0
// Address:   0x00829ce0  (autoassault.exe, image base 0x400000)
// Body:      0x00829ce0–0x00829e80 exclusive (416 B / 0x1A0)
// System:    client UI / mission journal
// Generated: 2026-07-29 W26-R dual seal (raw + live decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Dual A/B: accept-with-gaps (2026-07-29).
// Ghidra:    FUN_00829ce0
// =============================================================================
//
// PURPOSE:
//   Build mission-select (mselect) chrome widgets on a mission-journal panel:
//     - if category-mode byte at +0x4FC is zero: mission button (+0x504),
//       status window (+0x50C), apply complete label, title (+0x508);
//     - else: category title only (+0x508) with title_cat XML.
//   Loads retail XML skins under i_d_npc_2d_btn_mselect_*.xml, attaches children
//   via parent vtbl+0xA8, loads XML via child vtbl+0x28, refreshes via vtbl+0x34C.
//
// ABI: MSVC thiscall (Ghidra __fastcall ECX)
//   ECX = panel this
//   no stack formals; plain ret after SEH teardown
//
// CALLEES: FUN_00792600, operator_new, FUN_0079c860, FUN_007b5dd0,
//          FUN_00829ac0 (UI_MissionJournal_ApplyStatusCompleteLabel_Inferred)
// OFFSETS: +0x4FC category byte; +0x4FD complete flag; +0x504/+0x508/+0x50C widgets
//
// NOTE: Decompiler may invent extra args on vtbl+0xA8 calls and mangle SEH teardown.
//       Prefer single-arg attach as in prologue attach sites; epilogue is
//       mov ecx,[esp+8]; pop edi; mov fs:[0],ecx; add esp,0x10; ret.
// =============================================================================

#include <cstdint>

// External / image symbols (not defined here)
extern "C" void __fastcall FUN_00792600(void* panel);
extern "C" void* operator_new(uint32_t size);
extern "C" int __fastcall FUN_0079c860(void* self);           // button ctor
extern "C" int __thiscall FUN_007b5dd0(void* self, int arg0); // window/label ctor
extern "C" void FUN_00829ac0(void); // ESI=panel, AL=flag (ApplyStatusCompleteLabel)

// Vtbl call helpers (runtime polymorphic)
using VtblFn = void*(__thiscall*)(void* self, ...);

struct UiObject {
  void** vtbl; // +0x00
};

struct MissionJournalPanel {
  void** vtbl;                 // +0x00
  // ... many base fields ...
  // byte  categoryMode;       // +0x4FC  (index 0x13f as dword slot low byte)
  // byte  completeFlag;       // +0x4FD
  // UiObject* missionButton;  // +0x504  [0x141]
  // UiObject* titleWidget;    // +0x508  [0x142]
  // UiObject* statusWidget;   // +0x50C  [0x143]
};

static inline uint8_t* panel_bytes(MissionJournalPanel* p) {
  return reinterpret_cast<uint8_t*>(p);
}

static inline UiObject** slot_uiptr(MissionJournalPanel* p, uint32_t byteOff) {
  return reinterpret_cast<UiObject**>(panel_bytes(p) + byteOff);
}

// Load XML path via child vtbl +0x28
static inline void ui_load_xml(UiObject* child, const char* xmlPath) {
  auto* fn = reinterpret_cast<void(__thiscall*)(UiObject*, const char*)>(child->vtbl[0x28 / 4]);
  fn(child, xmlPath);
}

// Parent attach child via vtbl +0xa8
static inline void ui_attach_child(MissionJournalPanel* panel, UiObject* child) {
  auto* fn = reinterpret_cast<void(__thiscall*)(MissionJournalPanel*, UiObject*)>(panel->vtbl[0xa8 / 4]);
  fn(panel, child);
}

// Parent refresh via vtbl +0x34c
static inline void ui_refresh(MissionJournalPanel* panel) {
  auto* fn = reinterpret_cast<void(__thiscall*)(MissionJournalPanel*)>(panel->vtbl[0x34c / 4]);
  fn(panel);
}

// Mission button vtbl +0x74 with imm 60000
static inline void ui_button_set_prop(UiObject* btn, int value) {
  auto* fn = reinterpret_cast<void(__thiscall*)(UiObject*, int)>(btn->vtbl[0x74 / 4]);
  fn(btn, value);
}

void __fastcall UI_MissionJournal_BuildMSelectChrome_Inferred(MissionJournalPanel* panel)
{
  // SEH: push -1; push LAB_009b430a; fs:[0] chain — omitted as runtime frame
  FUN_00792600(panel);

  const char* titleXml;

  if (panel_bytes(panel)[0x4FC] == 0) {
    // ---- Mission mode: button + status + title ----
    void* btnMem = operator_new(0x4CC);
    int btnRaw = 0;
    if (btnMem != nullptr) {
      btnRaw = FUN_0079c860(btnMem);
    }
    UiObject* btn = reinterpret_cast<UiObject*>(btnRaw);
    *slot_uiptr(panel, 0x504) = btn;
    ui_attach_child(panel, btn);
    ui_load_xml(btn, "i_d_npc_2d_btn_mselect_btn_mission.xml");
    ui_button_set_prop(btn, 60000);

    void* stMem = operator_new(0x488);
    UiObject* status = nullptr;
    if (stMem != nullptr) {
      status = reinterpret_cast<UiObject*>(FUN_007b5dd0(stMem, 0));
    }
    *slot_uiptr(panel, 0x50C) = status;
    ui_attach_child(panel, status);
    ui_load_xml(status, "i_d_npc_2d_btn_mselect_wnd_status.xml");

    // FUN_00829ac0 ABI: ESI = panel, AL = complete flag at +0x4FD
    // (register ABI not expressible in portable C++; call as sealed peer)
    {
      // Illustrative of byte seal:
      //   mov al, [edi+0x4FD]
      //   mov esi, edi
      //   call FUN_00829ac0
      uint8_t flag = panel_bytes(panel)[0x4FD];
      (void)flag;
      FUN_00829ac0();
    }

    void* tiMem = operator_new(0x488);
    UiObject* title = nullptr;
    if (tiMem != nullptr) {
      title = reinterpret_cast<UiObject*>(FUN_007b5dd0(tiMem, 0));
    }
    *slot_uiptr(panel, 0x508) = title;
    ui_attach_child(panel, title);
    titleXml = "i_d_npc_2d_btn_mselect_wnd_title.xml";
  } else {
    // ---- Category mode: title_cat only ----
    void* tiMem = operator_new(0x488);
    UiObject* title = nullptr;
    if (tiMem != nullptr) {
      title = reinterpret_cast<UiObject*>(FUN_007b5dd0(tiMem, 0));
    }
    *slot_uiptr(panel, 0x508) = title;
    ui_attach_child(panel, title);
    titleXml = "i_d_npc_2d_btn_mselect_wnd_title_cat.xml";
  }

  ui_load_xml(*slot_uiptr(panel, 0x508), titleXml);
  ui_refresh(panel);
  // SEH teardown + ret
}

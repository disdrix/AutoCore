// =============================================================================
// Object_SetMissionStateFx_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00518370
// Address:   0x00518370 – 0x00518580  (529 B / 0x211)  autoassault.exe @ 0x400000
// System:    client-fx / mission-state SpecialFX
// Wave:      W30-H OWN-ONLY dual (2026-07-29)
// Exactness: Behavior-preserving rewrite of decompiler CF + byte ABI seal.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE
//   Store a mission/progress FX state on the object host (+0x154), tear down any
//   prior secondary SpecialFX list, arm flag bit2 at +0x184, then either:
//     - state > 2: play mission-complete audio only
//     - state 0/1/2: load FxMaster event variants 9/10/11, attach via vtbl+0xF8,
//       push a dword (historical name CVOGReaction_FailMissionNotify), play audio,
//       and call FUN_004b7e50.
//
// ABI (bytes sealed)
//   thiscall; ECX = object*; stack int newState; ret 4 (C2 04 00).
//
// CALLERS (live)
//   CVOGReaction_SpawnObject / FUN_005825d0 / FUN_00582670 → newState=3
//   FUN_005c8270 / FUN_005c8580 → progress bucket (a-b)*3/a ∈ {0,1,2}
//
// NESTED SEALS
//   FUN_00516930 Object_TeardownSecondaryFxList_Inferred (W29-N)
//   FUN_004a16d0 FxMaster_LoadEventVariant_Inferred
// =============================================================================

#include <cstdint>

// Forward decls — roles sealed elsewhere; types tentative.
extern "C" void __thiscall Object_TeardownSecondaryFxList_Inferred(void* self, int unused);
extern "C" void __thiscall FUN_004eb3b0(void* catalog_host_ctx /*ecx from caller setup*/);
extern "C" void* __thiscall FxMaster_LoadEventVariant_Inferred(void* host, uint32_t eventId,
                                                              uint32_t mode, int slot);
extern "C" void Client_GetMissionCompleteAudioTable(int a, int b, unsigned c, int d, int e);
extern "C" void FUN_00723b20(int a, int b, unsigned c, int d, int e);
extern "C" void FUN_004b7e50(int, void* linked, int, int, int, int);
extern "C" void Vector_PushDword(/* historical Ghidra: CVOGReaction_FailMissionNotify */);

void __thiscall Object_SetMissionStateFx_Inferred(int* self, int newState)
{
  int oldState = self[0x55]; // +0x154
  self[0x55] = newState;

  // vtbl + 0x1CC → linked host (mission/FX attachment root)
  int* vtbl = reinterpret_cast<int*>(*self);
  auto fn_1cc = *reinterpret_cast<int*(__thiscall**)(int*)>(vtbl + (0x1cc / 4));
  int* linked = fn_1cc(self);

  // Gate: clonebase / FX master present
  int* clonebase = reinterpret_cast<int*>(self[0x2a]); // +0xA8
  if (*(int*)(reinterpret_cast<char*>(clonebase) + 0x88) == 0) {
    return;
  }
  if (linked == nullptr) {
    return;
  }
  if (*(int*)(reinterpret_cast<char*>(linked) + 8) == 0) {
    return;
  }
  // Idempotent when already armed for same state
  if (newState == oldState && ((*(uint8_t*)(self + 0x61) & 4) != 0)) {
    return;
  }

  Object_TeardownSecondaryFxList_Inferred(self, /*unused*/ 1);
  self[0x61] = self[0x61] | 4; // +0x184 bit2

  int state = self[0x55];
  if (state > 2) {
    unsigned audio_c = static_cast<unsigned>(*(uint8_t*)(self + 0x5a));
    int b = self[0x59];
    int a = self[0x58];
    Client_GetMissionCompleteAudioTable(a, b, audio_c, 0, 0);
    FUN_00723b20(a, b, audio_c, 0, 0);
    return;
  }

  void* fx = nullptr;
  if (state == 0) {
    FUN_004eb3b0(/*ensure catalog*/);
    fx = FxMaster_LoadEventVariant_Inferred(/*host*/ nullptr, /*event*/ 9, 1, -1);
  } else if (state == 1) {
    FUN_004eb3b0();
    fx = FxMaster_LoadEventVariant_Inferred(nullptr, 10, 1, -1);
    if (fx == nullptr) {
      return;
    }
    // Walk intrusive list at fx+0x204; clear linked +0x148
    int* head = *reinterpret_cast<int**>(reinterpret_cast<char*>(fx) + 0x204);
    int* it = reinterpret_cast<int*>(*head);
    if (it != head) {
      do {
        int* node_payload = reinterpret_cast<int*>(it[2]);
        int* deep = *reinterpret_cast<int**>(reinterpret_cast<char*>(node_payload) + 0x914);
        deep[0x148 / 4] = -1;
        it = reinterpret_cast<int*>(*it);
      } while (it != head);
    }
  } else {
    if (state != 2) {
      return;
    }
    FUN_004eb3b0();
    fx = FxMaster_LoadEventVariant_Inferred(nullptr, 11, 1, -1);
    if (fx == nullptr) {
      return;
    }
    int* head = *reinterpret_cast<int**>(reinterpret_cast<char*>(fx) + 0x204);
    int* it = reinterpret_cast<int*>(*head);
    if (it != head) {
      do {
        int* node_payload = reinterpret_cast<int*>(it[2]);
        int* deep = *reinterpret_cast<int**>(reinterpret_cast<char*>(node_payload) + 0x914);
        deep[0x148 / 4] = -1;
        it = reinterpret_cast<int*>(*it);
      } while (it != head);
    }
  }

  if (fx != nullptr) {
    auto fn_f8 = *reinterpret_cast<void(__thiscall**)(int*, void*, int, int*)>(vtbl + (0xf8 / 4));
    fn_f8(self, fx, 0, self + 0x4d); // attach at +0x134
    Vector_PushDword();
    unsigned audio_c = static_cast<unsigned>(*(uint8_t*)(self + 0x5a));
    int b = self[0x59];
    int a = self[0x58];
    Client_GetMissionCompleteAudioTable(a, b, audio_c, 0, 0);
    FUN_00723b20(a, b, audio_c, 0, 0);
    FUN_004b7e50(0, linked, 0, 0, 0, 0);
  }
}

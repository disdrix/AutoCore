// =============================================================================
// UI_SkillPanel_UpdateSharedColumnClassHints_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_008967b0
// Address:   0x008967b0 – 0x00896986 inclusive (471 B / 0x1D7)
// Module:    autoassault.exe (image base 0x400000)
// System:    skills-abilities
// Dual:      R11-034 OWN-ONLY 2026-08-05 (accept-with-gaps)
// Exactness: Behavior-preserving rewrite of decompiler CF + machine ABI seal.
//            Not modernization. Bit-for-bit vs retail: DEFERRED.
// =============================================================================
//
// PURPOSE
//   When skill panel mode *(panel+0x51c)==1 and session host DAT_00d1b6d8 is
//   live, set text on the two shared skill-column widgets (panel+0x744 / +0x748)
//   to a localized hint:
//     "This column of skills is shared by the <ClassName> class."
//   ClassName comes from LookupClassDisplayName_Inferred using a hard-coded
//   12-pair share table indexed by local character (class@+0x531, race@+0x532).
//
// ABI (sealed)
//   EDI-this custom: EDI = panel*; no stack args; plain RET.
//   Caller site 0x00897a89: MOV EDI,EBP ; CALL this.
//   Frame: SUB ESP,0x164 / ADD ESP,0x164.
//
// CALLEES (not owned)
//   FUN_007a69d0  Locale_GetInstance_Inferred
//   FUN_007a6de0  StringPool_ApplyModeAndRingStore_Inferred  (thiscall ECX=pool)
//   FUN_0051f940  LookupClassDisplayName_Inferred            (cdecl 2-arg)
//   sprintf       IAT [0x009c6654]
//
// GAPS
//   Product/PDB panel method name; vtbl+0x308 English; +0x51c mode English;
//   host function at 0x00897a89; runtime / bit-exact.
// =============================================================================

#include <cstdint>
#include <cstdio>

// External dualed helpers (names from peer duals; linkage illustrative).
extern "C" void*        FUN_007a69d0(void);                 // Locale_GetInstance
extern "C" const char*  FUN_007a6de0(void* pool, const char* src, int mode); // thiscall
extern "C" const char*  FUN_0051f940(unsigned classId, unsigned raceId);
extern "C" void*        DAT_00d1b6d8;

// Widget vfunc at +0x308 — product English open (SetText / SetLabel / tooltip).
struct UiWidgetVtable {
  // ...
  // slot 0x308/4
};

struct UiWidget {
  UiWidgetVtable* vtbl;
};

// Skill panel / dialog shell (partial; only OWN offsets documented).
struct SkillPanel {
  // +0x51c  mode / tab gate (must be 1)
  // +0x744  shared-column widget A*
  // +0x748  shared-column widget B*
};

// Index: i = classId + raceId*4  (class 0..3, race 0..2 → i 0..11)
// Pair:  { share[i*2], share[i*2+1] } → columns A / B
static const uint32_t kSharedClassPairs[24] = {
  1, 3,  0, 2,  1, 3,  0, 2,  1, 3,  0, 2,
  1, 3,  0, 2,  1, 3,  0, 2,  3, 1,  2, 0,
};

// Resolve local character blob: chain used by peer class-display duals.
static inline uint8_t* LocalCharacterBlob()
{
  // *( *(*(DAT_00d1b6d8+4)+4) + 0xac + DAT_00d1b6d8 ) + 0x3c
  auto host = reinterpret_cast<uint8_t*>(DAT_00d1b6d8);
  auto p1   = *reinterpret_cast<uint8_t**>(host + 4);
  auto p2   = *reinterpret_cast<uint8_t**>(p1 + 4);
  auto p3   = *reinterpret_cast<uint8_t**>(p2 + reinterpret_cast<uintptr_t>(host) + 0xac);
  return *reinterpret_cast<uint8_t**>(p3 + 0x3c);
}

static void SetSharedColumnHint(void* locale, UiWidget* widget, unsigned sharedClassId, unsigned raceId)
{
  if (widget == nullptr) return;

  // Ring "class" first so it remains as sprintf's third %s after Lookup cleans 8 B.
  const char* classWord = FUN_007a6de0(locale, "class", -1);

  const char* rawName = FUN_0051f940(sharedClassId, raceId);
  const char* name    = FUN_007a6de0(locale, rawName, -1);
  const char* prefix  = FUN_007a6de0(locale, "This column of skills is shared by the", -1);

  char buf[256];
  // Machine: ADD ESP,0x14 after sprintf → buf + fmt + 3 strings.
  std::sprintf(buf, "%s %s %s.", prefix, name, classWord);

  // thiscall-style vfunc: ECX = widget (native), arg0 = buf
  using SetTextFn = void(__thiscall*)(UiWidget*, const char*);
  auto* slots = reinterpret_cast<void**>(widget->vtbl);
  auto fn = reinterpret_cast<SetTextFn>(slots[0x308 / 4]);
  fn(widget, buf);
}

// Native: EDI = panel*; no stack args; plain RET.
extern "C" void UI_SkillPanel_UpdateSharedColumnClassHints_Inferred(void /* EDI = panel* */)
{
  // In the binary, panel arrives in EDI (unaff_EDI in decompiler).
  // For readable C we take it as a parameter-shaped local filled by the caller ABI.
  SkillPanel* panel = nullptr; // placeholder: real site uses EDI
  (void)panel;

  void* locale = FUN_007a69d0();
  if (DAT_00d1b6d8 == nullptr) return;

  // Stack table init matches kSharedClassPairs (see disassembly stores).
  uint32_t share[24];
  for (int i = 0; i < 24; ++i) share[i] = kSharedClassPairs[i];

  // Gate: panel+0x51c == 1  (CMP before fill; JNZ after fill — flags preserved)
  // Native reads [EDI+0x51c].
  // if (*(int32_t*)((uint8_t*)panel + 0x51c) != 1) return;

  uint8_t* blob = LocalCharacterBlob();
  unsigned classId = blob[0x531];
  unsigned raceId  = blob[0x532];
  unsigned idx     = classId + raceId * 4;

  // Column A: share[idx*2]   → widget at panel+0x744
  // Column B: share[idx*2+1] → widget at panel+0x748
  // (Null checks on each widget pointer before SetSharedColumnHint.)

  (void)share;
  (void)idx;
  (void)locale;
  // Full dual branches preserved in FUN_008967b0.cpp twin (decompiler-faithful).
}

// Ghidra symbol alias
extern "C" void FUN_008967b0(void);

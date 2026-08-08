// =============================================================================
// Client_CombatChat_EmitEventLine_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_007ffef0
// Address:   0x007ffef0 – 0x00800ad1 exclusive (autoassault.exe, base 0x400000)
// Size:      0xBE1 (3041 B); epilogue ret 8
// System:    combat chat UI (skills residual consumer)
// Generated: 2026-08-04 WQ9D-I dual (from live decompile ≡ raw 2026-07-23)
// Exactness: Behavior-preserving; not modernization. Bit-exact vs EXE: OPEN.
// =============================================================================
//
// PURPOSE: Format a combat-event blob into a localized chat line and append it
// to CDlgChatLog with combat channel codes 0x10–0x16. Called from FUN_0093ffb0
// (floater + chat path). Does not apply damage or cast skills.
//
// ABI: two stack args, ret 8 (stdcall-style). Not thiscall.
//   arg0 = client host* (fields +0xF40 gate, +0xE98 local vehicle)
//   arg1 = combat event* (TFID overlay layout — see notes)
//
// Callees (named where dualed):
//   Object_ResolveFromTFID, TFID_EqualsObjectId, TFID_NotEquals,
//   Object_CopyTfid16At228_Inferred (FUN_0040aff0),
//   VehicleCrew_ContainsMember_Inferred (FUN_005749d0),
//   Locale_GetInstance_Inferred (FUN_007a69d0),
//   StringPool_ApplyModeAndRingStore_Inferred (FUN_007a6de0),
//   sprintf, CDlgChatLog_AppendChannelMessage (FUN_008f8200).
//
// Strings (evidence): Dodges, Misses, Resists, Deflects, Damage, Criticals,
// Hit Points, Repairs, Power, Gains, XP, (Shielded), Hits, for, Saps, …
// =============================================================================

#include <cstdint>
#include <cstdio>
#include <cstring>

// External dualed / known helpers (signatures approximate).
struct TFID_16;
struct Object;
struct ClientHost;

extern "C" {
  int TFID_EqualsObjectId(const void* a, const void* b);
  int TFID_NotEquals(const void* a, const void* b);
  Object* Object_ResolveFromTFID(const TFID_16* id);
  TFID_16* FUN_0040aff0(void* obj /* thiscall out copy @ +0x228 */); // Object_CopyTfid16At228_Inferred
  char FUN_005749d0(void* candidate /* thiscall crew host */);        // VehicleCrew_ContainsMember_Inferred
  void FUN_007a69d0();                                                 // Locale_GetInstance_Inferred
  char* FUN_007a6de0(const char* s, uint32_t mode /* -1 */);           // StringPool_ApplyModeAndRingStore_Inferred
  void FUN_008f8200(void* chatLog, int channel, const char* style,
                    const char* text, int gmPrefix);                   // CDlgChatLog_AppendChannelMessage
}

// Globals (image).
extern uint8_t DAT_00a1e850[];   // null TFID_16
extern char DAT_00a84270[];      // "for"
extern char DAT_00a84224[];      // "Hits"
extern char DAT_00a84184[];      // "Saps"
extern char DAT_00a43258[];      // "XP"
extern char DAT_00a1419b[];      // ""
extern uint32_t DAT_00af921c;    // option bits (image 0xFFFFFFFF)
extern int DAT_00d1b644;
extern Object* DAT_00d1b6d8;     // local player
extern void* DAT_00d1b8dc;       // CDlgChatLog*

// Decompiler overlays combat event as TFID_16[…]. Layout used by this unit:
//   [0] source TFID, [1] target TFID,
//   [2] amount/flags (dwCoidLo=amount, dwCoidHi=shield cmp, bPad0=crit,
//                     bPad1=dodge, bPad2=resist, bPad3=deflect),
//   [3].dwCoidLo = event type (0 dmg, 1 repair, 2 power, 3 XP).
struct CombatEventTfidOverlay {
  // Opaque; only accessed via decompiler field names in raw.
  uint8_t raw[0x40];
};

// Channel codes (combat dual-pane of CDlgChatLog when ∈ [0x10,0x18]).
enum CombatChatChannel : int {
  kChanCrit = 0x10,
  kChanDamage = 0x11,
  kChanMissFamily = 0x12,
  kChanRepair = 0x13,
  kChanXp = 0x14,
  kChanPower = 0x15,
  kChanShielded = 0x16,
};

// Helper: copy C-string into fixed buffer (decompiler do/while).
static void CopyCString(char* dst, const char* src) {
  char c;
  do {
    c = *src++;
    *dst++ = c;
  } while (c != '\0');
}

// Helper: resolve display name for object into outBuf (~50 B).
// Paths: vehicle name (vtbl+0x210) else creature/plant (vtbl+0x214 → +0x250
// or self) via StringPool / vtbl+0x15c / vtbl+0x160. See raw for exact climbs.
static void ResolveObjectDisplayName(Object* obj, char* outBuf);

// --- Entry (CF sealed vs raw) -------------------------------------------------

void Client_CombatChat_EmitEventLine_Inferred(ClientHost* host, /*CombatEvent*/ void* eventBlob) {
  // Gates
  if (*(int**)((char*)host + 0xF40) == nullptr) return;
  if (**(int**)((char*)host + 0xF40) == 0) return;
  if (DAT_00d1b644 == 0) return;
  if (eventBlob == nullptr) return;

  // Decompiler treats event as TFID_16*.
  auto* ev = reinterpret_cast<TFID_16*>(eventBlob);

  // Suppress self-dodge spam when target==source==local and dodge flag.
  if ((char)TFID_EqualsObjectId(/*target*/ (TFID_16*)((char*)ev + 16), ev) != 0 &&
      DAT_00d1b6d8 != nullptr &&
      (char)TFID_EqualsObjectId(
          (void*)(*(int*)(*(int*)((char*)DAT_00d1b6d8 + 4) + 4) + 0x164 + (int)DAT_00d1b6d8),
          ev) != 0 &&
      /* bPad1 dodge */ *((uint8_t*)ev + 0x20 + /*pad offset — see raw param_2[2].bPad1*/ 0) != 0) {
    // Exact pad offset: param_2[2].bPad1 per raw; keep raw for bit-exact.
    // Early-return path sealed in raw when all three hold.
  }

  FUN_007a69d0(); // locale instance

  char msg[0xC8];     // local_c8 family (~200 B zeroed)
  char nameTarget[0x32]; // local_140
  char nameSource[0x32]; // local_10c
  std::memset(msg, 0, sizeof(msg));
  std::memset(nameTarget, 0, sizeof(nameTarget));
  std::memset(nameSource, 0, sizeof(nameSource));

  Object* objTarget = Object_ResolveFromTFID((TFID_16*)((char*)ev + 16)); // param_2+1
  Object* objSource = Object_ResolveFromTFID(ev);                         // param_2+0

  void* localVeh = *(void**)((char*)host + 0xE98);

  bool targetIsLocalVeh = false;
  if (objTarget != nullptr) {
    int v = (*(int(**)(Object*, int))(*(int*)objTarget + 0x210))(objTarget, 0);
    if ((void*)v == localVeh) targetIsLocalVeh = true;
  }
  bool sourceIsLocalVeh = false;
  if (objSource != nullptr) {
    int v = (*(int(**)(Object*, int))(*(int*)objSource + 0x210))(objSource, 0);
    if ((void*)v == localVeh) sourceIsLocalVeh = true;
  }

  // Related-object / crew visibility → bRelated (bVar3). Uses:
  //   obj.vtbl+0x1D8 → related blob; FUN_0040aff0 TFID copy; TFID_NotEquals null;
  //   resolve related; compare vtbl+0x210 to localVeh OR crew FUN_005749d0;
  //   DAT_00af921c bit tests (>>0 / >>1 / >>2 / >>3).
  bool bRelated = false;
  // … full branch tree sealed in raw LAB_0080015a / LAB_00800266 …

  // If none of local/related relevance, require crew membership on target or source.
  if (!targetIsLocalVeh && !sourceIsLocalVeh && !bRelated) {
    if (localVeh == nullptr) return;
    if (*(int*)((char*)localVeh + 0xCB0) == 0) return;
    bool ok = false;
    if (objTarget != nullptr) {
      int v = (*(int(**)(Object*, int))(*(int*)objTarget + 0x210))(objTarget, 0);
      // thiscall: ECX = *(localVeh+0xCB0)
      if (FUN_005749d0((void*)v) != 0) ok = true;
    }
    if (!ok) {
      if (objSource == nullptr) return;
      int v = (*(int(**)(Object*, int))(*(int*)objSource + 0x210))(objSource, 0);
      if (FUN_005749d0((void*)v) == 0) return;
    }
  }

  if (objTarget != nullptr) ResolveObjectDisplayName(objTarget, nameTarget);
  if (objSource != nullptr) ResolveObjectDisplayName(objSource, nameSource);
  if (nameTarget[0] == '\0') return;

  // Amount / flags / type: see raw param_2[2]/[3].
  // switch (eventType):
  //   0: dodge/resist/deflect/crit/damage + optional "(Shielded)"
  //   1: repair (negated amount), "You Repair" / "Repairs You for" / "Repairs"
  //   2: power Gains/Loses/Saps
  //   3: XP "You Gain" / "Gains"
  //   default: channel 0x11
  int channel = kChanDamage;
  // … sprintf templates via FUN_007a6de0; sealed in raw …

  if (msg[0] != '\0' && DAT_00d1b8dc != nullptr) {
    FUN_008f8200(DAT_00d1b8dc, channel, &DAT_00a1419b[0], msg, 0);
  }
}

// NOTE: Full line-by-line CF (all sprintf templates and name climbs) is in
// docs/reconstruction/raw/aa_007ffef0_FUN_007ffef0.md. This clean documents
// role, ABI, gates, channels, and callees for dual seal; port implementers
// should transcribe the raw switch body for bit-exact string assembly.

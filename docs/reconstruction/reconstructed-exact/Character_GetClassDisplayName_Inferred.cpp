// =============================================================================
// Character_GetClassDisplayName_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00521900
// Address:   0x00521900  (autoassault.exe, image base 0x400000)
// System:    missions-progression / character display
// Generated: 2026-08-04 WQ7R-F dual (live decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow + bytes ABI.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Dual:      A/B accept-with-gaps — class table lives in unowned FUN_0051f940.
// =============================================================================

// PURPOSE
//  Return a ring-buffered English display name for the character's class,
//  qualified by race via FUN_0051f940(classId@+0x531, raceId@+0x532).
//  Mission token path: FUN_005465c0 replaces "[$class]" with this result.
//
// ABI
//  __thiscall / ECX = character-like this; plain RET; returns char* (ring buffer).
//
// KEY OFFSETS
//  Nested blob path identical to race helper (aa_00521800).
//  Class: blob+0x531 (uint8); Race: blob+0x532 (uint8)
//
// CALLEES
//  FUN_0051f940(classId, raceId) — cdecl leaf; product class C-strings
//    class 0: Commando / Champion / Terminator
//    class 1: Engineer / Shaman / Constructor
//    class 2: Lieutenant / Archon / MasterMind (else Officer)
//    class 3: Bounty Hunter / Avenger / Agent (else Ranger)
//    default: Unknown
//  FUN_007a69d0 / FUN_007a6de0 — TLS ring copy-out
//
// DECOMPILER PITFALL
//  Do not pass a third 0xffffffff to FUN_0051f940; that -1 is FUN_007a6de0 length.

// CF summary: load class+race bytes → lookup leaf → buffer copy-out → return.

extern "C" const char* FUN_0051f940(unsigned classId, unsigned raceId);
extern "C" void* FUN_007a69d0(void);
extern "C" char* __thiscall FUN_007a6de0(void* tls_table, const char* src, int len);

char* __fastcall Character_GetClassDisplayName_Inferred(int this_char)
{
  int vft = *(int*)(this_char + 4);
  int mid = *(int*)(vft + 4);
  int slot = *(int*)(mid + 0xac + this_char);
  int blob = *(int*)(slot + 0x3c);

  unsigned char classId = *(unsigned char*)(blob + 0x531);
  unsigned char raceId  = *(unsigned char*)(blob + 0x532);

  const char* name = FUN_0051f940(classId, raceId);

  void* tls = FUN_007a69d0();
  return FUN_007a6de0(tls, name, /*len=*/-1);
}

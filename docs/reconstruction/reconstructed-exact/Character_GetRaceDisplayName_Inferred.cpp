// =============================================================================
// Character_GetRaceDisplayName_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00521800
// Address:   0x00521800  (autoassault.exe, image base 0x400000)
// System:    missions-progression / character display
// Generated: 2026-08-04 WQ7R-F dual (live decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow + bytes ABI.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Dual:      A/B accept-with-gaps — product method English + deep types open.
// =============================================================================

// PURPOSE
//  Return a ring-buffered English display name for the character's race byte
//  (blob+0x532): 0 Human, 1 Mutant, 2 Biomek, else Unknown.
//  Mission token path: FUN_005465c0 replaces "[$race]" with this result.
//
// ABI
//  __thiscall / ECX = character-like this; plain RET; returns char* (ring buffer).
//
// KEY OFFSETS
//  Nested: *(*( *( *(this+4)+4 ) + this + 0xac ) + 0x3c ) → blob
//  Race: blob+0x532 (uint8)
//
// CALLEES
//  FUN_007a69d0 — TLS string-table object (&DAT_00d1f660)
//  FUN_007a6de0 — thiscall copy src into ring slot; return buffer pointer
//
// STRINGS (product)
//  "Human"  @ 0x00a40958
//  "Mutant" @ 0x00a40950
//  "Biomek" @ 0x00a40948
//  "Unknown"@ 0x00a37c4c

// CF summary: load race byte → 4-way cascade → buffer copy-out → return.

extern "C" void* FUN_007a69d0(void);
extern "C" char* __thiscall FUN_007a6de0(void* tls_table, const char* src, int len);

// Returns pointer into TLS ring — not owned by caller; do not free.
char* __fastcall Character_GetRaceDisplayName_Inferred(int this_char)
{
  int vft = *(int*)(this_char + 4);
  int mid = *(int*)(vft + 4);
  int slot = *(int*)(mid + 0xac + this_char);
  int blob = *(int*)(slot + 0x3c);
  unsigned char race = *(unsigned char*)(blob + 0x532);

  const char* name;
  if (race == 0) {
    name = "Human";
  } else if (race == 1) {
    name = "Mutant";
  } else if (race == 2) {
    name = "Biomek";
  } else {
    name = "Unknown";
  }

  void* tls = FUN_007a69d0();
  return FUN_007a6de0(tls, name, /*len=*/-1);
}

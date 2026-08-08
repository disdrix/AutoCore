// =============================================================================
// Character_FormatLevelRaceClassLine_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0092e710
// Address:   0x0092e710  (autoassault.exe, image base 0x400000)
// Body:      0x0092e710–0x0092e8a7 inclusive (408 B / 0x198)
// System:    missions-progression / character display UI
// Generated: 2026-08-05 R10-016 dual (live decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow + bytes ABI.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Dual:      A/B accept-with-gaps — product method English + vtbl+0x27c name open.
// =============================================================================

// PURPOSE
//  Format a single ASCII summary line into a caller-provided buffer:
//
//      "Level " + itoa(level) + " " + raceName + " " + className
//
//  Level comes from character nested vtbl slot +0x27c.
//  Race/class English come from dualed helpers:
//    Character_GetRaceDisplayName_Inferred  (0x00521800)
//    Character_GetClassDisplayName_Inferred (0x00521900)
//
//  Sole caller: FUN_008f97c0 (character-sheet UI refresh) → widget set-text
//  when DAT_00d1b6d8 (local player) is non-null and UI slot this[0x520] is set.
//
// ABI
//  - Stack (cdecl): character*  (caller ADD ESP,4)
//  - Register:      EBX = char* outBuf  (writable; typically "" on entry)
//  - Return:        int strlen(outBuf), or 0 if character==0 or outBuf==0
//  - Plain RET after local frame teardown (SUB ESP,0xC / PUSH EBP)
//
// STRINGS / CONSTANTS
//  "Level "      @ 0x00a2d280
//  DAT_00a2a000  = 0x0020 (" \0") space separator
//
// CALLEES
//  FUN_007a69d0 / FUN_007a6de0 — TLS ring string buffer
//  _itoa — radix 10 into 12-byte stack scratch
//  Character_GetRaceDisplayName_Inferred / Character_GetClassDisplayName_Inferred
//
// SCAFFOLD RETIRED
//  Named_CalleeOf_Skill_Combat_Fighting_and_driving_ability_Affect_0092e710
//  (parent-seed noise from skill tooltip string near caller)

#include <cstdint>

extern "C" void* FUN_007a69d0(void);
// thiscall: ECX = TLS table from FUN_007a69d0; copy src into ring; return slot.
extern "C" char* __thiscall FUN_007a6de0(void* tls_table, const char* src, int len);
extern "C" char* _itoa(int value, char* buffer, int radix);
extern "C" char* __fastcall Character_GetRaceDisplayName_Inferred(int this_char);
extern "C" char* __fastcall Character_GetClassDisplayName_Inferred(int this_char);

// Retail DAT_00a2a000 — uint16 store of " \0".
static const uint16_t kSpaceNul = 0x0020;

// Inline retail pattern: find end of dst, dword/byte copy src including NUL.
static void AppendCString(char* dst, const char* src)
{
  char* end = dst - 1;
  char* p;
  do {
    p = end + 1;
    end = end + 1;
  } while (*p != '\0');

  // dword copy then tail bytes (matches decompiler loops)
  const char* s = src;
  const char* s_end = src;
  while (*s_end != '\0') {
    ++s_end;
  }
  unsigned len = (unsigned)(s_end - src);
  for (unsigned n = len >> 2; n != 0; --n) {
    *(uint32_t*)end = *(const uint32_t*)s;
    s += 4;
    end += 4;
  }
  for (unsigned n = len & 3; n != 0; --n) {
    *end++ = *s++;
  }
}

// EBX-out convention exposed as explicit outBuf for port readability.
// Retail: character* on stack (cdecl), outBuf in EBX, returns strlen.
int Character_FormatLevelRaceClassLine_Inferred(int character, char* outBuf)
{
  char local_c[12];

  if (character == 0 || outBuf == nullptr) {
    return 0;
  }

  // --- "Level " ---
  {
    void* tls = FUN_007a69d0();
    char* prefix = FUN_007a6de0(tls, "Level ", -1);
    AppendCString(outBuf, prefix);
  }

  // --- decimal level via nested vtbl +0x27c ---
  {
    int level =
        (**(int (**)())(*(int*)(*(int*)(*(int*)(character + 4) + 4) + 4 + character) + 0x27c))();
    _itoa(level, local_c, 10);
    AppendCString(outBuf, local_c);
  }

  // --- ' ' + race display name ---
  {
    char* end = outBuf - 1;
    char* p;
    do {
      p = end + 1;
      end = end + 1;
    } while (*p != '\0');
    *(uint16_t*)end = kSpaceNul;

    char* race = Character_GetRaceDisplayName_Inferred(character);
    void* tls = FUN_007a69d0();
    char* race_buf = FUN_007a6de0(tls, race, -1);
    AppendCString(outBuf, race_buf);
  }

  // --- ' ' + class display name ---
  {
    char* end = outBuf - 1;
    char* p;
    do {
      p = end + 1;
      end = end + 1;
    } while (*p != '\0');
    *(uint16_t*)end = kSpaceNul;

    char* klass = Character_GetClassDisplayName_Inferred(character);
    void* tls = FUN_007a69d0();
    char* class_buf = FUN_007a6de0(tls, klass, -1);
    AppendCString(outBuf, class_buf);
  }

  // strlen(outBuf) — retail: mov eax,ebx; scan; sub eax, start+1
  {
    char* start = outBuf;
    char* cur = outBuf;
    char c;
    do {
      c = *cur;
      ++cur;
    } while (c != '\0');
    return (int)(cur - (start + 1));
  }
}

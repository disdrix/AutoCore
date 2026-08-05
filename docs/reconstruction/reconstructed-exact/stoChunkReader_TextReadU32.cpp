// =============================================================================
// stoChunkReader_TextReadU32
// -----------------------------------------------------------------------------
// Stable ID: aa_007689e0
// Address:   0x007689e0–0x00768c50  (autoassault.exe, image base 0x400000)
// System:    storage / arda2 stoChunk (text mode)
// Generated: 2026-07-23 scaffold as FUN_007689e0 / Named_stoChunk_007689e0;
//            dual A/B seal 2026-07-29 (W22-Q)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes:
 * - Text-mode peer of binary stoChunkReader_ReadU32 @ 0x00437050.
 * - Dispatcher FUN_00436900: if reader+0x4044==0 → binary; else → this unit.
 * - Retail ABI: EDI=reader, stack=uint32_t* out, RET 4. Returns 0 or −1.
 * - Scans whitespace-separated / quoted token, then FUN_00767600(out, 4, 0).
 * - "}" token → past-end-of-chunk sticky fail + pushback.
 * - Source strings: stoChunk.cpp :0x2a0 / :0x40b; "Expected uint32 but got…".
 * - Name is Inferred (peer of sealed binary ReadU32); product English open.
 */

#include <cstdint>
#include <cctype>
#include <string>

struct StoChunkReader {
  // … other fields …
  // Window embedded such that:
  int32_t cursor;     // +0x18
  int32_t base;       // +0x1c
  int32_t available;  // +0x20
  // +0x2c: inline buffer base (reader+0x2c)
  // …
  int32_t status;           // +0x402c  sticky; fail if < 0
  // +0x4044: mode (dispatcher only)
  std::string pushback;     // +0x404c  MSVC string layout in retail
  int32_t pushbackActive;   // +0x4060  nonzero → use pushback, skip scan
};

// External (not owned)
extern "C" int32_t __thiscall FUN_00435df0(void* window, int32_t absPos);
extern "C" int32_t FUN_00767600(uint32_t* out, int32_t sizeBytes, int32_t flags);
extern "C" void* FUN_00436250(void); // current chunk name string*
extern "C" const char* FUN_0076cec0(void* ctx, const char* fmt, ...);
extern "C" void vog_LogMessage(const char* file, int line, int level, const char* msg);

static bool ensure_byte(StoChunkReader* r)
{
  // retail: window is reader+0x14; fields at +0x18/+0x1c/+0x20 relative to reader
  if (r->available < r->cursor + 1) {
    // FUN_00435df0(window=reader+0x14, base+cursor)
    int32_t hr = FUN_00435df0(reinterpret_cast<uint8_t*>(r) + 0x14,
                              r->base + r->cursor);
    if (hr < 0 || r->available < 1) {
      return false;
    }
  }
  return true;
}

static char read_char(StoChunkReader* r)
{
  char c = *reinterpret_cast<char*>(reinterpret_cast<uint8_t*>(r) + 0x2c + r->cursor);
  r->cursor += 1;
  return c;
}

// Clean explicit signature. Retail: EDI=reader, stack=out, RET 4.
int32_t stoChunkReader_TextReadU32(StoChunkReader* r /*EDI*/, uint32_t* out /*stack*/)
{
  std::string token;

  if (r->status < 0) {
    goto fail_expected_uint32;
  }

  if (r->pushbackActive == 0) {
    token.clear();
    bool hadContent = false;
    char quoteChar = '"';

    // Decompiler: outer do-while(true) with goto exits only.
    for (;;) {
      bool inQuote = false;
      for (;;) {
        if (!ensure_byte(r)) {
          if (hadContent) {
            goto parse_token;
          }
          r->status = -1;
          goto fail_expected_uint32;
        }
        char c = read_char(r);
        if (!inQuote) {
          if (c == '\'' || c == '"') {
            inQuote = true;
            quoteChar = c;
          } else if (std::isspace(static_cast<unsigned char>(c))) {
            if (hadContent) {
              goto parse_token;
            }
            continue;
          }
          hadContent = true;
          token.push_back(c);
          continue;
        }
        // in quote: append until matching closer (inclusive)
        token.push_back(c);
        if (c == quoteChar) {
          break; // leave quote region; outer loop may resume
        }
      }
    }
  } else {
    token = r->pushback;
    r->pushback.clear();
  }

parse_token:
  if (token == "}") {
    vog_LogMessage(
        "C:\\vog\\1_code\\palantir\\arda2\\storage\\stoChunk.cpp",
        0x2a0,
        3,
        "Attempt to read past end of chunk. Ignoring reads until chunk exit");
    r->status = -1;
    r->pushback = token;
    token.clear();
  } else {
    // retail binds token string as implicit/this for FUN_00767600
    int32_t hr = FUN_00767600(out, 4, 0);
    if (hr >= 0) {
      return 0;
    }
  }

fail_expected_uint32:
  {
    // FUN_00436250 → SSO c_str of current chunk name
    // FUN_0076cec0 formats error; vog_LogMessage at line 0x40b
    (void)FUN_00436250();
    const char* msg = FUN_0076cec0(
        nullptr,
        "Expected uint32 but got \"%s\" in chunk \"%s\"",
        token.c_str(),
        /* chunkName */ "");
    vog_LogMessage(
        "C:\\vog\\1_code\\palantir\\arda2\\storage\\stoChunk.cpp",
        0x40b,
        3,
        msg);
  }
  return -1; // 0xffffffff
}

// Legacy Ghidra / scaffold names:
//   FUN_007689e0.cpp
//   Named_stoChunk_007689e0.cpp

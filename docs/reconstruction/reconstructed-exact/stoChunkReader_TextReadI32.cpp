// =============================================================================
// stoChunkReader_TextReadI32
// -----------------------------------------------------------------------------
// Stable ID: aa_00768760
// Address:   0x00768760–0x007689D0  (autoassault.exe, image base 0x400000)
// System:    storage / arda2 stoChunk (text mode)
// Generated: 2026-07-23 scaffold as FUN_00768760;
//            dual A/B seal 2026-08-04 (W38-I)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes:
 * - Text-mode signed peer of stoChunkReader_TextReadU32 @ 0x007689e0.
 * - Same token scan / pushback / "}" past-end as TextReadU32.
 * - Parse: FUN_00767600(out, 4, 1)  // byteLen=4, signedMode=1
 * - Error plate: "Expected int32 but got \"%s\" in chunk \"%s\"" (stoChunk.cpp:0x414).
 * - Past-end plate: line 0x2a0 (shared with other text readers).
 * - Retail ABI: EDI=reader, stack=int32_t* out, RET 4. Returns 0 or −1.
 * - Binary dual often stoChunkReader_ReadU32 @ 0x00437050 (LE dword bits).
 * - Name is Inferred from error string + ConvertToInteger signed flag.
 */

#include <cstdint>
#include <cctype>
#include <string>

struct StoChunkReader {
  // Window fields relative to reader:
  int32_t cursor;     // +0x18
  int32_t base;       // +0x1c
  int32_t available;  // +0x20
  // +0x2c: inline buffer base
  int32_t status;           // +0x402c
  // +0x4044: mode (dispatcher only)
  std::string pushback;     // +0x404c
  int32_t pushbackActive;   // +0x4060
};

// External (not owned)
extern "C" int32_t __thiscall FUN_00435df0(void* window, int32_t absPos);
// stoChunk_ConvertToInteger: out, byteLen, signedMode — token string in EAX (retail)
extern "C" int32_t FUN_00767600(void* out, int32_t sizeBytes, int32_t signedMode);
extern "C" void* FUN_00436250(void); // current chunk name string*
extern "C" const char* FUN_0076cec0(void* ctx, const char* fmt, ...);
extern "C" void vog_LogMessage(const char* file, int line, int level, const char* msg);

static bool ensure_byte(StoChunkReader* r)
{
  if (r->available < r->cursor + 1) {
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
int32_t stoChunkReader_TextReadI32(StoChunkReader* r /*EDI*/, int32_t* out /*stack*/)
{
  std::string token;

  if (r->status < 0) {
    goto fail_expected_int32;
  }

  if (r->pushbackActive == 0) {
    token.clear();
    bool hadContent = false;
    char quoteChar = '"';

    for (;;) {
      bool inQuote = false;
      for (;;) {
        if (!ensure_byte(r)) {
          if (hadContent) {
            goto parse_token;
          }
          r->status = -1;
          goto fail_expected_int32;
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
            continue; // skip leading ws
          }
          hadContent = true;
          token.push_back(c);
          continue;
        }
        token.push_back(c);
        if (c == quoteChar) {
          break; // end quote; outer loop restarts scan state in retail
        }
      }
      // retail: outer do-while(true) — after closing quote continues until unquoted end
    }
  } else {
    token = r->pushback;
    r->pushback.clear();
    // retail also clears pushbackActive via string assign path
  }

parse_token:
  if (token == "}") {
    vog_LogMessage(
        "C:\\vog\\1_code\\palantir\\arda2\\storage\\stoChunk.cpp",
        0x2a0, 3,
        "Attempt to read past end of chunk. Ignoring reads until chunk exit");
    r->status = -1;
    r->pushback = token;
    token.clear();
    // fall through to type-error path shape (retail)
  } else {
    // Retail: token string in EAX; FUN_00767600(out, 4, 1)
    int32_t hr = FUN_00767600(out, 4, /*signedMode*/ 1);
    if (hr >= 0) {
      return 0;
    }
  }

fail_expected_int32:
  {
    void* nameStr = FUN_00436250();
    // MSVC string c_str select (SSO vs heap) — retail detail
    const char* chunkName = reinterpret_cast<const char*>(nameStr); // simplified
    const char* msg = FUN_0076cec0(
        &out,
        "Expected int32 but got \"%s\" in chunk \"%s\"",
        token.c_str(),
        chunkName);
    vog_LogMessage(
        "C:\\vog\\1_code\\palantir\\arda2\\storage\\stoChunk.cpp",
        0x414, 3, msg);
  }
  return static_cast<int32_t>(0xffffffffu);
}

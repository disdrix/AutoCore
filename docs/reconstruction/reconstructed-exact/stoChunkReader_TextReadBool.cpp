// =============================================================================
// stoChunkReader_TextReadBool
// -----------------------------------------------------------------------------
// Stable ID: aa_00769660
// Address:   0x00769660–0x007698d0  (autoassault.exe, image base 0x400000)
// System:    storage / arda2 stoChunk (text mode)
// Generated: 2026-07-23 scaffold as FUN_00769660 / Named_stoChunk_00769660;
//            dual A/B seal 2026-08-04 (W38-J)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes:
 * - Text-mode peer of binary bool reader FUN_00437000 via dispatcher FUN_00439a50
 *   (gate reader+0x4044: 0 → binary; else → this unit).
 * - Retail ABI: EDI=reader, stack=uint8_t* out, RET 4. Returns 0 or −1.
 * - Same token family as TextReadU32: sticky, pushback, whitespace/quote scan.
 * - Parse via stoChunk_ConvertToInteger (FUN_00767600) with byteLen=1, signedMode=0.
 * - "}" token → past-end log (stoChunk.cpp:0x2a0), sticky −1, re-push token.
 * - Type fail: "Expected bool but got \"%s\" in chunk \"%s\"" (line 0x3dd).
 * - Name Inferred from error string + integer-text reader family; product English open.
 */

#include <cstdint>
#include <cctype>
#include <string>

struct StoChunkReader {
  // Window (relative to reader base):
  int32_t cursor;     // +0x18
  int32_t base;       // +0x1c
  int32_t available;  // +0x20
  // +0x2c: inline window buffer base
  int32_t status;           // +0x402c  sticky; early fail if < 0
  // +0x4044: mode (dispatcher only)
  std::string pushback;     // +0x404c
  int32_t pushbackActive;   // +0x4060  nonzero → use pushback, skip scan
};

// External (not owned)
extern "C" int32_t FUN_00435df0(/* window this, absPos — see W18 family */);
extern "C" int32_t FUN_00767600(/* EAX=const string* token */,
                                void* out, int32_t byteLen, int32_t signedMode);
extern "C" void* FUN_00436250(void); // current chunk name string*
extern "C" const char* FUN_0076cec0(void* ctx, const char* fmt, ...);
extern "C" void vog_LogMessage(const char* file, int line, int level, const char* msg);

static const char* STOCHUNK_CPP =
    "C:\\vog\\1_code\\palantir\\arda2\\storage\\stoChunk.cpp";

// Clean explicit signature. Retail: EDI=reader, stack=out, RET 4.
int32_t stoChunkReader_TextReadBool(StoChunkReader* r /*EDI*/, uint8_t* out /*stack*/)
{
  std::string token;

  if (r->status < 0) {
    goto fail_expected_bool;
  }

  if (r->pushbackActive == 0) {
    token.clear();
    bool hadContent = false;
    char quoteChar = '"';

    for (;;) {
      bool inQuote = false;
      for (;;) {
        if (r->available < r->cursor + 1) {
          int32_t hr = FUN_00435df0(/* window=r+0x14, abs = base+cursor */);
          if (hr < 0 || r->available < 1) {
            if (hadContent) {
              goto parse_token;
            }
            r->status = -1;
            goto fail_expected_bool;
          }
        }
        char c = *reinterpret_cast<char*>(
            reinterpret_cast<uint8_t*>(r) + 0x2c + r->cursor);
        r->cursor += 1;

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
          break;
        }
      }
    }
  } else {
    token = r->pushback;
    r->pushback.clear();
  }

parse_token:
  if (token == "}") {
    vog_LogMessage(STOCHUNK_CPP, 0x2a0, 3,
                   "Attempt to read past end of chunk. Ignoring reads until chunk exit");
    r->status = -1;
    r->pushback = token;
    token.clear();
    // fall through to type-error path with empty token (retail also restashes)
  } else {
    // Retail: EAX=&token; stack (out, 1, 0)
    int32_t hr = FUN_00767600(out, 1, 0);
    if (hr >= 0) {
      return 0;
    }
  }

fail_expected_bool:
  {
    void* chunkName = FUN_00436250();
    const char* msg = FUN_0076cec0(
        nullptr, "Expected bool but got \"%s\" in chunk \"%s\"",
        token.c_str(), /* chunk name c_str */ chunkName);
    vog_LogMessage(STOCHUNK_CPP, 0x3dd, 3, msg);
  }
  return static_cast<int32_t>(0xffffffffu);
}

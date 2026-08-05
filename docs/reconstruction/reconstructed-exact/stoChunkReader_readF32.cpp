// =============================================================================
// stoChunkReader_readF32
// -----------------------------------------------------------------------------
// Stable ID: aa_00767fd0
// Address:   0x00767fd0–0x00768254  (autoassault.exe, image base 0x400000)
// System:    sto-chunk / arda2 storage (stoChunk.cpp)
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29 (W17-G)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes:
 * - ABI: __thiscall; ECX = stoChunkReader*; stack = float* out; RET 4.
 * - Returns 0 on sscanf success; 0xffffffff on fail / past-end sticky.
 * - Text/token path: whitespace- or quote-delimited token → sscanf "%f".
 * - Binary bulk/array path is stoChunkReader_readF32Array (0x00436090); that
 *   helper calls THIS when reader+0x4044 != 0 (non-binary mode).
 * - Source path string: C:\vog\1_code\palantir\arda2\storage\stoChunk.cpp
 * - Error: "Expected float32 but got \"%s\" in chunk \"%s\"" (line 0x434).
 * - Past-end: token "}" logs line 0x2a0 and stickies +0x402c = -1.
 */

#include <cstdint>
#include <cctype>
#include <cstdio>
#include <string>

// External callees (owned elsewhere)
extern int32_t FUN_00435df0(int32_t streamPos);
extern void *FUN_00436250(void);  // returns chunk-name std::string-like
extern uint32_t FUN_0076cec0(void *ctx, const char *fmt, ...);
extern void vog_LogMessage(const char *file, int line, int level, const char *msg);

struct StoChunkReader {
  // +0x18 cursor, +0x1c refill partner, +0x20 avail, +0x2c payload window
  // +0x402c validity / past-end sticky (signed)
  // +0x404c pushback std::string
  // +0x4060 token-source mode (0 = scan stream; else use pushback)
  uint8_t _opaque[0x4070];
};

// MSVC std::string SSO: capacity field at +0x18 of string object; < 0x10 → inline.
static const char *sso_cstr(const std::string &s)
{
  // Portability shim: retail uses MSVC SSO layout matching decompiler local_2c gate.
  return s.c_str();
}

uint32_t __thiscall stoChunkReader_readF32(StoChunkReader *self, float *out)
{
  char c;
  bool in_quotes;
  bool have_token;
  int32_t refill_hr;
  char quote_ch;
  std::string token;
  uint8_t *base = reinterpret_cast<uint8_t *>(self);
  int32_t *p_cursor = reinterpret_cast<int32_t *>(base + 0x18);
  int32_t *p_partner = reinterpret_cast<int32_t *>(base + 0x1c);
  int32_t *p_avail = reinterpret_cast<int32_t *>(base + 0x20);
  int32_t *p_valid = reinterpret_cast<int32_t *>(base + 0x402c);
  int32_t *p_mode = reinterpret_cast<int32_t *>(base + 0x4060);
  // pushback string lives at +0x404c (MSVC std::string)
  std::string *pushback = reinterpret_cast<std::string *>(base + 0x404c);

  // SEH omitted (LAB_009afea0)

  if (*p_valid >= 0) {
    if (*p_mode == 0) {
      token.resize(0);
      have_token = false;
      quote_ch = '\"';
      for (;;) {
        in_quotes = false;
      scan:
        for (;;) {
          if (*p_avail < *p_cursor + 1 &&
              ((refill_hr = FUN_00435df0(*p_partner + *p_cursor), refill_hr < 0) ||
               *p_avail < 1)) {
            if (have_token)
              goto parse;
            *p_valid = -1;
            goto fail;
          }
          c = *reinterpret_cast<char *>(*p_cursor + base + 0x2c);
          *p_cursor = *p_cursor + 1;
          if (!in_quotes) {
            if (c == '\'' || c == '\"') {
              in_quotes = true;
              quote_ch = c;
            } else if (std::isspace(static_cast<unsigned char>(c))) {
              if (have_token)
                goto parse;
              goto scan;
            }
            have_token = true;
            token += c;
            goto scan;
          }
          token += c;
          if (c == quote_ch)
            break;
        }
        // after matching closer: outer loop continues (decompiler while(true))
      }
    }

    token = *pushback;
    *pushback = "";

  parse:
    if (token == "}") {
      vog_LogMessage(
          "C:\\vog\\1_code\\palantir\\arda2\\storage\\stoChunk.cpp",
          0x2a0,
          3,
          "Attempt to read past end of chunk. Ignoring reads until chunk exit");
      *p_valid = -1;
      *pushback = token;
      token = "";
    } else {
      if (std::sscanf(sso_cstr(token), "%f", out) == 1) {
        return 0;
      }
    }
  }

fail:
  {
    void *name_obj = FUN_00436250();
    // SSO gate on chunk-name object (size @ +0x18): inline at +4 else heap at *[ +4 ]
    char *chunk_name;
    uint32_t name_cap = *reinterpret_cast<uint32_t *>(
        reinterpret_cast<uint8_t *>(name_obj) + 0x18);
    if (name_cap < 0x10)
      chunk_name = reinterpret_cast<char *>(name_obj) + 4;
    else
      chunk_name = *reinterpret_cast<char **>(
          reinterpret_cast<uint8_t *>(name_obj) + 4);

    const char *tok = sso_cstr(token);
    uint32_t msg = FUN_0076cec0(
        &out,
        "Expected float32 but got \"%s\" in chunk \"%s\"",
        tok,
        chunk_name);
    vog_LogMessage(
        "C:\\vog\\1_code\\palantir\\arda2\\storage\\stoChunk.cpp",
        0x434,
        3,
        reinterpret_cast<const char *>(static_cast<uintptr_t>(msg)));
  }
  return 0xffffffffu;
}

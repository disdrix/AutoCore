// =============================================================================
// stoChunkReader_ReadQuotedTag
// -----------------------------------------------------------------------------
// Stable ID: aa_00769b70
// Address:   0x00769b70–0x00769d79  (autoassault.exe, image base 0x400000)
// System:    storage / arda2 stoChunk
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29 W25-S
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes:
 * - ABI: EDI = std::string *outTag; stack reader*; ret 4; SEH LAB_009affaf.
 * - Sticky < 0 at entry → -1 immediately.
 * - Same pushback/scan token core as ReadTextToken (quotes included in raw token).
 * - "}" → past-end log + sticky -1 + re-stash + return -1.
 * - Success ONLY if size>1 and first/last chars are '"'; then substr(1, size-2).
 * - Bare tags, single-quoted tags, braces (except past-end path) → -1.
 * - Callers: OpenChunk 0x0076a2c0; PeekChunkTag 0x0076a900; FUN_0076a200 expected-string.
 * - Twin: ReadTextToken 0x00767840 (general token, allowEndBrace).
 */

#include <cstdint>
#include <cctype>
#include <string>

struct StoChunkReader;

extern "C" int32_t FUN_00435df0(int32_t absPos);
extern "C" void vog_LogMessage(const char* file, int line, int level, const char* msg);

/* stoChunkReader::ReadQuotedTag (structural name)
   Read a double-quoted tag token into *out (EDI), stripping surrounding quotes.
   Returns 0 on success, 0xffffffff on fail. */

uint32_t __stdcall stoChunkReader_ReadQuotedTag(
    StoChunkReader* reader /* stack */,
    std::string* out /* EDI — document only */)
{
  uint8_t* r = reinterpret_cast<uint8_t*>(reader);
  std::string& token = *out;

  if (*reinterpret_cast<int32_t*>(r + 0x402c) < 0) {
    return 0xffffffffu;
  }

  if (*reinterpret_cast<int32_t*>(r + 0x4060) == 0) {
    token.resize(0);
    bool have = false;
    char quote_ch = '\"';
    for (;;) {
      bool in_quote = false;
      for (;;) {
        int32_t cursor = *reinterpret_cast<int32_t*>(r + 0x18);
        int32_t remain = *reinterpret_cast<int32_t*>(r + 0x20);
        if (remain < cursor + 1) {
          int32_t abs_pos =
              *reinterpret_cast<int32_t*>(r + 0x1c) + cursor;
          int32_t fill = FUN_00435df0(abs_pos);
          if (fill < 0 || *reinterpret_cast<int32_t*>(r + 0x20) < 1) {
            if (!have) {
              *reinterpret_cast<uint32_t*>(r + 0x402c) = 0xffffffffu;
              return 0xffffffffu;
            }
            goto finish;
          }
          cursor = *reinterpret_cast<int32_t*>(r + 0x18);
        }
        char c = *reinterpret_cast<char*>(cursor + r + 0x2c);
        *reinterpret_cast<int32_t*>(r + 0x18) = cursor + 1;

        if (!in_quote) {
          if (c == '\'' || c == '\"') {
            in_quote = true;
            quote_ch = c;
          } else if (std::isspace(static_cast<unsigned char>(c))) {
            if (have) goto finish;
            continue;
          }
          have = true;
          token.push_back(c);
          continue;
        }
        token.push_back(c);
        if (c == quote_ch) break;
      }
    }
  } else {
    token = *reinterpret_cast<std::string*>(r + 0x404c);
    *reinterpret_cast<std::string*>(r + 0x404c) = std::string();
  }

finish:
  if (token == "}") {
    vog_LogMessage(
        "C:\\vog\\1_code\\palantir\\arda2\\storage\\stoChunk.cpp",
        0x2a0, 3,
        "Attempt to read past end of chunk. Ignoring reads until chunk exit");
    *reinterpret_cast<uint32_t*>(r + 0x402c) = 0xffffffffu;
    *reinterpret_cast<std::string*>(r + 0x404c) = token;
    token.clear();
  } else if (token.size() > 1) {
    if (token.front() == '\"' && token.back() == '\"') {
      token = token.substr(1, token.size() - 2);
      return 0;
    }
  }
  return 0xffffffffu;
}

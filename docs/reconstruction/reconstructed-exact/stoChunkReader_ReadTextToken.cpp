// =============================================================================
// stoChunkReader_ReadTextToken
// -----------------------------------------------------------------------------
// Stable ID: aa_00767840
// Address:   0x00767840–0x007679d3  (autoassault.exe, image base 0x400000)
// System:    storage / arda2 stoChunk
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29 W25-S
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes:
 * - ABI: EDI = std::string *outToken; stack reader*, char allowEndBrace; ret 8.
 * - allowEndBrace==0: sticky<0 early fail; token "}" → past-end log + sticky -1 + pushback.
 * - allowEndBrace!=0: "}" returned as normal success token (LeaveChunk brace walk).
 * - Pushback: if reader+0x4060 != 0, take string at +0x404c and clear it.
 * - Scan: skip isspace; optional ' or " quoted span (quotes included in token);
 *   unquoted token ends on whitespace; EOF with partial → finish; EOF empty → sticky -1.
 * - Refill: FUN_00435df0(base(+0x1c)+cursor(+0x18)); window char at reader+0x2c+cursor.
 * - Callers: LeaveChunk 0x00769e40 (allow=1); PeekChunkTag 0x0076a900.
 * - Twin: ReadQuotedTag 0x00769b70 (stricter success + quote strip).
 */

#include <cstdint>
#include <cctype>
#include <string>

struct StoChunkReader; // opaque; offsets below

// External (owned elsewhere)
extern "C" int32_t FUN_00435df0(int32_t absPos);
extern "C" void vog_LogMessage(const char* file, int line, int level, const char* msg);

/* stoChunkReader::ReadTextToken (structural name)
   Read next text token into *out (EDI). Returns 0 on success, 0xffffffff on fail. */

uint32_t __stdcall stoChunkReader_ReadTextToken(
    StoChunkReader* reader /* stack */,
    char allowEndBrace /* stack */,
    std::string* out /* EDI — not a real C++ param; document only */)
{
  // NOTE: Retail passes out in EDI. Ports should use an explicit out parameter.
  uint8_t* r = reinterpret_cast<uint8_t*>(reader);
  std::string& token = *out;

  if (allowEndBrace == 0 &&
      *reinterpret_cast<int32_t*>(r + 0x402c) < 0) {
    return 0xffffffffu;
  }

  if (*reinterpret_cast<int32_t*>(r + 0x4060) != 0) {
    token = *reinterpret_cast<std::string*>(r + 0x404c);
    *reinterpret_cast<std::string*>(r + 0x404c) = std::string();
    goto finish;
  }

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
      if (c == quote_ch) {
        break; // outer loop clears in_quote
      }
    }
  }

finish:
  if (token == "}" && allowEndBrace == 0) {
    vog_LogMessage(
        "C:\\vog\\1_code\\palantir\\arda2\\storage\\stoChunk.cpp",
        0x2a0, 3,
        "Attempt to read past end of chunk. Ignoring reads until chunk exit");
    *reinterpret_cast<uint32_t*>(r + 0x402c) = 0xffffffffu;
    *reinterpret_cast<std::string*>(r + 0x404c) = token;
    token.clear();
    return 0xffffffffu;
  }
  return 0;
}

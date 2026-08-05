// =============================================================================
// stoChunkReader_TextReadString
// -----------------------------------------------------------------------------
// Stable ID: aa_0076a200
// Address:   0x0076a200–0x0076a2b5  (autoassault.exe, image base 0x400000)
// System:    storage / arda2 stoChunk (text mode)
// Generated: 2026-07-23 scaffold as FUN_0076a200 / Named_stoChunk_0076a200;
//            dual A/B seal 2026-08-04 (W38-J)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes:
 * - Text-mode peer of binary string reader FUN_00436f10 via dispatcher FUN_00439a20
 *   (gate reader+0x4044: 0 → binary; else → this unit).
 * - Retail leaf ABI: ECX = std::string* out, EBX = reader*, plain RET (C3).
 *   Mode dispatcher still takes stack reader* and RET 4.
 * - Success path: call stoChunkReader_ReadQuotedTag (0x00769b70, W25-S) with
 *   EDI=out, stack=reader (pushed from EBX). Tag success (≥0) → return 0.
 * - ReadQuotedTag requires double-quoted token and strips surrounding quotes.
 * - Fail: "Expected string but got \"%s\" in chunk \"%s\"" at stoChunk.cpp:0x44a.
 * - Name Inferred from error string + ReadQuotedTag wrapper role; product English open.
 */

#include <cstdint>
#include <string>

struct StoChunkReader;

// External (not owned) — sealed W25-S
extern "C" int32_t FUN_00769b70(/* EDI out string*, stack reader* */);
extern "C" void* FUN_00436250(void);
extern "C" const char* FUN_0076cec0(void* ctx, const char* fmt, ...);
extern "C" void vog_LogMessage(const char* file, int line, int level, const char* msg);

static const char* STOCHUNK_CPP =
    "C:\\vog\\1_code\\palantir\\arda2\\storage\\stoChunk.cpp";

// Clean explicit signature.
// Retail leaf: ECX=out, EBX=reader, RET 0. Document register ABI explicitly.
int32_t stoChunkReader_TextReadString(std::string* out /*ECX*/,
                                      StoChunkReader* reader /*EBX*/)
{
  // Retail: mov edi, ecx; push ebx; call ReadQuotedTag
  int32_t hr = FUN_00769b70(/* EDI=out, stack=reader */);
  if (hr >= 0) {
    return 0;
  }

  void* chunkName = FUN_00436250();
  // SSO c_str selection on both out and chunkName (capacity +0x18 < 0x10 → inline+4)
  const char* msg = FUN_0076cec0(
      nullptr, "Expected string but got \"%s\" in chunk \"%s\"",
      out->c_str(), /* chunk name c_str */ chunkName);
  vog_LogMessage(STOCHUNK_CPP, 0x44a, 3, msg);
  return static_cast<int32_t>(0xffffffffu);
}

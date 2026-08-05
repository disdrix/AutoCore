// =============================================================================
// stoChunk_ConvertToInteger
// -----------------------------------------------------------------------------
// Stable ID: aa_00767600
// Address:   0x00767600–0x007677f6  (autoassault.exe, image base 0x400000)
// System:    storage / arda2 stoChunk
// Generated: 2026-07-23 scaffold as FUN_00767600; dual A/B seal 2026-07-29 (W25-R)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes:
 * - Product evidence: "Invalid integer length in ConvertToInteger()",
 *   path C:\vog\1_code\palantir\arda2\storage\stoChunk.cpp (lines 0x3ab / 0x3c3).
 * - Retail ABI: EAX=const std::string* token, stack (out, byteLen, signedMode), RET 12.
 * - Returns 0 on success, -1 on failure.
 * - Decimal digits only; optional leading '-' when signedMode==1.
 * - byteLen in {1,2,4,8}; other lengths log + fail.
 * - Signed abs-range does not admit INT8_MIN (-128) etc. (max +127 then negate).
 * - Callers: text-mode stoChunk integer readers (u8/i8/u16/i16/u32/i32/u64/i64).
 */

#include <cstdint>
#include <cstring>
#include <cctype>

struct MsvcString {
  union {
    char inline_buf[16];
    char* ptr;
  };               // +0x00 / used via +0x04 in 32-bit layout below
  // Retail 32-bit MSVC string (simplified for this unit's access path):
  //   +0x00.. : SSO buffer or first fields
  //   +0x04   : inline char[1..] OR heap pointer when +0x18 >= 0x10
  //   +0x18   : capacity (SSO threshold 0x10)
};

// External
extern "C" void vog_LogMessage(const char* file, int line, int level, const char* msg);
extern "C" unsigned long long __allmul(unsigned lo, unsigned hi, unsigned mlo, unsigned mhi);

static const char* STOCHUNK_CPP =
    "C:\\vog\\1_code\\palantir\\arda2\\storage\\stoChunk.cpp";

// Clean explicit signature. Retail: EAX=text, stack out/byteLen/signedMode, RET 12.
int32_t stoChunk_ConvertToInteger(const void* text /*EAX MsvcString*/,
                                  void* out /*stack*/,
                                  uint32_t byteLen /*stack*/,
                                  int32_t signedMode /*stack*/)
{
  const uint8_t* base = static_cast<const uint8_t*>(text);
  const char* pc;
  if (*reinterpret_cast<const uint32_t*>(base + 0x18) < 0x10u) {
    pc = reinterpret_cast<const char*>(base + 4);
  } else {
    pc = *reinterpret_cast<char* const*>(base + 4);
  }

  if (*pc == '\0') {
    return -1;
  }

  bool neg = false;
  if (*pc == '-') {
    if (signedMode == 0) {
      return -1;
    }
    neg = true;
    ++pc;
  }

  uint64_t val = 0;
  if (*pc != '\0') {
    do {
      if (isdigit(static_cast<unsigned char>(*pc)) == 0) {
        return -1;
      }
      // retail: __allmul(lo,hi,10,0) then add (c-'0') with 64-bit carry
      val = val * 10ull + static_cast<uint64_t>(*pc - '0');
      ++pc;
    } while (*pc != '\0');
  }

  if (signedMode == 0) {
    switch (byteLen) {
    case 1:
      if ((val & 0xffffff00ull) != 0) return -1;
      break;
    case 2:
      if ((val & 0xffff0000ull) != 0) return -1;
      break;
    case 4:
      if ((val >> 32) != 0) return -1;
      break;
    case 8:
      break;
    default:
      vog_LogMessage(STOCHUNK_CPP, 0x3ab, 3,
                     "Invalid integer length in ConvertToInteger()");
      return -1;
    }
  } else if (signedMode == 1) {
    switch (byteLen) {
    case 1:
      if ((val & 0xffffff80ull) != 0) return -1;
      break;
    case 2:
      if ((val & 0xffff8000ull) != 0) return -1;
      break;
    case 4:
      if ((val & 0x80000000ull) != 0) return -1;
      break;
    case 8:
      if ((val & 0x8000000000000000ull) != 0) return -1;
      break;
    default:
      vog_LogMessage(STOCHUNK_CPP, 0x3c3, 3,
                     "Invalid integer length in ConvertToInteger()");
      return -1;
    }
    if (neg) {
      // two's complement 64-bit as retail: neg lo; adc; neg hi
      val = static_cast<uint64_t>(-static_cast<int64_t>(val));
    }
  }

  // dword then byte copy (retail rep movsd / movsb style)
  auto* d = static_cast<uint8_t*>(out);
  const auto* s = reinterpret_cast<const uint8_t*>(&val);
  uint32_t n = byteLen;
  while (n >= 4) {
    *reinterpret_cast<uint32_t*>(d) = *reinterpret_cast<const uint32_t*>(s);
    d += 4;
    s += 4;
    n -= 4;
  }
  while (n != 0) {
    *d++ = *s++;
    --n;
  }
  return 0;
}

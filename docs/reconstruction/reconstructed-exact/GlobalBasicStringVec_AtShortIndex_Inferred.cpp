// =============================================================================
// GlobalBasicStringVec_AtShortIndex_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004a05c0
// Address:   0x004a05c0  (autoassault.exe, image base 0x400000)
// System:    Global MSVC basic_string vector lookup by int16 index
// Wave:      W38-AF dual A/B (2026-08-04)
// Exactness: Behavior-preserving reconstruction from decompile + read_memory.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Copy-construct a std::string into *out from global vector
//   [DAT_00b0360c, DAT_00b03610) of elements size 0x1c, indexed by a signed
//   short. Out-of-range (including negative after MOVSX) yields empty string.
//
// ABI: __cdecl  (std::string* out, int16_t index) -> out*  // caller ADD ESP,8
//
// Reject: Named_CalleeOf_Mission_Uses_Client_GetMissionCompleteAudioTable_004a05c0
// =============================================================================

#include <cstdint>
#include <string>

// Runtime-filled BSS vector of MSVC basic_string (0x1c bytes each).
extern "C" std::string* DAT_00b0360c;  // begin
extern "C" std::string* DAT_00b03610;  // end

static constexpr std::size_t kBasicStringStride = 0x1c;

extern "C" std::string* __cdecl GlobalBasicStringVec_AtShortIndex_Inferred(
    std::string* out, std::int16_t index) {
  std::uint32_t count = 0;
  if (DAT_00b0360c != nullptr) {
    // Machine uses signed magic-multiply division by 0x1c on (end-begin).
    const auto begin = reinterpret_cast<const char*>(DAT_00b0360c);
    const auto end = reinterpret_cast<const char*>(DAT_00b03610);
    count = static_cast<std::uint32_t>((end - begin) / static_cast<std::ptrdiff_t>(kBasicStringStride));
  }

  // MOVSX short → int, then compare as unsigned against count.
  const auto uIndex = static_cast<std::uint32_t>(static_cast<std::int32_t>(index));
  if (count <= uIndex) {
    new (out) std::string("");
    return out;
  }

  // Element address: begin + index * 0x1c (as string*).
  const auto* elem = reinterpret_cast<const std::string*>(
      reinterpret_cast<const char*>(DAT_00b0360c) +
      static_cast<std::size_t>(index) * kBasicStringStride);
  new (out) std::string(*elem);
  return out;
}

// Ghidra twin name
extern "C" std::string* __cdecl FUN_004a05c0(std::string* out, std::int16_t index) {
  return GlobalBasicStringVec_AtShortIndex_Inferred(out, index);
}

// =============================================================================
// FUN_004a05c0  (twin of GlobalBasicStringVec_AtShortIndex_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_004a05c0
// Address:   0x004a05c0  (autoassault.exe, image base 0x400000)
// Wave:      W38-AF (2026-08-04) — refined from scaffold
// =============================================================================

#include <cstdint>
#include <string>

extern "C" std::string* DAT_00b0360c;
extern "C" std::string* DAT_00b03610;

extern "C" std::string* __cdecl FUN_004a05c0(std::string* out, std::int16_t index) {
  std::uint32_t count = 0;
  if (DAT_00b0360c != nullptr) {
    const auto begin = reinterpret_cast<const char*>(DAT_00b0360c);
    const auto end = reinterpret_cast<const char*>(DAT_00b03610);
    count = static_cast<std::uint32_t>((end - begin) / 0x1c);
  }
  const auto uIndex = static_cast<std::uint32_t>(static_cast<std::int32_t>(index));
  if (count <= uIndex) {
    new (out) std::string("");
    return out;
  }
  const auto* elem = reinterpret_cast<const std::string*>(
      reinterpret_cast<const char*>(DAT_00b0360c) +
      static_cast<std::size_t>(index) * 0x1c);
  new (out) std::string(*elem);
  return out;
}

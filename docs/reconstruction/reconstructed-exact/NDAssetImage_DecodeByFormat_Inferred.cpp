// =============================================================================
// NDAssetImage_DecodeByFormat_Inferred  (was FUN_00432cb0)
// -----------------------------------------------------------------------------
// Stable ID: aa_00432cb0
// Address:   0x00432cb0  (autoassault.exe, image base 0x400000)
// Body:      0x00432cb0–0x004330bf (1039 / 0x40F bytes)
// System:    gfx-asset / NDAssetImage / multi-format decode dispatch
//
// EAX = format mode 0..4; ECX = stream*; stack context*; RET 4; return 1|0.
// Modes: 0=auto TGA→PNG→BMP→other; 1=BMP; 2=PNG; 3=TGA; 4=other; else fail string.
// String: "Decode: Unknown or wrong format"
// Dual: reviews/A|B_aa_00432cb0_NDAssetImage_DecodeByFormat_Inferred.md (W22-P)
// Exactness: CF mirrors decompile; not modernization.
// Bit-for-bit / runtime / diff: DEFERRED.
// =============================================================================

#include <cstdint>

// Ghidra name alias — body shared with FUN_00432cb0.cpp scaffold.
// Register formal `format_mode` is EAX at entry (not a stack arg).

extern "C" std::uint8_t NDAssetImage_LoadTGA(void* image, int* stream);
extern "C" std::uint8_t FUN_00435410(void* image, int* stream); // PNG
extern "C" std::uint8_t FUN_00433dc0(void* image);              // BMP
extern "C" std::uint8_t FUN_0098b5b0(void* image);
extern "C" void FUN_004320d0();
extern "C" void FUN_004321b0();
extern "C" void FUN_00432580(int context);
extern "C" void FUN_00432af0();
extern "C" void FUN_00432b10();
extern "C" std::uint32_t FUN_004323c0();

// Clean plate — full CF is in FUN_00432cb0.cpp (decompiler-faithful scaffold).
// Named entry documents sealed ABI:

// uint8_t __thiscall NDAssetImage_DecodeByFormat_Inferred(
//     int* stream /*ECX*/, int context /*stack*/, int format_mode /*EAX*/);

std::uint32_t __thiscall NDAssetImage_DecodeByFormat_Inferred(int* param_1, int param_2)
{
  // format_mode is in EAX at entry — decompiler surface as in_EAX inside FUN_00432cb0.
  // Prefer FUN_00432cb0.cpp for line-faithful body; this unit is the named API plate.
  extern std::uint32_t __thiscall FUN_00432cb0(int* param_1, int param_2);
  return FUN_00432cb0(param_1, param_2);
}

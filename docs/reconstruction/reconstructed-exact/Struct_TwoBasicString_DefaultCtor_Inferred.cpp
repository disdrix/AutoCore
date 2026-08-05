// =============================================================================
// Struct_TwoBasicString_DefaultCtor_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004382c0
// Address:   0x004382c0  (autoassault.exe, image base 0x400000)
// System:    MSVC basic_string composite default ctor
// Generated: 2026-08-04 W38-G dual seal
// Exactness: Behavior-preserving rewrite of decompiler + machine seal.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Default-construct a struct of two MSVC basic_string members:
//     str0 @ +0x00 (sizeof 0x1c)
//     str1 @ +0x1c (sizeof 0x1c)
//   Total object size 0x38. Used as default fill element for vectors of
//   0x38-byte dual-string records (e.g. callers into FUN_00437e40).
//
// ABI: stack this*; returns this in EAX; ret 4. Not ECX-thiscall.
// Body: 0x004382c0-0x00438305 inclusive (70 B / 0x46).
// =============================================================================

#include <cstdint>

// MSVC basic_string layout in this binary is 0x1c bytes.
struct BasicString_0x1c {
    uint8_t opaque[0x1c];
};

struct Struct_TwoBasicString {
    BasicString_0x1c str0; // +0x00
    BasicString_0x1c str1; // +0x1c
};

// IAT [0x009c6288] -> basic_string default ctor
extern "C" void __thiscall basic_string_default_ctor(BasicString_0x1c *self);

Struct_TwoBasicString *Struct_TwoBasicString_DefaultCtor_Inferred(Struct_TwoBasicString *self)
{
    // SEH: LAB_009bbfb9; state -1 then 0 after first ctor
    basic_string_default_ctor(&self->str0);
    basic_string_default_ctor(&self->str1);
    return self;
}

// Ghidra export alias
Struct_TwoBasicString *FUN_004382c0(Struct_TwoBasicString *self)
{
    return Struct_TwoBasicString_DefaultCtor_Inferred(self);
}

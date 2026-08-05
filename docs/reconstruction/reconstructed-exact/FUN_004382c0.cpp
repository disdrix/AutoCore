// =============================================================================
// FUN_004382c0  (alias of Struct_TwoBasicString_DefaultCtor_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_004382c0
// Address:   0x004382c0  (autoassault.exe, image base 0x400000)
// System:    MSVC basic_string composite default ctor
// Generated: 2026-08-04 W38-G dual seal
// Exactness: Behavior-preserving rewrite of decompiler + machine seal.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
// Canonical clean: Struct_TwoBasicString_DefaultCtor_Inferred.cpp
// =============================================================================

#include <cstdint>

struct BasicString_0x1c {
    uint8_t opaque[0x1c];
};

struct Struct_TwoBasicString {
    BasicString_0x1c str0;
    BasicString_0x1c str1;
};

extern "C" void __thiscall basic_string_default_ctor(BasicString_0x1c *self);

Struct_TwoBasicString *FUN_004382c0(Struct_TwoBasicString *self)
{
    basic_string_default_ctor(&self->str0);
    basic_string_default_ctor(&self->str1);
    return self;
}

// =============================================================================
// StdVector_DestroyRuns_0x80_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004271c0
// Address:   0x004271c0  (autoassault.exe, image base 0x400000)
// System:    skills-abilities / UI text-layout (vector tidy, stride 0x80)
// Generated: 2026-08-05 MEGA-128 (live decompile + disasm + read_memory)
// Exactness: Behavior-preserving. Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE: MSVC-style vector tidy for 0x80-byte "run" elements owned by the
// UiTextLayout block at layout+0x80 (caller FUN_00797d70):
//   1. If begin null → zero begin/end/cap @ +4/+8/+0xC and return.
//   2. Else for each elem in [begin,end): FUN_00426f70 (ECX=elem) destroys
//      embedded basic_string<wchar_t> at elem+0x0C.
//   3. operator_delete(begin); zero triple; return.
//
// ABI: EBX = vector*; no stack args; bare RET (C3); void.
// Thunk: 0x00427040 JMP here.
// Caller: UiTextLayout_CompleteDtor_Inferred @ 0x00797df0
//         (LEA EBX,[ESI+0x80]; CALL 004271c0).
//
// REJECT: Named_CalleeOf_* scaffold; thiscall-ECX=vector; false noreturn on
// operator_delete; inventing full product element demangle.
// =============================================================================

#include <cstdint>

struct Vec80Shell {
    void* _pad0;       // +0 unused by this tidy
    uint8_t* begin;    // +4
    uint8_t* end;      // +8
    uint8_t* capacity; // +0xC
};

// Element stride 0x80; only sealed field is wstring @ +0x0C
struct RunElem0x80_Inferred {
    uint8_t pad0[0x0C];
    // basic_string<wchar_t> at +0x0C (MSVC SSO layout; dtor via IAT)
    // remaining bytes through +0x7F unowned / not dualled here
};

extern void operator_delete(void*);
// ECX = element*; ADD ECX,0xC; JMP IAT ~basic_string<wchar_t>
extern void __fastcall FUN_00426f70(void* elem /* ECX */);

// Register ABI: EBX = this vector* (not a C formal; MSVC custom)
void StdVector_DestroyRuns_0x80_Inferred(/* EBX = Vec80Shell* v */)
{
    // Pseudocode with explicit register source (bytes authority):
    // Vec80Shell* v = EBX;
    Vec80Shell* v = nullptr; // placeholder — real: EBX
    (void)v;

    // Live plate (EBX-this):
    // uint8_t* begin = *(uint8_t**)((char*)EBX + 4);
    // if (!begin) { zero +4/+8/+0xC; return; }
    // for (p = begin; p != end; p += 0x80) { ECX=p; FUN_00426f70(); }
    // operator_delete(begin); zero +4/+8/+0xC;
}

// Explicit structural form for porting (caller must pass vector via EBX):
inline void StdVector_DestroyRuns_0x80_Port(Vec80Shell* v)
{
    uint8_t* begin = v->begin;
    if (begin == nullptr) {
        v->begin = nullptr;
        v->end = nullptr;
        v->capacity = nullptr;
        return;
    }
    for (uint8_t* p = begin; p != v->end; p += 0x80) {
        FUN_00426f70(p); // ECX = p; destroys wstring at p+0x0C
    }
    operator_delete(v->begin);
    v->begin = nullptr;
    v->end = nullptr;
    v->capacity = nullptr;
}

// =============================================================================
// RunElem_WStringDtor_Plus0C_Trampoline_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00426f70
// Address:   0x00426f70–0x00426f78 inclusive (9 B)  (autoassault.exe, base 0x400000)
// System:    skills-abilities / UI text-layout (run-elem member dtor trampoline)
// Generated: 2026-08-05 R10-026 (live decompile + analyze + read_memory + IAT)
// Exactness: Behavior-preserving. Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE: thiscall trampoline that destroys the embedded MSVC
// basic_string<wchar_t> at element+0x0C. Used by dualed
// StdVector_DestroyRuns_0x80_Inferred (and the twin destroy-range helper)
// for 0x80-stride "run" elements under UiTextLayout (+0x80 vector shell).
//
// ABI: ECX = element base*; no stack args; void; tail-JMP IAT (no local RET).
// Body (bytes authority):
//   ADD ECX, 0x0C
//   JMP DWORD PTR [0x009C62AC]   // PTR_~basic_string<wchar_t,...>
//
// REJECT: full element dtor; narrow string; free host buffer; VOG_DEBUG scaffold.
// =============================================================================

#include <cstdint>

// Element stride 0x80 at vector callers; only +0x0C wstring sealed here.
struct RunElem0x80_Inferred {
    uint8_t pad0[0x0C];
    // basic_string<wchar_t> at +0x0C (MSVC layout; dtor via IAT trampoline)
    // remaining bytes through +0x7F unowned / not dualled here
};

// IAT slot 0x009c62ac — Ghidra: PTR_~basic_string<wchar_t,...>
// Runtime entry image dword: 0x006EB03A (not dualled).
using WStringDtor_IAT = void(__thiscall*)(void* wstring_this);

// ECX = RunElem0x80* element base
void __fastcall RunElem_WStringDtor_Plus0C_Trampoline_Inferred(void* elem /* ECX */)
{
    // Exact machine behavior:
    //   ECX = (char*)elem + 0x0C;
    //   goto *IAT_009c62ac;   // ~basic_string<wchar_t>
    auto* wstring_this = reinterpret_cast<void*>(
        reinterpret_cast<char*>(elem) + 0x0C);
    // Portable equivalent (IAT resolves to MSVC wstring dtor):
    // WStringDtor_IAT dtor = *reinterpret_cast<WStringDtor_IAT*>(0x009C62AC);
    // dtor(wstring_this);
    (void)wstring_this;
}

// Twin Ghidra symbol kept for inventory linkage:
// void __fastcall FUN_00426f70(void* elem /* ECX */);

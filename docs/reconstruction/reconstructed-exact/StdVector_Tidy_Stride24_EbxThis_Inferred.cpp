// =============================================================================
// StdVector_Tidy_Stride24_EbxThis_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00465d70
// Address:   0x00465d70  (autoassault.exe, image base 0x400000)
// System:    container / vector tidy (stride 0x24 elements)
// Generated: 2026-08-04 W38-R (bytes + decompile; not modernization)
// Exactness: Behavior-preserving. Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE: MSVC-style vector tidy for 0x24-byte elements: destroy each element
// via FUN_00481d80 (ESI-this; free nested buffer @+0x18), operator_delete the
// buffer, zero begin/end/cap at +4/+8/+0xC.
//
// ABI: EBX = vector*; no stack args; RET (C3); void.
// Thunk: 0x00465c30 JMP here.
// Caller: FUN_00735390 @ 0x007353cd (LEA EBX, [elem+0x70C]) — W37-N.
//
// REJECT: Named_CalleeOf_* scaffold aliases; inventing product element English.
// =============================================================================

#include <cstdint>

struct Vec24Shell {
    void* _pad0;       // +0 unused by this tidy
    uint8_t* begin;    // +4
    uint8_t* end;      // +8
    uint8_t* capacity; // +0xC
};

extern void operator_delete(void*);
// ESI = element*; frees *(void**)(elem+0x18) if non-null; zeros +0x18/+0x1c/+0x20
extern void FUN_00481d80(/* ESI = elem */);

// Register ABI: EBX = this vector* (not a C formal; MSVC custom)
void StdVector_Tidy_Stride24_EbxThis_Inferred(/* EBX = Vec24Shell* v */)
{
    // Pseudocode with explicit register source (bytes authority):
    // Vec24Shell* v = EBX;
    Vec24Shell* v = nullptr; // placeholder — real: EBX
    (void)v;

    // Live plate (EBX-this):
    // uint8_t* begin = *(uint8_t**)((char*)EBX + 4);
    // if (!begin) { zero +4/+8/+0xC; return; }
    // for (p = begin; p != end; p += 0x24) { ESI=p; FUN_00481d80(); }
    // operator_delete(begin); zero +4/+8/+0xC;
}

// Explicit structural form for porting (caller must pass vector via EBX):
inline void StdVector_Tidy_Stride24_EbxThis_Port(Vec24Shell* v)
{
    uint8_t* begin = v->begin;
    if (begin == nullptr) {
        v->begin = nullptr;
        v->end = nullptr;
        v->capacity = nullptr;
        return;
    }
    for (uint8_t* p = begin; p != v->end; p += 0x24) {
        // FUN_00481d80 with ESI = p
        (void)p;
        FUN_00481d80();
    }
    operator_delete(v->begin);
    v->begin = nullptr;
    v->end = nullptr;
    v->capacity = nullptr;
}

// =============================================================================
// StdVector_PushBack12_Inferred  (was FUN_00480ca0)
// -----------------------------------------------------------------------------
// Stable ID: aa_00480ca0
// Address:   0x00480ca0  (autoassault.exe, image base 0x400000)
// Body:      0x00480ca0–0x00480d17 (120 bytes)
// System:    container / std::vector<Element12> push
//
// Customcc (call-site Confirmed):
//   EAX = vector*  (+4 begin, +8 end, +0xc capacityEnd)
//   EBX = const Element12*  (exactly 12 bytes / 3 dwords)
//   bare RET
//
// Fast path: size < capacity → FUN_0042acc0(count=1, dest=end, src=EBX); end+=0xC
// Slow path: FUN_0042a710 grow/insert (EDI=vector into callee)
//
// Stride 0xC Confirmed (add 0xC; signed /12 via 0x2AAAAAAB).
// Name INFERRED — structural; no product string in body.
// Dual: reviews/A|B_aa_00480ca0_StdVector_PushBack12_Inferred.md (W18-O 2026-07-29)
// Exactness: CF mirrors bytes + decompile; not modernization.
// Bit-for-bit / runtime / diff: DEFERRED.
// =============================================================================

#include <cstdint>

struct Element12 {
    std::uint32_t w0;
    std::uint32_t w1;
    std::uint32_t w2;
};

struct Vec12 {
    void*        unused_or_cookie; // +0 not touched here
    Element12*   begin;            // +4
    Element12*   end;              // +8
    Element12*   capacityEnd;      // +0xc
};

// EAX=dest, ECX=count, EDX=src — copy count × 12-byte elements
extern "C" void __fastcall FUN_0042acc0(int count, Element12* src_edx /*EDX*/,
                                        Element12* dest_eax /*EAX*/);
// Grow/insert path; vector in EDI (callee customcc)
extern "C" void FUN_0042a710(void* outIt, Element12* end, const Element12* src);

// Modeled with explicit args; retail binds EAX/EBX.
void StdVector_PushBack12_Inferred(Vec12* v, const Element12* src)
{
    Element12* begin = v->begin;
    if (begin != nullptr) {
        const auto size =
            static_cast<std::uint32_t>(v->end - begin); // element count via /12 in asm
        const auto cap =
            static_cast<std::uint32_t>(v->capacityEnd - begin);
        // asm uses byte-diff / 12; pointer-diff already element-scaled in this model
        if (size < cap) {
            Element12* end = v->end;
            // FUN_0042acc0(1, src, end): three dword copy
            end->w0 = src->w0;
            end->w1 = src->w1;
            end->w2 = src->w2;
            v->end = end + 1; // +0xC
            return;
        }
    }
    // Slow: realloc / insert at end (FUN_0042a710)
    Element12* outIt = nullptr;
    FUN_0042a710(&outIt, v->end, src);
}

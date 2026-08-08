// =============================================================================
// StdSort_RanItStride16_Inferred  (Ghidra: FUN_00409bd0)
// -----------------------------------------------------------------------------
// Stable ID: aa_00409bd0
// Address:   0x00409bd0–0x00409cb9 inclusive (234 B / 0xEA)
// Module:    autoassault.exe (image base 0x400000)
// System:    MSVC STL std::_Sort — random-access, element stride 16
// Agent:     MEGA-043 OWN-ONLY dual 2026-08-05
// Exactness: Behavior-preserving rewrite of decompiler CF + ABI seal.
//            Not modernization. Bit-for-bit vs retail: DEFERRED.
// Terminal:  false (no runtime Confirmed)
//
// ABI (sealed via disassemble_function + read_memory + call-site):
//   __cdecl void (Elem16* first, Elem16* last, int ideal, Pred pred)
//   plain RET (C3); caller cleans 0x10
//   count = (last - first) >> 4   // sizeof(Elem16) == 16
//
// Prior scaffold RETIRED:
//   Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_Input_PollB_00409bd0
// Live sole external caller: FUN_00930360 @ 0x009305fc (sort target list).
// =============================================================================

#include <cstdint>

// 16-byte random-access element (layout product-open; stride sealed).
struct Elem16 {
    std::uint32_t w0;
    std::uint32_t w1;
    std::uint32_t w2;
    std::uint32_t w3;
};

// bool pred(const Elem16* a, const Elem16* b) — less-than
using Elem16_Pred = bool(__cdecl *)(const Elem16 *a, const Elem16 *b);

// Nested MSVC helpers (addresses only; not dualled in MEGA-043):
//   FUN_00409f90  unguarded partition → writes {mid_lo, mid_hi}
//   FUN_0040a410  insertion sort for ranges with count in (1, 32]
//   FUN_0040a820  make_heap
//   FUN_0040a380  sort_heap
extern "C" void __cdecl FUN_00409f90(Elem16 **out_pair, Elem16 *first, Elem16 *last, Elem16_Pred pred);
extern "C" void __cdecl FUN_0040a410(Elem16 *first, Elem16 *last, Elem16_Pred pred);
extern "C" void __cdecl FUN_0040a820(Elem16 *first, Elem16 *last, Elem16_Pred pred);
extern "C" void __cdecl FUN_0040a380(Elem16 *first, Elem16 *last, Elem16_Pred pred);

extern "C" void __cdecl StdSort_RanItStride16_Inferred(
    Elem16 *first,
    Elem16 *last,
    int ideal,
    Elem16_Pred pred)
{
    int count = static_cast<int>(
        reinterpret_cast<char *>(last) - reinterpret_cast<char *>(first));

    for (;;) {
        count >>= 4; // / 16
        if (count < 0x21) {
        do_insertion:
            if (count > 1) {
                FUN_0040a410(first, last, pred);
            }
            return;
        }

        if (ideal < 1) {
            if (count > 0x20) {
                const int span =
                    static_cast<int>(
                        reinterpret_cast<char *>(last) - reinterpret_cast<char *>(first)) &
                    static_cast<int>(0xfffffff0u);
                if (span > 0x10) {
                    FUN_0040a820(first, last, pred);
                }
                FUN_0040a380(first, last, pred);
                return;
            }
            goto do_insertion;
        }

        Elem16 *mid_pair[2];
        FUN_00409f90(mid_pair, first, last, pred);
        Elem16 *mid_lo = mid_pair[0];
        Elem16 *mid_hi = mid_pair[1];

        // ideal = ideal/2 + (ideal/2)/2  →  ¾ of prior budget (MSVC _Sort)
        ideal = ideal / 2 + (ideal / 2) / 2;

        const int left_span =
            static_cast<int>(
                reinterpret_cast<char *>(mid_lo) - reinterpret_cast<char *>(first)) &
            static_cast<int>(0xfffffff0u);
        const int right_span =
            static_cast<int>(
                reinterpret_cast<char *>(last) - reinterpret_cast<char *>(mid_hi)) &
            static_cast<int>(0xfffffff0u);

        if (left_span < right_span) {
            StdSort_RanItStride16_Inferred(first, mid_lo, ideal, pred);
            first = mid_hi;
        } else {
            StdSort_RanItStride16_Inferred(mid_hi, last, ideal, pred);
            last = mid_lo;
        }

        count = static_cast<int>(
            reinterpret_cast<char *>(last) - reinterpret_cast<char *>(first));
    }
}

// Ghidra twin symbol
extern "C" void __cdecl FUN_00409bd0(
    Elem16 *first, Elem16 *last, int ideal, Elem16_Pred pred)
{
    StdSort_RanItStride16_Inferred(first, last, ideal, pred);
}

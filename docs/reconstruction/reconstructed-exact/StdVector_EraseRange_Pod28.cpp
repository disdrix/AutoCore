// =============================================================================
// StdVector_EraseRange_Pod28  (aa_0045cce0)
// -----------------------------------------------------------------------------
// Address:   0x0045cce0–0x0045cd2b exclusive (75 B)  autoassault.exe @ 0x400000
// System:    MSVC-style vector erase for POD elem size 0x1c
// Wave:      W36-L OWN-ONLY 2026-07-29
// Exactness: Behavior-preserving reconstruction from decompile + read_memory.
//            Not modernization. Bit-for-bit / runtime: DEFERRED.
// =============================================================================

#include <cstdint>

struct Pod28 {
    // 7× dword/float lanes (0x1c). Moved via rep movsd (ECX=7).
    uint32_t w[7];
};

struct StdVectorPod28 {
    uint32_t unused0;  // +0x00 (often allocator / pad in this layout)
    Pod28* begin;      // +0x04
    Pod28* end;        // +0x08
    Pod28* capEnd;     // +0x0C (unused here)
};

// ABI (stack, RET 0x10):
//   arg0 = vec*
//   arg1 = out_it*     (written with first; also returned in EAX)
//   arg2 = first       (erase range begin)
//   arg3 = last        (erase range end, exclusive)
//
// Semantics: MSVC vector<T>::erase(first,last) for POD T size 0x1c.
//   - If first!=last: shift [last,end) down to [first,...) by 0x1c; end=new.
//   - Always *out_it = first; return out_it.
// Leaf.

extern "C" Pod28** StdVector_EraseRange_Pod28(
    StdVectorPod28* vec,
    Pod28** out_it,
    Pod28* first,
    Pod28* last)
{
    if (first != last) {
        Pod28* end = vec->end;
        Pod28* dest = first;
        while (last != end) {
            Pod28* src = last;
            Pod28* dst = dest;
            dest = reinterpret_cast<Pod28*>(
                reinterpret_cast<char*>(dest) + 0x1c);
            last = reinterpret_cast<Pod28*>(
                reinterpret_cast<char*>(last) + 0x1c);
            // Retail: ECX=7; ESI=src; EDI=dst; rep movsd
            *dst = *src;
        }
        vec->end = dest;
    }
    *out_it = first;
    return out_it;
}

// Ghidra twin name
extern "C" Pod28** FUN_0045cce0(
    StdVectorPod28* vec,
    Pod28** out_it,
    Pod28* first,
    Pod28* last)
{
    return StdVector_EraseRange_Pod28(vec, out_it, first, last);
}

// =============================================================================
// FUN_0045cce0  (twin of StdVector_EraseRange_Pod28)
// -----------------------------------------------------------------------------
// Stable ID: aa_0045cce0
// Address:   0x0045cce0–0x0045cd2b exclusive (75 B)
// Wave:      W36-L OWN-ONLY 2026-07-29
// =============================================================================

#include <cstdint>

struct Pod28 { uint32_t w[7]; };
struct StdVectorPod28 {
    uint32_t unused0;
    Pod28* begin;
    Pod28* end;
    Pod28* capEnd;
};

extern "C" Pod28** StdVector_EraseRange_Pod28(
    StdVectorPod28* vec, Pod28** out_it, Pod28* first, Pod28* last);

extern "C" Pod28** FUN_0045cce0(
    StdVectorPod28* vec,
    Pod28** out_it,
    Pod28* first,
    Pod28* last)
{
    return StdVector_EraseRange_Pod28(vec, out_it, first, last);
}

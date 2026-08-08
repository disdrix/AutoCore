// =============================================================================
// Host_LookupObjectByKey_PairTable30_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0040afb0
// Address:   0x0040afb0 – 0x0040afed (62 B)  (autoassault.exe, image base 0x400000)
// System:    interaction-activation (shared host pair-table leaf)
// Generated: 2026-08-05 MEGA-028 dual seal from live Ghidra re-verify
// Exactness: Behavior-preserving rewrite of decompiler + sealed assembly ABI.
// Bit-for-bit vs retail EXE: DEFERRED (no runtime Confirmed).
// Supersedes: Named_CalleeOf_Named_VOG_DEBUG_STOP_0040afb0 (scaffold)
// Ghidra:    FUN_0040afb0
// =============================================================================

// PURPOSE:
//   Linear-scan lookup of a keyed object* in the host's pair table at +0x30
//   (count at +0x34). On match writes the associated value into *outObject;
//   on miss writes NULL. Used by soft-cast hit resolve (key 1), GetObjectsInArea
//   (key 1), and drive collision material pair-list (keys 3/4).
//
// ABI (sealed):
//   __thiscall
//   ECX      = host*
//   [ESP+4]  = void **outObject
//   [ESP+8]  = int key
//   EAX      = outObject (out-param return idiom)
//   RET 8
//
// Layout (sealed):
//   host+0x30 -> Pair*  where Pair = { int key; void* value; }  // stride 8
//   host+0x34 -> int count
//
// Leaf: no callees. Odd behavior preserved: first match wins; no bounds on
// value type; decompiler may show void while EAX is live.

#include <cstdint>

struct Host_PairTable30 {
    // ... preceding fields ...
    // at +0x30:
    //   struct { int32_t key; void* value; } *pairs;
    //   int32_t count;   // +0x34
};

void* __thiscall Host_LookupObjectByKey_PairTable30_Inferred(
    void* host,
    void** outObject,
    int key)
{
    int i = 0;
    int count = *reinterpret_cast<int*>(reinterpret_cast<char*>(host) + 0x34);

    if (0 < count) {
        int* table = *reinterpret_cast<int**>(reinterpret_cast<char*>(host) + 0x30);
        int* pairCursor = table;
        do {
            if (*pairCursor == key) {
                *outObject = reinterpret_cast<void*>(table[i * 2 + 1]);
                return outObject;
            }
            i = i + 1;
            pairCursor = pairCursor + 2; // +8 bytes
        } while (i < count);
    }

    *outObject = nullptr;
    return outObject;
}

// =============================================================================
// FUN_0040afb0  (machine-name twin of Host_LookupObjectByKey_PairTable30_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0040afb0
// Address:   0x0040afb0  (autoassault.exe, image base 0x400000)
// System:    interaction-activation
// Generated: 2026-08-05 MEGA-028 (clean twin; keep FUN_* path for inventory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Named clean: Host_LookupObjectByKey_PairTable30_Inferred.cpp
// =============================================================================

// ABI: __thiscall; ECX=host; stack out*, key; EAX=out; RET 8
// Layout: host+0x30 pair base {int key; void* value}, host+0x34 count

void* __thiscall FUN_0040afb0(void* host, void** outObject, int key)
{
    int i = 0;
    int count = *(int*)((char*)host + 0x34);

    if (0 < count) {
        int* table = *(int**)((char*)host + 0x30);
        int* pairCursor = table;
        do {
            if (*pairCursor == key) {
                *outObject = (void*)table[i * 2 + 1];
                return outObject;
            }
            i = i + 1;
            pairCursor = pairCursor + 2;
        } while (i < count);
    }

    *outObject = 0;
    return outObject;
}

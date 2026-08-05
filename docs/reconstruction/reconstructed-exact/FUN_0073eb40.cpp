// Twin of GfxBodyHolder_ReplaceUnserialize_Inferred — Ghidra symbol keep-alive.
// See: GfxBodyHolder_ReplaceUnserialize_Inferred.cpp (W38-R authoritative clean).
// Stable ID: aa_0073eb40  VA: 0x0073eb40

#include <cstdint>

void* operator_new(unsigned);
void* FUN_00764030(void* self);
uint32_t FUN_0076a900(void);
uint32_t FUN_009615c0(void* body, void* reader);
uint32_t FUN_00765740(void* body, void* reader);

uint32_t __thiscall FUN_0073eb40(void* holder, void* reader)
{
    void* old = *(void**)((char*)holder + 4);
    if (old) {
        (**(void(__thiscall***)(void*, int))old)(old, 1);
    }
    void* raw = operator_new(0x14C);
    void* body = raw ? FUN_00764030(raw) : nullptr;
    *(void**)((char*)holder + 4) = body;
    uint32_t tag = FUN_0076a900();
    if (tag == 0x424D4153u) {
        return FUN_009615c0(body, reader);
    }
    return FUN_00765740(body, reader);
}

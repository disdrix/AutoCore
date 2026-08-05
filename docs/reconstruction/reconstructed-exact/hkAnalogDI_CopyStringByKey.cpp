// =============================================================================
// hkAnalogDI_CopyStringByKey
// -----------------------------------------------------------------------------
// Stable ID: aa_005ffc90
// Address:   0x005ffc90 – 0x005ffce5  (autoassault.exe, image base 0x400000)
// System:    Havok / DI analog string table
// Agent:     W25-M OWN-ONLY dual A/B 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler CF + thiscall from bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================

// PURPOSE:
//   Look up a uint key in the open-address hash table at this+8.
//   On hit: strncpy the mapped C-string into dst (maxlen), return strlen(src).
//   On miss: return 0 (dst untouched).
//
// ABI (bytes):
//   thiscall ECX=this; stack key, dst, maxlen; ret 0xc; EAX = length or 0.
//
// Sole caller: hkAnalogDI_vtbl1 (0x005ffd80) when *(byte*)(this+5) & 0x80.

extern "C" unsigned __thiscall FUN_00650290(void* table, unsigned key);
extern "C" void __thiscall FUN_0065ad10(void* table, bool* outFound, unsigned index);
extern "C" char* __thiscall FUN_0065acb0(void* table, int index);
extern "C" void FUN_00638040(char* dst, const char* src, unsigned maxlen); // strncpy
extern "C" int FUN_00638060(const char* s); // strlen

int __thiscall hkAnalogDI_CopyStringByKey(
    void* self,
    unsigned key,
    char* dst,
    unsigned maxlen)
{
    void* table = (unsigned char*)self + 8;
    unsigned index = FUN_00650290(table, key);
    bool found = false;
    // Decomp reuses key stack slot as bool out; call order matches bytes.
    FUN_0065ad10(table, &found, index);
    // Bytes compare the stack bool; equivalent:
    // found written by FUN_0065ad10 as (index <= *(int*)(table+8))
    if (!found) {
        return 0;
    }
    char* src = FUN_0065acb0(table, (int)index);
    FUN_00638040(dst, src, maxlen);
    return FUN_00638060(src);
}

// Scaffold alias
int __thiscall FUN_005ffc90(void* self, unsigned key, char* dst, unsigned maxlen)
{
    return hkAnalogDI_CopyStringByKey(self, key, dst, maxlen);
}

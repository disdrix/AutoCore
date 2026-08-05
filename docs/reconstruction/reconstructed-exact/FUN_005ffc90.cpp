// =============================================================================
// FUN_005ffc90 / hkAnalogDI_CopyStringByKey (scaffold twin)
// -----------------------------------------------------------------------------
// Stable ID: aa_005ffc90
// Address:   0x005ffc90  (autoassault.exe, image base 0x400000)
// Agent:     W25-M OWN-ONLY 2026-07-29
// Prefer:    reconstructed-exact/hkAnalogDI_CopyStringByKey.cpp
// =============================================================================

// See named clean for full commentary. Scaffold keeps Ghidra symbol surface.

extern "C" unsigned __thiscall FUN_00650290(void* table, unsigned key);
extern "C" void __thiscall FUN_0065ad10(void* table, bool* outFound, unsigned index);
extern "C" char* __thiscall FUN_0065acb0(void* table, int index);
extern "C" void FUN_00638040(char* dst, const char* src, unsigned maxlen);
extern "C" int FUN_00638060(const char* s);

// Decompiler omitted thiscall; bytes: lea esi,[ecx+8]
int __thiscall FUN_005ffc90(void* self, unsigned key, char* dst, unsigned maxlen)
{
    void* table = (unsigned char*)self + 8;
    unsigned index = FUN_00650290(table, key);
    bool found = false;
    FUN_0065ad10(table, &found, index);
    if (!found) {
        return 0;
    }
    char* src = FUN_0065acb0(table, (int)index);
    FUN_00638040(dst, src, maxlen);
    return FUN_00638060(src);
}

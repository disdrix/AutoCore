// =============================================================================
// FUN_00404730 / CombatFloater_CopyRange_0x38_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00404730
// Address:   0x00404730  (autoassault.exe, image base 0x400000)
// System:    missions-progression / combat floater UI
// Generated: 2026-07-29 dual seal W16-E (from live decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE:
//   Range POD copy for combat-floater elements (stride 0x38):
//     for (p = srcBegin; p != srcEnd; p += 0x38) {
//       FUN_004046f0(dst, p);  // 14 dwords if dst != NULL
//       dst += 0x38;
//     }
//     return dst;
//
//   Sole static caller: FUN_004044c0 (CombatFloater_UninitializedCopy trampoline)
//   used by CombatFloaterVector_InsertN realloc/relocate path.
//
// ABI: cdecl (ret); 3 formals (srcBegin, srcEnd, dst). Caller may push extra
//      stack slots; 4th slot is loaded into ECX but ignored by pod leaf.
// SEH: LAB_009bd1d0 frame present in retail; omitted only if port drops EH.

#include <cstdint>

// Forward: CombatFloater_PodCopyElement_0x38 (stdcall dst, src; ret 8)
extern "C" void __stdcall FUN_004046f0(void *dst, void *src);

// ExceptionList / SEH symbols as decompiler sees them (no-op stubs for ports)
extern "C" void *ExceptionList;
extern "C" unsigned char LAB_009bd1d0;

extern "C" int FUN_00404730(int param_1, int param_2, int param_3)
{
    void *local_10;
    uint8_t *puStack_c;
    uint32_t local_8;

    puStack_c = &LAB_009bd1d0;
    local_10 = ExceptionList;
    local_8 = 0;
    ExceptionList = &local_10;
    for (; param_1 != param_2; param_1 = param_1 + 0x38) {
        FUN_004046f0((void *)param_3, (void *)param_1);
        param_3 = param_3 + 0x38;
    }
    ExceptionList = local_10;
    return param_3;
}

// Named alias (structural / inferred — product name open)
extern "C" void *CombatFloater_CopyRange_0x38_Inferred(void *srcBegin, void *srcEnd,
                                                         void *dst)
{
    return (void *)FUN_00404730((int)srcBegin, (int)srcEnd, (int)dst);
}

// =============================================================================
// FUN_00426f70  (twin of RunElem_WStringDtor_Plus0C_Trampoline_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00426f70
// Address:   0x00426f70  (autoassault.exe, image base 0x400000)
// System:    skills-abilities / UI text-layout
// Generated: 2026-08-05 R10-026 refresh (was 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite. Bit-for-bit: DEFERRED.
// =============================================================================

// PURPOSE: thiscall trampoline — destroy embedded basic_string<wchar_t> at +0x0C.
// Canonical: RunElem_WStringDtor_Plus0C_Trampoline_Inferred
// Parent: StdVector_DestroyRuns_0x80_Inferred (0x004271c0)
//
// Bytes: 83 C1 0C  FF 25 AC 62 9C 00
// IAT 0x009c62ac = PTR_~basic_string<wchar_t,...>

void __fastcall FUN_00426f70(void* elem /* ECX */)
{
    // ADD ECX, 0x0C; JMP [IAT ~basic_string<wchar_t>]
    // Decompiler equivalent (call-shaped; bytes are tail JMP):
    //   ~basic_string<wchar_t>((char*)elem + 0x0C);
    (void)elem;
}

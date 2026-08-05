// =============================================================================
// _CxxThrowException
// -----------------------------------------------------------------------------
// Purpose:  MSVC C++ exception throw entry — PE import trampoline only.
//           Jumps through IAT slot to CRT implementation. Noreturn.
//
// Address:  0x006a3d60  (autoassault.exe, image base 0x400000)
// Body:     0x006a3d60–0x006a3d65 (6 bytes)
// Stable:   aa_006a3d60
// System:   CRT / MSVC C++ EH
//
// Does NOT: contain game logic, object layouts, or AutoAssault domain code.
// Callers:  any C++ `throw` site / helper that targets this import.
//
// Exactness: bytes are the entire unit (jmp [IAT]).
// Bit-for-bit / runtime / differential: N/A for game logic; CRT external.
// Dual A/B: accept (2026-07-29 W17-N seal).
// =============================================================================

/* _CxxThrowException — import thunk.

   Parameters (CRT stdcall):
     pExceptionObject: pointer to thrown object storage
     pThrowInfo:       MSVC ThrowInfo* describing type

   Returns: does not return */

__declspec(noreturn)
void __stdcall _CxxThrowException(void *pExceptionObject, ThrowInfo *pThrowInfo)
{
  /* bytes: FF 25 D8 64 9C 00  — jmp dword ptr [0x009c64d8] */
  /* WARNING noise: decompiler may say jumptable / recursive call */
  ((void (__stdcall *)(void *, ThrowInfo *))*(void **)0x009c64d8)
      (pExceptionObject, pThrowInfo);
}

// =============================================================================
// Path_GetFileName  (FUN_007b6420)
// -----------------------------------------------------------------------------
// Stable ID: aa_007b6420
// Address:   0x007b6420 – 0x007b644f  (autoassault.exe, image base 0x400000)
// System:    path utilities (ND UI / resource load)
// Generated: 2026-07-29 dual A/B seal (W17-L OWN-ONLY)
// Exactness: Behavior-preserving rewrite of decompiler + read_memory body.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Return pointer to the filename component of a path (after last '\\' or '/').
//   If no separator present, return the original path pointer.
//   Does not allocate; result points into the input string.
//
// ABI (retail): path in EDI (register). Return char* in EAX. Plain RET.
// Callee: strrchr (IAT 0x009c662c). EBX preserved.
// Port ABI: ordinary C parameter (path).
// Name: inferred Path_GetFileName (PathFindFileName-like).
// =============================================================================

#include <cstring>

char *FUN_007b6420_path_in_edi_semantics(char *path /* retail: EDI */)
{
  char *pcVar1; // last '\\'
  char *pcVar2; // last '/'

  pcVar1 = std::strrchr(path, 0x5c);
  pcVar2 = std::strrchr(path, 0x2f);
  if (pcVar1 == nullptr) {
    if (pcVar2 == nullptr) {
      return path;
    }
  } else if (pcVar2 < pcVar1) {
    pcVar2 = pcVar1;
  }
  return pcVar2 + 1;
}

// Preferred name alias
char *Path_GetFileName(char *path)
{
  return FUN_007b6420_path_in_edi_semantics(path);
}

// Ghidra export name
char *FUN_007b6420(char *path)
{
  return FUN_007b6420_path_in_edi_semantics(path);
}

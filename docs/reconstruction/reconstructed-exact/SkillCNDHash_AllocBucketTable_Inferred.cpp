// =============================================================================
// SkillCNDHash_AllocBucketTable_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004cb410
// Address:   0x004cb410–0x004cb4a0  (autoassault.exe @ 0x400000; 145 B)
// System:    skills-abilities / skill-family CNDHash
// Dual A/B:  2026-08-04 WQ9E-A
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================
// PURPOSE
//   Allocate skill-family CNDHash bucket pointer table + contiguous 0xc
//   sentinel slab. Requires log2 byte at this+0x1c in [1,16]. Provisional
//   count at this+0x08 is power-of-two N (= 1<<log2 from Recreate/ctor).
//   After init, this+0x08 becomes mask N-1 for key&mask indexing.
//
// ABI
//   __thiscall; ECX = hash*; bare ret on success; noreturn throw on bad log2
//
// Callers
//   SkillCNDHash_Recreate_Inferred (0x004cbdc0) @ 0x004cbe0c
//   SkillCNDHash_Ctor_Inferred     (0x0051dd60) @ 0x0051ddba
//
// Sentinel stamp
//   PTR_LAB_009cb970 @ each bucket head (skill family; not 009ce090 medal)
//
// Parallel
//   CNDHash_AllocBucketTable_009ce090 @ 0x0051ba40
//   CNDHash_AllocBucketTable_Inferred @ 0x00413d80
//
// Fail path
//   vog log "VOG_DEBUG_STOP"; throw 0x80004003 (E_POINTER)
//
// Rejected aliases
//   Named_VOG_DEBUG_STOP_004cb410 as product identity
//   type-merge with inventory alloc helpers (different VA/stamp)
// =============================================================================

#include <cstdint>
#include <cstdlib>

extern void *operator new[](std::size_t n);
extern void FUN_007a4480(int level, const char *msg);
extern void _CxxThrowException(void *pExceptionObject, void *pThrowInfo);
extern void *PTR_LAB_009cb970; // sentinel stamp @ 0x009cb970
extern void *DAT_00acc430;     // ThrowInfo

// void __thiscall — bare ret (or noreturn throw)
void __thiscall SkillCNDHash_AllocBucketTable_Inferred(int thisHash)
{
  char log2 = *reinterpret_cast<char *>(thisHash + 0x1c);
  if (!(log2 > 0 && log2 < 0x11)) { // 1..16
    FUN_007a4480(0, "VOG_DEBUG_STOP");
    int code = static_cast<int>(0x80004003u); // E_POINTER; decomp -0x7fffbffd
    _CxxThrowException(&code, &DAT_00acc430);
  }

  int N = *reinterpret_cast<int *>(thisHash + 8);
  void **table = static_cast<void **>(operator new[](static_cast<std::size_t>(N) * 4u));
  *reinterpret_cast<void ***>(thisHash + 0x10) = table;

  void *slab = std::malloc(static_cast<std::size_t>(N) * 0xCu);
  std::uint32_t i = 0;
  if (N != 0) {
    do {
      table[i] = static_cast<char *>(slab) + i * 0xC;
      std::uint32_t *sent = static_cast<std::uint32_t *>(table[i]);
      i = i + 1;
      *sent = reinterpret_cast<std::uint32_t>(&PTR_LAB_009cb970);
      sent[1] = 0;
      sent[2] = 0;
    } while (i < static_cast<std::uint32_t>(N));
  }

  *reinterpret_cast<int *>(thisHash + 8) = N - 1; // COUNT → MASK
}

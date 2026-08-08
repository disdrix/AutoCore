// =============================================================================
// FUN_00406420 — clean twin of CNDHash_Dtor_00a2c2b0
// -----------------------------------------------------------------------------
// Stable ID: aa_00406420
// Address:   0x00406420–0x0040649a  (123 B)
// Dual A/B:  2026-08-04 WQ9H-D
// Prefer named source: CNDHash_Dtor_00a2c2b0.cpp
// =============================================================================

#include <cstdint>

extern void *PTR_FUN_00a2c2b0;
extern void FUN_007a4480(int level, const char *msg);
extern void CNDHash_DestroyBucketTable_00a2c2e4(/* EAX */ void *hash);
extern void FUN_00416e80(void *freelistSubobject);

void __fastcall FUN_00406420(void *thisHash /*ECX*/)
{
  *reinterpret_cast<void **>(thisHash) = &PTR_FUN_00a2c2b0;

  if (*reinterpret_cast<char *>(reinterpret_cast<char *>(thisHash) + 0x1d) != '\0') {
    FUN_007a4480(0, "HashError:Destructor, already locked for traversal");
    FUN_007a4480(0, "VOG_DEBUG_STOP");
  }

  CNDHash_DestroyBucketTable_00a2c2e4(thisHash);
  FUN_00416e80(reinterpret_cast<char *>(thisHash) + 0x20);
}

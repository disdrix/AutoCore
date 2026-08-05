// =============================================================================
// NDResource_LoadByKey
// -----------------------------------------------------------------------------
// Stable ID: aa_00423ac0
// Address:   0x00423ac0  (autoassault.exe, image base 0x400000)
// System:    nd-resource
// Generated: 2026-07-23 scaffold; 2026-07-29 dual A/B machine seal
// Exactness: Behavior-preserving rewrite of decompiler + read_memory CF.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes:
 * - __stdcall, four stack args, ret 0x10.
 * - Global cache pointer DAT_00d1f050 (runtime-filled).
 * - Type token from FUN_00423b10() (not a formal).
 * - *pOut always written; null → -1; else vtbl+4 bool → 0/1.
 * - NDXml_LoadDocumentFromPath treats only rc < 0 as error.
 */

// External symbols (names sealed where known; FUN_* residual):
//   FUN_00423b10
//   NDResourceCache_LookupOrCreate  @ 0x0075dba0
//   DAT_00d1f050

extern void *DAT_00d1f050;
extern void *FUN_00423b10(void);
extern void *NDResourceCache_LookupOrCreate(void *cache, void *key, void *typeToken,
                                            void *matchCtx, int createPolicy);

/* NDResource_LoadByKey

   Resolve resource via NDResourceCache_LookupOrCreate(DAT_00d1f050, key, type, ...).
   Calls virtual method +4 on result (init/load).
   Returns: -1 if null, else 0/1 from init bool.
   NOTE: NDXml_LoadDocumentFromPath treats only <0 as error, so init-fail (0) still enters Release
   path. */

int __stdcall NDResource_LoadByKey(void **pOutResource, void *pKey, void *pMatchCtx,
                                   int createPolicy)
{
  char initOk;
  void *typeToken;
  int *resource;

  typeToken = FUN_00423b10();
  resource = (int *)NDResourceCache_LookupOrCreate(DAT_00d1f050, pKey, typeToken, pMatchCtx,
                                                   createPolicy);
  *pOutResource = resource;
  if (resource == (int *)0x0) {
    return -1;
  }
  initOk = (**(char (**)(void))(*resource + 4))();
  return (int)(initOk != '\0');
}

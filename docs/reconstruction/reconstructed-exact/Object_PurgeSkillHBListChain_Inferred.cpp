// =============================================================================
// Object_PurgeSkillHBListChain_Inferred  (was FUN_00514ff0)
// Address:  0x00514ff0  Stable: aa_00514ff0
// Dual: reviews/A|B_aa_00514ff0_Object_PurgeSkillHBListChain_Inferred.md
// =============================================================================

extern "C" void __thiscall CNDDoubleList_InvokePredicateAndRemove_Inferred(
    void* pList, void* pPredicate, void* pCtx, char nullPayloadFlag);

// void __thiscall Object_PurgeSkillHBListChain_Inferred(Object* this, int ctxHost)
// RET 4
extern "C" void __thiscall Object_PurgeSkillHBListChain_Inferred(void* pThis, int ctxHost)
{
  if (*(char*)((char*)pThis + 0x25) != '\0') {
    CNDDoubleList_InvokePredicateAndRemove_Inferred(
        *(void**)((char*)pThis + 0xb0),
        (void*)0x00512eb0,
        &ctxHost,
        0);
  }
  void* linked = *(void**)((char*)pThis + 0xac);
  if (linked != 0) {
    Object_PurgeSkillHBListChain_Inferred(linked, 0);
  }
}

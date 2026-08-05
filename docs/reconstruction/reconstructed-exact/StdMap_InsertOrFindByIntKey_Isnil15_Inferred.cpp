// =============================================================================
// StdMap_InsertOrFindByIntKey_Isnil15_Inferred
// -----------------------------------------------------------------------------
// Purpose:  MSVC std::map/set insert-or-find by int key. Walk tree, optional
//           predecessor, insert via RB helper or return existing iterator.
//           Writes pair{iterator, inserted}. Equal key does NOT rewrite value.
//
// Address:  0x004a7580  (autoassault.exe, image base 0x400000)
// Body:     0x004a7580–0x004a7638 (184 bytes; ret 8 ×3)
// Stable:   aa_004a7580
// System:   container / ordered map (FX event-map family consumers)
// Ghidra:   FUN_004a7580
//
// ABI:      __thiscall
//             ECX = MapShell *map   (+4 head, +8 size)
//             stack: outPair*, int *pKey
//             ret 8
//
// Node:     left+0 parent+4 right+8 key+0xC isnil+0x15
//           (color+0x14 used inside insert callee FUN_004a6d80)
//
// Twin:     aa_00569320 StdMap_InsertOrFindByIntKey_Inferred (isnil +0x49)
//
// Exactness: CF mirrors raw + live decompile; names cleaned / INFERRED.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept (2026-07-29 W23-F).
// =============================================================================

#include <cstdint>

// RB insert + rebalance; throws "map/set<T> too long" if size huge
void *__thiscall FUN_004a6d80(void *map, void *outIt, char addLeft, void *parent, int *pKey);

// Map predecessor — Node** in ECX; isnil +0x15
void __fastcall FUN_005a2850(void **pNode);

/* StdMap_InsertOrFindByIntKey_Isnil15_Inferred — plate-faithful CF.

   Parameters:
     map:    this / ECX — shell with head* at +4
     out:    pair out — *out = iterator node*; byte at out+4 = inserted
     pKey:   pointer to int key

   Algorithm:
     1) Walk from head->parent while !isnil(child)
     2) If last compare was left:
          if node == *head → insert left of head; inserted=1
          else predecessor(node)
     3) If node->key < *pKey → insert; inserted=1
     4) Else equal → inserted=0; it=node

   Callers (3): FUN_004a0b90, FUN_004a6390, FUN_004a4fa0 (FX paths). */

void __thiscall StdMap_InsertOrFindByIntKey_Isnil15_Inferred(
    int map,
    uint32_t *outPair,
    int *pKey)
{
    uint32_t uVar1;
    bool bVar2;
    int *piVar3;
    uint32_t *puVar4;
    uint32_t *puVar5;

    piVar3 = pKey;
    puVar5 = *(uint32_t **)(map + 4);
    bVar2 = true;
    if (*(char *)((int)puVar5[1] + 0x15) == '\0') {
        puVar4 = (uint32_t *)puVar5[1];
        do {
            puVar5 = puVar4;
            bVar2 = *pKey < (int)puVar5[3];
            if (bVar2) {
                puVar4 = (uint32_t *)*puVar5;
            } else {
                puVar4 = (uint32_t *)puVar5[2];
            }
        } while (*(char *)((int)puVar4 + 0x15) == '\0');
    }
    pKey = (int *)puVar5;
    if (bVar2) {
        if (puVar5 == (uint32_t *)**(int **)(map + 4)) {
            puVar5 = (uint32_t *)FUN_004a6d80(
                (void *)map, &pKey, 1, puVar5, piVar3);
            uVar1 = *puVar5;
            *(uint8_t *)(outPair + 1) = 1;
            *outPair = uVar1;
            return;
        }
        FUN_005a2850((void **)&pKey);
    }
    if (pKey[3] < *piVar3) {
        puVar5 = (uint32_t *)FUN_004a6d80(
            (void *)map, &pKey, (char)bVar2, puVar5, piVar3);
        *outPair = *puVar5;
        *(uint8_t *)(outPair + 1) = 1;
        return;
    }
    *(uint8_t *)(outPair + 1) = 0;
    *outPair = (uint32_t)pKey;
    return;
}

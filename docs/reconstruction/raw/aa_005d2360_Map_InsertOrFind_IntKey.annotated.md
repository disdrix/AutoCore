# Annotated low-level: Map_InsertOrFind_IntKey

| Field | Value |
|---|---|
| Stable ID | `aa_005d2360` |
| VA | `0x005d2360` |
| System | `skills-abilities` |
| Date | 2026-07-29 (dual seal; prior scaffold 2026-07-23) |

## Machine-level notes

- Source: raw capture for `aa_005d2360` + live re-decompile 2026-07-29 (body ≡ raw).
- **ABI:** `__thiscall`, **`RET 0x8`** (two stack dwords). Ghidra prototype listing a third `pKey` is a **phantom** — unused in body.
- **Actual args:** `this` = map shell (ECX); stack0 = `InsertPair* pOut`; stack1 = `IntPair* pVal` (key at `*pVal`, mapped at `pVal[1]`).
- **Do not trust** decompiler names `pMap` / `pOutPair` / `pKey` literally — first stack is **out pair**, second is **value** (key+mapped).
- Node nil flag **`+0x15`**; key **`+0x0C`**; mapped **`+0x10`**; color **`+0x14`**; size **`0x18`** (from node ctor `FUN_006173a0`).
- Callees: `FUN_005d20b0` insert+rebalance; `FUN_005a2850` predecessor.
- Only static caller: `NPC_TryCastSkillFromSet` @ `0x005d18f7` (map @ AI `+0x98`).
- Dual A/B: `reviews/A_aa_005d2360_Map_InsertOrFind_IntKey.md`, `reviews/B_aa_005d2360_Map_InsertOrFind_IntKey.md`.

## Pseudocode (annotated copy of raw)

```c
/* Map_InsertOrFind_IntKey — MSVC map insert-or-find (int key → int mapped)
 *
 * ABI: void __thiscall(MapShell *this, InsertPair *pOut, const IntPair *pVal);
 *      RET 0x8
 * Out:  pOut->it = node*; pOut->inserted = 0|1 at +4
 * Node: size 0x18; key+0x0C; mapped+0x10; color+0x14; isnil+0x15
 * Equal key: return existing, inserted=0, mapped NOT rewritten.
 *
 * Note: decompiler renames below keep raw identifiers; semantic map:
 *   this     = map shell
 *   pMap     = InsertPair *pOut   (misnamed)
 *   pOutPair = IntPair *pVal      (misnamed; first dword is key)
 *   pKey     = unused phantom
 */

void __thiscall Map_InsertOrFind_IntKey(void *this,void *pMap,void *pOutPair,int *pKey)

{
  undefined4 uVar1;
  bool bVar2;
  void *pvVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  pvVar3 = pOutPair;                         /* pVal (key at *pvVar3) */
  puVar5 = *(undefined4 **)((int)this + 4);  /* head / end */
  bVar2 = true;                              /* goLeft */
  if (*(char *)((int)puVar5[1] + 0x15) == '\0') {  /* root not nil */
    puVar4 = (undefined4 *)puVar5[1];
    do {
      puVar5 = puVar4;
      bVar2 = *(int *)pOutPair < (int)puVar5[3];   /* key < node.key (+0x0C) */
      if (bVar2) {
        puVar4 = (undefined4 *)*puVar5;            /* left */
      }
      else {
        puVar4 = (undefined4 *)puVar5[2];          /* right */
      }
    } while (*(char *)((int)puVar4 + 0x15) == '\0');
  }
  pOutPair = puVar5;                         /* parent / candidate (reuse local) */
  if (bVar2) {
    if (puVar5 == (undefined4 *)**(int **)((int)this + 4)) { /* parent == leftmost */
      puVar5 = (undefined4 *)FUN_005d20b0(&pOutPair,1,puVar5,pvVar3); /* insert left */
      uVar1 = *puVar5;
      *(undefined1 *)((int)pMap + 4) = 1;    /* inserted */
      *(undefined4 *)pMap = uVar1;           /* it */
      return;
    }
    FUN_005a2850();                          /* predecessor(&parent) */
  }
  if (*(int *)((int)pOutPair + 0xc) < *(int *)pvVar3) { /* parent.key < key → insert */
    puVar5 = (undefined4 *)FUN_005d20b0(&pOutPair,bVar2,puVar5,pvVar3);
    *(undefined4 *)pMap = *puVar5;
    *(undefined1 *)((int)pMap + 4) = 1;
    return;
  }
  *(undefined1 *)((int)pMap + 4) = 0;        /* equal key: find only */
  *(void **)pMap = pOutPair;
  return;
}
```

## Open questions

- Optional Ghidra prototype cleanup (drop phantom `pKey`).
- Optional helper product renames.
- Runtime / bit-exact image diff.

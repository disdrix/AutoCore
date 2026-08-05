# Annotated low-level: Skill_CategoryCooldownMap_Insert

| Field | Value |
|---|---|
| Stable ID | `aa_0051d2f0` |
| VA | `0x0051d2f0` |
| System | skills-abilities |
| Date | 2026-07-23; residual annotate 2026-07-29 |

## Machine-level notes

- Source: raw capture for `aa_0051d2f0` + live re-decompile/read_memory 2026-07-29.
- Prefer assembly when decompiler conflicts (out-pair `inserted` is **byte at +4**, not `param_2+1` char index confusion).
- **ABI:** `RET 0x8` — two stack formals + ECX map.
- **Semantics:** insert-or-**find**, not insert-or-assign. Equal key → `inserted=0`, no write to `+0x10/+0x14`.
- Node layout sealed by `FUN_005ae220` (`new 0x1c`): key `+0x0C`, start `+0x10`, duration `+0x14`, color `+0x18`, isnil `+0x19`.
- `FUN_005ae050` = tree **predecessor** (not insert). `FUN_0051c1c0` = insert + rebalance.
- Callers: `Skill_InsertCategoryCooldown` `0x00518e23`, `CVOGHBOKToCastAgain_ctor` `0x0051e361` only.

## Pseudocode (annotated)

```c
/* Skill_CategoryCooldownMap_Insert — Map insert-or-find
   Node {left,parent,right, key@+0xC, start@+0x10, duration@+0x14, color@+0x18, isnil@+0x19}
   size 0x1C. Map shell: head@+4, size@+8, shell 0x0C.
   RET 0x8. */

void __thiscall Skill_CategoryCooldownMap_Insert(
    int thisMap,            // ECX — CategoryCooldownMap*
    undefined4 *pOutPair,   // stack0 — {node* it @+0, u8 inserted @+4}
    int *pValue)            // stack1 — {key, startTick, durationMs}
{
  undefined4 uVar1;
  bool goLeft;
  int *pValueSaved;
  undefined4 *child;
  undefined4 *node;

  pValueSaved = pValue;
  node = *(undefined4 **)(thisMap + 4);          // head
  goLeft = true;
  if (*(char *)((int)node[1] + 0x19) == '\0') {  // root not nil
    child = (undefined4 *)node[1];
    do {
      node = child;
      goLeft = *pValue < (int)node[3];           // key < node.key (+0x0C)
      if (goLeft) {
        child = (undefined4 *)*node;             // left
      } else {
        child = (undefined4 *)node[2];           // right
      }
    } while (*(char *)((int)child + 0x19) == '\0');
  }
  pValue = (int *)node;                          // decomp reuses slot as parent*
  if (goLeft) {
    if (node == (undefined4 *)**(int **)(thisMap + 4)) { // leftmost
      node = (undefined4 *)FUN_0051c1c0(&pValue, 1, node, pValueSaved);
      uVar1 = *node;
      *(undefined1 *)((int)pOutPair + 4) = 1;    // inserted
      *pOutPair = uVar1;
      return;
    }
    FUN_005ae050();                              // Tree_Predecessor(&parent)
  }
  if (pValue[3] < *pValueSaved) {                // parent.key < key → insert
    node = (undefined4 *)FUN_0051c1c0(&pValue, goLeft, node, pValueSaved);
    *pOutPair = *node;
    *(undefined1 *)((int)pOutPair + 4) = 1;
    return;
  }
  // equal key — find only
  *(undefined1 *)((int)pOutPair + 4) = 0;
  *pOutPair = pValue;                            // existing node
  return;
}
```

## Open questions

- Optional product renames for `FUN_0051c1c0` / `FUN_005ae050` / `FUN_005ae220`.
- Runtime confirmation of no equal-key value refresh (asm already seals).

# Annotated low-level: Map_LowerBoundFindByIntKey_Isnil65 (FUN_004cbd50)

| Field | Value |
|---|---|
| Stable ID | `aa_004cbd50` |
| VA | `0x004cbd50`–`0x004cbdb1` (98 B) |
| Canonical name | `Map_LowerBoundFindByIntKey_Isnil65` |
| Ghidra name | `FUN_004cbd50` |
| System | ordered map / AI profile lookup helper |
| Date | 2026-07-29 (W26-O seal) |

## Machine-level notes

- **ABI:** `__thiscall` (`ECX=this`); two stack args; **`ret 8`** (`C2 08 00`).
- **Leaf:** no CALLs; pure tree walk.
- **Nil flag** at **`node+0x65`** (layout sibling of other Map_* helpers with different isnil offsets).
- **Key** at **`node+0x0C`**, compared as **signed dword** (`cmp [reg+0xC], reg`).
- Call sites in AI DoLogic pass a **float*** key (def field `+0x4dc`) after `FUN_00540890` map select — dword compare is valid for non-negative IEEE floats (profile floats); treat payload as dword key bits.
- Post-walk `cand.key <= *pKey` with lower_bound walk invariant ⇒ **exact match** (not pure STL lower_bound return of first ≥).

## Pseudocode (annotated)

```c
// void __thiscall Map_LowerBoundFindByIntKey_Isnil65(MapHeader *this, Node **pOut, int *pKey)
void __thiscall FUN_004cbd50(int param_1 /*this*/, uint32_t *param_2 /*pOut*/, int *param_3 /*pKey*/)
{
  // end = *(this+4); cand starts as end; root = end->parent at +4
  uint32_t *cand = *(uint32_t **)(param_1 + 4);
  if (*(char *)((int)cand[1] + 0x65) == 0) {
    uint32_t *cur = (uint32_t *)cand[1];
    do {
      if ((int)cur[3] < *param_3)          // key @ +0x0C
        cur = (uint32_t *)cur[2];          // right @ +0x08
      else {
        cand = cur;
        cur = (uint32_t *)*cur;            // left @ +0x00
      }
    } while (*(char *)((int)cur + 0x65) == 0);
  }
  if (cand != *(uint32_t **)(param_1 + 4) && (int)cand[3] <= *param_3)
    *param_2 = (uint32_t)cand;             // exact hit
  else
    *param_2 = *(uint32_t *)(param_1 + 4); // end / miss
}
```

## Open questions

- Product STL / RTTI name for the map type (large node: isnil @ +0x65 ⇒ big value_type).
- Full value payload layout beyond key/links/isnil (caller-owned).
- Whether any caller relies on pure lower_bound (first ≥) without equality — **no**: post-gate enforces equality; miss writes end.

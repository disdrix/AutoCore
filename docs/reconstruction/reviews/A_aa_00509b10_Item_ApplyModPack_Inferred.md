# Review A (reconstruction fidelity): `aa_00509b10` Item_ApplyModPack_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00509b10` |
| **VA** | `0x00509b10` |
| **Canonical name** | `Item_ApplyModPack_Inferred` (leave-FUN retail) |
| **Prior names** | `FUN_00509b10`; scaffold `Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispatch_00509b10` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (fidelity / clean ≡ raw) |
| **Counterpart** | `reviews/B_aa_00509b10_Item_ApplyModPack_Inferred.md` |
| **System** | inventory-transfer / loot affix path |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Collect existing item mod-slot IDs**, optionally **remap item type code** for type-6 subtypes 10/11, then invoke the **mod-pack resolve pair** (`FUN_005e0580` / `FUN_005e1150`) with caller-supplied pack parameters. On success, push the resolved pack id through **vtbl `+0x54`**; on failure return **0** (after freeing the temporary u16 vector when non-null).

Primary static caller: quality/affix roller `FUN_00509c70` when the “broken-def → re-roll mods” branch chooses the pack path. Secondary: `FUN_0050ac80` (kill-loot generate).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean / function record | `aa_00509b10_*` / `FUN_00509b10.cpp` |
| Live decompile | Ghidra `0x00509b10` (2026-07-29) — **≡ raw** |
| Callers | `FUN_00509c70`, `FUN_0050ac80` |
| Related | `FUN_005e0580` / `FUN_005e1150` (loot residual pair); `FUN_004073a0` vector grow |

---

## 3. Control flow (authoritative)

```
FUN_00509b10(item*, p2, p3, p4, p5):
  vec = empty u16 vector (begin/end/capacity locals)
  count = item->vtbl[+0x60]()
  if count != 0:
    for i in 0..count-1:
      slot = item->vtbl[+0x5c](i)   // low 16 bits
      if (slot & 0xffff) != 0xffffffff:
        push_back(vec, slot & 0xffff)  // FUN_004073a0 grow if needed

  typeCode = *(int*)(item[0x2a] + 0x38)   // def type
  if typeCode == 6:
    sub = *(short*)(*(int*)(item[0x2a]+0x3c) + 0x3f4)
    if sub == 10: typeCode = 0x44
    else if sub == 11: typeCode = 0x46

  FUN_005e0580(typeCode, p2, p3, p4, &vec, p5)
  result = FUN_005e1150(typeCode, p2, p3, p4, &vec, p5)
  if result < 0:
    free vec if non-null; return 0

  item->vtbl[+0x54](result)
  free vec if non-null
  return 1
```

SEH plate `LAB_009a3288` wraps the vector lifetime (operator_delete on unwind paths).

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Collects slot ids via vtbl `+0x60` count / `+0x5c` get | **High** | Loop sealed |
| Skip sentinel `0xffff` / `-1` low word | **High** | |
| Type-6 subtype 10→`0x44`, 11→`0x46` remap | **High** | Matches `00513d10` subtype window |
| `005e0580` then `005e1150` with same args + vec | **High** | Order sealed |
| `result < 0` → fail 0; else vtbl `+0x54` + success 1 | **High** | |
| `p2..p5` product meaning (quality / seed / pack id) | **Tentative** | From `00509c70`: `(1, uVar10, iVar8, 0)` |
| Exact product of `005e1150` return | **Tentative** | Negative = fail; non-neg applied |

---

## 5. Control flow: clean ≡ raw

**Yes** — scaffold preserves collect → remap → resolve pair → vtbl apply → free/return.

---

## 6. Gaps / open

1. Dual `FUN_005e0580` / `FUN_005e1150` (still loot residual).
2. Seal vtbl `+0x54` as “set mod pack id” vs alternate attach.
3. Call-site semantics of the five formals beyond the broken-repack path.

**Verdict:** CF **High**. Mod-pack product labels **Tentative**. **accept-with-gaps.**

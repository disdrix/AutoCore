# Review A (reconstruction fidelity): `aa_004d2750` CVOGSectorMap_AllocateNewObjectFromCbid

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d2750` |
| **VA** | `0x004d2750` |
| **Canonical name** | `CVOGSectorMap_AllocateNewObjectFromCbid` |
| **Ghidra name** | `FUN_004d2750` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_004d2750_CVOGSectorMap_AllocateNewObjectFromCbid.md` |
| **System** | `inventory-transfer` / kill credits drop |
| **Verdict** | **accept-with-gaps** — plate + pipeline sealed; drop-call arg recovery residual |
| **Dual status** | **Present (first full dual)** |

---

## 1. Purpose

**Spawn a currency/credit world object from a 64-bit amount and drop it on the map.**

Plate evidence: `"allocatenewobjectfromcbid failed %d"`.

Pipeline:

1. `cbid = Credits_AmountToCurrencyCbid(amountLo, amountHi)` (`FUN_005123e0`).
2. `item = CVOGReaction_GiveItemByCbid(cbid)` — factory (dual-sealed).
3. If null → log fail with cbid and return.
4. `rc = item->vtbl[+0x08](cbid, map, 1)` — type init.
5. If `rc == 0`: store `amountLo` at `item[0x31]` (dword index → **+0xc4**), and `param_4/param_5` at `item[0x5c]/[0x5d]` (**+0x170/+0x174**).
6. Allocate next map COID from `map+0xe6e0` 64-bit counter (post-inc with carry).
7. `Object_SetCoidIdentity(item, oldLo, oldHi, 1)` (`FUN_00512160`).
8. `item->vtbl[+0x2a4](*(map+0xe4e8))` — bind map/context.
9. `CVOGSectorMap_DropObjectOnGround(...)` (`FUN_004d0ed0`) — place in world.

Sole xref: `0x004dad87` inside `CVOGCombat_OnDeathAwardKillXp` (credits floaters path).

---

## 2. ABI (decompiler-derived)

```c
// __thiscall this = sector map*
void CVOGSectorMap_AllocateNewObjectFromCbid(
    Map* this,
    int amountLo,          // param_2 → also stored on item if init ok
    uint32_t amountHi,     // param_3 → tier select with lo
    int extraA,            // param_4 → item[+0x170]
    int extraB);           // param_5 → item[+0x174]
```

Semantic of `extraA/B` residual (may be owner TFID / source ids from kill path).

---

## 3. COID counter (SEALED shape)

```
lo = map[+0xe6e0]; hi = map[+0xe6e4];
map[+0xe6e4] = hi + (lo > 0xfffffffe);  // carry if lo==0xffffffff
map[+0xe6e0] = lo + 1;
Object_SetCoidIdentity(item, lo, hi, 1);
```

Same pattern as `004d2820` when object lacks identity.

---

## 4. Inspected artifacts

| Artifact | Path |
|---|---|
| Live decompile | Ghidra `0x004d2750` |
| Raw / annotated / clean | `aa_004d2750_*`, `FUN_004d2750.cpp` |
| Callees dualed this batch | `005123e0`, `00512160`, `004d0ed0` |
| Factory dual | `A_aa_0051a170_CVOGReaction_GiveItemByCbid` |
| Parent | `A_aa_004da630_*` credits floaters |

---

## 5. Confidence

| Claim | Confidence |
|---|---|
| Amount → CBID → GiveItemByCbid | **Confirmed** |
| Fail log plate | **Confirmed** |
| COID stamp + counter | **Confirmed** |
| Drop after bind | **Confirmed** |
| `item[0x31]` stores amountLo | **High** |
| `param_4/5` semantic | **Tentative** |
| Drop arg list exact (decompiler unaff) | **Medium** |

---

## 6. Gaps

1. Recover kill-site stack for drop radius / HB flag.
2. Name `extraA/B` from `004dad87` context.
3. vtbl `+0x08` / `+0x2a4` product names.

**Verdict:** **accept-with-gaps**.

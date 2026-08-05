# Review B (skeptical / adversarial): `aa_00539dd0` CNDHash_Recreate_009cfa7c

| Field | Value |
|---|---|
| **Stable ID** | `aa_00539dd0` |
| **VA** | `0x00539dd0` |
| **Canonical name** | `FUN_00539dd0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Adversarial dual |
| **Counterpart** | `reviews/A_aa_00539dd0_CNDHash_Recreate_009cfa7c.md` |
| **System** | container / CNDHash / missions-progression |
| **Verdict** | **accept-with-gaps** |

---

## 1. What this is *not*

| Attack | Result |
|---|---|
| “Same function as `00539d70`” | **Falsified** — different teardown (`005390d0`/`00538190`) and AllocBuckets (`00537b50`) |
| “Active-mission hash recreate (`+0x540`)” | **Falsified** — caller uses `*(char+0x530)` |
| “Pending objectives (`+0x55c`)” | **Falsified** — that slot uses `00539e30` in same parent |
| “Lock aborts” | **Falsified** — continue after log |
| “Non-owning” | **Falsified** — value `operator_delete` in clear twin |
| “`cdecl` multi-arg” | **Falsified** — thiscall + `RET 4` |

---

## 2. Cross-check vs dual A

| A claim | B stance |
|---|---|
| Skeleton ≡ sibling Recreate | **Agree** |
| Slot `+0x530` / ctor `0x14c` | **Agree** |
| Owning teardown + AllocBuckets_00537b50 | **Agree** |
| Product English open | **Agree** |
| Sole static caller `FUN_0052b4e0` | **Agree** |

---

## 3. Surviving contract

```
// thiscall RET 4 — twin for object vtbl 009cfa7c / char+0x530
void CNDHash_Recreate_009cfa7c(CNDHash* this, uint8_t log2Bits);
// lock → log+continue; teardown 005390d0; bits/size/head/tail; AllocBuckets 00537b50
```

### Traps

1. Do **not** wire this VA into `+0x540`/`+0x538`/`+0x55c` slots.
2. Do **not** treat as RemoveAll (table survives RemoveAll; dies here).
3. Parent `FUN_0052b4e0` also clears other hashes via **vtbl+4**, not this Recreate.

---

## 4. Residual

1. Hash product name at `+0x530`.
2. Why bulk reset recreates only `+0x530` and `+0x55c` while others use vtbl method.
3. Runtime.

**Verdict:** **accept-with-gaps**. Accept A.

# Review B (skeptical / adversarial): `aa_00539d70` CNDHash_Recreate_009cfa64

| Field | Value |
|---|---|
| **Stable ID** | `aa_00539d70` |
| **VA** | `0x00539d70` |
| **Canonical name** | `FUN_00539d70` / `CNDHash_Recreate` (vtbl family open) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Adversarial dual (attack over-claims) |
| **Counterpart** | `reviews/A_aa_00539d70_CNDHash_Recreate_009cfa64.md` |
| **System** | container / CNDHash |
| **Verdict** | **accept-with-gaps** on CF/ABI; **reject** merge with non-owning RemoveAll and wrong AllocBuckets twins |

---

## 1. What this is *not*

| Attack | Result |
|---|---|
| “Early-return on lock (safe no-op)” | **Falsified** — logs then continues teardown/realloc |
| “Same as RemoveAll” | **Falsified** — frees bucket table + sentinel slab; RemoveAll keeps table |
| “Non-owning clear” | **Falsified** — teardown `FUN_00538120` `operator_delete`s node value `[2]` |
| “Identical to `00539dd0` / `00539e30`” | **Falsified** — different teardown (`00539090`) + AllocBuckets (`00537a10` / stamp `009cf004`) |
| “`void` / no stack cleanup” | **Falsified** — `RET 4` |
| “Resizes without freeing old table” | **Falsified** — teardown nulls `+0x10` after free |
| “Changes bits without realloc when size same” | **Falsified** — always teardown + AllocBuckets |

---

## 2. Decompiler hazards corrected by dual

| Decomp artifact | Reality |
|---|---|
| `FUN_00539090()` / `FUN_00537a10()` no args | Asm: `mov ecx,esi` before each — **`__fastcall`/`__thiscall` this in ECX** |
| `int param_1` as first arg | `this` in ECX; stack only `byte bits` |
| Scaffold “for×1” noise | No loop in this body — loops live in callees |

---

## 3. Layout challenges

| Challenge | Response | CF |
|---|---|---|
| Is `+0x08` still size after return? | AllocBuckets stores `N-1` mask | **High** |
| Does lock block recreate? | No — only logs | **High** |
| Is freelist wiped? | Teardown pushes nodes onto freelist; recreate does not zero `+0x20` | **High** residual keep-alive |
| Sole caller ApplyCreate | `get_function_callers` | **High** static |

---

## 4. Surviving contract (minimal)

```
// thiscall; RET 4
void CNDHash_Recreate_009cfa64(CNDHash* this, uint8_t log2Bits);
// if lock@+0x1d: log Recreate-locked + VOG_DEBUG_STOP (continue)
// teardown owning (00539090/00538120); free table
// +0x1c = bits; +0x14=+0x18=0; +0x08 = 1<<bits; AllocBuckets_00537a10
// Do NOT merge with 00539dd0/00539e30 or RemoveAll twins.
```

---

## 5. Cross-check vs dual A

| A claim | B stance |
|---|---|
| `RET 4` + lock-continue | **Agree** |
| Owning teardown + AllocBuckets_00537a10 | **Agree** |
| Char slot `+0x534` | **Agree** offset from ctor index `0x14d`; product name open |
| Product English open | **Agree** |
| Twin separation High | **Agree** |

---

## 6. Residual (honest)

1. Product method name / RTTI.
2. Whether ApplyCreate always re-passes **same** bits (observed: read from `hash+0x1c`).
3. Freelist slab capacity after multi-recreate.
4. Bit-exact / runtime.

---

## 7. Verdict

### **accept-with-gaps**

CF, ABI, owning teardown, AllocBuckets twin, and non-identity with sibling Recreates are **sealed**. Reject lock-as-abort, RemoveAll merge, and cross-twin identity.

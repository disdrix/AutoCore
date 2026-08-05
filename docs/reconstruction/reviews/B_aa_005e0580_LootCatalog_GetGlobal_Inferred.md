# Review B (skeptical / adversarial): `aa_005e0580` LootCatalog_GetGlobal_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005e0580` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005e0580_LootCatalog_GetGlobal_Inferred.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Multi-arg loot roll / filter | Live body is one `return &DAT_00bc56d8` | **Falsified** multi-arg role |
| 2 | Is `LootManager` ctor (`0050c1b0`) | Distinct VA; ctor is `0xbc` new + vtbl | **Falsified** merge |
| 3 | Call-site args are formals of this FN | Body has no stack reads | **Falsified** — leftovers for next call |
| 4 | Returns table row, not object base | Callees use huge `this+0x8700c` / `+0x10e00c` | **Survives** as object base pointer |
| 5 | Product name proven | No string at site | **Survives** as `_Inferred` gap only |

---

## 2. Live ≡ raw

Live `batch_decompile` matches raw `aa_005e0580` byte-for-byte in structure: `return &DAT_00bc56d8`.

---

## 3. Surviving contract

```
// no args
// return &DAT_00bc56d8   // global loot catalog singleton base
```

**Gaps kept:** retail type name; layout of singleton.

**Verdict:** **accept**.

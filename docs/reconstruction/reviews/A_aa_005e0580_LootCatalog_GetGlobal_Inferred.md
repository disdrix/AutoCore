# Review A (reconstruction fidelity): `aa_005e0580` LootCatalog_GetGlobal_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005e0580` |
| **VA** | `0x005e0580` |
| **Canonical name (Ghidra)** | `FUN_005e0580` |
| **Proposed name** | `LootCatalog_GetGlobal_Inferred` (**High** role; product name absent) |
| **Prior scaffold alias** | `Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispatch_005e0580` — chain-of-callers only |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile) |
| **Counterpart** | `reviews/B_aa_005e0580_LootCatalog_GetGlobal_Inferred.md` |
| **System** | `inventory` / loot generation catalog |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

---

## 1. Purpose

**Return the address of the global loot catalog / table manager singleton** at `DAT_00bc56d8`.

Body is a one-instruction getter:

```c
void *LootCatalog_GetGlobal_Inferred(void)
{
  return &DAT_00bc56d8;
}
```

Used by loot roll paths so subsequent thiscalls (`FUN_005e1030`, `FUN_005e1150` / `FUN_005e07d0` / `FUN_005e0cd0`) bind `this` to that large global object (offsets such as `+0xc`, `+0x8700c`, `+0x10e00c` in callees).

**Not** a roll, not a ctor, not a filter. Call-site argument lists in decompiler are **stack leftovers / prep for the next call** — this function takes no meaningful args.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x005e0580` |
| Callers | `get_function_callers` → `004d0cf0`, `00509b10`, `0050ac80`, `0050c1b0`, `00541e70` |
| Consumer dual | `A_aa_004d0cf0_Inv_GenerateLootItem_type` cites this + `005e1030` |
| LootManager ctor | `A_aa_0050c1b0_*` mentions validation touch of `005e0580` during load |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact` for `aa_005e0580` |
| Function record | `docs/reconstruction/functions/aa_005e0580_FUN_005e0580.md` |

**This pass:** live decompile; callers. **Not performed:** Launcher, runtime, bit-exact, ledgers.

---

## 3. Signature

```c
// cdecl / no-args; return EAX = &DAT_00bc56d8
void *LootCatalog_GetGlobal_Inferred(void);
```

---

## 4. Callers / callees

| Direction | Symbol | Role |
|---|---|---|
| Caller | `Inv_GenerateLootItem_type` `0x004d0cf0` | Get catalog then roll via `005e1030` |
| Caller | `FUN_0050ac80` | Kill/zone loot materialize path |
| Caller | `FUN_00509b10` | Affix/mod roll path → `005e1150` |
| Caller | `LootManager_ctor_Inferred` `0x0050c1b0` | Load-time touch / validation |
| Caller | `FUN_00541e70` | Additional content path |
| Callee | *(none)* | pure return |

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Single `return &DAT_00bc56d8` | Yes |
| No branches / no callees | Yes |

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Returns `&DAT_00bc56d8` only | **High** | live ≡ raw |
| Global is loot catalog / table manager | **High** | used as `this` for loot band rolls |
| Product class name of `DAT_00bc56d8` | **Tentative** | `_Inferred` |
| Call-site args are meaningful formals | **Falsified** | body ignores args |

---

## 7. Gaps / open

1. Exact retail name of the global type at `DAT_00bc56d8`.
2. Full layout of the singleton (huge; residual in `005e07d0` / `005e0cd0`).

**Verdict:** **accept** — trivial High-confidence getter; dual sealed.

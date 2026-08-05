# Review A (reconstruction fidelity): `aa_005129b0` EnsureLootRarityTableLoaded_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005129b0` |
| **VA** | `0x005129b0` |
| **Canonical name** | `EnsureLootRarityTableLoaded_Inferred` (leave-FUN retail) |
| **Prior names** | `FUN_005129b0`; scaffold `Named_CalleeOf_Named_Client_InitInstance_005129b0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (fidelity / clean ≡ raw) |
| **Counterpart** | `reviews/B_aa_005129b0_EnsureLootRarityTableLoaded_Inferred.md` |
| **System** | inventory-transfer / loot tables |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Allocate + load the `tLootRarity` client table** into global `DAT_00b04214`. Sequence:

1. `DAT_00b04214 = operator_new(0x288)`
2. `FUN_007e1d80()` — DB/WAD reader enter (shared ensure bookend)
3. `FUN_007ce130(DAT_00b04214)` — **`Inv_tLootRarity`** row loader (`//tLootRarity/row`)
4. `FUN_007b7df0()` — DB/WAD reader leave

Sibling of the Experience/Quest ensure family (same enter/leave pair) but **always allocates 0x288** before load rather than only pushing a map root. No in-body ready-flag early-out; no `VOG_DEBUG_STOP` on failure in this thin wrapper.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean / function record | `aa_005129b0_*` |
| Live decompile | Ghidra `0x005129b0` (2026-07-29) — **≡ raw** |
| Loader dual | `reviews/A_aa_007ce130_Inv_tLootRarity.md` |
| Enter/leave dual | `reviews/A_aa_007b7df0_*` (lists this unit as ensure caller) |
| Callers | `FUN_0050ac80`, `FUN_00847240`, `FUN_0094a6a0` |

---

## 3. Control flow

```
FUN_005129b0():
  DAT_00b04214 = operator_new__(0x288)
  FUN_007e1d80()
  FUN_007ce130(DAT_00b04214)   // Inv_tLootRarity
  FUN_007b7df0()
  return
```

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| No args / void return | **High** | |
| Alloc size **0x288** → `DAT_00b04214` | **High** | |
| Loader is `Inv_tLootRarity` `0x007ce130` | **High** | Dual + XPath `//tLootRarity/row` |
| Enter `007e1d80` / leave `007b7df0` bookends | **High** | Family pattern |
| No fail `VOG_DEBUG_STOP` in this body | **High** | Linear four calls |
| Idempotent / safe if called twice | **Open** | Overwrites global pointer; possible leak if re-entered |
| Ready-flag lives in callers | **Probable** | Same as other ensures |

---

## 5. Control flow: clean ≡ raw

**Yes** — four-call linear body.

---

## 6. Gaps / open

1. Whether callers null-check `DAT_00b04214` before calling (avoid double-alloc).
2. Schema of 0x288 object beyond rarity rows (count fields, weights).
3. Relationship to kill-loot color/rarity selection consumers.

**Verdict:** CF **High**. Lifetime/idempotence residual. **accept-with-gaps.**

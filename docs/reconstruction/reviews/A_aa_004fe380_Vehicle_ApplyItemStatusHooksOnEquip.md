# Review A (reconstruction fidelity): `aa_004fe380` Vehicle_ApplyItemStatusHooksOnEquip

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fe380` |
| **VA** | `0x004fe380` |
| **Canonical name** | `Vehicle_ApplyItemStatusHooksOnEquip` |
| **Aliases** | `FUN_004fe380`, equip/unequip status-effect hook applicator |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B — Equip callee residual) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004fe380_Vehicle_ApplyItemStatusHooksOnEquip.md` |
| **System** | `inventory-transfer` / skills |
| **Dual status** | **Present** (first dual pair) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Apply / refresh **status-effect or presentation hooks** tied to an item’s skill/mod tables when equipping (and related bind paths). Distinct from `FUN_004fdcb0` (active skill cast): this unit looks up handler objects via `FUN_00508c00` / `FUN_00508c50` and invokes **`handler.vtbl+4(item, charResolve)`** when item def subtype matches:

| Subtype at `*(item[0x2a]+0x3c)+0x3f4` | Handler family |
|---:|---|
| **0xb** | `FUN_00508c00` result |
| **10** (`0x0a`) | `FUN_00508c50` result |

**Gates:** vehicle character host `+0xb0` non-null, `host.vtbl+0x1dc()` non-null, item non-null.

**Flow:**

1. `FUN_004ce940()` context touch.
2. Loop `i = 0 .. item.vtbl+0x60()`: load skill/mod id via `vtbl+0x5c(0)` (decompiler residual on index), resolve both handler maps; if subtype matches, call handler `+4` with character resolve args (includes stack/`unaff_retaddr` flag residual).
3. Second loop over `item.vtbl+0x80()` entries: hash-lookup skill def through global `DAT_00b041fc` tree (`+0xf10`), ensure loaded `FUN_004f1e20`, read id at def`+0x4c0`, same handler dual call pattern for subtypes 0xb / 10.

---

## 2. Calling convention

| Slot | Role |
|------|------|
| **ECX** | vehicle (this) |
| stack0 | item* |
| stack residual | equip vs unequip flag appears in decompiler as `unaff_retaddr` — **High residual**, not fully formalized |

Xrefs: ornament path `004fe67f` / `004fe753`, wheelset/create `004ff47b` / `004ff4cd` — matches equip dual notes (`FUN_004fe380(prev,0)` unbind vs `(…,1)` bind).

---

## 3. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_004fe380_*`, `reconstructed-exact/FUN_004fe380.cpp` |
| Live decompile | Ghidra 2026-07-29 ≡ raw (including unaff residuals) |
| Parent duals | `A_aa_004fe620_Vehicle_SetEquippedOrnament` (calls with 0/1) |
| Sibling cast | `aa_004fdcb0` (cast skills — complementary) |
| Handler lookups | `FUN_00508c00`, `FUN_00508c50` |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Host + resolve + item gates | **Yes** |
| `FUN_004ce940` then skill-count loop | **Yes** |
| Dual handler resolve 00508c00/50 | **Yes** |
| Subtype 0xb / 10 gates | **Yes** |
| handler vtbl `+4(item, …)` | **Yes** |
| Second hash-def loop with `FUN_004f1e20` ensure | **Yes** |
| Clean scaffold ≡ raw (including residual vars) | **Yes** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Role = status/hook apply not mesh attach | **High** | no slot stores |
| Subtype 10 vs 0xb splits handler maps | **High** | shorts at def `+0x3f4` |
| Called on equip and clear paths | **High** | ornament dual 0/1 |
| Exact 3rd stack flag ABI | **Tentative** | `unaff_retaddr` |
| Loop index vs always `0` in first `+0x5c` arg | **Tentative** | decompiler may collapse index |
| Handler product names | **Open** | |

---

## 6. Gaps

1. Formal signature of third flag (equip vs remove) — parent passes immediates; decompiler residual.
2. `FUN_00508c00` / `00508c50` dual units still open.
3. Hash walk at `DAT_00b041fc+0xf10` exact structure (pattern shared with other skill maps).
4. Runtime / bit-exact open.

**Verdict:** Equip status-hook applicator sealed at CF/role level. **accept-with-gaps.**

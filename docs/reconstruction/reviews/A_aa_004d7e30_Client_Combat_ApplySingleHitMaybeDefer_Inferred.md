# Review A (reconstruction fidelity): `aa_004d7e30` Client_Combat_ApplySingleHitMaybeDefer_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d7e30` |
| **VA** | `0x004d7e30` |
| **Canonical name (Ghidra)** | `FUN_004d7e30` |
| **Proposed name** | `Client_Combat_ApplySingleHitMaybeDefer_Inferred` (**High** role; product name absent) |
| **Prior scaffold alias** | (chain scaffolds only) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile) |
| **Counterpart** | `reviews/B_aa_004d7e30_Client_Combat_ApplySingleHitMaybeDefer_Inferred.md` |
| **System** | `combat` / single-target hit + deferred record |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Single-target combat hit apply with optional deferred 0x28 multi-hit-style record enqueue.**

Sibling of batch path `Client_Combat_ApplyMultiTargetHits_Inferred` (`0x004da2e0`); shares host flag `this+0x7E`, type-0x12 climb via `004bb070`, deferred enqueue `004e1600`, and hit primitive `004d78e0`.

### Control flow

1. Gate: `target == null` **or** `target->vtbl+0x198() != 0` → return 0 (skip dead/filtered — **Probable**).
2. `status = Client_Combat_ApplyHit_Inferred (004d78e0)(...)`.
3. If `host[+0x7e] == 0` **and** `param_8 == 0` → return status (no deferred pack).
4. Else build **0x28** record:
   * `operator_new(0x28)`; byte @+0x20 from `param_7`.
   * Attacker transform: null → `DAT_009cbf68`; type **0x12** climb (`vtbl+0x1d8` TFID @+0x228 → `004bb070` → parent adjust) until non-0x12; type **0x14** uses `+0x160`; else attacker `+0x160`.
   * Record `+0x00..+0x0C`: that transform **or** override `param_9..` when `(param_9 & param_10) != 0xffffffff` or `param_11 != 0`.
   * Count short @+0x22 = **1**; blob @+0x24 = `operator_new__(0x20)` with target transform `+0x160`, damage/kind fields, optional `param_13` meta overlay.
   * Status byte @ blob+0x14 from hit result.
5. `CombatDeferredQueue_Enqueue_Inferred (004e1600)(record)`.
6. Return hit status.

**Not** multi-entry batch walk (`004da2e0`), not FX stage (`004b67d0`), not queue node link alone (`004e1600`).

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x004d7e30` |
| Callers | `get_function_callers` → `0056c860`, `00589c70`, `0058c850`, `005d9290`, `006233f0`, `006236a0`, `00633650` |
| Callees duals | `A_aa_004d78e0_*`, `A_aa_004e1600_*`, `A_aa_004bb070_*` |
| Parent family | multi-target `A_aa_004da2e0_*` |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact` for `aa_004d7e30` |
| Function record | `docs/reconstruction/functions/aa_004d7e30_FUN_004d7e30.md` |

**This pass:** live decompile; callers; cross-check multi-hit dual. **Not performed:** Launcher, runtime, bit-exact, ledgers.

---

## 3. Signature

```c
// thiscall — ECX = combat/session host (flag @ +0x7E)
char __thiscall Client_Combat_ApplySingleHitMaybeDefer_Inferred(
    void *host,
    undefined4 hit_kind,      // → 004d78e0 / blob+0x15
    undefined4 damage,        // → 004d78e0 / blob+0x10
    int *attacker,            // nullable object*
    int *target,              // required
    undefined4 unused_or_pad, // param_6 unused in body
    undefined4 flags_a,       // → record +0x20; also 004d78e0
    undefined4 allow_defer_b, // with host+0x7e gates deferred
    uint mask_lo, uint mask_hi,
    undefined4 block_flag,
    undefined4 pad,
    undefined4 *hit_meta);    // optional overlay into 0x20 blob
```

---

## 4. Callers / callees

| Callee | Role |
|---|---|
| `target vtbl+0x198` | Alive/hittable gate |
| `FUN_004d78e0` | Apply hit |
| `FUN_004bb070` | Type-0x12 parent resolve |
| `operator_new` / `operator_new__` | 0x28 record + 0x20 blob |
| `FUN_004e1600` | Deferred enqueue |
| `DAT_009cbf68` | Default transform |

| Caller (sample) | Role |
|---|---|
| `0x0056c860` | Weapon/FX sibling of multi-hit |
| `0x00589c70` / `0x0058c850` | Combat apply sites |
| `0x006233f0` / `0x006236a0` / `0x00633650` | Additional combat paths |

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Null/vtbl+0x198 gate | Yes |
| `004d78e0` then optional defer | Yes |
| Type 0x12 climb + 0x14 branch | Yes |
| 0x28 record + single 0x20 blob | Yes |
| `004e1600` enqueue | Yes |

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Single-target apply + optional defer | **High** | body |
| Same deferred record schema as multi-hit (count=1) | **High** | 0x28 / 0x20 / +0x22 |
| Host `+0x7e` / `param_8` gate deferred | **High** | |
| Product function name | **Tentative** | `_Inferred` |
| `param_6` unused | **High** | not referenced |

---

## 7. Gaps / open

1. Retail names of host / type 0x12 / 0x14.
2. Full 0x20 entry schema (partial fields sealed).
3. Runtime / bit-exact not run.

**Verdict:** **accept-with-gaps** — CF High; product naming open.

# Review A (reconstruction fidelity): `aa_004d78e0` Client_Combat_ApplyHit_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d78e0` |
| **VA** | `0x004d78e0` |
| **Canonical name (Ghidra)** | `FUN_004d78e0` |
| **Proposed name** | `Client_Combat_ApplyHit_Inferred` (**High** role; product name absent) |
| **Prior scaffold alias** | `Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004d78e0` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile) |
| **Counterpart** | `reviews/B_aa_004d78e0_Client_Combat_ApplyHit_Inferred.md` |
| **System** | `combat` / single-target hit apply |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Apply one combat hit** to a target object: optional HP delta, shield pool update, combat floater enqueue, reaction/combat-hook side effects, and an optional physics impulse when flags/type allow.

Primary consumer of multi-target path `Client_Combat_ApplyMultiTargetHits_Inferred` (`0x004da2e0`) and sibling `FUN_004d7e30`.

### Branch A — zero damage (`param_3 == 0`)

Floater-only (no pool mutate) when gates pass:

* `(param_6 != 0 || host[+0x7e] != 0)` **and** `(param_8 & param_9) == 0xffffffff` **and** `param_10 == 0`
* Else early out to return.

Packs attacker/target transforms (`obj+0x160` / `param_4+0x58` dwords, fallback `DAT_009cbf68`), optional meta from `param_12+6..+8`, then `Client_EnqueueCombatFloater_INFERRED`.

### Branch B — non-zero damage

1. Read pre-hit pool via `target->vtbl+0x23c` (current HP/pool **High**).
2. Optional combat-def blob via `vtbl+0x1d4` → `+0x144` baseline.
3. If `host[+0x7e] == 0`: apply via `vtbl+0x44(param_3)` then re-read pool (`+0x23c`).
4. Else: clamp applied amount against `vtbl+0x244` max, compute delta.
5. If `param_7 == 0`: `vtbl+0x240(oldPool)` then `Vehicle_SetCurrentShield` on def blob (shield restore/sync path).
6. Floater pack when mask/flag gates match multi-hit deferred rules (`param_8&param_9`, `param_10`, `param_6` / host flag); includes damage amount + pool delta in floater struct.
7. Optional combat reaction: `vtbl+0x214` list + nested `+0x298` gate + `FUN_00513b00` + `vtbl+0x88` notify.
8. Optional impulse: when `(host[+0x7e] || param_7)` and `param_3 > 0` and target type `param_5[0x2a]+0x38 == 3` and `vtbl+0x1c8` phys component non-null with `+8` body → build transform, scale damage/`vtbl+0x244`, `FUN_0058c3b0(attacker, target, scale, …)`.

Return: high byte of applied amount / status (`uStack_b4._3_1_` / unaff_EDI noise on impulse early return).

**Not** multi-target batch (`004da2e0`), not deferred queue enqueue (`004e1600`), not FX stage (`004b67d0`).

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x004d78e0` |
| Callers | `get_function_callers` → `004d7e30`, `004da2e0` |
| Parent dual | `A_aa_004da2e0_Client_Combat_ApplyMultiTargetHits_Inferred` |
| Floater | `Client_EnqueueCombatFloater_INFERRED` (named in body) |
| Shield | `Vehicle_SetCurrentShield` (named in body) |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact` for `aa_004d78e0` |
| Function record | `docs/reconstruction/functions/aa_004d78e0_FUN_004d78e0.md` |

**This pass:** live decompile; callers; cross-check multi-hit dual. **Not performed:** Launcher, runtime, bit-exact, ledgers.

---

## 3. Signature

```c
// thiscall — ECX = combat/session host (flag @ +0x7E)
uint8_t __thiscall Client_Combat_ApplyHit_Inferred(
    void *host,              // this / param_1
    uint8_t hit_kind,        // param_2 → floater type byte
    int damage,              // param_3 — 0 = floater-only path
    int *attacker,           // param_4 — object* (nullable; transform @ +0x160)
    int *target,             // param_5 — object* (required for damage path)
    char allow_floater_a,    // param_6
    char skip_shield_sync,   // param_7 — when non-zero, skip +0x240 / SetCurrentShield
    uint mask_lo, uint mask_hi, // param_8/9 — floater gate vs 0xffffffff
    char block_floater,      // param_10
    undefined4 unused_or_pad,// param_11
    int *hit_meta);          // param_12 — optional bytes @ +6..+8
```

---

## 4. Callers / callees

| Callee | Role |
|---|---|
| `target vtbl+0x23c / +0x244 / +0x44 / +0x240 / +0x1d4 / +0x1c8 / +0x214` | Pool read/write, max, def blob, phys, reaction list |
| `Vehicle_SetCurrentShield` | Shield pool write |
| `Client_EnqueueCombatFloater_INFERRED` | Damage/miss floater UI |
| `FUN_0040da70` | Def blob resolve for attacker type-9 gate |
| `FUN_00513b00` | Pack args for reaction notify |
| `FUN_0058c3b0` | Physics impulse on type-3 targets |
| `DAT_009cbf68` | Default transform when attacker null |

| Caller | Role |
|---|---|
| `0x004da2e0` | Multi-target hit apply loop |
| `0x004d7e30` | Sibling single/batch path |

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Zero-damage floater-only gated path | Yes |
| Non-zero: pool read, host-flag apply vs clamp | Yes |
| Shield sync when `param_7==0` | Yes |
| Floater on damage with mask gates | Yes |
| Reaction `+0x214` / `+0x88` | Yes |
| Type-3 phys impulse + `0058c3b0` | Yes |
| Return status byte | Yes (noisy on impulse branch) |

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Single-target combat hit apply | **High** | floaters + shield + multi-hit caller |
| Host flag `+0x7e` selects apply mode | **High** | shared with `004da2e0` |
| `param_3==0` floater-only | **High** | |
| `vtbl+0x23c` current pool / `+0x244` max | **Probable** | usage pattern |
| Type `==3` phys impulse path | **High** CF | type name open |
| Exact return-byte meaning | **Tentative** | decompiler byte extract |
| Product function name | **Tentative** | `_Inferred` |

---

## 7. Gaps / open

1. Retail names of host, pool vtbls, type-3 class.
2. Full `param_12` hit-meta schema (only +6..+8 observed).
3. Impulse math constants (`0x3dcccccd`, `DAT_00a0f734`) product meaning.
4. Runtime / bit-exact not run.

**Verdict:** **accept-with-gaps** — hit/floater/shield CF High; vtbl product names open.

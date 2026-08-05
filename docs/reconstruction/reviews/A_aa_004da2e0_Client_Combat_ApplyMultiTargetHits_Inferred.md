# Review A (reconstruction fidelity): `aa_004da2e0` Client_Combat_ApplyMultiTargetHits_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004da2e0` |
| **VA** | `0x004da2e0` |
| **Canonical name (Ghidra)** | `FUN_004da2e0` |
| **Proposed name** | `Client_Combat_ApplyMultiTargetHits_Inferred` (**High** role; product symbol absent) |
| **Prior scaffold alias** | `Named_CalleeOf_Named_VOG_DEBUG_STOP_004da2e0` — chain-of-callers only |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile) |
| **Counterpart** | `reviews/B_aa_004da2e0_Client_Combat_ApplyMultiTargetHits_Inferred.md` |
| **System** | `combat` / multi-target hit apply + optional deferred record |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Batch-apply combat hits across a TFID array**, then optionally **queue a deferred multi-hit record** when host flag `this+0x7E` is set.

### Phase 1 — per-entry walk

For `param_3` entries, stride **2 × `TFID_16`** (decompiler advances `pTVar8 += 2`; each logical slot is **0x20** bytes — matches stage alloc in `004b67d0`):

1. `Object_ResolveFromTFID(entry)`.
2. Gate: resolved non-null **and** `vtbl+0x198()` returns **0** (alive / hittable check — **Probable**).
3. Pack ancillary bytes from the second half of the 0x20 slot into a stack blob.
4. `FUN_004d78e0(...)` — combat damage / shield / floater path (`Client_EnqueueCombatFloater_INFERRED` inside).
5. Store return status byte into the entry header.
6. Push successful `TFID*` into a local growable pointer vector (`FUN_004e39d0` grow).

### Phase 2 — deferred record (flag `this+0x7E`)

If flag set and vector non-empty:

1. `operator_new(0x28)` record; fill:
   - `+0x20` byte from `param_6`
   - `+0x10..+0x1C` transform/quat from attacker (`param_4+0x160` / type-`0x12` climb / type-`0x14` branch / default `DAT_009cbf68`)
   - `+0x00..+0x0C` either that transform **or** override `param_8..param_11` when mask/flag set
   - `+0x22` short = hit count
   - `+0x24` (`[9]`) = `operator_new__(count<<5)` copy of first staged entry blob
   - optional `param_12` overlays bytes at entry `+0x16..+0x1E`
2. `FUN_004e1600(record)` — enqueue/submit deferred hit pack.
3. Free local vector (`operator_delete`).

**Not** FX list teardown, not map erase, not single-target stage (`004b67d0`).

Callers: `FUN_004b6980` (flush staged FX targets), `FUN_0056bab0` / `FUN_0056c860` / `FUN_0056e000` (weapon multi-hit paths).

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x004da2e0` |
| Callers | `get_function_callers` → `004b6980`, `0056bab0`, `0056c860`, `0056e000` |
| Hit primitive | live `FUN_004d78e0` (floaters / shield / vehicle pools) |
| Stage producer | `A_aa_004b67d0_*` / live `004b67d0` |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact` for `aa_004da2e0` |
| Function record | `docs/reconstruction/functions/aa_004da2e0_FUN_004da2e0.md` |

**This pass:** live decompile; callers; `004d78e0` role. **Not performed:** Launcher, runtime, bit-exact, ledgers.

---

## 3. Signature

```c
// thiscall — ECX = combat/session host (flag at +0x7E)
void __thiscall Client_Combat_ApplyMultiTargetHits_Inferred(
    void *host,            // this
    TFID_16 *entries,      // param_2 — array of 0x20-stride slots
    uint count,            // param_3
    int *attacker_or_src,  // param_4 — object* (transform @ +0x160 / type climb)
    /* param_5 unused in body */,
    uint flags_a,          // param_6 → record byte @+0x20
    uint flags_b,          // param_7 → 004d78e0
    uint mask_lo, uint mask_hi, // param_8/9 — override transform when ~(mask)==0
    uint override_flag,    // param_10
    uint unused_or_extra,  // param_11
    void *aux_overlay);    // param_12 — optional bytes into first entry
```

Decompiler may drop true `this` at some call sites; body indexes `param_1+0x7E` as host.

---

## 4. Callers / callees

| Callee | Role |
|---|---|
| `Object_ResolveFromTFID` | Resolve each entry |
| `vtbl+0x198` | Per-object gate (skip when non-zero) |
| `FUN_004d78e0` | Apply hit / damage / floater |
| `FUN_004e39d0` | Grow local TFID* vector |
| `FUN_004bb070` | Type-`0x12` parent resolve during transform climb |
| `FUN_004e0eb0` | Fallback when count==0 after alloc edge |
| `FUN_004e1600` | Submit 0x28 deferred record |
| `operator_new` / `operator_new__` / `operator_delete` | Record + entry copy + vector free |

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Count loop with `+2` TFID stride | Yes |
| Resolve + vtbl gate + `004d78e0` | Yes |
| Vector push / grow | Yes |
| Early out if `+0x7E==0` (skip deferred) | Yes |
| 0x28 record build + type-0x12/0x14 climb | Yes |
| `004e1600` + vector free | Yes |

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Multi-target combat hit apply | **High** | `004d78e0` floater/shield body |
| Entry stride `0x20` | **High** | `pTVar8 += 2` on `TFID_16`; stage uses `<<5` |
| Deferred path gated by `host+0x7E` | **High** | explicit |
| Record size `0x28` + count@`+0x22` + blob@`+0x24` | **High** | body |
| Transform source `obj+0x160` / type 0x12 climb / 0x14 branch | **High** CF | product type names open |
| `vtbl+0x198` semantic (dead/filter) | **Probable** | zero required to hit |
| Product function name | **Tentative** | `_Inferred` |
| `param_5` role | **Tentative** | unused in decompiled body |

---

## 7. Gaps / open

1. Exact product name of host and of `004e1600` queue consumer.
2. Full schema of 0x20 entry (second half used as hit-meta).
3. Formal names of object types `0x12` / `0x14` at `obj[0x2a]+0x38`.
4. Caller ABI: some sites lose `this` in decompiler.
5. Runtime / bit-exact not run.

**Verdict:** **accept-with-gaps** — multi-hit CF High; deferred-queue product naming open.

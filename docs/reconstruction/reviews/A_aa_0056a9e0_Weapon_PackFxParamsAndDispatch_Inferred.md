# Review A (reconstruction fidelity): `aa_0056a9e0` Weapon_PackFxParamsAndDispatch_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0056a9e0` |
| **VA** | `0x0056a9e0` |
| **Canonical name (Ghidra)** | `FUN_0056a9e0` |
| **Proposed name** | `Weapon_PackFxParamsAndDispatch_Inferred` (**High** role; product string absent) |
| **Prior scaffold alias** | `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_PacketDispa_0056a9e0` — chain-of-callers only |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0056a9e0_Weapon_PackFxParamsAndDispatch_Inferred.md` |
| **System** | combat / client-fx (weapon event FX pack + play) |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Weapon-side helper** that binds an already-allocated **NDSpecialFX session** (`param_2`, from `FUN_004ec010` event ids such as `0x14`/`0x15`/`0xc`/`0xe`/`5`/`6`) with the same scalar param-map keys used by `Weapon_FireHelper` (`0x0056d160`), sets the FX **target TFID + zero offset**, runs the host **FX entry play** walker, then either **dispatches** the FX object through a target object's vtbl or **tears it down**.

High-level stages (this = weapon-like host in ECX):

1. **Null FX early-out:** if `param_2 == NULL` → return.
2. **Pack float3 map keys 1–4** via `NDSpecialFX_SetParamFloat3ByKey` (`0x004b7550`) on the FX session (ECX reloaded to FX; decompiler may hide reload):
   | Key | Value written (X-slot; 3-float local) |
   |---|---|
   | **1** | `0` |
   | **2** | `weapon+0xe8` |
   | **3** | `weapon+0xdc` (raw; unlike FireHelper's `(1 - +0xdc)*0.5`) |
   | **4** | `weapon+0xe0` |
3. **Target TFID source:** if `param_4 == 0` → sentinel `DAT_009d2f68` = **`(-1,-1,0,0)`** (`read_memory` sealed); else `param_4+0x160..+0x16c` (entity TFID_16).
4. **Offset local** `{0,0, weapon+0xe8, 0}` float4 → `NDSpecialFX_SetTargetTfidAndOffset` (`0x004b68c0`).
5. **Optional transform provider:** if `param_3 != NULL` and `param_3->vtbl[+0x1cc]()` non-null, capture that pointer; else `0`.
6. **Play attached FX list:** `FUN_004b7e50(0, provider, 0,0,0,0)` (forceType off; no name filter; zero position args).
7. **Dispatch or free:**
   - If `param_3 != NULL`: `param_3->vtbl[+0xf8](fx, 1, 0)` and return (FX ownership transferred / queued).
   - Else: `FUN_004b99c0()` (FX teardown) then `operator_delete(param_2)`.

**Not** the primary fire path (`Weapon_FireHelper`); sole direct caller is `FUN_0056bab0` (multi-event weapon FX dispatcher that allocates sessions by event id then packs via this unit).

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` + `analyze_function_complete` @ `0x0056a9e0` |
| Raw / annotated / clean | `raw/aa_0056a9e0_*`, `reconstructed-exact/FUN_0056a9e0.cpp` |
| Function record | `functions/aa_0056a9e0_FUN_0056a9e0.md` |
| Caller decompile | `FUN_0056bab0` @ `0x0056bab0` (3 call sites @ `0056bb28`, `0056bb9c`, `0056bc42`) |
| Peer duals | `A/B_aa_004b7550_*`, `A/B_aa_004b68c0_*`, `A/B_aa_004b7e50_*`, `A/B_aa_0056d160_Weapon_FireHelper_*` |
| Sentinel | `read_memory` `0x009d2f68` length 16 → `ff…ff 00…00` = (−1,−1,0,0) |

**Not performed:** Launcher, runtime, ledgers, Ghidra rename commit, full `FUN_004b99c0` dual.

---

## 3. Signature

```c
// thiscall; weapon host in ECX
void __thiscall Weapon_PackFxParamsAndDispatch_Inferred(
    void *weapon,      // ECX — source of +0xe8/+0xdc/+0xe0 scalars
    void *fxSession,   // Stack[0x4] — NDSpecialFX from FUN_004ec010; may be deleted
    void *targetObj,   // Stack[0x8] — optional; vtbl +0x1cc / +0xf8
    void *tfidOwner);  // Stack[0xc] — NULL → DAT_009d2f68; else TFID at +0x160
```

Storage from `analyze_function_complete`: `param_1` ECX; stack `param_2`/`param_3`/`param_4` match.

---

## 4. Callers / callees

| Direction | Symbol | Role |
|---|---|---|
| Caller (only) | `FUN_0056bab0` | Allocates event FX (`004ec010` codes 0x14/0x15/0xc/0xe/5/6), passes weapon this + FX + target/owner |
| Callee | `FUN_004b7550` ×4 | `NDSpecialFX_SetParamFloat3ByKey` keys 1–4 |
| Callee | `FUN_004b68c0` | `NDSpecialFX_SetTargetTfidAndOffset` |
| Callee | `FUN_004b7e50` | FX entry list play/attach walker |
| Callee | `FUN_004b99c0` | FX teardown when no target dispatch |
| Callee | `operator_delete` | Free FX when not dispatched |

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Null `param_2` → return | Yes |
| Key1=0, key2=+0xe8, key3=+0xdc, key4=+0xe0 via `004b7550` | Yes |
| TFID from `param_4+0x160` vs `DAT_009d2f68` | Yes |
| Zero-ish offset float4 + `004b68c0` | Yes |
| Optional `vtbl+0x1cc` provider into `004b7e50` | Yes |
| Target present → `vtbl+0xf8(fx,1,0)` else teardown+delete | Yes |

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Weapon thiscall; FX is stack arg0 | **High** | bab0 call shape + field offsets match FireHelper weapon layout |
| Param keys 1–4 pack contract | **High** | same helper dual as FireHelper; key3 raw vs transformed is intentional CF diff |
| Null TFID sentinel `DAT_009d2f68` = (−1,−1,0,0) | **Confirmed** | `read_memory` |
| Target TFID from entity `+0x160` | **High** | peer `004b68c0` / FireHelper owner copy |
| Dispatch via `vtbl+0xf8` vs teardown | **High** | explicit branch |
| `004b7e50` = play attached FX list | **High** | peer dual sealed |
| Product English name / exact event matrix | **Tentative** | keep `_Inferred` |
| Exact semantic of `vtbl+0xf8` (queue vs start) | **Probable** | residual on target class |
| Which object is ECX for each `004b*` call (FX vs weapon) | **High** role; decompiler may hide ECX reload | peer duals + FireHelper pattern |

---

## 7. Gaps / open

1. Full event-id → script name table lives in `FUN_004ec010` / `FUN_004a16d0` (`"%s_FOR_EVENT_%d"`) — not this unit.
2. Key3 in FireHelper applies `(1−x)*0.5`; this unit stores **raw** `+0xdc` — product reason open.
3. `FUN_004b99c0` teardown internals not dual-sealed this pass (only call-site role).
4. Scaffold clean plate still uses `FUN_*` names; no rename commit.

**Verdict:** **accept-with-gaps**

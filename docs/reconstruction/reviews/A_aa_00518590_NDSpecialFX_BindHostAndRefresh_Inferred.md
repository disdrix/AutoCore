# Review A (reconstruction fidelity): `aa_00518590` NDSpecialFX_BindHostAndRefresh_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00518590` |
| **VA** | `0x00518590` |
| **Canonical name (Ghidra)** | `FUN_00518590` |
| **Proposed name** | `NDSpecialFX_BindHostAndRefresh_Inferred` (**High** role; product string absent) |
| **Prior scaffold alias** | `Named_CalleeOf_Named_CalleeOf_Drive_s_VEHICLE_EXHAUST_d_00518590` — one parent string path; **too narrow** (multi-vtbl DATA xrefs) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00518590_NDSpecialFX_BindHostAndRefresh_Inferred.md` |
| **System** | `client-fx` / NDSpecialFX host bind |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Bind a game-object host onto an NDSpecialFX session and refresh param-map transforms** — the interact/reaction attach pattern referenced by peer duals (`NDSpecialFX_SetHostObject`, `NDSpecialFX_UpdateParamMapTransforms`).

Stages:

1. **Mode on `param_3` (char flag):**
   - **`param_3 == 0`:** set **`*(u8*)(fx + 9) = 1`** (session ready / enabled byte).
   - **`param_3 != 0`:** call historical symbol `CVOGReaction_FailMissionNotify(&fx)` — sealed peer dual proves this is **`Vector_PushDword`** (generic dword vector push of the FX pointer). **Which vector is `this` for that push is residual** (decompiler hides ECX reload; not a mission-fail notify).
2. **`NDSpecialFX_SetHostObject(fx, host)`** (`FUN_004b73c0(host)` with FX in ECX): store host at FX `+0x10`, cache host TFID `+0x18..+0x24` from `host+0x160`, walk child list `+0x204`.
3. **Context gate copy:** `*(fx + 0x2c) = host[0x29]` = `*(host + 0xa4)` — feeds the `this+0x2c` null-skip gate used by `004b75d0` / `004b9300`.
4. **`FUN_004b9300(0)`** — FX host spatial / attachment setup (large body; uses `+0x2c`, host `+0x10`, quat helpers). Arg `0` → falls back to host at `fx+0x10` inside callee.
5. **Optional quality/type floor:** if `host->vtbl[+0x210](0)` returns non-null object `o`, and `*(o+0x250) != 0`, and `*(char*)(*(o+0x250)+0x103) != 0`, and `*(int*)(fx+0x230) < 3` → set **`*(fx+0x230) = 3`**.
6. **`NDSpecialFX_UpdateParamMapTransforms(fx)`** (`FUN_004b75d0`) — resolve param-map float3s from host/target geometry.

**Not** mission-fail logic despite the historical `FailMissionNotify` callee name. **Not** vehicle-exhaust-only despite scaffold alias — DATA xrefs place this at multiple vtbl slots.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` + `analyze_function_complete` @ `0x00518590` |
| Raw / annotated / clean | `raw/aa_00518590_*`, `reconstructed-exact/FUN_00518590.cpp` |
| Function record | `functions/aa_00518590_FUN_00518590.md` |
| Wrapper caller | `FUN_005829d0` @ `0x005829d0` → `FUN_00518590(param_2,param_3,param_4)` then optional `FUN_004b7030` |
| Xrefs | call @ `005829f3`; DATA vtbl-ish `009ce344`, `009d34bc`, `009d4244`, `009dbcf4` |
| Peer duals | `A/B_aa_004b73c0_NDSpecialFX_SetHostObject_*`, `A/B_aa_004b75d0_*`, `A/B_aa_004149d0_CVOGReaction_FailMissionNotify` (Vector_PushDword) |

**Not performed:** Launcher, runtime, ledgers, full `004b9300` dual, vtbl owner class names.

---

## 3. Signature

```c
// thiscall — host object in ECX (param_1); FX session on stack
void __thiscall NDSpecialFX_BindHostAndRefresh_Inferred(
    void *hostObject,  // ECX — game object; provides +0x160 TFID, +0xa4 context, vtbl+0x210
    void *fxSession,   // Stack[0x4] — NDSpecialFX host being bound
    char modeFlag);    // Stack[0x8] — 0: set fx+9=1; nonzero: Vector_PushDword(&fx)
```

Note: nested `004b73c0` / `004b75d0` / `004b9300` are **thiscall on `fxSession`** (ECX reload; often elided in decompiler display).

---

## 4. Field / offset map

| Slot | Role | Conf |
|---|---|---|
| `fx+0x9` | Ready/enabled byte set when `modeFlag==0` | **High** |
| `fx+0x10` | Host object (via `004b73c0`) | **High** (peer) |
| `fx+0x2c` | Context / gate ptr ← `host+0xa4` | **High** |
| `fx+0x230` | Type/priority int; floored up to **3** under vtbl+0x210 chain | **High** (write); English **Tentative** |
| `host+0x160` | TFID_16 for host cache (inside SetHostObject) | **High** |
| `host+0xa4` (`[0x29]`) | Source of FX `+0x2c` | **High** |
| host `vtbl+0x210` | Resolve related object (arg 0); then `+0x250` → `+0x103` flag | **Probable** |

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| `modeFlag==0` → `fx+9=1` else Vector_PushDword | Yes |
| SetHostObject(fx, host) | Yes |
| `fx+0x2c = host+0xa4` | Yes |
| `004b9300(0)` | Yes |
| Triple-gated `vtbl+0x210` → maybe `fx+0x230 = 3` | Yes |
| UpdateParamMapTransforms | Yes |

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Role = bind host + refresh FX params | **High** | callees dual-sealed |
| `FailMissionNotify` here = `Vector_PushDword` | **High** | peer dual; not mission fail |
| `modeFlag==0` sets `fx+9` | **High** | decompile |
| `fx+0x2c` context copy from `host+0xa4` | **High** | feeds `004b75d0` gate |
| Multi-vtbl shared entry (not exhaust-only) | **High** | 4 DATA xrefs + code caller |
| Which vector receives push when `modeFlag!=0` | **Partial** | ECX residual |
| Product name for `+0x230` floor | **Tentative** | |
| Full `004b9300` English | **Probable** | spatial setup; not dualed here |

---

## 7. Gaps / open

1. Identify the dword vector object for the `modeFlag!=0` push (assembly ECX).
2. English for `fx+0x230` and the `+0x250/+0x103` quality gate on the `vtbl+0x210` object.
3. Map DATA xref owners (`009ce344` …) to class names.
4. Scaffold clean still `FUN_*`; no Ghidra rename this pass.

**Verdict:** **accept-with-gaps**

# Review A (reconstruction fidelity): `aa_004b2b90` ObjectMotion_ApplyStageParams_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b2b90` |
| **VA** | `0x004b2b90`–`0x004b3253` (1732 B / `0x6C4`) |
| **Canonical name** | `ObjectMotion_ApplyStageParams_Inferred` (structural; product/PDB open) |
| **Ghidra name** | `FUN_004b2b90` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual W27-E) |
| **Counterpart** | `reviews/B_aa_004b2b90_ObjectMotion_ApplyStageParams_Inferred.md` |
| **System** | client object motion / reaction stage params |
| **Verdict** | **accept-with-gaps** — CF + ABI + dirty/continuous dual path sealed; stage field product English open |
| **Dual status** | **Present (first full dual)** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` + callers/callees/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Apply **stage-template parameters** to a motion slot:

- **dirty ≠ 0:** re-sample end-state + flag-gated fields from stage; RNG; snapshot baseline for later lerps.
- **dirty == 0:** progress = `1 − remaining/total`; lerp baseline→end; always integrate `slot[0xb] += slot[9]*dt`.

Called from SlotTick immediately before sealed `ObjectMotion_IntegrateStep_Inferred`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live decompile | full body @ `0x004b2b90` |
| Bounds | `get_function_by_address` → `004b2b90`–`004b3253` |
| Entry/exit bytes | `read_memory` @ `0x004b2b90`, `0x004b3240` |
| Constant | `DAT_00aaa638` ≈ 1/65535; uses `g_flOne` |
| Callers | `FUN_004b4620`, `FUN_005bc120` |
| Peer dual | SlotTick (W26-H) — supplies dirty + dt |
| Raw / annotated / clean | W27-E updated |

**Not performed:** Launcher, runtime golden, bit-exact, dual of `FUN_004b2910` / full stage schema.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body range `004b2b90`–`004b3253` (1732 B) | **Confirmed** | `get_function_by_address` |
| ECX this + **`ret 8`** (`C2 08 00`) | **Confirmed** | epilogue `read_memory` |
| Void (no AL contract) | **Confirmed** | decompile returns |
| dirty / continuous dual path | **Confirmed** | entry `cmp [esp+8],0` |
| progress = 1 − rem/total | **Confirmed** | `g_flOne - [0x5c]/[0x5d]` |
| Always rate*dt on continuous path | **Confirmed** | terminal `slot[0xb]+=…` |
| 0x1D dword end-state copy + baseline snapshot | **Confirmed** | for loops |
| Product field English | **Open** | bitmasks only |
| Runtime / differential | **Open** | |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| dirty≠0: copy stage+0x36c → slot+0x3e (0x1D) | Yes |
| dirty≠0: flag-gated loads from +0x3e0..3e3 | Yes |
| dirty≠0: RNG adjustments + FUN_004b2910 | Yes |
| dirty≠0: optional rate mirror under host+0x8d4 | Yes |
| dirty≠0: snapshot slot+4 → slot+0x21 (0x1D); return | Yes |
| dirty==0: progress formula | Yes |
| dirty==0: flag-gated lerps | Yes |
| dirty==0: always slot[0xb]+=slot[9]*dt; ret 8 | Yes |

---

## 5. Callers

| Caller | Site | Notes |
|---|---|---|
| `FUN_004b4620` | `0x004b48de` | SlotTick: `ApplyStageParams(dirty, dt)` then IntegrateStep |
| `FUN_005bc120` | `0x005bc2ae` | related motion path (unsealed) |

---

## 6. Gaps

1. Retail / PDB symbol.
2. Product English for each stage bitmask field.
3. Dual of `FUN_004b2910` and full stage layout.
4. Runtime golden for dirty reinit vs continuous lerp.

**Verdict:** **accept-with-gaps** — sealed dual-path CF and ABI; field schema product names open.

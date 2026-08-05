# Review A (reconstruction fidelity): `aa_004b1100` ObjectMotion_IntegrateStep_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b1100` |
| **VA** | `0x004b1100`–`0x004b18e5` (2021 B / `0x7E5`) |
| **Canonical name** | `ObjectMotion_IntegrateStep_Inferred` (structural; product/PDB open) |
| **Ghidra name** | `FUN_004b1100` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual W24-C) |
| **Counterpart** | `reviews/B_aa_004b1100_ObjectMotion_IntegrateStep_Inferred.md` |
| **System** | client object motion / reaction entity pose |
| **Verdict** | **accept-with-gaps** — CF skeleton + ABI + constants sealed; nested force helpers residual |
| **Dual status** | **Present (first full dual)** |

**Tools:** Ghidra `decompile_function` + `get_function_by_address` + `read_memory` + callers/callees/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Per-step **motion integrate** for a slot bound to a host object:

- Snapshot position `slot[0x5e..0x60]`.
- **Null path pointer:** nested basis prep (sealed `Math_QuatInverseRotateDelta`), attach-chase or flag-gated force helpers, optional heightfield Y pad.
- **Non-null path:** sample path point by index, optional look-ahead bias (`0.5` / `6.0`).
- Post modes on host`+0x984` (2=unit delta, 4=copy facing).
- Optional host linear velocity * dt.

Evidence: sole consumer of dualed `Math_QuatInverseRotateDelta`; callers `FUN_004b4620` / `FUN_005bc120` feed `(flag, ctx, dt)`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live decompile | full body @ `0x004b1100` |
| Entry/exit bytes | `read_memory` @ `0x004b1100`, `0x004b18c0` |
| Constants | `0x00a0f2a0=1.0`, `0x00a10e74=2.0`, `0x00a0f718≈0.01`, `0x00a0f298=0.5`, `0x00aaa8dc=6.0`, `0x00aaa668=-1.0` |
| Callers | `FUN_004b4620` @ `0x004b48e8`, `FUN_005bc120` @ `0x005bc2ba` |
| Peer dual | `Math_QuatInverseRotateDelta_Inferred` (`aa_004e8590`) |
| Raw / annotated / clean | W24-C updated |

**Not performed:** Launcher, runtime golden, bit-exact, line dual of every force helper.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body range `004b1100`–`004b18e5` | **Confirmed** | `get_function_by_address` |
| ECX this + **`ret 0xC`** | **Confirmed** | epilogue `C2 0C 00` |
| Pos at `+0x178` (`[0x5e]`) | **Confirmed** | entry loads `movss` from `esi+0x178` |
| Path null vs non-null branch | **Confirmed** | decomp |
| Attach chase when `def+0x3e3&8` + host`+0xc` | **Confirmed** | decomp |
| Force bits on `def+0x1e4` | **Confirmed** | decomp |
| Quat factor 2.0 at `0x00a10e74` | **Confirmed** | `read_memory` + W23-O |
| Early abort write `-1.0` to `[0x5c]` | **Confirmed** | `DAT_00aaa668` |
| Product method name | **Inferred** | `_Inferred` |
| Nested force helper English | **Open** | out of owned scope |
| Every float formula bit-exact | **Open** | large body |
| Runtime / differential | **Open** | |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| Snapshot pos | Yes |
| Path-null free integrate | Yes |
| Nested basis prep gate | Yes |
| Attach chase vs force helpers | Yes |
| Heightfield Y pad (`param_2`) | Yes |
| Path-sample branch | Yes |
| Post mode 2 / 4 | Yes |
| Optional host velocity | Yes |
| Epilogue ret 0xC | Yes |

---

## 5. Callers

| Caller | Site | Notes |
|---|---|---|
| `FUN_004b4620` | `0x004b48e8` | after `FUN_004b2b90`; args `(iVar3, local_28, dt)` |
| `FUN_005bc120` | `0x005bc2ba` | spawn loop; args `(param_3, 1, 0)` |

---

## 6. Gaps

1. Retail / PDB symbol.
2. Product class of motion slot (reaction entity? FX particle?).
3. Full dual of force helpers `005c36f0` / `005c4040` / `005c2de0` / `005c2030`.
4. Exact product meaning of host`+0x984` modes beyond CF.
5. Runtime golden.

**Verdict:** **accept-with-gaps** — sealed integrate CF skeleton, ABI, and key constants; nested force helper product names open.

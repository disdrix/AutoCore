# Review A (reconstruction fidelity): `aa_00921f70` Client_SelectHostileUnderScreenPick_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00921f70` |
| **VA** | `0x00921f70`–`0x009221de` (**623** bytes) |
| **Canonical name** | `Client_SelectHostileUnderScreenPick_Inferred` |
| **Prior scaffold** | `FUN_00921f70` |
| **Review date** | `2026-07-29` (W20-Q dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00921f70_Client_SelectHostileUnderScreenPick_Inferred.md` |
| **System** | `interaction-activation` / client target pick |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). No Launcher. Own VA only.

---

## 1. Purpose

**Screen-cursor hostile pick → select:**

1. Gate: `DAT_00d1b6d8` (local char) non-null and `char+0x4f1 == 0` (busy suppress shared with `Client_SelectTargetObject`).
2. Screen ints `DAT_00d1d86c/70` → `GfxView_UnprojectScreenToWorldRay_Inferred` → origin + dir.
3. Height helper `FUN_004cd220(ox, oz)`; ray param `t = (oy - h) / |dirY|`; hit = origin + dir*t.
4. `Math_CopyFloat3ToFloat4`; distance from `DAT_00d17944+0x228..230`.
5. Range = `dist * 0.015f * 25.0f` (= **0.375 * dist**), capped at **40.0f**.
6. Seed null TFID; `Skill_GatherTargetsInArea` with **maxTargets=1**, **mode=2 (hostile)**, filterA=0, filterB=0, filterC=1, scoreArg=-1.0f.
7. If still null TFID → `Client_SelectTargetObject(0)`; else resolve + select. Return **1** on pick path; **0** on gate fail.

**Not** click-pick living interact (mode 3), not drive-control combat look alone, not gather implementation body.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x00921f70` |
| Body range | `get_function_by_address` → `00921f70`–`009221de` |
| Entry/exit bytes | `read_memory` entry 64 B; exit @ `0x009221d0` |
| Constants | `read_memory` `0x00aaacbc`, `0x00aaa6fc`, `0x00a1109c`, `0x00a158b8` |
| Xrefs | sole CODE `0x00922262` |
| Callees | `get_function_callees` / analyze complete |
| Sibling duals | GatherTargets mode table; SelectTargetObject; UnprojectScreenToWorldRay |
| Raw / annotated / clean | `aa_00921f70_*`, `Client_SelectHostileUnderScreenPick_Inferred.cpp` |

**Not performed:** Launcher, runtime pick capture, naming parent UI function at `0x00922223` (undefined in Ghidra).

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 623 B, returns 0/1 bare ret | **Confirmed** | exit bytes `b0 01` / `32 c0` + `c3` |
| Gate char + `+0x4f1` | **Confirmed** | entry bytes + decompile |
| Unproject → hit → gather → select CF | **Confirmed** | live decompile |
| Constants 0.015 / 25 / 40 | **Confirmed** | LE float `read_memory` |
| Mode **2** hostile, maxTargets **1** | **Confirmed** | decompile literals; mode table dual |
| Sole xref `0x00922262` | **Confirmed** | `get_xrefs_to` |
| Product keybind English | **Open** | no string |
| `DAT_00d17944` exact object class | **Probable** | position ref |
| Runtime | **Open** | |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Busy/null gate → 0 | Yes |
| Screen → unproject | Yes |
| Ray-height hit | Yes |
| Distance range *0.015*25 cap 40 | Yes |
| Gather mode 2 max 1 | Yes |
| Null TFID → select(0) else resolve+select | Yes |
| Return 1 on path | Yes |

---

## 5. Gaps / open

1. Product/PDB / input-binding name.
2. Parent function identity at ~`0x00922223` (Ghidra has no function; `ret 8` region).
3. Exact gfxView `this` recovery for unproject (callee dual documents thiscall).
4. Whether gather origin should be hit vs float4 composition product intent.
5. Runtime / bit-exact.

**Verdict:** **accept-with-gaps** — screen hostile pick CF, sealed constants, mode/maxTargets, select/clear arms sealed; product bind name / parent UI function residual open.

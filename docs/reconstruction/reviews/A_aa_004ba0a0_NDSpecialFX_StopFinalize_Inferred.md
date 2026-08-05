# Review A (reconstruction fidelity): `aa_004ba0a0` NDSpecialFX_StopFinalize_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ba0a0` |
| **VA** | `0x004ba0a0`–`0x004ba26d` (461 B / `0x1CD`) |
| **Canonical name** | `NDSpecialFX_StopFinalize_Inferred` (structural; product/PDB open) |
| **Ghidra name** | `FUN_004ba0a0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual W27-D) |
| **Counterpart** | `reviews/B_aa_004ba0a0_NDSpecialFX_StopFinalize_Inferred.md` |
| **System** | client-fx / NDSpecialFX lifecycle |
| **Verdict** | **accept-with-gaps** — CF + ABI + layout family sealed; nested helper English open |
| **Dual status** | **Present (first full dual)** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` + callers/callees/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Manager-facing **stop/finalize** for an NDSpecialFX host:

- Re-entry on host`+8`.
- Type-gated early clear (case 4 via dualed `List1e0_AnyFlag10`; cases 5/6/C–E/14/15 + host`+0xB`).
- Mark `+8=1`; walk lists `+0x1E0/+1EC/+204/+210/+21C`; clear `+0x10`.
- Return **1** default (manager free OK) / **0** early-clear polarity.

Evidence: layout matches dualed HostTick/DeactivateClear/LivenessDone; callers `FUN_005179e0` / `FUN_00514d80` prune managers — not HostTick deactivate path.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live decompile | full body @ `0x004ba0a0` |
| Bounds | `get_function_by_address` → `004ba0a0`–`004ba26d` |
| Entry/exit bytes | `read_memory` @ `0x004ba0a0`, `0x004ba250` |
| Callers | `FUN_005179e0` @ `0x00517a1d`; `FUN_00514d80` @ `0x00514d9a` |
| Peer duals | `NDSpecialFX_List1e0_AnyFlag10`, HostTick, DeactivateClear, LivenessDone |
| Raw / annotated / clean | W27-D updated |

**Not performed:** Launcher, runtime golden, bit-exact, dual of every nested helper.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body range 461 B | **Confirmed** | `get_function_by_address` |
| ECX this + plain `RET` (`C3`) | **Confirmed** | entry/exit `read_memory` |
| Return AL 0 / 1 | **Confirmed** | `B3 01` / `8A C3` paths |
| Case-4 gate `FUN_004b6a80` | **Confirmed** | callees + dual peer |
| List offsets family | **Confirmed** | decomp ≡ HostTick layout |
| Not DeactivateClear | **Confirmed** | different callees/CF |
| Product method name | **Inferred** | `_Inferred` |
| Nested helper English | **Open** | out of OWN |
| Runtime / differential | **Open** | |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| Re-entry `+8` → ret 1 | Yes |
| Type switch + case 4 AnyFlag10 | Yes |
| Early clear `+0xB` path | Yes |
| Sticky `+8=1` | Yes |
| Lists 1e0/1ec/204/210/21c | Yes |
| Clear `+0x10` / return local_8 | Yes |
| Plain ret | Yes |

---

## 5. Callers

| Caller | Site | Notes |
|---|---|---|
| `FUN_005179e0` | `0x00517a1d` | free if `+9==0` && return ≠0 |
| `FUN_00514d80` | `0x00514d9a` | type 0xF batch |

---

## 6. Gaps

1. Retail / PDB symbol.
2. Type-code and host`+0xB` product English.
3. Nested `FUN_004b9af0` / `004b9270` / `005b8340` / `00593e10` duals.
4. Runtime golden for manager free polarity.

**Verdict:** **accept-with-gaps** — sealed outer CF/ABI/layout; nested helpers open.

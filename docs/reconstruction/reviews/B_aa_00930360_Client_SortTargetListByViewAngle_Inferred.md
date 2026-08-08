# Review B (adversarial): `aa_00930360` Client_SortTargetListByViewAngle_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00930360` |
| **VA** | `0x00930360`–`0x00930691` inclusive (**0x332** B) |
| **Canonical name** | `Client_SortTargetListByViewAngle_Inferred` |
| **Ghidra name** | `FUN_00930360` |
| **Review date** | `2026-08-05` (MEGA-023 OWN-ONLY dual seal) |
| **Reviewer role** | Adversarial / claim-falsification (Path B) |
| **Counterpart** | `reviews/A_aa_00930360_Client_SortTargetListByViewAngle_Inferred.md` |
| **System** | skills-abilities / client target selection |
| **Evidence pass** | Same live Ghidra set as Path A (independent claim checks) |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + disassemble_function + read_memory + callers/xrefs. **No** `disassemble_bytes`. **No** Launcher. **No** parent ledgers.

---

## 1. Adversarial charter

Attempt to falsify Path A seals on ABI, role, sort metric, calling convention, and naming. Prefer overclaim rejection over rubber-stamp.

---

## 2. Claims tested

| # | Attack claim | Result | Evidence |
|---|---|---|---|
| 1 | **thiscall** / ECX = client | **Falsified** | Entry loads client from `[EBP+8]`; tail `C2 0C 00` cleans **12** B; caller pushes 3 stack args |
| 2 | **Distance-only** sort (ignore view) | **Falsified** | Explicit forward/right dots; half-plane branch on `rDot`; `DAT_00aaa668=-1` path |
| 3 | Sort by **dist** / distSq not score | **Falsified** | Comparator loads **`[elem+4]`** only; dist lives @+8 / distSq @ construct path |
| 4 | **Descending** “best first” sort | **Falsified as claim** | cmp returns true when `R.score > L.score` ⇒ **ascending** by score. Product “best” English open; do not re-label as descending |
| 5 | **Multiple callers** / shared util | **Falsified** | Single xref: `FUN_00943340` @ `0x00943440` UNCONDITIONAL_CALL |
| 6 | **Selection apply** / sets `client+0x3048` | **Falsified** | No store to `+0x3048`; only rewrites TFID array + count; apply is caller’s `FUN_0093e120` |
| 7 | **Gather** targets itself | **Falsified** | No `Skill_GatherTargetsInArea`; operates on pre-filled list |
| 8 | `operator_delete` **noreturn** (decomp warning) | **Falsified** | Asm falls through `0x0093066f` SEH teardown → `RET 0xC` |
| 9 | Scaffold name is product plate | **Falsified** | `Named_CalleeOf_…PollBoundActions…` is chain auto-name; no string/RTTI at VA |
| 10 | **Forward** extract is right / swap axes | **Falsified** | Call order: `004e8a40` then `004e8ad0`; dualed right is `004e8ad0` (`Quat_ExtractRight_Inferred`); forward sibling `004e8a40` closed form matches +Z |
| 11 | Element stride **not** 0x10 | **Falsified** | All `SAR …,4` / `ADD ESI,0x10` / InsertN dualed 0x10 |
| 12 | `RET 4` or cdecl caller-clean | **Falsified** | `C2 0C 00` only |
| 13 | Invent retail name without `_Inferred` | **Rejected** | No PDB/string; Path A correctly keeps `_Inferred` |
| 14 | Zero-distance score is **0** or **1** | **Falsified** | Loads `0x00a10e74` = **2.0f** when `dist <= 0` |

---

## 3. Residual risks (not falsifications)

| Risk | Severity | Notes |
|---|---|---|
| Product method English | Low | `_Inferred` retained |
| Ascending order UX intent | Medium | Bytes sealed; “prefer right-forward first” is interpretation only |
| Virtual `+0x144` side effects | Low | Called; body not re-owned this pass |
| `FUN_00409e20` exact construct fields | Low | Size/end bump sealed; 4th dword exactness Probable |
| Decompiler component alias order | Low | Clean uses asm X/Y/Z @ 0x80/84/88; decomp int indices match |
| Runtime golden | Open | Terminal **false** by charter |

---

## 4. ABI / CF cross-check

| Check | Path A claim | B result |
|---|---|---|
| Body span 0x332 B | yes | **Confirm** — RET ends `0x00930691`; pad `CC` |
| Sole caller cycle hostile | yes | **Confirm** — dualed parent WQ9R-C |
| Score half-plane formula | yes | **Confirm** — asm `COMISS` / `MULSS DAT_00aaa668` / `ADDSS` paths |
| Sort ascending score@+4 | yes | **Confirm** — comparator bytes |
| Clean ≡ raw ≡ live CF | yes | **Confirm** — no invented branches |

---

## 5. Naming

| Candidate | B ruling |
|---|---|
| `FUN_00930360` | Ghidra default — keep as twin id |
| `Named_CalleeOf_…PollBoundActions…` | **Retire** — non-product scaffold |
| `Client_SortTargetListByViewAngle_Inferred` | **Accept** as canonical — role matches CF; `_Inferred` required |
| Bare `Client_SortTargetListByViewAngle` (no suffix) | **Reject** — overclaims product plate |

---

## 6. Verdict

**accept-with-gaps** — adversarial pass **failed to break** ABI, CF, score geometry, sort key, sole-caller, or void/RET0xC seals. Gaps limited to product English, nested leaf duals, and runtime. Aligns with Path A.

Runtime Confirmed: **not claimed**.

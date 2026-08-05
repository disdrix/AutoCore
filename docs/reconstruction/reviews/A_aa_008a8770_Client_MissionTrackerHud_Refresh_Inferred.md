# Review A (reconstruction fidelity): `aa_008a8770` Client_MissionTrackerHud_Refresh_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008a8770` |
| **VA** | `0x008a8770`–`0x008a9618` |
| **Canonical name** | `Client_MissionTrackerHud_Refresh_Inferred` |
| **Ghidra name** | `FUN_008a8770` |
| **Review date** | `2026-07-29` (W20-F OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_008a8770_Client_MissionTrackerHud_Refresh_Inferred.md` |
| **System** | `missions-progression` / mission-tracker HUD chrome |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` entry/tail + float/string constants. No `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Mission-tracker **HUD refresh**: with UI host in **ECX**, recompute objective title, instruction text, icon materials, and optional range/minimap captions into host widgets. **Chrome only** — no C2S builders.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live decompile | `decompile_function` `0x008a8770` — **identical** to raw body |
| Function meta | body `008a8770`–`008a9618` (3752 B) |
| Entry bytes | `read_memory` @ `0x008a8770` — SEH prolog; `mov esi,ecx`; gates on `DAT_00d1b6d8` / `+0x4f1` |
| Epilogue region | `read_memory` @ `0x008a9600` — `5B 8B E5 5D C3` |
| DATA xref | `0x00a4b55c` → `0x008a8770` |
| Distance constants | `0x00aaa670`=1200f, `0x00a0f520`=1000f, imperial scales, `">1.20km"` / `">0.75 mi"` strings |
| Raw / annotated / clean | `raw/aa_008a8770_*`, `Client_MissionTrackerHud_Refresh_Inferred.cpp` |
| Peer duals | `CVOGCharacter_IsMissionTurnInReady`, `Client_EvalAutoPatrolWaypoint`, `TFID_EqualsObjectId` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body `0x008a8770`–`0x008a9618` (3752 B) | **Confirmed** | Ghidra meta + epilogue `C3` |
| ABI: host in **ECX**; **no stack args**; `ret` | **Confirmed** | entry `8B F1`; epilogue `C3` |
| Early outs: no client; `client+0x4f1`; missing widgets `[0x1a2]/[0x1a5]/[0x1a4]` | **Confirmed** | entry bytes + decomp (byte offs **0x688 / 0x694 / 0x690**) |
| Title strings `"No Objective"` / `"Next mission"` | **Confirmed** | decomp literals |
| Instruction strings inventory / journal / `"Go to"` | **Confirmed** | decomp + prior `FUN_005710c0` framing |
| Minimap hints Gold / Blue Dots | **Confirmed** | decomp |
| Distance metric/imperial bands + overflow captions | **High** | decomp + `read_memory` constants/strings |
| Tracker state `DAT_00d1ad10` (+4 dirty, +7 mode, +8 flag, +9 next, +0x10 key) | **High** | uses across body |
| Mission hash `client+0x548` via `CNDHash_LookupByKey` | **High** | |
| No sector packet send in this unit | **High** | callees are hash/UI/math/string only |
| Product host class / method English | **Inferred** | `_Inferred` required |
| Sole name from inventory string | **Rejected** | multi-arm chrome; B seals attack |

---

## 4. Control flow: raw ≡ live ≡ clean

| Stage | Match |
|---|---|
| Triple widget + client gates | **Yes** |
| Title arm (key 0 / lookup fail / no objective / next mission / types 3+6 / contact) | **Yes** |
| Common title layout + host `vtbl+0x450` | **Yes** |
| Instruction arm `FUN_0092c810()<1` | **Yes** |
| Range arm waypoint + distance + materials | **Yes** |
| SEH teardown | **Yes** |
| No invented net opcodes | **Yes** |

---

## 5. Naming gate

| Evidence | Present? |
|---|---|
| Multi-arm tracker chrome (title/instruction/range) | **Yes** |
| Tracker global + mission hash | **Yes** |
| Product class/method | **No** |
| Single-string product name covers whole body? | **No** |

**Decision:** promote **`Client_MissionTrackerHud_Refresh_Inferred`** (role High; method English open → `_Inferred`). Keep inventory string as **branch evidence only**.

---

## 6. Gaps

1. Product name of host class and method.
2. Full semantics of `FUN_0092c810` range-mode predicate.
3. Product English for objective vtbl type codes 3 / 6 / 0xc.
4. Invoker that stores this pointer at DATA `0x00a4b55c` (vtable owner).
5. Runtime / bit-exact / differential — open.

**Verdict:** **accept-with-gaps**

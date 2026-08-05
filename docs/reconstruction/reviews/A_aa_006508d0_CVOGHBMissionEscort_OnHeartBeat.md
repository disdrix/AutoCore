# Review A (reconstruction fidelity): `aa_006508d0` CVOGHBMissionEscort_OnHeartBeat

| Field | Value |
|---|---|
| **Stable ID** | `aa_006508d0` |
| **VA** | `0x006508d0` |
| **Canonical name** | `CVOGHBMissionEscort_OnHeartBeat` |
| **Review date** | `2026-08-04` (WQ7R-H dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_006508d0_CVOGHBMissionEscort_OnHeartBeat.md` |
| **System** | missions-progression / heartbeat |
| **Scratch** | `tmp/a_006508d0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Escort mission **OnHeartBeat** (`CVOGHBBase` `vtable+0x0C`): resolve/track escort target; **FailMission** + end-quest drain if lost; **CompleteObjective(force=1)** if complete-zone proximity met; else **RescheduleAfterFire**.

WQ-007 residual: **caller of `CVOGReaction_CompleteObjective`** (and FailMission).

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | Ghidra HTTP `decompile_function(0x006508d0)` 2026-08-04 |
| Entry/exit image | `read_memory` → `ret 4`; `*out = DAT_00af514c` (16) |
| Vtable | `read_memory` `0x009e52c0`… — methods: dtor `00650d00`, Stamp `00508270`, TryFire `005082c0`, **this `006508d0`**, … |
| RTTI | COL `0x00ab1e9c` → TD `0x00af4a10` `.?AVCVOGHBMissionEscort@@` |
| Ctor | `FUN_006507c0` sets `*this = &PTR_FUN_009e52c4` |
| TryFire dual | `A_aa_005082c0` documents OnHeartBeat @`vtable+0x0C` |
| FailMission dual | drain YES for this caller @`0x00650c62` |
| Raw / clean / record | `raw/`, `reconstructed-exact/`, `functions/aa_006508d0_*` |

**Not performed:** `disassemble_bytes`; Launcher.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Class `CVOGHBMissionEscort` | **High** | RTTI TD string |
| OnHeartBeat role (`vtable+0x0C`) | **High** | vtable layout + TryFire dual |
| No static CALL; DATA vtable bind | **High** | xrefs |
| Character cast + hash `+0x548` lookup | **High** | decomp |
| FailMission + `FUN_005307e0` drain | **High** | decomp + prior dual table |
| CompleteObjective(key, −1, −1, 1) | **High** | decomp |
| Reschedule when not complete | **High** | decomp |
| `*out = 16` Remove family | **High** | `DAT_00af514c` image + TryFire dual |
| Distance / complete-zone field English | **Probable** | float SQRT compares |
| Not `CVOGHBOutpost` | **High** | different RTTI; adjacent string is red herring |
| Runtime / bit-exact | **Open** | |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Cast / lookup / TFID resolve | **Yes** |
| Lost → fail + drain + destroy | **Yes** |
| !complete → reschedule | **Yes** |
| complete → CompleteObjective | **Yes** |
| Terminal *out=16 | **Yes** |

---

## 5. Gaps

1. Product names for max-range and complete-zone dual object fields on HB instance.
2. Interaction with mid-chain vs final objective CompleteObjective force=1.
3. Runtime escort distance capture.

**Verdict:** **accept-with-gaps** — identity + Complete/Fail arms sealed; field English residual.

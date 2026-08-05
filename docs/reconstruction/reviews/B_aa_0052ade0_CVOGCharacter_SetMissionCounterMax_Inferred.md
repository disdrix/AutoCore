# Review B (skeptical / adversarial): `aa_0052ade0` CVOGCharacter_SetMissionCounterMax_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052ade0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY W37-P) |
| **Counterpart** | `reviews/A_aa_0052ade0_CVOGCharacter_SetMissionCounterMax_Inferred.md` |
| **Scratch** | `tmp/a_0052ade0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is SetMissionCounter (`005305b0`) | **Falsified** — writes **+0x10** not **+0x14**; miss does **not** insert |
| 2 | This is AddMissionCounter (`00530610`) | **Falsified** — no `ADD`; **ret 8** not **ret 0xC** |
| 3 | This is GetResourceBalance (`0052ada0`) | **Falsified** — writes; void; dirty |
| 4 | Miss inserts like Set | **Falsified** — `JE` to epilog; no `0053af20` |
| 5 | Clamp is max(value, +0x14) | **Falsified** — if +0x14 < value then store +0x14 → result is **min(value, +0x14)** |
| 6 | Dirty bit is 0x10 (FailMission family) | **Falsified** — imm **0x40** |
| 7 | Free function / stdcall | **Falsified** — `MOV ESI,ECX`; thiscall |
| 8 | Name "Max" is PDB-proven | **Overstated** — slash-help **inferred** only |
| 9 | Core mission path (not debug) | **Weak** — sole xref is debug slash; mission-**adjacent** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Hit-only +0x10 set + clamp | **High** | Wrong counter UI / rewards |
| ret 8 thiscall | **High** | ABI break |
| Dirty 0x40 | **High** | Missed sync |
| "Max" English | **Medium** | Naming |
| Production callers | **Low** | May be debug-only |
| Runtime | **Open** | Matrix |

---

## 3. Cross-check against raw + bytes

```
PUSH ECX; PUSH ESI; MOV ESI,ECX
LEA map, [ESI+0x584]
CALL lower_bound → node
CMP node, [ESI+0x588]; JE done
MOV [node+0x10], value
IF [node+0x14] < value: [node+0x10] = [node+0x14]
OR [ESI+0x634], 0x40
POP ESI; POP ECX; RET 8
```

Live 2026-08-04 ≡ raw 2026-07-23 CF. Caller W31-T optional flag path after SetMissionCounter.

---

## 4. Surviving contract for AutoCore

```
// Hit-only max/field10 set (does NOT create keys):
CVOGCharacter_SetMissionCounterMax(character, key, value);
// Preserve: map +0x584 / head +0x588; clamp to +0x14; dirty |= 0x40; ret 8.
// Do not use for absolute current set (+0x14) — that is SetMissionCounter.
// Do not assume miss inserts. Debug-only caller today; still seal for map field policy.
```

---

## 5. Verdict

Adversarial pass **confirms** A: distinct from Set/Add/Get, ABI, clamp, dirty sealed; max English + production callers open → **accept-with-gaps**.

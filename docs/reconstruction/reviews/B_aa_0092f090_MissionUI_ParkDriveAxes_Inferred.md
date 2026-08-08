# Review B (skeptical / adversarial): `aa_0092f090` MissionUI_ParkDriveAxes_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092f090` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY MEGA-021) |
| **Counterpart** | `reviews/A_aa_0092f090_MissionUI_ParkDriveAxes_Inferred.md` |
| **System** | `input-drive-control` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | ECX-thiscall on the park helper | **Falsified** — body reads **ESI+0xe98**; all 5 sites `MOV ESI,EBP`; no ECX seed for this unit |
| 2 | Stack formals / `RET 4` | **Falsified** — bare `C3`; no pushes of formals for self |
| 3 | `unaff_ESI` is phantom / unused garbage | **Falsified** — first insn `MOV EAX,[ESI+0xe98]`; call sites seed ESI |
| 4 | Only thr is parked (steer/HB invent) | **Falsified** — three CALLs: long, steer, HB with immediates 0/0/1 |
| 5 | Clears handbrake (HB=0) | **Falsified** — `PUSH 1` before SetHandbrake |
| 6 | Calls `PushDriveAxes` / applies controller | **Falsified** — only three setter VAs; no `0x004fbc10` |
| 7 | Direct stores to `+0x614`/`+0x618`/`+0x61c` | **Falsified** — stores are inside dualed setters |
| 8 | Exclusive callee of ShowNpcMissionDialogUI | **Falsified** — 3 additional sites in `FUN_0093e450` |
| 9 | Scaffold name is product role | **Falsified** — parent-seed only; misses second parent + park semantics |
| 10 | Always parks (no gate) | **Falsified** — dual null checks on char + vehicle |
| 11 | Thr/steer writes always succeed | **Falsified (nuance)** — setters have 0xC7 gate; HB is ungated — thr/steer may retain prior under suppress while HB still sets 1 |
| 12 | Vehicle cached once in ECX across three calls | **Falsified** — each call reloads from ESI chain |
| 13 | Product demangle known (no `_Inferred`) | **Falsified** — no strings/RTTI in body; `_Inferred` required |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ABI ESI-host / bare RET | **High** | Wrong call convention → crash / no park |
| Offsets +0xe98 / +0x250 | **High** | Wrong object → park nothing or wrong entity |
| thr0 / steer0 / HB1 constants | **High** | Wrong park posture |
| Callee VAs dualed | **High** | Wrong setter ports |
| 5 call sites / 2 parents | **High** | Missed dialog park path |
| No PushDriveAxes here | **High** | Over-claim controller apply |
| Product host class English | **Low** | Naming only |
| FUN_0093e450 English | **Low** | Parent residual |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

| Check | Result |
|---|---|
| Live decompile 2026-08-05 ≡ raw 2026-07-23 CF | **Match** |
| Body size 66 B to RET | **Match** (`0x0092f090`–`0x0092f0d1`) |
| Hex vs disasm mnemonics | **Match** |
| Callers seed ESI from EBP | **Match** (all 5 sites) |
| Rel32 → `004f5650` / `004f5620` / `004f3620` | **Match** |
| ShowNpcMissionDialogUI ends with park then epilogue | **Match** (`CALL` then `POP*` / `RET 0xc`) |
| FUN_0093e450 case 0/1 paths park | **Match** (3 sites before return) |

---

## 4. Surviving contract for AutoCore

```
// Before / while mission-NPC dialog UI holds the player:
//   ESI = clientHost;   // EBP in callers
//   MissionUI_ParkDriveAxes_Inferred();
// Effect when character* and vehicle* present:
//   SetLongitudinalInput(vehicle, 0)
//   SetSteerInput(vehicle, 0)
//   SetHandbrake(vehicle, 1)
// Does NOT push controller axes.
// Does NOT clear handbrake.
// Do NOT model as ECX-thiscall or stack-arg RET 4.
// Note: thr/steer may be suppressed by 0xC7 gate inside setters; HB is ungated.
```

---

## 5. Verdict

Adversarial attacks on ECX-thiscall / thr-only / HB-clear / PushDriveAxes / single-parent / always-park / scaffold-product claims **fail**. Residual product English + runtime only → **accept-with-gaps**. Terminal **false**.

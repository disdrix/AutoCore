# Review B (skeptical / adversarial): `aa_0052da30` CVOGReaction_FailMission

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052da30` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (dual residual body strengthen, pass 2) |
| **Counterpart** | `reviews/A_aa_0052da30_CVOGReaction_FailMission.md` |
| **Chain** | `reviews/CHAIN_2026-07-29_abandon_failmission.md` |
| **Scratch** | `tmp/a_0052da30.md` |
| **Scope** | **Body only** — attacks on Recv dual are out of scope except as one caller |
| **Verdict** | **accept-with-gaps** — thin kernel + Notify push + xref/drain table sealed; lifecycle / dirty readers / orphan hosts / runtime open |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Fail removes mission from active hash here | Body has no hash remove/destroy — only notify push + flag | **Falsified** |
| 2 | Abandon UI calls FailMission directly | Confirm path only `Client_SendSectorPacket(0x20B2)`; this unit is S2C/reaction apply | **Falsified as direct caller** |
| 3 | Any `missionId` fails | Must be **active** with **live** node (`node+8`) | **Overstated** |
| 4 | Flag `0x10` means “failed” exclusively | Same dirty bit set by AddActiveObjective path | **Falsified as exclusive** |
| 5 | `FailMissionNotify` is UI-only / full teardown | Callee is a **vector push** (`aa_004149d0`); multi-caller generic helper | **Falsified as teardown** |
| 6 | Notify `this` unknown / only Probable | Asm `LEA ECX,[ESI+0x560]` + image bytes | **Sealed High** |
| 7 | Symmetric to GiveMission teardown | GiveMission inserts active node; Fail is thin apply + enqueue | **Attacked — asymmetric** |
| 8 | Clean implies full fail UX (“Failed …” toast) | Toast/string work is in `FUN_005307e0` after some callers, not here | **Falsified for this unit** |
| 9 | Every caller drains notify list | Only **3/11** sites drain (`0080b111`, `00650c62`, `00886402`) | **Falsified** |
| 10 | Local optimistic abandon fail without S2C | Confirm case has no FailMission call | **Falsified** (static) |
| 11 | Only five callers | `get_xrefs_to` lists **11** CALL sites; 5 orphan outside named functions | **Prior table incomplete — corrected** |
| 12 | `FUN_0060e800` single call | Two sites (`0060e82f`, `0060e9c3`); both no-drain; both clear AL on return | **Corrected** |
| 13 | Orphan `00886402` is non-draining like other orphans | Next instruction CALL → `FUN_005307e0` with `ECX=DAT_00d1b6d8` | **Falsified (it drains)** |
| 14 | Body return is full EAX bool | Image `MOV AL,1` / `XOR AL,AL` only; some callers mask with `& 0xffffff00` | **AL-only sealed; caller masking documented** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Lookup + live-node gates | **High** | Silent no-op fail |
| Side effects inside unit (log, push, `\|0x10`) | **High** | Incomplete dirty state |
| Notify `ECX = char+0x560` | **High** | Wrong vector → lost fail ids |
| Notify body = push only | **High** | Over-implement teardown in kernel |
| Active hash erase in this unit | **None** (does not happen) | AutoCore must not erase here only |
| Drain on every caller | **None** (not true) | Stuck active mission after local fail |
| 11-site xref inventory | **High** (static) | Missed AutoCore call paths |
| Orphan site framing | **High** for bytes; **Tentative** product role | Mis-map missionId source |
| Full fail lifecycle from this VA alone | **Tentative** | Client stuck with active mission |
| Dirty bit English | **Probable** | Wrong journal refresh semantics |
| Logger COID layout | **High** (offsets) / **Probable** (product) | Bad logs only |
| Abandon end-to-end ownership | **N/A here** | Chain units `00911840` / `0080b100` |

---

## 3. Cross-check against raw / live decompile / image

Entire body is ~0x8A bytes / ~30 decompiler lines. Clean is a 1:1 scaffold. Surviving facts after attack:

- Lookup miss / dead node → `0` (`XOR AL,AL` / `RET 4`)
- Success → log, push id to `char+0x560` vector, `*(char+0x634)|=0x10`, `1` (`MOV AL,1` / `RET 4`)
- **No** packet send, **no** modal close, **no** hash erase
- Live Ghidra 2026-07-29 pass 2: no CF drift; Notify register sealed; **11** xrefs catalogued

### Surviving drain contract

```
Drain YES:  0080b111 (Recv), 00650c62 (HB), 00886402 (orphan / DAT_00d1b6d8 path)
Drain NO:   Patrol, Kill_Precheck, 0060e800×2, orphans 0060caa2/0060ec36/00612970/0057f44c
```

---

## 4. Surviving contract for AutoCore

```
FailMission(char, missionId) -> 0|1   // AL only; RET 4
  node = activeHash(char+0x540).find(missionId)
  if !node || !node.live(+8): return 0
  log("Player %I64d failed mission %d", coid, missionId)
  vector_push_u32(char+0x560, missionId)   // NOT full teardown
  char.flags(+0x634) |= 0x10
  return 1

DO NOT implement in this unit:
  - active hash erase
  - completed-hash insert
  - cargo strip
  - C2S/S2C 0x20B2 I/O
  - abandon modal handling
  - "Failed" toast / gen_end_quest audio

CALLER may:
  - invoke FUN_005307e0 to drain +0x564 list (Recv, HB 006508d0, orphan 00886402)
  - or leave id queued (majority of reaction/req sites)
```

MissionId construction is **caller-owned**. Common reaction pattern:

```
missionId = **(*(requirementOrHb + 4) + 0x14c)
```

Do not assume every caller passes a raw constant mission id.

---

## 5. Contradictions / doc debt

| Source | Statement | This review |
|---|---|---|
| Prior dual “5 callers” | Incomplete | **11 CALL sites**; 5 named + 5 orphan + multi-site `0060e800` |
| Prior “who always drains after non-S2C” | Open | **Answered:** not always; only HB + one orphan drain besides Recv |
| Name `CVOGReaction_FailMissionNotify` | Implies fail-only | Multi-xref generic push; fail site still correct role |
| `docs/missionState.md` product gaps | Server wiring | Do not conflate with client kernel |
| Orphan code gaps in Ghidra | Undefined functions | Documented by site VA; host dual deferred |

---

## 6. Open questions

1. Readers of `char+0x634` bit `0x10` (serialize / UI tick).
2. When deferred (no drain) fail ids are processed later.
3. Recover / dual orphan hosts (`0060caa2`, `0060ec36`, `00612970`, `00886402`, `0057f44c`).
4. Runtime abandon observation (CE/packet).

**Verdict:** Thin fail apply + Notify push + static xref/drain contract sealed; **do not** treat this VA as abandon end-to-end or full teardown. Lifecycle completeness remains **accept-with-gaps**.

# Review A (reconstruction fidelity): `aa_0093ffb0` Client_ProcessWorldCombatFloaters_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0093ffb0` |
| **VA** | `0x0093ffb0` |
| **Canonical name** | `Client_ProcessWorldCombatFloaters_Inferred` |
| **Prior names** | `FUN_0093ffb0`, `Named_CalleeOf_Named_VOGClient_0093ffb0` |
| **Review date** | `2026-07-29` (dual A/B — OWN-ONLY) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_0093ffb0_Client_ProcessWorldCombatFloaters_Inferred.md` |
| **System** | combat UI floaters / client world feedback |
| **Dual status** | **Present** (first dual pair) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Drain a **pending combat-event range** on the client world host and spawn **world-space combat floaters** (damage numbers, Deflect/Resist text, heal/XP-style labels) when in range:

```text
// param_1 = Client* (stack)
char = client+0xe98
if !char || !char+0x250: return

// sample local position via embedded phys vtbl+0x1a0 + FUN_004e88e0
range = [*(client+0xe04)+0xe8a8 , +0xe8ac)   // pending event structs

for each event in range:
  target = CVOGReaction_ResolveObjectTarget(event+…)
  if !target: continue
  type = target.clonebase+0x38
  if type not in {0xe, 0x12, 0x14}: continue

  // world pos (special path when event.kind==4 uses local char pos)
  if distance(event_pos, local_pos) > DAT_00aaa9f0 /* 60.0f */: continue

  // kind==3: first-time tip gates + XP threshold half-band
  // build floater object (0x60 bytes): colors, text, motion seeds
  sprintf("%d") amount; optional locale FUN_007a6de0
  switch (event.kind = event[0xc]):
    case 0: damage / miss colors; "Deflect"/"Resist"/crit-ish strings; TFID self/other tint
    case 1: green-ish + locale suffix
    case 2: signed amount (+/-) colors
    case 3: tip/XP style colors + upward motion scale
    case 4: pale label path + optional audio/UI hooks
  // attach into client floater list client+0xaac with overlap separation
  // optional first-time tips, target select FUN_0093e120, UI panel hooks
```

Related infrastructure: `Client_EnqueueCombatFloater_INFERRED` (`0x00402620`) is the **0x38-byte queue** helper; this unit is the **world-event → rich floater** producer (larger 0x60 widget path).

---

## 2. Calling convention

| Slot | Role | Evidence |
|------|------|----------|
| Stack | `Client*` | Callers `PUSH EDI/EBX`; prologue `mov ebx, [esp+…]` |
| Return | `void` | |
| SEH | `LAB_009bb2c1` | |

Live prologue:

```text
0093ffb0  push -1
0093ffb2  mov  eax, fs:[0]
…
0093ffc4  sub  esp, 0xa0
0093ffca  push ebx
0093ffcb  mov  ebx, [esp+0xb4]   ; client*
```

---

## 3. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean / record | `aa_0093ffb0_*` |
| Live decompile | Ghidra `batch_decompile` `0x0093ffb0` (~700 lines) |
| Live bytes | `read_memory` `0x0093ffb0` length 32 |
| Constant | `read_memory` `0x00aaa9f0` → `00 00 70 42` = **60.0f** |
| Callers | `FUN_00940ed0` @ `0x00940f2d`, `FUN_009440e0` @ `0x00944214` |
| Named callees | `CVOGReaction_ResolveObjectTarget`, `TFID_EqualsObjectId`, `Client_MaybeShowFirstTimeTip`, `Experience_GetCumulativeThreshold`, `FUN_004e88e0`, `FUN_0093e120` |

**Not performed:** full case-by-case product string dump beyond Deflect/Resist; runtime.

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Require local char + `char+0x250` | **Yes** |
| Iterate world pending `[+0xe8a8,+0xe8ac)` | **Yes** |
| Type gate `0xe / 0x12 / 0x14` | **Yes** |
| Distance gate **60.0f** (`DAT_00aaa9f0`) | **Yes** |
| `switch(event[0xc])` cases **0..4** | **Yes** |
| Floater alloc ~`0x60` + string buffer | **Yes** |
| TFID self/other color branches | **Yes** |
| Overlap adjust on list `client+0xaac` | **Yes** |
| Optional tips / select / panel hooks | **Yes** |

### Key constants / offsets

| Item | Role |
|------|------|
| `DAT_00aaa9f0` | **60.0f** max distance |
| world `+0xe8a8/+0xe8ac` | pending combat event range |
| client `+0xe98` | local character |
| client `+0xaac` | active floater list head |
| event `[0xc]` | floater kind 0..4 |
| event amount field used in `sprintf("%d")` | numeric label |
| strings | `"Deflect"`, `"Resist"`, numeric / locale tails |

---

## 5. Naming / gaps

| Claim | Confidence |
|---|---|
| Role = process pending world combat floaters | **High** |
| Distance 60.0 | **High** (bytes) |
| Kind switch 0..4 | **High** |
| Product names per kind | **Tentative** |
| Relation vs 0x38 enqueue helper | **Probable** (parallel pipeline) |
| Runtime | **Open** |

---

## 6. Verdict

**accept-with-gaps** — gate/switch/distance sealed from live decompile + `read_memory`. Kind English residual; large body not line-audited for every side path.

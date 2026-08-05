# Annotated low-level: CVOGReaction_GiveMission (`aa_005327c0`)

| Field | Value |
|---|---|
| **Stable ID** | `aa_005327c0` |
| **VA** | `0x005327c0` |
| **Module** | `autoassault.exe` @ image base `0x400000` |
| **System** | missions-progression |
| **Source raw** | `aa_005327c0_CVOGReaction_GiveMission.md` (capture 2026-07-23) |

This file is the **annotated** layer: widths, signedness, branch order, side effects, and decompiler corrections. It does not replace the immutable raw capture.

---

## 1. Corrected signature

```c
// MSVC thiscall: ECX = character
uint32_t /* 0 fail / 1 granted */ __thiscall
CVOGReaction_GiveMission(CVOGCharacter* this, uint32_t missionId);
```

| Name | Width | Signedness | Origin | Role |
|---|---|---|---|---|
| `this` / `param_1` | 32-bit pointer | unsigned | `ECX` | Character |
| `missionId` / `param_2` | **u32** | unsigned | stack | Mission to grant |
| return | **u32** 0/1 | unsigned | `EAX` | 1 = grant path taken; 0 = refused / missing def |

---

## 2. Decompiler corrections

| Decompiler artifact | Correction | Confidence |
|---|---|---|
| `void *param_1` | **CVOGCharacter*** | **High** |
| `FUN_0053fff0` | Mission definition hash root | **Probable** |
| `puVar3 + 0x4c` as `char` | **Byte `def+0x130` objective count** (asm `CMP …,1` / `JC`); grant requires ≥1 — **not** a separate awardable bit | **High** (2026-07-29 residual) |
| `puVar3 + 0x5a` / `FUN_00547920(1|0)` | **ECX=def**; second call if `byte def+0x168==0`; body = **XML ensure-load** | **High** role; stack 0/1 nuance Tentative |
| `FUN_0053c360(id,def,0)` free form | **thiscall** insert: ECX=`char+0x540` then optional ECX=`**char+0x544**` | **High** |
| `FUN_0053c660` free form | **thiscall** insert: ECX=`**char+0x530**`, key=`*def`, payload=0x30 blob | **High** |
| `FUN_00538b20` | **CNDHash_Remove** on ECX=`char+0x538` | **High** |
| `FUN_00538a40` | lower_bound; ECX=`LEA char+0x508` | **High** |
| `this+0x540` / `+0x538` / `+0x53c` / `+0x548` | Active / completed / instance-completed / active objectives | **High** |
| `puVar3[0x4f]` | `def+0x13c` first objective list pointer | **High** |
| objective `+0x120` | Continent object unlock id for `UnlockContinentObject` | **Probable** |
| `short at dword-idx 0x2b / 0x3e` | Byte offs **`+0xAC`** (repeatable iff `-1`) / **`+0xF8`** (toast when 0) | **High** as gates |
| dword-idx `0x40` | Byte **`def+0x100`** (secondary insert OR arm vs `-1`) | **High** as gate |
| Toast / audio | UI only when `word def+0xF8 == 0` | **High** |
| AddActiveObjective 1-arg in raw | **2-arg** `__thiscall(char, objDef)` — asm `MOV ECX,EBP; PUSH obj; CALL` | **High** |
| `WeaponAllowsKillXpBonus()` no-arg | **this** = object at entity chain `char → +4 → +4 → +0xa8` | **High** framing |

**Critical typing note:** Ghidra often types mission def as `undefined4*`, so `puVar3 + N` means **byte offset `N*4`**. Prefer **byte offsets** (residual sealed 2026-07-29).

---

## 3. Character hash field map

| Offset | Width | Role |
|---|---|---|
| `this+0x538` | ptr | Completed (permanent) |
| `this+0x53c` | ptr | Completed (instance) |
| `this+0x540` | ptr | Active missions |
| `this+0x544` | ptr | **Paired active-mission hash** (second `FUN_0053c360`; residual 2026-07-29) |
| `this+0x548` | ptr | Active objectives |
| `this+0x530` | ptr | Mission **state-blob** hash (`FUN_0053c660` insert) |
| `this+0x508` / `+0x50c` | tree / sentinel | Prior-state tree (`FUN_00538a40` this=`+0x508`; sentinel `+0x50c`) |

---

## 4. Control flow (high level)

```text
def = Lookup(missionDefHash, missionId)
if !def or !def.enabled: return 0

FUN_00547920(1); maybe FUN_00547920(0)

if already active (Lookup this+0x540): return 0 (outer structure — actually outer fails earlier)

// completed guards when def.specialShort != -1:
//   if !mode && in +0x538: return 0
//   if  mode && in +0x53c: return 0

// first objective:
if not already in +0x548: AddActiveObjective(firstObj)
else: log "Already had objective"

UnlockContinentObject(this, firstObj+0x120)

if not in +0x540:
  FUN_0053c360 insert mission...
  optional second insert under mode flag
  optional FUN_00538b20 if special short == -1 and was completed
  allocate 0x30 state blob, copy from prior if any
  FUN_0053c660 / FUN_0052d8b0
  if toast path: "Received Mission" UI + gen_give_quest sound
  return 1
else:
  log "Already had mission"
  return 1
return 0
```

| Branch | Result |
|---|---|
| Missing/disabled def | `0` |
| Already completed (guard) | `0` |
| Grant / already-had mission after partial work | `1` |

Control-flow confidence: **Probable** (large; Ghidra nesting + `undefined4*` indexing).

---

## 5. Side-effect order (success grant)

1. Lookup def; optional UI prep `FUN_00547920`.
2. Completed-set guards (read hashes).
3. `CVOGMission_AddActiveObjective` for first objective if needed.
4. `CVOGReaction_UnlockContinentObject`.
5. Insert active mission (`FUN_0053c360` / `FUN_0053c660`), optional state blob `0x30`.
6. `FUN_0052d8b0` (mission-related notify/list).
7. Optional toast + `Client_PlayNamedInterfaceSound("gen_give_quest", ...)`.

Does **not** open volume gates by itself (plate); map triggers re-eval type-11 conditions afterward.

---

## 6. Open questions

- Re-derive **byte** offsets for all `puVar3 + N` fields (dword-pointer trap).
- Difference between `FUN_0053c360` vs `FUN_0053c660` inserts.
- When toast path is skipped (`short +0x3e != 0`).
- Server mirror: GiveMission reaction + logic var type 11 (plate only).

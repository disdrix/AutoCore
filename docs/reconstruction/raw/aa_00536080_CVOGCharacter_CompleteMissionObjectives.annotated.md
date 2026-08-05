# Annotated low-level: CVOGCharacter_CompleteMissionObjectives (`aa_00536080`)

| Field | Value |
|---|---|
| **Stable ID** | `aa_00536080` |
| **VA** | `0x00536080` |
| **Module** | `autoassault.exe` @ image base `0x400000` |
| **System** | missions-progression |
| **Source raw** | `aa_00536080_CVOGCharacter_CompleteMissionObjectives.md` (capture 2026-07-23) |
| **Residual annotate** | 2026-07-29 dual strengthen (listing + callers) |

This file is the **annotated** layer: widths, signedness, branch order, side effects, and decompiler corrections. It does not replace the immutable raw capture.

---

## 1. Corrected signature

```c
// __thiscall on character (NOT __cdecl — decompiler lie; listing RET 8)
char /* bool 0/1 */ __thiscall
CVOGCharacter_CompleteMissionObjectives(
    void* thisCharacter,       // ECX — saved and forwarded to CompleteObjective
    uint32_t missionId,        // stack formal 0
    uint32_t forceComplete);   // stack formal 1 — raw name uReason; callee force flag
```

| Name | Width | Signedness | Origin | Role |
|---|---|---|---|---|
| `thisCharacter` | **ptr** | — | ECX | Character; required for CompleteObjective thiscall |
| `uMissionID` | **u32** | unsigned | stack | Mission def key |
| `uReason` / `forceComplete` | **u32** (used as char) | opaque / force bit | stack | Forwarded as CompleteObjective 4th stack arg (force) |
| return | **i8/char** | 0/1 | `AL` | 1 if mission def found (even if 0 objectives) |

Plate: used by prerequisite auto-complete path with `forceComplete = 1`.

### Convention proof (listing)

```
00536080  PUSH ECX / MOV [ESP],ECX     ; save this
00536084  MOV ECX,[DAT_00b041fc]       ; table owner for FUN_0053fff0
...
005360d0  MOV ECX,[ESP+0x10]           ; restore this for CompleteObjective
005360d4  PUSH force / PUSH -1 / PUSH -1 / PUSH objId
005360da  CALL CompleteObjective
...
005360aa / 005360ed  RET 8             ; clean missionId + forceComplete
```

Callers (`0x005365ae`, `0x00536722`): `PUSH 1; PUSH missionId; MOV ECX,ESI; CALL` — **ECX is live**, not dead.

---

## 2. Decompiler corrections

| Decompiler artifact | Correction | Confidence |
|---|---|---|
| `__cdecl` / no this | **`__thiscall`** with live character this | **High** |
| `undefined4 uReason` | **forceComplete** u32 (callee char force) | **High** |
| Plate “CompleteObjective with reason 0xffffffff” | Args **2/3** are `0xFFFFFFFF`; arg **4** is force; this in ECX | **High** |
| `FUN_0053fff0` free call | ECX = `DAT_00b041fc`; returns lazy `*(owner+0xf18)` | **High** CF |
| `*(byte*)(def + 0x130)` | **u8** objective count (MOVZX) | **High** |
| `*(def + 0x13c)` | **ptr** to array of **objective def pointers** | **High** |
| Array element `objPtr + 0x10` | Objective id **u32** | **High** |
| CompleteObjective without this | `CompleteObjective(this, id, -1, -1, force)` | **High** |

Loop bound: `i < (int)(uint)count` after MOVZX — count **0..255**; `TEST/JLE` skips empty.

---

## 3. Control flow

```text
this_saved = this
root = FUN_0053fff0(DAT_00b041fc)
defTable = *root
if defTable == 0: return 0
def = Lookup(defTable, missionId)
if def == 0: return 0

count = *(u8*)(def + 0x130)
array = *(ObjectiveDef**)(def + 0x13c)
for i in 0 .. count-1:
  obj = *(array + i)            // raw: *(int*)(*(int*)(def+0x13c) + i*4)
  CompleteObjective(this_saved, obj->id, 0xFFFFFFFF, 0xFFFFFFFF, forceComplete)
return 1
```

Raw expression for obj id:

```c
*(undefined4 *)(*(int *)(*(int *)((int)pvVar3 + 0x13c) + iVar4 * 4) + 0x10)
```

| Branch | Effect |
|---|---|
| No table / miss | `return 0`, no completes (`RET 8`) |
| Found, count 0 | `return 1` immediately (JLE skip loop) |
| Found, count N | N× CompleteObjective then `return 1` |

---

## 4. Side-effect order

1. Def lookup (read-only).
2. Sequential `CVOGReaction_CompleteObjective` calls (order = array order); each may advance/final/rewards (callee).
3. Return success byte for **def found**, not for per-objective success.

No direct character hash mutation in this function — delegates to CompleteObjective.

---

## 5. Open questions

- Full force values beyond sole static `1` (no EvaluatePending xref as of 2026-07-29).
- Whether CompleteObjective failures matter — **ignored in body**.
- Relationship to S2C force-complete opcode `0x2070` (not this function; that path calls CompleteObjective directly).
- Product name for `FUN_0053fff0` / `DAT_00b041fc`.

## 6. Dual residual note (2026-07-29)

Live Ghidra decompile body **≡** raw CF; listing **corrects** convention/`this`/force naming. Dual A/B strengthened; scratch `tmp/a_00536080.md`. Prior residual that labeled call-site ECX dead / cdecl static is **withdrawn**.

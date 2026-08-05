# Review A (reconstruction fidelity): `aa_00530610` CVOGCharacter_AddMissionCounter

| Field | Value |
|---|---|
| **Stable ID** | `aa_00530610` |
| **VA** | `0x00530610` |
| **Canonical name** | `FUN_00530610` (proposed: `CVOGCharacter_AddMissionCounter`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00530610_CVOGCharacter_AddMissionCounter.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** (map node layout product English open; decompiler arity incomplete) |

---

## 1. Purpose

Character-side **keyed counter map** update used on final objective rewards:

1. Map object lives at **`char+0x584`** (lower_bound this); sentinel/head pointer at **`char+0x588`**.
2. `FUN_00418b80` lower-bounds / finds by **key** (stack arg0).
3. **Miss** (result == head at `+0x588`): `FUN_0053af20` insert node; write `{0, insertValue}` into new node dwords.
4. **Hit**: `*(node+0x14) += delta`.

CompleteObjective packs: key=`obj+0x10c`, delta=`obj+0x110`, third=`0`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00530610_FUN_00530610.md` |
| Annotated | `docs/reconstruction/raw/aa_00530610_FUN_00530610.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00530610.cpp` |
| Function record | `docs/reconstruction/functions/aa_00530610_FUN_00530610.md` |
| Live listing | `disassemble_function` `0x00530610` |
| Call site | `get_assembly_context` @ `0x00534239` |
| Parent residual | `reviews/a_00533f90.md` |

---

## 3. Listing / ABI (corrects decompiler)

```text
00530613  MOV EDI, ECX                 ; character
0053061e  LEA ESI, [EDI+0x584]         ; map object
00530627  CALL FUN_00418b80(&cursor, &key)
00530630  CMP EAX, [EDI+0x588]         ; miss if == head
00530636  JNZ hit
          ; miss: FUN_0053af20 insert; [node]=0; [node+4]=arg2_or_arg3 (see B)
0053065b  ADD [EAX+0x14], delta        ; hit
00530654/61  RET 0xC                   ; **3 stack formals**
```

| Claim | Evidence | Conf |
|---|---|---|
| `__thiscall` character in ECX | `MOV EDI,ECX`; call sites `MOV ECX,ESI` | **High** |
| **RET 0xC** → **3** stack args | listing both exits | **High** |
| Decompiler shows only 2 stack formals | incomplete | **Falsified arity display** |
| Map at `+0x584`, head `+0x588` | `LEA ESI,[EDI+0x584]`; CMP vs `[EDI+0x588]` | **High** |
| Hit add at `node+0x14` | `ADD dword [EAX+0x14], ECX` | **High** |

Proposed signature:

```c
void __thiscall CVOGCharacter_AddMissionCounter(
    void* thisCharacter,  // ECX
    uint32_t key,         // obj counter id
    int32_t delta,        // addend on hit
    int32_t insertSeed);  // third formal; CompleteObjective passes 0
// RET 0xC
```

---

## 4. CompleteObjective packing

```text
MOV EAX, [EBX+0x10c]     ; key
CMP EAX, -1
JZ skip
MOV ECX, [EBX+0x110]     ; delta
PUSH 0                   ; third
PUSH ECX
PUSH EAX
MOV ECX, ESI             ; character
CALL 0x00530610
```

| Objective field | Role |
|---|---|
| `obj+0x10c` (`puVar2[0x43]`) | Counter key; **-1** = none |
| `obj+0x110` (`puVar2[0x44]`) | Delta / payload |
| immediate `0` | Third formal |

Raw CompleteObjective decompile `FUN_00530610(puVar2[0x43], puVar2[0x44], 0)` matches.

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF miss insert / hit += | **High** | listing |
| Map base `+0x584` / head `+0x588` | **High** | residual said `+0x588` map — refine: head at 588, object 584 |
| 3 stack args RET 0xC | **High** | decompiler under-counted |
| Counter English (quest counter vs faction) | **Tentative** | product open |
| Insert node dword layout | **Probable** | `[0]=0`, seed in second dword on insert path |
| Clean scaffold ≡ raw CF | **High** | arity doc fix needed |

---

## 6. Surviving contract

```
AddMissionCounter(character, key, delta, insertSeed=0):
  map = character+0x584
  node = lower_bound(map, key)
  if node == head(character+0x588):
    insert(key); init node fields with seed
  else:
    node.counter(+0x14) += delta
```

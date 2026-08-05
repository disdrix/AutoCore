# Review A (reconstruction fidelity): `aa_004cf100` Mission_FillType0RewardTable

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cf100` |
| **VA** | `0x004cf100` |
| **Canonical name** | `FUN_004cf100` (proposed: `Mission_FillType0RewardTable`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004cf100_Mission_FillType0RewardTable.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept** (thin wrapper; callee `FUN_0052c700` not dualed) |

---

## 1. Purpose

**Thin wrapper** for type-0 mission reward table fill on local final complete:

```c
// listing
void FUN_004cf100(objDef*, character_unused*, rewardTable*) {
  FUN_0052c700(*objDef /* first dword / mission id or def key */, rewardTable);
}
```

CompleteObjective branch: when `obj+0xf8` (short `puVar2[0x3e]`) **== 0** → type-0 path calls this; else rolled path `FUN_004d08c0`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean / fn record | scaffold `aa_004cf100_*` |
| Live listing | `disassemble_function` `0x004cf100` |
| Call site | CompleteObjective `0x005342c9`; also `FUN_004d5c10` |
| Parent residual | `reviews/a_00533f90.md` |

---

## 3. Listing

```text
004cf100  MOV EAX, [ESP+0xC]     ; arg2 = reward table ptr
004cf104  MOV ECX, [ESP+0x4]     ; arg0 = objective/mission def*
004cf108  MOV EDX, [ECX]         ; *def
004cf10a  MOV ECX, [ESP+0x8]     ; arg1 loaded then **ignored**
004cf10e  PUSH EAX
004cf10f  PUSH EDX
004cf110  CALL FUN_0052c700
004cf115  RET 0xC                ; 3 stack formals
```

| Claim | Evidence | Conf |
|---|---|---|
| **3** stack args, **RET 0xC** | listing | **High** |
| arg1 **unused** | loaded to ECX never pushed/stored | **High** |
| Forwards `*arg0` + arg2 only | two PUSHes | **High** |
| Not thiscall | no ECX this use; all stack | **High** |

```c
void __stdcall /* or thiscall-less */ Mission_FillType0RewardTable(
    void* pObjOrMissionDef,  // *def first dword used
    void* ignoredCharacter,  // CompleteObjective still passes char
    void* pRewardTable);     // from CNDHash_LookupByKey(char+0x530 bind, missionId)
// RET 0xC
```

---

## 4. CompleteObjective site

```text
; local player only (+0x7e)
; EBP = reward table from Lookup(char+0x530, *obj)
CMP word [EBX+0xf8], 0
JNZ rolled
PUSH EBP
PUSH ESI              ; character (ignored by body)
PUSH EBX              ; objective def
CALL 0x004cf100
```

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Thin forward to `FUN_0052c700` | **High** | |
| Type-0 gate is **caller** (`+0xf8==0`) | **High** | not in body |
| arg1 unused | **High** | |
| `FUN_0052c700` fill semantics | **Open** | boundary |
| Clean ≡ raw | **High** | |

---

## 6. Surviving contract

```
FillType0Rewards(def, character_ignored, rewardTable):
  FUN_0052c700(*def, rewardTable)
// Only called when objective type short +0xf8 == 0 on local final path.
```

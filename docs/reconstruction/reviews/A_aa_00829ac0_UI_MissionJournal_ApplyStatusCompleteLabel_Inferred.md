# Review A (reconstruction fidelity): `aa_00829ac0` UI_MissionJournal_ApplyStatusCompleteLabel_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00829ac0` |
| **VA** | `0x00829ac0` |
| **Body** | `0x00829ac0`–`0x00829aff` exclusive (**64** B) |
| **Canonical name** | `UI_MissionJournal_ApplyStatusCompleteLabel_Inferred` |
| **Ghidra symbol** | `FUN_00829ac0` |
| **Prior / alias** | `Named_CalleeOf_Named_CalleeOf_Client_UpdateMissionJournal_00829ac0` |
| **Review date** | `2026-07-29` (W25-G OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00829ac0_UI_MissionJournal_ApplyStatusCompleteLabel_Inferred.md` |
| **System** | client UI / mission journal |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, meta/xrefs (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Apply the mission-journal **status** complete label from AL: store flag at panel+`0x4fd`, set status widget text to clear or `"(complete)"`, refresh widget.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00829ac0_FUN_00829ac0.md` (+ W25-G append) |
| Annotated | `docs/reconstruction/raw/aa_00829ac0_FUN_00829ac0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_MissionJournal_ApplyStatusCompleteLabel_Inferred.cpp` |
| Scaffold | `reconstructed-exact/FUN_00829ac0.cpp` |
| Function record | `docs/reconstruction/functions/aa_00829ac0_UI_MissionJournal_ApplyStatusCompleteLabel_Inferred.md` |
| Live decompile | ≡ raw |
| Live body bytes | full 64 B `read_memory` |
| String | `"(complete)"` @ `0x00a7496c` |
| Callers | SelectMission `00829b20`; build `00829ce0` |
| Peer | `UI_MissionJournal_SelectMission_Inferred` (W24-J) |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte seal (full body)

```
8b8e0c050000          mov ecx, [esi+0x50c]   ; status
85c9                  test ecx, ecx
8886fd040000          mov [esi+0x4fd], al    ; flag store (before branch)
742f                  jz ret
84c0                  test al, al
6a01                  push 1
6a01                  push 1
740f                  jz clear_path
8b01                  mov eax, [ecx]
686c49a700            push 0x00a7496c        ; "(complete)"
ff90d8010000          call [eax+0x1d8]
eb0a                  jmp join
clear_path:
8b11                  mov edx, [ecx]
6a00                  push 0
ff92d8010000          call [edx+0x1d8]
join:
8b8e0c050000          mov ecx, [esi+0x50c]
8b01                  mov eax, [ecx]
ffa04c030000          jmp [eax+0x34c]        ; tail refresh
c3                    ret                   ; null-status path
```

String read_memory @ `0x00a7496c`: `28 63 6f 6d 70 6c 65 74 65 29 00` = `"(complete)\0"`.

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw | **pass** |
| Body size 64 B exclusive end | **pass** (`00829aff`) |
| ESI / AL register ABI | **pass** |
| +0x4fd / +0x50c | **pass** |
| String identity | **pass** |
| Both arms push 1,1 | **pass** (bytes; decomp incomplete on complete arm) |
| Tail jmp +0x34c | **pass** |
| Null status early out | **pass** |
| Not objective-list rebuild | **pass** (no list walks) |
| Product flag semantics (ready vs complete) | **gap** |
| Construct-time AL intent | **gap** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Status label apply role | **High** | string + widget offset |
| ABI ESI/AL | **High** | decomp + callers |
| SetText (text,1,1) | **High** | bytes both arms |
| Consumes ready AL from SelectMission | **High** | call order `0052b3b0` then this |
| Product English | **Inferred** | |
| Ready ≡ complete badge meaning | **Probable** | open product |

---

## 6. Gaps

1. Product plate spelling.  
2. Exact product meaning of AL (ready vs mission-complete).  
3. SetText trailing int semantics.  
4. `FUN_00829ce0` AL at construct.  
5. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**

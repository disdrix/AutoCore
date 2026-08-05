# Review A (reconstruction fidelity): `aa_0041ac60` Hash_CollectKeyMatchesToLockedList_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0041ac60` |
| **VA** | `0x0041ac60` |
| **Canonical name** | `Hash_CollectKeyMatchesToLockedList_Inferred` |
| **Ghidra name** | `FUN_0041ac60` |
| **Prior alias** | `Named_CalleeOf_Skill_DbLoadSkillsCharacters_0041ac60` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Path A — fidelity (OWN-ONLY dual; Skill_DbLoadSkillsCharacters nested) |
| **Counterpart** | `reviews/B_aa_0041ac60_Hash_CollectKeyMatchesToLockedList_Inferred.md` |
| **System** | skills-abilities / hash → locked list collect |
| **Live tools** | Ghidra `batch_decompile`, `read_memory`, callees |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Given a **hash table object** (`param_1`) and **key** (`param_2`):

1. Allocate a **0x2C-byte locked list** object:
   - `*list = PTR_FUN_00a86168` (vtbl)
   - list head/tail/count zeros at `list[7..9]` (`+0x1C/+0x20/+0x24`)
   - lock-held flag byte `*(list+0x28) = 0`
   - `InitializeCriticalSection(list+1)` (CS at `+0x04`)
2. Compute bucket: `mask = *(param_1+8)`; chain head from  
   `*(*(param_1+0x10) + (mask & key)*4) + 4` (walk nodes via `node+0x0C`).
3. For each node where `*(node+0x10) == key` and `*(node+0x08) != 0`:  
   `FUN_0041c7e0(list, *(node+0x08))` — insert payload under CS.
4. Return list pointer (`ret 8`, stdcall 2 args).

Used in skill loader when skill has element count `local_1290 > 0`: build element collection for that skill key before copying 0x14-byte element records.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_0041ac60_*`, `reconstructed-exact/FUN_0041ac60.cpp` |
| Function record | `functions/aa_0041ac60_FUN_0041ac60.md` |
| Live bytes | `read_memory` @ `0x0041ac60` length 128 — ends `ret 8` + `CC` |
| Callees | `operator_new`, `InitializeCriticalSection`, `FUN_0041c7e0` |
| Vtbl | `PTR_FUN_00a86168` → first method `0x0041b9c0` |
| Parent | only **`0x007e34b0`** + `0x007e26e0` (skill-family) in callers window |

---

## 3. Assembly-sealed body

```text
0041ac60  push ebx / ebp
0041ac62  mov  ebp, [esp+0xC]           ; param_1
0041ac66  push esi / edi
0041ac68  mov  edi, [ebp+8]             ; mask
0041ac6b  and  edi, [esp+0x18]          ; mask & key (param_2)
0041ac6f  push 0x2C
0041ac71  call operator_new
0041ac76  mov  esi, eax
0041ac78  xor  ebx, ebx
0041ac7a  add  esp, 4
0041ac7d  cmp  esi, ebx
0041ac7f  jz   no_obj
0041ac81  lea  eax, [esi+4]
0041ac84  push eax
0041ac85  mov  [esi], 0x00a86168        ; vtbl
0041ac8b  mov  [esi+0x20], ebx
0041ac8e  mov  [esi+0x1C], ebx
0041ac91  mov  [esi+0x24], ebx
0041ac94  mov  [esi+0x28], bl           ; flag
0041ac97  call InitializeCriticalSection
0041ac9d  jmp  walk
no_obj:
0041ac9f  xor  esi, esi
walk:
0041aca1  mov  ecx, [ebp+0x10]          ; bucket table
0041aca4  mov  edx, [ecx+edi*4]
0041aca7  mov  edi, [edx+4]             ; first node
loop:
0041acaa  cmp  edi, ebx
0041acac  jz   done
0041acb0  mov  eax, [esp+0x18]          ; key
0041acb4  cmp  eax, [edi+0x10]
0041acb7  jnz  next
0041acb9  mov  eax, [edi+8]
0041acbc  cmp  eax, ebx
0041acbe  jz   next
0041acc0  push eax
0041acc1  push esi
0041acc2  call FUN_0041c7e0             ; insert
next:
0041acc7  mov  edi, [edi+0xC]
0041acca  cmp  edi, ebx
0041accc  jnz  loop
done:
0041acce  pop  edi
0041accf  mov  eax, esi                 ; return list*
0041acd1  pop  esi / ebp / ebx
0041acd4  ret  8
```

| Claim | Conf |
|---|---|
| Object size **0x2C** + CS at **+4** | **High** |
| Vtbl **`0x00a86168`** | **High** |
| Hash: `(mask & key)` into table at `param_1+0x10` | **High** |
| Node key at **+0x10**, payload at **+0x08**, next at **+0x0C** | **High** |
| Insert via `0041c7e0` | **High** |
| `ret 8` | **High** |
| Skill-element semantics of payload | **Medium** (parent context) |

---

## 4. Insert helper note (`FUN_0041c7e0`, not dualled)

From live decompile: EnterCS → reject if flag at `list+0x28` already set (`VOG_DEBUG_STOP` + throw `0x80070005`) → allocate node via vtbl+4 → link into list head at `list+0x20` / count++ → LeaveCS. Confirms list is **CS-protected singly/doubly linked**.

---

## 5. Gaps

1. Product type names for hash table vs locked list.
2. Dual of `0041c7e0` insert (throws on re-entrant lock flag).
3. Whether empty match set still returns non-null empty list (yes if `operator_new` succeeds — list with count 0).

**Verdict:** **accept-with-gaps**

# Review A (reconstruction fidelity): `aa_005875c0` List_RemoveNodeByIntKey

| Field | Value |
|---|---|
| **Stable ID** | `aa_005875c0` |
| **VA** | `0x005875c0` |
| **Canonical name** | `FUN_005875c0` (proposed: `List_RemoveNodeByIntKey` / reward-staging unlink) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005875c0_List_RemoveNodeByIntKey.md` |
| **System** | `missions-progression` (also FX / staging peers) |
| **Verdict** | **accept** on CF; product list English **open** |

---

## 1. Purpose

**Doubly-linked list remove-by-key**:

1. `this` = list owner; head/sentinel at `*(this+4)`.
2. Walk nodes via `node = *head` … until back to head.
3. Compare `node[2]` (`+0x8`) to `*pKey`.
4. On match: unlink (`prev->next` / `next->prev`), `operator_delete(node)`, continue walk (can remove multiple? — continues with next).
5. Ghidra warns "does not return" on delete — **false**: listing continues after `CALL operator_delete` and loops.

CompleteObjective: `LEA ECX, [character+0xcc4]; PUSH &resolvedObjId; CALL` — unregister resolved reward object from staging list before grant-or-delete.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean / fn | scaffold `aa_005875c0_*` |
| Live listing | `disassemble_function` `0x005875c0` |
| Call site CO | `0x00534384` with `LEA ECX,[ESI+0xcc4]` |
| Parent residual | `reviews/a_00533f90.md` (Probable "resolve/register") |

---

## 3. Listing seals

```text
005875c2  MOV ESI, ECX
005875c4  MOV EBX, [ESI+4]          ; sentinel
005875c7  MOV EAX, [EBX]            ; first node
005875cb  JZ empty → RET 4
005875d0  MOV ECX, [EAX+8]          ; node key
005875d3  MOV EDX, [ESP+0x10]       ; pKey
005875d7  CMP ECX, [EDX]
005875d9  JNZ advance
          ; unlink + PUSH EAX; CALL operator_delete
005875fe  JMP continue
00587609  RET 4
```

| Claim | Evidence | Conf |
|---|---|---|
| `__thiscall` list + **RET 4** | listing | **High** |
| Key at node `+0x8` | `MOV ECX,[EAX+8]` | **High** |
| Compare `*pKey` not pointer identity of arg | `CMP ECX,[EDX]` | **High** |
| Delete returns | fallthrough after CALL | **High** (decomp warning wrong) |
| CO this = `char+0xcc4` | call site LEA | **High** |

```c
void __thiscall List_RemoveNodeByIntKey(void* listThis, int* pKey);
// RET 4
```

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF walk / unlink / delete | **High** | |
| Residual "register" overstated | **Corrected** | body is **remove** |
| Staging list at `char+0xcc4` | **High** use-site | product name open |
| Multi-match removes all equal keys | **Probable** | loop continues after delete |
| Clean ≡ raw | **High** | |

---

## 5. Surviving contract

```
RemoveByKey(list, *key):
  for node in list:
    if node.key(+8) == *key:
      unlink; delete node
// CompleteObjective: list = character+0xcc4; key = resolved reward object id
// before inventory add or QueueDelete.
```

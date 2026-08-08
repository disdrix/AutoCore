# Review B (skeptical / adversarial): `aa_00402dd0` StdList_Resize_EsiList_EaxCount_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00402dd0` |
| **VA** | `0x00402dd0` |
| **Canonical name** | `StdList_Resize_EsiList_EaxCount_Inferred` |
| **Review date** | `2026-08-05` (MEGA-127 dual) |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_00402dd0_StdList_Resize_EsiList_EaxCount_Inferred.md` |
| **Live tools** | Independent `decompile_function` + `read_memory` + analyze/xrefs + `disassemble_function` + assembly context |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This is mission-list **domain logic** / `DebugListMissionsStatus` body | **Falsified** — pure list resize; mission parent is one of 5 callers |
| 2 | `void()` / no stack cleanup / thiscall ECX=list | **Falsified** — **ESI=list**, **EAX=count**, **`RET 4`** ×2; call sites `PUSH`+`MOV ESI`+`XOR EAX` |
| 3 | Same as `StdList_Clear_ESI` `00415e90` | **Falsified** — clear twin has no grow path, bare RET, different VA |
| 4 | `operator_delete` never returns (decompiler WARNING) | **Falsified** — `ADD ESP,4`; `ADD [ESI+8],-1`; loop re-CMP |
| 5 | Shrink removes **front** (`head->_Next`) | **Falsified** — `MOV EAX,[ECX+4]` = **head->_Prev** (back) |
| 6 | Vector resize (contiguous) | **Falsified** — circular node unlink; no begin/end pointers |
| 7 | Only clear (no grow) | **Falsified** — grow path CALL `004034c0` present; sites happen to pass 0 |
| 8 | Named_CalleeOf scaffold is final name | **Falsified** — parent-seed only; promote structural name |
| 9 | Runtime Confirmed | **Fails** — open |

---

## 2. Decisive machine dataflow

```text
PUSH EDI
MOV EDI, EAX              // target
MOV EAX, [ESI+8]          // size
CMP EDI, EAX
JBE shrink_eq

// grow
MOV ECX, [ESI+4]
SUB EDI, EAX
PUSH EDI / PUSH ECX / PUSH ESI
LEA ECX, [ESP+0x14]       // &fill
CALL 0x004034c0
POP EDI
RET 4

shrink_eq:
JNC done                  // equal
// shrink loop: node = head->prev; unlink; delete; size--
CMP EDI, [ESI+8]
JB  loop
done:
POP EDI
RET 4
```

Call-site (debug missions @ `0x00957447`):

```text
PUSH ESI                  // fill (old ESI)
XOR EAX, EAX              // new_size = 0
LEA ESI, [ESP+0x40]       // list local
CALL 0x00402dd0
// then rebuild via FUN_00402d10 push
```

A ≡ B on live decompile + body hex + xrefs + assembly context.

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Resize CF grow/eq/shrink | **High** | list corruption |
| ESI list + EAX count + RET 4 | **High** | stack smash / wrong this |
| Pop-back shrink + size-- | **High** | leak / size desync |
| Caller set (5) | **High** | missing specialization |
| Element type T | Medium | fill width only |
| Product English | Medium | naming only |

---

## 4. Surviving contract for AutoCore

```csharp
// Resize MSVC circular list: ESI=list (+4 head, +8 size), EAX=newCount, stack fill, RET 4
void ListResize(ListShell list, uint newCount, uint fill)
{
    if (list.Size < newCount)
    {
        InsertN(list, list.Head, newCount - list.Size, fill); // FUN_004034c0 path
        return;
    }
    while (newCount < list.Size)
    {
        var node = list.Head.Prev; // back
        if (node != list.Head)
        {
            Unlink(node);
            Delete(node);
            list.Size--;
        }
    }
}
// Keep distinct from StdList_Clear_ESI 00415e90 and ECX clear 00404060.
// Do not invent mission-specific product name from parent only.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/caller roles. Residual product element type → **accept-with-gaps**.

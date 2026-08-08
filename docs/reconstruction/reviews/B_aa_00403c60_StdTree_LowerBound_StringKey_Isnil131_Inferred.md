# Review B (skeptical / adversarial): `aa_00403c60` StdTree_LowerBound_StringKey_Isnil131_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00403c60` |
| **VA** | `0x00403c60` |
| **Canonical name** | `StdTree_LowerBound_StringKey_Isnil131_Inferred` |
| **Review date** | `2026-08-05` (MEGA-041 dual) |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_00403c60_StdTree_LowerBound_StringKey_Isnil131_Inferred.md` |
| **Live tools** | Independent `decompile_function` + `read_memory` + analyze/xrefs + `disassemble_function` + assembly context |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This is **upper_bound** | **Falsified** — compare is `operator<(node.key, key)`; true→right / false→cand+left is lower_bound. Twin `00403d60` inverts args. |
| 2 | This is **exact find** (equality sealed write-out) | **Falsified** — returns candidate only; equality/prefix checks live in callers (`find` / level gate). |
| 3 | isnil at +0x31 / +0x21 / +0x2D | **Falsified** — only **`+0x131`** (`80 BE 31 01 00 00` ×2). |
| 4 | **ECX thiscall** map method | **Falsified** — entry uses **EAX**; call sites set EAX; body never takes this from ECX. |
| 5 | Plain **RET** / no stack cleanup | **Falsified** — **`RET 4`** (`C2 04 00`); one stack arg. |
| 6 | Char-key / int-key lower_bound peer merge | **Falsified** — string key via `LEA [ESI+0xC]` + string `operator<` IAT; distinct from `Map_LowerBoundFindByCharKey` isnil@+0x21. |
| 7 | Product **QuickBar_ActivateSlot** leaf | **Falsified** — pure tree walk; callers are slash-command dispatch/help; residual seed only. |
| 8 | Same as insert-or-find `FUN_00402710` | **Falsified** — `00402710` is insert path (buynode / side flag); this unit is read-only lower_bound. |
| 9 | Runtime Confirmed | **Fails** — open |

---

## 2. Decisive machine dataflow

```text
MOV EAX, [EAX+4]              // head
MOV EBP, [ESP+8]              // key*
MOV ESI, [EAX+4]              // root
MOV EDI, EAX                  // cand = end
CMP BYTE PTR [ESI+0x131], 0
JNZ ret_cand
MOV EBX, [0x009c62e8]         // operator<
loop:
  LEA ECX, [ESI+0xC]          // &node.key
  PUSH EBP / PUSH ECX / CALL EBX / ADD ESP,8
  TEST AL, AL
  JZ  cand_left               // !(node.key < key)
  MOV ESI, [ESI+8]            // right
  JMP next
cand_left:
  MOV EDI, ESI                // cand = cur
  MOV ESI, [ESI]              // left
next:
  CMP BYTE PTR [ESI+0x131], 0
  JZ  loop
  POP EBX
ret_cand:
  MOV EAX, EDI
  RET 4
```

Call-site (`FUN_0093bd10` @ `0x0093bdfa`):

```text
LEA EAX, [EBX+4]
PUSH EDX                      // string
CALL 0x00403c60
MOV EDI, EAX
CMP EDI, [EBX+8]              // vs end/head
```

A ≡ B on live decompile + body hex + xrefs + assembly context.

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Lower-bound CF | **High** | wrong iterator / missed inserts |
| isnil@+0x131 | **High** | wrong family merge |
| EAX-map + RET 4 | **High** | stack smash / wrong map |
| string key @ +0xC | **High** | wrong compare |
| Caller set (3 sites) | **High** | missing specialization |
| Product English | Medium | naming only |
| Slash-cmd host type | Medium | not required for port of leaf |

---

## 4. Surviving contract for AutoCore

```csharp
// lower_bound for isnil@+0x131 string-key tree
// ABI: map in EAX, key* on stack, node* in EAX, callee cleans 4
Node LowerBound(Map map, string key)
{
    var head = map.Head;          // map+4
    var cur  = head.Parent;       // root
    var cand = head;              // end()
    while (!cur.IsNil)            // isnil @ +0x131
    {
        if (cur.Key < key)        // string @ +0x0C
            cur = cur.Right;      // +8
        else
        {
            cand = cur;
            cur  = cur.Left;      // +0
        }
    }
    return cand;
}
// Keep distinct from upper_bound 00403d60, char-key 00402210, isnil31 peers.
// Not QuickBar product logic.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/isnil/string-key/caller roles. Residual product map English + runtime → **accept-with-gaps**.

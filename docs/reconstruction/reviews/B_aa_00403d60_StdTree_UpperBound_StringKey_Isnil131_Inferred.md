# Review B (skeptical / adversarial): `aa_00403d60` StdTree_UpperBound_StringKey_Isnil131_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00403d60` |
| **VA** | `0x00403d60` |
| **Canonical name** | `StdTree_UpperBound_StringKey_Isnil131_Inferred` |
| **Review date** | `2026-08-05` (R10-020 dual) |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_00403d60_StdTree_UpperBound_StringKey_Isnil131_Inferred.md` |
| **Live tools** | Independent `decompile_function` + `read_memory` + analyze/xrefs + `disassemble_function` + assembly context |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This is **lower_bound** | **Falsified** — compare is `operator<(key, node.key)`; true→cand+left / false→right is upper_bound. Twin `00403c60` inverts args. |
| 2 | This is **exact find** (equality sealed write-out) | **Falsified** — returns candidate only; equality/prefix checks live in callers. |
| 3 | isnil at +0x31 / +0x21 / +0x2D | **Falsified** — only **`+0x131`** (`80 BE 31 01 00 00` ×2). |
| 4 | **ECX thiscall** map method | **Falsified** — entry uses **EAX**; call sites set EAX; body never takes this from ECX. |
| 5 | Plain **RET** / no stack cleanup | **Falsified** — **`RET 4`** (`C2 04 00`); one stack arg. |
| 6 | Char-key / int-key upper_bound peer merge | **Falsified** — string key via `LEA [ESI+0xC]` + string `operator<` IAT; distinct from `Map_LowerBoundFindByCharKey` isnil@+0x21. |
| 7 | Same body as twin lower_bound `00403c60` | **Falsified** — push order inverted (`PUSH node; PUSH key` vs lower's `PUSH key; PUSH node`); branch polarity inverted. |
| 8 | Product **QuickBar** / skill-cast leaf | **Falsified** — pure tree walk; only slash-help caller pairs lb/ub. |
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
  PUSH ECX / PUSH EBP / CALL EBX / ADD ESP,8  // op<(key, node.key)
  TEST AL, AL
  JZ  go_right                // !(key < node.key)
  MOV EDI, ESI                // cand = cur
  MOV ESI, [ESI]              // left
  JMP next
go_right:
  MOV ESI, [ESI+8]            // right
next:
  CMP BYTE PTR [ESI+0x131], 0
  JZ  loop
  POP EBX
ret_cand:
  MOV EAX, EDI
  RET 4
```

Call-site (`FUN_00957820` @ `0x0095797a`):

```text
LEA EDI, [EBP+4]
PUSH ECX                      // string
MOV EAX, EDI
CALL 0x00403d60               // upper
; then CALL 0x00403c60        // lower
CMP EDI, [EBP+8]              // vs end/head
```

A ≡ B on live decompile + body hex + xrefs + assembly context.

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Upper-bound CF | **High** | wrong range end / over-iterate |
| isnil@+0x131 | **High** | wrong family merge |
| EAX-map + RET 4 | **High** | stack smash / wrong map |
| string key @ +0xC | **High** | wrong compare |
| Caller set (2 sites, one function) | **High** | missing specialization |
| Product English | Medium | naming only |
| Slash-cmd host type | Medium | not required for port of leaf |

---

## 4. Surviving contract for AutoCore

```csharp
// upper_bound for isnil@+0x131 string-key tree
// ABI: map in EAX, key* on stack, node* in EAX, callee cleans 4
Node UpperBound(Map map, string key)
{
    var head = map.Head;          // map+4
    var cur  = head.Parent;       // root
    var cand = head;              // end()
    while (!cur.IsNil)            // isnil @ +0x131
    {
        if (key < cur.Key)        // string @ +0x0C; operator<(key, node.key)
        {
            cand = cur;
            cur  = cur.Left;      // +0
        }
        else
            cur = cur.Right;      // +8
    }
    return cand;
}
// Keep distinct from lower_bound 00403c60, char-key 00402210, isnil31 peers.
// Port with twin lower_bound for [lb, ub) ranges (slash help).
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/isnil/string-key/caller roles. Residual product map English + runtime → **accept-with-gaps**.

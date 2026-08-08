# Review B (skeptical / adversarial): `aa_004043e0` StdTree_Max_Isnil31

| Field | Value |
|---|---|
| **Stable ID** | `aa_004043e0` |
| **VA** | `0x004043e0` |
| **Canonical name** | `StdTree_Max_Isnil31` |
| **Review date** | `2026-08-05` (WQ9L-C dual) |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_004043e0_StdTree_Max_Isnil31.md` |
| **Live tools** | Independent `batch_decompile` + `read_memory` + `disassemble_function` + `get_assembly_context` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Function is void (decomp) | **Falsified** — call site `MOV [EBX+8],EAX` consumes return |
| 2 | Result lives in ECX | **Falsified** — when right already nil, EAX is original node and is stored; ECX is isnil right |
| 3 | Walks until isnil and **returns isnil** | **Falsified** — loop condition exits with EAX=last non-nil, ECX=isnil child |
| 4 | thiscall / ECX = node | **Falsified** — entry uses EAX; call site only `MOV EAX,EDI` |
| 5 | isnil at +0x29 / +0x2D | **Falsified** — every compare is `+0x31` |
| 6 | Min / leftmost walk | **Falsified** — loads `[EAX+8]` (right), not `[EAX]` (left) |
| 7 | Stack-arg ABI like Max isnil29 | **Falsified** — this unit is EAX register ABI |
| 8 | Runtime Confirmed | **Fails** — open (does not block accept of CF) |

---

## 2. Decisive machine dataflow

```text
// entry EAX = node
MOV ECX, [EAX+8]            // right
CMP byte [ECX+0x31], 0
JNZ ret                     // right isnil → EAX still = node
// LEA ESP,[ESP] 7-byte NOP align
loop:
MOV EAX, ECX                // node = right
MOV ECX, [EAX+8]
CMP byte [ECX+0x31], 0
JZ loop
ret:
RET                         // EAX = max non-nil
```

Call site (`0x00408fbf` in erase when updating head right):

```text
MOV EAX, EDI
CALL 0x004043e0
MOV dword ptr [EBX+8], EAX
```

A ≡ B on bytes + call-site EAX discipline. Twin min walks left (`[EAX]`) with same isnil/EAX pattern.

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Max / rightmost CF | **High** | Wrong head->right after erase |
| EAX in/out ABI | **High** | Corrupted tree rightmost |
| isnil +0x31 | **High** | Wrong size class merge |
| Product map English | **Open** | Naming residual only |

---

## 4. Surviving contract

```text
StdTree_Max_Isnil31:
  EAX = subtree root node*
  return EAX = rightmost non-nil (isnil@+0x31)
  bare RET; leaf; no callees
```

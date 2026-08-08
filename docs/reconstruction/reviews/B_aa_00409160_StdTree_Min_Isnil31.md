# Review B (skeptical / adversarial): `aa_00409160` StdTree_Min_Isnil31

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409160` |
| **VA** | `0x00409160` |
| **Canonical name** | `StdTree_Min_Isnil31` |
| **Review date** | `2026-08-05` (WQ9J-E dual) |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_00409160_StdTree_Min_Isnil31.md` |
| **Live tools** | Independent `batch_decompile` + `read_memory` + `disassemble_function` + `get_assembly_context` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Function is void (decomp) | **Falsified** — call site `MOV [EBX],EAX` consumes return |
| 2 | Result lives in ECX | **Falsified** — when left already nil, EAX is original node and is stored; ECX is isnil left |
| 3 | Walks until isnil and **returns isnil** | **Falsified** — loop condition exits with EAX=last non-nil, ECX=isnil child |
| 4 | thiscall / ECX = node | **Falsified** — entry uses EAX; no ECX setup at call site |
| 5 | isnil at +0x29 / +0x19 | **Falsified** — every compare is `+0x31` |
| 6 | Iterator++ / predecessor | **Falsified** — pure left walk min; no parent climb |
| 7 | Freelist / CNDHash domain | **Falsified** — only caller is map erase `FUN_00408ed0` |
| 8 | Same ABI as `StdTree_Min_Isnil29` (stack) | **Falsified** — this unit is EAX register ABI |
| 9 | Runtime Confirmed | **Fails** — open (does not block accept of CF) |

---

## 2. Decisive machine dataflow

```text
// entry EAX = node
MOV ECX, [EAX]              // left
CMP byte [ECX+0x31], 0
JNZ ret                     // left isnil → EAX still = node
loop:
MOV EAX, ECX                // node = left
MOV ECX, [EAX]
CMP byte [ECX+0x31], 0
JZ loop
ret:
RET                         // EAX = min non-nil
```

Call site (`0x00408f9d` in erase when updating head left):

```text
MOV EAX, EDI
CALL 0x00409160
MOV dword ptr [EBX], EAX
```

A ≡ B on bytes + call-site EAX discipline.

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Min / leftmost CF | **High** | Wrong head->left after erase |
| EAX in/out ABI | **High** | Corrupted tree leftmost |
| isnil +0x31 | **High** | Wrong size class merge |
| Product map English | **Open** | Naming residual only |

---

## 4. Surviving contract

```text
StdTree_Min_Isnil31:
  EAX = subtree root node*
  return EAX = leftmost non-nil (isnil@+0x31)
  bare RET; leaf; no callees
```

# Review B (skeptical / adversarial): `aa_004cb2c0` StdTree_Min_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cb2c0` |
| **VA** | `0x004cb2c0` |
| **Canonical name** | `StdTree_Min_Isnil21_Inferred` |
| **Review date** | `2026-08-05` (R13-002 dual) |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_004cb2c0_StdTree_Min_Isnil21_Inferred.md` |
| **Live tools** | Independent `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + `get_assembly_context` + callers/xrefs |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Function is void (decomp) | **Falsified** — all 7 call sites `MOV [EBX],EAX` consume return |
| 2 | Result lives in ECX | **Falsified** — when left already nil, EAX is original node and is stored; ECX is isnil left |
| 3 | Walks until isnil and **returns isnil** | **Falsified** — loop exits with EAX=last non-nil, ECX=isnil child |
| 4 | thiscall / ECX = node | **Falsified** — entry `MOV EAX,[ESP+4]`; call sites `PUSH` + `ADD ESP,4` |
| 5 | EAX-in register ABI (like isnil31 Min) | **Falsified** — stack arg only; no `MOV EAX` before CALL at sites |
| 6 | isnil at +0x29 / +0x31 | **Falsified** — every compare is `+0x21` (`80 79 21 00`); call-site guards also `+0x21` |
| 7 | Iterator++ / predecessor / max | **Falsified** — pure left walk min; no parent climb; no right walk |
| 8 | Freelist / CNDHash / skill product domain | **Falsified** — only erase-family map callers; generic STL plate |
| 9 | Same unit as Min isnil29 / isnil31 | **Falsified** — different isnil offset (and isnil31 different ABI) |
| 10 | Runtime Confirmed | **Fails** — open (does not block accept of CF) |

---

## 2. Decisive machine dataflow

```text
// entry [ESP+4] = node
MOV EAX, [ESP+4]            // node
MOV ECX, [EAX]              // left
CMP byte [ECX+0x21], 0
JNZ ret                     // left isnil → EAX still = node
nop: LEA ESP,[ESP]
loop:
MOV EAX, ECX                // node = left
MOV ECX, [EAX]
CMP byte [ECX+0x21], 0
JZ loop
ret:
RET                         // EAX = min non-nil
```

Call plate (all 7 erase parents, e.g. `0x0040571a` in parent `FUN_00405650`):

```text
PUSH EDI
CALL 0x004cb2c0
ADD ESP, 0x4
MOV dword ptr [EBX], EAX    // head->left = min(replacement)
```

Surrounding erase CF uses `CMP byte ptr [EDI+0x21],0` — same isnil class as parent dual R12-009.

A ≡ B on bytes + call-site stack/EAX discipline.

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Min / leftmost CF | **High** | Wrong head->left after erase |
| Stack-arg in / EAX out ABI | **High** | Corrupted tree leftmost |
| isnil +0x21 | **High** | Wrong size class merge with isnil29/31 |
| Product map English | **Open** | Naming residual only |

---

## 4. Surviving contract

```text
StdTree_Min_Isnil21_Inferred:
  stack = subtree root node*
  return EAX = leftmost non-nil (isnil@+0x21)
  bare RET; leaf; no callees
  caller cleans 4 (ADD ESP,4)
```

**Verdict:** **accept**. Falsified decomp-void / thiscall / EAX-in / wrong-isnil / skill-product claims. Role + ABI High; product English open → `_Inferred` retained. Runtime **not** Confirmed.

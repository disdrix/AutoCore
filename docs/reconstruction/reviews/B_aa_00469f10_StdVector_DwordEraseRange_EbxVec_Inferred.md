# Review B (skeptical / adversarial): `aa_00469f10` StdVector_DwordEraseRange_EbxVec_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00469f10` |
| **VA** | `0x00469f10` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_00469f10_StdVector_DwordEraseRange_EbxVec_Inferred.md` |
| **Evidence** | Live decompile + full-body `read_memory` 49 B + 1 xref + sole-caller shrink site bytes + twin `00410490` contrast |
| **Agent** | W38-N OWN-ONLY |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Decompiler `void(param_1,param_2)` is complete ABI | Bytes: EBX end triad, EAX out store, `RET 8` | **Falsified complete** — register formals required |
| 2 | Same as `FUN_00410490` | Twin is thiscall + `memmove` + `RET 0xC` | **Falsified merge** |
| 3 | Element size ≠ 4 | Loop `ADD 4` / sole caller `LEA [reg+reg*4]` | **Falsified** |
| 4 | Performs free / shrink capacity | Body only rewrites `+8`; no delete/new | **Falsified free** |
| 5 | Calls element dtors | Pure dword store loop | **Falsified dtor** |
| 6 | Scaffold effVertexDecl name is product | Multi-domain container helper via resize | **Rejected scaffold** |
| 7 | EAX is return-by-value of iterator (not out*) | Final `MOV [EAX],EDI` store-through | **Falsified value-return** — hidden out pointer |
| 8 | Product name sealed | Structural `_Inferred` only | **Accepted gap** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Erase-range role + dword stride | **Confirmed** | Wrong container port |
| EBX + EAX + stack + RET 8 | **Confirmed** | Caller contract break |
| Distinction from `00410490` | **Confirmed** | Wrong RET / memmove vs loop |
| Product name | **Open** | Doc-only |
| Runtime | **Open** | — |

---

## 3. Cross-check vs sole caller

`FUN_0044a380` shrink (`0x0044a3c7` region):

```text
PUSH EBX
LEA EAX, [begin+n*4]   ; first
PUSH end               ; last
PUSH first
LEA EAX, [esp+0x18]    ; outIt storage
MOV EBX, ECX           ; vec*
CALL FUN_00469f10
POP EBX
… RET 4
```

Matches EBX=vec, EAX=outIt*, two stack pointers, RET 8.

---

## 4. Byte anchors

```text
0x00469f10: 8B 4C 24 08 … 3B F9 74 1E   ; last/first; empty skip
            8B 73 08                     ; end from [EBX+8]
            83 C1 04 83 C2 04            ; dword step
            89 53 08  … 89 38 C2 08 00   ; publish end; *EAX=first; RET 8
```

---

## 5. What would reverse the seal?

- Proof EBX is not vec (contradicted by sole caller `MOV EBX,ECX` + end store).
- Proof `RET 4` or `RET 0xC` (contradicted by `C2 08 00`).
- Proof non-dword element (contradicted by `+4` loop and caller `*4` index).

None observed.

# Review A (reconstruction fidelity): `aa_0040d980` GuardedVector_PopFront

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040d980` |
| **VA** | `0x0040d980`–`0x0040d9b1` (**50 B**) |
| **Canonical name** | `GuardedVector_PopFront` (**Inferred**) |
| **Ghidra name** | `FUN_0040d980` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W30-B) |
| **Counterpart** | `reviews/B_aa_0040d980_GuardedVector_PopFront.md` |
| **System** | STL / guarded ring-deque container |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (full 50 B) + `analyze_function_complete`; leaf; 6 xrefs |
| **Verdict** | **accept** |

---

## 1. Purpose

Header-only ring **pop_front**: if non-empty, advance `begin` with wrap at `capacity*4`, `size--`, force `begin=0` when emptied. No element access, free, or CS.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0040d980_FUN_0040d980.md` (+ 2026-07-29 W30-B append) |
| Annotated | `docs/reconstruction/raw/aa_0040d980_FUN_0040d980.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_PopFront.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0040d980.cpp` |
| Function record | `docs/reconstruction/functions/aa_0040d980_FUN_0040d980.md` |
| Named record | `docs/reconstruction/functions/aa_0040d980_GuardedVector_PopFront.md` |
| Live | decompile ≡ raw CF; full body hex; plain RET |

---

## 3. Signature (sealed)

```c
// EAX=container; 0 stack formals; plain RET; void
void GuardedVector_PopFront(GuardedVectorHeader* container /*EAX*/);
```

| Slot | Source | Conf |
|---|---|---|
| container | **EAX** (direct `[EAX+…]` loads) | **High** |
| stack formals | none | **High** |
| cleanup | plain `RET` (`C3`) | **High** |
| return | void | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if size == 0: return
begin++
if capacity*4 <= begin: begin = 0
size--
if size == 0: begin = 0
```

| Stage | Match | Conf |
|---|---|---|
| size==0 no-op | **Yes** | **High** |
| begin++ + wrap at cap×4 | **Yes** | **High** |
| size-- | **Yes** | **High** |
| empty → begin=0 | **Yes** | **High** |
| No page/CS touch | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body (50 B):

```
8B 48 10          ; MOV ECX,[EAX+0x10]  size
85 C9             ; TEST ECX,ECX
74 2A             ; JZ ret
83 40 0C 01       ; ADD DWORD [EAX+0x0C],1  begin++
8B 50 0C          ; MOV EDX,[EAX+0x0C]
57                ; PUSH EDI
8B 78 08          ; MOV EDI,[EAX+0x08]  capacity
03 FF 03 FF       ; LEA EDI,[EDI*4] via ADD EDI,EDI twice
3B FA             ; CMP EDI,EDX
5F                ; POP EDI
77 07             ; JA skip wrap  (cap*4 > begin)
C7 40 0C 00 00 00 00  ; begin=0
83 C1 FF          ; ADD ECX,-1
89 48 10          ; MOV [EAX+0x10],ECX
75 07             ; JNZ ret
C7 40 0C 00 00 00 00  ; begin=0 if empty
C3                ; RET
```

Note: wrap compare is `cap*4 > begin` (JA) before zeroing — equivalent to `begin >= cap*4` after the prior `begin++`.

---

## 6. Gaps

- Product/PDB English only (structural name residual is naming, not CF).
- Callers may still owe element dtor / free before this (body itself complete).

---

## 7. Verdict

Leaf body fully sealed by decompile ≡ bytes; ABI/CF closed → **accept**.

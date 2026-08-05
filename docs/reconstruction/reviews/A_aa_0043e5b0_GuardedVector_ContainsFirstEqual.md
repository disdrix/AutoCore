# Review A (reconstruction fidelity): `aa_0043e5b0` GuardedVector_ContainsFirstEqual

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043e5b0` |
| **VA** | `0x0043e5b0`–`0x0043e62a` (**123 B**) |
| **Canonical name** | `GuardedVector_ContainsFirstEqual` (**Inferred**) |
| **Ghidra name** | `FUN_0043e5b0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W30-B) |
| **Counterpart** | `reviews/B_aa_0043e5b0_GuardedVector_ContainsFirstEqual.md` |
| **System** | STL / guarded ring-deque container |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (full 123 B) + `analyze_function_complete`; 5 callers / 6 xrefs; CS IAT Enter/Leave |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

CS-gated linear **first-equal** membership scan over the ring page map. Returns AL=1 on first `*slot == *key`, else 0. **No mutate**.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0043e5b0_FUN_0043e5b0.md` (+ 2026-07-29 W30-B append) |
| Annotated | `docs/reconstruction/raw/aa_0043e5b0_FUN_0043e5b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_ContainsFirstEqual.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043e5b0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0043e5b0_FUN_0043e5b0.md` |
| Named record | `docs/reconstruction/functions/aa_0043e5b0_GuardedVector_ContainsFirstEqual.md` |
| Live | decompile ≡ raw CF; full body hex; RET 0x4; AL=BL |

---

## 3. Signature (sealed)

```c
// EAX=container; stdcall 1 stack formal (key*); RET 0x4; AL=bool
uint8_t GuardedVector_ContainsFirstEqual(
    GuardedVectorHeader* container /*EAX*/,
    const int* key /*stack*/);
```

| Slot | Source | Conf |
|---|---|---|
| container | **EAX** (`MOV EDI,EAX` entry) | **High** |
| key* | Stack[+4] after ret (`[ESP+0x18]` mid-body) | **High** |
| cleanup | `RET 0x4` | **High** |
| return | **AL** (BL found flag) | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if cs_flag(+0x2c): EnterCS(+0x14)
idx = begin; found = 0; end = begin + size
while idx != end:
  page = idx>>2; sub = idx&3
  if capacity <= page: page -= capacity
  if pages[page][sub] == *key: found=1; break
  idx++
if cs_flag: LeaveCS
return found
```

| Stage | Match | Conf |
|---|---|---|
| CS enter/leave on +0x2c | **Yes** | **High** |
| Half-open [begin, begin+size) | **Yes** | **High** |
| Page wrap by capacity | **Yes** | **High** |
| First-equal stop + AL | **Yes** | **High** |
| No mutate | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Entry:

```
51 53 55 56 57 8B F8 80 7F 2C 00 8D 77 14 …
; PUSH ECX/EBX/EBP/ESI/EDI; MOV EDI,EAX; CMP [EDI+0x2C],0; LEA ESI,[EDI+0x14]
```

Epilogue:

```
B3 01             ; MOV BL,1   (hit path)
…
8A C3             ; MOV AL,BL
5B 59 C2 04 00    ; POP EBX; POP ECX; RET 4
```

Body length **123 B**. Full hex in raw W30-B append.

---

## 6. Gaps

- Product/PDB class English (`GuardedVector_*` structural; retail map overflow says `deque<T> too long`).
- Element type beyond dword POD.
- Runtime / bit-exact under multi-caller parents.
- Null page load residual if map hole (bytes do not null-check).

---

## 7. Verdict

Fidelity pass seals ABI, CS gate, ring index math, first-equal return. Product/runtime residual → **accept-with-gaps**.

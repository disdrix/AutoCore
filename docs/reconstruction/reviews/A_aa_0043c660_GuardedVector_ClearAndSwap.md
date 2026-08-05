# Review A (reconstruction fidelity): `aa_0043c660` GuardedVector_ClearAndSwap

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043c660` |
| **VA** | `0x0043c660`–`0x0043c6e8` (**137 B**) |
| **Canonical name** | `GuardedVector_ClearAndSwap` (**Inferred**) |
| **Ghidra name** | `FUN_0043c660` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W29-A) |
| **Counterpart** | `reviews/B_aa_0043c660_GuardedVector_ClearAndSwap.md` |
| **System** | STL / guarded ring-deque container |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (full 137 B) + callers/callees; caller `0075dae0`; callees Resize + CS imports |
| **Verdict** | **accept** |

---

## 1. Purpose

Clear container A (`ESI`) to size 0 via sealed `GuardedVector_Resize`, then swap ring headers with container B (`EDI`) under B's optional critical section (`+0x2c` flag / `+0x14` CS).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0043c660_FUN_0043c660.md` (+ 2026-07-29 W29-A append) |
| Annotated | `docs/reconstruction/raw/aa_0043c660_FUN_0043c660.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_ClearAndSwap.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043c660.cpp` |
| Function record | `docs/reconstruction/functions/aa_0043c660_FUN_0043c660.md` |
| Named record | `docs/reconstruction/functions/aa_0043c660_GuardedVector_ClearAndSwap.md` |
| Live | decompile ≡ raw; full body hex; sole caller `FUN_0075dae0` |
| Context | nested Resize sealed W28-D; CS imports |

---

## 3. Signature (sealed)

```c
// ESI=A, EDI=B; plain RET after SEH ADD ESP,0x10
void GuardedVector_ClearAndSwap(void /*ESI, EDI*/);
```

| Slot | Source | Conf |
|---|---|---|
| A | **ESI** | **High** |
| B | **EDI** | **High** |
| CS flag | `[EDI+0x2c]` | **High** |
| CS object | `EDI+0x14` | **High** |
| Resize clear | `XOR ECX,ECX; MOV EAX,ESI; CALL 0043c7e0` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if flag: EnterCS(B+0x14)
Resize(A, 0)
swap A/B +0x04 +0x08 +0x0c +0x10
if flag: LeaveCS(B+0x14)
RET
```

| Stage | Match | Conf |
|---|---|---|
| CS gate both sides | **Yes** | **High** |
| Clear via Resize ECX=0 | **Yes** | **High** |
| 4-dword header swap | **Yes** | **High** |
| No stack formals | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Entry / clear:

```
6A FF 68 78 E9 9B 00 …          ; SEH
80 7F 2C 00                     ; cmp [edi+0x2c],0
… EnterCriticalSection …
33 C9 8B C6 E8 44 01 00 00      ; xor ecx,ecx; mov eax,esi; call Resize
```

Epilogue: `83 C4 10 C3`.  
Body length **137 B** (`0x0043c660`–`0x0043c6e8`).

---

## 6. Gaps

- Product/PDB English.
- Parent `FUN_0075dae0` higher-level purpose (who owns A/B).
- Runtime / bit-exact under contended CS.

---

## 7. Verdict

ESI/EDI ABI, optional CS, clear-via-Resize, and four-dword ring swap fully sealed from live decompile + full body bytes. Residual naming/parent only → **accept**.

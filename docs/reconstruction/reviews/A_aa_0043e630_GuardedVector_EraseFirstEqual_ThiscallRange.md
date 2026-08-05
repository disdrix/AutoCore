# Review A (reconstruction fidelity): `aa_0043e630` GuardedVector_EraseFirstEqual_ThiscallRange

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043e630` |
| **VA** | `0x0043e630`–`0x0043e6c1` (**146 B**) |
| **Canonical name** | `GuardedVector_EraseFirstEqual_ThiscallRange` (**Inferred**) |
| **Ghidra name** | `FUN_0043e630` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W35-A) |
| **Counterpart** | `reviews/B_aa_0043e630_GuardedVector_EraseFirstEqual_ThiscallRange.md` |
| **System** | STL / guarded ring-deque container |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (full 146 B) + `analyze_function_complete` + xrefs; 2 callers; CS IAT Enter/Leave; nested `0043df90` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

CS-gated linear **first-equal erase** over the ring page map. On hit, erase one slot via **thiscall** `GuardedVector_EraseRange_Thiscall` and return AL=1; miss → AL=0.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0043e630_FUN_0043e630.md` (+ 2026-07-29 W35-A append) |
| Annotated | `docs/reconstruction/raw/aa_0043e630_FUN_0043e630.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_EraseFirstEqual_ThiscallRange.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043e630.cpp` |
| Function record | `docs/reconstruction/functions/aa_0043e630_FUN_0043e630.md` |
| Named record | `docs/reconstruction/functions/aa_0043e630_GuardedVector_EraseFirstEqual_ThiscallRange.md` |
| Live | decompile ≡ raw CF; full body hex; RET 0x4; AL=BL; ESI from entry |
| Twin | W28-C `GuardedVector_EraseFirstEqual` @ `0x0043c550` (same size/outer ABI; different nested erase) |

---

## 3. Signature (sealed)

```c
// ESI=container; stdcall 1 stack formal (key*); RET 0x4; AL=bool
uint8_t GuardedVector_EraseFirstEqual_ThiscallRange(
    const int* key /*stack*/,
    GuardedVectorHeader* container /*ESI*/);
```

| Slot | Source | Conf |
|---|---|---|
| container | **ESI** (entry `CMP [ESI+0x2C],0`) | **High** |
| key* | Stack formal | **High** |
| cleanup | `RET 0x4` | **High** |
| return | **AL** (BL found flag) | **High** |
| nested erase | `MOV ECX,ESI; CALL 0043df90` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if cs_flag(+0x2c): EnterCS(+0x14)
idx = begin; found = 0; end = begin + size
while idx != end:
  page = idx>>2; sub = idx&3 (via page*-4)
  if capacity <= page: page -= capacity
  if pages[page][sub] == *key:
    EraseRange_Thiscall([idx, idx+1)); found=1; break
  idx++
if cs_flag: LeaveCS
return found
```

| Stage | Match | Conf |
|---|---|---|
| CS enter/leave on +0x2c | **Yes** | **High** |
| Half-open [begin, begin+size) | **Yes** | **High** |
| Page wrap by capacity | **Yes** | **High** |
| First-equal stop + erase one + AL | **Yes** | **High** |
| Nested thiscall EraseRange | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Entry:

```
83 EC 0C          ; SUB ESP,0xC
80 7E 2C 00       ; CMP [ESI+0x2C],0
53 55 57          ; PUSH EBX/EBP/EDI
8D 7E 14          ; LEA EDI,[ESI+0x14]
```

Hit path nested erase:

```
8B CE             ; MOV ECX,ESI
E8 EC F8 FF FF    ; CALL FUN_0043df90
B3 01             ; MOV BL,1
```

Epilogue:

```
8A C3             ; MOV AL,BL
5B 83 C4 0C C2 04 00  ; POP EBX; ADD ESP,0xC; RET 4
```

Body length **146 B**. Full hex in raw W35-A append.

---

## 6. Gaps

- Product/PDB class English; element semantic type beyond dword compare.
- Nested EraseRange internals owned by W34-L (not re-owned here).
- Runtime / multi-caller concurrent erase under CS.

---

## 7. Verdict

ABI, CS, scan, and thiscall one-slot erase CF sealed from live decompile + bytes + two callers (AssPreloader pending `+0x1c`, NDResourceCache). Product residual → **accept-with-gaps**.

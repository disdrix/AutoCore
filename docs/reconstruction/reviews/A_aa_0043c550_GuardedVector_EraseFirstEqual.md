# Review A (reconstruction fidelity): `aa_0043c550` GuardedVector_EraseFirstEqual

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043c550` |
| **VA** | `0x0043c550`–`0x0043c5e1` (**146 B**) |
| **Canonical name** | `GuardedVector_EraseFirstEqual` (**Inferred**) |
| **Ghidra name** | `FUN_0043c550` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W28-C) |
| **Counterpart** | `reviews/B_aa_0043c550_GuardedVector_EraseFirstEqual.md` |
| **System** | STL / guarded ring-vector container |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (full 146 B); callers `00423e00`/`007b65d0`; callees CS + `0043c8c0` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Optional-CS first-equal erase:

1. If `lockEnable (+0x2c)` → `EnterCriticalSection(+0x14)`.
2. Scan ring indices `[begin, begin+size)`.
3. On first `elem == *key` → `GuardedVector_EraseRange([idx,idx+1))`, set found=1, exit loop.
4. Leave CS if entered; return bool.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0043c550_FUN_0043c550.md` (+ 2026-07-29 W28-C append) |
| Annotated | `docs/reconstruction/raw/aa_0043c550_FUN_0043c550.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_EraseFirstEqual.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043c550.cpp` |
| Function record | `docs/reconstruction/functions/aa_0043c550_FUN_0043c550.md` |
| Named record | `docs/reconstruction/functions/aa_0043c550_GuardedVector_EraseFirstEqual.md` |
| Live | decompile ≡ raw CF; `RET 4`; ESI used from entry; caller `00423e00` does `MOV ESI,ECX; ADD ESI,0x58` |
| Context | EraseRange sealed W27-C; AssignTo sibling at `0x0043c5f0` |

---

## 3. Signature (sealed)

```c
// ESI=container; stdcall 1 stack arg; RET 4; AL=bool
uint8_t GuardedVector_EraseFirstEqual(int* key);
```

| Slot | Source | Conf |
|---|---|---|
| container | **ESI** (caller-established) | **High** |
| key | Stack[+4] | **High** |
| cleanup | `RET 4` | **High** |
| return | AL found | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if lockEnable: EnterCS
idx=begin; end=begin+size; found=0
while idx!=end:
  if elem(idx)==*key: EraseRange[idx,idx+1); found=1; break
  idx++
if lockEnable: LeaveCS
return found
```

| Stage | Match | Conf |
|---|---|---|
| CS gate +0x2c / +0x14 | **Yes** | **High** |
| Linear first-match | **Yes** | **High** |
| EraseRange one-slot | **Yes** | **High** |
| RET 4 / AL | **Yes** | **High** |
| Element type beyond dword | shape only | **Medium** |

---

## 5. Machine bytes (`read_memory`)

Full **146 B** hex sealed in raw. Entry `83 EC 0C 80 7E 2C 00`. Epilogue `8A C3 5B 83 C4 0C C2 04 00`. Rel32 to `0043c8c0`.

---

## 6. Gaps

- Product/PDB class English; element semantic type (dword compare sealed only).
- Nested EraseRange internals owned elsewhere (W27-C).
- Runtime / multi-key concurrent erase.

---

## 7. Verdict

ABI, CS, scan, and erase-one CF sealed from live decompile + bytes + two assManager callers. Element-type / product residual → **accept-with-gaps**.

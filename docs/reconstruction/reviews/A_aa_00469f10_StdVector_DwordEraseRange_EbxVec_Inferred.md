# Review A (reconstruction fidelity): `aa_00469f10` StdVector_DwordEraseRange_EbxVec_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00469f10` |
| **VA** | `0x00469f10`–`0x00469f41` exclusive (**49 B** / `0x31`) |
| **Canonical name** | `StdVector_DwordEraseRange_EbxVec_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_00469f10` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W38-N) |
| **Counterpart** | `reviews/B_aa_00469f10_StdVector_DwordEraseRange_EbxVec_Inferred.md` |
| **System** | STL dword vector erase-range (EBX-vec ABI) |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (49 B full) + `analyze_function_complete` + callers/xrefs + sole-caller shrink site `0x0044a380`. **No** `disassemble_bytes`. |
| **Verdict** | **accept** |

---

## 1. Purpose

MSVC-style **`vector<uint32_t>::erase(first, last)`** for POD dword:

1. If `first == last`: still `*outIt = first`; no end change.
2. Else: copy `[last, end)` → `[first, …)` by dword stores; publish `end = dest`.
3. Always `*outIt = first`.

**ABI:** **EBX=vec\***, **EAX=outIt\***, stack **first + last**, **`RET 8`**.

Not the thiscall/memmove twin `FUN_00410490` (`RET 0xC`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W38-N append) | `docs/reconstruction/raw/aa_00469f10_FUN_00469f10.md` |
| Annotated | `docs/reconstruction/raw/aa_00469f10_FUN_00469f10.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_DwordEraseRange_EbxVec_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00469f10.cpp` |
| Function record | `docs/reconstruction/functions/aa_00469f10_FUN_00469f10.md` |
| Named record | `docs/reconstruction/functions/aa_00469f10_StdVector_DwordEraseRange_EbxVec_Inferred.md` |
| Live | decompile CF ≡ scaffold; full 49 B hex; `C2 08 00` |
| Sole caller | `FUN_0044a380` shrink: `MOV EBX,ECX`; `LEA EAX,[esp+…]`; push first/last |
| Twin context | `A_aa_00410490_StdVector_EraseRange_Dword_Inferred` (W16-S) |

**Not performed:** Launcher, runtime, ledgers.

---

## 3. Signature (sealed)

```c
// EBX=vec*; EAX=outIt*; stack first, last; RET 8
void StdVector_DwordEraseRange_EbxVec_Inferred(
    uint32_t* first /*stack*/,
    uint32_t* last  /*stack*/);
```

| Slot | Source | Conf |
|---|---|---|
| vec | **EBX** (`[EBX+8]` end load/store) | **High** |
| outIt | **EAX** (`MOV [EAX],EDI`) | **High** |
| first / last | stack pair; sole caller pushes | **High** |
| cleanup | **RET 8** (`C2 08 00`) | **High** |
| stride | `ADD reg,4` loop | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if first != last:
  end = *(EBX+8)
  dest = first
  while last != end:
    *dest++ = *last++   // dword
  *(EBX+8) = dest
*EAX = first
RET 8
```

| Stage | Match | Conf |
|---|---|---|
| Empty-range skip loop | **Yes** | **High** |
| Dword slide | **Yes** | **High** |
| Publish end | **Yes** | **High** |
| Always write outIt | **Yes** | **High** |
| Body 49 B | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Full 49 B hex in raw W38-N append.

```text
0x00469f10: 8B 4C 24 08 57 8B 7C 24 08 3B F9 74 1E …
            8B 73 08 … 83 C1 04 83 C2 04 …
            89 53 08 5E 89 38 5F C2 08 00
```

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | leaf |
| Callers | 1 — `FUN_0044a380` @ `0x0044a3df` |
| Callees | none |

---

## 7. Gaps

- Product/PDB STL mangled English.
- Runtime / bit-exact.

---

## 8. Verdict rationale

Leaf body fully covered by bytes + sole-caller ABI cross-check. Decompiler phantoms (`unaff_EBX`, `in_EAX`) resolved. **accept**.

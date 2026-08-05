# Review A (reconstruction fidelity): `aa_00431450` BasicString_FillAssignRange_0x1c

| Field | Value |
|---|---|
| **Stable ID** | `aa_00431450` |
| **VA** | `0x00431450`–`0x00431477` (**39 B**) |
| **Canonical name** | `BasicString_FillAssignRange_0x1c` |
| **Ghidra name** | `FUN_00431450` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W33-I) |
| **Counterpart** | `reviews/B_aa_00431450_BasicString_FillAssignRange_0x1c.md` |
| **System** | MSVC `basic_string<char>` range assign-fill |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (full body + IAT dword) + callers/xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept** |

---

## 1. Purpose

Assign one template `basic_string` into every live slot in `[first, last)` (stride **0x1c**). Hole-fill worker for `StdVector_InsertN_BasicString` in-place insert.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W33-I append) | `docs/reconstruction/raw/aa_00431450_FUN_00431450.md` |
| Annotated | `docs/reconstruction/raw/aa_00431450_FUN_00431450.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/BasicString_FillAssignRange_0x1c.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00431450.cpp` |
| Parent dual | `StdVector_InsertN_BasicString` (W32-B) |
| Live | decompile ≡ body loop; `ADD ESI,1C`; IAT call; plain `C3` |

---

## 3. Signature (sealed)

```c
// cdecl; first*, last*, value*; plain RET; void
void BasicString_FillAssignRange_0x1c(
    BasicString_0x1c* first,
    BasicString_0x1c* last,
    const BasicString_0x1c* value);
```

| Formal | Source | Conf |
|---|---|---|
| first / last / value | 3 stack args; caller `ADD ESP,0C` / combined `18` | **High** |
| stride 0x1c | `83 C6 1C` in body hex | **High** |
| operator= | `FF 15 C4 63 9C 00`; dword @ IAT → `0x006ec244` | **High** |

---

## 4. Control flow

| Stage | Match | Conf |
|---|---|---|
| `first == last` early exit | `CMP ESI,EDI` / `JE` | **High** |
| Loop assign | push value; `MOV ECX,ESI`; IAT call | **High** |
| Advance +0x1c | `ADD ESI,1C` | **High** |
| Epilogue pops + `RET` | `5B 5F 5E C3` | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (39 B) — see raw W33-I append.

```
56 8B 74 24 08 57 8B 7C 24 10 3B F7 74 16 53 8B 5C 24 18
53 8B CE FF 15 C4 63 9C 00 83 C6 1C 3B F7 75 F0 5B 5F 5E C3
```

Pad `CC`×9 to `0x00431480`.

---

## 6. Gaps / open

1. Product / MSVC demangle English.
2. Runtime / bit-exact / differential.

**Verdict:** **accept**

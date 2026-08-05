# Review A (reconstruction fidelity): `aa_00431480` BasicString_CopyBackward_Thunk_0x1c

| Field | Value |
|---|---|
| **Stable ID** | `aa_00431480` |
| **VA** | `0x00431480`–`0x0043149d` (**29 B**) |
| **Canonical name** | `BasicString_CopyBackward_Thunk_0x1c` |
| **Ghidra name** | `FUN_00431480` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W33-I) |
| **Counterpart** | `reviews/B_aa_00431480_BasicString_CopyBackward_Thunk_0x1c.md` |
| **System** | MSVC `basic_string<char>` copy-backward trampoline |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (thunk body + callee head + call site) + xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Thin trampoline: forward three range pointers into free `FUN_00431790` which performs `copy_backward` of live `basic_string` elements (stride **0x1c**). Opens the mid-insert hole in `StdVector_InsertN_BasicString`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W33-I append) | `docs/reconstruction/raw/aa_00431480_FUN_00431480.md` |
| Annotated | `docs/reconstruction/raw/aa_00431480_FUN_00431480.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/BasicString_CopyBackward_Thunk_0x1c.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00431480.cpp` |
| Callee decompile | `FUN_00431790` (role only; not owned) |
| Call site | `read_memory` @ `0x00430970` — 3 pushes + call @ `0x00430984` |
| Sibling thunk | `FUN_00431430` → `FUN_0046a2c0` (same parent family) |

---

## 3. Signature (sealed)

```c
// Call-site: cdecl; first*, last*, dest_end*; plain RET; void
void BasicString_CopyBackward_Thunk_0x1c(
    BasicString_0x1c* first,
    BasicString_0x1c* last,
    BasicString_0x1c* dest_end);
```

| Formal | Source | Conf |
|---|---|---|
| 3 stack args | parent `PUSH`×3 then call | **High** |
| callee | `E8 F7 02 00 00` → `0x00431790` | **High** |
| body stack clean | `83 C4 14` | **High** |
| Ghidra thiscall 4-param | body `PUSH ECX` shape | **Med** (not call-site ABI) |

---

## 4. Control flow

| Stage | Match | Conf |
|---|---|---|
| Entry push ECX / reorder | body hex | **High** |
| Call free copy_backward | relative call sealed | **High** |
| `ADD ESP,14` + `RET` | body hex | **High** |
| Callee reverse assign loop | decompile + `SUB *,1C` + IAT `operator=` | **High** (role) |

---

## 5. Machine bytes (`read_memory`)

Full body hex (29 B) — see raw W33-I append.

```
51 8B 04 24 8B 4C 24 10 8B 54 24 0C 50 8B 44 24 0C 51 52 50
E8 F7 02 00 00 83 C4 14 C3
```

---

## 6. Gaps / open

1. Product demangle for thunk vs free helper.
2. Nested `FUN_00431790` dual residual (role sealed only).
3. Whether ECX was ever a real `vector*` this in another build/caller — no second xref found.
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**

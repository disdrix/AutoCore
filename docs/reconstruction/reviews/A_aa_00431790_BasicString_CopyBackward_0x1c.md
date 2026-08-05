# Review A (reconstruction fidelity): `aa_00431790` BasicString_CopyBackward_0x1c

| Field | Value |
|---|---|
| **Stable ID** | `aa_00431790` |
| **VA** | `0x00431790`–`0x004317c2` (**51 B**) |
| **Canonical name** | `BasicString_CopyBackward_0x1c` (**Inferred**) |
| **Ghidra name** | `FUN_00431790` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W34-L) |
| **Counterpart** | `reviews/B_aa_00431790_BasicString_CopyBackward_0x1c.md` |
| **System** | MSVC `basic_string<char>` copy_backward free helper |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (full 51 B) + `analyze_function_complete`; sole caller `00431480`; IAT `[0x009c63c4]` |
| **Verdict** | **accept** |

---

## 1. Purpose

Free reverse-assign over half-open range `[first, last)` of live `basic_string` elements into a destination ending at `dest_end` (element stride **0x1c**). Implements the real algorithm behind W33-I trampoline `BasicString_CopyBackward_Thunk_0x1c`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00431790_FUN_00431790.md` (+ 2026-07-29 W34-L append) |
| Annotated | `docs/reconstruction/raw/aa_00431790_FUN_00431790.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/BasicString_CopyBackward_0x1c.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00431790.cpp` |
| Function record | `docs/reconstruction/functions/aa_00431790_FUN_00431790.md` |
| Named record | `docs/reconstruction/functions/aa_00431790_BasicString_CopyBackward_0x1c.md` |
| Live | decompile ≡ raw CF; full 51 B hex; plain `C3`; IAT call |
| Context | parent thunk W33-I; insert mid path `StdVector_InsertN_BasicString` |

---

## 3. Signature (sealed)

```c
// cdecl; 3 stack args; plain RET; returns final dest in EAX
BasicString_0x1c* BasicString_CopyBackward_0x1c(
    BasicString_0x1c* first,
    BasicString_0x1c* last,
    BasicString_0x1c* dest_end);
```

| Slot | Source | Conf |
|---|---|---|
| first | Stack → EBX | **High** |
| last | Stack → ESI | **High** |
| dest_end | Stack → EDI; empty path EAX load | **High** |
| return | EAX = final dest | **High** |
| cleanup | plain `C3` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if first == last: return dest_end
do:
  last -= 0x1c; dest_end -= 0x1c
  operator=(dest_end, last)   // IAT [0x009c63c4]
while last != first
return dest_end
```

| Stage | Match | Conf |
|---|---|---|
| Empty early-out | **Yes** | **High** |
| Reverse stride 0x1c | **Yes** (`83 EE 1C` / `83 EF 1C`) | **High** |
| IAT operator= | **Yes** (`FF 15 C4 63 9C 00`) | **High** |
| EAX return final dest | **Yes** (`8B C7` / empty load) | **High** |

---

## 5. Machine bytes (`read_memory`)

Full 51 B hex:

```
538b5c2408568b7424103bde741e578b7c241883ee1c83ef1c568bcfff15c4639c003bf375ed8bc75f5e5bc38b4424145e5bc3
```

Body end `0x004317c2`; pad `CC` follows.

---

## 6. Gaps

- Product/MSVC demangle English.  
- Runtime / bit-exact golden.

**Verdict:** **accept**

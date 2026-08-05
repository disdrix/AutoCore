# Review A (reconstruction fidelity): `aa_0044e1c0` GuardedVector_InsertRange

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044e1c0` |
| **VA** | `0x0044e1c0`–`0x0044e4ee` (**815 B**) |
| **Canonical name** | `GuardedVector_InsertRange` (**Inferred**) |
| **Ghidra name** | `FUN_0044e1c0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W32-G) |
| **Counterpart** | `reviews/B_aa_0044e1c0_GuardedVector_InsertRange.md` |
| **System** | STL / guarded ring-deque container |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (full 815 B) + `analyze_function_complete`; sole-caller setup |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Insert external dword range `[first, last)` into GuardedVector at absolute `insert_at`, using shorter-side (prefix vs suffix) policy with thiscall push_front / push_back growth and nested ring move/assign.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0044e1c0_FUN_0044e1c0.md` (+ W32-G live seal + full hex) |
| Annotated | `docs/reconstruction/raw/aa_0044e1c0_FUN_0044e1c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_InsertRange.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0044e1c0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0044e1c0_FUN_0044e1c0.md` |
| Named record | `docs/reconstruction/functions/aa_0044e1c0_GuardedVector_InsertRange.md` |
| Live | decompile ≡ raw CF tree; full 815 B hex; RET 0x18 on all exits |
| Nested sealed | W31-I PushFront/PushBack_Thiscall |
| Nested free | `0043ec50` / `0043ebb0` / `0044e4f0` (not OWN) |
| Caller | `FUN_00971700` @ `0x0097176b` — 6 stack pushes |

---

## 3. Signature (sealed)

```c
// stdcall; RET 0x18
void GuardedVector_InsertRange(
    GuardedVectorHeader* container,  // [ebp+8] → ESI
    void* seed_out,                  // [ebp+0xc]
    uint32_t insert_at,              // [ebp+0x10]
    const uint32_t* first,           // [ebp+0x14]
    const uint32_t* last,            // [ebp+0x18]
    uint32_t sixth_residual          // [ebp+0x1c]
);
```

| Slot | Source | Conf |
|---|---|---|
| container | Stack / ESI | **High** |
| insert_at / first / last | Stack formals | **High** |
| N = (last−first)>>2 | Bytes + decompile | **High** |
| cleanup | **`RET 0x18`** | **High** |
| 6th formal meaning | Caller-present; decompiler-unused | **Tentative** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
prefix = insert_at - begin
suffix = size - prefix
N      = (last - first) >> 2

if prefix < suffix:          // front-biased
  if prefix < N:  push_front excess src + old prefix → assign → return
  else:           push_front N mapped → FUN_0043ec50 → fallthrough assign
else:                        // back-biased
  if suffix < N:  push_back excess src + old suffix → assign → return
  else:           push_back N mapped → FUN_0043ebb0 → fallthrough assign
FUN_0044e4f0 assign source into gap
```

| Stage | Match | Conf |
|---|---|---|
| 4-arm shorter-side tree | **Yes** | **High** |
| Front → `0043e3d0` | **Yes** (call displ) | **High** |
| Back → `0043d670` | **Yes** (call displ) | **High** |
| Page map `>>2` / wrap | **Yes** | **High** |
| Nested move/assign free | residual | **Open** |
| Product English | inferred only | **Inferred** |

---

## 5. Machine bytes (`read_memory`)

Full 815 B hex: see raw W32-G append.

Key sites:

| Site | Meaning |
|---|---|
| Epilogues `C2 18 00` | RET 0x18 (6 dwords) |
| `E8 …` → `0043e3d0` | PushFront_Thiscall |
| `E8 …` → `0043d670` | PushBack_Thiscall |
| SEH `LAB_009bdf40` | Frame / unwind |

---

## 6. Gaps

- Product/PDB class English.
- Nested free of `FUN_0044e4f0` / `FUN_0043ec50` / `FUN_0043ebb0`.
- Exact 6th stack formal product role.
- SEH throw/grow islands not re-owned.
- Runtime / bit-exact.

---

## 7. Verdict

ABI (RET 0x18 / 6-arg), shorter-side CF, and thiscall push polarity sealed; nested move/assign + 6th formal residual → **accept-with-gaps**.

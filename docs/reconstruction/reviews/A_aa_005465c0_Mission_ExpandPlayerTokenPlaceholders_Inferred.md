# Review A (reconstruction fidelity): `aa_005465c0` Mission_ExpandPlayerTokenPlaceholders_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005465c0` |
| **VA** | `0x005465c0` (measured **566 B**) |
| **Canonical name** | `Mission_ExpandPlayerTokenPlaceholders_Inferred` |
| **Ghidra name** | `FUN_005465c0` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY WQ7R-D) |
| **Counterpart** | `reviews/B_aa_005465c0_Mission_ExpandPlayerTokenPlaceholders_Inferred.md` |
| **System** | missions-progression / dialog string prep |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (body + strings) + `analyze_function_complete` + `get_assembly_context` + xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

In-place expand of five fixed player-token placeholders in a mission/UI `std::string`, sourcing values from a character object (name/class/race/credits/level).

Closes WQ-007 residual: undualed string helper on mission dialog path (`FUN_008aaf60`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ WQ7R-D append) | `docs/reconstruction/raw/aa_005465c0_FUN_005465c0.md` |
| Annotated | `docs/reconstruction/raw/aa_005465c0_FUN_005465c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Mission_ExpandPlayerTokenPlaceholders_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_005465c0.cpp` |
| Function record | `docs/reconstruction/functions/aa_005465c0_Mission_ExpandPlayerTokenPlaceholders_Inferred.md` |
| Live | decompile ≡ scaffold five-loop CF; string VAs verified; 2 callers |

---

## 3. Signature (sealed)

```c
// cdecl — 2 stack args; caller ADD ESP,8
void Mission_ExpandPlayerTokenPlaceholders_Inferred(
    Character* character,
    std::string* text);
```

| Formal | Source | Conf |
|---|---|---|
| character* | stack arg0 → EDI | **High** |
| text* | stack arg1 → ESI | **High** |
| cleanup | caller `ADD ESP,8` @ both sites | **High** |

---

## 4. Control flow / tokens

| Token | Replace len | Value source | Conf |
|---|---|---|---|
| `[$name]` @ `0x009d0620` | 7 | vcall `vtbl+0x160` (MI adjustor) | **High** |
| `[$class]` @ `0x009d0614` | 8 | `FUN_00521900` | **High** |
| `[$race]` @ `0x009d060c` | 7 | `FUN_00521800` | **High** |
| `[$credits]` @ `0x009d0600` | 10 | i64 `(+0x720)−(+0x728)` via `%I64d` | **High** |
| `[$level]` @ `0x009d05f4` | 8 | vcall `vtbl+0x27c` via `%i` | **High** |

Each block: find; if not npos, loop find → materialize → `replace` → find until npos.

Credits image spine: load `+0x720/+0x724`, `SUB`/`SBB` against `+0x728/+0x72c`, `sprintf`, replace 10.

---

## 5. Machine bytes (`read_memory`)

Prologue: `83 EC 40 53 55 56 8B 74 24 54 57 …`  
Epilogue: `5F 5E 5D 5B 83 C4 40 C3`  
Immediate string pushes: `68 20 06 9D 00` / `14 06 9D 00` / `0C 06 9D 00` / `00 06 9D 00` / `F4 05 9D 00`.  
Full hex: raw WQ7R-D append (566 B).

---

## 6. Gaps

- Product English for vtbl slots `+0x160` / `+0x27c` (GetName / GetLevel residual).
- Product English for `FUN_00521800` / `FUN_00521900` (WQ7R-F).
- Semantic name of subtractand at `char+0x728` (spent vs reserved vs display base).
- Whether `+0x720` is always “wallet credits” vs mission-only money field — cross-doc probable, not runtime Confirmed.
- Runtime / bit-exact / differential.

---

## Verdict

**accept-with-gaps** — five-token expand CF, cdecl ABI, string literals, and credits delta sealed against image; product getter names residual.

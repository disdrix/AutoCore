# Review A (reconstruction fidelity): `aa_00971900` AssPreloader_IsKeyTrackedRecursive_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00971900` |
| **VA** | `0x00971900`–`0x00971a19` (**282 B**) |
| **Canonical name** | `AssPreloader_IsKeyTrackedRecursive_Inferred` |
| **Ghidra name** | `FUN_00971900` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W31-K) |
| **Counterpart** | `reviews/B_aa_00971900_AssPreloader_IsKeyTrackedRecursive_Inferred.md` |
| **System** | assPreloader / asset preload pipeline |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (full 282 B) + `analyze_function_complete` + caller `004ed38a` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Drain AssPreloader work, then test whether a key is in the tracked GuardedVector at `this+0x7c`, optionally walking dependency keys when recurse≠0. Returns bool AL.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00971900_FUN_00971900.md` (+ W31-K append) |
| Annotated | `docs/reconstruction/raw/aa_00971900_FUN_00971900.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssPreloader_IsKeyTrackedRecursive_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00971900.cpp` |
| Function record | `docs/reconstruction/functions/aa_00971900_FUN_00971900.md` |
| Named record | `docs/reconstruction/functions/aa_00971900_AssPreloader_IsKeyTrackedRecursive_Inferred.md` |
| Live | decompile ≡ raw CF; full body hex; three `RET 8`; AL returns |

---

## 3. Signature (sealed)

```c
// ECX=this; stdcall 2 (key*, recurse); RET 8; AL=bool
uint8_t AssPreloader_IsKeyTrackedRecursive_Inferred(
    void* self /*ECX*/,
    const int* key /*stack*/,
    uint8_t recurse /*stack*/);
```

| Slot | Source | Conf |
|---|---|---|
| this | **ECX** (`mov ebp,ecx`) | **High** |
| key* | Stack | **High** |
| recurse | Stack (char test `cmp bl, al`) | **High** |
| cleanup | **`RET 8`** (all exits) | **High** |
| return | **AL** (1/0) | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
FUN_00971480(this)
if ContainsFirstEqual(this+0x7c, key*): return 1
if recurse == 0: return 0
local = empty ring
FUN_00744360(key, &local)
for child in local:
  if self(this, child, recurse): clear local; return 1
clear local; return 0
```

| Stage | Match | Conf |
|---|---|---|
| Drain first | **Yes** | **High** |
| Contains on +0x7c | **Yes** (`lea eax,[ebp+0x7c]`) | **High** |
| Recurse gate | **Yes** | **High** |
| Self-call preserves ECX | **Yes** (`mov ecx,ebp`) | **High** |
| Local ring clear both paths | **Yes** (`FUN_005b2ba0`) | **High** |

---

## 5. Machine bytes (`read_memory`)

Entry / this:

```
64 A1 00 00 00 00    ; SEH
...
8B E9                ; mov ebp, ecx
55                   ; push ebp  → FUN_00971480(this)
E8 5E FB FF FF       ; call FUN_00971480
8B 74 24 2C          ; mov esi, key*
56                   ; push esi
8D 45 7C             ; lea eax, [ebp+0x7c]
E8 …                 ; call FUN_0043e5b0
```

Epilogues (all):

```
… B0 01 … C2 08 00   ; return 1
… 32 C0 … C2 08 00   ; return 0
```

Body length **282 B**. Full hex in raw W31-K append.

External caller `0x004ed38a`: `mov ecx,[ecx+0x6c]; push 0; push ebx; call` — recurse=0 membership-only path.

---

## 6. Gaps

- Product/PDB method English.
- Nested `FUN_00971480` / `FUN_00744360` product semantics (not owned).
- Exact product meaning of tracked set +0x7c vs pending +0x1c pairing.
- Runtime / bit-exact.

---

## 7. Verdict

Fidelity pass seals ABI, drain-first, +0x7c contains, optional recursive dep walk, AL/RET8. Nested dual + product English residual → **accept-with-gaps**.

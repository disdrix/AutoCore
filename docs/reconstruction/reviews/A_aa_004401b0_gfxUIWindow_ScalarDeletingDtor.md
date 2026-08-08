# Review A (reconstruction fidelity): `aa_004401b0` gfxUIWindow_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_004401b0` |
| **VA** | `0x004401b0`–`0x004401cd` inclusive (**30 B** / `0x1E`) |
| **Canonical name** | `gfxUIWindow_ScalarDeletingDtor` |
| **Ghidra name** | `FUN_004401b0` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY MEGA-129) |
| **Counterpart** | `reviews/B_aa_004401b0_gfxUIWindow_ScalarDeletingDtor.md` |
| **System** | gfxUIWindow / MSVC scalar-deleting destructor |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_by_address` + callees/xrefs + multi-span `read_memory` + RTTI COL. **No** `disassemble_bytes`. |
| **Verdict** | **accept** |

---

## 1. Purpose

MSVC scalar-deleting destructor (vtbl[0] of `PTR_FUN_00a9f304`): always run complete dtor `FUN_00759de0` / `gfxUIWindow_CompleteDtor`; if `(flags & 1)` free the host with `operator_delete`; return `this`. Product class **gfxUIWindow** sealed by RTTI.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ MEGA-129 append) | `docs/reconstruction/raw/aa_004401b0_FUN_004401b0.md` |
| Annotated | `docs/reconstruction/raw/aa_004401b0_FUN_004401b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/gfxUIWindow_ScalarDeletingDtor.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_004401b0.cpp` |
| Function records | `aa_004401b0_FUN_004401b0.md`, `aa_004401b0_gfxUIWindow_ScalarDeletingDtor.md` |
| Complete peer | dualed `gfxUIWindow_CompleteDtor` (`aa_00759de0`, WQ9L-F) |
| Live | decompile ≡ 30 B hex; vtbl dword @ `0x00a9f304` = `0x004401b0`; COL → `.?AVgfxUIWindow@@` |

---

## 3. Signature (sealed)

```c
// ECX=this; stack flags; RET 4; returns this*
void* __thiscall gfxUIWindow_ScalarDeletingDtor(void* self, uint8_t flags);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX (`56 8B F1`) | **High** |
| flags | stack (`F6 44 24 08 01`) | **High** |
| return | EAX = ESI = this | **High** |
| cleanup | `C2 04 00` | **High** |

---

## 4. Control flow (bytes authority)

```
ESI = this
call FUN_00759de0              // complete dtor (thiscall)
if (flags & 1):
  operator_delete(this)
return this                    // RET 4
```

| Stage | Match | Conf |
|---|---|---|
| Complete-then-optional-free | decompile ≡ 30 B hex | **High** |
| bit0 gate only (not vector) | `test …,1` / `jz` | **High** |
| False noreturn ignored | epilogue present after delete | **High** |
| vtbl[0] | DATA `00a9f304` → `004401b0` | **High** |
| RTTI product name | COL → `.?AVgfxUIWindow@@` | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (30 B):

```
568bf1e8289c3100f644240801740956e85d96040083c4048bc65ec20400
```

Pad `CC CC` then next function @ `0x004401ce`.

Call reloc checks:

| Site | Target | Relative LE |
|---|---|---|
| `0x004401b3` CALL | `0x00759de0` | `28 9c 31 00` |
| `0x004401c0` CALL | `0x00489822` (`operator_delete`) | `5d 96 04 00` |

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker (`analyze_function_complete`) |
| Callers | DATA vtbl[0] only (no code CALL sites; callers list empty) |
| Callees | `FUN_00759de0`, `operator_delete` |

---

## 7. Gaps

1. Complete dtor body / member map not owned here (`FUN_00759de0` dualed separately **accept-with-gaps**).  
2. Runtime / bit-exact / differential — open.

---

## 8. Verdict

**accept** — scalar-dtor CF/ABI/vtbl[0]/RTTI/`RET 4`/false-noreturn sealed. Product demangle sealed (no `_Inferred`).

# Review A (reconstruction fidelity): `aa_0051e180` Map_Tidy_FreeHead_B

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051e180` |
| **VA** | `0x0051e180`–`0x0051e1ad` inclusive (**46 B** / exclusive end `0x0051e1ae`) |
| **Canonical name** | `Map_Tidy_FreeHead_B` |
| **Ghidra name** | `FUN_0051e180` |
| **Review date** | `2026-08-04` (WQ9F-H OWN dual) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY WQ9F-H) |
| **Counterpart** | `reviews/B_aa_0051e180_Map_Tidy_FreeHead_B.md` |
| **System** | MSVC map tidy / free header (host of dualed `Map_EraseRange_B`) |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `disassemble_function` + `read_memory` (full body) + xrefs + `get_assembly_context`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Bare map tidy (no SEH): full-range erase via dualed **`Map_EraseRange_B`**, free header sentinel, null `head` and `size`. Same **46 B** template as dualed `Map_Tidy_FreeHead` @ `0x0051da30` (which uses `Map_EraseRange` instead). Sole recovered host: static map at `0x00b0427c` via atexit thunk `FUN_009c3970`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ WQ9F-H append) | `docs/reconstruction/raw/aa_0051e180_FUN_0051e180.md` |
| Annotated | `docs/reconstruction/raw/aa_0051e180_FUN_0051e180.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Map_Tidy_FreeHead_B.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0051e180.cpp` |
| Function record | `docs/reconstruction/functions/aa_0051e180_Map_Tidy_FreeHead_B.md` |
| Erase range | dualed `Map_EraseRange_B` / `aa_0051d880` (WQ9D) |
| Peer tidy A | dualed `Map_Tidy_FreeHead` / `aa_0051da30` (WQ9E-J) |
| Live | decompile truncated after delete; **46 B hex seals null + RET** |

---

## 3. Signature (sealed)

```c
// ECX = map*; bare RET (C3); void
void __fastcall Map_Tidy_FreeHead_B(MapFacade* map);
```

| Formal | Source | Conf |
|---|---|---|
| map | ECX (`56 8B F1`) | **Confirmed** |
| head@+4 / size@+8 | post-delete stores | **Confirmed** |
| free this? | no (frees head only) | **Confirmed** |
| SEH | none in body | **Confirmed** |

---

## 4. Control flow (bytes authority)

```
ESI = this (map)
out slot = push ECX
head = [ESI+4]
CALL Map_EraseRange_B(map, &out, *head, head)   // full-range @ 0x0051d880
operator_delete(head); ADD ESP,4
[ESI+4] = 0; [ESI+8] = 0
POP ESI; POP ECX; RET
```

| Stage | Match | Conf |
|---|---|---|
| Full-range erase args | Yes (`*head`, `head`) | **Confirmed** |
| Erase callee is EraseRange_B | Yes (rel32 → `0x0051d880`) | **Confirmed** |
| Free header only | Yes | **Confirmed** |
| Null head+size after delete | Yes (bytes; decompiler missed) | **Confirmed** |
| Bare RET / no SEH | Yes | **Confirmed** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (46 B):

```
51568bf18b46048b0850518d44240c508bcee8e9f6ffff8b4e0451e882b6f6ff83c40433c08946048946085e59c3
```

Pad `CC CC` then next function.

---

## 6. Callers / classification

| Item | Value | Conf |
|---|---|---|
| Code callers | `FUN_009c3970` (`MOV ECX,0xb0427c` / `JMP`) | **Confirmed** |
| Classification | map tidy / free-head (not scalar deleting dtor of facade) | **High** |
| Product host class | Open (static map @ `0x00b0427c`) | open |

Prior dual note (`Map_EraseRange_B` A): sole static caller was this tidy — **confirmed**.

---

## 7. Naming gate

| Evidence | Present? |
|---|---|
| Tidy template (erase full + free head + null) | **Yes** |
| Callee is dualed Map_EraseRange_B | **Yes** |
| Peer shape Map_Tidy_FreeHead (46 B; different erase) | **Yes** |
| Product/PDB English | **No** |

**Decision:** promote **`Map_Tidy_FreeHead_B`** (structural twin naming like `Map_EraseRange_B` / `Map_FreeSubtree_B`).

Reject: identity merge with `Map_Tidy_FreeHead`; map complete/scalar dtor of facade; `FUN_0051e150` isnil15 tidy.

---

## 8. Gaps

1. Product English for owning class / map K/V at `0x00b0427c`.
2. Peer tidy `FUN_0051e150` not dual-owned here.
3. Runtime / bit-exact / image diff.

**Verdict:** **accept-with-gaps**

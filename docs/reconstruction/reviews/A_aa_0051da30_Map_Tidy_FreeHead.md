# Review A (reconstruction fidelity): `aa_0051da30` Map_Tidy_FreeHead

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051da30` |
| **VA** | `0x0051da30`–`0x0051da5d` inclusive (**46 B** / exclusive end `0x0051da5e`) |
| **Canonical name** | `Map_Tidy_FreeHead` |
| **Ghidra name** | `FUN_0051da30` |
| **Review date** | `2026-08-04` (WQ9E-J OWN dual) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY WQ9E-J) |
| **Counterpart** | `reviews/B_aa_0051da30_Map_Tidy_FreeHead.md` |
| **System** | MSVC map tidy / free header (host of dualed `Map_EraseRange`) |
| **Evidence pass** | Live Ghidra `decompile_function` / `batch_decompile` + `analyze_function_complete` + `read_memory` (full body) + xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Bare map tidy (no SEH): full-range erase via dualed **`Map_EraseRange`**, free header sentinel, null `head` and `size`. Same 46 B template as dualed `StdTree_Tidy_FreeHead_Bare_Val12` @ `0x0040d6d0`. Called from object teardown of map slot `+0x68` and matching SEH unwind.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ WQ9E-J append) | `docs/reconstruction/raw/aa_0051da30_FUN_0051da30.md` |
| Annotated | `docs/reconstruction/raw/aa_0051da30_FUN_0051da30.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Map_Tidy_FreeHead.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0051da30.cpp` |
| Function record | `docs/reconstruction/functions/aa_0051da30_Map_Tidy_FreeHead.md` |
| Erase range | dualed `Map_EraseRange` / `aa_0051c7c0` (WQ9D-H) |
| Live | decompile truncated after delete; **46 B hex seals null + RET** |

---

## 3. Signature (sealed)

```c
// ECX = map*; bare RET (C3); void
void __fastcall Map_Tidy_FreeHead(MapFacade* map);
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
CALL Map_EraseRange(map, &out, *head, head)   // full-range erase @ 0x0051c7c0
operator_delete(head); ADD ESP,4
[ESI+4] = 0; [ESI+8] = 0
POP ESI; POP ECX; RET
```

| Stage | Match | Conf |
|---|---|---|
| Full-range erase args | Yes (`*head`, `head`) | **Confirmed** |
| Free header only | Yes | **Confirmed** |
| Null head+size after delete | Yes (bytes; decompiler missed) | **Confirmed** |
| Bare RET / no SEH | Yes | **Confirmed** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (46 B):

```
51568bf18b46048b0850518d44240c508bcee879edffff8b4e0451e8d2bdf6ff83c40433c08946048946085e59c3
```

Pad `CC` then next function.

---

## 6. Callers / classification

| Item | Value | Conf |
|---|---|---|
| Code callers | `FUN_00518ec0` (map @ `+0x68` then outer delete); `Unwind@009a8e4c` | **Confirmed** |
| Classification | map tidy / free-head (not scalar deleting dtor of facade) | **High** |
| Product host class | Open | open |

---

## 7. Naming gate

| Evidence | Present? |
|---|---|
| Tidy template (erase full + free head + null) | **Yes** |
| Callee is dualed Map_EraseRange | **Yes** |
| Peer shape StdTree_Tidy_FreeHead_Bare_Val12 | **Yes** (46 B) |
| Product/PDB English | **No** |

**Decision:** promote **`Map_Tidy_FreeHead`** (structural; Map_* family host for isnil@+0x29 `Map_EraseRange`).

---

## 8. Gaps

1. Product English for owning class / map K/V at object `+0x68`.
2. Peer tidies `FUN_0051e150` / `FUN_0051e180` not dual-owned here.
3. Runtime / bit-exact / image diff.

**Verdict:** **accept-with-gaps**

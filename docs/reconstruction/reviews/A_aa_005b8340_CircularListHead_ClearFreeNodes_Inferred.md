# Review A (reconstruction fidelity): `aa_005b8340` CircularListHead_ClearFreeNodes_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b8340` |
| **VA** | `0x005b8340`–`0x005b8369` (**41 B**) |
| **Canonical name** | `CircularListHead_ClearFreeNodes_Inferred` |
| **Ghidra name** | `FUN_005b8340` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W37-AC) |
| **Counterpart** | `reviews/B_aa_005b8340_CircularListHead_ClearFreeNodes_Inferred.md` |
| **System** | circular sentinel list clear (bare node free) |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (full body hex) + 15 xrefs / 5 callers + parent call-site context (`005bbc50`, `004ba0a0`). **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Clear a circular list when **ECX is the head/sentinel node**: re-ring `+0`/`+4` to self, then free every former node reached via `+4` with `operator_delete` until the walk returns to the head. Does **not** free the head. Does **not** run element destructors.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W37-AC append) | `docs/reconstruction/raw/aa_005b8340_FUN_005b8340.md` |
| Annotated | `docs/reconstruction/raw/aa_005b8340_FUN_005b8340.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CircularListHead_ClearFreeNodes_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_005b8340.cpp` |
| Function records | `functions/aa_005b8340_FUN_005b8340.md`, `…_CircularListHead_ClearFreeNodes_Inferred.md` |
| Consumers | W30-S `ObjectMotion_HostTeardown`; W27-D `NDSpecialFX_StopFinalize` residual |
| Live | decompile incomplete on loop; **bytes restore free-loop** |

---

## 3. Signature (sealed)

```c
// ECX = circular list head/sentinel; bare C3; void
void __fastcall CircularListHead_ClearFreeNodes_Inferred(void* head);
```

| Formal | Source | Conf |
|---|---|---|
| head | ECX (`56 8B F1`) | **High** |
| link0 @ +0 / link4 @ +4 | stores + walk | **High** |
| return void / bare `C3` | epilogue | **High** |
| free = cdecl `operator_delete` | `E8…; 83 C4 04` | **High** |

---

## 4. Control flow (bytes authority)

| Stage | Match | Conf |
|---|---|---|
| Save first = [head+4] | `8B 46 04` | **High** |
| Re-ring [+4]=head, [+0]=head | `89 76 04; 89 36` | **High** |
| Null first → return | `85 C0; 74 18` | **High** |
| first==head → return | `3B C6; 74 14` | **High** |
| Loop: next=[node+4]; delete; until head | `8B 78 04 … 75 EE` | **High** |
| delete continues (not noreturn) | `83 C4 04` then loop | **High** |

### Decompile gap

Ghidra marks `operator_delete` noreturn → free-loop **collapsed** to a single delete. Scaffold raw shows the incomplete form. **Bytes win** for multi-node free.

---

## 5. Machine bytes (`read_memory`)

Full body hex (41 B):

```
568bf18b460485c0897604893674183bc67414578b780450e8c514edff83c4043bfe8bc775ee5f5ec3
```

Call target: `operator_delete` @ `0x00489822`. Pad `CC` after `C3`.

---

## 6. Gaps

1. Product/PDB English for node payload type and size beyond link header.
2. Whether `+0` is prev and `+4` is next (MSVC order) — walk uses `+4` only.
3. Per-caller empty invariant (null vs circular).
4. Runtime / bit-exact / differential.

## 7. Verdict

Fidelity pass seals ABI/re-ring/free-loop against full hex; corrects decompiler collapse. Residual product node type → **accept-with-gaps**.

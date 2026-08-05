# Review A (reconstruction fidelity): `aa_0051bc90` ObjectCsList_ClearDestroyNoNode4_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051bc90` |
| **VA** | `0x0051bc90`–`0x0051bd8b` exclusive (**251 B** / `0xFB`) |
| **Canonical name** | `ObjectCsList_ClearDestroyNoNode4_Inferred` |
| **Ghidra name** | `FUN_0051bc90` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W31-S) |
| **Counterpart** | `reviews/B_aa_0051bc90_ObjectCsList_ClearDestroyNoNode4_Inferred.md` |
| **System** | object core / CS-owned list teardown |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + callers/callees/xrefs + `analyze_function_complete`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

CS-protected **clear/destroy all nodes** on Object CS-list used by the list’s own complete/scalar dtors:

1. `EnterCriticalSection(list+4)`.
2. If TraversalLock flag `list+0x28 ≠ 0`: `Leave` + throw `0x80070005`.
3. Walk head `list+0x1C`; next @ `node+8`; scalar-delete `vtbl[0](1)` — **without** clearing `node+4`.
4. Zero `+0x24`, `+0x20`, `+0x1C`.
5. `LeaveCriticalSection`.

Does **not** free the list object or delete the CS (callers `FUN_0051bf10` / `FUN_0051d0e0` do).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W31-S append) | `docs/reconstruction/raw/aa_0051bc90_FUN_0051bc90.md` |
| Annotated | `docs/reconstruction/raw/aa_0051bc90_FUN_0051bc90.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/ObjectCsList_ClearDestroyNoNode4_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0051bc90.cpp` |
| Function records | `functions/aa_0051bc90_FUN_0051bc90.md`, `functions/aa_0051bc90_ObjectCsList_ClearDestroyNoNode4_Inferred.md` |
| Twin | `ObjectCsList_ClearDestroy_Inferred` `0x0051b8a0` (W30-F; **does** `node+4=0`) |
| Live | decompile ≡ raw; body hex sealed; entry `55 8B EC` + chkstk `0x1004`; epilogue `C3` |

---

## 3. Signature (sealed)

```c
// __thiscall/__fastcall; ECX=list*; void; bare RET
void __fastcall ObjectCsList_ClearDestroyNoNode4_Inferred(void *list);
```

| Formal | Source | Conf |
|---|---|---|
| list | ECX (`8B F1`); dtor callers pass `this` list | **High** |
| return | void | **High** |
| cleanup | FS restore + `C3` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ live)

```
SEH LAB_009a3520 + chkstk 0x1004
EnterCS(list+4)
if list+0x28: LeaveCS; throw 0x80070005
while head=list+0x1C:
  head = node->next (+8)
  (*node->vtbl)(1)          // no node+4 write
zero +0x24/+0x20/+0x1C
LeaveCS
RET
```

| Stage | Match | Conf |
|---|---|---|
| EnterCS then flag check | **Yes** | **High** |
| Next @ +8, head update before dtor | **Yes** | **High** |
| No `node+4=0` (vs twin) | **Yes** (body lacks write) | **High** |
| Zero three head fields | **Yes** | **High** |
| LeaveCS / bare RET | **Yes** | **High** |

---

## 5. Call graph

| Role | Address / name |
|---|---|
| Callers | `FUN_0051bf10` (scalar dtor); `FUN_0051d0e0` (complete dtor, two calls) |
| Xrefs | 3 unconditional calls |
| Callees | CS enter/leave; `_CxxThrowException`; `__chkstk`; nested node vtbl |

---

## 6. Gaps

- Product demangle for `009ce154` / `009ce07c` list class.
- Field English `+0x20`/`+0x24`.
- Why SharedBase pre-clear (`0051b8a0`) zeros `node+4` and dtor clear does not.
- Runtime / bit-exact open.

---

## 7. Verdict

CF, ABI, offsets, twin difference, and caller ownership sealed → **accept-with-gaps**.

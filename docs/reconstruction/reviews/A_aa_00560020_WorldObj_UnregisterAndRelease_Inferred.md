# Review A (reconstruction fidelity): `aa_00560020` WorldObj_UnregisterAndRelease_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00560020` |
| **VA** | `0x00560020`–`0x0056010c` |
| **Body** | **237 bytes** (`0xED`) |
| **Canonical name** | `WorldObj_UnregisterAndRelease_Inferred` |
| **Ghidra name** | `FUN_00560020` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W29-S) |
| **Counterpart** | `reviews/B_aa_00560020_WorldObj_UnregisterAndRelease_Inferred.md` |
| **System** | world / phys-link object unenroll + release |
| **Evidence pass** | Live Ghidra decompile + read_memory + get_function_by_address + xrefs/callers/callees + assembly context |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Unregister an enrolled object from the world/link manager:

1. Scope/lock via `0062d960(*(manager+0x234))`.
2. Extract unbind pair-range through `*(manager+0xc4)->vtbl+0xc`.
3. If pairs: `LinkPair_CanonAndSort` + `LinkPair_SortedDiffWalk` (empty left, extracted right; handler `manager+0x138`).
4. `FUN_0062a510(manager, obj)`.
5. Refcount-- at `obj+6`; clear `obj+0x8`; destroy via `vtbl[0](1)` if zero.
6. Swap-remove from `manager+0x120` / `+0x124`.
7. `LocalWorklist_Release` (`0055f4c0`).

Twin of enroll `FUN_0055ff20` (not OWN this dual).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00560020_FUN_00560020.md` (+ W29-S re-verify) |
| Annotated | `docs/reconstruction/raw/aa_00560020_FUN_00560020.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/WorldObj_UnregisterAndRelease_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00560020.cpp` |
| Function record | `docs/reconstruction/functions/aa_00560020_FUN_00560020.md` |
| Named record | `docs/reconstruction/functions/aa_00560020_WorldObj_UnregisterAndRelease_Inferred.md` |
| Live | decompile ≡ raw CF; prologue `83 EC 14 53 56 8B F1`; epilogue `C2 04 00` |
| Related duals | W27-N `006caaa0`/`0055f4c0`; W28-Q `006cad30` |

---

## 3. Signature (sealed)

```c
// thiscall; ECX = manager; stack object*; void; ret 4
void __thiscall WorldObj_UnregisterAndRelease_Inferred(void* manager, void* object);
```

| Formal | Source | Conf |
|---|---|---|
| manager | ECX (`MOV ESI,ECX`) | **High** |
| object | Stack after pushes (`MOV EDI,[esp+…]`) | **High** |
| cleanup | `ret 4` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ live)

```
lock(manager+0x234)
pair_view = (obj==-12) ? null : obj+0x1C
extract vtbl+0xC → (pairs, count) in local out-buf
if count:
  canon_sort(pairs,count)
  sorted_diff_walk(handler=manager+0x138, empty, empty, pairs, count, opt)
notify 0062a510(manager,obj)
ref-- ; obj+8=0 ; if ref==0 destroy(obj,1)
swap_remove manager+0x120
worklist_release
```

| Stage | Match | Conf |
|---|---|---|
| thiscall + ret 4 | **Yes** | **High** |
| Extract + conditional pair path | **Yes** | **High** |
| Refcount / destroy / swap-remove | **Yes** | **High** |
| Handler ECX = manager+0x138 | **Yes** (machine) | **High** |
| unaff residual = out-buf | **Yes** (machine) | **High** |

---

## 5. Machine bytes (`read_memory`)

- Entry `0x00560020`: `83 EC 14 53 56 8B F1 8B 86 34 02 00 00 57 50 … E8 …` → call `0062d960`.
- Extract: `FF 52 0C` (`vtbl+0xc`).
- `006cad30` / `006caaa0` rel32 **Confirmed**; before `006caaa0`: `8B 8E 38 01 00 00` (`ECX=manager+0x138`).
- Epilogue: `5F 5E 5B 83 C4 14 C2 04 00` then `CC`.
- Body **237 B**.

---

## 6. Gaps

- Product English for manager / object classes.
- Nested duals of `0062d960`, `0062a510` (not OWN).
- Full extract out-buffer field map beyond pair ptr+count.
- Runtime / bit-exact — open.

---

## 7. Verdict

CF/ABI/role sealed against bytes + twin enroll shape → **accept-with-gaps** (product names + nested helpers open).

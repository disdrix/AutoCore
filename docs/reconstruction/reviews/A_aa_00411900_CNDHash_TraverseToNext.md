# Review A (reconstruction fidelity): `aa_00411900` CNDHash_TraverseToNext

| Field | Value |
|---|---|
| **Stable ID** | `aa_00411900` |
| **VA** | `0x00411900` |
| **Body** | `0x00411900`–`0x0041194d` (**78** bytes incl. dual `ret 4`; pad `CC`) |
| **Canonical name** | `CNDHash_TraverseToNext` (string-sealed) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00411900_CNDHash_TraverseToNext.md` |
| **System** | container / CNDHash (inventory sheet + skill bar + many) |
| **Live tools** | Ghidra `batch_decompile`, `force_decompile`, `get_function_by_address`, `get_function_callers`, `read_memory` (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose (behavioral)

**CNDHash ordered-list iterator step** under an already-held traversal lock:

1. If `*(this+0x1d) == 0` → log `"HashError:TraverseToNext, not locked for traversal"` + `"VOG_DEBUG_STOP"` (continues; does **not** return early).
2. Cursor `*param_2`:
   - If **0** → seed from list head `*(this+0x14)`; write cursor.
   - Else → advance `cursor = *(cursor+0x14)` (node list-next at **+0x14** on this 0x1c-class node family used by skill hash — see note below).
3. If cursor node non-null → return **payload** `*(node+8)`.
4. Else → return **0**.

Does **not** mutate membership, lock byte, or freelist. Companion of insert/remove twins and TraversalLock helpers.

> **Node layout note:** This Traverse body uses **+0x14** next / **+8** value — the **0x1c mission-style** node used by many skill/mission hashes. Inventory 64-bit insert (`0x00413920`) uses **+0x20/+0x24** list links and **+0xc** value. Same product string family; **node size is not universal**.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Fresh decompile Pass A | Ghidra `batch_decompile` @ `0x00411900` |
| Force re-decompile Pass B | Ghidra `force_decompile` @ `0x00411900` (**identical**) |
| Machine | `read_memory` @ `0x00411900` length 80 |
| Function range | entry `00411900`, body `00411900`–`0041194d` |
| Callers (sample) | `Client_QuickBarActivateSkillSlot` `0x00921b50`, `Client_UpdateNpcInteractIcons`, `FUN_0089bc30`, many more |
| Raw / clean | `raw/aa_00411900_FUN_00411900.md`, `reconstructed-exact/FUN_00411900.cpp` |
| Function record | `functions/aa_00411900_FUN_00411900.md` |

---

## 3. Authoritative body (Ghidra dual A/B 2026-07-29)

**Pass A** ≡ **Pass B**:

```c
undefined4 __thiscall FUN_00411900(int param_1, int *param_2)
{
  int iVar1;

  if (*(char *)(param_1 + 0x1d) == '\0') {
    FUN_007a4480(0, "HashError:TraverseToNext, not locked for traversal");
    FUN_007a4480(0, "VOG_DEBUG_STOP");
  }
  if (*param_2 == 0) {
    *param_2 = *(int *)(param_1 + 0x14);
    iVar1 = *(int *)(param_1 + 0x14);
  }
  else {
    iVar1 = *(int *)(*param_2 + 0x14);
    *param_2 = iVar1;
  }
  if (iVar1 != 0) {
    return *(undefined4 *)(iVar1 + 8);
  }
  return 0;
}
```

---

## 4. Machine seal (`read_memory`)

Hex start: `568bf1807e1d00…` ends `…c20400` + `cccc`.

| Claim | Evidence | Conf |
|---|---|---|
| `__thiscall`; **1 stack arg** cursor*; **`ret 4`** | `mov esi,ecx`; `c2 04 00` | **High** |
| Lock check `this+0x1d` | `cmp byte [esi+0x1d],0` | **Confirmed** |
| Head seed `this+0x14` | `mov eax,[esi+0x14]` | **Confirmed** |
| Advance via `node+0x14` | `mov eax,[eax+0x14]` | **Confirmed** |
| Return payload `node+8` | `mov eax,[eax+8]` | **Confirmed** |
| Dual A/B decompile identity | force ≡ non-force | **High** |

---

## 5. Confidence

| Claim | Level |
|---|---|
| CF sealed dual A≡B ≡ raw | **Confirmed** |
| Product role TraverseToNext | **Confirmed** (string) |
| Requires lock byte set by caller (logs if not) | **High** |
| Returns value ptr, not node | **Confirmed** |
| Universal node layout across all CNDHash VAs | **False** — skill 0x1c vs inv 0x28 |
| Runtime / bit-exact | **Open** |

**Verdict:** **accept-with-gaps.**

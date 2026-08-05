# Review A (reconstruction fidelity): `aa_004e2ca0` FUN_004e2ca0 (leave-FUN)

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e2ca0` |
| **VA** | `0x004e2ca0` |
| **Body** | `0x004e2ca0`–`0x004e2cef` (**`ret 4`**) |
| **Canonical name** | `FUN_004e2ca0` (**retained**) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_004e2ca0_FUN_004e2ca0.md` |
| **System** | hash / free-list (missions + multi-domain) |
| **Live tools** | Ghidra `decompile_function`, `force_decompile`, `analyze_function_complete`, `read_memory` (no `disassemble_bytes`) |
| **Verdict** | **leave-FUN** — CF sealed **High**; product name open |

---

## 1. Purpose (behavioral)

**Unlink-by-key** from a **singly-linked** free-list / hash-bucket chain rooted at `*(this+4)`:

1. `cur = *(this+4)`; `prev = 0`.
2. While `cur != 0` and `*(cur+0x10) != key`: advance `prev = cur`, `cur = *(cur+0xC)`. If next null → integrity walk `FUN_00537d30(this)`, return **0**.
3. On match:
   - If `prev != 0`: `*(prev+0xC) = *(cur+0xC)` (unlink mid/tail).
   - Else: `*(this+4) = *(cur+0xC)` (unlink head).
4. Always call **`FUN_00537d30(this)`** (hash-list integrity / cycle repair — string `"HashListError: Went to node we already touched!…"` inside callee).
5. Return **node pointer** on hit, **0** on miss/empty.

Does **not** free the node heap block — returns it to the caller for further teardown. Used heavily from mission end-quest / objective hash drains (e.g. `Mission_Client_HandleEndQuest` dual cites this path for `char+0x540` / sibling removes).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Fresh decompile | Ghidra `decompile_function` @ `0x004e2ca0` |
| Force re-decompile | Ghidra `force_decompile` @ `0x004e2ca0` (**identical**) |
| Complete analysis | `analyze_function_complete` — **14** xrefs; sole callee `FUN_00537d30` |
| Machine | `read_memory` @ `0x004e2ca0` length 80 |
| Function range | entry `004e2ca0` body `004e2ca0`–`004e2cef` |
| Integrity callee | `FUN_00537d30` decompile (cycle-mark + optional repair log) |
| Raw / clean scaffold | `raw/aa_004e2ca0_*`, `reconstructed-exact/FUN_004e2ca0.cpp` |
| Function record | `functions/aa_004e2ca0_FUN_004e2ca0.md` |

---

## 3. Authoritative body

```c
int __thiscall FUN_004e2ca0(int param_1, int param_2 /* key */)
{
  int *piVar1;
  int iVar2; // prev
  int iVar3; // cur

  iVar3 = *(int *)(param_1 + 4);
  iVar2 = 0;
  if (iVar3 != 0) {
    while (param_2 != *(int *)(iVar3 + 0x10)) {
      piVar1 = (int *)(iVar3 + 0xc);
      iVar2 = iVar3;
      iVar3 = *piVar1;
      if (*piVar1 == 0) {
        FUN_00537d30(); // this in ECX (fastcall/thiscall residual)
        return 0;
      }
    }
    if (iVar3 != 0) {
      if (iVar2 != 0) {
        *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar3 + 0xc);
        FUN_00537d30();
        return iVar3;
      }
      *(undefined4 *)(param_1 + 4) = *(undefined4 *)(iVar3 + 0xc);
    }
  }
  FUN_00537d30();
  return iVar3; // 0 if empty/miss; node* if head hit
}
```

---

## 4. Machine seal (`read_memory`)

Hex (body):  
`56 8b 71 04 33 c0 85 f6 74 3b 8b 54 24 08 … c2 04 00`

| Claim | Evidence | Conf |
|---|---|---|
| `__thiscall` ECX=list; 1 stack key; **`ret 4`** | `mov esi,[ecx+4]`; `mov edx,[esp+8]`; ends `c2 04 00` | **High** |
| Chain head at `this+4` | `8b 71 04` | **High** |
| Key compare at `node+0x10` | `3b 56 10` | **High** |
| Next at `node+0xC` | `8b 76 0c` | **High** |
| Prev-unlink `mov [eax+0xc], edx` | `89 50 0c` mid path | **High** |
| Head-unlink `mov [ecx+4], edx` | `89 51 04` | **High** |
| Always `call FUN_00537d30` before return | three call sites in body | **High** |
| No heap free in this unit | no `operator_delete` / vcall free | **High** |

---

## 5. Node / list contract

| Offset | Role |
|---|---|
| `list+0x04` | head of singly-linked chain |
| `node+0x04` | touch/mark byte used by `FUN_00537d30` (callee) |
| `node+0x0C` | next |
| `node+0x10` | key (mission id / hash key — domain-dependent) |

**Not** the CS doubly-linked list of `FUN_00508490` / `FUN_005085b0`.

---

## 6. Gaps / open

1. Product method name (hash-table remove helper — multi-domain).
2. Full node struct (fields beyond +4/+0xC/+0x10).
3. Whether every caller frees / recycles the returned node (caller-owned).
4. Runtime / differential — open.

**Verdict:** **leave-FUN** (accept CF)

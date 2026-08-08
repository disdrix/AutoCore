# Review A (reconstruction fidelity): `aa_004e52a0` StdTree_EraseRange_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e52a0` |
| **VA** | `0x004e52a0`–`0x004e5353` inclusive (**180 B** / `0xB4`; pad `CC`×12 → `FUN_004e5360`) |
| **Canonical name** | `StdTree_EraseRange_Isnil21_Inferred` |
| **Ghidra name** | `FUN_004e52a0` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Independent reconstruction fidelity (OWN-ONLY dual R13-025 Path A) |
| **Counterpart** | `reviews/B_aa_004e52a0_StdTree_EraseRange_Isnil21_Inferred.md` |
| **System** | skills-abilities / STL map-set helpers (isnil@+0x21 family) |
| **Live tools** | `decompile_function`, `analyze_function_complete`, `get_function_callers`, `get_function_xrefs`, `get_xrefs_to`, `read_memory`, `get_function_by_address` |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** — R13 residual; parent dual `0x004e3e70` erase+rebalance |
| **Terminal** | **false** |

**Tools note:** No `disassemble_bytes`. No Launcher. No parent ledgers.

---

## 1. Purpose

MSVC-style `_Tree::erase(first, last)` range shell for the **isnil@+0x21** red-black node family (node **0x28**, color@**+0x20**, Val16 payload @+0x10):

```c
// __thiscall  RET 0x0C  void (out-it via stack)
void StdTree_EraseRange_Isnil21_Inferred(
    /*ECX*/ MapShell_Isnil21 *map,
    MapNode_Isnil21 **outIt,
    MapNode_Isnil21 *first,
    MapNode_Isnil21 *last);
```

1. If `[first, last) == [head->left, head)` → free entire tree via `FUN_004e2e40(head->parent)`; reset sentinel links; `size=0`; `*outIt=head->left`.
2. Else while `first != last`: compute in-order successor (isnil@+0x21); call single erase `FUN_004e3e70(map, &slot, first)`; advance to successor.
3. `*outIt = first` (end iterator after partial erase).

**Does not:** implement RB rebalance itself; free individual nodes outside callees; use Val12 isnil@+0x19 offsets.

**Callers (2):** `FUN_004da160` @ `0x004da2b4` (clear after populate); `FUN_004e73f0` @ `0x004e7402` (erase-all + delete head).

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ raw 2026-07-23 CF (full free + partial successor+erase) |
| Live body bytes | full 180 B + `CC` pad via `read_memory` |
| Parent dual | `aa_004e3e70` `StdTree_EraseAndRebalance_Isnil21_Inferred` (R12-013) |
| Free callee | `FUN_004e2e40` isnil21 free-subtree (`RET 4`) |
| Sibling clone | `FUN_004e4e10` same CF/size; free=`FUN_004e2e00` (R13-024 OWN) |
| Val12 peer | `aa_0040d700` `StdTree_EraseRange_Val12` (isnil@+0x19; 180 B twin shape) |
| Callers | `FUN_004da160`, `FUN_004e73f0` (both full-range style) |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Authoritative body (bytes)

Prologue / full-range gate:

```text
004e52a0  PUSH EBX
004e52a1  MOV  EBX, [ESP+0x10]     ; last
004e52a5  PUSH ESI
004e52a6  MOV  ESI, [ESP+0x10]     ; first
004e52aa  PUSH EDI
004e52ab  MOV  EDI, ECX            ; map
004e52ad  MOV  EAX, [EDI+4]        ; head
004e52b0  CMP  ESI, [EAX]          ; first == head->left?
004e52b2  JNZ  partial
004e52b4  CMP  EBX, EAX            ; last  == head?
004e52b6  JNZ  partial
004e52b8  MOV  EAX, [EAX+4]        ; head->parent (root)
004e52bb  PUSH EAX
004e52bc  CALL FUN_004e2e40        ; free subtree
... head reset; size=0; *outIt = head->left ...
          RET  0x0C
```

Partial erase call site:

```text
004e5337  PUSH ECX                 ; node (first)
004e5338  LEA  EAX, [ESP+0x18]     ; &first slot
004e533c  PUSH EAX
004e533d  MOV  ECX, EDI            ; map
004e533f  CALL FUN_004e3e70        ; single erase+rebalance
...
004e534e  RET  0x0C
```

Entry 64 B hex:

```text
538b5c2410568b742410578bf98b47043b3075363bd875328b400450e87fdbffff8b47048940048b4704c747080000000089008b47048940088b4f048b118b44
```

Epilogue:

```text
8b4424105f89305e5bc20c00
```

---

## 4. Sealed facts

| # | Fact | Evidence |
|---|---|---|
| 1 | Body **180 B** / `0xB4` | `get_function_by_address` + full hex count |
| 2 | `__thiscall` + **RET 0x0C** | both exits `C2 0C 00` |
| 3 | isnil@**+0x21** successor | `CMP byte [reg+0x21], 0` throughout partial path |
| 4 | Full free `004e2e40` | call @ `0x004e52bc` → `0x004e2e40` |
| 5 | Single erase `004e3e70` | call @ `0x004e533f` → `0x004e3e70` (parent dual) |
| 6 | Two callers only | xrefs `004da2b4`, `004e7402` |
| 7 | Live decompile ≡ raw CF | 2026-08-05 re-decompile |
| 8 | Name `StdTree_EraseRange_Isnil21_Inferred` | family vocabulary + parent erase dual |

---

## 5. Gaps

- Product / PDB English for owning `map<K,V>` (callers use local shells + insert `004e48b0`).
- Residual dual of free `004e2e40` and sibling range `004e4e10` (other agents).
- Bit-exact golden vs MSVC `_Tree::erase` range.
- Runtime / differential.

---

## 6. Verdict

**accept-with-gaps** — ABI, CF, layout, callees, callers, and size sealed from decompile + bytes. Product demangle open. Name is **Inferred** only.

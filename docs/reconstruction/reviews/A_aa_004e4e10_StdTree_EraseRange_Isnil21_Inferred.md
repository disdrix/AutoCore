# Review A (reconstruction fidelity): `aa_004e4e10` StdTree_EraseRange_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e4e10` |
| **VA** | `0x004e4e10`–`0x004e4ec4` exclusive (**180 B** / `0xB4`; pad `CC`×12 → `0x004e4ed0`) |
| **Canonical name** | `StdTree_EraseRange_Isnil21_Inferred` |
| **Ghidra name** | `FUN_004e4e10` |
| **Prior alias** | `Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004e4e10` (**reject** as product id) |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Independent reconstruction fidelity (OWN-ONLY dual R13-024 Path A) |
| **Counterpart** | `reviews/B_aa_004e4e10_StdTree_EraseRange_Isnil21_Inferred.md` |
| **System** | skills-abilities / STL map-set helpers (isnil@+0x21 family) |
| **Live tools** | `decompile_function`, `analyze_function_complete`, `get_function_callers`, `get_function_xrefs`, `read_memory`, `batch_decompile` (callees) |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** — R13 residual; parent dual `0x004e3e70` erase |
| **Terminal** | **false** |
| **Dual start** | 2686 |

**Tools note:** No `disassemble_bytes`. No Launcher. No parent ledgers.

---

## 1. Purpose

MSVC-style `_Tree::erase(const_iterator first, const_iterator last)` for the **isnil@+0x21** red-black node family (node **0x28**, color@**+0x20**, Val16 payload @+0x10):

```c
// __thiscall  RET 0x0C  void (out-it via stack)
void StdTree_EraseRange_Isnil21_Inferred(
    /*ECX*/ MapShell_Isnil21 *map,
    MapNode_Isnil21 **outIt,
    MapNode_Isnil21 *first,
    MapNode_Isnil21 *last);
```

1. **Full clear** when `first == head->left && last == head`:
   - `FUN_004e2e00(head->parent)` free non-nil subtree of root
   - reset head L/P/R to self; `size = 0`; `*outIt = head->left`
2. **Partial range**: while `first != last`, precompute successor (isnil@+0x21), call parent dual `StdTree_EraseAndRebalance_Isnil21_Inferred(map, &first, first)`, advance to successor.
3. `*outIt = first` (end of erased range).

**Does not:** single-node RB rebalance itself (delegates); free whole tree without head reset; use Val12 isnil@+0x19.

**Caller (1):** map clear shell `FUN_004e7320` @ `0x004e7332`.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ raw 2026-07-23 CF (full-clear + successor + erase loop) |
| Live body bytes | entry 64 B + full 180 B body + both `ret 0xc` + `CC` pad |
| Parent dual | `aa_004e3e70` `StdTree_EraseAndRebalance_Isnil21_Inferred` (R12-013) |
| Free callee | `FUN_004e2e00` (isnil@+0x21 free-subtree; residual left-recurse) |
| Peer twin | `FUN_004e52a0` (same erase; free `FUN_004e2e40`) |
| Val12 peer | `StdMap_EraseRange_Val12` @ `0x004e5120` |
| Isnil29 peer | `StdTree_EraseRange_Isnil29_Inferred` @ `0x004cbaa0` (same 180 B shape) |
| Sole caller | `FUN_004e7320` live decompile (clear + delete head) |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Authoritative body (bytes)

Prologue / full-clear gate:

```text
004e4e10  PUSH EBX
004e4e11  MOV  EBX, [ESP+0x10]     ; last
004e4e15  PUSH ESI
004e4e16  MOV  ESI, [ESP+0x10]     ; first
004e4e1a  PUSH EDI
004e4e1b  MOV  EDI, ECX            ; this = map
004e4e1d  MOV  EAX, [EDI+4]        ; head
004e4e20  CMP  ESI, [EAX]          ; first == head->left?
004e4e22  JNZ  partial
004e4e24  CMP  EBX, EAX            ; last == head?
004e4e26  JNZ  partial
004e4e28  MOV  EAX, [EAX+4]        ; root
004e4e2b  PUSH EAX
004e4e2c  CALL FUN_004e2e00
          ... head reset, size=0 ...
004e4e52  POP  EDI / POP ESI
004e4e54  MOV  [outIt], EDX
004e4e56  POP  EBX
004e4e57  RET  0x0C                ; C2 0C 00
```

Partial erase call site:

```text
004e4ea7  PUSH ESI                 ; node = first
004e4ea8  LEA  EAX, [ESP+0x18]     ; &first (out-it for erase)
004e4eac  PUSH EAX
004e4ead  MOV  ECX, EDI            ; map
004e4eaf  CALL FUN_004e3e70
...
004e4eb8  MOV  EAX, [ESP+0x10]
004e4ebc  POP  EDI
004e4ebd  MOV  [EAX], ESI          ; *outIt = first
004e4ebf  POP  ESI / POP EBX
004e4ec1  RET  0x0C
004e4ec4  CC pad ×12 → 004e4ed0
```

Entry hex (64 B):  
`538b5c2410568b742410578bf98b47043b3075363bd875328b400450e8cfdfffff8b47048940048b4704c747080000000089008b47048940088b4f048b118b44`

Full body hex (180 B): see raw re-verify append.

---

## 4. Layout (this body)

| Off | Field | Role |
|---|---|---|
| map`+0x04` | head* | end sentinel; root@head+4; L@head+0; R@head+8 |
| map`+0x08` | size | zeroed on full clear |
| node`+0x00` | left* | |
| node`+0x04` | parent* | |
| node`+0x08` | right* | |
| node`+0x10` | Val16 payload | not touched here |
| node`+0x20` | color | used inside erase only |
| node`+0x21` | isnil | successor tests |

---

## 5. Naming

| Candidate | Decision |
|---|---|
| `StdTree_EraseRange_Isnil21_Inferred` | **Accept** — matches isnil21 erase parent + Isnil29 range vocabulary |
| `StdMap_EraseRange_Isnil21` | Acceptable alias; prefer StdTree form (pairs EraseAndRebalance) |
| `FUN_004e4e10` | scaffold |
| Named_CalleeOf VOG_DEBUG_STOP | **Reject** product identity |

---

## 6. Confidence

| Claim | Level |
|---|---|
| CF dual A ≡ raw ≡ live | **Confirmed** |
| `__thiscall` + **RET 0x0C** both exits | **Confirmed** (bytes) |
| isnil@+0x21 successor | **Confirmed** |
| Full free `004e2e00` + erase `004e3e70` | **Confirmed** |
| Sole caller `004e7320` (1 xref) | **Confirmed** |
| Role range erase shell | **High** |
| Product/PDB English / demangled map T | **Open** (`_Inferred`) |
| Free-subtree full algebra of `004e2e00` | **Open** (residual) |
| Runtime / bit-exact / differential | **Open** |

**Verdict:** **accept-with-gaps.**

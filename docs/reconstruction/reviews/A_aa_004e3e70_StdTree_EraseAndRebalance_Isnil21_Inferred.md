# Review A (reconstruction fidelity): `aa_004e3e70` StdTree_EraseAndRebalance_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e3e70` |
| **VA** | `0x004e3e70`–`0x004e4126` exclusive (**694 B** / `0x2B6`; pad `CC`×10 → `FUN_004e4130`) |
| **Canonical name** | `StdTree_EraseAndRebalance_Isnil21_Inferred` |
| **Ghidra name** | `FUN_004e3e70` |
| **Prior alias** | `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_004e3e70` (**reject** as product id) |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Independent reconstruction fidelity (OWN-ONLY dual R12-013 Path A) |
| **Counterpart** | `reviews/B_aa_004e3e70_StdTree_EraseAndRebalance_Isnil21_Inferred.md` |
| **System** | skills-abilities / STL map-set helpers (isnil@+0x21 family) |
| **Live tools** | `decompile_function`, `analyze_function_complete`, `get_function_callers`, `get_function_xrefs`, `read_memory`, `batch_decompile` (callees) |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** — R12 residual; parent dual `0x005a27f0` Rrotate |
| **Terminal** | **false** |

**Tools note:** No `disassemble_bytes`. No Launcher. No parent ledgers.

---

## 1. Purpose

MSVC-style `_Tree::erase(const_iterator)` for the **isnil@+0x21** red-black node family (node **0x28**, color@**+0x20**, Val16 payload @+0x10):

```c
// __thiscall  RET 8  void (out-it via stack)
void StdTree_EraseAndRebalance_Isnil21_Inferred(
    /*ECX*/ MapShell_Isnil21 *map,
    MapNode_Isnil21 **outIt,
    MapNode_Isnil21 *node);
```

1. If `node->isnil (+0x21)` → throw `"invalid map/set<T> iterator"`.
2. `FUN_004e12c0` — successor prep for `*outIt`.
3. Splice replacement child; fix root / leftmost (`FUN_004cb2c0`) / rightmost (`FUN_00421a60`).
4. If erased color black (`+0x20 == 1`) → RB fixup with Lrotate `FUN_0050e9f0` / Rrotate `FUN_005a27f0`.
5. `operator_delete(node)`; if `size(+0x08)>0` then `--size`; `*outIt = successor`; **`ret 8`**.

**Does not:** free whole tree; destroy value via vtbl (plain node delete); range-loop (callers do).

**Callers (2):** EraseRange shells `FUN_004e4e10` @ `0x004e4eaf`, `FUN_004e52a0` @ `0x004e533f`.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ raw 2026-07-23 CF (throw/splice/RB); epilogue from bytes |
| Live body bytes | entry 64 B + epilogue through `ret 8` + `CC` pad |
| Insert twin | `aa_00407200` `StdTree_InsertAndRebalance_Isnil21_Inferred` (WQ9I-B) |
| Peer Val12 erase | `aa_004e4130` `StdTree_EraseAndRebalance_Val12` (isnil@+0x19; different rotates) |
| Parent dual | `FUN_005a27f0` Rrotate isnil21 (partition parent) |
| L rotate | `FUN_0050e9f0` (isnil@+0x21) |
| Successor | `FUN_004e12c0` isnil21 nextnode |
| Callers | `FUN_004e4e10`, `FUN_004e52a0` (both walk range → this erase) |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Authoritative body (bytes)

Prologue / isnil throw:

```text
004e3e70  MOV  EAX, FS:[0]
004e3e76  PUSH -1
004e3e78  PUSH LAB_009a1e62
...
004e3e8c  CMP  byte [EAX+0x21], 0     ; isnil
004e3e90  PUSH EBP
004e3e91  MOV  EBP, ECX               ; this = map
004e3e93  JZ   continue
004e3e95  PUSH "invalid map/set<T> iterator"  ; 00a152f0
          ... _CxxThrowException(DAT_00acc34c)
```

Epilogue (decomp misses — sealed from `read_memory`):

```text
          PUSH node; CALL operator_delete
          MOV  EAX, [EBP+8]           ; size
          ...
          JBE  skip                   ; size==0
          ADD  EAX, -1                ; size--
          MOV  [EBP+8], EAX
          MOV  [outIt*], successor
          ADD  ESP, 0x54
004e4123  RET  8                      ; C2 08 00
004e4126  CC pad → 004e4130
```

Entry hex (64 B):  
`64a1000000006aff68621e9a00508b4424146489250000000083ec4880782100558be9745968f052a1008d4c240cff15f8629c008d4c2424c744245400000000`

Epilogue tail hex:  
`8b44241050e82b57faff8b450883c40485c05f5e5b760683c0ff8945088b4c24608b44245c89088b4c244c5d64890d0000000083c454c20800`

---

## 4. Layout (this body)

| Off | Field | Role |
|---|---|---|
| map`+0x04` | head* | end sentinel; root@head+4; L@head+0; R@head+8 |
| map`+0x08` | size | decremented after delete |
| node`+0x00` | left* | |
| node`+0x04` | parent* | |
| node`+0x08` | right* | |
| node`+0x10` | Val16 payload | not touched (POD / no dtor here) |
| node`+0x20` | color | 0=red, 1=black |
| node`+0x21` | isnil | throw if non-zero |

---

## 5. Naming

| Candidate | Decision |
|---|---|
| `StdTree_EraseAndRebalance_Isnil21_Inferred` | **Accept** — matches isnil21 insert twin + Isnil29/31 erase family vocabulary |
| `StdMap_EraseIterator_Isnil21` | Acceptable alias; prefer EraseAndRebalance form (rebalance in body) |
| `FUN_004e3e70` | scaffold |
| Named_CalleeOf VOG_DEBUG_ST | **Reject** product identity |

---

## 6. Confidence

| Claim | Level |
|---|---|
| CF dual A ≡ raw ≡ live (throw/splice/RB) | **Confirmed** |
| `__thiscall` + **RET 8** + size-- + `*outIt` | **Confirmed** (bytes) |
| isnil@+0x21 / color@+0x20 | **Confirmed** |
| Throw string + ThrowInfo | **Confirmed** |
| Callers `004e4e10` + `004e52a0` only (2 xrefs) | **Confirmed** |
| Rotates `0050e9f0` / `005a27f0` | **Confirmed** |
| Role single-node erase+rebalance | **High** |
| Product/PDB English / demangled map T | **Open** (`_Inferred`) |
| Runtime / bit-exact / differential | **Open** |

**Verdict:** **accept-with-gaps.**

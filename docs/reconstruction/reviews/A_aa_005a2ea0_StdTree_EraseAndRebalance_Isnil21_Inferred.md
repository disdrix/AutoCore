# Review A (reconstruction fidelity): `aa_005a2ea0` StdTree_EraseAndRebalance_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a2ea0` |
| **VA** | `0x005a2ea0`–`0x005a3155` inclusive (**694 B** / `0x2B6`; pad `CC` @ `0x005a3156`) |
| **Canonical name** | `StdTree_EraseAndRebalance_Isnil21_Inferred` |
| **Ghidra name** | `FUN_005a2ea0` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Independent reconstruction fidelity (OWN-ONLY dual R12-030 Path A) |
| **Counterpart** | `reviews/B_aa_005a2ea0_StdTree_EraseAndRebalance_Isnil21_Inferred.md` |
| **System** | skills-abilities / STL map-set helpers (isnil@+0x21 family) |
| **Live tools** | `decompile_function`, `analyze_function_complete`, `get_function_callers`, `get_function_xrefs`, `get_function_callees`, `disassemble_function`, `get_assembly_context`, `read_memory` |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** — R12 residual; parent dual `0x005a27f0` Rrotate |
| **Terminal** | **false** |

**Tools note:** No `disassemble_bytes`. No Launcher. No parent ledgers. Never Runtime Confirmed.

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

**Callers / xrefs (2):** `FUN_005a3860` @ `0x005a38ff` (EraseRange); orphan @ `0x005a052b`.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ raw 2026-07-23 CF (throw/splice/RB); epilogue from bytes |
| Live body bytes | entry 80 B + epilogue through `ret 8` + `CC` pad (full 694 B) |
| Insert twin | `aa_00407200` `StdTree_InsertAndRebalance_Isnil21_Inferred` (WQ9I-B) |
| Peer erase clones | `00405650` (R12-009), `004e3e70` (R12-013, 694 B reloc-near-identical) |
| Parent dual | `FUN_005a27f0` Rrotate isnil21 (R11-007) |
| L rotate | `FUN_0050e9f0` (isnil@+0x21) |
| Successor | `FUN_004e12c0` isnil21 nextnode |
| Callers | `FUN_005a3860` (range); orphan shell @ `005a052b` |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Authoritative body (bytes)

Prologue / isnil throw:

```text
005a2ea0  MOV  EAX, FS:[0]
005a2ea6  PUSH -1
005a2ea8  PUSH LAB_009a6342
...
005a2ebc  CMP  byte [EAX+0x21], 0     ; isnil
005a2ec0  PUSH EBP
005a2ec1  MOV  EBP, ECX               ; this = map
005a2ec3  JZ   continue
005a2ec5  PUSH "invalid map/set<T> iterator"  ; 00a152f0
          ... _CxxThrowException(DAT_00acc34c)
```

Epilogue (decomp misses — sealed from `read_memory` @ `005a311d`):

```text
005a311d  MOV  EAX, [ESP+0x10]        ; node
005a3121  PUSH EAX
005a3122  CALL operator_delete        ; 00489822
          MOV  EAX, [EBP+8]           ; size
          ADD  ESP, 4
          TEST EAX, EAX
          POP  EDI / ESI / EBX
          JBE  skip                   ; size==0
          ADD  EAX, -1                ; size--
          MOV  [EBP+8], EAX
          MOV  [outIt*], successor
          ADD  ESP, 0x54
005a3153  RET  8                      ; C2 08 00
005a3156  CC pad
```

Entry hex (80 B):  
`64a1000000006aff6842639a00508b4424146489250000000083ec4880782100558be9745968f052a1008d4c240cff15f8629c008d4c2424c744245400000000ff1560669c008d442408508d4c2434c6`

Epilogue tail hex:  
`8b44241050e8fb66eeff8b450883c40485c05f5e5b760683c0ff8945088b4c24608b44245c89088b4c244c5d64890d0000000083c454c20800`

---

## 4. Layout (this body)

| Off | Field | Role |
|---|---|---|
| map`+0x04` | head* | end sentinel; root@head+4; L@head+0; R@head+8 |
| map`+0x08` | size | decremented after delete |
| node`+0x00` | left* | |
| node`+0x04` | parent* | |
| node`+0x08` | right* | |
| node`+0x10` | Val16 payload | not destroyed here (POD path) |
| node`+0x20` | color | 0=red, 1=black |
| node`+0x21` | isnil | throw if non-zero |

---

## 5. Naming

| Evidence | Present? |
|---|---|
| `"invalid map/set<T> iterator"` plate | **Yes** |
| Classical erase + RB with dualed isnil21 rotates | **Yes** |
| Insert twin dualed (`00407200`) | **Yes** |
| Product / RTTI demangle of map value_type | **No** → `_Inferred` |

**Name:** `StdTree_EraseAndRebalance_Isnil21_Inferred` — structural family vocabulary; not skill-domain exclusive.

---

## 6. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw CF (throw/splice/RB) | **pass** |
| Body size 694 B / inclusive end `005a3155` | **pass** |
| `ret 8` / 2 stack args / thiscall | **pass** |
| isnil throw string | **pass** |
| size-- after delete | **pass** (bytes; decomp miss) |
| `*outIt` write | **pass** (bytes) |
| RB uses isnil21 L/R rotate | **pass** |
| Min/max isnil21 extremities | **pass** |
| Clean meaningful names | **pass** (`FUN_005a2ea0.cpp`) |
| Product demangle of map | **gap** |
| Orphan caller full recovery | **gap** |

---

## 7. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI | **High** | live ≡ raw; ret 8 sealed |
| isnil@+0x21 node layout | **High** | match min/max/rotates + insert twin |
| Callers (2 xrefs) | **High** | xrefs + assembly context |
| Name `…_Isnil21_Inferred` | **Inferred** | structural; not plate/RTTI product |
| Runtime / differential | Open | |

---

## 8. Gaps

1. Product demangle for map value_type of `FUN_005a3860` / orphan host.  
2. Full function recovery for orphan site `005a052b` (DATA `009d7f0c`).  
3. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**

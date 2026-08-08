# Review B (skeptical / adversarial): `aa_00402850` StdTree_EraseAndRebalance_Isnil29_RetC_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00402850` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (MEGA-034) |
| **Counterpart** | `reviews/A_aa_00402850_StdTree_EraseAndRebalance_Isnil29_RetC_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` + `disassemble_function` + callers/xrefs (no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Decompiler `void` + noreturn delete is full body | **Falsified** — bytes continue: size--, `*outIt`, `ret 0xC` |
| 2 | isnil/color at +0x31/+0x30 (isnil31 family) | **Falsified** — this unit uses **+0x29 / +0x28** |
| 3 | Same binary as isnil29 thiscall erase `0x004cb740` | **Falsified** — different rotates (`00407a60`/`00403200` vs `004192a0`/`004192f0`), ABI (RET0xC stack vs thiscall RET8) |
| 4 | Same as Val28 isnil29 erase `0x00603830` | **Falsified** — no mapped-heap dtor; stack RET 0xC vs thiscall RET 8 |
| 5 | Same as isnil31 erase `0x00408ed0` | **Falsified** — isnil offset + rotate/min/iter helpers differ (same ABI shape only) |
| 6 | Function is input-key handler (`Named_CalleeOf_OnKeyDown`) | **Falsified** — STL tree erase; OnKeyDown is one **caller** only |
| 7 | Function frees whole tree / range | **Falsified** — single-node erase; range is parent loops |
| 8 | ECX-thiscall primary | **Falsified** — **3 stack args**, `ret 0x0C` |
| 9 | No size update on erase | **Falsified** — epilogue `--size` when size>0 |
| 10 | `param_2` unused dead formal | **Falsified** — out-iterator store in epilogue |
| 11 | Must destroy string key / value | **Falsified** — bare `operator_delete` only |
| 12 | Role is tree min / rotate only | **Falsified as sole role** — this is **erase** that *calls* min/rotate |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Single-node erase (not clear) | **High** | double-free / corruption |
| ABI ret 0xC / 3 stack args | **High** | stack smash |
| isnil@+0x29 layout | **High** | map corruption |
| size-- epilogue | **High** | size drift |
| Multiple callers (input + range + host maps) | **High** | missing specialization |
| Family vs thiscall isnil29 / isnil31 / Val28 | **High** | wrong rotate/dtor/ABI |
| Product English | Medium | naming only |
| Two-child splice plate exactness | Med | rare path only |

---

## 3. Cross-check against raw + bytes

```
if node->isnil(+0x29) → throw "invalid map/set<T> iterator"
FUN_004040a0(); splice; fix root/L/R extremity (min 004031e0 / max 004031c0)
if erased black → RB recolor/rotate (isnil29 L/R 00407a60/00403200)
operator_delete(node);  // no value dtor
if size>0 size--; *outIt=succ; ret 0xC
```

Clean must **not** invent range loops, freelist recycle, isnil31 rotates, thiscall RET8 ABI, value dtor, or OnKeyDown product semantics.

---

## 4. Surviving contract for AutoCore

```csharp
// Erase one isnil29 tree node by pointer (stack ABI)
void EraseAndRebalance_Isnil29_RetC(MapShell map, ref Node outIt, Node node)
{
    if (node.IsNil) throw new InvalidOperationException("invalid map/set<T> iterator");
    var succ = PrepSuccessor_Isnil29(node); // FUN_004040a0
    UnlinkAndRebalance(map, node);          // isnil29 L/R rotate helpers 00407a60/00403200
    Delete(node);                           // no value dtor
    if (map.Size > 0) map.Size--;
    outIt = succ;
}
```

Port must keep **isnil@+0x29** / **color@+0x28** and call the RetC-family rotate/min/iter pair (not thiscall isnil29 `004cb740` helpers, not isnil31 family).

---

## 5. Open questions

1. Exact demangled map type for host maps (`0x00d1b564`, host+0xd24).  
2. Value payload English (POD sealed; fields open).  
3. Runtime / bit-exact.

**Verdict:** **accept-with-gaps**

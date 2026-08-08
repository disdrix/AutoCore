# Review B (skeptical / adversarial): `aa_004cbaa0` StdTree_EraseRange_Isnil29_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cbaa0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (WQ9F-C) |
| **Counterpart** | `reviews/A_aa_004cbaa0_StdTree_EraseRange_Isnil29_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` + xrefs (no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Same binary as `Map_EraseRange` `0x0051c7c0` | **Falsified** — free `004cb550` vs `0051bbc0`; erase `004cb740` vs `Map_EraseNode` `0051cb40`; different VA |
| 2 | Same as `Map_EraseRange_B` | **Falsified** — free `0051be90` on B; this unit uses `004cb550` |
| 3 | Single-node only (no range) | **Falsified** — loops erase; full-clear path |
| 4 | isnil@+0x15 / +0x1d / Val12 | **Falsified** — successor immediates **+0x29** |
| 5 | VOG_DEBUG_STOP scaffold is product role | **Narrow** — shared STL range helper; multi-caller |
| 6 | Decompiler void return hides stack cleanup | **Falsified for ABI** — both exits `C2 0C 00` |
| 7 | Free path leaves size non-zero | **Falsified** — size written 0 on full clear |
| 8 | Erase called without map ECX | **Falsified** — bytes `MOV ECX,EDI` before `CALL 004cb740` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Range erase role | **High** | wrong API surface |
| RET 0x0C thiscall | **High** | stack smash |
| isnil@+0x29 | **High** | map corruption |
| Free/erase callee pair | **High** | merge with skill-bank twins |
| Product English | Medium | naming only |
| Free-subtree completeness | Med | double-free / leak residual |

---

## 3. Cross-check against raw + bytes

```
if first==begin && last==end:
  free_subtree(root); reset head; size=0; *outIt=begin; ret 0xc
while first!=last:
  succ = successor_isnil29(first)
  erase_rebalance(map, &first, first)  // 004cb740
  first = succ
*outIt = first; ret 0xc
```

Clean must **not** invent Val12 isnil offsets, merge with `Map_EraseRange*`, or drop full-clear size zeroing.

---

## 4. Surviving contract for AutoCore

```csharp
// Erase [first, last) on isnil@+0x29 tree; parent owns uniqueness
void EraseRange(MapShell map, ref Node outIt, Node first, Node last)
{
    if (first == map.Begin && last == map.End) {
        FreeSubtree(map.Root); // FUN_004cb550
        map.ResetEmpty();
        outIt = map.Begin;
        return;
    }
    while (first != last) {
        var succ = SuccessorIsnil29(first);
        EraseAndRebalance(map, ref first, first); // 004cb740
        first = succ;
    }
    outIt = first;
}
```

Port must keep **this free/erase pair** (not Map_EraseRange's `0051bbc0`/`Map_EraseNode`).

---

## 5. Open questions

1. Exact demangled map type of callers (`FUN_004cc3d0` shell dtor, creature dtor map, `FUN_004ea350`).  
2. Whether `FUN_004cb550` left-recurses (decomp drops left).  
3. Runtime / bit-exact.

**Verdict:** **accept-with-gaps**

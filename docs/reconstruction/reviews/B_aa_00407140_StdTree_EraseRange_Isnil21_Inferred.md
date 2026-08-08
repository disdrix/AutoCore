# Review B (skeptical / adversarial): `aa_00407140` StdTree_EraseRange_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00407140` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (R13-016; dual start **2686**) |
| **Counterpart** | `reviews/A_aa_00407140_StdTree_EraseRange_Isnil21_Inferred.md` |
| **Parent dual** | `0x00405650` StdTree_EraseAndRebalance_Isnil21_Inferred |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context` (**no** `disassemble_bytes`). No Launcher.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Same binary as isnil29 range `0x004cbaa0` | **Falsified** — free `00406710` vs `004cb550`; erase `00405650` vs `004cb740`; isnil `+0x21` vs `+0x29`; different VA |
| 2 | Same as isnil11 range `0x00441960` | **Falsified** — different isnil plate + callee pair |
| 3 | Same as `Map_EraseRange` / `_B` | **Falsified** — different free + single-erase callees |
| 4 | Single-node only (no range) | **Falsified** — loops erase; full-clear path; range is this unit (parent erase is single) |
| 5 | isnil@+0x29 / +0x15 / +0x1d / Val12 | **Falsified** — successor immediates **+0x21** |
| 6 | This is the single erase unit `00405650` | **Falsified** — calls `00405650`; own RET 0xC vs erase RET 8 |
| 7 | cdecl / bare RET / RET 8 | **Falsified** — both exits `C2 0C 00`; ECX=map thiscall |
| 8 | Free path leaves size non-zero | **Falsified** — size written 0 on full clear |
| 9 | Erase called without map ECX | **Falsified** — bytes `MOV ECX,EDI` before `CALL 00405650` |
| 10 | Product skill/ability method | **Falsified as name** — generic STL; partition skills-abilities is queue system only |
| 11 | Runtime Confirmed | **Falsified / not claimed** — static dual only; no Launcher |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Range erase role | **High** | wrong API surface |
| RET 0x0C thiscall | **High** | stack smash |
| isnil@+0x21 | **High** | map corruption |
| Free/erase callee pair | **High** | merge with isnil29 / Map_EraseRange twins |
| Product English | Medium | naming only |
| Free-subtree completeness | Med | double-free / leak residual |
| Runtime / differential | Open | not sealed — never Runtime Confirmed |

---

## 3. Cross-check against raw + bytes

```
if first==begin && last==end:
  free_subtree(root); reset head; size=0; *outIt=begin; ret 0xc
while first!=last:
  succ = successor_isnil21(first)
  erase_rebalance(map, &first, first)  // 00405650
  first = succ
*outIt = first; ret 0xc
```

Clean must **not** invent Val12/isnil29 offsets, merge with `Map_EraseRange*` or isnil29 range, drop full-clear size zeroing, or claim Runtime Confirmed.

---

## 4. Surviving contract for AutoCore

```csharp
// Erase [first, last) on isnil@+0x21 tree; parent owns uniqueness
void EraseRange(MapShell map, ref Node outIt, Node first, Node last)
{
    if (first == map.Begin && last == map.End) {
        FreeSubtree(map.Root); // FUN_00406710
        map.ResetEmpty();
        outIt = map.Begin;
        return;
    }
    while (first != last) {
        var succ = SuccessorIsnil21(first);
        EraseAndRebalance(map, ref first, first); // 00405650
        first = succ;
    }
    outIt = first;
}
```

Port must keep **this free/erase pair** (`00406710` / `00405650`) and isnil@+0x21 — not the isnil29 pair (`004cb550` / `004cb740`).

---

## 5. Open questions

1. Exact demangled map type of tidy callers (`FUN_00405290`, `FUN_00405620`) and host map at `FUN_004ffe60` (`ESI-0x3B4`).  
2. Whether `FUN_00406710` left-recurses (decomp shows right-only + delete).  
3. Runtime / bit-exact / differential (deferred).

**Verdict:** **accept-with-gaps**

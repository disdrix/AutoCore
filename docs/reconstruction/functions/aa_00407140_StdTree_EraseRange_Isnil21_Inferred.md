# Function record: StdTree_EraseRange_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00407140` |
| **Canonical name** | `StdTree_EraseRange_Isnil21_Inferred` (**Inferred** structural + isnil plate + parent erase dual) |
| **Ghidra name** | `FUN_00407140` |
| **Address** | `0x00407140`–`0x004071f4` exclusive (**180 B** / `0xB4`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities — MSVC `std::_Tree` range erase (isnil@+0x21) |
| **Classification** | worker (shared map range erase) |
| **Agent** | R13-016 OWN-ONLY dual 2026-08-05 (dual start **2686**) |
| **Parent dual** | `0x00405650` StdTree_EraseAndRebalance_Isnil21_Inferred (R12-009) |
| **Completion status** | **accept-with-gaps** — dual A/B sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual verdict** | **accept-with-gaps** |
| **Terminal** | **false** |

## Alias

- `FUN_00407140` (Ghidra)

## Purpose

MSVC red-black **range erase** `[first, last)` for nodes with **color@+0x20** and **isnil@+0x21** (node size **0x28**). Full clear frees via residual `FUN_00406710`; partial erase loops dualed `StdTree_EraseAndRebalance_Isnil21_Inferred` (`0x00405650`). Writes end iterator to `*outIt`. Both exits **RET 0x0C**.

Shape twin of dualed isnil29 range erase `0x004cbaa0` (180 B / RET 0xC) but **different isnil offset and free/erase callees** — do **not** merge.

## Signature (byte-sealed)

```c
void __thiscall StdTree_EraseRange_Isnil21_Inferred(
    MapShell_Isnil21 *map,      // ECX — head @ +4, size @ +8
    MapNode_Isnil21 **outIt,    // stack0
    MapNode_Isnil21 *first,     // stack1 inclusive
    MapNode_Isnil21 *last);     // stack2 exclusive
// RET 0x0C
```

## Layout

| Offset | Field |
|---|---|
| +0x00 | left |
| +0x04 | parent |
| +0x08 | right |
| +0x0C..+0x1F | value payload (trivial in erase path — no value dtor) |
| +0x20 | color |
| +0x21 | isnil |
| size | **0x28** |

Shell: `head@+4`, `size@+8`.

## Call graph

| Role | Target |
|---|---|
| **Callers (3)** | `FUN_00405290` @ `0x004052c3`; `FUN_00405620` @ `0x00405632`; `FUN_004ffe60` @ `0x00500162` |
| Free subtree | `FUN_00406710` (isnil21 residual — not dualled here) |
| Single erase | `StdTree_EraseAndRebalance_Isnil21_Inferred` @ `0x00405650` (R12-009) |

## Evidence summary

- Live decompile ≡ raw CF; both exits `C2 0C 00` sealed via `read_memory` + `disassemble_function`.
- isnil successor immediates `+0x21` (`80 7E 21 00` / `80 78 21 00`).
- Call sites: `MOV ECX,<map>` + 3× PUSH → thiscall RET 0xC; tidy callers free head after.
- Parent erase dual R12-009 seals single-node plate (isnil21 / color20 / node 0x28 / ret 8).
- Do **not** merge with isnil29 range `004cbaa0`, isnil11 range `00441960`, or Map_EraseRange* families.

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/StdTree_EraseRange_Isnil21_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00407140.cpp`
- Raw: `docs/reconstruction/raw/aa_00407140_FUN_00407140.md`
- Annotated: `docs/reconstruction/raw/aa_00407140_FUN_00407140.annotated.md`
- Review A: `docs/reconstruction/reviews/A_aa_00407140_StdTree_EraseRange_Isnil21_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00407140_StdTree_EraseRange_Isnil21_Inferred.md`
- Machine record: `docs/reconstruction/functions/aa_00407140_FUN_00407140.md`
- Report: `docs/agents/task-dual-ab-00407140-r13-report.md`

## Confidence

| Claim | Level |
|---|---|
| STL range-erase role | **High** (structural) |
| ABI thiscall + ret 0x0c + isnil@+0x21 | **High** |
| Free/erase callee pair vs isnil29 / Map_EraseRange* | **High** |
| Product/PDB English / K/V | Open (`_Inferred`) |
| Runtime / image diff | Open — **not** Runtime Confirmed |

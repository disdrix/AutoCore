# Review A (reconstruction fidelity): `aa_00539150` MissionStagingTree_EraseRange

| Field | Value |
|---|---|
| **Stable ID** | `aa_00539150` |
| **VA** | `0x00539150` |
| **Body** | `0x00539150`–`0x00539203` |
| **Canonical name** | `MissionStagingTree_EraseRange` (role-sealed; product English open) |
| **Ghidra name** | `FUN_00539150` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00539150_MissionStagingTree_EraseRange.md` |
| **System** | `missions-progression` |
| **Parent chain** | Peers `MissionStagingTree_DestroySubtree` / `EraseNode`; char dtor + map clear |
| **Dual status** | **Present** (W24-L first full A+B dual) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + `get_assembly_context` + `get_xrefs_to`. No `disassemble_bytes`. No Launcher.

---

## 1. Purpose

**Erase a half-open range** of mission-staging tree nodes `[first, last)`:

1. `this` (ECX) = map (`header` at `+4`, `size` at `+8`).
2. Stack: `outIter*`, `first`, `last`; epilogue **`ret 0xc`**.
3. If full range (`first == *header` leftmost and `last == header`): bulk `DestroySubtree(header[1])`, re-init header self-links, `size=0`, `*out=begin`.
4. Else: while `first != last`, compute **tree successor** (nil at `+0x49`), `EraseNode(node)`, advance.

Does **not** touch CNDHash tables at char `+0x538/+0x540/+0x548` — only the staging map.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00539150_FUN_00539150.md` |
| Annotated | `docs/reconstruction/raw/aa_00539150_FUN_00539150.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/MissionStagingTree_EraseRange.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_00539150.cpp` |
| Function record | `docs/reconstruction/functions/aa_00539150_FUN_00539150.md` |
| Live decompile | `decompile_function` / `analyze_function_complete` @ `0x00539150` |
| Entry bytes | `read_memory` 48 B — push ebx/esi/edi, load last/first, ECX=this |
| Epilogue bytes | `read_memory` @ `0x005391f0` — `*out=cur; ret 0xc` |
| Call sites | `0x0053ae82` (`FUN_0053ae70`); `0x0052f607` (char dtor, map `char+0x508`) |

**Not performed:** `disassemble_bytes`, Launcher, runtime.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Role = map range erase | **High** | CF + callees DestroySubtree/EraseNode |
| ABI thiscall + ret 0xc | **High** | entry/epilogue bytes |
| Full-clear arm when `[begin,end)==[leftmost,header]` | **High** | body + `FUN_0053ae70` call pattern |
| Selective arm = successor + EraseNode | **High** | body |
| Nil flag `+0x49` | **High** | peers + body |
| Map on mission char path = `+0x508` | **High** | `0x0052f607` LEA (`ESI-0x898` with adj-this `+0xda0`) |
| Product / PDB name | **Open** | |
| Exact left/parent/right polarity | **Probable** | MSVC Dinkumware |
| Runtime | **Open** | |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Raw | Clean | Live |
|---|---|---|---|
| Full-clear gate | Y | Y | Y |
| DestroySubtree + header reset + size0 | Y | Y | Y |
| Successor walk | Y | Y | Y |
| EraseNode per node | Y | Y | Y |
| *out = final | Y | Y | Y |
| Invented branches | — | **None** | **None** |

---

## 5. Gaps

1. Product English for staging map type.
2. Formal MSVC `_Tree_nod` field names.
3. Ghidra function body for containing char-dtor fragment around `0x0052f607` is split (call still live in image).
4. Runtime / bit-exact / differential — open.

**Verdict:** Role + ABI + dual-path CF **High**. **accept-with-gaps.**

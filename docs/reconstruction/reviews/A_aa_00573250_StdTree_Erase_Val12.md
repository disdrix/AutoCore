# Review A (reconstruction fidelity): `aa_00573250` StdTree_Erase_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_00573250` |
| **VA** | `0x00573250` |
| **Body** | `0x00573250`–`0x00573506` exclusive (**694** B) |
| **Canonical name** | `StdTree_Erase_Val12` (inferred) |
| **Ghidra symbol** | `FUN_00573250` |
| **Review date** | `2026-07-29` (W27-S OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00573250_StdTree_Erase_Val12.md` |
| **System** | std map/set tree single-node erase |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, meta/xrefs (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Erase one non-nil Val12 RB tree node; publish successor; decrement size.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00573250_FUN_00573250.md` (+ W27-S append) |
| Annotated | `docs/reconstruction/raw/aa_00573250_FUN_00573250.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Erase_Val12.cpp` |
| Scaffold | `reconstructed-exact/FUN_00573250.cpp` |
| Function record | `docs/reconstruction/functions/aa_00573250_StdTree_Erase_Val12.md` |
| Live decompile | ≡ raw CF |
| Live body bytes | `read_memory` entry + post-delete epilogue + string |
| Peer | `aa_0051cb40` Map_EraseNode (different isnil offset) |
| Rotates | W26-Q StdTree_L/Rrotate_Val12 |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Prologue | SEH (`LAB_009a4fc2`); load node; `cmp byte [node+0x19],0` |
| True body end | exclusive `0x00573506` (pad `cc` after `ret 8`) |
| Ghidra plate end | `0x005734d6` **false** — `operator_delete` not noreturn |
| Epilogue | `size--` if `size>0`; `*outIt=succ`; `add esp,0x54; ret 8` |
| String | `"invalid map/set<T> iterator"` @ `0x00a152f0` |
| ThrowInfo | `DAT_00acc34c` |
| Color / isnil | +0x18 / +0x19 (Val12) |

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw CF | **pass** |
| True body size / ret 8 | **pass** (bytes) |
| thiscall ECX=map | **pass** (callers) |
| isnil throw string | **pass** |
| Val12 layout | **pass** |
| Post-delete size-- | **pass** (bytes; decomp omits) |
| RB rotates called | **pass** (`FUN_00573170` / `FUN_00418c10`) |
| Two-child path complete in decomp | **gap** (unreachable warnings) |

---

## 5. Gaps (non-blocking)

1. Product/MSVC demangle for map type using this erase.  
2. Full reconstruction of Ghidra-"unreachable" transplant blocks.  
3. Runtime / bit-exact / differential.

---

## 6. Verdict rationale

**accept-with-gaps** — ABI, throw, Val12 layout, unlink/fixup callees, and post-delete tail are sealed from live decompile + bytes. Gaps are product naming and two-child path decompiler noise, not ABI risk.

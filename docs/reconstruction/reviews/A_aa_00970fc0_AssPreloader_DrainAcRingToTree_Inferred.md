# Review A (reconstruction fidelity): `aa_00970fc0` AssPreloader_DrainAcRingToTree_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00970fc0` |
| **VA** | `0x00970fc0`–`0x00971024` inclusive (**101 B** / `0x65`) |
| **Canonical name** | `AssPreloader_DrainAcRingToTree_Inferred` |
| **Ghidra name** | `FUN_00970fc0` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W37-AD) |
| **Counterpart** | `reviews/B_aa_00970fc0_AssPreloader_DrainAcRingToTree_Inferred.md` |
| **System** | assPreloader / asset preload pipeline |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` (full body + pads) + `get_xrefs_to` + callee decompiles. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Drain AssPreloader locked ring **host+0xAC** of `{u32 key, u8 flag}` entries into membership tree **host+0xDC**: success flag marks tree value **1** via find-or-insert; fail flag invokes sole-caller helper `FUN_0043d770`. Host in **EAX**. Pre-loop drain for child-asset preload (W32-J) and preload worker (W32-K).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W37-AD append) | `docs/reconstruction/raw/aa_00970fc0_FUN_00970fc0.md` |
| Annotated | `docs/reconstruction/raw/aa_00970fc0_FUN_00970fc0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/AssPreloader_DrainAcRingToTree_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00970fc0.cpp` |
| Function records | `functions/aa_00970fc0_FUN_00970fc0.md`, `functions/aa_00970fc0_AssPreloader_DrainAcRingToTree_Inferred.md` |
| Caller duals | W32-J `00971280`, W32-K `00972140` |
| Live | decompile CF + body hex `55 8B EC 83 E4 F8…C3` |

---

## 3. Signature (sealed)

```c
// EAX = AssPreloader* host; bare RET; void
void AssPreloader_DrainAcRingToTree_Inferred(void /*EAX=host*/);
```

| Formal | Source | Conf |
|---|---|---|
| host | EAX (`8B D8` after pushes) | **High** |
| stack args | none (bare `C3`) | **High** |
| return | void (no AL/EAX product) | **High** |

---

## 4. Control flow (clean ≡ bytes; decompiler corrected)

```
local = {0,0}                 // FUN_0043d6f0(EAX=&local)
ring  = host+0xAC             // ESI
if (!RingPop(ring, &local)) return   // FUN_0043e850 → AL
tree  = host+0xDC             // ADD EBX,0xDC once
loop:
  if local.flag == 0:
    FUN_0043d770()            // EAX=tree, ECX=&key
  else:
    *FUN_0043d700(&key) = 1   // ECX=key*, EDI=tree
  if (!RingPop(ring, &local)) break
```

| Stage | Match | Conf |
|---|---|---|
| Body 101 B / pad CC | **Yes** (`read_memory`) | **High** |
| Host EAX | **Yes** (both call sites `MOV EAX,EBP`) | **High** |
| Ring +0xAC | **Yes** (`LEA ESI,[EBX+0xAC]`) | **High** |
| Tree +0xDC once | **Yes** (`ADD EBX,0xDC` after first hit) | **High** |
| Flag@+4 branch | **Yes** (`CMP [ESP+0x14],0`) | **High** |
| Value store 1 | **Yes** (`C7 00 01 00 00 00`) | **High** |
| 2 callers | **Yes** (xrefs) | **High** |

---

## 5. Gaps

- Product/PDB method English for this drain.
- Nested product duals: `FUN_0043e850` ring pop, `FUN_0043d700` find-or-insert, `FUN_0043d770` fail path (not owned).
- Flag polarity English beyond structural success/fail used by known pushers.
- Runtime / bit-exact / differential.

---

## 6. Verdict

Fidelity pass seals host-in-EAX ABI, body bounds, ring/tree offsets, flag branch, and set-value-1 success path. Residual product English + nested helpers → **accept-with-gaps**.

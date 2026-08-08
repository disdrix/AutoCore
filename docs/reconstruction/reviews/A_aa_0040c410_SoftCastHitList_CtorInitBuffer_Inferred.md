# Review A (reconstruction fidelity): `aa_0040c410` SoftCastHitList_CtorInitBuffer_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040c410` |
| **VA** | `0x0040c410`–`0x0040c4df` inclusive (**208 B** / `0xD0`) |
| **Canonical name** | `SoftCastHitList_CtorInitBuffer_Inferred` |
| **Ghidra name** | `FUN_0040c410` |
| **Prior scaffold** | `FUN_0040c410` (2026-07-23 trio) |
| **Rejected misname** | no `Named_CalleeOf_*` present; reject ECX-thiscall, heap-allocating ctor, skill-hit ctor, runtime Confirmed |
| **Review date** | `2026-08-05` (MEGA-111 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_0040c410_SoftCastHitList_CtorInitBuffer_Inferred.md` |
| **System** | interaction-activation (soft-cast hit list) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + `get_function_callers` / `get_function_callees` + `get_xrefs_to` / `get_xrefs_from` + `get_function_by_address` + `get_function_signature` + parent hub callee/call-site context. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

**Constructor / buffer init** for the soft-cast hit-list object used by world-click interaction:

```text
SoftCastHitList_CtorInitBuffer_Inferred(self)   // stack self*, RET 4
  self.vtbl = base then final (a2f52c → a2f538)
  self+0x04 = 1.0f
  self+0x10 = &inline[0]   // self+0x20
  self+0x14 = count = 0
  self+0x18 = 0x80000008   // cap 8 | inline high-bit
  for i in 0..7:
    elem[i].key@+0x14 = 1.0f
    elem[i].slot@+0x20 = 0
  reassert count=0, +0x04=1.0f
```

Sole retail caller: dualed **`Client_InteractWorldClickHub`** (`0x00925820`) @ `0x00925c06` — stack-construct before soft-cast fill (`FUN_0055e1e0`) and sort (`SoftCastHitList_SortIfCountGt1_Inferred` / MEGA-116).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ MEGA-111 append) | `docs/reconstruction/raw/aa_0040c410_FUN_0040c410.md` |
| Annotated | `docs/reconstruction/raw/aa_0040c410_FUN_0040c410.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/SoftCastHitList_CtorInitBuffer_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0040c410.cpp` |
| Function record | `docs/reconstruction/functions/aa_0040c410_FUN_0040c410.md` |
| Named record | `docs/reconstruction/functions/aa_0040c410_SoftCastHitList_CtorInitBuffer_Inferred.md` |
| Live | decompile ≡ scaffold CF; body hex 208 B; 1 CALL xref; leaf; `RET 4` |
| Parent hub | dualed `Client_InteractWorldClickHub` (W17-C) |
| Sort sibling | dualed `SoftCastHitList_SortIfCountGt1_Inferred` (MEGA-116) |
| Dtor twin | `FUN_0040c510` (elem `*0x30` free size; high-bit skip) |

---

## 3. Signature (sealed)

```c
// stack SoftCastHitList* self; void; RET 4
void __stdcall SoftCastHitList_CtorInitBuffer_Inferred(SoftCastHitList *self);
```

| Slot | Source | Conf |
|---|---|---|
| self | stack arg0 — `MOV EAX,[ESP+0x14]` after SEH | **Confirmed** |
| ECX-this | **not used** for object | **Confirmed** |
| return | void; no EAX contract | **Confirmed** |
| cleanup | **`RET 4`** (`C2 04 00`) | **Confirmed** |
| callees | none (leaf) | **Confirmed** |

**Note:** Decompiler prints `void FUN_0040c410(undefined4 *param_1)` without `__stdcall`; assembly seals stack this + `RET 4`.

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| SEH install (`-1`, `0x009bd03d`, FS:[0]) | **Yes** | **Confirmed** |
| Load self from stack | **Yes** | **Confirmed** |
| Load `g_flOne` via MOVSS from `0x00a0f2a0` | **Yes** (`00 00 80 3f`) | **Confirmed** |
| Temp vtbl `a2f52c` then final `a2f538` | **Yes** | **Confirmed** |
| Header: begin=`self+0x20`, count=0, cap=`0x80000008` | **Yes** | **Confirmed** |
| 8× slot seeds float+0x14 / zero+0x20 stride 0x30 | **Yes** (net offsets ≡ decompiler indices) | **Confirmed** |
| Reassert count / +0x04 | **Yes** | **Confirmed** |
| SEH teardown + `RET 4` | **Yes** | **Confirmed** |
| No branches / no callees | **Yes** (1 BB, complexity 1) | **Confirmed** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | leaf constructor / buffer init |
| External callers | **1** — `FUN_00925820` / `Client_InteractWorldClickHub` |
| Xref count | **1** UNCONDITIONAL_CALL @ `0x00925c06` |
| Callees | none |
| Site role | stack-construct hit list before soft-cast fill + sort + walk + dtor |

---

## 6. Naming gate

| Candidate | Result |
|---|---|
| `SoftCastHitList_CtorInitBuffer_Inferred` | **Accepted** — sole hub caller; layout matches dualed sort sibling; dtor confirms 0x30/inline cap |
| Product demangled class name | **Open** — no RTTI string on this unit; `_Inferred` required |
| `Named_CalleeOf_*` | **N/A** — not present for this VA |

---

## 7. Gaps

1. Product English for SoftCastHitList class and float fields (container +0x04 / key +0x14).  
2. Full final-vtbl method English beyond scalar dtor + grow pattern.  
3. Runtime / bit-exact / differential — open.

---

## 8. Verdict

CF/ABI/`RET 4`/vtbl pair/inline buffer header/8×0x30 seeds/sole hub caller sealed. Product residual only → **accept-with-gaps**. Terminal **false**.

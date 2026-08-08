# Review A (reconstruction fidelity): `aa_004e2b80` StdTree_Buynode_Val16_Isnil21_Inline_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e2b80` |
| **VA** | `0x004e2b80` |
| **Body** | `0x004e2b80`–`0x004e2bce` inclusive (**79** B / `0x4F`) |
| **Canonical name** | `StdTree_Buynode_Val16_Isnil21_Inline_Inferred` |
| **Ghidra symbol** | `FUN_004e2b80` |
| **Review date** | `2026-08-05` (R13-004 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_004e2b80_StdTree_Buynode_Val16_Isnil21_Inline_Inferred.md` |
| **System** | skills-abilities (partition); body = STL / map-set buynode |
| **Parent dual** | `0x004e37e0` `StdTree_InsertAndRebalance_Val16_Isnil21_Inferred` (R12-012) |
| **Dual start** | 2686 |
| **Terminal** | **false** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` entry/epilogue + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Allocate and construct one **isnil@+0x21** tree node with **Val16** payload for insert/rebalance `FUN_004e37e0` (and peer `FUN_005a3500`). Construct is **inlined** after `operator_new(0x28)` — no SEH, no separate NodeCtor.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ R13-004 re-verify) | `docs/reconstruction/raw/aa_004e2b80_FUN_004e2b80.md` |
| Annotated | `docs/reconstruction/raw/aa_004e2b80_FUN_004e2b80.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Buynode_Val16_Isnil21_Inline_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_004e2b80.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGReaction_Updat_004e2b80.cpp` |
| Function record | `docs/reconstruction/functions/aa_004e2b80_StdTree_Buynode_Val16_Isnil21_Inline_Inferred.md` |
| Live body | `disassemble_function` + `read_memory` @ `0x004e2b80` / epilogue `C2 14 00` |
| Parent insert | dualed `FUN_004e37e0` call site `0x004e3872` |
| Peer insert | residual `FUN_005a3500` call site `0x005a3592` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 79 B + `ret 0x14` | **Confirmed** | disasm + `read_memory` epilogue `C2 14 00` |
| `__stdcall` 5 stack args; EAX return | **Confirmed** | disasm; callers `MOV ECX,EAX`; no ECX this on entry |
| `operator_new(0x28)` | **Confirmed** | `PUSH 0x28` + call |
| Links left/parent/right @+0/+4/+8 | **Confirmed** | disasm stores |
| Val16 (4 dwords) @+0x10 from `*param_4` | **Confirmed** | LEA +0x10 + 4 dword copies |
| color@+0x20 + isnil0@+0x21 | **Confirmed** | `MOV [EAX+0x20],DL` / `MOV byte [EAX+0x21],0` |
| +0x0C not written | **Confirmed** | no store between +8 and +0x10 |
| No SEH / no NodeCtor call | **Confirmed** | leaf body; sole callee = `operator_new` |
| Callers (2): `004e37e0`, `005a3500` | **Confirmed** | 2 UNCONDITIONAL_CALL xrefs |
| Parent dual color arg **0** (red) | **Confirmed** | call-site `PUSH 0` before CALL |
| Distinct from peer `00408990` (SEH+ctor) | **Confirmed** | body size/CF differ; same layout family |
| Not CNDHash freelist | **Confirmed** | CRT new + tree field writes |
| Product / PDB demangle | **Open** | `_Inferred` |
| Runtime / bit-exact / differential | **Open** | deferred; never Runtime Confirmed |

---

## 4. Control flow: raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| `PUSH 0x28` → `operator_new` → `ADD ESP,4` | **Yes** |
| null skip / else field stores | **Yes** |
| return node in EAX; RET 0x14 | **Yes** (decompiler void is display gap only) |

---

## 5. Naming gate

| Evidence | Present? |
|---|---|
| Node size 0x28 + isnil@+0x21 | **Yes** |
| Val16 (4 dwords) inline | **Yes** |
| Parent insert color@+0x20 | **Yes** |
| Inline (no SEH/ctor helper) differentiator | **Yes** |
| Product/PDB English | **No** |

**Decision:** promote **`StdTree_Buynode_Val16_Isnil21_Inline_Inferred`** (structural High; English unproven). Reject freelist/CNDHash/CVOGReaction chain scaffold; reject Val24/isnil29 merge; reject merge with SEH peer `00408990` (keep clone name distinct).

---

## 6. Gaps

1. Product/PDB symbol.
2. Dual of peer insert `FUN_005a3500` (not OWN).
3. Runtime / bit-exact / image diff.

**Verdict:** **accept-with-gaps**

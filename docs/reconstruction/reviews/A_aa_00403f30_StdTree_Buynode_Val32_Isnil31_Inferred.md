# Review A (reconstruction fidelity): `aa_00403f30` StdTree_Buynode_Val32_Isnil31_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00403f30` |
| **VA** | `0x00403f30` |
| **Body** | `0x00403f30`–`0x00403fb2` exclusive (**130** B / `0x82`) |
| **Canonical name** | `StdTree_Buynode_Val32_Isnil31_Inferred` |
| **Ghidra symbol** | `FUN_00403f30` |
| **Review date** | `2026-08-05` (MEGA-048 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00403f30_StdTree_Buynode_Val32_Isnil31_Inferred.md` |
| **System** | STL / map-set buynode (partition: missions-progression) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra HTTP `127.0.0.1:8089` — `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs/callees. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Allocate and construct one **isnil@+0x31** tree node (**size 0x38**) with **Val32** (8-dword) payload for the residual insert/rebalance path `FUN_00403250` (isnil31 family nested under dualed `Client_NotifyActiveMissionChanged` call chain).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ MEGA-048 re-verify) | `docs/reconstruction/raw/aa_00403f30_FUN_00403f30.md` |
| Annotated | `docs/reconstruction/raw/aa_00403f30_FUN_00403f30.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Buynode_Val32_Isnil31_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_00403f30.cpp` |
| Function record | `docs/reconstruction/functions/aa_00403f30_StdTree_Buynode_Val32_Isnil31_Inferred.md` |
| Live body | `disassemble_function` + `read_memory` @ `0x00403f30` / epilogue `C2 14 00` |
| Ctor | `FUN_00404360` decompile + disasm (`REP MOVSD` ECX=8; isnil@+0x31) |
| Parent insert | `FUN_00403250` decompile + call-site @ `0x004032b6` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 130 B + `ret 0x14` | **Confirmed** | disasm ends `RET 0x14`; hex `C2 14 00` |
| `__stdcall` 5 stack args; EAX return | **Confirmed** | no ECX this; caller `MOV ECX,EAX` after CALL |
| `operator_new(0x38)` | **Confirmed** | `PUSH 0x38` + call `00489892` |
| Ctor links + 8 dwords + color + isnil0 | **Confirmed** | ctor disasm `MOVSD.REP` ECX=8; color@+0x30; isnil=0@+0x31 |
| Sole caller insert `00403250` | **Confirmed** | 1 xref / 1 caller |
| SEH frame present | **Confirmed** | FS:[0] / `LAB_009bc781` |
| Decompiler ctor-arg elision | **Confirmed** | raw shows 3 stack args; asm passes 5 + EAX-in-EAX |
| isnil31 / 0x38 family | **Confirmed** | matches dualed Lrot/erase/BuyHead peers |
| Product / PDB demangle | **Open** | `_Inferred` |
| Runtime / bit-exact / differential | **Open** | deferred |

---

## 4. Control flow: raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| SEH setup → new(0x38) | **Yes** |
| null skip / else ctor | **Yes** |
| return node in EAX; RET 0x14 | **Yes** |

---

## 5. Naming gate

| Evidence | Present? |
|---|---|
| Node size 0x38 + isnil@+0x31 family | **Yes** |
| Val32 (8 dwords) from ctor | **Yes** |
| Parent insert sole caller | **Yes** |
| Product/PDB English | **No** |

**Decision:** promote **`StdTree_Buynode_Val32_Isnil31_Inferred`** (structural High; English unproven). Reject chain-of-caller `Named_CalleeOf_*NotifyActiveMission*` scaffold; reject Val24 isnil29 buynode merge (`00407e30`); reject BuyHead merge (`00409180` — no value copy).

---

## 6. Gaps

1. Product/PDB symbol for host map value_type.
2. Full dual of ctor `FUN_00404360` and insert parent `FUN_00403250` (not OWN; MEGA-047 owns insert).
3. Runtime / bit-exact / image diff.

**Verdict:** **accept-with-gaps**

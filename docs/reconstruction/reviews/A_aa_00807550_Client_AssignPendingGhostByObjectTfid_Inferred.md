# Review A (reconstruction fidelity): `aa_00807550` Client_AssignPendingGhostByObjectTfid_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00807550` |
| **VA** | `0x00807550`–`0x008075cb` exclusive (**123 B** / `0x7B`) |
| **Canonical name** | `Client_AssignPendingGhostByObjectTfid_Inferred` |
| **Ghidra symbol** | `FUN_00807550` |
| **Review date** | `2026-08-04` (WQ9H-G OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00807550_Client_AssignPendingGhostByObjectTfid_Inferred.md` |
| **System** | client net / pending ghost map (TFID) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` / `analyze_function_complete` / `disassemble_function` + `read_memory` (full body hex, string) + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

TFID map **consumer**: find pending-ghost entry by object's TFID (`object+0x160`), and when hit with `payload+0x5c==0`, log assignment, call object vtbl `+0x2b8` with payload, then erase the node.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ WQ9H-G append) | `docs/reconstruction/raw/aa_00807550_FUN_00807550.md` |
| Annotated | `docs/reconstruction/raw/aa_00807550_FUN_00807550.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_AssignPendingGhostByObjectTfid_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_00807550.cpp` |
| Live body | full hex sealed; epilogue **`C2 04 00`** |
| Dualed find | `aa_004cba00` StdMap_Find_Tfid_Isnil29 (WQ9G-G) |
| Dualed erase | `aa_00409220` Map_EraseNode_B (WQ9E-G) |
| String | `0x00a7f548` `"Assigned a pending ghost to %I64d"` |
| Callers | `Client_CreateVehicleObjectApply` (×3), `FUN_0080af70` (×1) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 123 B; **`RET 4`** | **Confirmed** | bytes `C2 04 00` |
| **EAX** = host; stack = object* | **Confirmed** | entry `MOV ECX,[EAX+0xc78]`; `MOV EBP,[ESP+8]` |
| Map at manager `+0x244`; head `map+4` | **Confirmed** | `LEA ESI,[EAX+0x244]`; `CMP EBX,[ESI+4]` |
| Key at object `+0x160` (TFID) | **Confirmed** | `LEA EDI,[EBP+0x160]`; string `%I64d` |
| Find via dualed `004cba00` | **Confirmed** | `CALL` + ECX=map |
| Erase via dualed `00409220` | **Confirmed** | after assign |
| Gate payload `+0x5c == 0` | **Confirmed** | `CMP dword [ECX+0x5c],0` |
| Product class / vtbl English | **Tentative** | `_Inferred` |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| manager = vtbl+0x48 on host+0xc78; null → ret | Yes |
| find(map@+0x244, key@object+0x160) | Yes |
| end/miss → ret | Yes |
| payload+0x5c != 0 → ret | Yes |
| log + vtbl+0x2b8(payload) + erase | Yes |
| RET 4 | Yes |

---

## 5. Naming

| Candidate | Ruling |
|---|---|
| `FUN_00807550` | Scaffold only |
| `Named_CalleeOf_Client_CreateVehicleObjectApply_*` | **Reject** — scaffold chain; under-describes |
| `Net_Assigned_pending_ghost_I64d` (plate only) | Partial — log string only; not full CF |
| `StdMap_Find_Tfid_*` (this VA) | **Reject** — find is child `004cba00`; this is consumer |
| `Client_AssignPendingGhostByObjectTfid_Inferred` | **Accept** — find+assign+erase + plate string; English Inferred |

---

## 6. Gaps

1. Product host/manager/payload class names.  
2. Semantics of object vtbl `+0x2b8` and manager vtbl `+0x48`.  
3. Meaning of payload field `+0x5c` (assigned flag).  
4. Full dual of callers (not OWN).  
5. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**

# Review A (reconstruction fidelity): `aa_004099b0` StdTree_NodeCtor_Val16_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004099b0` |
| **VA** | `0x004099b0` |
| **Body** | `0x004099b0`–`0x004099f3` exclusive (**67** B / `0x43`) |
| **Canonical name** | `StdTree_NodeCtor_Val16_Isnil21_Inferred` (inferred) |
| **Ghidra symbol** | `FUN_004099b0` |
| **Review date** | `2026-08-05` (WQ9I-C OWN-ONLY dual) |
| **Reviewer role** | Path A — fidelity |
| **Counterpart** | `reviews/B_aa_004099b0_StdTree_NodeCtor_Val16_Isnil21_Inferred.md` |
| **System** | std tree node construct (Val16 / isnil21) |
| **Live tools** | decompile + read_memory + analyze + callers/xrefs + disassemble_function (**no** disassemble_bytes) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Thiscall node constructor for the **isnil@+0x21 / Val16 / size 0x28** family. Called only from dualed buynode `StdTree_Buynode_Val16_Isnil21_Inferred` (`0x00408990`) after `operator_new(0x28)`. Writes L/P/R, copies 16-byte value, sets color, forces isnil=0.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ WQ9I-C append) | `docs/reconstruction/raw/aa_004099b0_FUN_004099b0.md` |
| Annotated | `docs/reconstruction/raw/aa_004099b0_FUN_004099b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_NodeCtor_Val16_Isnil21_Inferred.cpp` |
| Scaffold twin | `reconstructed-exact/FUN_004099b0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004099b0_StdTree_NodeCtor_Val16_Isnil21_Inferred.md` |
| Parent dual | `aa_00408990` StdTree_Buynode_Val16_Isnil21_Inferred (WQ9H-J) |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Entry | `8B 54 24 08` / `8B C1` — parent load; **EAX=this** |
| Links | stores to `[EAX]`, `[EAX+4]`, `[EAX+8]` |
| Val16 | `LEA EDX,[EAX+0x10]` + four dword copies |
| Color | `88 50 20` — `MOV [EAX+0x20],DL` |
| isnil | `C6 40 21 00` — force **0** |
| RET | `C2 14 00` (**RET 0x14**) |
| Body end | exclusive `0x004099f3`; pad `CC` |

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw CF | **pass** |
| Body size | **pass** (67 B) |
| RET 0x14 thiscall | **pass** |
| Val16 @+0x10..+0x1c | **pass** |
| color@+0x20 / isnil@+0x21=0 | **pass** |
| +0x0c untouched | **pass** |
| EAX returns this | **pass** (entry MOV EAX,ECX) |
| Product value_type English | **gap** |
| Runtime | **open** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI + layout | **High** | full leaf sealed |
| Role node ctor for buynode | **High** | single caller |
| Name `_Inferred` | **Inferred** | product open |
| Runtime | Open | low risk leaf |

---

## 6. Gaps (acceptable)

1. Product demangle for 4-dword value_type.  
2. Runtime / bit-exact (optional for trivial leaf).

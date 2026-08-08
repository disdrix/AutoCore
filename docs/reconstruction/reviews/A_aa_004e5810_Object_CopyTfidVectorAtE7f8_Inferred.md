# Review A (reconstruction fidelity): `aa_004e5810` Object_CopyTfidVectorAtE7f8_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e5810` |
| **VA** | `0x004e5810`–`0x004e5833` exclusive (**35** B / `0x23`) |
| **Canonical name** | `Object_CopyTfidVectorAtE7f8_Inferred` |
| **Ghidra name** | `FUN_004e5810` |
| **Prior scaffold** | `FUN_004e5810` / `Named_CalleeOf_*RefreshOpen*_004e5810` |
| **Review date** | `2026-08-05` (R13-026 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_004e5810_Object_CopyTfidVectorAtE7f8_Inferred.md` |
| **System** | inventory-transfer — object TFID vector materialize (partition parent craft gate `0x0052eb90`) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Thin **object thiscall** that materializes a temporary **TFID-pair vector** for the caller:

```text
Object_CopyTfidVectorAtE7f8_Inferred(object, outShell) -> outShell*
  src = object + 0xe7f8
  FUN_004e53e0(outShell, src)   // std::vector copy-construct, elem 8 B
  return outShell
  RET 4
```

Used by craft-station proximity (`0052eb90`) and station-subtype walker (`004dd940`) as the dual CALL pattern: first for count, second for indexed TFID resolve.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ R13-026 re-verify) | `docs/reconstruction/raw/aa_004e5810_FUN_004e5810.md` |
| Annotated | `docs/reconstruction/raw/aa_004e5810_FUN_004e5810.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_CopyTfidVectorAtE7f8_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_004e5810.cpp` |
| Function record | `docs/reconstruction/functions/aa_004e5810_Object_CopyTfidVectorAtE7f8_Inferred.md` |
| Live body | `disassemble_function` + `read_memory` @ `0x004e5810` (35 B + `CC` pad) |
| Parent dual | `Character_Craft_HasMatchingStationInRange_Inferred` @ `0x0052eb90` (R12-021) |
| Callee body | decompile `FUN_004e53e0` (evidence only; not OWN dual) |

---

## 3. Calling convention (assembly-sealed)

| Slot | Role | Evidence |
|---|---|---|
| ECX | `Object* this` | prologue uses ECX then `ADD ECX,0xe7f8`; call sites `MOV ECX,ESI` / MI+0xa8 |
| stack0 | `VectorU64Shell* out` | `MOV ESI,[ESP+0xC]` after 2 pushes; `RET 4` |
| EAX | returns `out` | `MOV EAX,ESI` before epilogue |
| cleanup | **`ret 4`** | `C2 04 00` @ `0x004e5830` |
| Call sites | 4× PUSH out + ECX object | `0052ec12`, `0052ec6b`, `004ddb67`, `004ddbb7` |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 35 B + `ret 4` + pad `CC` | **High** | `read_memory` hex; exclusive end `0x004e5833` |
| thiscall ECX=object, stack out*, EAX=out | **High** | full disasm |
| Source member `+0xe7f8` | **High** | opcode `81 C1 F8 E7 00 00` |
| Sole callee `FUN_004e53e0` | **High** | relative CALL `E8 B4 FB FF FF` → `004e53e0` |
| Elem stride 8 (TFID pair) | **High** | all callers `SAR EAX,3` after end-begin; resolve uses two dwords |
| Classification wrapper | **High** | analyze_function_complete |
| 2 callers / 4 UNCONDITIONAL_CALL xrefs | **High** | callers + xrefs tools |
| Parent craft-gate consumer | **High** | dualed R12-021 call sites |
| Product / PDB demangle of member | **Open** | `_Inferred` |
| Runtime / bit-exact / differential | **Open** | deferred; **never Runtime Confirmed** |

---

## 5. Control flow: raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| Load out* into ESI | **Yes** |
| `this+0xe7f8` as source | **Yes** |
| CALL `004e53e0` with ECX=out | **Yes** |
| Return out* + RET 4 | **Yes** |

Full hex:

```
51568b74240c81c1f8e70000518bcec744240800000000e8b4fbffff8bc65e59c20400
```

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Object thiscall + fixed member offset | **Yes** (`+0xe7f8`) |
| Vector copy materialize (not mutate source) | **Yes** (callee constructs dest) |
| TFID pair consumers (resolve + craft/station) | **Yes** |
| Product/PDB English | **No** |

**Decision:** promote **`Object_CopyTfidVectorAtE7f8_Inferred`** (structural High; English unproven). Reject Named_CalleeOf mission-UI plate; reject inventory-grid place/find; reject claim that this unit itself walks/resolves TFIDs (that is callers).

---

## 7. Gaps

1. Product English for `+0xe7f8` member (nearby-objects list vs craft-station list vs generic association).
2. Full dual of copy worker `FUN_004e53e0` and pod copy `FUN_006a2be0`.
3. Exact MSVC vector shell layout cookie at `out+0` (callers use `+4/+8`; callee zeros `+4/+8/+0xc`).
4. Runtime / bit-exact / image diff.

**Verdict:** **accept-with-gaps**

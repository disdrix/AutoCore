# Review A (reconstruction fidelity): `aa_005305b0` CVOGCharacter_SetMissionCounter

| Field | Value |
|---|---|
| **Stable ID** | `aa_005305b0` |
| **VA** | `0x005305b0` |
| **Body** | `0x005305b0`–`0x00530603` exclusive (**83** B) |
| **Canonical name** | `CVOGCharacter_SetMissionCounter` (proposed) |
| **Ghidra symbol** | `FUN_005305b0` |
| **Prior / alias** | `Named_CalleeOf_Named_CalleeOf_Named_FAILED_Server_reports_failu_005305b0` (narrow) |
| **Review date** | `2026-07-29` (W30-I OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_005305b0_CVOGCharacter_SetMissionCounter.md` |
| **System** | `missions-progression` |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `analyze_function_complete`, `get_function_by_address` (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Character Val12 map **absolute set by key**:

1. Map object at **`char+0x584`**; end/head at **`char+0x588`**.
2. `FUN_00418b80` finds by stack key.
3. **Miss** (`node == head`): `StdTree_OperatorIndex_Val12` insert; write mapped `{0, value}`.
4. **Hit**: `*(node+0x14) = value` (assign, not add).

Sibling `CVOGCharacter_AddMissionCounter` (`00530610`) does hit `+=` and uses **ret 0xC** (3 stack formals).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005305b0_FUN_005305b0.md` (+ W30-I append) |
| Annotated | `docs/reconstruction/raw/aa_005305b0_FUN_005305b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGCharacter_SetMissionCounter.cpp` |
| Twin | `reconstructed-exact/FUN_005305b0.cpp` |
| Function records | `functions/aa_005305b0_FUN_005305b0.md` + named |
| Live decompile | ≡ raw 2026-07-23 CF |
| Live body bytes | full 83 B via `read_memory` |
| Sibling dual | `A/B_aa_00530610_CVOGCharacter_AddMissionCounter` |
| Operator[] dual | `aa_0053af20` StdTree_OperatorIndex_Val12 (W29-Q) |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Prologue | `PUSH ECX; PUSH ESI; PUSH EDI; MOV EDI,ECX` |
| Map this | `LEA ESI,[EDI+0x584]` |
| Find | `CALL FUN_00418b80` (rel32 → `00418b80`) |
| Miss gate | `CMP EAX,[EDI+0x588]; JNZ hit` |
| Insert | `CALL FUN_0053af20`; `MOV [EAX],EDI0; MOV [EAX+4],value` |
| Hit store | `MOV [EAX+0x14], value` |
| Epilogue both | `RET 8` (`C2 08 00`) |
| Body end | exclusive `0x00530603` (pad `cc`) |

Full body hex (83 B):

```
5156578bf98d442410508d4c240c8db784050000518bcee8b485eeff8b4424083b8788050000751f538b5c24188d542414528bce33ffe835a9000089388958045b5f5e59c208008b4c24145f8948145e59c20800
```

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw CF | **pass** |
| Body size exclusive end | **pass** (`00530603`, 83 B) |
| `ret 8` / 2 stack args | **pass** |
| thiscall ECX=character | **pass** |
| Map +0x584 / head +0x588 | **pass** |
| Miss → operator[] + `{0,value}` | **pass** |
| Hit → assign +0x14 only | **pass** |
| Clean typed path (no bare undefined4) | **pass** |
| Product English | **gap** |
| +0x10 vs +0x14 vs GetResourceBalance | **gap** (documented) |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI | **High** | live ≡ raw; ret 8; full body hex |
| Set vs Add role | **High** | assign vs sibling += |
| Name `CVOGCharacter_SetMissionCounter` | **Inferred** | mirrors sealed AddMissionCounter |
| Map shared with GetResourceBalance | **High** (same +0x584) |
| Runtime / differential | Open | |

---

## 6. Gaps

1. Product demangle / English for counter key domain.  
2. Dual-field policy: Get reads **+0x10**, Set/Add write **+0x14**.  
3. Bit-exact / differential — open.

**Verdict:** **accept-with-gaps**

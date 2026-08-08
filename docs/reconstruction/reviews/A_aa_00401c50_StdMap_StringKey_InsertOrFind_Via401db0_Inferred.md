# Review A (reconstruction fidelity): `aa_00401c50` StdMap_StringKey_InsertOrFind_Via401db0_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00401c50` |
| **VA** | `0x00401c50` |
| **Body** | `0x00401c50`–`0x00401d26` inclusive (**215** B / `0xD7`) |
| **Canonical name** | `StdMap_StringKey_InsertOrFind_Via401db0_Inferred` (inferred) |
| **Ghidra symbol** | `FUN_00401c50` |
| **Prior / alias** | `Named_CalleeOf_*Mission_Attempting_to_open_null_dialog*` (**reject** product) |
| **Review date** | `2026-08-05` (MEGA-064 OWN-ONLY dual) |
| **Reviewer role** | Path A — fidelity |
| **Counterpart** | `reviews/B_aa_00401c50_StdMap_StringKey_InsertOrFind_Via401db0_Inferred.md` |
| **System** | std map insert-or-find (isnil2D string key) |
| **Live tools** | decompile + analyze_function_complete + disassemble_function + read_memory + callers/xrefs + assembly_context (**no** disassemble_bytes) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Unique insert-or-find for **isnil@+0x2d** maps keyed by **`basic_string`**. ABI: **stack**=map, **EAX**=key, **EBX**=out. Insert worker undualed `0x00401db0`. Pred dualed `0x004313d0` (`StdTree_IteratorDecrement`).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ MEGA-064 append) | `docs/reconstruction/raw/aa_00401c50_FUN_00401c50.md` |
| Annotated | `docs/reconstruction/raw/aa_00401c50_FUN_00401c50.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdMap_StringKey_InsertOrFind_Via401db0_Inferred.cpp` |
| Scaffold twin | `reconstructed-exact/FUN_00401c50.cpp` |
| Function record | `docs/reconstruction/functions/aa_00401c50_StdMap_StringKey_InsertOrFind_Via401db0_Inferred.md` |
| Live decompile | ≡ raw CF (`in_EAX` / `unaff_EBX` = register ABI) |
| Live body bytes | 215 B hex in raw append |
| Parent context | `FUN_00980160` @ `0x009801dd` (Mission dialog string path; host evidence only) |
| Twin reference | dualed `StdMap_StringKey_InsertOrFind` `0x004309c0` |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Prologue | `83 EC 08` / `8B 54 24 0C` — stack map into EDX |
| Key capture | `8B F8` — EAX→EDI key |
| isnil | `80 7E 2D 00` — `[ESI+0x2d]` |
| Key field | `LEA EAX,[ESI+0x0C]` before IAT `<` |
| Compare | `FF 15 E8 62 9C 00` — IAT `0x009c62e8` |
| Leftmost insert | `PUSH EDI` / `PUSH 1` / `CALL 0x00401db0` |
| Pred | `LEA EDX,[ESP+0x0C]` / `CALL 0x004313d0` |
| Found | `[EBX]=ESI`; `[EBX+4]=0`; `MOV EAX,EBX`; `RET 4` |
| Inserted | `[EBX]=node`; `[EBX+4]=1`; `MOV EAX,EBX`; `RET 4` |
| Body end | inclusive `0x00401d26` (`C2 04 00`) |

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw CF | **pass** |
| Body size 215 B | **pass** |
| RET 4 stack map + EAX key + EBX out | **pass** |
| isnil@+0x2d / key@+0x0C | **pass** |
| Equal no rewrite (inserted=0) | **pass** |
| Pred dualed | **pass** (`004313d0`) |
| Insert worker dual | **gap** (`00401db0`) |
| Product map English | **gap** |
| Twin merge with `004309c0` | **reject** (different insert monomorph) |
| Runtime | **open** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI | **High** | disasm + call-site sealed |
| String key compare | **High** | IAT + LEA +0x0C |
| Role insert-or-find shell | **High** | MSVC pattern; twin match |
| Name `_Inferred` + Via401db0 | **Inferred** | insert-worker disambiguator |
| Runtime | Open | |

---

## 6. Gaps (acceptable)

1. Product demangle / English for map value type (Mission host only).  
2. Dual of insert worker `FUN_00401db0` / buynode `FUN_00401f40`.  
3. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**

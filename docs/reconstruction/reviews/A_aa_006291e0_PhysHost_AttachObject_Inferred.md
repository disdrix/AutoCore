# Review A (reconstruction fidelity): `aa_006291e0` PhysHost_AttachObject_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_006291e0` |
| **VA** | `0x006291e0` |
| **Body** | `0x006291e0`–`0x00629231` exclusive (**81** B) |
| **Canonical name** | `PhysHost_AttachObject_Inferred` |
| **Ghidra symbol** | `FUN_006291e0` |
| **Prior / alias** | `Named_CalleeOf_…_CVOGSpawnPoint_Set_006291e0` (narrow); W29-T `Host_Attach` |
| **Review date** | `2026-07-29` (W30-I OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_006291e0_PhysHost_AttachObject_Inferred.md` |
| **System** | world-object / phys host |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `analyze_function_complete`, `get_function_by_address` (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Phys-host **object attach leaf**:

1. `obj+0x44 = host` backlink.
2. Ensure capacity of pointer vector at **`host+0x3c`** (`FUN_005b3370` elem 4, cdecl).
3. Push `obj`; stamp **`obj+0x58 = index`**.
4. `result = (*(obj+0x3c))->vtbl+0x14()` then `host->vtbl+0x10(result)`.

Sole external consumer: `WorldObj_AttachRegisterHost_Inferred` (`0055e760`) with three host-this variants (sticky / new / list[0]).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_006291e0_FUN_006291e0.md` (+ W30-I append) |
| Annotated | `docs/reconstruction/raw/aa_006291e0_FUN_006291e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/PhysHost_AttachObject_Inferred.cpp` |
| Twin | `reconstructed-exact/FUN_006291e0.cpp` |
| Function records | `functions/aa_006291e0_FUN_006291e0.md` + named |
| Live decompile | ≡ raw 2026-07-23 CF |
| Live body bytes | full 81 B via `read_memory` |
| Caller dual | `A/B_aa_0055e760_WorldObj_AttachRegisterHost_Inferred` (W29-T) |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden, nested vfunc duals.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Entry | `PUSH EBX; MOV EBX,[ESP+8]; PUSH ESI/EDI; MOV EDI,ECX` |
| Backlink | `MOV [EBX+0x44],EDI` |
| Vector base | `LEA ESI,[EDI+0x3c]` |
| Cap mask | `AND EAX,0x7FFFFFFF` |
| Grow | `PUSH 4; PUSH ESI; CALL FUN_005b3370; ADD ESP,8` |
| Push + index | `MOV [data+size*4],obj; INC size; MOV [obj+0x58],size-1` |
| Nested vcall | `MOV ECX,[obj+0x3c]; CALL [vtbl+0x14]` |
| Host vcall | `PUSH EAX; MOV ECX,host; CALL [host.vtbl+0x10]` |
| Epilogue | `RET 4` (`C2 04 00`) |
| Body end | exclusive `0x00629231` (pad `cc`) |

Full body hex (81 B):

```
538b5c240856578bf98d773c897b448b460825ffffff7f394604750b6a0456e86ca1f8ff83c4088b4e048b16891c8a834604018b47408b4b3c83e8018943588b118b37ff5214508bcfff56105f5e5bc20400
```

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw CF | **pass** |
| Body size exclusive end | **pass** (`00629231`, 81 B) |
| `ret 4` / 1 stack arg | **pass** |
| thiscall ECX=host | **pass** (caller sites force host ECX) |
| Vector +0x3c layout | **pass** |
| Stamps +0x44 / +0x58 | **pass** |
| Nested then host vcall this | **pass** (machine) |
| Grow cdecl | **pass** (`ADD ESP,8`) |
| Clean typed path | **pass** |
| Product English / vfunc names | **gap** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI | **High** | live ≡ raw; ret 4; full body hex |
| Host attach role | **High** | sole caller AttachRegisterHost |
| Name `PhysHost_AttachObject_Inferred` | **Inferred** | PhysHost family + Host_Attach role |
| Nested/host vfunc product | Open | |
| Runtime / differential | Open | |

---

## 6. Gaps

1. Product type name for host block (0xa8 / tag 0x2d from caller).  
2. English for `obj+0x3c` nested object and both vfuncs.  
3. Nested dual of `FUN_005b3370` grow (shared utility).  
4. Bit-exact / differential — open.

**Verdict:** **accept-with-gaps**

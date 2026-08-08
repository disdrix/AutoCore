# Review A (reconstruction fidelity): `aa_0083a880` ShopVehObject_ApplyDefaultOrientQuat_Flag_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0083a880` |
| **VA** | `0x0083a880`–`0x0083a94d` inclusive (**206 B** / `0xCE`) |
| **Canonical name** | `ShopVehObject_ApplyDefaultOrientQuat_Flag_Inferred` |
| **Ghidra name** | `FUN_0083a880` |
| **Review date** | `2026-08-05` (WQ9L-J dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY WQ9L-J) |
| **Counterpart** | `reviews/B_aa_0083a880_ShopVehObject_ApplyDefaultOrientQuat_Flag_Inferred.md` |
| **System** | shopveh list UI — slot-object default orientation |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + read_memory (+ analyze/xrefs/disassemble_function/assembly_context). **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Apply the shopveh default display quaternion (`DAT_00aaa97c`..`988`, unit after `Math_QuatNormalize`) to a slot object. Two modes via stack flag:

- **flag == 0** (reindex match/swap refresh): seed cached orient block `obj+0x5e0..+0x5ec`, set `obj+0x5dc = 1`, re-normalize in place.
- **flag != 0** (post-bind from `FUN_0083ab90`): write quat into XformState (`obj+0x510` thiscall → store at `obj+0x590`), run residual helpers `FUN_00833490` / optional nested vtbl`+0x44` / `FUN_00833390`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ WQ9L-J append) | `docs/reconstruction/raw/aa_0083a880_FUN_0083a880.md` |
| Annotated | `docs/reconstruction/raw/aa_0083a880_FUN_0083a880.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ShopVehObject_ApplyDefaultOrientQuat_Flag_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0083a880.cpp` |
| Function record | `docs/reconstruction/functions/aa_0083a880_ShopVehObject_ApplyDefaultOrientQuat_Flag_Inferred.md` |
| Live | full disasm listing; body hex; 3 CALL xrefs; quat `.data` floats |

---

## 3. Signature (sealed)

```c
// EAX = ShopVehObject* obj; stack uint8 flag; void; RET 4
void ShopVehObject_ApplyDefaultOrientQuat_Flag_Inferred(void *obj /* EAX */, uint8_t flag);
```

| Formal | Source | Conf |
|---|---|---|
| obj | **EAX** → `MOV ESI,EAX` / `TEST ESI` | **High** |
| flag | stack (`CMP byte [ESP+0x18],0` after `SUB ESP,0x10; PUSH ESI`) | **High** |
| return | void | **High** |
| cleanup | **`RET 4`** (`C2 04 00`) both exits | **High** |

---

## 4. Control flow (authority)

```text
if obj == null: return
local = { DAT_00aaa988, 984, 980, 97c }   // MOVSS order
Math_QuatNormalize(local, local)          // FUN_0076e5e0
if flag != 0:
  FUN_0040d1a0(this=obj+0x510, &local)    // LEA ECX,[ESI+0x510]
  FUN_00833490()                          // ESI=obj
  if obj+0x508 != 0: thiscall vtbl+0x44 on nested
  FUN_00833390()                          // EAX=*(obj+0x508)
  return
// flag == 0:
copy local → obj+0x5e0..+0x5ec
obj+0x5dc = 1
Math_QuatNormalize(obj+0x5e0, obj+0x5e0)
```

| Stage | Match | Conf |
|---|---|---|
| Null gate + ESI=obj | `MOV ESI,EAX; TEST ESI; JZ epilogue` | **High** |
| Default quat load order | MOVSS from `00aaa988/984/980/97c` | **High** |
| Normalize ×2 | `CALL 0x0076e5e0` @ `0083a8ce` and `0083a93f` | **High** |
| flag branch | `CMP byte [ESP+0x18],0` / `JZ flag0` | **High** |
| Xform thiscall | `LEA ECX,[ESI+0x510]; PUSH &local; CALL 0040d1a0` | **High** |
| Nested vtbl+0x44 | `MOV ECX,[ESI+0x508]; CALL [EAX+0x44]` | **High** |
| Cached seed +0x5e0 / +0x5dc=1 | `LEA EAX,[ESI+0x5e0]` … `MOV byte [ESI+0x5dc],1` | **High** |
| RET 4 | epilogue `5E 83 C4 10 C2 04 00` | **High** |

---

## 5. Machine bytes (entry / exit)

| Item | Hex / notes |
|---|---|
| Body | `0x0083a880`–`0x0083a94d` (**206 B** / `0xCE`); pad `CC CC` then `FUN_0083a950` |
| Entry | `83 EC 10 56 8B F0 85 F6 0F 84 …` |
| Exit (both) | `5E 83 C4 10 C2 04 00` |
| Quat `.data` | `00aaa97c`: `-0.2244063, 0.0923448, -0.9699135, -0.01934201` (‖q‖≈1.0) |

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers (3 CALL) | `FUN_0083ac90` @ `0083ada4` / `0083ade0` (**PUSH 0**); `FUN_0083ab90` @ `0083abe4` (**PUSH 1**, EAX=obj) |
| Callees | `Math_QuatNormalize` (`0076e5e0`)×2, `FUN_0040d1a0`, `FUN_00833490`, `FUN_00833390`, nested vtbl+0x44 |

---

## 7. Gaps

1. Product / RTTI demangle for slot class.  
2. Exact English for residual helpers `FUN_00833490` / `FUN_00833390` / vtbl`+0x44`.  
3. Semantic product label of default quat (display pose — not identity).  
4. Runtime / bit-exact / differential.

---

## 8. Verdict

Fidelity path seals ABI (EAX obj + stack flag + RET 4), default-quat constants, both flag paths, and call-site push 0/1 roles. Residual product English + helper duals → **accept-with-gaps**.

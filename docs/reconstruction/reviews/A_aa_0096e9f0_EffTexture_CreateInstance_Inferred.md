# Review A (reconstruction fidelity): `aa_0096e9f0` EffTexture_CreateInstance_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0096e9f0` |
| **VA** | `0x0096e9f0`–`0x0096ea5a` exclusive (**106 B** / `0x6A`) |
| **Canonical name** | `EffTexture_CreateInstance_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_0096e9f0` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W38-O) |
| **Counterpart** | `reviews/B_aa_0096e9f0_EffTexture_CreateInstance_Inferred.md` |
| **System** | palantir graphics Effects — effTexture factory |
| **Evidence pass** | Live Ghidra `batch_decompile` + `disassemble_function` + `read_memory` (full 106 B) + `analyze_function_complete` + xrefs + callee decompiles + caller-site bytes (`0096f0e0`, `0096ee00`). **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Factory: freelist-allocate + construct + initialize an effect-texture instance.

1. `FUN_0043f120` with `EDI=&DAT_00d21930` — freelist pop → EAX.
2. Non-null → `FUN_0096bbb0` in-place ctor (vtbls `00aa0a20` / `00aa0a10`).
3. `FUN_0096cad0` thiscall init packing `*EBX`/`*(EBX+4)` dims + five stack formals.
4. Init `< 0` → `vtbl[0](this, 1)` complete dtor → null.
5. Else return object\*; **`RET 0x14`**.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W38-O append) | `docs/reconstruction/raw/aa_0096e9f0_FUN_0096e9f0.md` |
| Annotated | `docs/reconstruction/raw/aa_0096e9f0_FUN_0096e9f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/EffTexture_CreateInstance_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0096e9f0.cpp` |
| Function records | `functions/aa_0096e9f0_FUN_0096e9f0.md`, `…_EffTexture_CreateInstance_Inferred.md` |
| Live | decompile CF; full 106 B hex; dual `RET 0x14`; `MOV ECX,[EBX]` / `[EBX+4]` dims copy |
| Context | W37-H create-or-assign parent; PalantirEnv init plates; `effTextureImpl.cpp` in `0096cad0` |

---

## 3. Signature (sealed)

```c
// EBX = const uint32_t dims[2]* {width,height}
// five stack dwords; RET 0x14; returns object* or null
void* __stdcall EffTexture_CreateInstance_Inferred(
    uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4);
```

| Slot | Source | Conf |
|---|---|---|
| dims* | **EBX** (`MOV ECX,[EBX]`; `MOV EDX,[EBX+4]`) | **High** |
| stack count | **5 dwords** (`RET 0x14`) | **High** |
| return | object\* / null in **EAX** | **High** |
| cleanup | **`RET 0x14`** both paths | **High** |

Parent `0096f0e0` forwards `(p0,p2,p3,p4,p5)` with EBX=`p1` — **High**.

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
obj = freelist_pop(DAT_00d21930)
if obj: ctor(obj)
if obj:
  hr = init(obj, dims from *EBX, stack a0..a4)
  if hr < 0: complete_dtor(obj,1); return null
return obj
```

| Stage | Match | Conf |
|---|---|---|
| Freelist + ctor + init | **Yes** | **High** |
| Fail complete dtor | **Yes** | **High** |
| RET 0x14 both exits | **Yes** | **High** |
| effTextureImpl via cad0 | **Yes** | **High** |
| a0..a4 product English | Partial | **Medium/Open** |

---

## 5. Verdict

ABI, body bounds, freelist/ctor/init/fail-dtor CF sealed. Residual product English for stack formals and object RTTI → **accept-with-gaps**.

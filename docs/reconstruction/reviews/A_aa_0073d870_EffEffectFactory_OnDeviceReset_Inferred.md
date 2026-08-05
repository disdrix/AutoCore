# Review A (reconstruction fidelity): `aa_0073d870` EffEffectFactory_OnDeviceReset_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0073d870` |
| **VA** | `0x0073d870`–`0x0073d8c2` exclusive (**82 B** / `0x52`) |
| **Canonical name** | `EffEffectFactory_OnDeviceReset_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_0073d870` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W38-V) |
| **Counterpart** | `reviews/B_aa_0073d870_EffEffectFactory_OnDeviceReset_Inferred.md` |
| **System** | graphics / Effects / Device Reset recreate |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (full body) + `analyze_function_complete` + callers/xrefs + call-site context + callee decompile. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Effect Factory post-`IDirect3DDevice9::Reset` recreate walk**:

1. For each 0x14-byte table entry in host `[+4, +8)`:
   - If `(*entry)[+0xC] != 0`, vcall that child at vtbl **`+0x118`** (OnResetDevice-style).
   - For each param pointer in `entry[+8, +0xC)`, call `FUN_007525f0` (**EDI** formal).
2. Return **0** always.

Sole caller is `gfxDevice.cpp` Device Reset with fail plate **"Failed to Reset() device on Effect Factory"**.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W38-V append) | `docs/reconstruction/raw/aa_0073d870_FUN_0073d870.md` |
| Annotated | `docs/reconstruction/raw/aa_0073d870_FUN_0073d870.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/EffEffectFactory_OnDeviceReset_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0073d870.cpp` |
| Function records | `aa_0073d870_FUN_0073d870.md`, `…_EffEffectFactory_OnDeviceReset_Inferred.md` |
| Pair Lost | `aa_0073d8d0` same host `[EBP+0x764]` |
| Live | decompile CF ≡ bytes; body 82 B; `XOR EAX,EAX` before RET |

---

## 3. Signature (sealed)

```c
// EAX host*; no stack; RET; returns 0
uint32_t EffEffectFactory_OnDeviceReset_Inferred(void /* EAX host */);
```

| Formal | Source | Conf |
|---|---|---|
| EAX host | `MOV EAX,[EBP+0x764]` @ caller `0x0075f2f0` | **High** |
| return 0 | `33 C0` before epilogue | **High** |
| epilogue | `POP EBX; POP ECX; RET` (`C3`) | **High** |

---

## 4. Control flow (decompile + bytes authority)

```
end = host+8; begin = host+4
for entry in [begin, end) step 0x14:
  if (*entry)[+0xC] != 0:
    child = (*entry)[+0xC]
    child->vtbl[+0x118](child)
  for p in [entry+8, entry+0xC) step 4:
    EDI = *p; FUN_007525f0()
return 0
```

| Stage | Match | Conf |
|---|---|---|
| Outer stride 0x14 | Yes (`ADD EBX,0x14` / decomp `+5`) | **High** |
| Child null gate +0xC | Yes | **High** |
| Vcall +0x118 | Yes (`FF 91 18 01 00 00`) | **High** |
| Inner FUN_007525f0 | Yes (target sealed) | **High** |
| Always return 0 | Yes | **High** |
| Body 82 B | Yes | **High** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | `FUN_0075eff0` only |
| Callees | `FUN_007525f0` |

---

## 6. Gaps

1. Product English for factory / entry / child class (structural `_Inferred` only).  
2. Full dual of unowned `FUN_007525f0`.  
3. Why always-0 while caller checks `< 0` (shared factory reset template).  
4. Runtime / bit-exact / differential.

---

## 7. Verdict rationale

Structural CF, ABI, body size, sole-caller Effect Factory plate, and OnReset placement vs pair OnLost are **sealed**. Product class English and unowned param helper remain open → **accept-with-gaps**.

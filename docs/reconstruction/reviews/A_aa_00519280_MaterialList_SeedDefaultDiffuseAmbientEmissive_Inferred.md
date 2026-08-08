# Review A (reconstruction fidelity): `aa_00519280` MaterialList_SeedDefaultDiffuseAmbientEmissive_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00519280` |
| **VA** | `0x00519280` |
| **Canonical name (Ghidra)** | `FUN_00519280` |
| **Proposed name** | `MaterialList_SeedDefaultDiffuseAmbientEmissive_Inferred` (**High** string evidence; product demangle absent) |
| **Review date** | `2026-08-04` (OWN-ONLY dual A — WQ9R-E) |
| **Reviewer role** | Reconstruction fidelity (clean ≡ raw ≡ live decompile) |
| **Counterpart** | `reviews/B_aa_00519280_MaterialList_SeedDefaultDiffuseAmbientEmissive_Inferred.md` |
| **System** | client-fx / material param bank (WQ-009 residual nested callee of `FUN_0051b2a0`) |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Seed a float4 material-color bank from a material-pointer list**, writing default **`{0,0,0,1}`** for each of **MatDiffuse / MatAmbient / MatEmissive** per source slot, then applying a **caller float4** to those effect parameters.

Loop:

```
count = (src+0xC0==0) ? 0 : ((src+0xC4)-(src+0xC0))>>2
for i in 0..count-1:
  for name in (MatDiffuse, MatAmbient, MatEmissive):
    FUN_0096f840(name, &defaultFloat4)   // default {0,0,0,1}
    push defaultFloat4 into dst vector   // stride 0x10; grow via 0051d4a0 or copy via 00608720
  FUN_009700f0(MatDiffuse|Ambient|Emissive, &callerFloat4)
```

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` + `analyze_function_complete` @ `0x00519280` |
| `read_memory` | prologue `0x00519280`; epilogue `0x005194e0`; `g_flOne` @ `0x00A0F2A0` |
| Callers decompiled | `FUN_0051b2a0`, `FUN_004c5480` |
| Callees sample | `FUN_0051def0` (vector resize 0x10), `FUN_00608720` (copy N float4), `FUN_0051d4a0` (grow) |
| Raw / annotated / clean | `aa_00519280` three-rep + named clean |

**Not performed:** Launcher, runtime, parent ledgers, `disassemble_bytes`.

---

## 3. Signature

```c
void MaterialList_SeedDefaultDiffuseAmbientEmissive_Inferred(
    void *srcMaterialOwner,   // pointer vector @ +0xC0/+0xC4
    void *dstVecHost,         // begin/end/cap @ +4/+8/+0xC
    float r, float g, float b, float a); // caller float4 @ stack+0x0C
```

Body **624 B** (`0x00519280`–`0x005194f0` exclusive). Epilogue `POP`×4 + `ADD ESP,0x14; RET`.

Note: Ghidra signature shows only 2 formals; callers pass **6** stack values — extra 4 floats sealed by `FUN_009700f0(..., &stack0x0000000c)` + caller sites.

---

## 4. Callers / callees

| Caller | Role |
|---|---|
| `FUN_0051b2a0` | If host bank empty (`[0x52]==0` or count0): `src=*(vtbl+0x1CC()+8)`, `dst=host+0x51`, forward colors |
| `FUN_004c5480` | Calls `0051b2a0` then optional second seed on alternate offsets |

| Callee | Role |
|---|---|
| `FUN_0096f840` | Set named effect param from float4 |
| `FUN_009700f0` | Set named effect param (caller color path) |
| `FUN_0051d4a0` | Grow-insert into float4 vector |
| `FUN_00608720` | Copy N×float4 in-place |
| `FUN_0051def0` | Vector resize-to-N (head call; ECX residual) |

Xrefs: **2**. Classification: **worker**.

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Default float4 `{0,0,0,g_flOne}` | Yes (`g_flOne` sealed 1.0f) |
| Count from `+0xC0/+0xC4` `>>2` | Yes |
| Triple Mat* bind + push | Yes (three identical grow/copy blocks) |
| Triple 009700f0 with stack float4 | Yes |
| Capacity check `>>4` stride 0x10 | Yes |

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| MatDiffuse/Ambient/Emissive string params | **Confirmed** | decompile strings |
| Default color `{0,0,0,1}` | **High** | zeros + `g_flOne` |
| Dst vector stride 0x10 | **High** | `>>4` + `end+=0x10` |
| Src count `>>2` pointer vector | **High** | decompile |
| Extra stack float4 from callers | **High** | `0051b2a0` / `004c5480` |
| Empty-bank gate at caller | **High** | `0051b2a0` |
| Head `FUN_0051def0` this/target | **Tentative** | decompiler shows zeros |
| Product type names | **Tentative** | `_Inferred` |
| Loop uses material ptr values | **Tentative** | decomp indexes count only |

---

## 7. Gaps / open

1. Exact ECX/object for `FUN_0051def0` at entry (likely clear a float4 vector; N≈0).
2. Whether loop body loads `src_vec[i]` for per-material state (decomp shows count-only).
3. Product class of src material table / host bank.
4. Runtime / bit-exact / differential not run.

**Verdict:** **accept-with-gaps** — string-driven Mat* seed CF High; head resize this residual.

# Review A (reconstruction fidelity): `aa_00985f40` PoolHost_ForEachTrackedNested_CallVtable0C_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00985f40` |
| **VA** | `0x00985f40`–`0x00985f8a` inclusive (**75 B** / `0x4B`) |
| **Canonical name** | `PoolHost_ForEachTrackedNested_CallVtable0C_Inferred` |
| **Ghidra name** | `FUN_00985f40` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W38-AD) |
| **Counterpart** | `reviews/B_aa_00985f40_PoolHost_ForEachTrackedNested_CallVtable0C_Inferred.md` |
| **System** | client / gfxDevice Device Reset pre-shutdown |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `get_function_by_address` + `read_memory` (full 75 B + pad) + xrefs/callers + sole-caller decompile `FUN_0075eff0` + GfxDevice ctor slot map. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

First Device Reset pre-shutdown step: walk the **PoolHost track** vector of container pointers and, for each non-empty nested object* vector, **thiscall** `vtbl[+0xC]` on every object. Host is GfxDevice slot `+0x73C` / `DAT_00d1f624` seed.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W38-AD) | `docs/reconstruction/raw/aa_00985f40_FUN_00985f40.md` |
| Annotated | `docs/reconstruction/raw/aa_00985f40_FUN_00985f40.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/PoolHost_ForEachTrackedNested_CallVtable0C_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00985f40.cpp` |
| Function records | `functions/aa_00985f40_FUN_00985f40.md`, named twin |
| Related | W33-R PoolHost track @+4; W35-R GfxDevice ctor slot `+0x73C`; parent `FUN_0075eff0` |
| Live | body 75 B; epilogue `5F 5E 5D 5B 59 C3`; sole xref `0x0075f0d1` |

---

## 3. Signature (sealed)

```c
// EAX = host*; no stack formals; bare C3; void
void PoolHost_ForEachTrackedNested_CallVtable0C_Inferred(/* EAX */);
```

| Formal | Source | Conf |
|---|---|---|
| host* | **EAX** (caller `MOV EAX,[device+0x73C]`) | **High** |
| stack args | none | **High** |
| RET | bare `C3` | **High** |
| return | void | **High** |

---

## 4. Control flow (clean ≡ bytes; decompiler + thiscall fix)

```
begin=*(EAX+4); end=*(EAX+8)
for p in [begin,end) step 4:
  c = *p
  ib = *(c+8)
  if ib==0 or ((*(c+0xC)-ib)>>2)==0: continue
  for q in [ib,*(c+0xC)) step 4:
    obj=*q; ECX=obj; CALL [(*obj)+0xC]
```

| Stage | Match | Conf |
|---|---|---|
| Body 75 B / pad CC | **Yes** | **High** |
| Outer track +4/+8 | **Yes** | **High** |
| Inner empty null/count | **Yes** | **High** |
| thiscall vtbl+0xC | **Yes** (bytes; decompiler omits ECX) | **High** |
| Sole Device Reset site | **Yes** (1 xref) | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (75 B) — raw W38-AD append.

Entry: `51 53 8B 58 04 55 8B 68 08`.  
Inner call: `8B 0E 8B 01 FF 50 0C`.  
Epilogue: `5F 5E 5D 5B 59 C3`.  
Pad `CC` then later `FUN_00985fe0`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker (pre-reset notify walk) |
| Callers | **1** — `FUN_0075eff0` @ `0x0075f0d1` |
| Callees | indirect vtbl only |
| Sequence | log → **this** → IB pre-reset `00985580` → VB pre-reset `009864e0` |

---

## 7. Gaps

1. Product English for vtbl+0xC method (device-lost vs release vs other).
2. Tracked container class demangle (HostAux0x40 vs other).
3. Runtime / bit-exact / differential.

---

## 8. Verdict

Fidelity pass seals EAX host, 75 B body, double-vector walk, thiscall vtbl+0xC, sole Device Reset wiring to `+0x73C`. Residual product English → **accept-with-gaps**.

# Review A (reconstruction fidelity): `aa_0073d8d0` EffEffectFactory_OnDeviceLost_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0073d8d0` |
| **VA** | `0x0073d8d0`–`0x0073d937` exclusive (**103 B** / `0x67`) |
| **Canonical name** | `EffEffectFactory_OnDeviceLost_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_0073d8d0` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W38-V) |
| **Counterpart** | `reviews/B_aa_0073d8d0_EffEffectFactory_OnDeviceLost_Inferred.md` |
| **System** | graphics / Effects / Device Reset shutdown release |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (full body) + `analyze_function_complete` + callers/xrefs + call-site context + callee decompile. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Effect Factory pre-reset / device-lost release walk**:

1. For each 0x14-byte table entry in host `[+4, +8)`:
   - `FUN_0074f0c0` with **ESI = \*entry** (OnLost-style release; also hits shared globals).
   - For each param pointer in `entry[+8, +0xC)`, call `FUN_00752640` (**EBX** formal).
2. `DAT_00d1f048[+0xC] = 0`.
3. If `DAT_00d1f044[+0x77C] == 1` (`[0x1df]` dword index): device iface vtbl **`+0x134`(0)**.

Sole caller is `gfxDevice.cpp` Device Reset **shutdown** (`"Beginning shutdown for Device Reset()"`), same host register load as OnDeviceReset pair.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W38-V append) | `docs/reconstruction/raw/aa_0073d8d0_FUN_0073d8d0.md` |
| Annotated | `docs/reconstruction/raw/aa_0073d8d0_FUN_0073d8d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/EffEffectFactory_OnDeviceLost_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0073d8d0.cpp` |
| Function records | `aa_0073d8d0_FUN_0073d8d0.md`, `…_EffEffectFactory_OnDeviceLost_Inferred.md` |
| Pair Reset | `aa_0073d870` same host `[EBP+0x764]` |
| Live | decompile CF ≡ bytes; body 103 B; global tail sealed |

---

## 3. Signature (sealed)

```c
// EAX host*; no stack; RET; void
void EffEffectFactory_OnDeviceLost_Inferred(void /* EAX host */);
```

| Formal | Source | Conf |
|---|---|---|
| EAX host | `MOV EAX,[EBP+0x764]` @ caller `0x0075f0f1` | **High** |
| void | no value set for return; caller ignores | **High** |
| epilogue | conditional device vcall then `POP ECX; RET` | **High** |

---

## 4. Control flow (decompile + bytes authority)

```
end = host+8; begin = host+4
for entry in [begin, end) step 0x14:
  ESI = *entry; FUN_0074f0c0()
  for p in [entry+8, entry+0xC) step 4:
    EBX = *p; FUN_00752640()
DAT_00d1f048[+0xC] = 0
if DAT_00d1f044[+0x77C] == 1:
  (*DAT_00d1f044)->vtbl[+0x134](*DAT_00d1f044, 0)
return
```

| Stage | Match | Conf |
|---|---|---|
| Outer stride 0x14 | Yes (`ADD EDI,0x14`) | **High** |
| FUN_0074f0c0 per entry | Yes | **High** |
| FUN_00752640 param walk | Yes | **High** |
| Global byte clear +0xC | Yes (`C6 40 0C 00`) | **High** |
| Mode flag + vcall +0x134 | Yes | **High** |
| Body 103 B | Yes | **High** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | `FUN_0075eff0` only |
| Callees | `FUN_0074f0c0`, `FUN_00752640` |
| Globals | `DAT_00d1f048`, `DAT_00d1f044` |

---

## 6. Gaps

1. Product English for factory / entry.  
2. Full dual of `FUN_0074f0c0` (W38-X) and `FUN_00752640`.  
3. Product name of device vtbl `+0x134` (software-VP residual from caller CF only).  
4. Runtime / bit-exact / differential.

---

## 7. Verdict rationale

ABI, table walk, global tail, and pre-reset polarity vs pair are **sealed**. Product English and unowned callees open → **accept-with-gaps**.

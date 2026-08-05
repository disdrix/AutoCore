# Review A (reconstruction fidelity): `aa_0074f090` Gfx_GlobalEffect_OnDeviceReset_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0074f090` |
| **VA** | `0x0074f090`–`0x0074f0be` exclusive (**46 B** / `0x2E`) |
| **Canonical name** | `Gfx_GlobalEffect_OnDeviceReset_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_0074f090` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W38-W) |
| **Counterpart** | `reviews/B_aa_0074f090_Gfx_GlobalEffect_OnDeviceReset_Inferred.md` |
| **System** | Palantir graphics — Global Effect device-reset step |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (46 B full) + `analyze_function_complete` + sole caller call-site bytes + sibling `FUN_0074f0c0` + parent fail plate. **No** `disassemble_bytes`. |
| **Verdict** | **accept** |

---

## 1. Purpose

**EAX = holder\***: if `holder[+0xC]` null → return **0**; else vcall **`vtbl[+0x118]`** on inner iface; map status with **SETGE / SUB 1** → **0** (ok) or **−1** (fail). Sole use: **`GfxDevice_Reset`** factory rebuild stage; product fail string **“Failed to Reset() device on Global Effect”**.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W38-W append) | `docs/reconstruction/raw/aa_0074f090_FUN_0074f090.md` |
| Annotated | `docs/reconstruction/raw/aa_0074f090_FUN_0074f090.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Gfx_GlobalEffect_OnDeviceReset_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0074f090.cpp` |
| Function record | `docs/reconstruction/functions/aa_0074f090_FUN_0074f090.md` |
| Named record | `docs/reconstruction/functions/aa_0074f090_Gfx_GlobalEffect_OnDeviceReset_Inferred.md` |
| Live | decompile + 46 B hex; phantom `in_EAX` confirmed by `CMP [EAX+0xC]` prologue |
| Parent plate | W37-N `GfxDevice_Reset` Global Effect fail string |
| Sibling | `FUN_0074f0c0` lost-device vtbls +0x10c/+0x114 |

**Not performed:** Launcher, runtime, ledgers.

---

## 3. Signature (sealed)

```c
// EAX = holder*; bare RET; return 0 | -1
int Gfx_GlobalEffect_OnDeviceReset_Inferred(void* holder /*EAX*/);
```

| Slot | Source | Conf |
|---|---|---|
| holder | **EAX** (`CMP dword [EAX+0xC],0`) | **High** |
| inner | `[EAX+0xC]` | **High** |
| vcall | `CALL [vtbl+0x118]` after `PUSH` inner | **High** |
| return map | `SETGE` / `SUB 1` → 0/−1 | **High** |
| null | → 0 (SETGE path on zero) | **High** |
| cleanup | bare `C3` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if [EAX+0xC] == 0: return 0
inner = [EAX+0xC]
status = vcall(inner, vtbl[+0x118])
return (status >= 0) ? 0 : -1
```

---

## 5. Machine bytes

- Body **46 B**; pad `CC`.
- Full hex in raw W38-W append.
- Caller: `MOV EAX,[EBP+0x760]; MOV EAX,[EAX+4]; CALL`; `CMP EAX,EBX; JGE` success.

---

## 6. Gaps (fidelity)

- Product C++ type of holder / iface.
- Exact English of vtbl[+0x118] (OnResetDevice vs custom).
- Frame identity of `[EBP+0x760]` in Reset.
- Runtime / bit-exact / differential.

---

## 7. Verdict rationale

ABI (EAX), field, vcall slot, 0/−1 map, sole caller + product Global Effect plate sealed. Residual type English open but does not block **accept**.

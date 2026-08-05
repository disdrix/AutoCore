# Review A (reconstruction fidelity): `aa_00754480` Palantir_ResetDevice

| Field | Value |
|---|---|
| **Stable ID** | `aa_00754480` |
| **VA** | `0x00754480`–`0x007544E0` exclusive (**96 B**) |
| **Canonical name** | `Palantir_ResetDevice` |
| **Ghidra name** | `FUN_00754480` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W35-K) |
| **Counterpart** | `reviews/B_aa_00754480_Palantir_ResetDevice.md` |
| **System** | client / Palantir host device reset |
| **Evidence pass** | Live Ghidra `batch_decompile` / `decompile_function` + `analyze_function_complete` + `read_memory` (full body 96 B) + string reads `@0x00a9f85c` / `@0x00a9f910` + vtbl `@0x00a9f76c` + caller `0x007a3c80`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Product `Palantir::ResetDevice`: drive nested gfx device reset; on failure log + set retry flag + Sleep(1000) + return -1; on success clear flag, invoke subobject vtbl[+8] with `this+8`, return 0.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W35-K append) | `docs/reconstruction/raw/aa_00754480_FUN_00754480.md` |
| Annotated | `docs/reconstruction/raw/aa_00754480_FUN_00754480.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Palantir_ResetDevice.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_00754480.cpp` |
| Function records | `functions/aa_00754480_FUN_00754480.md`, `functions/aa_00754480_Palantir_ResetDevice.md` |
| Peer complete dtor | W34-K `aa_00754320` Palantir_CompleteDtor |
| Live | decompile + 96 B hex + string/vtbl memory + caller |

---

## 3. Signature (sealed)

```c
// ECX=this; bare RET; EAX = 0 | -1
int Palantir_ResetDevice(Palantir* self);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX (`8B F1`) | **High** |
| cleanup | `C3` | **High** |
| stack args | none | **High** |
| return | EAX `0` / `OR EAX,-1` | **High** |

---

## 4. Control flow (bytes authority)

```
ESI = ECX
AL = [ESI+5]; ECX = [ESI+0xB0]; EDX = [ESI+0x28]
EDI = ESI+8
PUSH AL, ECX, EDX; EAX = EDI; CALL FUN_0075eff0
if (EAX < 0):
  vog_LogMessage(path, 0x184, 0, "Palantir::ResetDevice failed...")
  [ESI+6] = 1; Sleep(1000); return -1
[ESI+6] = 0
ECX = [ESI+0x2C]; PUSH EDI; CALL [vtbl+8]
return 0
```

| Stage | Match | Conf |
|---|---|---|
| ECX→ESI this | `8B F1` | **High** |
| nested EAX=this+8 | `8D 7E 08` / `8B C7` | **High** |
| failure log product name | string @ `0x00a9f85c` | **High** |
| retry flag + Sleep(1000) | `C6 46 06 01` / push `0x3E8` | **High** |
| success vcall vtbl+8 | `FF 50 08` | **High** |
| vtbl slot[1] identity | `PTR_FUN_00a9f76c+4` → this | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (96 B) — see raw W35-K append.

Entry: `56 8B F1 8A 46 05 …`  
Fail epilogue: `5F 83 C8 FF 5E C3`  
Success epilogue: `5F 33 C0 5E C3`  
Pad: `CC` from `0x007544E0`.

**Decompile ≢ bytes:** nested `EAX=this+8` under-reported. **Bytes win.**

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | `FUN_007a3c80` @ `0x007a3c84`; vtbl[1] |
| Callees | `FUN_0075eff0`, `vog_LogMessage`, IAT `Sleep` |

---

## 7. Gaps

1. Nested `FUN_0075eff0` full dual (gfxDevice Reset body).  
2. Type of `*(this+0x2C)` / meaning of `+5` / `+0xB0`.  
3. Runtime / bit-exact / differential.

---

## 8. Verdict

96 B body sealed: product ResetDevice, ECX this, 0/-1, retry+Sleep, success vcall. Nested device plate open → **accept-with-gaps**.

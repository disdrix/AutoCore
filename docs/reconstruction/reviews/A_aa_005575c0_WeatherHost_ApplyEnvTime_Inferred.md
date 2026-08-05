# Review A (reconstruction fidelity): `aa_005575c0` WeatherHost_ApplyEnvTime_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005575c0` |
| **VA** | `0x005575c0`–`0x005579be` exclusive (**1022 B**) |
| **Canonical name** | `WeatherHost_ApplyEnvTime_Inferred` |
| **Ghidra name** | `FUN_005575c0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W36-F) |
| **Counterpart** | `reviews/B_aa_005575c0_WeatherHost_ApplyEnvTime_Inferred.md` |
| **System** | client weather / env-time + nfx preload |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` (entry/epilogue/call sites + constants) + callers/callees. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Apply env-time slot on weather host: resolve weather, fill/activate nfx key rings with AssPreloader coop steps, blend 5000 ms transition, commit weather pointers, apply.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W36-F append) | `docs/reconstruction/raw/aa_005575c0_FUN_005575c0.md` |
| Annotated | `docs/reconstruction/raw/aa_005575c0_FUN_005575c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/WeatherHost_ApplyEnvTime_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_005575c0.cpp` |
| Function records | `functions/aa_005575c0_*.md` |
| Sealed callees | W32-I `00556b10`; W35-A `004ed310`; W32-K `00971820` |
| Callers | `FUN_005579c0` ×2 |

---

## 3. Signature (sealed)

```c
// ECX=host, stack uint8_t slot; RET 0x4
void WeatherHost_ApplyEnvTime_Inferred(void* host, uint8_t env_time_slot);
```

| Formal | Source | Conf |
|---|---|---|
| host | ECX → ESI | **High** |
| env_time_slot | stack; RET 4 | **High** |
| void return | epilogue | **High** |

---

## 4. Control flow

| Stage | Match | Conf |
|---|---|---|
| Gate `+0x178` | decompile + entry bytes | **High** |
| Lookup / forgotten-weather seed | strings + `00556da0` | **High** |
| Early-out `weather+0x54c == slot` | decompile | **High** |
| Fill `+0x190` mode0 + ProcessKeyRingStep | call sites + W32-I | **High** |
| Yield → ExpandDeps (ECX=AssPreloader) | bytes @ `005577eb` | **High** |
| Activate `+0x1a4` mode1 + same pattern | call sites | **High** |
| 5000 ms blend (`0x00af2ce8`) | `read_memory` float | **High** |
| Commit prev/cur + `00555f10` | decompile | **High** |

---

## 5. Machine bytes (`read_memory`)

- Entry SEH + `SUB ESP,0x56C` + `MOV ESI,ECX`.
- Epilogue `ADD ESP,0x578` / **`C2 04 00`**.
- ExpandDeps: `MOV EDX,[DAT_00d1f050]; MOV ECX,[EDX+0x6c]; PUSH EDI; CALL 00971820`.
- Full body size **1022 B**; pad then `FUN_005579c0`.

---

## 6. Gaps

- Product/PDB weather host class English.
- Full bit-exact default-seed string layout (byte-copy order only; semantic default TOD names sealed).
- Unowned `FUN_00558eb0` / `FUN_00556da0` / `FUN_00555f10` product duals.
- Runtime / bit-exact — open.

---

## 7. Verdict

Fidelity pass seals ABI, weather/nfx/AssPreloader CF, transition constant, and sole parent. Residuals product English + unowned helpers → **accept-with-gaps**.

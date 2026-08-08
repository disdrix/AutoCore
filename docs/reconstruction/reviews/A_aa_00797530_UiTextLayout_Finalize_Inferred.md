# Review A (reconstruction fidelity): `aa_00797530` UiTextLayout_Finalize_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00797530` |
| **VA** | `0x00797530`–`0x00797987` (**1112 B** / `0x458`) |
| **Canonical name** | `UiTextLayout_Finalize_Inferred` |
| **Ghidra name** | `FUN_00797530` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY MEGA-122) |
| **Counterpart** | `reviews/B_aa_00797530_UiTextLayout_Finalize_Inferred.md` |
| **System** | UI owned text-layout finalize / flush |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs/callees. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Finalize/flush a heap-owned text-layout block: trim trailing spaces, apply alignment mode, materialize display runs (multi or single), mark ready, clear source `wstring`. Called from thin merge wrappers and from dualed complete dtor `UiTextLayout_CompleteDtor_Inferred` with flag **1** before vector free.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ MEGA-122 append) | `docs/reconstruction/raw/aa_00797530_FUN_00797530.md` |
| Annotated | `docs/reconstruction/raw/aa_00797530_FUN_00797530.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UiTextLayout_Finalize_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00797530.cpp` |
| Function records | `aa_00797530_FUN_00797530.md`, `aa_00797530_UiTextLayout_Finalize_Inferred.md` |
| Owner path | dualed `UiTextLayout_CompleteDtor_Inferred` `PUSH 1; EBX=layout; CALL` |
| Live | decompile ≡ raw CF; body `00797530`–`00797987`; `RET 4` sealed |

---

## 3. Signature (sealed)

```c
// EBX = layout*; stack char flag; SEH LAB_009add2c; RET 4 (C2 04 00); void
void __stdcall UiTextLayout_Finalize_Inferred(char flag);
```

| Formal | Source | Conf |
|---|---|---|
| layout | **EBX** (LEA EDI,[EBX+0xC]; all body refs) | **High** |
| flag | stack (`CMP [ESP+0xac],0` for mode-3 gate); callers PUSH 0/1 | **High** |
| return | void; **`RET 4`** @ `0x00797985` | **High** |

---

## 4. Control flow (bytes authority)

```
SEH LAB_009add2c; SUB ESP,0x90; EDI = EBX+0x0C
trim trailing wchar 0x20; count@+0xB0--
if empty && run_count_60 < 2:
  mode1: x = (int)(mA0 * 0.5f)     // DAT_00a0f298
  mode2: x = (int)mA0
  → common tail
else:
  mode1/2: x += delta*(0.5|1)
  mode3 && flag==0: lineH@+0x8 = delta / count_B0
  if run_count > 1: multi-run → vector@+0x80; goto epilogue
  if run_count != 0: FUN_00426ff0 + 8-dword copy to +0x60
  cache +0xC4/+0xC0 → +0x2C/+0x28; FUN_00427050
epilogue:
  y += (int)float@+0xAC; ready@+0xB4=1; resize(0); FUN_00427210(0); RET 4
```

| Stage | Match | Conf |
|---|---|---|
| SEH + EBX-this | entry hex `LEA EDI,[EBX+0xC]` | **High** |
| Trailing-space trim | `CMP word [EAX],0x20` loop + resize IAT | **High** |
| Mode 1 half-factor | `MULSS [0x00a0f298]`; mem `0000003f` = 0.5f | **High** |
| Mode 3 flag gate | `CMP [ESP+0xac],0; JNZ` | **High** |
| Multi-run stride 0x60→0x80 | imul magic + `ADD …,0x60` / `ADD EDI,0x80` | **High** |
| Epilogue RET 4 | hex `C2 04 00` @ `0x00797985` | **High** |

---

## 5. Machine bytes (`read_memory`)

| Span | Result |
|---|---|
| Entry 64 B @ `0x00797530` | SEH `LAB_009add2c` + `SUB ESP,0x90` + `LEA EDI,[EBX+0xC]` sealed |
| Float @ `0x00a0f298` | `00 00 00 3f` = **0.5f** sealed |
| Epilogue @ `0x00797970` | FS restore + `ADD ESP,0x9c` + **`RET 4`** + `CC` pad sealed |

---

## 6. Gaps (accepted)

- Product demangle / exact class English (hence `_Inferred`).
- Element type English for 0x60 source runs vs 0x80 display runs; residual helpers `00426ff0`/`00427050`/`00427210`/`004275b0`/`00427a40`.
- Alignment mode product names beyond CF (1=half, 2=full, 3=line-height).
- Runtime / bit-exact / differential.

---

## 7. Verdict rationale

Fidelity path accepts EBX-this + stack flag + RET 4 finalize role, offset map, multi/single run split, and pairing with dualed complete dtor. Product name remains inferred — gap only. Scaffold Client_RecvBroadcast parent seed rejected.

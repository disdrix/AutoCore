# Review A (reconstruction fidelity): `aa_0090c700` MedalUI_PrepClearButtonSlots_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0090c700` |
| **VA** | `0x0090c700`–`0x0090c74c` (**77 B** / `0x4D`) |
| **Canonical name** | `MedalUI_PrepClearButtonSlots_Inferred` |
| **Ghidra name** | `FUN_0090c700` |
| **Prior names** | `Named_CalleeOf_Named_VOG_DEBUG_STOP_0090c700` (retired) |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY MEGA-102) |
| **Counterpart** | `reviews/B_aa_0090c700_MedalUI_PrepClearButtonSlots_Inferred.md` |
| **System** | `missions-progression` |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + `get_function_callers` + `get_xrefs_to` + `get_assembly_context` @ `0x0090cbef`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Medal UI **prep clear**: destroy/detach all **24** achievement button widgets stored at `host+0x540` so parent `FUN_0090cbc0` can rebuild the page (count via `FUN_0090c810`, bind via `FUN_0090c9a0` + `i_d_a_2d_btn_achievement.xml`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ MEGA-102 append) | `docs/reconstruction/raw/aa_0090c700_FUN_0090c700.md` |
| Annotated | `docs/reconstruction/raw/aa_0090c700_FUN_0090c700.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/MedalUI_PrepClearButtonSlots_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0090c700.cpp` |
| Function records | `functions/aa_0090c700_FUN_0090c700.md` + named |
| Live decompile | Ghidra `decompile_function` `0x0090c700` |
| Live listing | `disassemble_function` `0x0090c700` |
| Live bytes | `read_memory` 128 B @ entry |
| Call site | `get_assembly_context` @ `0x0090cbef` |
| Parent (evidence only) | `FUN_0090cbc0` decompile head |

**Not performed:** `disassemble_bytes`, Launcher, runtime Confirmed, dual of parent/siblings.

---

## 3. Body (listing seals)

```text
0090c700  PUSH EBX / PUSH ESI
0090c702  LEA  ESI,[EDI+0x540]     ; slot cursor
0090c708  MOV  EBX,0x18            ; 24 slots
0090c70d  LEA  ECX,[ECX]           ; align nop
0090c710  CMP  [ESI],0 / JZ next
0090c715  MOV  EAX,[EDI] / MOV ECX,EDI
0090c719  CALL [EAX+0x3d8]         ; host query → AL
0090c71f  TEST AL,AL / JZ skip_detach
0090c723  MOV  EAX,[ESI] / MOV EDX,[EDI]
0090c727  PUSH EAX / MOV ECX,EDI
0090c72a  CALL [EDX+0xb0]          ; host detach(slot)
0090c730  MOV  ECX,[ESI] / TEST ECX / JZ null_slot
0090c736  MOV  EDX,[ECX] / PUSH 1
0090c73a  CALL [EDX]               ; scalar dtor flags=1
0090c73c  MOV  [ESI],0
0090c742  ADD  ESI,4 / SUB EBX,1 / JNZ loop
0090c74a  POP  ESI / POP EBX / RET
```

Live decompile CF ≡ frozen raw 2026-07-23 ≡ live 2026-08-05.  
Body hex 77 B sealed; pad `CC` then `FUN_0090c750`.

---

## 4. ABI / signature (High)

```c
// Retail: EDI = host; no stack args; bare RET (C3)
void MedalUI_PrepClearButtonSlots_Inferred(void);
```

| Formal | Source | Conf |
|---|---|---|
| host | **EDI** (`LEA ESI,[EDI+0x540]`; caller `MOV EDI,ESI`) | **High** |
| stack | none | **High** |
| return | void; bare `C3` | **High** |
| ECX-thiscall | **No** (ECX only for nested host vcalls) | **High** |

---

## 5. Control flow (bytes authority)

| Stage | Match | Conf |
|---|---|---|
| Slot base `+0x540` | `8D B7 40 05 00 00` | **High** |
| Count `0x18` | `BB 18 00 00 00` | **High** |
| Empty-slot skip | `CMP [ESI],0` / `JZ` | **High** |
| Host vcall `+0x3d8` | `FF 90 D8 03 00 00` | **High** |
| Conditional host vcall `+0xb0` | `FF 92 B0 00 00 00` | **High** |
| Scalar dtor flags=1 | `6A 01` / `FF 12` | **High** |
| Always-null slot | `C7 06 00 00 00 00` | **High** |
| Loop / epilogue | `ADD ESI,4` / `SUB EBX,1` / `JNZ` / `POP;POP;RET` | **High** |

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker (virtual callees; no static FUN_*) |
| Code callers | **1** — `FUN_0090cbc0` @ `0x0090cbef` |
| Xrefs | 1× UNCONDITIONAL_CALL |
| Parent sequence | visible-gate → **this** → `FUN_0090c810` count → page math → `FUN_0090c9a0` bind |

---

## 7. Gaps

1. Product English for medal UI host class (EDI object).  
2. Product names for host vtbl `+0x3d8` / `+0xb0`.  
3. RTTI / exact type of slot widgets (XML path is sibling evidence).  
4. Runtime / bit-exact / differential — open.  
5. Parent `FUN_0090cbc0` and siblings residual (MEGA-095/103 partition).

---

## 8. Verdict

CF/ABI/slot layout/vcall offsets/sole-caller prep role sealed. Product host/widget English residual → **accept-with-gaps**. Terminal **false**.

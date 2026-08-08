# Raw capture: FUN_005fdf20

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fdf20` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005fdf20` |
| **Canonical name** | `FUN_005fdf20` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
float10 __fastcall FUN_005fdf20(int param_1)

{
  float fVar1;
  float fVar2;
  
  fVar1 = ABS(*(float *)(param_1 + 0x1c));
  if (fVar1 < *(float *)(param_1 + 0x38)) {
    return (float10)g_flZero;
  }
  fVar2 = g_flOne;
  if (*(float *)(param_1 + 0x1c) <= g_flZero) {
    fVar2 = DAT_00aaa668;
  }
  if (fVar1 < *(float *)(param_1 + 0x28)) {
    return ((float10)fVar1 - (float10)*(float *)(param_1 + 0x38)) *
           (float10)*(float *)(param_1 + 0x2c) * (float10)fVar2;
  }
  return (((float10)fVar1 - (float10)*(float *)(param_1 + 0x28)) *
          (float10)*(float *)(param_1 + 0x30) + (float10)*(float *)(param_1 + 0x34)) *
         (float10)fVar2;
}
```

---

## MEGA-026 live re-verify (2026-08-05) — APPEND ONLY

| Field | Value |
|---|---|
| **Agent** | OWN-ONLY dual **MEGA-026** |
| **Tools** | Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` + `get_function_xrefs` + `get_assembly_context` + `read_memory` |
| **Forbidden avoided** | No `disassemble_bytes`; no Launcher; no parent ledgers; no other VAs dualled |
| **Image** | `autoassault.exe` base `0x400000` |
| **Live decompile ≡ raw CF** | **Yes** (identical 3-return piecewise filter) |
| **Body** | `0x005fdf20`–`0x005fdf97` inclusive (**120 B** / `0x78`); pad `CC` at `0x005fdf98+` |
| **ABI** | **ECX** = this (`hkDefaultAnalogDriverInput*`); **no stack args**; **plain `RET`** ×3 exits; return **float on FPU ST0** (`float10`) |
| **Callees** | **none** (leaf) |
| **Callers** | **1** — `hkDefaultAnalogDriverInput_calcStatus` @ `0x005fe520` |
| **Xrefs** | **1** UNCONDITIONAL_CALL from `0x005fe58d` |
| **Call-site** | `MOV ECX,ESI` @ `0x005fe586`; `CALL 0x005fdf20` @ `0x005fe58d`; `FSTP [ESI+0x14]` @ `0x005fe592` (status steer slot) |
| **Globals** | `g_flZero` @ `0x00a0f518` = `0.0f`; `g_flOne` @ `0x00a0f2a0` = `1.0f`; `DAT_00aaa668` = `-1.0f` (`00 00 80 bf`) |
| **This layout (reads)** | `+0x1c` raw signed steer; `+0x28` inner thresh; `+0x2c` inner slope; `+0x30` outer slope; `+0x34` outer base; `+0x38` deadzone |
| **Semantics** | Piecewise-linear **filtered steer**: deadzone → inner ramp → outer ramp+base; multiply by sign(+1/−1) |
| **System** | **input-drive-control** (parent calcStatus plate WI-MOV-005) |
| **Promoted name** | `hkDefaultAnalogDriverInput_FilterSteer_Inferred` (product English open → `_Inferred`) |
| **Terminal** | **false** (no runtime Confirmed) |

### Live disassembly (Ghidra `disassemble_function`)

```text
005fdf20  SUB  ESP,0x8
005fdf23  MOV  EAX,dword ptr [ECX + 0x1c]
005fdf26  MOV  dword ptr [ESP + 0x4],EAX
005fdf2a  FLD  float ptr [ESP + 0x4]
005fdf2e  FABS
005fdf30  FST  float ptr [ESP]
005fdf33  FLD  float ptr [ECX + 0x38]
005fdf36  FCOMIP ST0,ST1
005fdf38  FSTP ST0
005fdf3a  JBE  0x005fdf46                 ; deadzone: if abs < +0x38 return 0
005fdf3c  FLD  float ptr [0x00a0f518]      ; g_flZero
005fdf42  ADD  ESP,0x8
005fdf45  RET
005fdf46  MOVSS XMM0,dword ptr [ESP + 0x4]
005fdf4c  COMISS XMM0,dword ptr [0x00a0f518]
005fdf53  MOVSS XMM0,dword ptr [0x00a0f2a0]; g_flOne
005fdf5b  JA   0x005fdf65                 ; sign: raw > 0 → +1 else −1
005fdf5d  MOVSS XMM0,dword ptr [0x00aaa668]; DAT_00aaa668 = −1.0f
005fdf65  FLD  float ptr [ESP]            ; abs
005fdf68  MOVSS dword ptr [ESP + 0x4],XMM0; store sign
005fdf6e  MOVSS XMM0,dword ptr [ECX + 0x28]
005fdf73  COMISS XMM0,dword ptr [ESP]
005fdf77  JBE  0x005fdf87                 ; if abs >= +0x28 → outer branch
005fdf79  FSUB float ptr [ECX + 0x38]     ; (abs − deadzone)
005fdf7c  FMUL float ptr [ECX + 0x2c]     ; * inner slope
005fdf7f  FMUL float ptr [ESP + 0x4]      ; * sign
005fdf83  ADD  ESP,0x8
005fdf86  RET
005fdf87  FSUB float ptr [ECX + 0x28]     ; (abs − inner thresh)
005fdf8a  FMUL float ptr [ECX + 0x30]     ; * outer slope
005fdf8d  FADD float ptr [ECX + 0x34]     ; + outer base
005fdf90  FMUL float ptr [ESP + 0x4]      ; * sign
005fdf94  ADD  ESP,0x8
005fdf97  RET
```

### Body hex (read_memory `0x005fdf20` len 128)

```text
83ec088b411c89442404d9442404d9e1d91424d94138dff1ddd8760a
d90518f5a00083c408c3f30f104424040f2f0518f5a000f30f1005a0
f2a0007708f30f100568a6aa00d90424f30f11442404f30f1041280f
2f0424760ed86138d8492cd84c240483c408c3d86128d84930d84134
d84c240483c408c3cccccccccccccccc
```

### Call-site context (`0x005fe58d`)

```text
005fe586  MOV  ECX,ESI
005fe588  MOVSS dword ptr [ESI + 0x10],XMM0   ; brake already stored
005fe58d  CALL 0x005fdf20
005fe592  FSTP float ptr [ESI + 0x14]         ; filtered steer → status.+0x14
005fe595  MOV  AL,byte ptr [ESI + 0x24]
005fe59f  MOV  byte ptr [ESI + 0x18],AL       ; handbrake
; then calcReverse → +0x19
```

### Piecewise formula (sealed)

```text
abs = |this.+0x1c|
if abs < this.+0x38:          return 0
sign = (this.+0x1c > 0) ? +1 : −1
if abs < this.+0x28:          return (abs − +0x38) * +0x2c * sign
else:                         return ((abs − +0x28) * +0x30 + +0x34) * sign
```

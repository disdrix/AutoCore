# Raw capture: FUN_0040dab0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040dab0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0040dab0` |
| **Canonical name** | `FUN_0040dab0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int FUN_0040dab0(float param_1)

{
  if (param_1 < 0.0) {
    return (int)(param_1 - g_flMissionXpRoundBias);
  }
  return (int)(param_1 + g_flMissionXpRoundBias);
}
```

---

## MEGA-119 live re-verify append — 2026-08-05

| Field | Value |
|---|---|
| **Agent** | OWN-ONLY dual **MEGA-119** |
| **Tools** | Ghidra HTTP `decompile_function` + `disassemble_function` + `read_memory` + callers/xrefs + `get_function_by_address` (**no** `disassemble_bytes`) |
| **Live decompile** | Identical CF to raw body above |
| **Body span** | `0x0040dab0`–`0x0040dad7` inclusive (**40 B** / `0x28`); pad `CC` from `0x0040dad8` |
| **Classification** | leaf utility (signed float→int round) |
| **Proposed name** | `Math_RoundFloatToInt_MissionXpBias_Inferred` |

### Live decompile (2026-08-05)

```c
int FUN_0040dab0(float param_1)

{
  if (param_1 < 0.0) {
    return (int)(param_1 - g_flMissionXpRoundBias);
  }
  return (int)(param_1 + g_flMissionXpRoundBias);
}
```

### Byte seal (`read_memory` 40 B @ `0x0040dab0` + `disassemble_function`)

```
0f 57 c9             xorps  xmm1, xmm1
f3 0f 10 44 24 04    movss  xmm0, dword ptr [esp+4]   ; float arg
0f 2f c8             comiss xmm1, xmm0                 ; 0 ? param
76 0d                jbe    pos                        ; if 0 <= param
f3 0f 5c 05 d0 a6 aa 00  subss xmm0, [0x00aaa6d0]     ; param - bias
f3 0f 2c c0          cvttss2si eax, xmm0               ; trunc toward 0
c3                   ret
pos:
f3 0f 58 05 d0 a6 aa 00  addss xmm0, [0x00aaa6d0]     ; param + bias
f3 0f 2c c0          cvttss2si eax, xmm0
c3                   ret
```

Full body hex (40 B, excl. `cc` pad):
```
0f57c9f30f104424040f2fc8760df30f5c05d0a6aa00f30f2cc0c3f30f5805d0a6aa00f30f2cc0c3
```

### Bias constant (`read_memory` 4 B @ `0x00aaa6d0`)

```
8e 06 00 3f  →  float 0.5001f  (g_flMissionXpRoundBias)
```

| Claim | Evidence | Conf |
|---|---|---|
| Stack formal float + plain `RET` | `[esp+4]` `MOVSS`; two `C3` | **High** |
| No thiscall / ECX unused | body never touches ECX | **High** |
| EAX = int result | `CVTTSS2SI EAX, XMM0` both exits | **High** |
| Signed half-away-from-zero via ±bias then trunc | `COMISS`/`JBE` + `SUBSS`/`ADDSS` + `CVTTSS2SI` | **High** |
| Bias = 0.5001f @ `0x00aaa6d0` | image dword `8e06003f` | **High** |
| Leaf (no callees) | no CALL; xrefs-from empty | **High** |
| Toast caller | `Client_ShowMissionRewardChatToast` @ `0x008ac624` | **High** |

### Callers / xrefs (20 UNCONDITIONAL_CALL)

| Caller | Sites (sample) | Role |
|---|---|---|
| `Client_ShowMissionRewardChatToast` `0x008ac540` | `0x008ac624` | mission reward XP chat/floater int |
| `FUN_0087d810` | 8 sites (`0x0087d8b5`…`0x0087e392`) | multi-float round consumer |
| `FUN_00503780` | 4 sites | multi-float round consumer |
| `FUN_0056a680` | `0x0056a744` | item cycle / scaled int (inline ±bias twin for gate) |
| `FUN_0049aa60` | `0x0049ab74` | float→int consumer |
| `FUN_005d9290` | `0x005d97e7` | float→int consumer |
| `FUN_0054cb10` | `0x0054cb59` | `conversion_percent` path |
| (orphan sites) | `0x009005dd`, `0x0090063a`, `0x008a45e3` | UNCONDITIONAL_CALL; host fn boundary open |

### Call graph (this unit only)

| Role | Target | Notes |
|---|---|---|
| Callees | **none** | pure SSE leaf |
| Primary dual parent | `Client_ShowMissionRewardChatToast` @ `0x008ac540` | after `Mission_ComputeObjectiveXpAsFloat` (`0x0051f510`) |
| Shared constant | `g_flMissionXpRoundBias` @ `0x00aaa6d0` | also used inline by grant path / item cycle |


# Raw capture: FUN_004c4dd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c4dd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004c4dd0` |
| **Canonical name** | `FUN_004c4dd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
float10 __fastcall FUN_004c4dd0(int param_1)



{

  short sVar1;

  float10 extraout_ST0;

  

  (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x27c))();

  sVar1 = FUN_004c41c0();

  return ((float10)(int)sVar1 * (float10)g_flMsToSeconds_Inferred + extraout_ST0) *

         (float10)DAT_00a110c0 + (float10)DAT_00aaa7b8;

}
```

---

## Live seal append — 2026-07-29 W23-K (OWN-ONLY)

| Field | Value |
|---|---|
| **Tools** | Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (+ callers/callees). **No** `disassemble_bytes` |
| **Body** | `0x004c4dd0`–`0x004c4e1d` (**77** B) |
| **Epilogue** | `POP ECX` — no stack formals; FPU **ST0** return |
| **ABI** | `__fastcall` / thiscall-style; **ECX** = host; return float in **ST0** |
| **Live decompile** | ≡ raw 2026-07-23 body (no CF drift) |
| **Classification** | worker / combat crit base |

### Machine body (`read_memory`, 77 B hex)

```
51568bf18b46048b48048b5431048d4c3104ff927c02000089442404db4424048bced80d2cf7a000e8c3f3ffff0fbfc0894424045edb0424d80d2cf7a000dec1d80dc010a100d805b8a7aa0059
```

### Byte-exact formula (FPU order)

1. `vcall` MI slot **`vtbl+0x27c`** on `(this + *(vbtable+4) + 4)` → int level-like.
2. `FILD` → `FMUL dword [0x00a0f72c]` → ST0 = `level * 0.001f`.
3. `FUN_004c41c0(this)` → short (sign-extended) perception-capped score.
4. `FILD` score → `FMUL dword [0x00a0f72c]` → `FADDP` → ST0 = `(score + level) * 0.001f`.
5. `FMUL dword [0x00a110c0]` (`0.125f`) → `FADD dword [0x00aaa7b8]` (`0.02f`).

**Closed form:**  
`chance = ((int)score + level) * 0.001f * 0.125f + 0.02f`  
`= ((int)score + level) * 0.000125f + 0.02f`

Decompiler writes `((score)*g + extraout_ST0)*scale+base` where `extraout_ST0` is already `level*g` after step 2 — same math.

### Constants (`read_memory`)

| Symbol / VA | Hex LE | float |
|---|---|---|
| `g_flMsToSeconds_Inferred` `0x00a0f72c` | `6f12833a` | **0.001** |
| `DAT_00a110c0` | `0000003e` | **0.125** |
| `DAT_00aaa7b8` | `0ad7a33c` | **0.02** |

### Callees / callers

| Dir | VA | Notes |
|---|---|---|
| Callee | `FUN_004c41c0` `0x004c41c0` | capped perception-like int from host `+0x142/+0x14a` + vcall gate |
| Caller | `Combat_ComputeCritChance_Inferred` `0x004cef70` | skill-bind non-null path |
| Caller | `FUN_008f97c0` `0x008f97c0` | character sheet; string **"Base Critical Hit Chance"** near call |

### Role (evidence)

Skill-host / bind path for **base critical-hit chance** fraction (UI label sealed). Sibling no-bind path in `0x004cef70` uses `level*0.001*0.25+0.05` instead.

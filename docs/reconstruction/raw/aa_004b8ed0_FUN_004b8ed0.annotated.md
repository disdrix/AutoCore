# Annotated: FUN_004b8ed0 → NDSpecialFX_HostTick_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b8ed0` |
| **VA** | `0x004b8ed0`–`0x004b9240` (880 B) |
| **Proposed name** | `NDSpecialFX_HostTick_Inferred` |
| **Ghidra** | `FUN_004b8ed0` |
| **System** | client-fx / NDSpecialFX lifecycle |
| **Pass** | W24-C OWN-ONLY dual seal 2026-07-29 |
| **Tools** | decompile + read_memory (no disassemble_bytes) |

---

## Purpose (annotated)

Per-frame / periodic **host tick** for an NDSpecialFX instance:

1. **Profiler** counter at `DAT_00d17958+0x154`.
2. **Rate / type gate:**
   - If `g_dwClientTickMs - (this+0xd0) < 0x1389` (≤ 5000 ms since last stamp): force **active path** (label `caseD_7`).
   - Else `switch(this+0x28)` event type:
     - type **4**: optional `FUN_004b6a80` may re-enter active path
     - types **2,3,5,6,0xC–0xE,0x13–0x15,0x17**: fall through → **deactivate**
     - **default**: active path
3. **Active path:**
   - Stamp `this+0xd0 = g_dwClientTickMs`
   - Liveness gate `FUN_004b7330` — if non-zero → **DeactivateClear** (`FUN_004b7150`) + **return 1**
   - Else: `FUN_004b75d0` (UpdateParamMapTransforms), distance/cull vs camera node, walk owned lists
   - Own children `+0x204`: tick (`CVOGObject_Tick`) or profile `"Destroy"` free path when `+0x90e bit0`
   - Lists `+0x1e0`, `+0x210`, `+0x21c` residual maintenance
   - `FUN_004b6910` epilogue (optional host notify)
   - **return 0** (still live)
4. **Deactivate path:** `NDSpecialFX_DeactivateClear_Inferred` + **return 1**

## ABI

```
// thiscall; stack: ctx pointer; ret 4
uint8_t / int  NDSpecialFX_HostTick_Inferred(NDSpecialFX *this, void **ctx /* *ctx forwarded */);
// 0 = still active; 1 = deactivated / finished this call
```

## Key offsets (this / children)

| Off | Role |
|---|---|
| `+0x28` | event / FX type (switch) |
| `+0xd0` | last-tick ms stamp |
| `+0xd4` | accum flags (OR from `FUN_0058e1a0`) |
| `+0x1e0` | list A |
| `+0x204` | owned CVOG child list (same as DeactivateClear) |
| `+0x210` | list B (owned heap payloads) |
| `+0x21c` | list C |
| child `+0x90e` bit0 | destroy-pending (set by DeactivateClear; free here) |
| child `+0x798` | optional float gate before `FUN_00590c20` |

## Constants

| Sym | Value | Notes |
|---|---|---|
| rate limit | `0x1388` / `< 0x1389` | 5000/5001 ms |
| `DAT_009cb2b0` | ≈1e-6 | sq length cull floor |
| `"Destroy"` | profile string | free-path scope |

## Confidence

| Claim | Level |
|---|---|
| Body range + ret 4 | **Confirmed** |
| Rate gate + type switch CF | **Confirmed** |
| DeactivateClear linkage | **Confirmed** (W23-H dual) |
| Role = host tick / deactivate | **High** |
| Product method name | **Inferred** |
| Full nested list free CF (operator_delete residual) | **Probable** (decomp noreturn noise) |
| Runtime / bit-exact | **Open** |

## Raw body

See `aa_004b8ed0_FUN_004b8ed0.md` (scaffold + W24-C re-verify append).

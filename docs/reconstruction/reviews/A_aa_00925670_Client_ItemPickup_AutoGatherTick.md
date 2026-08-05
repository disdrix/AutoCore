# Review A (reconstruction fidelity): `aa_00925670` Client_ItemPickup_AutoGatherTick

| Field | Value |
|---|---|
| **Stable ID** | `aa_00925670` |
| **VA** | `0x00925670`–`0x00925712` |
| **Canonical name** | `Client_ItemPickup_AutoGatherTick` |
| **Ghidra name** | `FUN_00925670` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W24-T) |
| **Counterpart** | `reviews/B_aa_00925670_Client_ItemPickup_AutoGatherTick.md` |
| **System** | inventory-transfer / client input auto gather |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory`; sole caller PollBound |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Always-on **auto ItemPickup gather tick** (~**100 ms** throttle) from `Client_Input_PollBoundActions`:

1. Gate `*(client+0xcd0) == 0`.
2. `GetTickCount`; require delta vs `DAT_00d1f0d4` **> 99**.
3. Arm throttle stamp; init TFID pair to sentinel `-1,-1`.
4. Resolve host via `*( *(client+4)+4 )`; vtbl `+0x1a0`( **20.0f**, 1, 6, 0, 0, 1 ).
5. `FUN_0058cd60` radius-map gather into pair.
6. If pair valid: `FUN_00925580` / `Client_SendItemPickup` (C2S **0x2055**).

**Not** Activate-edge exclusive path (that is the later PollBound block); this unit runs **unconditionally** each poll after the main action body.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00925670_FUN_00925670.md` (+ 2026-07-29 append) |
| Annotated | `docs/reconstruction/raw/aa_00925670_FUN_00925670.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_ItemPickup_AutoGatherTick.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00925670.cpp` |
| Function record | `docs/reconstruction/functions/aa_00925670_FUN_00925670.md` |
| Parent duals | `A/B_aa_00925580_*`, `A/B_aa_0058cd60_*`, `A/B_aa_00925d60_*` |
| Live | decompile ≡ raw CF; `read_memory` 163 B; epilog `C2 04 00` |
| Call site | `0x00927894`: `mov eax, DAT_00d1b6d8; push param_1; call` |

---

## 3. Signature (sealed)

```c
// EAX = client*; Stack[4] unused; RET 4; void
void Client_ItemPickup_AutoGatherTick(void *unused_stack);
```

| Formal | Source | Conf |
|---|---|---|
| client | EAX (`DAT_00d1b6d8`) | **High** |
| unused stack | pushed by PollBound; not read | **High** |
| cleanup | `RET 4` | **High** |
| ESI on pickup | `LEA ESI, pair` before `FUN_00925580` | **High** (bytes + parent dual) |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| Gate `+0xcd0 == 0` | **Yes** | **High** |
| GetTickCount + write `DAT_00d218d4` | **Yes** | **High** |
| Throttle `cmp ecx, 0x64` / `jb` | **Yes** | **High** |
| Stamp `DAT_00d1f0d4` before gather | **Yes** | **High** |
| Pair init `-1,-1` | **Yes** | **High** |
| vtbl+0x1a0 imm `0x41a00000` (=20.0f) | **Yes** | **High** |
| `FUN_0058cd60` then AND-sentinel test | **Yes** | **High** |
| Hit → `FUN_00925580` | **Yes** | **High** |
| Sole caller PollBound always-path | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Hex body (163 B):
```
83ec30568bf083bed00c0000000f8589000000ff152c629c008bc82b0dd4f0d100a3d418d20083f96472718b5604576a01c744240cffffffffc7442410ffffffff6a00a3d4f0d1008b42048bca8b51046a008d7c30048d04328bb0a80000006a068d48048b016a01680000a041ff90a00100005057568d4c242c6a0051e86e76c6ff8b5424342354243883c42c83faff5f74098d742404e874feffff5e83c430c20400
```

Callees (relative verified): `FUN_0058cd60` @ `0x0058cd60`, `FUN_00925580` @ `0x00925580`.

---

## 6. Gaps

- Product English for `client+0xcd0` gate and vtbl+0x1a0 helper.
- Full `FUN_0058cd60` argc at this site (`add esp,0x2c` residual).
- Runtime / bit-exact / live auto-loot verification.

**Residual gaps are non-blocking for CF/ABI/throttle/opcode path.** Verdict **accept-with-gaps**.

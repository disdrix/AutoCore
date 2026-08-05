# Review A (reconstruction fidelity): `aa_004b6a80` NDSpecialFX_List1e0_AnyFlag10

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b6a80` |
| **VA** | `0x004b6a80`–`0x004b6aa7` (**40 B**) |
| **Canonical name** | `NDSpecialFX_List1e0_AnyFlag10` (**Inferred**) |
| **Ghidra name** | `FUN_004b6a80` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W26-G) |
| **Counterpart** | `reviews/B_aa_004b6a80_NDSpecialFX_List1e0_AnyFlag10.md` |
| **System** | client-fx / NDSpecialFX residual list |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `analyze_function_complete`; both callers |
| **Verdict** | **accept** |

---

## 1. Purpose

Leaf **bool probe** over residual list `host+0x1e0`:

1. `sentinel = *(host+0x1e0)`; start at `*sentinel`.
2. For each node until sentinel: payload = `node[2]`; if `payload[0x989] & 0x10` → return **1**.
3. Else return **0**.

Callers use non-zero as type-4 **optional re-enter / keep-active** (HostTick + `FUN_004ba0a0`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004b6a80_FUN_004b6a80.md` (+ 2026-07-29 W26-G append) |
| Annotated | `docs/reconstruction/raw/aa_004b6a80_FUN_004b6a80.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NDSpecialFX_List1e0_AnyFlag10.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004b6a80.cpp` |
| Function record | `docs/reconstruction/functions/aa_004b6a80_FUN_004b6a80.md` |
| Named record | `docs/reconstruction/functions/aa_004b6a80_NDSpecialFX_List1e0_AnyFlag10.md` |
| Live | decompile ≡ raw; full body hex 40 B; 0 callees; 2 callers |

---

## 3. Signature (sealed)

```c
// ECX = host; AL = 0|1; plain RET; leaf
uint8_t NDSpecialFX_List1e0_AnyFlag10(void* host /*ECX*/);
```

| Slot | Source | Conf |
|---|---|---|
| host | **ECX** (`MOV ECX,[ECX+0x1e0]` overwrites after load) | **High** |
| return | **AL** `XOR AL,AL` / `MOV AL,1` | **High** |
| cleanup | `POP ESI; RET` | **High** |
| callees | none | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
sentinel = *[host+0x1e0]
node = *sentinel
while node != sentinel:
  if (node[2])[0x989] & 0x10: return 1
  node = *node
return 0
```

| Stage | Match | Conf |
|---|---|---|
| Sentinel list walk | **Yes** | **High** |
| Payload at node+8 | **Yes** | **High** |
| Flag `+0x989 & 0x10` | **Yes** | **High** |
| Leaf | **Yes** | **High** |
| Type-4 caller role | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`) — full body

```
8b89e00100008b013bc1567414b210908b7008849689090000750a8b003bc175ef32c05ec3b0015ec3
```

Epilogues: `32 C0 5E C3` (0) / `B0 01 5E C3` (1). Pad `CC` after `0x004b6aa7`.

---

## 6. Gaps

- Product English for bit `0x10` at `+0x989` and list element class.
- Runtime golden / differential.
- Naming is structural inference (not plate string).

---

## 7. Verdict

CF, ABI, offsets, leaf status, and caller gate role are sealed from live decompile + full body bytes. Residual is English/runtime only → **accept**.

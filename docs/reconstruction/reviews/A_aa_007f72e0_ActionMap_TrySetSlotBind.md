# Review A (reconstruction fidelity): `aa_007f72e0` ActionMap_TrySetSlotBind

| Field | Value |
|---|---|
| **Stable ID** | `aa_007f72e0` |
| **VA** | `0x007f72e0`–`0x007f748f` |
| **Canonical name** | `ActionMap_TrySetSlotBind` |
| **Ghidra name** | `FUN_007f72e0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W21-P) |
| **Counterpart** | `reviews/B_aa_007f72e0_ActionMap_TrySetSlotBind.md` |
| **System** | input-drive-control |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory`; callers InitDefaultKeybinds + keymap.ini |
| **Verdict** | **accept** |

---

## 1. Purpose

Leaf ActionMap helper: for mode group `0..3` and slot index, if the slot’s customized flag is clear, write primary (BL==0) or alt (BL!=0) DIK/mod pair and clear two status bytes. Returns success in AL.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007f72e0_FUN_007f72e0.md` (+ 2026-07-29 append) |
| Annotated | `docs/reconstruction/raw/aa_007f72e0_FUN_007f72e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ActionMap_TrySetSlotBind.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_007f72e0.cpp` |
| Function record | `docs/reconstruction/functions/aa_007f72e0_FUN_007f72e0.md` |
| Parent | `Client_InitDefaultKeybinds` `0x007f8720` |
| Keymap loader | `FUN_0092f710` `0x0092f710` |
| Live | decompile ≡ raw; body 432 B; jump table `@0x007f7490`; 9× `C2 08 00` |

---

## 3. Signature (sealed)

```c
// AL=index BL=lane SI=key DX=mod; stack base + mode; RET 8; AL success
uint8_t ActionMap_TrySetSlotBind(uint8_t idx, uint8_t lane, uint16_t key, uint16_t mod,
                                 void* actionMap, uint32_t mode);
```

| Formal | Source | Conf |
|---|---|---|
| slotIndex | **AL** | **High** |
| bindLane | **BL** (0 vs nonzero) | **High** |
| keyCode | **SI** | **High** |
| modCode | **DX** (`param_2`) | **High** |
| actionMap | stack0 | **High** |
| mode | stack1 (0..3) | **High** |
| return | AL 1/0; `RET 8` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if mode>3: fail
jmp jt[mode]
case m:
  if index >= max[m]: fail
  slot = base + index*0x34
  if flag[slot+off[m]] != 0: fail
  if lane==0: write key0/mod0 else key1/mod1
  clear two bytes; return 1
fail: return 0
```

| Stage | Match | Conf |
|---|---|---|
| Switch 0..3 + jump table | **Yes** | **High** |
| Stride 0x34 index math | **Yes** | **High** |
| Bounds 5 / 6 / 0x78 / 0x14 | **Yes** | **High** |
| Flag gate + dual-lane stores | **Yes** | **High** |
| Leaf / no callees | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Body 432 B through final `XOR AL,AL; POP EDI; RET 8`. Jump table dwords:
`0x007f72f9, 0x007f734b, 0x007f73b8, 0x007f7425`.

Mode-0 primary path matches InitDefaultKeybinds plate (`flag@+0x40` for index 1).

---

## 6. Gaps

- Product English for four mode groups.
- Semantics of cleared bytes (`+0x0A/+0x0B` family).
- Live differential of keymap.ini path.

## Verdict rationale

All control flow, ABI, bounds, and field offsets sealed High from bytes + both major callers. Residual is naming only → **accept**.

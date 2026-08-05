# Reconstruction review A: `aa_007f8720` Client_InitDefaultKeybinds

| Field | Value |
|---|---|
| **Stable ID** | `aa_007f8720` |
| **VA** | `0x007f8720` |
| **Canonical name** | `Client_InitDefaultKeybinds` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review (faithfulness of clean C++ to raw) |
| **Author of reconstruction** | Not this reviewer |
| **Counterpart** | `reviews/B_aa_007f8720_Client_InitDefaultKeybinds.md` (skeptical) |
| **Verdict** | **accept-with-gaps** |

---

## 1. What was inspected

| Artifact | Path | Role / claims reviewed |
|---|---|---|
| Raw capture | `docs/reconstruction/raw/aa_007f8720_Client_InitDefaultKeybinds.md` | Authoritative Ghidra decompile body |
| Exact C++ (refined) | `docs/reconstruction/reconstructed-exact/Client_InitDefaultKeybinds.cpp` | Sectioned clean; CF must ≡ raw |
| Function record | `docs/reconstruction/functions/aa_007f8720_Client_InitDefaultKeybinds.md` | Status / confidence |
| Parent clean | `Client_ActionMap_Init.cpp` @ `0x007f9110` | Call site after display names |
| Sibling clean | `Client_InitActionDisplayNames.cpp` @ `0x007f7570` | Same ActionMap object |
| Fresh re-decompile | Ghidra HTTP `decompile_function` @ `0x007f8720` (2026-07-23) | Confirm raw still matches |

**Primary claims under review (clean must match low-level):**

1. Prologue `FUN_007f74a0()` then per-slot “if flag==0 write DIK primary/secondary + clear u8s”.
2. Inventory DIK `0x17` at `+0x5ea`; Shift+I (`mod 0x2a`) at mission-inv offsets.
3. QuickBar 1–10 primary DIK values `2..0x0B` at `+0xc9e` family.
4. Shift-QB pages use primary `2..9` with secondary `0x2a`.
5. Exact counts of `FUN_007f72e0(p,2)` and `FUN_007f72e0(p,3)` calls preserved.
6. Enable-byte stores (`+0x2da`..`+0x3de`, `+0x450`, early `+0x40` family) preserved.
7. Section comments do **not** invent branches or DIK semantics beyond plate/raw immediates.

**Not re-authored in this review.** Runtime ActionMap dump not performed.

---

## 2. What evidence was used

| Evidence | Source | Use |
|---|---|---|
| Authoritative pseudocode | Raw § “Raw pseudocode” | Ground truth CF, constants, call order |
| Fresh Ghidra re-decompile | `0x007f8720` 2026-07-23 | Same unaff_EDI pattern, same immediates |
| Clean C++ section markers | SECTIONs 0–8 | Map claims ↔ body regions |
| Parent raw/clean | `aa_007f9110` | Confirms call after zero-fill + display names |

No instruction-byte length measure. No live key-down correlation of DIK → held flags.

---

## 3. What was confirmed

### 3.1 Control flow: clean ≡ raw (spot-checked regions)

| Region | Raw | Clean | Match |
|---|---|---|---|
| Prologue | `FUN_007f74a0()` | SECTION 0 | **Yes** |
| Early slots | flags `+0x40/+0x74/+0xa8/+0xdc`; DIK `0x35/0xb7/0xb5/0x4e` | SECTION 1 | **Yes** |
| Force flags | five `=1` stores after early quartet | SECTION 1 | **Yes** |
| Inventory | `+0x5ea=0x17`, shift inv `+0x61e=0x17` / `+0x648=0x2a` | SECTION 2 | **Yes** |
| QB1–10 | keys `2..0x0B` | SECTION 4 | **Yes** |
| Shift QB | keys `2..9` + mod `0x2a` | SECTION 5 | **Yes** |
| Decimal `4000` secondary | raw uses decimal `4000` | preserved as `4000` | **Yes** |
| `FUN_007f72e0` bursts | two `mode=2` groups + enable bytes + `mode=3` | SECTIONS 6–8 | **Yes** (call order) |

### 3.2 Parameter / object modeling

| Claim | Level | Notes |
|---|---|---|
| `unaff_EDI` is ActionMap object | **High** (context) | Same object as ActionMap_Init `unaff_ESI` / display-names `in_EAX` via register pass |
| Clean rename `pActionMap` | **OK** | Documented; does not change CF |
| Slot stride `0x34` | **High** | Plate + sibling units |
| Drive thr/steer DIK assigned in this body | **Open** | No named Accel/Steer immediates here; may be `FUN_007f74a0` / `FUN_007f72e0` |

---

## 4. Gaps

1. Bodies of `FUN_007f74a0` and `FUN_007f72e0` not reconstructed — may hold drive-axis defaults.
2. Exact mapping DIK → global held `DAT_00d1bc*` used by DriveControlTick not proven in this unit.
3. Secondary DIK meaning (0 unbound vs modifier) is structural inference from plate/patterns.
4. Runtime: not verified that defaults survive save-game load / user remap flags.

---

## 5. Verdict

Clean is a faithful, sectioned transcription of the raw InitDefaultKeybinds body with documented renames and no invented control flow. Important semantic gaps remain around helper callees and drive-axis default seeding.

**accept-with-gaps**
